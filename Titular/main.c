// Debug Display Sensor Main.c file
#include <18F46k22.h>
#DEVICE ICD=TRUE
#device ADC=10
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <STDIO.h>

#define SDAPIN PIN_B0
#define SCLPIN PIN_B1

#define SENSORBOARDA PIN_B5
#define SENSORBOARDB PIN_B4

#define TESTER 1
#define NOTOSMOBOT 1
#define ADCREZ 1024
#define OSMOBOT 0    // this not the main board, but the programmer
#define TIRHTEMP 1
char adcBuff[20];
char bt_cmd[50]; // buffer where the command is kept for parsing.  Added July 10, 2015
char rec_buffer[65];
unsigned int16 reading[128];  // this is the linear array
unsigned int8 streamCntr = 0;
unsigned int8 dispCntr = 0;
int1 writeReady = 0;
unsigned int8 xCntr = 0;
unsigned int8 yCntr = 0;
unsigned int16 stufftocheck;

#fuses  NOWDT, NOLVP, NOBROWNOUT, NOPROTECT, PUT 
#use delay(crystal=20000000, clock=20000000)


#use i2c(stream=PH_LIGHT, MASTER, sda=SDAPIN, scl=SCLPIN, fast=10000)    // this is the master I2c for talking with removote sensor boards.  There is only one I2c on this chip.
#use rs232(uart1, baud=9600, xmit=PIN_C6, rcv=PIN_C7, stream=BT)

void selectsensor(int sensornumber);
int readlineararray(void);
int16 DORaw, WTRaw, NH4Raw;

typedef struct outputDataStruct {
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
    float rH, averagepH;
    float aTemp;
    int16 cO2;
    float nh3;
    float dPoint;
    char DIEHARD[8];
} outputData;


outputData sysOutput;
unsigned int16 selectitem; // this is the var used for local configurations
//int16 DORaw, WTRaw, NH4Raw, CO2Raw, stuffit,NHWhiteRaw, NHRedRaw,NHGreenRaw, NHBlueRaw;
int16 stuffit;
int8 startupdate = 0; // this is the flag to start an upload 
int16 th,tl,hh,hl;  // variables for 1050 RH and temp sensor

#include <CU20045SCPB-U1J.c>
#include "G:\OsmobotLocalDisplay Via Bluetooth\VacDisplayRoutines.c"
#include <MasterReadWriteTeRemoteDevice.c>
#include "G:\OsmobotLocalDisplay Via Bluetooth\BluetoothRoutines.c"
#include "G:\Osmobot4PostProduction\Instrumentation\CheapRHAndTemp.c"
//GPIO Initialization
#USE STANDARD_IO(d)
#USE STANDARD_IO(e)

#include "G:\Osmobot4PostProduction\Instrumentation\ECcalculation.c"
//*********************************************************************************
// Added May 21, 2015
// This is the calibrations for temperature on the thermister for water
//*********************************************************************************

float temp1 = 40.0;
float reading1 = 5140.00;
float temp2 = 20.0;
float reading2 = 11700.00;
float temp3 = 6.0;
float reading3 = 21594.00;
float tempa1, tempa2, tempa3; //Addded May 15, 2014 These are the coefecents for thermister calculation
float matx[3][3]; //This is the global diffinition of solving a 3X3 matrix equation. This is a scrach pad matrix used to pass arrays between functions. Added May 13, 2013
float matrixequation[3][3]; //  Added May 13, 2013  This is the array used for setting up the eqaution for solving a 3X3 equation.
float fourbyfourmatrix[4][4];
float matrixequals[3];

int colorlow, colorhigh;   // gain, scale;  //This is the pair of bytes used to return the current selected color.
unsigned int16 red,green,blue,clear;


//************************************************************************
// Addded Sept 2, 2015
// Global varables for decay solution
//************************************************************************
float eccalibrationy[4]; //The four numbers for the y axis or the ppm axis.
float eccalibrationx[4]; //The four numbers for the x axis or the count axis.
float x, y, z; //Color chart positions,coored.


//***************************************************************************
// Created December 2, 2015
// Changed for the digital sensor board Oct 13, 2016
// This routine sets the encoder to select where the I2C clock signal goes to.
// It returns nothing.
// The input is number for 0 to 5;  each one selecting a sensor.
// Added March 17, 2016
//  SENSORBOARDA    0       1      0         1
//  SENSORBOARDB    0       0      1         1
//                in unit   top   bot Rj45   nothing
//***************************************************************************

void selectsensor(int sensornumber) {
    //fprintf(BT,"Device Number Selected %i\n\r",sensor number);
    if (sensornumber > 3) // Set the high bit
    {
        sensornumber = sensornumber - 4; // Remove the offset so the bottom part of the byte can be accessed
    }

    if (sensornumber == 0) // Set the lower bits.
    {
        output_low(SENSORBOARDA); // This is connected to the input for the A on both 74139 chips.
        output_low(SENSORBOARDB); // This is connected to the input for the B on both 74139 chips.
    }

    if (sensornumber == 1) {
        output_high(SENSORBOARDA); // This is connected to the input for the A on both 74139 chips.
        output_low(SENSORBOARDB); // This is connected to the input for the B on both 74139 chips.
    }
    if (sensornumber == 2) {
        output_low(SENSORBOARDA); // This is connected to the input for the A on both 74139 chips.
        output_high(SENSORBOARDB); // This is connected to the input for the B on both 74139 chips.
    }
    if (sensornumber == 3) {
        output_high(SENSORBOARDA); // This is connected to the input for the A on both 74139 chips.
        output_high(SENSORBOARDB); // This is connected to the input for the B on both 74139 chips.
    }

}


//***********************************************************************
//Created September 26, 2016
// This routines returns the calucated pH from the given system inputs and of the calibration derived from the server.
// It returns a float
//***********************************************************************

float CalculatepH(float ADCNumber) {

    float mm, b, result;

    mm = (sysInput.phnumberupper - 4.0) / (sysInput.phcalhigh - sysInput.phcallow);
    //y = mx +b
    // find b
    // b = y - mx
    b = sysInput.phnumberupper - mm * sysInput.phcalhigh;
    result = ADCNumber * mm + b;



    return (result);
}

#include <EEPROMReadWriteRoutines.c>     // this is included to connect to the master Osmobot.


//*********************************************************************
// Created July 15, 2015
// Splash screen for 1 second before going into the main loop;
//  Give Version, credit to Erik and Paul
// Provide Version Date
//*********************************************************************

void splash(void) {
    clearDisplay();
    char teststr4[20] = "Ver 5.03 4/6/2017";
    char teststr1[20] = "Production Tester";
    char teststr2[20] = "Config Editor";
    char teststr3[20] = "Paul Holowko-Titular";
    writeString(0, 0, teststr1);
    writeString(0, 1, teststr2);
    writeString(0, 2, teststr3);
    writeString(0, 3, teststr4);
    delay_ms(2500);
    clearDisplay();
}



//******************************************************************************
// Created May 13, 2013
// This routine returns the determinent for a given 3X3 mastrix passed through the funtion stack as a pointer to address.
// The Deteminete is returned at the end of the funtion call.
// This method for solving equations is called Cramer's rule
//******************************************************************************

float FindTheDetermint(void) {
    float det, part1, part2; //Define the determint as float.

    part1 = matx[0][0] * matx[1][1] * matx[2][2];

    det = (part1 + matx[1][0] * matx[2][1] * matx[0][2] + matx[2][0] * matx[0][1] * matx[1][2]);
    part2 = (matx[0][2] * matx[1][1] * matx[2][0] + matx[1][2] * matx[2][1] * matx[0][0] + matx[2][2] * matx[0][1] * matx[1][0]);
    det = det - (matx[0][2] * matx[1][1] * matx[2][0] + matx[1][2] * matx[2][1] * matx[0][0] + matx[2][2] * matx[0][1] * matx[1][0]);

    return (det);
}

int16 GetADCValue(int selection) {
    int16 ReturnedADC, Summer;
    int f;
    //setup_adc(ADC_CLOCK_INTERNAL);  //Setup the ADC to run..
    set_adc_channel(selection);
    //		delay_ms(10);
    Summer = 0;
    for (f = 0; f < 32; f++) {
        //delay_us(10);
        Summer = Summer + read_adc(); // Read adc channel 10 
    }
    ReturnedADC = Summer >> 5;
    return (ReturnedADC);
}



//*****************************************************************
// Created May 19, 2016
// This takes a sampling of the pHBulb and averages them all together.
// The result is the raw data from the ADC.  In this case it is connected to AD7
// It returns a float
//****************************************************************

float ConvertADCTophBulb(void) {
    int16 ReturnedADC;
    int x;
    float tempfloater, tempsummer;
    tempsummer = 0.0;
    for (x = 0; x < 10; x++) {

        ReturnedADC = GetADCValue(0); //This gets the current ADC conversion for the channel number.

        tempfloater = (float) ReturnedADC;
        tempsummer = tempsummer + tempfloater;

    }
    tempfloater = tempsummer / 10.0;
    return (tempfloater);
}

//*************************************************************
// Created May 15, 2015
// This routine solves for the coefficents for thermisters ai
// This routine reads the EEPROM (when completed) and calculates the curve and temperature from four thermal points.
//*************************************************************

void DetermineTempCoef(void) {
    //This has been removed and placed in TaosLightSensor.h  May 21, 2015
    //float temp1,reading1,temp2,reading2,temp3,reading3;
    float temp1in, temp2in, temp3in;
    float reading1in, reading2in, reading3in;
    float det, det1, det2, det3; //These are the other dets for each solution
    // This is the raw data.  Added May 15, 2015

    //temp1 = 40;    
    //temp2 = 21;
    //temp3 = 6;

    //***************************************************************************
    //Added January 13, 2015
    // These are the values used for the 10K reistor stolen from Animatics
    //***************************************************************************
    //reading1 = 5140;
    //reading2 = 13037;
    //reading3 = 27594;
    //***************************************************************************
    //Added January 13, 2015
    // These are the values used for the ?K reistor supplied by Rick
    //***************************************************************************

    //reading1 = 12000;   //this one is measured at 45 degrees C   // these numbers are for the 30K reistor
    //reading2 = 40000;   //this is measured at 22 C  Checked on May 14, 2015
    //reading3 = 72000;   // this tempature is measured at 12 degrees C


    temp1in = 1.0 / (temp1 + 273.0);
    temp2in = 1.0 / (temp2 + 273.0);
    temp3in = 1.0 / (temp3 + 273.0);


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
    tempa1 = det1 / det; //  This finds the value for the first a1

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
    tempa2 = det2 / det; //  This finds the value for the first a2



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
    tempa3 = det3 / det; //  This finds the value for the first a2


}


//*****************************************************************
// Created Nov. 6, 2012
// Converts the ADC number on a scale of 5 volts minus some for Op-amp issues
// The numerical convertion is conveted into degrees C.
// The returned value in C degrees.
//  Ths interm convertion is to Kalvin and will later be switched over to Kalvin scale.
//*****************************************************************

float ConvertADCToKalvin(int ADCInputNumber) {
    int16 ReturnedADC;
    float32 ADCVoltageIn, Kelvin, tempfloater;
    ReturnedADC = GetADCValue(ADCInputNumber); //This gets the current ADC convertion for the channel number.
    //    ADCVoltageIn = ReturnedADC * 5.0 / 1024.0;  //Recycled the same float variable.  This is for the 5 volts version.
    tempfloater = (float) ReturnedADC;
    // ADCVoltageIn = (float) ReturnedADC * 3.3 / 1024.0;  //Recycled the same float variable.  This converts the input into scaling
    ADCVoltageIn = (float) ReturnedADC * 5.0 / 1024.0; //Recycled the same float variable.  This converts the input into scaling

    //Added May 18, 2015  - The current/last thermister is RL0503-7.56K-96-MS  it's a 30K thermister.

    //	ADCVoltageIn = 5100.0*ADCVoltageIn/(3.3 - ADCVoltageIn);  // Calulate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K

    //ADCVoltageIn = 4999.0*ADCVoltageIn/(3.3 - ADCVoltageIn);  // Calculate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K
    ADCVoltageIn = 5100.0 * ADCVoltageIn / (5.0 - ADCVoltageIn); // Calculate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K



    DetermineTempCoef();

    //Kelvin = (1/(tempa1 + tempa2*(log(ADCVoltageIn)) + tempa3*(log(ADCVoltageIn)*log(ADCVoltageIn))))-273.15;   //This is the old line of code used to find the thermister temperature
    Kelvin = (1 / (tempa1 + tempa2 * (log(ADCVoltageIn)) + tempa3 * (log(ADCVoltageIn) * log(ADCVoltageIn)))) - 273.15;
    return (Kelvin);
}



//*********************************************************************
// Created June 25, 2015
// This routine calls the water temperature program and averages together twenty points.  Twenty two points are
// collected and the high and low reading is thrown out.  
// There is no input needed in this routine.  The result is returned as a float.
//*********************************************************************

float WaterTemperature(void) {
    float temparray[42], tempval;

    int switchflag, x; //This is used in the ordering routine to indicate if two numbers have been switched.  If not, then the array is in numerical order.

    for (x = 0; x < 42; x++) // Get all of the readings and save them in an array.
    {
        temparray[x] = ConvertADCToKalvin(1); //This called current thermisting reading routine. It returns a temperature reading in C.
    }

    //  Place the numbers in order in the array from the lowest reading at the high numbers indexs and the hightest readings at the low indexes.

    do {
        switchflag = 0; //Set it to zero indicating everything is in order.
        for (x = 0; x < 41; x++) {
            if (temparray[x] < temparray[x + 1]) {
                tempval = temparray[x];
                temparray[x] = temparray[x + 1];
                temparray[x + 1] = tempval;
                // Since this case is true, then switch the numbers in the array and set the not completed flag to 1.
                switchflag = 1; //  Indicate are reversal needed to be done.
            }
        }
    } while (switchflag == 1); //If the value is zero, the array is in order.


    //  Average the numbers between 1 and 21.  This will kick out the hightest and lowest readings.
    tempval = 0; //recycled the varaible used for averaging the readings together.
    for (x = 1; x < 41; x++) {
        tempval = tempval + temparray[x];
    }
    tempval = tempval / 40.0; //Divide the added number by 20 which is the number of values added together.


    return (tempval);
}


//******************************************************************************
// Created October 17, 2016
// This is a check sum for the data sent through the I2C back to the master.  The numbers are split and put into the
// last two locations of the upload send_buffer[].
//  Returns a 0 if there is no problem, It returns a 1 if there is a problem
//******************************************************************************

int CalculateCRC(void) {
    unsigned int16 checksum;
    unsigned int8 checksumhigh, checksumlow, x;
    for (x = 0; x < 98; x++) {
        checksum = checksum + rec_buffer[x];
    }
    //seperate the numbers into high and low
    checksumlow = 0x00FF & checksum;
    //  place the numbers in the array
    checksumhigh = (0xFF00 & checksum) >> 8;
    if ((checksumlow == rec_buffer[98]) && (checksumlow == rec_buffer[99])) {
        return (0); // no problem and the checksum matches
    } else {
        return (1); // someplace has an error and the checksum does not match.
    }
}



#INT_RDA

void RDA_isr() {
    int8 tbt;

    BTbuffer[BTnext_in] = fgetc(BT);
    tbt = BTnext_in;
    // putc(tbt,BT);
    //writeChar(tbt);
    BTnext_in = (BTnext_in + 1) % sizeof (BTbuffer);
    if (BTnext_in == BTnext_out) {
        BTnext_in = tbt; // Buffer full !!
    }
    //ADDED Crap
    if (BTnext_in == BT_BUFF_SIZE) {
        BTnext_in = 0;
    }
    //ADDED Crap
    if (BTnext_out == BT_BUFF_SIZE) {
        BTnext_out = 0;
    }

}


//******************************************************************************
// Created Febuary 12, 2017
// Get the version of the device.  This is used for checking if the device is plugged into the unit
// Command 0x40   It has been changed from 0x66 because of memory buffer size
// The correct returned value is 0xA9
int GetAnalogDONHFourVersion(int lightsensor)
	{
int version,returned,x;

	selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.

	i2c_start(PH_LIGHT);
 //       delay_ms(10);
    returned=i2c_write(PH_LIGHT,0xa0);  //Move the address number left on and add a zero.
    if (returned == 0x01)
    {
    i2c_stop(PH_LIGHT);   // perhaps a delay here
    return(0x1A);
    } 
 //   delay_ms(10);
    returned=i2c_write(PH_LIGHT,0x40);  //Send the command for reading the version
if (returned == 0x01)
    {
    i2c_stop(PH_LIGHT);   // perhaps a delay here
    return(0x1B);
    } 
  

returned=i2c_write(PH_LIGHT,0x01);  //Set the register to one to ask for the version number.
if (returned == 0x01) 
    {
    i2c_stop(PH_LIGHT);   // perhaps a delay here
    return(0x1C);
    }
//delay_ms(15);
	i2c_stop(PH_LIGHT);   // perhaps a delay here

    i2c_start(PH_LIGHT);


returned=i2c_write(PH_LIGHT,0xa1);  //Move the address number left on and add a one to make is a read command.
if (returned == 0x01) 
    {
    i2c_stop(PH_LIGHT);   // perhaps a delay here
    return(0x1D);
    }
 
    delay_ms(75);
	version = i2c_read(PH_LIGHT,FALSE);
 
i2c_stop(PH_LIGHT);   // perhaps a delay here
//return(0x88);
	return(version);
	}



//********************************************************************
// Created March 19, 2013
// Added to this routine Jan 24, 2017
// Get the version of the device.  This  routine is used for testing I2C.
// Command 0x04
// This routine returns the version of the light chip. 
//*********************************************************************
int getTAOSVersion(int lightsensor)
	{
int version;

	selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.


	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x84);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);
    i2c_start(PH_LIGHT,0);
	i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
	version = i2c_read(PH_LIGHT,0);
	i2c_stop(PH_LIGHT);

	return(version);
	}


//**********************************************************************
// Created March 19, 2013
// Power up light chip
// The value for light sensors is as follows:
// 1:PH
// 2:DO
// 3:General Light in the room
//  Updated December 8, 2015
//  StartupATOS is used for all six sensors.  The number of the sensor needs to be provided.
//**********************************************************************
void StartUpTAOS(int lightsensor)
	{

	selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communication is done through the I2C on PH_LIGHT.

	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x80);  //Send the command for reading the version
	i2c_write(PH_LIGHT,0x03);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);
	

	}


//***********************************************************************
// Created March 20, 2013
// This routine changes the exposure time for each sample.
//  There are three modes of intigration or exposure time per sample.
// 0 for 12ms
// 1 for 100 ms
// 2 for 400 ms
//***********************************************************************
void ExposureTimeTAOS(byte integration, byte lightsensor)
	{

	selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communication is done through the I2C on PH_LIGHT.


	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x81);  //Send the command for reading the Timing Register
	i2c_write(PH_LIGHT,integration);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);

	} 



//******************************************************************
//Created March 17, 2013
// This routine reads the all four inputs and returns the 16 bit value for that color.
// The value for color is as follows:
// 1:red
// 2:greem
// 3:blue
// 4:clear
// The retuened value is measured value.
//  This measurement is influnenced by the scalling factor for each ADC.
//  The two numbers are returned through tow global varibles.
//  The variables are colorlow and colorhigh.
// Added Oct 20, 2014 - Multi I2C lines can be used for each light sensor
// The value for light sensors is as follows:
// 1:PH
// 2:DO
// 3:General Light in the room
//******************************************************************
void ReadColorTAOS(int selectedcolor, int lightsensor)
	{

	switch(selectedcolor)
		{
		case 2:   //green
			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x90);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x91);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);
			break;


		case 1:   //red
			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x92);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x93);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);
			break;

		case 3:   //blue
			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x94);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x95);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);
			break;

		case 4:   //clear
			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x96);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x97);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);
			break;

		default:	
			break;
	}

}

#include <FindConnectedDevice.c>

//******************************************************************************
// Created Feb 18, 2017
// This routine inits all of the levels for the linear array chip to measure the mercury theomoeter
// Returns nothing
//******************************************************************************
void linearinit(void)
{
    
    //  Set up the output for the controls Si and CLK
    output_low(PIN_A4);
    // set up the output for the clock
    output_low(PIN_A5);
    
    
    
}

//******************************************************************************
// Created Feb 18, 2017
// this routine makes the exposure for the linear array and then places a reading in 
// an array for comparing to the scaling.  It also does level detention and scaling for high
// and low levels.
// It returns 0 if there is no problem
// A 1 is returned if there is a fault
//*****************************************************************************
int readlineararray(void)
{
    int x;
    unsigned int16 maxvalue = 0;
    unsigned int16 minvalue = 1024;
    char teststr2[20];
   
    set_adc_channel(0x01);
        delay_us(10);
        output_high(PIN_A4);  // SI
        output_high(PIN_A5);  // clock
        delay_us(10);//delay
        output_low(PIN_A4);  // SI
    for (x=0; x < 128; x++)  // loop through all of the clock cycles and recored the ADV from AN1 value
    {
        output_low(PIN_A5);
         reading[x]= read_adc(); // Read adc channel 1  
        //delay_us(5);  // delay for exposure?
        output_high(PIN_A5);
    }
        output_low(PIN_A4);  // when done, set low
        output_low(PIN_A5);    // when done, set low    
    
        
// Find the min and max value in the array.
        for (x=0; x < 128; x++)
        {
            if (reading[x] < minvalue)
                minvalue = reading[x];  // then new min value is set
              if (reading[x] > maxvalue)
                maxvalue = reading[x];  // then new min value is set          
        }
  //     sprintf(teststr2,"%Lu   %Lu    ",maxvalue,minvalue);
 //      writeString(0, 3, teststr2);        
        //remove the minvalue from the whole array
        for (x=0; x < 128; x++)
        {
            reading[x] = reading[x] - minvalue;
        }    
        maxvalue = (maxvalue - minvalue);
        
 //      sprintf(teststr2,"%Lu   ",maxvalue);
 //      writeString(0, 2, teststr2); 
       
       
        displaybar(maxvalue, 2);
        
    
        
    return(0);
}

void main(void) {
    //i2c_init(TRUE);

    int8 adcStrCntr;
    char teststr2[10];
    int8 deviceid,deviceidreturn;  // this is device ID that indicates what's plugged in.  A 1 means no device is plugged in.
    float tempvar;
    int16 tempvarint;
    BTnext_in = 0;
    BTnext_out = 0;


    sysInput.eccal1x = 4000.0; //  This the EC data point  Added July 18, 2016
    sysInput.eccal2x = 1100.0; //  This the EC data point  Added July 18, 2016
    sysInput.eccal3x = 200.0; //  This the EC data point  Added July 18, 2016
    sysInput.eccal1y = 150.0; //  This the EC data point  Added July 18, 2016
    sysInput.eccal2y = 603.0; //  This the EC data point  Added July 18, 2016
    sysInput.eccal3y = 10000.0; //  This the EC data point  Added July 18, 2016

    sysInput.phcallow = 250;
    sysInput.phcalhigh = 500;
    sysInput.phnumberupper = 10;

    linearinit();
    initDispIO();
    delay_ms(2000);    /// delay the display from coming up or the CPU will not stay booted.
    initDisplay();    
    splash();

    //**************************************************
    // Created Nov 22, 2106
    // Get the saved configurations from the EEPROM and put them in local variables.
    //**************************************************
    selectitem = getlocalconfigurations(); // this gets the items for local configuration
    LoadConfigurations();
    fprintf(BT, "Command Line Processor\r\n>");
    fprintf(BT, "Press ? and CR for a list of commands\r\n>");
     
    setup_adc_ports(sAN0|sAN1|sAN2|sAN3|VSS_VDD);   // AN1 is the linear array
    setup_adc(ADC_CLOCK_INTERNAL);
    enable_interrupts(GLOBAL);
    enable_interrupts(INT_RDA); //This starts up s the Blue tooth module enterupt for taking in charters.  Added July 8, 2015

    
   //************************************************************************
   // Added Jan 23, 2017
   // This routine cycles through all of the possible i2c devices to determine which one is plugged in.
   //************************************************************************
   deviceidreturn=0x02;
   
  // this is used for debugging and building new routines
 //  while(1)
 //  {
 //       readlineararray();
       // sprintf(teststr2,"%x",deviceid);
       // writeString(0, 0, teststr2);
     //   delay_ms(100);
        
 //  }
  
   
   while(1)   
   {
    deviceid = FindRJ45Device(0x01,deviceidreturn);
    deviceidreturn = deviceid;
    if (deviceid==0x22)
    { 
       deviceid = TestRHTemp();
       deviceidreturn = deviceid;
    }
    
    if (deviceid==0x23)
    {
       deviceid = TestPARchip();
       deviceidreturn = deviceid;
    }
    
    if (deviceid==0x24)  // this is for Analog DO and NH4
    {
       deviceid = TestAnalogDONHFourBoard();
       deviceidreturn = deviceid;
    }
    if (deviceid==0x25)  // this is for Analog DO and NH4
    {
       deviceid = TestDigitalDONHFourBoard();
       deviceidreturn = deviceid;
    }
    if (deviceid==0x26)  // this is for Analog DO and NH4
    {
       deviceid = TestCO2Board();
       deviceidreturn = deviceid;
    }
    BTTestEvent(); // check for the data coming back to display   
    BTTestEvent(); // check for the data coming back to display 
    BTTestEvent(); // check for the data coming back to display   
    BTTestEvent(); // check for the data coming back to display 
    BTTestEvent(); // check for the data coming back to display   
    BTTestEvent(); // check for the data coming back to display 
    
    
    //**************************************************************************
    // Update Feb 11, 2017
    // This section takes the global flag for startupdate and sends the lateset varaibel configuration to the remote devie.
    // There needs to be an added check the remote device is attached.
    //  It needs to be read back and confirmed after sending it to the remote device, saving it in EEPROM, re-read from EEPROM and sent back to this host.
    //  1  Send data to remote device
    //  2  Save varaible data in remote EEPROM device
    //  3  re-read the data from the EEPROM in the remote device
    //  4  send it back to this host
    //  5  Compare it with the orginal data
    //  6  Send an error if there is a difference.
    //**************************************************************************
        if (startupdate)
        {
          //  while(1)
         //   {
                stuffit = 1069;
                startupdate = 0;  // this sets the flag to do an update to the remote unit when all data polling is completed.
                fprintf(BT,"Sending Updated Configurations\n\r");
                sendConfigData(0x01, 0x03);   //device 1 or the top connector
                fprintf(BT,"Update Completed\r\n");
         //   }
        }
    
   }
    
}
