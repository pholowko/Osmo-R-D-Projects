// Digital DO and NH4 Probes -  Main.c file                                                                                                                                                                                                                                                        // DO and NH4 Patch Sensor Main.c file
#include <24FV32KA302.h>
#DEVICE ICD=1
#device ADC=10
#define PIC24 1
#device PASS_STRINGS = IN_RAM
#device PSV=16
#device CONST=READ_ONLY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define SENSORBOARDA PIN_B15
#define SENSORBOARDB PIN_B14


#fuses  NOWDT, NOBROWNOUT, NOPROTECT, PUT
#use delay(crystal=8mhz, clock=32mhz)

#define SDAPIN PIN_B2
#define SCLPIN PIN_B3

#use I2C(stream=SENSOR, SLAVE, sda=SDAPIN,scl=SCLPIN, I2C2, address=0xa0)   // this is I2C 1
#use I2C(stream=PH_LIGHT, MASTER, sda=PIN_B9, scl=PIN_B8)    // this is the master I2c for talking with removote sensor boards.  There is only one I2c on this chip.

#define SLAVE 1
#define SENSORNUMBER 0x39   // this means it is a Digital patch DO and NH4 board.
#define TESTER
//include this file.  Only edit this file because it changes all other remote digital boards.


typedef struct outputDataStruct{
char deviceID[16];
unsigned int8 hour;
unsigned int8 minute;
unsigned int8 second;
unsigned int8 day;
unsigned int8 month;
unsigned int16 year;
unsigned int8 taosVersion;
float dOxy;
float wTemp;
float pH;
float pHLow;
float WhiteBalance;
float tdsLevel;
float wLevel;
float lLevelX;
float lLevelY;

int32 lLevelRed;
int32 lLevelGreen;
int32 lLevelBlue;
int32 lLevelClear;
int8 time;
int16 date;


float lLevelScale;
float rH,averagepH;
float aTemp;
int16 cO2;
float nh3;
float dPoint;
char DIEHARD[8];
}outputData;


outputData sysOutput;
/*
// This is added for the retrieval of the configuration data from the host master I2C

typedef struct inputDataStruct{
unsigned int8 chksum;
unsigned int8 hour;
unsigned int8 minute;
unsigned int8 second;
unsigned int8 day;
unsigned int8 month;
unsigned int16 year;
unsigned int1 io1;
unsigned int1 io2;
unsigned int1 io3;
unsigned int8 uploadinterval;   //This is the upload time interval  It's default to 2 minutes for now.
float eccal1x;    //  This the EC data point  Added July 18, 2016
float eccal2x;    //  This the EC data point  Added July 18, 2016
float eccal3x;    //  This the EC data point  Added July 18, 2016
float eccal1y;    //  This the EC data point  Added July 18, 2016
float eccal2y;    //  This the EC data point  Added July 18, 2016
float eccal3y;    //  This the EC data point  Added July 18, 2016
char unittype[5];  // This is a string of no more than 5 characters to describe the unit type.  Needs to end with a null.
float phcallow;       //  This is the lower ADC value count.  It is assocatred always with a pH of 4.  The default is 275.
float phcalhigh;       //  This is the ADC value used to associate with the phnumberupper.  The default is 500, but it can change.
float phnumberupper;    // this is the upper variable pH number.  the default is 10, but it can change
unsigned int16 nh4pt1cal1of3;
unsigned int16 nh4pt1cal2of3;
unsigned int16 nh4pt1cal3of3;
unsigned int16 nh4pt2cal1of3;
unsigned int16 nh4pt2cal2of3;
unsigned int16 nh4pt2cal3of3;
unsigned int16 nh4pt3cal1of3;
unsigned int16 nh4pt3cal2of3;
unsigned int16 nh4pt3cal3of3;
float nh4pt1returnednumber;
float nh4pt2returnednumber;
float nh4pt3returnednumber;
unsigned int16 DOpt1cal1of3;
unsigned int16 DOpt1cal2of3;
unsigned int16 DOpt1cal3of3;
unsigned int16 DOpt2cal1of3;
unsigned int16 DOpt2cal2of3;
unsigned int16 DOpt2cal3of3;
unsigned int16 DOpt3cal1of3;
unsigned int16 DOpt3cal2of3;
unsigned int16 DOpt3cal3of3;
float DOpt1returnednumber;   // this is the returned DO number used for solving the equations at different temperatures
float DOpt2returnednumber;
float DOpt3returnednumber;
unsigned int16 Thermisterpt1cal1of3;
unsigned int16 Thermisterpt1cal2of3;
unsigned int16 Thermisterpt1cal3of3;
float Thermisterpt1returnednumber;
float Thermisterpt2returnednumber;
float Thermisterpt3returnednumber;
}inputData;
inputData sysInput;  */

#include <LightSensorForDigitalBoard.c>
#include "C:\Aquarium Software\Debug Monitor\CommonPassedDataFromMaterToSlave.h"
#include "..\OsomobotCarbonDioxideDigitalSensor\OsomobotCarbonDioxideDigitalSensor.X\ITwoSeeGeneralCommunicationSlave.c"     // this is included to connect to the master Osmobot.

#INT_SI2C2

void si2c2_interrupt()
    {

unsigned int8  incoming, state;

        state=i2c_isr_state(SENSOR);

   if(state <= 0x80)                      //Master is sending data
   {
      incoming = i2c_read(SENSOR,1); 
      if(state == 1)                     //First received byte is address 
      {//First received byte is address
         address = incoming;
         streamCntr=0;
      }
      if(state == 2)                     //Second received byte is data 
          {  
          rcv_buffer[address] = incoming; 
          streamCntr=0;
          }
      
      if(state == 1)                      //First received byte is address
         address = incoming;
      else if(state >= 2 && state != 0x80)   //Received byte is data auto from the master
           {
            rcv_buffer[address++] = incoming;
            streamCntr=0;
            }
   }

   if((state >= 0x80) & (rcv_buffer[0x40] != 0x01))               //Master is requesting data
   {
      i2c_write(SENSOR,send_buffer[streamCntr++]);
   }
      if((state >= 0x80) & (rcv_buffer[0x40] == 0x01))               //Master is requesting data
   {
      i2c_write(SENSOR,SENSORNUMBER);
      rcv_buffer[0x40]=0x00;
   }
	}
   
    

//***********************************************************
//*****************************************************************************
// Created April 6, 2015
//  This routine finds the constants K1 and K2 for any four given values of O2 concentration and intensity.
//  IntensityHighOxy matches up with LowOxyPercentage
//  IntensityLowOxy matches up with HighOxyPercentage
//  Updated April 29, 2014
//  This routine is completed with formula for K1 and K2.
// Added or changed May 18, 2015.  
//  Switched around reading 3 and reading 1 in the void function statment.  This appears to be backwards and conrfusuing when measureing all nine values for DO and temperatures.
//  *****************************************************************************
void SolveForTempCompK1AndK2(float disolvedOxygen1, float disolvedOxygen2, float disolvedOxygen3, float reading3, float reading2, float reading1)
	{

//float disolvedOxygen1,disolvedOxygen2,disolvedOxygen3;
//float reading1,reading2, reading3;
	float32 root1,root2,RatioOfIntensity,IntensityReadingfloat;
	int32 IntensityReading;
 
//disolvedOxygen1 = 9.600;  //Percent   this is the highest reading
//disolvedOxygen2 = 2.00;  //Percent
//disolvedOxygen3 = 0.0;  //Percent   this is the lowest reading

float RatioITemp, RatioIITemp;


//reading3 = 1000.0;    ///This is the reading close to tru O2 20% O2.
//reading2 = 3880.0;    //This is for 5% of O2 
//reading1 = 9000.0;  //This is for the low O2 reading for close to the axis reading.  This is the hight nummber


//  Find the ratios for all three combinations.
	RatioITemp=(reading1/reading3)-1.0;  // I0/I1 - 1.0
	RatioIITemp=(reading1/reading2)-1.0;    //  I0/I2 - 1.0


// Find K2 
     K2Temp = ((RatioITemp/disolvedOxygen1) - (RatioIITemp/disolvedOxygen2))/(disolvedOxygen1 - disolvedOxygen2);

// Find K1

     K1Temp = (RatioITemp-(K2Temp*disolvedOxygen1*disolvedOxygen1))/disolvedOxygen1;


// Find Iohhh 

//	Iohhh = RatioITemp;   //This used to be reading1   April 7, 2015  Removed and kept as reference.

	Iohhh = reading1;   //This used to be reading1   May 19, 2015 This is the hightest reading for the lowest DO measyrement.


IntensityReading = 16000;
//IntensityReading = reading3;
IntensityReadingfloat = (float) IntensityReading;   // Added May 18, 2015.  This is added to convert the hex number into a float so it can be calculated.

RatioOfIntensity = 1.0 - Iohhh/IntensityReadingfloat;

	root1 = sqrt(K1Temp*K1Temp - 4.0*RatioOfIntensity*K2Temp)- K1Temp;
	
	root1 = (root1)/(2.0*K2Temp);  //This is the plus version of the equation
	root2 = (-1.0 * K1Temp - (sqrt((K1Temp*K1Temp)-4.0*(RatioOfIntensity)*K2Temp)))/(2.0*K2Temp);  // This is the negative version of the equation.  Most likely not used?


	}


//***********************************************************************************************************
//Created April 6, 2015
// This routine finds all of the values for DO temperature Compensation.
//There are four temperatures DO is calibrated for.  Each one has its own set of coefficents that needs to be calculated from the calibration data.  
// All temperatures are measured and converted into Kalvin.
// All measurments are seperated into ranges split by the temperature ranges.
//The temperature ranges are as follows:
// T1 = 10  degrees C.
// T2 = 20  degrees C.
// T3 = 25  degrees C.
// Three sets of I values at differnt O2 concentrations needs to be measured or guessed.
// One for each temperature.  The K1 and K2 values are found for each temperature and then a set of coefficents for temperature is found.
// This routine 
//*************************************************************************************************************
void CalculateK1andK2WithTempComp(float temperature)
	{
/*   This is commented out because the varuibles are used globally and are saved on the SD Card. Added May 20, 2015
	float Temp1DOOne = 9.5;            //These are the set points where we want to read these numbers at temperature 1
	float Temp1DOTwo = 4.0;            //This is at 10 degrees
	float Temp1DOThree = 0.0;

	float Temp2DOOne = 7.5;            //These are the set points where we want to read these numbers at temperature 2
	float Temp2DOTwo = 4.0;				//This is at 20 degrees
	float Temp2DOThree = 0.0;

	float Temp3DOOne = 6.7;            //These are the set points where we want to read these numbers temperature 3
	float Temp3DOTwo = 4.0;            //This is at 25 degrees
	float Temp3DOThree = 0.0;


	float Temp1ReadingOne = 10752.0;       //Readings for Temp3  10 degrees C
	float Temp1ReadingTwo = 11000.0;      //Readings for Temp3
	float Temp1ReadingThree = 12000.0;    //Readings for DOOne    this is no DO.

	float Temp2ReadingOne = 11266.0;       //Readings for Temp3    20 degrees C
	float Temp2ReadingTwo = 12000.0;      //Readings for Temp3
	float Temp2ReadingThree = 13000.0;    //Readings for DOOne

	float Temp3ReadingOne = 12425.0;       //Readings for Temp3   25 degrees C
	float Temp3ReadingTwo = 13000.0;      //Readings for Temp3
	float Temp3ReadingThree = 14000.0;    //Readings for DOOne
*/
	float  K1TempOne,K2TempOne, K1TempTwo, K2TempTwo, K1TempThree, K2TempThree, TempOneOut, TempTwoOut, TempThreeOut;
/*
	float TempOne = 10.0;       //Calibration temperatures for DO   Added April 7, 2015
 	float TempTwo =  20.0;      //Calibration temperatures for DO  Added April 7, 2015
	float TempThree =  25.0;     //Calibration temperatures for DO  Added April 7, 2015

*/
	float IohhhTempTwo,IohhhTempThree,IohhhTempOne;   //This is added May 18, 2015 for using the Ioh as part of the temperature compensation rourtines.

//Find all of the K values for solving temperature compensation.  There needs to be three equations for three unknows for K1, K2 and I which is the highest reading

	SolveForTempCompK1AndK2(Temp3DOOne, Temp3DOTwo, Temp3DOThree, Temp3ReadingOne, Temp3ReadingTwo, Temp3ReadingThree);

//Save the first set of K values for Tempature 3  or 25 degrees
	K1TempThree = K1Temp;
	K2TempThree = K2Temp;
	IohhhTempThree = Iohhh;

	SolveForTempCompK1AndK2(Temp2DOOne, Temp2DOTwo, Temp2DOThree, Temp2ReadingOne, Temp2ReadingTwo, Temp2ReadingThree);
//Save the first set of K values for Tempature 2 which is at 20 degrees C
	K1TempTwo = K1Temp;
	K2TempTwo = K2Temp;
	IohhhTempTwo = Iohhh;

	SolveForTempCompK1AndK2(Temp1DOOne, Temp1DOTwo, Temp1DOThree, Temp1ReadingOne, Temp1ReadingTwo, Temp1ReadingThree);
//Save the first set of K values for Tempature 1 which is at 10 degrees C
	K1TempOne = K1Temp;
	K2TempOne = K2Temp;
	IohhhTempOne = Iohhh;

//*******************************************************************************************************
//Solve for K1 and find a,b and c for K1 temperature compensation
//Created April 7, 2015
//*******************************************************************************************************
// The temperature needs to be converted to degrees Kalvin


temperature = temperature + 273.0;   //The conversion from C to K is add 273 to degrees C.

TempOneOut = TempOne + 273.0;     //The conversion from C to K is add 273 to degrees C.
TempTwoOut = TempTwo + 273.0;     //The conversion from C to K is add 273 to degrees C.
TempThreeOut = TempThree + 273.0;     //The conversion from C to K is add 273 to degrees C.

//Find K1 coefficents for T = 5  or 273 +5 = 278 degress K.

      matrixequation[0][0] = 1;
      matrixequation[1][0] = TempOneOut; 
      matrixequation[2][0] = TempOneOut * TempOneOut; 
      matrixequals[0] = K1TempOne; 
      matrixequation[0][1] = 1;
      matrixequation[1][1] = TempTwoOut; 
      matrixequation[2][1] = TempTwoOut * TempTwoOut; 
      matrixequals[1] = K1TempTwo; 
      matrixequation[0][2] = 1;
      matrixequation[1][2] = TempThreeOut; 
      matrixequation[2][2] = TempThreeOut * TempThreeOut;    
      matrixequals[2] = K1TempThree;

ThreeByThreeSolution();  // Call to solve for coefs for K1


	atwo = MatrixSolution[0];   //Move the solution into the coefs
	btwo = MatrixSolution[1];   //Move the solution into the coefs
	ctwo = MatrixSolution[2];   //Move the solution into the coefs


//Found solution coefficenta for K1.  Now take the current temperature and calculate the Current K1 value.

K1 = atwo + btwo*temperature + ctwo*temperature*temperature;

      matrixequation[0][0] = 1;
      matrixequation[1][0] = TempOneOut; 
      matrixequation[2][0] = TempOneOut * TempOneOut; 
      matrixequals[0] = K2TempOne; 
      matrixequation[0][1] = 1;
      matrixequation[1][1] = TempTwoOut; 
      matrixequation[2][1] = TempTwoOut * TempTwoOut; 
      matrixequals[1] = K2TempTwo; 
      matrixequation[0][2] = 1;
      matrixequation[1][2] = TempThreeOut; 
      matrixequation[2][2] = TempThreeOut * TempThreeOut;    
      matrixequals[2] = K2TempThree;

ThreeByThreeSolution();  // Call to solve for coefs for K1


	atwo = MatrixSolution[0];   //Move the solution into the coefs
	btwo = MatrixSolution[1];   //Move the solution into the coefs
	ctwo = MatrixSolution[2];   //Move the solution into the coefs

K2 = atwo + btwo*temperature + ctwo*temperature*temperature;


//Now we need to find the last ratio for light intenstiry Ioooooooo

//************************************************************
// Save May 18, 2015.  This saved for reference only.  it's the orginal one
// Iohhhhs have been added as part of the temperature compensation.  It's a ratio, not only one reading.
//************************************************************


      matrixequation[0][0] = 1;
      matrixequation[1][0] = TempOneOut; 
      matrixequation[2][0] = TempOneOut * TempOneOut; 
      matrixequals[0] = IohhhTempOne; 
      matrixequation[0][1] = 1;
      matrixequation[1][1] = TempTwoOut; 
      matrixequation[2][1] = TempTwoOut * TempTwoOut; 
      matrixequals[1] = IohhhTempTwo; 
      matrixequation[0][2] = 1;
      matrixequation[1][2] = TempThreeOut; 
      matrixequation[2][2] = TempThreeOut * TempThreeOut;    
      matrixequals[2] = IohhhTempThree;

ThreeByThreeSolution();  // Call to solve for coefs for K1


	atwo = MatrixSolution[0];   //Move the solution into the coefs
	btwo = MatrixSolution[1];   //Move the solution into the coefs
	ctwo = MatrixSolution[2];   //Move the solution into the coefs

Iohhh = atwo + btwo*temperature + ctwo*temperature*temperature;

	}



//****************************************************************************
// Created May 9, 2013
// This rouitne uses the current read Intensity, K1 and K2 to determine the currnet percent of O2
// The calibration calculation routine needs to first be run before this routine works.
// Later on the temperature is also considered for Do compensation.
//****************************************************************************
float CalcaulateDO(unsigned int32 IntensityReading, float temperature)
	{

	float32 root1,root2,RatioOfIntensity,IntensityReadingfloat;
    float tempcalc,tempinside,tempsquare;  //This is used to calcaulte the intermediate steps for the quadratic equation.

//***************
// May 1, 2014 
// This is commented out to first test the K1 and K2 equations.  Temp comp is added later.
//***************

//Iohhh = azero + bzero * temperature + czero * temperature * temperature;

//K1 = aone + bone * temperature + cone * temperature * temperature;
//K2 = atwo + btwo * temperature + ctwo * temperature * temperature;
//SolveForK1AndK2(int16 IntensityLowOxy, int16 IntensityHighOxy, int16 IntensityMiddleOxy, float LowOxyPercentage, float HighOxyPercentage)


//******************************************************************************
// Added April 7, 2015
//  This is the old non-temperature compensated DO calculations.
//The routine is left for reference and history.
//SolveForK1AndK2();

//*****************************************************************************
//Created April 7, 2015
// The routine below calculates the K1, K2 and Ihooo for the current temperature.  Tempature must be in degrees C.
CalculateK1andK2WithTempComp(temperature);

//************************************************************** //Added April 27, 2014
// Before the DO can be calculated, it needs to be temperature 
// compensated.  The values of K2, K1 and Iohhh need to be 
// calculated through the three X three matrix temperature shift.
// **************************************************************
//IntensityReading = 200.0;   //this is the test input reading.  This is commeneted out for the real data Nov. 14, 2014

IntensityReadingfloat = (float) IntensityReading;   // Added May 18, 2015.  This is added to convert the hex number into a float so it can be calculated.

RatioOfIntensity = 1.0 - Iohhh/IntensityReadingfloat;

tempcalc = K1*K1;
tempinside = 4.0*RatioOfIntensity*K2;
tempcalc = tempcalc - tempinside;
tempsquare = sqrt(tempcalc);

	root1 = tempsquare - K1;
	root1 = sqrt(K1*K1 - 4.0*RatioOfIntensity*K2)- K1;
	
	root1 = (root1)/(2.0*K2);  //This is the plus version of the equation
	root2 = (-1.0 * K1 - (sqrt((K1*K1)-4.0*(RatioOfIntensity)*K2)))/(2.0*K2);  // This is the negative version of the equation.  Most likely not used?

	return(root1);  //If this root is positive, the return it.
	}


void DetermineTempCoef(void)
{
//This has been removed and placed in TaosLightSensor.h  May 21, 2015
//float temp1,reading1,temp2,reading2,temp3,reading3;
float temp1in,temp2in,temp3in;
float reading1in,reading2in,reading3in;
float det, det1, det2, det3;   //These are the other dets for each solution
// This is the raw data.  Added May 15, 2015

temp1 = 40;    
temp2 = 21;
temp3 = 6;  
//temp1 = sysInput.Thermisterpt1returnednumber;    //example 40 C
//temp2 = sysInput.Thermisterpt2returnednumber;   // example 21  C
//temp3 = sysInput.Thermisterpt3returnednumber;    // example 6  C

//***************************************************************************
//Added January 13, 2015
// These are the values used for the 10K reistor stolen from Animatics
//***************************************************************************
reading1 = 5140;
reading2 = 13037;
reading3 = 27594;

//reading1 = sysInput.Thermisterpt1cal1of3;   //5140
//reading2 = sysInput.Thermisterpt1cal2of3;  // 13037;
//reading3 = sysInput.Thermisterpt1cal3of3;  //  27594;
//***************************************************************************
//Added January 13, 2015
// These are the values used for the ?K reistor supplied by Rick
//***************************************************************************

//reading1 = 12000;   //this one is measured at 45 degrees C   // these numbers are for the 30K reistor
//reading2 = 40000;   //this is measured at 22 C  Checked on May 14, 2015
//reading3 = 72000;   // this tempature is measured at 12 degrees C


temp1in = 1.0/(temp1 + 273.0);
temp2in = 1.0/(temp2 + 273.0);
temp3in = 1.0/(temp3 + 273.0);


reading1in = log(reading1);
reading2in = log(reading2);
reading3in = log(reading3);


//  This part solves for tempa1, tempa2, tempa3 4
// Find the divistion determinent

matx[0][0] = 1.0;
matx[1][0] = 1.0;
matx[2][0] = 1.0;
matx[0][1] = reading1in;
matx[1][1] = reading2in;
matx[2][1] = reading3in;
matx[0][2] = reading1in*reading1in;
matx[1][2] = reading2in*reading2in;
matx[2][2] = reading3in*reading3in;

det = FindTheDetermint();

//Find the det for tempa1

matx[0][0] = temp1in;
matx[1][0] = temp2in;
matx[2][0] = temp3in;
matx[0][1] = reading1in;
matx[1][1] = reading2in;
matx[2][1] = reading3in;
matx[0][2] = reading1in*reading1in;
matx[1][2] = reading2in*reading2in;
matx[2][2] = reading3in*reading3in;

det1 = FindTheDetermint();
tempa1=det1/det;   //  This finds the value for the first a1

matx[0][0] = 1.0;
matx[1][0] = 1.0;
matx[2][0] = 1.0;
matx[0][1] = temp1in;
matx[1][1] = temp2in;
matx[2][1] = temp3in;
matx[0][2] = reading1in*reading1in;
matx[1][2] = reading2in*reading2in;
matx[2][2] = reading3in*reading3in;


det2 = FindTheDetermint();
tempa2=det2/det;   //  This finds the value for the first a2



matx[0][0] = 1.0;
matx[1][0] = 1.0;
matx[2][0] = 1.0;
matx[0][1] = reading1in;
matx[1][1] = reading2in;
matx[2][1] = reading3in;
matx[0][2] = temp1in;
matx[1][2] = temp2in;
matx[2][2] = temp3in;

det3 = FindTheDetermint();
tempa3=det3/det;   //  This finds the value for the first a2


}
//*************************************************************
// Created Nov. 6, 2012
//  This routine reads an ADC and averages 16 samples into one and returns the number.
// There is no scaling or any signal condition except for a low pass averaging filter.
//  The input selection is for ADC 1, 2, 3 and 5.  The numbers 0, 1, 2 and 4 are used for selecting the ADC.
//*************************************************************

int16 GetADCValue(int selection)
	{
	int16 ReturnedADC, Summer;	
	int f;
					//setup_adc(ADC_CLOCK_INTERNAL);  //Setup the ADC to run..
					set_adc_channel(selection); 
                    		delay_ms(10);
					Summer=0;
					for (f=0; f < 32; f++)
						{
					delay_us(10);
					Summer = Summer + read_adc(); // Read adc channel 10 
						}
					ReturnedADC = Summer>>5;
	return(ReturnedADC);	
	}




//*****************************************************************
// Created Nov. 6, 2012
// Converts the ADC number on a scale of 5 volts minus some for Op-amp issues
// The numerical convertion is conveted into degrees C.
// The returned value in C degrees.
//  Ths interm convertion is to Kalvin and will later be switched over to Kalvin scale.
//*****************************************************************
 

float ConvertADCToKalvin(int ADCInputNumber)
	{
int16 ReturnedADC;
float32 ADCVoltageIn,Kelvin, tempfloater;
    int8 highbyte, lowbyte;
    int16 returneditem;  // this is the returned item
	ReturnedADC = GetADCValue(ADCInputNumber);  //This gets the current ADC convertion for the channel number.
//    ADCVoltageIn = ReturnedADC * 5.0 / 1024.0;  //Recycled the same float variable.  This is for the 5 volts version.
  tempfloater = (float) ReturnedADC;
  ADCVoltageIn = (float) ReturnedADC * 3.3 / 1024.0;  //Recycled the same float variable.  This converts the input into scaling
 
  
        lowbyte = 0x00FF & ReturnedADC;
        returneditem = 0xFF00 & ReturnedADC;
        highbyte = ReturnedADC>8;  // this moves it over to the low part
        send_buffer[14] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[13] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

//Added May 18, 2015  - The current/last thermister is RL0503-7.56K-96-MS  it's a 30K thermister.
// This is for the thermister to be on the top of the 5K resistor
 
//	ADCVoltageIn = 5100.0*ADCVoltageIn/(3.3 - ADCVoltageIn);  // Calulate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K

//ADCVoltageIn = 4999.0*ADCVoltageIn/(5.0 - ADCVoltageIn);  // Calulate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K
//When it is when it's on the bottom....  The resistance becomes different.
//ADCVoltageIn = ADCVoltageIn/((5.0 - ADCVoltageIn)/4999.0);   // find the thermister resistace
ADCVoltageIn = ADCVoltageIn/((3.3 - ADCVoltageIn)/5100.0);   // find the thermister resistace


//ADCVoltageIn=12000.0;

DetermineTempCoef();

//Kelvin = (1/(tempa1 + tempa2*(log(ADCVoltageIn)) + tempa3*(log(ADCVoltageIn)*log(ADCVoltageIn))))-273.15;   //This is the old line of code used to find the thermister temperature
Kelvin = (1/(tempa1 + tempa2*(log(ADCVoltageIn)) + tempa3*(log(ADCVoltageIn)*log(ADCVoltageIn))))-273.15;
	return(Kelvin);
	}



//*********************************************************************
// Created June 25, 2015
// This routine calls the water temperature program and averages together twenty points.  Twenty two points are
// collected and the high and low reading is thrown out.  
// There is no input needed in this routine.  The result is returned as a float.
//*********************************************************************
float WaterTemperature(void)
	{
float temparray[42], tempval;

int  switchflag,x;  //This is used in the ordering routine to indicate if two numbers have been switched.  If not, then the array is in numerical order.

for (x=0; x < 42; x++)   // Get all of the readings and save them in an array.
	{
	temparray[x] = ConvertADCToKalvin(11);   //This called current thermisting reading routine. It returns a temperature reading in C.
	}

//  Place the numbers in order in the array from the lowest reading at the high numbers indexs and the hightest readings at the low indexes.

do {
switchflag =0;  //Set it to zero indicating everything is in order.
for (x=0; x < 41; x++)
	{
	if (temparray[x] < temparray[x+1])
		{
		tempval = temparray[x];
		temparray[x] = temparray[x+1];
		temparray[x+1] = tempval;
		// Since this case is true, then switch the numbers in the array and set the not completed flag to 1.
		switchflag =1;   //  Indicate are reversal needed to be done.
		}
	}
} while(switchflag == 1);   //If the value is zero, the array is in order.


//  Average the numbers between 1 and 21.  This will kick out the hightest and lowest readings.
tempval = 0;   //recycled the varaible used for averaging the readings together.
for (x = 1; x < 41; x++)
	{
	tempval=tempval+temparray[x];
	}
	tempval = tempval/40.0;   //Divide the added number by 20 which is the number of values added together.


	return(tempval);
	}




//*****************************************************************************************************
// Created May 19, 2014
// Completed May 23, 2014
// This routine reads the data from the DO or pH.  This is including the pre-deteremined gains
// The inputs are as following:
// PWM input channel
//  The PWM magic number
// the channel sensor input channel   
// DO is sensor 1

// SensprControl is  a number between 1 to 3 for each I2C
// PWMIntensity  this is the general starting point for the PWM
//  RequiredReading  - this is the required light reading needed to make a measurement.  THE PID will converg on this number.
//  Use the Pgain in the routine below to control the quickness of convergance.
//  the result is an unsigned 16 bit interger.
//*****************************************************************************************************
void TakeLightReading(int SensorChannel)
{

int color,attemptcounter, attempts,ttt,x;
int32 result,stepdifference;  //This is the result of the calculation.  This is returned to the calling function.

float DOReading,pgain,tempoffset;
char uffit[60];

unsigned int32 difference;
    int8 highbyte, lowbyte;
    int16 returneditem;  // this is the returned item


    

    
//*************************************************************************************
//  Added Augest 28, 2015
// This section measures the DO
//*************************************************************************************
//******************************************************************************
// Created November 14, 2016
//  This routine measure the light patch for DO.
// This routine cycles through all of the colors and gets the number for each LED turned on.  This helps with filtering.
//  Nothing is returned  
//******************************************************************************
if (SensorChannel == 0)
{
	selectsensor(SensorChannel);    // Added December 9, 2015     Sensor 1 is NH4.

    output_high(PIN_B12);  // turn on green
    delay_ms(100);  // set a PWM setup delay to stablize the timing.
}


if (SensorChannel == 1)
{
	selectsensor(SensorChannel);    // Added December 9, 2015     Sensor 1 is NH4.
    output_high(PIN_B12);  // turn on green
    delay_ms(100);  // set a PWM setup delay to stablize the timing.
}


// 2 is not populated.  Added April 5, 2017
if (SensorChannel == 3)
{
	selectsensor(SensorChannel);    // Added December 9, 2015     Sensor 1 is NH4.
    output_high(PIN_B12);  // turn on green
    delay_ms(100);  // set a PWM setup delay to stablize the timing.
}

	color = GetCurrentColorAVG(3, SensorChannel);   // Number 2 is the colored  LED.  The 4 means it any gain reading

// turn off all lights
	output_low(PIN_B12);    // turn off the blue light
 
	//redABS = redABS - AmbientOxyRed;
//	greenABS = greenABS - AmbientOxyGreen;
	//blueABS = blueABS - AmbientOxyBlue;
	//clearABS = clearABS - AmbientOxyClear;

//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.
// on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 
/*
if (blueABS < 0)
	{
	blueABS = 0;
	}
if (clearABS < 0)
	{
	clearABS = 0;
	}    

        lowbyte = 0x00FF & redABS;
        returneditem = 0xFF00 & redABS;
        highbyte = redABS>8;  // this moves it over to the low part
        send_buffer[20] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[19] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the   
    
    
if (greenABS < 0)
	{
	greenABS = 0;
	}
if (blueABS < 0)
	{
	blueABS = 0;
	}
if (clearABS < 0)
	{
	clearABS = 0;
	}    
        
 
        lowbyte = 0x00FF & blueABS;
        returneditem = 0xFF00 & blueABS;
        highbyte = blueABS>8;  // this moves it over to the low part
        send_buffer[24] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[23] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the       
    
   }
      // check for white
        // turn on all of the LEDS for white
    if (x==3)  // this checks the green light
     {
    output_low(PIN_B11);    // turn on the blue light
    output_low(PIN_B12);    // turn on the blue light
    output_low(PIN_B10);    // turn off the red light
        delay_ms(200);  // set a PWM setup delay to stablize the timing.
	color = GetCurrentColorAVG(3, 2);   // Number 2 is the colored  LED.  The 4 means it any gain reading
	output_high(PIN_B11);    // turn on the blue light
    output_high(PIN_B12);    // turn on the blue light
    output_high(PIN_B10);    // turn off the red light
 
	//redABS = redABS - AmbientOxyRed;
	//greenABS = greenABS - AmbientOxyGreen;
	//blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

    
    if (clearABS < 0)
	{
	clearABS = 0;
	} 
    
        lowbyte = 0x00FF & clearABS;
        returneditem = 0xFF00 & clearABS;
        highbyte = clearABS>8;  // this moves it over to the low part
        send_buffer[26] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[25] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 
 
    }    
    }
    }
 */
	}



//*********************************************************************
// 
void main(void){
    int8 x,returdata;
    int returneddummy;
    int16 changeover;  //this is used for changeing the int32 to 16 bit.
    int32 OxyBlue;
    float xxx;
    int8 blinkinggreenlight = 0;  // Added March 30, 2017  This is the blinking green light counter varaible

    int16 returneditem;  // this is the returned item
    int8 highbyte, lowbyte;
    
    Temp1DOOne = 9.5;            //These are the set points where we want to read these numbers at temperature 1
	Temp1DOTwo = 4.0;            //This is at 10 degrees
	Temp1DOThree = 0.0;

	Temp2DOOne = 7.5;            //These are the set points where we want to read these numbers at temperature 2
	Temp2DOTwo = 4.0;				//This is at 20 degrees
	Temp2DOThree = 0.0;

	Temp3DOOne = 6.7;            //These are the set points where we want to read these numbers temperature 3
	Temp3DOTwo = 4.0;            //This is at 25 degrees
	Temp3DOThree = 0.0;


	Temp1ReadingOne = 10752.0;       //Readings for Temp3  10 degrees C
	Temp1ReadingTwo = 11000.0;      //Readings for Temp3
	Temp1ReadingThree = 12000.0;    //Readings for DOOne    this is no DO.

	Temp2ReadingOne = 11266.0;       //Readings for Temp3    20 degrees C
	Temp2ReadingTwo = 12000.0;      //Readings for Temp3
	Temp2ReadingThree = 13000.0;    //Readings for DOOne

	Temp3ReadingOne = 12425.0;       //Readings for Temp3   25 degrees C
	Temp3ReadingTwo = 13000.0;      //Readings for Temp3
	Temp3ReadingThree = 14000.0;    //Readings for DOOne
	TempOne = 10.0;       //Calibration temperatures for DO   Added April 7, 2015
 	TempTwo =  20.0;      //Calibration temperatures for DO  Added April 7, 2015
	TempThree =  25.0;     //Calibration temperatures for DO  Added April 7, 2015
    
output_low(PIN_B7);  // this turns on the green piolate light LED for showing the board is running.  It also blinks through out the wnile(1) loop  Added March 30, 2017
initTransMitBuffer();  // clear the sending buffer
LEDtest();
//enable_interrupts(GLOBAL);


InitTAOS(); // this sets up the scaler time for the DO light
//StartUpTAOS(0x00);  // this starts up the integration time for the DO light sensor
setup_adc(ADC_CLOCK_INTERNAL);
setup_adc_ports(sAN11|sAN12);
enable_interrupts(INT_SI2C2);     

//returndata = SaveConfiguration();

 //   CalculateCRC();
LoadConfiguration();
rcv_buffer[2]==0x00;  // clear any buffer data for triggering calibration changes.


while(1)
{ 
// read the DO measurement
    //FindAmbientLight(0x01);   // this selects DO   Find the background light with no blue light on
        output_high(PIN_B12);
        returdata = GetCurrentColor(0x03, 0x01);
 
    //   TakeLightReading(0x03);   
    wTemp = WaterTemperature();
    

        output_low(PIN_B12);
    // this seaves DO measurements
        changeover = (int16) greenABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
     //   send_buffer[22] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
     //   send_buffer[21] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) redABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[16] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[15] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) blueABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
     //   send_buffer[22] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
     //   send_buffer[21] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) clearABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
     //   send_buffer[22] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
     //   send_buffer[21] = highbyte;   // update this
    
    
//sysOutput.wTemp = 10.0;
     output_high(PIN_B5);  // turn on white DpH LED
          // TakeLightReading(0x00);   
  // this selects DpH  Take a measurement and find the ABS color difference
    returdata =  GetCurrentColorAVG(0x03, 0x00);
     output_low(PIN_B5);  // turn on white DpH LED
    // this saves DpH measurements
        changeover = (int16) greenABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[22] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[21] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) redABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[20] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[19] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) blueABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[24] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[23] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) clearABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[26] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[25] = highbyte;   // update this
    
        
        output_low(PIN_B10);  // turn on white NH4 LED
         // this selects NH4  Take a measurement and find the ABS color difference
         returdata =  GetCurrentColorAVG(0x03, 0x03);
        output_high(PIN_B10);  // turn off white NH4 LED
    // this saves DpH measurements
        changeover = (int16) greenABS;
         lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[28] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[27] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) redABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[32] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[31] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) blueABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[34] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[33] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 

        changeover = (int16) clearABS;
        lowbyte = 0x00FF & changeover;
        returneditem = 0xFF00 & changeover;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[36] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[35] = highbyte;   // update this
       /* 
        
        xxx =  CalcaulateDO(redABS,wTemp);  //This holds the color intensity variable and the temperature in degrees C.
    
    
    */
    
    	sysOutput.wTemp = wTemp;  //This is the float temperature
    
    	if (sysOutput.wTemp < 0.0)
        {
		sysOutput.wTemp = 0.0;
        wTemp = 0.0;
        }
    // move calcaulated temperature into output buffer for water temperature
    send_buffer[5] =  (int) wTemp;  // high whole number byte
    send_buffer[6] =  (int) ((wTemp - (float) (int) wTemp)*100);  // high whole number byte
//  Toggle green light to show the system is working.   Added March 30, 2017  
   

if (blinkinggreenlight == 0)
{
    output_LOW(PIN_B7);
    blinkinggreenlight=1;
}
else
{
    output_HIGH(PIN_B7);
    blinkinggreenlight=0;
}
     

//*****************************************************************
// Created Nov 28, 2016
// This checks for any change in the update input.  Once rcv_buffer[2]== 1, then update the config varibles.
//*****************************************************************
        if (rcv_buffer[2]==0x01)
          {
          // move the data off the input buffer into the calibration varaibles.
            
            movercvbuffertocolibration();   //move over the data
            
            rcv_buffer[2]==0x00;
            // clear buffer
            for (x=0; x < 65; x++)
                rcv_buffer[x]==0x00;
          }
}

}






