


#ifndef byte
#define byte int8
#endif
#define COLOR_SENSOR_ADDR  0x39//the I2C address for the color sensor 
#define REG_CTL 0x80
#define REG_TIMING 0x81
#define REG_INT 0x82
#define REG_INT_SOURCE 0x83
#define REG_ID 0x84
#define REG_GAIN 0x87
#define REG_LOW_THRESH_LOW_BYTE 0x88
#define REG_LOW_THRESH_HIGH_BYTE 0x89
#define REG_HIGH_THRESH_LOW_BYTE 0x8A
#define REG_HIGH_THRESH_HIGH_BYTE 0x8B
#define REG_BLOCK_READ 0xCF
#define REG_GREEN_LOW 0xD0
#define REG_GREEN_HIGH 0xD1
#define REG_RED_LOW 0xD2
#define REG_RED_HIGH 0xD3
#define REG_BLUE_LOW 0xD4
#define REG_BLUE_HIGH 0xD5
#define REG_CLEAR_LOW 0xD6
#define REG_CLEAR_HIGH 0xD7
#define CTL_DAT_INIITIATE 0x03
#define CLR_INT 0xE0
//Timing Register
#define SYNC_EDGE 0x40
#define INTEG_MODE_FREE 0x00
#define INTEG_MODE_MANUAL 0x10
#define INTEG_MODE_SYN_SINGLE 0x20
#define INTEG_MODE_SYN_MULTI 0x30
 
#define INTEG_PARAM_PULSE_COUNT1 0x00
#define INTEG_PARAM_PULSE_COUNT2 0x01
#define INTEG_PARAM_PULSE_COUNT4 0x02
#define INTEG_PARAM_PULSE_COUNT8 0x03

#define GAIN_1 0x00
#define GAIN_4 0x10
#define GAIN_16 0x20
#define GANI_64 0x30
#define PRESCALER_1 0x00
#define PRESCALER_2 0x01
#define PRESCALER_4 0x02
#define PRESCALER_8 0x03
#define PRESCALER_16 0x04
#define PRESCALER_32 0x05
#define PRESCALER_64 0x06

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
byte ExposurescalepH = 3;   //This is the global variable used for prescaler for the ADC 
byte ExposurescaleLight = 2;   //This is the global variable used for prescaler for the ADC   Three is used to divide by 4
float x,y,z;  //Color chart positions,coored.

//************************************************************
// Added December 1, 2014
// These varaibles will keep the last intensity
unsigned int16 PWMDOIntensity;
unsigned int16 PWMPHIntensity;
//************************************************************
//Define the 3X4 matrix for solving three unknown equations.
float matx[3][3];  //This is the global diffinition of solving a 3X3 matrix equation. This is a scrach pad matrix used to pass arrays between functions. Added May 13, 2013
float matrixequation[3][3]; //  Added May 13, 2013  This is the array used for setting up the eqaution for solving a 3X3 equation.
float fourbyfourmatrix[4][4];
float matrixequals[3]; 
// Added April 27, 2014  
// Matrixequals is used for place the results of all three equations.
// This is used to subsitue into the 3X3 matrix for finding the DET.
float MatrixSolution[3]; 
// Added April 27, 2014  This matrix saves the
// result for the 3X3 unknown solution.
float TempCalmatrix[4][3];  //This matrix holds the temperatures and K1, K2 and Iohhh values.
float pk, slope;  //these are the varaibles used for ph calcualtions
//**************************************************************


//******************************************************************
// Added Dec 8, 2014
// These varaibles are used for optical offsets for ph and DO.
//******************************************************************
unsigned int32		AmbientOxyRed;
unsigned int32		AmbientOxyGreen;
unsigned int32		AmbientOxyBlue;
unsigned int32		AmbientOxyClear;
unsigned int32		AmbientPHRed;
unsigned int32		AmbientPHGreen;
unsigned int32		AmbientPHBlue; 
unsigned int32		AmbientPHClear; 


//************************************************************************
//Added December 12, 2014
// These varaibles are used for each color absolute.  These numbers combined with the gain.
//  They are 32 bits long
//************************************************************************
unsigned int32 redABS;
unsigned int32 blueABS;
unsigned int32 greenABS;
unsigned int32 clearABS;


//******************************************************************
// K1 and K2 are two constans caluclated from calibration constants saved in EEPROM.
// The rest of the constants are used for calculating K1, K2 and Iohhh against temperature.
//  Added April 27, 2014
//******************************************************************
float K1, K2;
float RatioI, RatioII, Iohhh;
float atwo, btwo, ctwo;

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


if (lightsensor==2)
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


if (lightsensor==1)
	{
	switch(selectedcolor)
		{
		case 2:   //green
			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x90);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);

			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x91);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);
			break;


		case 1:   //red
			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x92);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);

			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x93);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);
			break;

		case 3:   //blue
			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x94);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);

			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x95);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);
			break;

		case 4:   //clear
			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x96);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);

			i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(DO_LIGHT,0x97);  //Send the command for reading the version
			i2c_stop(DO_LIGHT);

    		i2c_start(DO_LIGHT);
			i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(DO_LIGHT,0);
			i2c_stop(DO_LIGHT);
			break;

		default:	
			break;
		}
	}



if (lightsensor==3)
	{
	switch(selectedcolor)
		{
		case 2:   //green
			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x90);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);

			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x91);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);
			break;


		case 1:   //red
			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x92);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);

			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x93);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);
			break;

		case 3:   //blue
			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x94);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);

			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x95);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);
			break;

		case 4:   //clear
			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x96);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);

			i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
			i2c_write(ROOM_LIGHT,0x97);  //Send the command for reading the version
			i2c_stop(ROOM_LIGHT);

    		i2c_start(ROOM_LIGHT);
			i2c_write(ROOM_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(ROOM_LIGHT,0);
			i2c_stop(ROOM_LIGHT);
			break;

		default:	
			break;
		}
	}  

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
//Prescaler are values btween 0 and 6.  0 is div by 1; 6 is divide by 64.
// Added Oct 20, 2014
//  The lightsensor is added to select which sensor we want to use
// The value for light sensors is as follows:
// 1:PH
// 2:DO
// 3:General Light in the ROOM
//********************************************************************
void setTAOSGain(byte AnalogGain, int lightsensor)
	{
byte controlword,PrescalerGain;

controlword = 0;


if (lightsensor==1)
	{
	PrescalerGain = ExposurescaleDO;
	}

if (lightsensor==2)
	{
	PrescalerGain = ExposurescalepH;
	}

if (lightsensor==3)
	{
	PrescalerGain = ExposurescaleLight;
	}



if (AnalogGain > 3)
	{
	AnalogGain = 3;
	}

// Concatinate the control byte.
controlword = AnalogGain*16 + PrescalerGain;  //This is the offset for gain to placeinto the chip.  Added March 4, 2015

if (lightsensor==2)
	{
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x87);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(PH_LIGHT,controlword);  //Move the address number left on and add a zero.
	i2c_stop(PH_LIGHT);
	}

if (lightsensor==1)
	{
	i2c_start(DO_LIGHT);
	i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(DO_LIGHT,0x87);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(DO_LIGHT,controlword);  //Move the address number left on and add a zero.
	i2c_stop(DO_LIGHT);
	}

if (lightsensor==3)
	{
	i2c_start(ROOM_LIGHT);
	i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(ROOM_LIGHT,0x87);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(ROOM_LIGHT,controlword);  //Move the address number left on and add a zero.
	i2c_stop(ROOM_LIGHT);
	}

// That's it.
	}


//********************************************************************
// Created March 19, 2013
// Get the version of the device.  This  routine is used for testing I2C.
// Command 0x04
// This routine returns the version of the light chip. 
//*********************************************************************
int getTAOSVersion(int lightsensor)
	{
int8 version;
	i2c_start(DO_LIGHT);
	i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(DO_LIGHT,0x84);  //Send the command for reading the version
	i2c_stop(DO_LIGHT);
    i2c_start(DO_LIGHT,0);
	i2c_write(DO_LIGHT,0x73);  //Move the address number left on and add a one to make is a read command.
	version = i2c_read(DO_LIGHT,0);
	i2c_stop(DO_LIGHT);

	return(version);
	}

//**********************************************************************
// Created March 19, 2013
// Power up light chip
// The value for light sensors is as follows:
// 1:PH
// 2:DO
// 3:General Light in the room
//**********************************************************************
void StartUpTAOS(int lightsensor)
	{

if (lightsensor==2)
	{
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x80);  //Send the command for reading the version
	i2c_write(PH_LIGHT,0x03);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);
	}

if (lightsensor==1)
	{
	i2c_start(DO_LIGHT);
	i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(DO_LIGHT,0x80);  //Send the command for reading the version
	i2c_write(DO_LIGHT,0x03);  //Send the command for reading the version
	i2c_stop(DO_LIGHT);
	}

if (lightsensor==3)
	{
	i2c_start(ROOM_LIGHT);
	i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(ROOM_LIGHT,0x80);  //Send the command for reading the version
	i2c_write(ROOM_LIGHT,0x03);  //Send the command for reading the version
	i2c_stop(ROOM_LIGHT);
	}

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


if (lightsensor==1)
	{
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x81);  //Send the command for reading the Timeing Register
	i2c_write(PH_LIGHT,integration);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);
	}

if (lightsensor==2)
	{
	i2c_start(DO_LIGHT);
	i2c_write(DO_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(DO_LIGHT,0x81);  //Send the command for reading the Timeing Register
	i2c_write(DO_LIGHT,integration);  //Send the command for reading the version
	i2c_stop(DO_LIGHT);
	}
if (lightsensor==3)
	{
	i2c_start(ROOM_LIGHT);
	i2c_write(ROOM_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(ROOM_LIGHT,0x81);  //Send the command for reading the Timeing Register
	i2c_write(ROOM_LIGHT,integration);  //Send the command for reading the version
	i2c_stop(ROOM_LIGHT);
	}
	} 

//************************************************************************
// Created March 24, 2013
// Returns the color of all three colors and points to the color on the chart.
//************************************************************************
void calculateCoordinate(void)
{

float redABSfloat,greenABSfloat,blueABSfloat;


redABSfloat = (float) redABS;
greenABSfloat = (float) greenABS;
blueABSfloat = (float) blueABS;

  x=(-0.14282) * redABSfloat + (1.54924) * greenABSfloat + (-0.95641) * blueABSfloat;
  y=(-0.32466) * redABSfloat +(1.57837) * greenABSfloat + (-0.73191) * blueABSfloat;
  z=(-0.68202) * redABSfloat +(0.77073) * greenABSfloat +(0.56332) * blueABSfloat;
  x=x/(x+y+z);   //Calculate the x location
  y=y/(x+y+z);   //Calculate the y location
  if(!((x>0.0)&&(y>0.0)&&(z>0.0)))
  {
   	x=0.0;
	y=0.0;
  }

}



//*******************************************************************************
//Created Febuary 28, 2015
// This routine returns the value of the pH from the WA guys patches
//  The equations takes the x and y values produced from the color.  It then maps it onto the ph.  There three
// sets of values required for calibrations.  There has to be some sort of equation/curve fitting to make the inputs work.
//  The x and y values are global variables.
//  The returned number (float) is the pH calucautaed from the calibration and x and y input.
float ConvertTopH(void)
	{
	float pHHigh, pHMiddle, pHLower;
      float pHHighCalibration,pHMiddleCalibration,pHLowerCalibration;
	float LowerSlope, UpperSlope;
	float pHBLower, pHBUpper;   //This is the calcaulted b for Y = MX + B

	pHHigh = 9.0;
	pHMiddle = 7.5;
	pHLower = 6.5;

	 pHHighCalibration =  0.93;
	pHMiddleCalibration =  0.97;
	pHLowerCalibration = 0.985;

	LowerSlope = (pHMiddle-pHLower)/(pHMiddleCalibration-pHLowerCalibration);
	UpperSlope = (pHHigh - pHMiddle)/(pHHighCalibration - pHMiddleCalibration);

	//This section finds b for the upper and lower pHs.
	pHBLower = -1.0 *LowerSlope * pHMiddleCalibration + pHMiddle;
      pHBUpper = -1.0 * UpperSlope * pHMiddleCalibration + pHMiddle;

	if (y < pHMiddleCalibration)
		{
		return(pHBUpper+UpperSlope*y);  //This the values for the larger values for pH
		}
		else
		{
		return(pHBLower+LowerSlope*y);   //This is for the values of the smaller values of pH
		}
	}




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

	matx[0][0] = 1.0;  //this for testing the deteminte routine.
	matx[1][0] = 0.0;  // remove all of this when completed.
	matx[2][0] = 3.0;
	matx[0][1] = 2.0;
	matx[1][1] = 1.0;
	matx[2][1] = 0.0;
	matx[0][2] = 4.0;
	matx[1][2] = 1.0;
	matx[2][2] = 0.0;

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





//*************************************************************
// Created May 15, 2014
// This routine finds a 4X4 detemint from a given matrix.
// The matrix is passed with a global variable
//*************************************************************
float FindFourbyFour(void)
{


float det;   //This is the result deteminent
float detsub1,detsub2,detsub3,detsub4;


matx[0][0] = fourbyfourmatrix[1][1];
matx[1][0] = fourbyfourmatrix[2][1];
matx[2][0] = fourbyfourmatrix[3][1];

matx[0][1] = fourbyfourmatrix[1][2];
matx[1][1] = fourbyfourmatrix[2][2];
matx[2][1] = fourbyfourmatrix[3][2];

matx[0][2] = fourbyfourmatrix[1][3];
matx[1][2] = fourbyfourmatrix[2][3];
matx[2][2] = fourbyfourmatrix[3][3];

detsub1 = (fourbyfourmatrix[0][0])*FindTheDetermint();



matx[0][0] = fourbyfourmatrix[1][0];
matx[1][0] = fourbyfourmatrix[2][0];
matx[2][0] = fourbyfourmatrix[3][0];

matx[0][1] = fourbyfourmatrix[1][2];
matx[1][1] = fourbyfourmatrix[2][2];
matx[2][1] = fourbyfourmatrix[3][2];

matx[0][2] = fourbyfourmatrix[1][3];
matx[1][2] = fourbyfourmatrix[2][3];
matx[2][2] = fourbyfourmatrix[3][3];

detsub2 = (fourbyfourmatrix[0][1])*FindTheDetermint();



matx[0][0] = fourbyfourmatrix[1][0];
matx[1][0] = fourbyfourmatrix[2][0];
matx[2][0] = fourbyfourmatrix[3][0];

matx[0][1] = fourbyfourmatrix[1][1];
matx[1][1] = fourbyfourmatrix[2][1];
matx[2][1] = fourbyfourmatrix[3][1];

matx[0][2] = fourbyfourmatrix[1][3];
matx[1][2] = fourbyfourmatrix[2][3];
matx[2][2] = fourbyfourmatrix[3][3];

detsub3 = (fourbyfourmatrix[0][2])*FindTheDetermint();


matx[0][0] = fourbyfourmatrix[1][0];
matx[1][0] = fourbyfourmatrix[2][0];
matx[2][0] = fourbyfourmatrix[3][0];

matx[0][1] = fourbyfourmatrix[1][1];
matx[1][1] = fourbyfourmatrix[2][1];
matx[2][1] = fourbyfourmatrix[3][1];

matx[0][2] = fourbyfourmatrix[1][2];
matx[1][2] = fourbyfourmatrix[2][2];
matx[2][2] = fourbyfourmatrix[3][2];

detsub4 = (fourbyfourmatrix[0][3])*FindTheDetermint();


det = detsub1 - detsub2 + detsub3 - detsub4;

return(det);

}



//*****************************************************************************
// Created May 9, 2013
//  This routine finds the constants K1 and K2 for any four given values of O2 concentration and intensity.
//  IntensityHighOxy matches up with LowOxyPercentage
//  IntensityLowOxy matches up with HighOxyPercentage
//  Updated April 29, 2014
//  This routine is completed with formula for K1 and K2.
//  *****************************************************************************
void SolveForK1AndK2(void)
	{

float disolvedOxygen1,disolvedOxygen2,disolvedOxygen3;
float reading1,reading2, reading3;

disolvedOxygen1 = .200;  //Percent
disolvedOxygen2 = .050;  //Percent
disolvedOxygen3 = 0.0;  //Percent



reading3 = 1096.0;    ///This is the reading close to tru O2 20% O2.
reading2 = 14000.0;    //This is for 5% of O2 
reading1 = 57243.0;  //This is for the low O2 reading for close to the axis reading.  This is the hight nummber



//  Find the ratios for all three combinations.
	RatioI=(reading1/reading3)-1.0;  // I0/I1 - 1.0
	RatioII=(reading1/reading2)-1.0;    //  I0/I2 - 1.0


//***************************************************
// Created April 29, 2014
// This sets up the matrix to solve for K1 and K2 using
// two O2 points and percentages.

//matrixSolve[1][0] = LowOxyPercentage;//  This is for RatioII
//matrixSolve[1][1] = LowOxyPercentage*LowOxyPercentage;//  This is for RatioII

//matrixSolve[0][0] = HighOxyPercentage;//  This is for RatioI
//matrixSolve[0][1] = HighOxyPercentage*HighOxyPercentage;//  This is for RatioII

  //  det = matrixSolve[0][0]*matrixSolve[1][1] - matrixSolve[0][1]*matrixSolve[0][1];


// Find K2 
     K2 = ((RatioI/disolvedOxygen1) - (RatioII/disolvedOxygen2))/(disolvedOxygen1 - disolvedOxygen2);

// Find K1

     K1 = (RatioI-(K2*disolvedOxygen1*disolvedOxygen1))/disolvedOxygen1;


// Find Iohhh 

	Iohhh = reading1;
	}

//***************************************************************
// Created April 27, 2014
// This routine finds all of the constants for temperature 
// constants for K2, K1 and Iohhh.
//  The intput is a matrix of inputs (K2, K1 and Iohhh) at three temperatures.
// The outputs are as follows:
// azero, bzero, czero
// aone, bone, cone
// atwo, btwo, ctwo
// TempCalmatrix is as follows:
//  [Temp1] [K1] [K2] [Iohhh]
//  [Temp2] [K1] [K2] [Iohhh]
//  [Temp3] [K1] [K2] [Iohhh]
//***************************************************************

void FindTemperatureCoef(void)
     {
      // Detemine Coefs for K1
      matrixequals[0] = TempCalmatrix[1][0]; 
      matrixequation[0][0] = 1;
      matrixequation[1][0] = TempCalmatrix[0][0]; 
      matrixequation[2][0] = TempCalmatrix[0][0] * TempCalmatrix[0][0]; 
      matrixequals[0] = TempCalmatrix[1][1]; 
      matrixequation[0][1] = 1;
      matrixequation[1][1] = TempCalmatrix[0][1]; 
      matrixequation[2][1] = TempCalmatrix[0][1] * TempCalmatrix[0][1]; 
      matrixequals[0] = TempCalmatrix[1][2]; 
      matrixequation[0][2] = 1;
      matrixequation[1][2] = TempCalmatrix[0][2]; 
      matrixequation[2][2] = TempCalmatrix[0][2] * TempCalmatrix[0][2];      

ThreeByThreeSolution();  // Call to solve for coefs
     


	atwo = MatrixSolution[0];   //Move the solution into the coefs
	btwo = MatrixSolution[1];   //Move the solution into the coefs
	ctwo = MatrixSolution[2];   //Move the solution into the coefs




	}





//****************************************************************************
// Created May 9, 2013
// This rouitne uses the current read Intensity, K1 and K2 to determine the currnet percent of O2
// The calibration calculation routine needs to first be run before this routine works.
// Later on the temperature is also considered for Do compensation.
//****************************************************************************
float CalcaulateDO(unsigned int32 IntensityReading, float temperature)
	{

	float root1,root2,RatioOfIntensity;

//***************************************************************
// Created April 27, 2014
// This routine uses the predetemined values for K1, K2 and Iohhh
// The values for aone, bone and cone are saved in EEPROM when that
// is working.  For now, three numbers will be used just for 
// calculations checking.
//*************************************************************	




//***************
// May 1, 2014 
// This is commented out to first test the K1 and K2 equations.  Temp comp is added later.
//***************

//Iohhh = azero + bzero * temperature + czero * temperature * temperature;

//K1 = aone + bone * temperature + cone * temperature * temperature;
//K2 = atwo + btwo * temperature + ctwo * temperature * temperature;
//SolveForK1AndK2(int16 IntensityLowOxy, int16 IntensityHighOxy, int16 IntensityMiddleOxy, float LowOxyPercentage, float HighOxyPercentage)
SolveForK1AndK2();

//************************************************************** //Added April 27, 2014
// Before the DO can be calculated, it needs to be temperature 
// compensated.  The values of K2, K1 and Iohhh need to be 
// calculated through the three X three matrix temperature shift.
// **************************************************************
//IntensityReading = 200.0;   //this is the test input reading.  This is commeneted out for the real data Nov. 14, 2014

RatioOfIntensity = 1.0 - Iohhh/IntensityReading;
	root1 = sqrt(K1*K1 - 4.0*RatioOfIntensity*K2)- K1;
	
	root1 = (root1)/(2.0*K2);  //This is the plus version of the equation
	root2 = (-1.0 * K1 - (sqrt((K1*K1)-4.0*(RatioOfIntensity)*K2)))/(2.0*K2);  // This is the negative version of the equation.  Most likely not used?

	return(root1);  //If this root is positive, the return it.
	}




//*****************************************************************
// Created May 1, 2014
// Updated June 4, 2014
// Updated the formulas and made the routine work.
// This routine detemines the pK and m for ph calcualations.
// The following inputs need to be present.
// int16 ASample1
// int16 ASample2
// int16 ASampleph11
// int Sample1pH    This needs to be a whole number only.  
// int Sample2pH  This needs to be a whole number only.  
// returns nothing.  pk and slope = m are global variables saved in EEPROM
//*****************************************************************
void FindPkAndSlope(int32 ASample1, int32 ASample2, int32 ASampleph11, int Sample1pH, int Sample2pH)
	{
		float pH1, pH2;
        float  Cal1, Cal2;  // Cal1 and Cal2 are caluculated points using LOG
		float Sampleph1,Sampleph2,Sampleph11;

		Sampleph1 = (float) ASample1;
		Sampleph2 = (float) ASample2;
		Sampleph11 = (float) ASampleph11;

		Cal1 = Sampleph1/(Sampleph11 - Sampleph1);
		Cal1 = log10(Cal1);
		Cal2 = log10(Sampleph2/(Sampleph11 - Sampleph2));

		pH1 = (float) Sample1pH;
        pH2 = (float) Sample2pH;
		slope = (pH1-pH2)/(Cal1 - Cal2); // This finds the slope

    	pk = pH1 - slope*Cal1;   //This solves for b in the equation y = mx + b


	}



//*****************************************************************************************
// Created June 4, 2014
// Find the current pH given the input read data.
// The pH is returned as a float
//*****************************************************************************************
float CalcaulatepH(unsigned int32 ASample)
	{ 

	int32 ASample1, ASample2, ASampleph11;
	int Sample1pH, Sample2pH;
static float LastSamplepH = 0.0;
	float Calm, Cal1, Caln, tempCal;   //This is the measurement 
//  this is the sample working calculations
/*	Sample1pH = 4;
	Sample2pH = 7;
	ASample1 = 100;
	ASample2 = 200;
	ASampleph11 = 1000;
    ASample = 210;

*/

	Sample1pH = 4;
	Sample2pH = 8;
	ASample1 = 15000;   //  33400
	ASample2 = 39900;    //  31200
	ASampleph11 = 85802;   // 
   // ASample = 200;  // This is the sample taken as a reading.  This is provided through the function

	FindPkAndSlope(ASample1, ASample2, ASampleph11, Sample1pH, Sample2pH);

    Calm = (float) ASample;
    Caln = (float) ASampleph11;
	Cal1 = log10(Calm/(Caln - Calm));
	Cal1 = pk + slope*Cal1;   //This finds the curretn pH.  This is also the y = mx + b

	if (Cal1 < 4.0)
		Cal1=4.0;

	if (Cal1 > 10.0)
		Cal1=10.0;	
//***********************************************************************************
// Created Nov 22, 2014
// This section filters off readings where it shows error becauseof bubble or other light readings.
//***********************************************************************************
//  
if (LastSamplepH != 0.0)
	{
	if (abs(Cal1 - LastSamplepH) < 0.75)
		{
		LastSamplepH = Cal1;  //  let it through
		}
		else
		{
		// if the difference is more than 0.9, then split thediffernece and send it out.
		if ((Cal1 - LastSamplepH) > 0.0)
			{  //this means the number is going up.
			tempCal = abs((Cal1 - LastSamplepH)/2.0);
			if (tempCal < 1.0)
				{
				Cal1 = LastSamplepH + (Cal1 - LastSamplepH)/2.0;
				}
				else
				{
				Cal1 = LastSamplepH + 0.75;
				}
			LastSamplepH = Cal1;
			}
			else
			{ //this means the number is going down in value.
			tempCal = abs((Cal1 - LastSamplepH)/2.0);
			if (tempCal < 1.0)
				{
				Cal1 = LastSamplepH - (Cal1 - LastSamplepH)/2.0;
				}
				else
				{
				Cal1 = LastSamplepH - 0.75;
				}
			LastSamplepH = Cal1;
			}
		}
	}
	else
	{
	LastSamplepH = Cal1;  //If this is the first time through, the set whatever number to the last value
	}

	
	return(Cal1);

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
// The colors are retuned in the global variables as follows:
// green, red, blue and clear
//  When a device is not selected correcly, the number 0xFF is returned as an error on the I2C.
//******************************************************************************************

int8 GetCurrentColor(int8 GainIn, int8 DeviceSelect)
	{

//  Set the device to be processed

int exitit = 1;
unsigned int gainMultiplyer;


// This section splits between returning the currecnt color with the specificed gains, or find the auto gan and return the gain and the colors.

	if (GainIn == 4)   //This is the auto gain routine.
		{
		GainIn = 3;  //This is the hightes gain.  It goes down from there.
		setTAOSGain(GainIn,DeviceSelect); //Gain and then scale
		StartUpTAOS(DeviceSelect);
//  The most senstive is when Gain is set to 11b and scaler is set to 000b

		do 
		{

		delay_ms(150);

		ReadColorTAOS(2,DeviceSelect);  //green
		green = colorlow + colorhigh * 256;

		ReadColorTAOS(1,DeviceSelect);  //red
		red = colorlow + colorhigh * 256;

		ReadColorTAOS(4,DeviceSelect);  //blue
		clear = colorlow + colorhigh * 256;

		ReadColorTAOS(3,DeviceSelect);  //blue
		blue = colorlow + colorhigh * 256;

	
		if ((green == 0xFFFF) || (red == 0xFFFF) || (blue == 0xFFFF))
			{
			if (GainIn == 0)
				{
				exitit = 0;  
				}
				else
				{
				GainIn--;
				}

			setTAOSGain(GainIn,DeviceSelect); //Gain and then scale
			}
			else
			{
			exitit = 0;  //Exit and return the gain that is found.
			}

		}

		while (exitit == 1);


//*****************************************************************
// Created December 12, 2014
// This section changes each color to an ABS color using the gainIn scales
//*****************************************************************

		if (GainIn == 3)
			{
			gainMultiplyer =  1;
			}
		if (GainIn == 2)
			{
			gainMultiplyer =  4;
			}
		if (GainIn == 1)
			{
			gainMultiplyer =  16;
			}
		if (GainIn == 0)
			{
			gainMultiplyer =  64;
			}


		redABS = (unsigned int32) red * (unsigned int32) gainMultiplyer;
		greenABS = (unsigned int32) green * (unsigned int32) gainMultiplyer;
		blueABS = (unsigned int32) blue * (unsigned int32) gainMultiplyer;
		clearABS = (unsigned int32) clear * (unsigned int32) gainMultiplyer;

		return(GainIn);


//********************************************************
//Exit the routine but not before giving scaled numbers out.
// Created May 6, 2014
// Scalered, scaleblue and scalegreen are 32 bit intergers
//********************************************************

		}	
		else   // this returns the measurement of the specificed gains.
		{
		setTAOSGain(GainIn,DeviceSelect); //Gain and then scale
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

return(GainIn);
	}



//*******************************************************************************************
// Created Nov 23, 2014
//  This takes severla color readings and then averages them together.  This is a direct drop in
// for the current "int8 GetCurrentColor(int8 GainIn, int8 DeviceSelect)"
// Retuens the gain and the returned value is in the global varaibles called
// red, green , blue and clear.
//*******************************************************************************************
int8 GetCurrentColorAVG(int8 GainIn, int8 DeviceSelect)
	{
float tempred, tempblue, tempgreen, tempclear;   //These are the averaging varaibles used for internal to the averaging calculations
int x,GainOut,averagesamples = 20;
unsigned int gainMultiplyer;

	tempred = 0.0;
	tempblue = 0.0;
	tempgreen = 0.0;
	tempclear = 0.0;
	for (x = 0; x <= averagesamples; x++)
		{
		GainOut = GetCurrentColor(GainIn, DeviceSelect);


//*****************************************************************
// Created December 12, 2014
// This section changes each color to an ABS color using the gainIn scales
//*****************************************************************

		if (GainOut == 3)
			{
			gainMultiplyer =  1;
			}
		if (GainOut == 2)
			{
			gainMultiplyer =  4;
			}
		if (GainOut == 1)
			{
			gainMultiplyer =  16;
			}
		if (GainOut == 0)
			{
			gainMultiplyer =  64;
			}


		redABS = (unsigned int32) red * (unsigned int32) gainMultiplyer;
		greenABS = (unsigned int32) green * (unsigned int32) gainMultiplyer;
		blueABS = (unsigned int32) blue * (unsigned int32) gainMultiplyer;
		clearABS = (unsigned int32) clear * (unsigned int32) gainMultiplyer;


		tempred = tempred + (float) redABS;
		tempblue = tempblue + (float) blueABS;
		tempgreen = tempgreen + (float) greenABS;
		tempclear = tempclear + (float) clearABS;
		}
	tempred = tempred/20.0;
	tempblue = tempblue/20.0;
	tempgreen = tempgreen/20.0;
	tempclear = tempclear/20.0;
	redABS = (unsigned int32) tempred;
	blueABS = (unsigned int32) tempblue;
	greenABS = (unsigned int32) tempgreen;
	clearABS = (unsigned int32) tempclear;


	return(GainOut);
	}



//*****************************************************************************************
// Created April 27, 2014
//This routine inits all of the slave I2C where they have a gain of 1 and start with no ND filteration
//*****************************************************************************************
void InitTAOS(void)
{

int8 gain = 0;



setTAOSGain(gain,1); //Gain and then scale
setTAOSGain(gain,2); //Gain and then scale
setTAOSGain(gain,3); //Gain and then scale
ExposureTimeTAOS(1,1);
ExposureTimeTAOS(1,2);
ExposureTimeTAOS(1,3);
StartUpTAOS(1);
StartUpTAOS(2);
StartUpTAOS(3);



}

//*****************************************************************************************
// Created May 19, 2014
// This rouine takes the inputs of each light sensor and returns the magic number for PWM in the
// center of the light readings.  The gain is assumed for 2 and the light intensity has to be 
//  between 32000 and 40000.
//  The inputs are as follows:
//  int PWM channel
//  int Sensor channel  Number 1 is Do and number 2 is pH
//  The function returns the PWM that works the best.
// This routine is called during calibration when there is no patch in place.  This may be done
//  only the first time the system is put together or may gave to be done all the time.  Don't know.
//****************************************************************************************
int16 FindMiddlePWMSensor(int PWMChannel, int SensorChannel)
{
int16 PWMCommand, CommandInput;   //This is the PWM command under test.  Just return where is finds the requires sensor numbers.
int color;
char uffit[40];
//  Just loop through all of the PWM states and find that ones that meet the light sensitivity.  No PID is required.

	pwm_set_duty(DO_PWM,0x0);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0x0);	//250hz

if (SensorChannel == 1)
	{
	for (PWMCommand=0; PWMCommand <= 0x6638; PWMCommand +=0)
			{
    	CommandInput = 0x6638-PWMCommand;
		pwm_set_duty(DO_PWM,CommandInput);  //Change the PWM to the last set reading for the PWM.  This prevent the LED from flashing brightly before stablizing
    	delay_us(100);
			sprintf(uffit,"blue PWM %Lu ",CommandInput);
			Display_XYString(1, 4, &uffit);
   			color = GetCurrentColor(4, 1);   // //Device 1 is the 
			sprintf(uffit,"color %Lu %Lu",blueABS,color);
			Display_XYString(1, 3, &uffit);
			sprintf(uffit,"red color %Lu ",redABS);
			Display_XYString(1, 2, &uffit);

 			if (color == 3 && blue > 27000 && blue < 33000)
				{
				sprintf(uffit,"blue  %Lu  %Lu",blueABS,CommandInput);
				Display_XYString(0, 1, &uffit);
				pwm_set_duty(DO_PWM,0x0);   //this shuts off the light.
				return(PWMCommand);
				}  
			}
	}

if (SensorChannel == 2)
	{
	for (PWMCommand=0; PWMCommand <= 0xFF00; PWMCommand +=0)
		{
    	CommandInput = 0x5F00-PWMCommand;
		pwm_set_duty(PH_PWM,CommandInput);  //Change the PWM to the last set reading for the PWM.  This prevent the LED from flashing brightly before stablizing
    	delay_us(100);
			sprintf(uffit,"white PWM %Lu ",CommandInput);
			Display_XYString(1, 4, &uffit);
   			color = GetCurrentColor(4, 2);   // //Device 2 is the pH
//			sprintf(uffit,"color %Lu",blueABS);
			calculateCoordinate();
			sprintf(uffit,"y %e",y);
			Display_XYString(1, 3, &uffit);
			sprintf(uffit,"x %e",x);
			Display_XYString(1, 2, &uffit);

			
   			color = GetCurrentColor(4, 2);   // Number 2 is the blue PWM LED
 			if (clearABS > 700000 && clearABS < 900000)
				{
				sprintf(uffit,"clear  %Lu  %Lu",clearABS,CommandInput);
				Display_XYString(0, 1, &uffit);
				pwm_set_duty(PH_PWM,0x0);   //this shuts off the light.
				return(PWMCommand);
				}  
			}
	}



return(PWMCommand);
}



//*****************************************************************************************************
// Created May 19, 2014
// Completed May 23, 2014
// This routine reads the data from the DO or pH.  This is includeing the pre-deteremined gains
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
float TakeLightReading(int SensorChannel, unsigned int16 PWMIntensity, unsigned int16 RequiredReading)
{

int color,attemptcounter, attempts;
int32 result;  //This is the result of the calculation.  This is returned to the calling function.

float DOReading,pgain,tempoffset,PHReading;
char uffit[60];
int32 readingrange = 100;
unsigned int32 difference;

unsigned int32 upperlimit = RequiredReading + readingrange;
unsigned int32 lowerlimit = RequiredReading - readingrange;
//*****************************************************************************
//Created Nov 15, 2014
//This section sets the PWM for the requied feedback for light driver and sensor dirt measurement drift.
//*****************************************************************************
// Set the light with in a specification range

attempts =  200;  //This is the number of attemps to get the color correct.

if (SensorChannel == 1)
	{
	pwm_set_duty(DO_PWM,PWMIntensity); 
	delay_ms(25);
	attemptcounter = 0;
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pgain = 0.0125;   //This the propotional gain for the PID loop.
	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

while (((blueABS < lowerlimit) || (blueABS > upperlimit)) && (attemptcounter < attempts))   // If it is in range, then exit.  If not in range, adjest and try again.
	{

	if (RequiredReading < blueABS)
		{
		difference = blueABS - (unsigned int32) RequiredReading;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity + (int16) difference;   //This inverted.  As the PWM number goes down, the light goes up.
		}
		else
		{
		difference = (unsigned int32) RequiredReading - blueABS;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity - (int16) difference;   //This inverted.  As the PWM number goes down, the light goes up.
		}
	pwm_set_duty(DO_PWM,PWMIntensity); 
	attemptcounter++;
	delay_ms(25);
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;
				sprintf(uffit,"B %Lu Red %Lu PW %Lu  ", blueABS, redABS,PWMIntensity);
				Display_XYString(0, 1, &uffit);
	}
PWMDOIntensity = PWMIntensity;  //Save the last PWM intensirty for the next go a round.
	}


//*****************************************************************************
//Created Nov 17, 2014
//This section sets the PWM for the requied feedback for light driver and sensor dirt measurement drift for the pH.
//*****************************************************************************
// Set the light with in a specification range
if (SensorChannel == 2)
	{
	pwm_set_duty(PH_PWM,PWMIntensity); 
	delay_ms(25);
	attemptcounter = 0;
	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pgain = 0.125;   //This the propotional gain for the PID loop.
	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;

while (((greenABS < lowerlimit) || (greenABS > upperlimit)) && (attemptcounter < attempts))   // If it is in range, then exit.  If not in range, adjest and try again.
	{

	if (RequiredReading < blueABS)
		{
		difference = greenABS - RequiredReading;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity + (int16) difference;   //This inverted.  As the PWM number goes down, the light goes up.
		}
		else
		{
		difference = RequiredReading - greenABS;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity - (int16) difference;   //This inverted.  As the PWM number goes down, the light goes up.
		}
	pwm_set_duty(PH_PWM,PWMIntensity); 
	attemptcounter++;
	delay_ms(25);
	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;

				sprintf(uffit,"B %Lu G %Lu Red %Lu PW %Lu  ", blueABS, greenABS, redABS, PWMIntensity );
				Display_XYString(0, 3, &uffit);
	}
PWMPHIntensity = PWMIntensity;
 }   


//Take the reading for real

switch (SensorChannel)
	{
	case 1:  //This is the DO Sensor
     //   delay_ms(25);  //Delay to stablize PWM
		color = GetCurrentColorAVG(4, 1);   // Number 0 is the red PWM LED
	    pwm_set_duty(DO_PWM,0x0);	//250hz  Turn off light for DO
 
 
	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

		DOReading =  CalcaulateDO(redABS,21.0);  //This holds the color intensity variable and the temperature in degrees C.

		delay_ms(1000);

		//		sprintf(uffit,"RED %Lu DO %f  ", red,DOReading);
	//			Display_XYString(0, 2, &uffit);

		return(DOReading);  //Return result.
		break;
	case 2:  //This is the pH Sensor
    //    delay_ms(1000);  //Delay to stablize PWM
		color = GetCurrentColorAVG(4, 2);   // Number 0 is the red PWM LED
		pwm_set_duty(PH_PWM,0xFFFF); 

	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;

		PHReading = CalcaulatepH(redABS);  // Take the red reading and calcualte the pH


        delay_ms(1000);

		//		sprintf(uffit,"RED  %Lu pH %f  ", red,PHReading);
		//		Display_XYString(0, 4, &uffit);

		return(PHReading);  //Return result.
		break;

	default:
		break;
	}
//result = (int) color * red;   //This is the result in 32 bit form for absolute intensity.
//result = 200;   // Added June 3, 2014 for temp value before doing a real calibration.
return(result);  //Return result.
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



		GetCurrentColorAVG(4,DeviceSelect);

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

	}


//*****************************************************************************************
// Created Febuary 11, 2015
// This routine calculates the pH from the guys in WA.  It takes finds the x and y for the
// given light reading and returns the pH as a float.
// A good measurement needs to be taken befor ethis routine is run.
//  Make sure to kick out all ambient light
//  Make sure all readings are in ABS. 
//*****************************************************************************************
float FindWAGuysPH(void)
	{
		char uffit[80];
			calculateCoordinate();
			sprintf(uffit,"y %e",y);
			Display_XYString(0, 4, &uffit);
			sprintf(uffit,"x %e",x);
			Display_XYString(0, 3, &uffit);	
	return(0.0);
	}



//*************************************************************
// Created Nov. 6, 2012
//  This routine reads an ADC and averages 16 samples into one and returns the number.
// There is no scaling or any signal condition excepct for a low pass averaging filter.
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



//*****************************************************************************************
// Created Febuary 11, 2015
// This routine does the measurement of the WA guys pH patch
// This routine returns nothing.  It's supposed to get an average, remove ambient light and leave
// a global colors in ABS.
// The input to the routine is the white light intensity
//*****************************************************************************************
void MeasureWAGuyspH(unsigned int16 PWMIntensity)
	{

		pwm_set_duty(PH_PWM,0x0000);  // Turn off light to get ambient light mearuement
		delay_ms(100);
		FindAmbientLight(2);    //Get the ambient light
		pwm_set_duty(PH_PWM,PWMIntensity);  // Turn off light to get ambient light mearuement

//  Remove the ambent light.
	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;
		delay_ms(100);
		GetCurrentColorAVG(4, 2);    //Find the current measurement averaged.
		FindWAGuysPH();

	}


//*****************************************************************************************
//Created Feb 24, 2015
//This routine balances the light for the pH and sets the PWM for the same brightness each time
// The entered number is the wanted feedback number for the pH.  The function returns that lastest PWM setting.
//*****************************************************************************************

int16 SetPWMWithPhotoTransistor(int16 StartingPWM, int16 DesiredIntensity)
	{

//Got through the routine only 50 times to get to the desired number.  This uses a PID loop to holm into the wanted number.
	signed int16 CurrentADCReading,CurrentAmbientLight, PIDReading, PIDDifference;
	int16 x,slop;
	float gain,tempreading;
	char uffit[80];

//First find the ambent light and subtract it out of the calculated value.
	pwm_set_duty(PH_PWM,0x0000);	//250hz
	delay_ms(100);  //Wait for it to settle down
	CurrentAmbientLight = GetADCValue(2);   //This finds the ADC value
	gain = .1;
	slop =  4;  //this is the tolerance for the phototransistor

	for (x=0; x < 50; x++)
		{
		pwm_set_duty(PH_PWM,StartingPWM);
		delay_ms(50);  //Wait for it to settle down
		CurrentADCReading = GetADCValue(2) - CurrentAmbientLight;   //This finds the ADC value
		if (CurrentADCReading < 0) 
			{
			CurrentADCReading = 0;
			}
		if ((CurrentADCReading < (DesiredIntensity + slop)) && (CurrentADCReading > (DesiredIntensity - slop)))
				{
                        MeasureWAGuyspH(StartingPWM);
				return(StartingPWM);
				}
				else
				{
				PIDDifference = CurrentADCReading - DesiredIntensity;
				if (PIDDifference < 0)
					{
					PIDDifference = -PIDDifference;
					}
				tempreading =  (float) PIDDifference;
				tempreading = tempreading *gain;
				PIDReading = (int16) tempreading;


				if (CurrentADCReading < (DesiredIntensity + slop))
					{
					StartingPWM = StartingPWM  + PIDReading;
					//break;
					}
				if (CurrentADCReading > (DesiredIntensity - slop))
					{
					StartingPWM = StartingPWM  - PIDReading;
					//break;
					}
		sprintf(uffit," %Lu  PWM %Lu  %Lu ", CurrentADCReading, StartingPWM, x);
		Display_XYString(0, 1, &uffit);
		pwm_set_duty(PH_PWM,StartingPWM);
		delay_ms(50);  //Wait for it to settle down
				}
			}
	MeasureWAGuyspH(StartingPWM);
	return(StartingPWM);  //Retuen the current PWM for the next go around
	}


