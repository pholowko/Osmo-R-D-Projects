
#define byte int8
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

int colorlow, colorhigh, gain, scale, exposure;  //This is the pair of bytes used to return the current selected color.
int16 red,green,blue,bluelight,redlight, color,colorred,clear;
float x,y,z;  //Color chart positions,coored.

//*******
//Define the 3X4 matrix for solving three unknown equations.
float matx[3][3];  //This is the global diffinition of solving a 3X3 matrix equation. This is a scrach pad matrix used to pass arrays between functions. Added May 13, 2013
float matrixequation[3][3]; //  Added May 13, 2013  This is the array used for setting up the eqaution for solving a 3X3 equation.
//*******


//******************************************************************
// K1 and K2 are two constans caluclated from calibration constants saved in EEPROM.
//******************************************************************
float K1, K2;
float RatioI, RatioII, RatioIII, Iohhh;
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
//******************************************************************
void ReadColorTAOS(int selectedcolor)
	{

	switch(selectedcolor)
		{
		case 2:   //green
			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x90);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(0);
			i2c_stop();

			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x91);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(0);
			i2c_stop();
			break;


		case 1:   //red
			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x92);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(0);
			i2c_stop();

			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x93);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(0);
			i2c_stop();
			break;

		case 3:   //blue
			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x94);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(0);
			i2c_stop();

			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x95);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(0);
			i2c_stop();
			break;

		case 4:   //clear
			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x96);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorlow = i2c_read(0);
			i2c_stop();

			i2c_start();
			i2c_write(0x72);  //Move the address number left on and add a zero.
			i2c_write(0x97);  //Send the command for reading the version
			i2c_stop();

    		i2c_start();
			i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
			colorhigh = i2c_read(0);
			i2c_stop();
			break;

		default:	
			break;
		}	

	}


//********************************************************************
// Created March 17, 2013
// This routine changes the gain/scaling routine for each color/ADC.
// The passed varaible is the gain for the ADC.  All colors get the same gain.
//  AnalogGain is a value between 0 to 4.  
//  0 is 1X
//  1 is 4X
//  2 is 16X
//  3 is 64X
//Prescaler are values btween 0 and 6.  0 is div by 1; 6 is divide by 64.
//********************************************************************
void setTAOSGain(byte AnalogGain, byte PrescalerGain)
	{
byte controlword;

controlword = 0;
if (PrescalerGain > 6)
	{
	PrescalerGain = 6;
	}
if (PrescalerGain < 0)
	{
	PrescalerGain = 0;
	}

if (AnalogGain > 3)
	{
	AnalogGain = 3;
	}
if (AnalogGain < 0)
	{
	AnalogGain = 0;
	}
// Concatinate the control byte.
controlword = AnalogGain*16 + PrescalerGain;

	i2c_start();
	i2c_write(0x72);  //Move the address number left on and add a zero.
	i2c_write(0x87);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(controlword);  //Move the address number left on and add a zero.
	i2c_stop();
// That's it.
	}


//********************************************************************
// Created March 19, 2013
// Get the version of the device.  This  routine is used for testing I2C.
// Command 0x04
// This routine returns the version of the light chip. 
//*********************************************************************
int getTAOSVersion(void)
	{
int8 version;
	i2c_start();
	i2c_write(0x72);  //Move the address number left on and add a zero.
	i2c_write(0x84);  //Send the command for reading the version
	i2c_stop();
    i2c_start();
	i2c_write(0x73);  //Move the address number left on and add a one to make is a read command.
	version = i2c_read(0);
	i2c_stop();

	return(version);
	}

//**********************************************************************
// Created March 19, 2013
// Power up light chip
//**********************************************************************
void StartUpTAOS(void)
	{
	i2c_start();
	i2c_write(0x72);  //Move the address number left on and add a zero.
	i2c_write(0x80);  //Send the command for reading the version
	i2c_write(0x03);  //Send the command for reading the version
	i2c_stop();
	}


//***********************************************************************
// Created March 20, 2013
// This routine changes the exposure time for each sample.
//  There are three modes of intigration or exposure time per sample.
// 0 for 12ms
// 1 for 100 ms
// 2 for 400 ms
//***********************************************************************
void ExposureTimeTAOS(byte integration)
	{
	if (integration > 2)
		{
		integration = 2;
		}
	if (integration < 0)
 		{
		integration = 0;
		}
	i2c_start();
	i2c_write(0x72);  //Move the address number left on and add a zero.
	i2c_write(0x81);  //Send the command for reading the Timeing Register
	i2c_write(integration);  //Send the command for reading the version
	i2c_stop();

	} 

//************************************************************************
// Created March 24, 2013
// Returns the color of all three colors and points to the color on the chart.
//************************************************************************
void calculateCoordinate(void)
{
float X,Y,Z;
  X=(-0.14282)*red+(1.54924)*green+(-0.95641)*blue;
  Y=(-0.32466)*red+(1.57837)*green+(-0.73191)*blue;
  Z=(-0.68202)*red+(0.77073)*green+(0.56332)*blue;
  x=X/(X+Y+Z);
  y=Y/(X+Y+Z);
  if(!((X>0)&&(Y>0)&&(Z>0)))
  {
   	x=0.0;
	y=0.0;
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
	float det;  //Define the determint as float.

	// Below is the equation that finds the determine mechanilly.


	det = (matx[0][0]*matx[1][1]*matx[2][2] + matx[1][0]*matx[2][1]*matx[0][2] + matx[2][0]*matx[0][1]*matx[1][2]); 
	det = det - (matx[0][2]*matx[1][1]*matx[2][0] + matx[1][2]*matx[2][1]*matx[0][0] + matx[2][2]*matx[0][1]*matx[1][0]);

	return(det);
	}

//******************************************************************************
// Created May 13, 2013
// This routine is a general purpose solution for three unknowns given the coefficents of all three equations and what they eqaul.
// The coefficents are given as a matrix of 3X3 in an 3X3 array of floats starting with 0 to 2.  The results are placed in the last colomum of of the 3X3 matrix.
// The routines uses a series of deteminets to solve the problems.
//******************************************************************************
void ThreeByThreeSolution(float firstequationResult, float secondequationResult, float thirdequationResult)
	{

	float det, detx, dety, detz;
	int x, y, z;



	for (z=0; z < 4; z++)  //This routine finds all of the determines and solves all for all of the variables.  It produces x,y and z.

//  Move the exisitng array into the scratch pad marix  matx
	for (x=0; x < 3; x++)
		{
		for (y=0; y < 3; y++)
			{
			matx[x][y] = matrixequation[x][y];   //Move this element into the scrach matrix.
			}
		}

	matx[0][0] = 1.0;
	matx[1][0] = 0.0;
	matx[2][0] = 3.0;
	matx[0][1] = 2.0;
	matx[1][1] = 1.0;
	matx[2][1] = 0.0;
	matx[0][2] = 4.0;
	matx[1][2] = 1.0;
	matx[2][2] = 0.0;


	det = FindTheDetermint();

	}



//*****************************************************************************
// Created May 9, 2013
//  This routine finds the constants K1 and K2 for any four given values of O2 concentration and intensity.
//  IntensityHighOxy matches up with HighOxyPercentage
//  IntensityLowOxy matches up with LowOxyPercentage
//*****************************************************************************
void SolveForK1AndK2(int16 IntensityLowOxy, int16 IntensityHighOxy, int16 IntensityMiddleOxy, float LowOxyPercentage, float HighOxyPercentage, float MiddleOxyPercentage)
	{

	

	RatioI=IntensityLowOxy/IntensityHighOxy-1.0;
	RatioII=IntensityMiddleOxy/IntensityHighOxy-1.0;
	RatioIII=IntensityHighOxy/IntensityHighOxy-1.0;




	}


//****************************************************************************
// Created May 9, 2013
// This rouinte saves all of the raw data for DO into EEPROM.
//****************************************************************************
void SaveConstantsIntoEEPROM(int16 IntensityLowOxy, int16 IntensityHighOxy, int16 IntensityMiddleOxy, float LowOxyPercentage, float HighOxyPercentage, float MiddleOxyPercentage)
	{


	}

//***********************************************************************************
// Created May 9, 2013
// This routine reads all of the saves raw calibration varables for DO out of  EEPROM
//***********************************************************************************
void ReadRawCalibrationVariables(void)
	{




	}

//****************************************************************************
// Created May 9, 2013
// This rouitne uses the current read Intensity, K1 and K2 to determine the currnet percent of O2
// The calibration calculation routine needs to first be run before this routine works.
// Later on the temperature is also considered for Do compensation.
//****************************************************************************
float CalcaulateDO(int16 IntensityReading, float temperature)
	{

	float root1,root2,RatioOfIntensity;

	RatioOfIntensity = (float) Iohhh/IntensityReading;
	
	root1 = -K2 + ((K1*K1)-sqrt(4*(1-RatioOfIntensity)*K2))/(2*K2);  //This is the plus version of the equation
	root2 = -K2 - ((K1*K1)-sqrt(4*(1-RatioOfIntensity)*K2))/(2*K2);  // This is the negative version of the equation.  Most likely not used?


	if (root1 > 0)
		{
		return(root1);  //If this root is positive, the return it.
		}
	if (root2 > 0)
		{
		return(root2);   // If this is postive, then return it.
		}
	return(-1.0);
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
int scale = 0;
int exitit = 1;
float greentwo;
switch (DeviceSelect)   // This sets the mut to point to the currect spectrume device.
	{
	case 0:
		output_bit(PIN_C5,0);
		output_bit(PIN_C0,0);
		break;
	case 1:
		output_bit(PIN_C5,1);
		output_bit(PIN_C0,0);
		break;
	case 2:
		output_bit(PIN_C5,0);
		output_bit(PIN_C0,1);
		break;
	case 3:
		output_bit(PIN_C5,1);
		output_bit(PIN_C0,1);
		break;
	}
// This section splits between returning the currecnt color with the specificed gains, or find the auto gan and return the gain and the colors.

	if (GainIn == 4)   //This is the auto gain routine.
		{
		GainIn = 3;  //This is the hightes gain.  It goes down from there.
		setTAOSGain(GainIn,scale); //Gain and then scale
		//StartUpTAOS();
//  The most senstive is when Gain is set to 11b and scaler is set to 000b

		do 
		{

		delay_ms(400);

		ReadColorTAOS(2);  //green
		green = colorlow + colorhigh * 256;

		ReadColorTAOS(1);  //red
		red = colorlow + colorhigh * 256;

		ReadColorTAOS(4);  //blue
		clear = colorlow + colorhigh * 256;

		ReadColorTAOS(3);  //blue
		blue = colorlow + colorhigh * 256;




	
		if ((green == 0xFFFF) || (red == 0xffff) || (blue == 0xffff))
			{
			if (GainIn == 0)
				{
				exitit = 0;
				}
				else
				{
				GainIn--;
				}
			setTAOSGain(GainIn,scale); //Gain and then scale
			}
			else
			{
			exitit = 0;  //Exit and return the gain that is found.
			}
		}
		while (exitit == 1);
		}	
		else   // this returns the measurement of the specificed gains.
		{
		setTAOSGain(GainIn,scale); //Gain and then scale
		ReadColorTAOS(2);  //green
		green = colorlow + colorhigh * 256;

		ReadColorTAOS(1);  //red
		red = colorlow + colorhigh * 256;

		ReadColorTAOS(4);  //blue
		clear = colorlow + colorhigh * 256;

		ReadColorTAOS(3);  //blue
		blue = colorlow + colorhigh * 256;
		}
return(GainIn);
	}

//*****************************************************************************************
// Created April 27, 2014
//This routine inits all of the slave I2C where they have a gain of 1 and start with no ND filteration
//*****************************************************************************************
void InitTAOS(void)
{

int8 gain = 0;
int8 scale = 0;

output_bit(PIN_C5,0);
output_bit(PIN_C0,0);

setTAOSGain(gain,scale); //Gain and then scale
StartUpTAOS();
ExposureTimeTAOS(1);

output_bit(PIN_C5,0);
output_bit(PIN_C0,1);

setTAOSGain(gain,scale); //Gain and then scale
StartUpTAOS();
ExposureTimeTAOS(1);

output_bit(PIN_C5,1);
output_bit(PIN_C0,0);

setTAOSGain(gain,scale); //Gain and then scale
StartUpTAOS();
ExposureTimeTAOS(1);

output_bit(PIN_C5,1);
output_bit(PIN_C0,1);

setTAOSGain(gain,scale); //Gain and then scale
StartUpTAOS();
ExposureTimeTAOS(1);

output_bit(PIN_C5,0);
output_bit(PIN_C0,0);

}