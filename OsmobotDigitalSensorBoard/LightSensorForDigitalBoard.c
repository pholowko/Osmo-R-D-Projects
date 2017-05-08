

#ifndef byte
#define byte int8
#endif

//Timing Register
#define SYNC_EDGE 0x40
#define INTEG_MODE_FREE 0x00
#define INTEG_MODE_MANUAL 0x10
#define INTEG_MODE_SYN_SINGLE 0x20
#define INTEG_MODE_SYN_MULTI 0x30
 


float tempa1, tempa2, tempa3;   //Addded May 15, 2014 These are the coefecents for thermister calculation
void selectsensor(int number);
float FindpHEquation(void);
int colorlow, colorhigh;   // gain, scale;  //This is the pair of bytes used to return the current selected color.
unsigned int16 red,green,blue,clear;
//int32 scaledred, scaledgreen, scaledblue;   // Added May 6, 2014  These are large number to hold the gain of the intensity

//*************************************************************************************
//Created March 4, 2015
// The Exposurescale is used for the preprocessor to scale down the ADC.  Each light sensor has a different scaling.
// Below is a table showing the values for each exposure scale down for the ADC.
//  000            Divide by 1
//  001            Divide by 2
//  010            Divide by 4
//  011            Divide by 8
//  100            Divide by 16
//  101            Divide by 32
//  110            Divide by 64
//  111            Does not exist and is not used.
//************************************************************************************

byte ExposurescaleDO = 0;   //This is the global variable used for prescaler for the ADC
byte ExposurescalepH = 0;   //This is the global variable used for prescaler for the ADC 
byte ExposurescaleLight = 2;   //  This used to be 2.  This is the global variable used for prescaler for the ADC   Three is used to divide by 4
float x,y,z;  //Color chart positions,coored.

//************************************************************
//Define the 3X4 matrix for solving three unknown equations.
float matx[3][3];  //This is the global diffinition of solving a 3X3 matrix equation. This is a scrach pad matrix used to pass arrays between functions. Added May 13, 2013
float matrixequation[3][3]; //  Added May 13, 2013  This is the array used for setting up the eqaution for solving a 3X3 equation.
//float fourbyfourmatrix[4][4];
float matrixequals[3]; 
// Added April 27, 2014  
// Matrixequals is used for place the results of all three equations.
// This is used to subsitue into the 3X3 matrix for finding the DET.
float MatrixSolution[3]; 
// Added April 27, 2014  This matrix saves the
// result for the 3X3 unknown solution.
float TempCalmatrix[4][3];  //This matrix holds the temperatures and K1, K2 and Iohhh values.
float pk, slope;  //these are the varaibles used for ph calcualtions
float lastphreading = -0.1;   //This is the last compare start up.  It's negative to start the current reading.
//**************************************************************


//******************************************************************
// Added Dec 8, 2014
// These varaibles are used for optical offsets for ph and DO.
//******************************************************************
signed int32		AmbientOxyRed;
signed int32		AmbientOxyGreen;
signed int32		AmbientOxyBlue;
signed int32		AmbientOxyClear;
signed int32		AmbientPHRed;
signed int32		AmbientPHGreen;
signed int32		AmbientPHBlue; 
signed int32		AmbientPHClear; 
signed int32		Ambientnh3Red;
signed int32		Ambientnh3Green;
signed int32		Ambientnh3Blue; 
signed int32		Ambientnh3Clear; 

//************************************************************************
//Added December 12, 2014
// These varaibles are used for each color absolute.  These numbers combined with the gain.
//  They are 32 bits long
//************************************************************************
signed int32 redABS;
signed int32 blueABS;
signed int32 greenABS;
signed int32 clearABS;


//******************************************************************
// K1 and K2 are two constants caluclated from calibration constants saved in EEPROM.
// The rest of the constants are used for calculating K1, K2 and Iohhh against temperature.
//  Added April 27, 2014
//******************************************************************
float K1, K2, K1Temp,K2Temp;   // Added April 6, 2015  These are all of the K values for DO temperature and non temperature compensation.
float RatioI, RatioII, Iohhh;
float atwo, btwo, ctwo;   //no Temp compensated DO

//****************************************************************
// Created/Moved May 20, 2015
// These varabbles are moved here to be global.
//  They are all for the DO only.
//****************************************************************
int debugnumber = 0;  //Added July 13, 2015.  It keeps the current state of the debug routine calls.  Default is zero; or not in debug/calibration mode.



    
    float wTemp = 20.0;



//*********************************************************************************
// The defs below are for pH
//************************************************************************************
	float pHHigh, pHMiddle, pHLower;
    float pHHighCalibration,pHMiddleCalibration,pHLowerCalibration;

//*********************************************************************************
// Added May 21, 2015
// This is the calibrations for temperature on the thermister for water
//*********************************************************************************

//	float temp1,reading1,temp2,reading2,temp3,reading3;
	int32 BlueLimit,WhiteLimit;  //This is the limit variable off the SD Card for the desiged light intesity.
	float StartWaterTemperature;  //This is the varaible used to keep track of the init water temperature for hose air expansion.



//************************************************************
// Added December 1, 2014
// These variables will keep the last intensity
unsigned int16 PWMDOIntensity;
unsigned int16 PWMPHIntensity;
unsigned int16 PWMnh3Intensity;
int32 DOreadingrange = 250;    //These are the starting values for the tolorance ranges for DO and pH  Added July 27, 2015
int32 pHreadingrange = 200;


//******************************************************************************
// Created May 13, 2013
// This routine returns the determinent for a given 3X3 mastrix passed through the funtion stack as a pointer to address.
// The Deteminete is returned at the end of the funtion call.
// This method for solving equations is called Cramer's rule
//******************************************************************************
float FindTheDetermint(void)
	{
	float det,part1,part2;  //Define the determint as float.

    part1=matx[0][0]*matx[1][1]*matx[2][2];

	det = (part1 + matx[1][0]*matx[2][1]*matx[0][2] + matx[2][0]*matx[0][1]*matx[1][2]); 
    part2 = (matx[0][2]*matx[1][1]*matx[2][0] + matx[1][2]*matx[2][1]*matx[0][0] + matx[2][2]*matx[0][1]*matx[1][0]);
	det = det - (matx[0][2]*matx[1][1]*matx[2][0] + matx[1][2]*matx[2][1]*matx[0][0] + matx[2][2]*matx[0][1]*matx[1][0]);

	return(det);
	}

//******************************************************************************
// Created May 13, 2013
// This routine is a general purpose solution for three unknowns given the coefficents of all three equations and what they eqaul.
// The coefficents are given as a matrix of 3X3 in an 3X3 array of floats starting with 0 to 2.  The results are placed in the last colomum of of the 3X3 matrix.
// The routines uses a series of deteminets to solve the problems.
//******************************************************************************
void ThreeByThreeSolution(void)
	{

	float det, detx, dety, detz;
	int x, y;

// this finds the common det for the whole matrix
//  Move the exisitng array into the scratch pad marix  matx
	for (x=0; x < 3; x++)
		{
		for (y=0; y < 3; y++)
			{
			matx[x][y] = matrixequation[x][y];   //Move this element into the scrach matrix.
			}
		}
/*
	matx[0][0] = 1.0;  //this for testing the deteminte routine.
	matx[1][0] = 0.0;  // remove all of this when completed.
	matx[2][0] = 3.0;    // Example 
	matx[0][1] = 2.0;    //  1.0  0.0  3.0
	matx[1][1] = 1.0;    //  2.0  1.0  0.0
	matx[2][1] = 0.0;    //  4.0  1.0  0.0
	matx[0][2] = 4.0;
	matx[1][2] = 1.0;
	matx[2][2] = 0.0;
*/
	det = FindTheDetermint();


//  Move the exisitng array into the scratch pad matrix  matrix
	for (x=0; x < 3; x++)
		{
		for (y=0; y < 3; y++)
			{
			matx[x][y] = matrixequation[x][y];   //Move this element into the scrach matrix.
			}
		}
		for (y=0; y < 3; y++) //move the first colunm into the x
			{
                 matx[0][y] = matrixequals[y];
			}

	detx = FindTheDetermint(); //find the detmeinent
      MatrixSolution[0] = detx/det; //Stuff the results in the x location

//  Move the exisitng array into the scratch pad matrix  matrix
	for (x=0; x < 3; x++)
		{
		for (y=0; y < 3; y++)
			{
			matx[x][y] = matrixequation[x][y];   //Move this element into the scrach matrix.
			}
		}
		for (y=0; y < 3; y++) //move the first colunm into the x
			{
                 matx[1][y] = matrixequals[y];
			}

	dety = FindTheDetermint(); //find the detmeinent
      MatrixSolution[1] = dety/det; //Stuff the results in the x location


//  Move the exisitng array into the scratch pad matrix  matrix
	for (x=0; x < 3; x++)
		{
		for (y=0; y < 3; y++)
			{
			matx[x][y] = matrixequation[x][y];   //Move this element into the scrach matrix.
			}
		}
		for (y=0; y < 3; y++) //move the first colunm into the x
			{
                 matx[2][y] = matrixequals[y];  // replace the colunm
			}

	detz = FindTheDetermint(); //find the detmeinent
      MatrixSolution[2] = detz/det; //Stuff the results in the x location

	}

#ifdef TESTER

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
void selectsensor(int number)
	{
//fprintf(BT,"Device Number Selected %i\n\r",sensor number);
	if (number > 3)   // Set the high bit
		{
		number = number - 4;    // Remove the offset so the bottom part of the byte can be accessed
		}

	if (number == 0)   // Set the lower bits.
		{
		output_low(SENSORBOARDA);   // This is connected to the input for the A on both 74139 chips.
		output_low(SENSORBOARDB);   // This is connected to the input for the B on both 74139 chips.
		}

	if (number == 1)
		{
		output_high(SENSORBOARDA);   // This is connected to the input for the A on both 74139 chips.
		output_low(SENSORBOARDB);   // This is connected to the input for the B on both 74139 chips.
		}
	if (number == 2)
		{
		output_low(SENSORBOARDA);   // This is connected to the input for the A on both 74139 chips.
		output_high(SENSORBOARDB);   // This is connected to the input for the B on both 74139 chips.
		}
	if (number == 3)
		{
		output_high(SENSORBOARDA);   // This is connected to the input for the A on both 74139 chips.
		output_high(SENSORBOARDB);   // This is connected to the input for the B on both 74139 chips.
		}

	}

#endif





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
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x98);  //Send the command for reading the green light low byte
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);   // read the low byte
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x99);  //Send the command for reading the high byte
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);  // read the high byte
			i2c_stop(PH_LIGHT);
			break;


		case 1:   //red
			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x96);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x97);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);
			break;

		case 3:   //blue
			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x9A);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x9B);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);
			break;

		case 4:   //clear
			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x94);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);

			i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
			i2c_write(PH_LIGHT,0x95);  //Send the command for reading the version
			i2c_stop(PH_LIGHT);

    		i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(PH_LIGHT,0);
			i2c_stop(PH_LIGHT);
			break;

		default:	
			break;
	}

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
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x80);  //Send the command for reading the version 
    //  0x01 turns on chip
    //  0x03 turns on and starts taking a reading
    
	i2c_write(PH_LIGHT,0x01);  //Send the command for turning on the chip only  
	i2c_stop(PH_LIGHT);
    
    delay_ms(3);
    // WLONG configuration.  0x00 is off
    //                       0x02 is on
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x8D);  //Send the command for reading the version 
    //  0x01 turns on chip
    //  0x03 turns on and starts taking a reading
    
	i2c_write(PH_LIGHT,0x00);  //Send the command for turning on the chip only  
	i2c_stop(PH_LIGHT);
   
    
    
	}



//********************************************************************
// Created March 17, 2013
// This routine changes the gain/scaling routine for each color/ADC.
// The passed varaible is the gain for the ADC.  All colors get the same gain.
//  AnalogGain is a value between 0 to 3.  
//  0 is 1X
//  1 is 4X
//  2 is 16X
//  3 is 64X
//Prescaler are values between 0 and 6.  0 is div by 1; 6 is divide by 64.
// Added Oct 20, 2014
//  The lightsensor is added to select which sensor we want to use
// The value for light sensors is as follows:
// 1:PH
// 2:DO
// 3:General Light in the ROOM
//********************************************************************
void setTAOSGain(int lightsensor)
	{
byte controlword,Integrationtime,again;

float tempowrd;

Integrationtime = 0;   // set it to this value if nothing else takes it.


if (lightsensor==3)   // changed March 23, 2016.  The passing number is the true sensor number, not the index   Used to be 1
	{
    Integrationtime = 100;
    again = 0x03;
	//PrescalerGain = ExposurescaleDO;
	}

if (lightsensor==1)  // changed March 23, 2016.  The passing number is the true sensor number, not the index   Used to be 2
	{
	//PrescalerGain = ExposurescalepH;
    Integrationtime = 100;
    again = 0x03;
	}

if (lightsensor==0)   // This is now for NH4
	{
    //PrescalerGain = ExposurescaleLight;
	Integrationtime = 100;
    again = 0x03;
	}


// Concatinate the control byte.
//controlword = AnalogGain*16 + PrescalerGain;  //This is the offset for gain to placeinto the chip.  Added March 4, 2015
// Calculate the integtation time
tempowrd = (float) Integrationtime;
tempowrd = tempowrd / 2.4;
Integrationtime = (byte) tempowrd;
controlword = 256 - Integrationtime;


selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.
// Added April 26, 2017
// Update intigration time
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x81);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(PH_LIGHT,controlword);  //Move the address number left on and add a zero.
	i2c_stop(PH_LIGHT);
	
    
    // Added April 26, 2017
    // Update the wait/delay time
    
  	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x83);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(PH_LIGHT,0xff);  //Move the address number left on and add a zero.
	i2c_stop(PH_LIGHT);  
    
    
    
    // Added April 26, 2017
    // Updates the again
    
  	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x8F);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(PH_LIGHT,again);  //Move the address number left on and add a zero.
	i2c_stop(PH_LIGHT);  
    
     
    
	}

//******************************************************************************************
// Created April 26, 2014
// This routine finds the color light for any of four spectrum devices.  The inputs for GainIn are as follows:
//  4:  Determine the gain for what ND to use where all of the colors are not saturated.
//  0 is 1X
//  1 is 4X
//  2 is 16X
//  3 is 64X
//  These are the same numbers used by the chip
//  The returned result of the function is always the gain used.  For instance if a predetemined gain is used, that gain
// is returned.  If the automatic gain is used, the detemine gain is returned, not the number 4.
//  All colors are returned as global varaibles for other routines to use.
// *********************
// The inputs for the chip select is as follows:
// 0: Number 1
// 1: Number 2
// 2: Number 3
// 3: Number 4  - this number does not exist on the Osmobot as is because thing is connected to it.
// The colors are returned in the global variables as follows:
// green, red, blue and clear
//  When a device is not selected correctly, the number 0xFF is returned as an error on the I2C.
//******************************************************************************************

int8 GetCurrentColor(int8 GainIn, int8 DeviceSelect)
	{

//  Set the device to be processed
    int x,returned;
    
unsigned int gainMultiplyer;

		setTAOSGain(DeviceSelect); //Gain and then scale

        // created April 26, 2017
        // this new sections starts itegration and waits for the chip to be ready for reading.
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x80);  //Send the command for reading the version
    
    //  0x01 turns on chip
    //  0x03 turns on and starts taking a reading
    
	i2c_write(PH_LIGHT,0x03);  //Send the command for turning on the chip only and starts integration  
	i2c_stop(PH_LIGHT);
    delay_ms(10);
    // loop until reading AVALID
    for (x=0; x < 1000; x++)
    {
        // exit loop when the AVAILD is high
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x93);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
	returned = i2c_read(PH_LIGHT,0);
	i2c_stop(PH_LIGHT);
    
  //  delay_ms(150);
    if (returned == 0x11)
        break;
 //    return(returned);  
    }
    
 
    if (x > 990)
        return(0xFF);   // if the loop fails, then return 0xFF for showing the device does not work.  It does not hang up.
        
    
    // Turn off intigration
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x80);  //Send the command for reading the version
    
    //  0x01 turns on chip
    //  0x03 turns on and starts taking a reading
    
	i2c_write(PH_LIGHT,0x01);  //Send the command for turning off the chip only  
	i2c_stop(PH_LIGHT);
    delay_ms(3);
    
    
    
		ReadColorTAOS(2,DeviceSelect);  //green

		green = colorlow + colorhigh * 256;

		ReadColorTAOS(1,DeviceSelect);  //red
		red = colorlow + colorhigh * 256;

		ReadColorTAOS(4,DeviceSelect);  //clear
		clear = colorlow + colorhigh * 256;

		ReadColorTAOS(3,DeviceSelect);  //blue
		blue = colorlow + colorhigh * 256;

//*****************************************************************
// Created December 12, 2014
// This section changes each color to an ABS color using the gainIn scales
//*****************************************************************

		if (GainIn == 0)
			{
			gainMultiplyer =  1;
			}
		if (GainIn == 1)
			{
			gainMultiplyer =  4;
			}
		if (GainIn == 2)
			{
			gainMultiplyer =  16;
			}
		if (GainIn == 3)
			{
			gainMultiplyer =  64;
			}
		redABS = (unsigned int32) red * (unsigned int32) gainMultiplyer;
		greenABS = (unsigned int32) green * (unsigned int32) gainMultiplyer;
		blueABS = (unsigned int32) blue * (unsigned int32) gainMultiplyer;
		clearABS = (unsigned int32) clear * (unsigned int32) gainMultiplyer;
		return(GainIn);

		}

//*******************************************************************************************
// Created May 4, 2017
//  This takes several color readings and then averages them together.  This is a direct drop in
// for the current "int8 GetCurrentColor(int8 GainIn, int8 DeviceSelect)"
// Returns the gain and the returned value is in the global varaibles called
// red, green , blue and clear.
//  Changed May 18, 2015  
// The below routine is changed from 20 samples to 200 to get the stability down
//*******************************************************************************************
void GetCurrentColorAVG(int8 GainIn, int8 DeviceSelect)
	{
float tempred, tempblue, tempgreen, tempclear, ageraging;   //These are the averaging varaibles used for internal to the averaging calculations
float ttred, ttgreen,ttblue,ttclear;
int x,GainOut,averagesamples = 12;
unsigned int gainMultiplyer;

//******************************************************************************
// Created May 3, 2017
// Added an array of numbers for averaging.  The high and low is throuwn out
//******************************************************************************
int32 arrayred[12];
int32 arraygreen[12];
int32 arrayblue[12];
int32 arrayclear[12];
int32 tempvar;
int done;

	tempred = 0.0;
	tempblue = 0.0;
	tempgreen = 0.0;
	tempclear = 0.0;
    ageraging = (float) averagesamples - 2.0;
    // Get the data and put it into an array
	for (x = 0; x < averagesamples; x++)
		{
		GainOut = GetCurrentColor(GainIn, DeviceSelect);
        arrayred[x] = redABS;
        arraygreen[x] = greenABS;
        arrayblue[x] = blueABS;
        arrayClear[x] = clearABS;
		}
    
    // put the array in order
    
    done=0;  // set the first flag to get out.
    while(!done)
    {
        done = 1;
        for (x=0; x < 11; x++)
        {
           if  (arrayclear[x] > arrayclear[x+1])
           {
              done = 0;  // go for another round 
               tempvar = arrayclear[x];
               arrayclear[x] = arrayclear[x+1];
               arrayclear[x+1] = tempvar;
               
               tempvar = arrayred[x];
               arrayred[x] = arrayred[x+1];
               arrayred[x+1] = tempvar;
               
               tempvar = arraygreen[x];
               arraygreen[x] = arraygreen[x+1];
               arraygreen[x+1] = tempvar;
               
               tempvar = arrayblue[x];
               arrayblue[x] = arrayblue[x+1];
               arrayblue[x+1] = tempvar;
           }
        }

    }
    
    // average them all together
    // throw out the high and low number of Clear
    
    for (x=1; x < 11; x++)
    {
   
        ttred = (float) arrayred[x];
        ttclear = (float) arrayclear[x];
        ttgreen = (float) arraygreen[x];
        ttblue = (float) arrayblue[x];       
    // if (DeviceSelect == 0x03)   
    // {
        tempred = tempred + ttred/ttclear;
		tempblue = tempblue + ttblue/ttclear;
		tempgreen = tempgreen + ttgreen/ttclear;
		tempclear = tempclear + ttclear;
    // }
    // else
   //  {
     //   tempred = tempred + ttred;
	//	tempblue = tempblue + ttblue;
	//	tempgreen = tempgreen + ttgreen;
	//	tempclear = tempclear + ttclear;         
   //  }
    }
	tempred = (tempred*10000.0)/ageraging;
	tempblue = (tempblue*10000.0)/ageraging;
	tempgreen = (tempgreen*10000.0)/ageraging;
	tempclear = tempclear/ageraging;
	redABS = (unsigned int32) tempred;
	blueABS = (unsigned int32) tempblue;
	greenABS = (unsigned int32) tempgreen;
	clearABS = (unsigned int32) tempclear;

	}

//***************************************************************************************
// Created Dec. 8, 2014
// This routine find the ambiant light and saves it as global variables for ph and DO routines to use.
//  The input is the selected sensor with the LED turned off.  The results are saved.
// Changed December 12, 2014
//  Removed the averaging part of the program and used the GetCurrentColorABS program instead
//  It has twice as many reading for averaging.
//***************************************************************************************
void FindAmbientLight(int DeviceSelect)
	{
		GetCurrentColorAVG(3,DeviceSelect);

	if (DeviceSelect == 1)   //Setup the OXyegen offsets.
		{
		AmbientOxyRed = redABS;
		AmbientOxyGreen = greenABS;
		AmbientOxyBlue = blueABS;
		AmbientOxyClear = clearABS;
		}

	if (DeviceSelect == 2)  //Setup the PH offsets.
		{
		AmbientPHRed = redABS;
		AmbientPHGreen = greenABS;
		AmbientPHBlue = blueABS;
		AmbientPHClear = clearABS;
		}
        
       if (DeviceSelect == 9)  //Setup the PH offsets.
		{
		Ambientnh3Red = redABS;
		Ambientnh3Green = greenABS;
		Ambientnh3Blue = blueABS;
		Ambientnh3Clear = clearABS;
		}

	}




//********************************************************************
// Created March 19, 2013
// Get the version of the device.  This  routine is used for testing I2C.
// Command 0x04
// This routine returns the version of the light chip. 
//*********************************************************************
int8 getTAOSVersion(int lightsensor)
	{
int8 version;

	selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.


	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x52);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x92);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x53);  //Move the address number left on and add a one to make is a read command.
	version = i2c_read(PH_LIGHT,0);
	i2c_stop(PH_LIGHT);

	return(version);
	}


//***********************************************************************
// Created March 20, 2013
// This routine changes the exposure time for each sample.
//  There are three modes of intigration or exposure time per sample.
// 0 for 12ms
// 1 for 100 ms
// 2 for 400 ms
// The value for light sensors is as follows:
// 1:PH
// 2:DO
// 3:General Light in the room
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







//*****************************************************************************************
// Created April 27, 2014
//This routine inits all of the slave I2C where they have a gain of 1 and start with no ND filteration

//NOTE: INTEG_MODE and TIME/COUNTER fields should be written before ADC_EN is asserted.
//FIELD VALUE NOMINAL INTEGRATION TIME 
//0000                12 ms 
//0001                100 ms 
//0010                400 ms
//*****************************************************************************************
void InitTAOS(void)
{

int8 x;


// turn on chips  and wait for 2.4 ms.  Only turn on chips, do not start intigration

StartUpTAOS(0x00);  // this starts up the integration time for the DO light sensor
StartUpTAOS(0x01);  // this starts up the integration time for the DO light sensor
StartUpTAOS(0x03);  // this starts up the integration time for the DO light sensor

delay_ms(3);    // wait for time to expire
}



//*************************************************************************
// Created November 14, 2016
// This routine runs the self test for all of the LEDs on the board.
// The routine returns nothing.
//*************************************************************************
void LEDtest(void)
{
    //  turn off all LEDs
    output_low(PIN_B12);    // turn off the blue light
    
    output_low(PIN_B5);  // turn off orange DpH LED
    output_high(PIN_B11);  // turn off blue
    output_low(PIN_B10);  // turn off NH4
 
    
    output_high(PIN_B5);  // turn on white DpH LED
    delay_ms(250);
    output_low(PIN_B5);  // turn off orange DpH LED
    output_low(PIN_B12);  // turn on blue for DO   
     delay_ms(250);
    output_low(PIN_B12);  // turn off blue DO
    output_high(PIN_B10);  // turn on NH4  
    delay_ms(250);


    output_low(PIN_B11);  // turn off blue
    output_low(PIN_B10);  // turn off red
    output_low(PIN_B5);  // turn off red for p 
    delay_ms(250);
}