


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

byte ExposurescaleDO = 1;   //This is the global variable used for prescaler for the ADC
byte ExposurescalepH = 0;   //This is the global variable used for prescaler for the ADC 
byte ExposurescaleLight = 4;   //  This used to be 2.  This is the global variable used for prescaler for the ADC   Three is used to divide by 4
float x,y,z;  //Color chart positions,coored.

void selectsensor(int sensornumber);
//************************************************************
//Define the 3X4 matrix for solving three unknown equations.
float matx[3][3];  //This is the global diffinition of solving a 3X3 matrix equation. This is a scrach pad matrix used to pass arrays between functions. Added May 13, 2013
//float matrixequation[3][3]; //  Added May 13, 2013  This is the array used for setting up the eqaution for solving a 3X3 equation.
//float fourbyfourmatrix[4][4];
//float matrixequals[3]; 
// Added April 27, 2014  
// Matrixequals is used for place the results of all three equations.
// This is used to subsitue into the 3X3 matrix for finding the DET.
//float MatrixSolution[3]; 
// Added April 27, 2014  This matrix saves the
// result for the 3X3 unknown solution.
//float TempCalmatrix[4][3];  //This matrix holds the temperatures and K1, K2 and Iohhh values.
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
//float K1, K2, K1Temp,K2Temp;   // Added April 6, 2015  These are all of the K values for DO temperature and non temperature compensation.
//float RatioI, RatioII, Iohhh;
//float atwo, btwo, ctwo;   //no Temp compensated DO



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
void setTAOSGain(byte AnalogGain, int lightsensor)
	{
byte controlword,PrescalerGain;

controlword = 0;
PrescalerGain = 0;   // set it to this value if nothing else takes it.

if (lightsensor==0)   // changed March 23, 2016.  The passing number is the true sensor number, not the index   Used to be 1
	{
	PrescalerGain = ExposurescaleDO;
	}

if (lightsensor==4)  // changed March 23, 2016.  The passing number is the true sensor number, not the index   Used to be 2
	{
	PrescalerGain = ExposurescalepH;
	}

if (lightsensor==5)   // Used to be 3
	{
	PrescalerGain = ExposurescaleLight;   // set to 2 for now.  this means divide by 4
	}



if (AnalogGain > 3)
	{
	AnalogGain = 3;
	}

// Concatinate the control byte.
controlword = AnalogGain*16 + PrescalerGain;  //This is the offset for gain to place into the chip.  Added March 4, 2015



	selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.



	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x87);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(PH_LIGHT,controlword);  //Move the address number left on and add a zero.
	i2c_stop(PH_LIGHT);
	
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
//	float pHHigh, pHMiddle, pHLower;
	float calc;
  //  float pHHighCalibration,pHMiddleCalibration,pHLowerCalibration;
	float LowerSlope, UpperSlope;
	float pHBLower, pHBUpper;   //This is the calcaulted b for Y = MX + B

//	pHHigh = 9.0;
//	pHMiddle = 7.5;
//	pHLower = 6.5;

//	pHHighCalibration =  0.72;    //Used to be  0.93
//	pHMiddleCalibration =  0.705;   //Used to be   0.97
//	pHLowerCalibration = 0.69;    //Used to be  0.985

	LowerSlope = (pHMiddle-pHLower)/(pHMiddleCalibration-pHLowerCalibration);
	UpperSlope = (pHHigh - pHMiddle)/(pHHighCalibration - pHMiddleCalibration);

	//This section finds b for the upper and lower pHs.
	pHBLower = -1.0 *LowerSlope * pHMiddleCalibration + pHMiddle;
      pHBUpper = -1.0 * UpperSlope * pHMiddleCalibration + pHMiddle;

// May 29th, 2015 ZS - adjusted pH upper and lower bounds for testing pH accuracy with "light tubes"

	if (y < pHMiddleCalibration) 
		{
		calc = pHBUpper+UpperSlope*y;
		if (calc > 99.0)
			{
			return(9.0);
			}
		if (calc < -96.5)
			{
			return(6.5);
			}
			return(pHBUpper+UpperSlope*y);   //This is for the values of the smaller values of pH
		}	
		else
		{
		calc = pHBLower+LowerSlope*y;
		if (calc > 99.0)
			{
			return(9.0);
			}	
 			if (calc < -96.5)
			{
			return(6.5);
			}
			return(pHBLower+LowerSlope*y);   //This is for the values of the smaller values of pH
		}
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

int exitit = 1;
unsigned int gainMultiplyer;


// This section splits between returning the current color with the specificed gains, or find the auto gan and return the gain and the colors.

	if (GainIn == 4)   //This is the auto gain routine.
		{
		GainIn = 3;  //This is the highest gain.  It goes down from there.
		setTAOSGain(GainIn,DeviceSelect); //Gain and then scale
		StartUpTAOS(DeviceSelect);
//  The most senstive is when Gain is set to 11b and scaler is set to 000b
		delay_ms(500);
		do 
		{

		ReadColorTAOS(2,DeviceSelect);  //green
		green = colorlow + colorhigh * 256;

		ReadColorTAOS(1,DeviceSelect);  //red
		red = colorlow + colorhigh * 256;

		ReadColorTAOS(4,DeviceSelect);  //clear
		clear = colorlow + colorhigh * 256;

		ReadColorTAOS(3,DeviceSelect);  //blue
		blue = colorlow + colorhigh * 256;

	//fprintf(BT,"Raw  Red,%Lu,Green,%Lu,Blue,%Lu,Clear,%Lu\n\r",red,green,blue,clear);
		if ((green == 0xFFFF) || (red == 0xFFFF) || (blue == 0xFFFF) || (clear == 0xFFFF))
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
        StartUpTAOS(DeviceSelect);
        delay_ms(500);
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
//  This takes several color readings and then averages them together.  This is a direct drop in
// for the current "int8 GetCurrentColor(int8 GainIn, int8 DeviceSelect)"
// Returns the gain and the returned value is in the global varaibles called
// red, green , blue and clear.
//  Changed May 18, 2015  
// The below routine is changed from 20 samples to 200 to get the stability down
//*******************************************************************************************
int8 GetCurrentColorAVG(int8 GainIn, int8 DeviceSelect)
	{
float tempred, tempblue, tempgreen, tempclear, ageraging;   //These are the averaging varaibles used for internal to the averaging calculations
int x,GainOut,DeviceSel,averagesamples = 10;
unsigned int gainMultiplyer;

if (DeviceSelect == 2)   //If this is for pH then sample the crap out of it.
	{
	averagesamples = 1;
	ageraging = 1.0;
	DeviceSel = 4;//  this changes to zero because of the change in selection.  Added Dec 9, 2015
	}

if (DeviceSelect == 4)   //If this is for nh3 then sample the crap out of it.  Added Jan 20, 2016
	{
	averagesamples = 1;
	ageraging = 1.0;
	DeviceSel = 2;//  This changes to the selected PWM for nh3.  Added Jan 20, 2016
	}

if ((DeviceSelect == 1) || (DeviceSelect == 3))   //If this is for DO and the light sensor
	{
	averagesamples = 10;
	ageraging = 10.0;
    selectsensor(0);
	DeviceSel = 0;
	}

	tempred = 0.0;
	tempblue = 0.0;
	tempgreen = 0.0;
	tempclear = 0.0;
	for (x = 0; x < averagesamples; x++)
		{
		GainOut = GetCurrentColor(GainIn, DeviceSel);

//fprintf(BT,"Raw Unaveraged 1 Red,%Lu,Green,%Lu,Blue,%Lu,Clear,%Lu\n\r",redABS,greenABS,blueABS,clearABS);
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

//fprintf(BT,"Raw Unaveraged 2 Red,%Lu,Green,%Lu,Blue,%Lu,Clear,%Lu\n\r",redABS,greenABS,blueABS,clearABS);

//	BTBasicTest();    //Check BT 

		tempred = tempred + (float) redABS;
		tempblue = tempblue + (float) blueABS;
		tempgreen = tempgreen + (float) greenABS;
		tempclear = tempclear + (float) clearABS;
		}
	tempred = tempred/ageraging;
	tempblue = tempblue/ageraging;
	tempgreen = tempgreen/ageraging;
	tempclear = tempclear/ageraging;
	redABS = (unsigned int32) tempred;
	blueABS = (unsigned int32) tempblue;
	greenABS = (unsigned int32) tempgreen;
	clearABS = (unsigned int32) tempclear;
//fprintf(BT,"Raw Unaveraged 3 Red,%Lu,Green,%Lu,Blue,%Lu,Clear,%Lu\n\r",redABS,greenABS,blueABS,clearABS);
//fprintf(BT,"Blue %Lu  Gain %i ",blueABS, GainOut);

	return(GainOut);
	}



//*****************************************************************************************
// Created April 27, 2014
//This routine inits all of the slave I2C where they have a gain of 1 and start with no ND filteration
//*****************************************************************************************
void InitTAOS(void)
{

int8 gain = 3;
int8 x;



//setTAOSGain(1,0); //Gain and then scale
setTAOSGain(gain,1); //Gain and then scale
//setTAOSGain(1,2); //Gain and then scale
setTAOSGain(gain,3); //Gain and then scale
//setTAOSGain(1,4); //Gain and then scale
setTAOSGain(gain,5); //Gain and then scale

ExposureTimeTAOS(1,0);     // this is for DO
ExposureTimeTAOS(0,1);   //This is for the pH  // Changed to 12ms exposure and then more light.  Changed to 100ms exposure for pH.  July 23, 2015
ExposureTimeTAOS(1,2);   //Set the exposure time for NH3  Changed Jan 20, 2016
ExposureTimeTAOS(0,3);     // this is for DO
ExposureTimeTAOS(1,4);   //This is for the pH  // Changed to 12ms exposure and then more light.  Changed to 100ms exposure for pH.  July 23, 2015
//ExposureTimeTAOS(0,5);   //Set this exposure time to 12ms to help with max out gains.  Changed April 7, 2014
ExposureTimeTAOS(2,5);   //Set this exposure time to 100ms to help with max out gains.  Changed November 4, 2016


for (x=0; x < 6; x++)	    // This runs through all of the sensors and starts them up.  Updated December 8, 2015
	{
	StartUpTAOS(x);
	}


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
float TakeLightReading(int SensorChannel, unsigned int16 PWMIntensity, unsigned long RequiredReading)
{

int color,attemptcounter, attempts,ttt;
int32 result,stepdifference;  //This is the result of the calculation.  This is returned to the calling function.

float DOReading,pgain,tempoffset;
char uffit[60];

unsigned int32 difference;

unsigned int32 upperlimit = RequiredReading + DOreadingrange;
unsigned int32 lowerlimit = RequiredReading - DOreadingrange;
//*****************************************************************************
//Created Nov 15, 2014
//This section sets the PWM for the requied feedback for light driver and sensor dirt measurement drift.
//*****************************************************************************
// Set the light with in a specification range

attempts =  50;  //This is the number of attemps to get the color correct.
/*
if (SensorChannel == 1)
	{
//	pwm_set_duty(DO_PWM,PWMIntensity); 
//	delay_ms(25);
	attemptcounter = 0;
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pgain = 0.00125;   //This the propotional gain for the PID loop.  old one
//	pgain = 0.0003125;   //This the propotional gain for the PID loop.  Added May 23, 2015

	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.

if (redABS < 0)
	{
	redABS = 0;
	}
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


while (((blueABS < lowerlimit) || (blueABS > upperlimit)) && (attemptcounter < attempts))   // If it is in range, then exit.  If not in range, adjest and try again.
	{

	if (RequiredReading < blueABS)
		{
		difference = blueABS - (unsigned int32) RequiredReading;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity - (int16) difference;   //  As the PWM number goes up, the light goes up.
		}
		else
		{
		difference = (unsigned int32) RequiredReading - blueABS;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity + (int16) difference;   // As the PWM number goes down, the light goes down.
		}
//	BTBasicTest();    //Check BT 
//	pwm_set_duty(DO_PWM,PWMIntensity); 
	attemptcounter++;
	delay_ms(250);
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;
				sprintf(uffit,"B %Lu Red %Lu PWM %Lu  %Lu", blueABS, redABS,PWMIntensity,attemptcounter);
				Display_XYString(0, 1, &uffit);
	}
PWMDOIntensity = PWMIntensity;  //Save the last PWM intensirty for the next go a round.
	}

*/
//*************************************************************************************
//  Added Augest 28, 2015
//  This section uses a set point PWM number that is saved and reteived from the SD Card.
//*************************************************************************************
if (SensorChannel == 8)
	{

	selectsensor(0);    // Added December 9, 2015     Sensor 0 is DO.
//	pwm_set_duty(DO_PWM,PWMDOIntensity);   // old

	pwm_set_duty(PH_PWM,PWMDOIntensity); 

    delay_ms(200);  // set a PWM setup delay to stablize the timing.
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading

	pwm_set_duty(PH_PWM,0x0000);     // Turn off DO light to cool off LED junction.
    
    
    

	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.

if (redABS < 0)
	{
	redABS = 0;
	}
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

/*
while (((blueABS < lowerlimit) || (blueABS > upperlimit)) && (attemptcounter < attempts))   // If it is in range, then exit.  If not in range, adjest and try again.
	{

	if (RequiredReading < blueABS)
		{
		difference = blueABS - (unsigned int32) RequiredReading;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity - (int16) difference;   //  As the PWM number goes up, the light goes up.
		}
		else
		{
		difference = (unsigned int32) RequiredReading - blueABS;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity + (int16) difference;   // As the PWM number goes down, the light goes down.
		}
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
*/
	pwm_set_duty(PH_PWM,PWMDOIntensity); 
//	attemptcounter++;
	delay_ms(200);    // set a time delay for time setup  Added April 14, 2016
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
//	fprintf(BT," PWM %Lu\n\r",PWMIntensity);
	pwm_set_duty(PH_PWM,0x0000);     // Turn off DO light to cool off LED junction.
fprintf(BT,"Before Background subtraction Red->%Lu Green->%Lu Blue ->%Lu\n\r",redABS,greenABS,blueABS); 

	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;
				sprintf(uffit,"B %Lu Red %Lu PWM %Lu  %Lu", blueABS, redABS,PWMIntensity,attemptcounter);
				Display_XYString(0, 1, &uffit);

fprintf(BT,"After Background subtraction Red->%Lu Green->%Lu Blue ->%Lu\n\r",redABS,greenABS,blueABS); 

if (redABS < 0)
	{
	redABS = 0;
	}
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



//********************************************************************
// Created Aug 5, 2015
//  This routine prints to the BT raw data where it can be collected on a terminal program.
//********************************************************************
/*
if (toggleechoonoff)    // see if it needs to send the string to bluetooth.  Added July 14, 2015 
	{ 
	fprintf(BT,"Red,%Lu,Green,%Lu,Blue,%Lu,PWM,%Lu\n\r",redABS,greenABS,blueABS,PWMIntensity); 
	}

*/
//	}

//redABS = 3757;


sysOutput.wTemp = WaterTemperature();

//sysOutput.wTemp = 10.0;
fprintf(BT,"Raw Reading before calculating DO  Red->%Lu Green->%Lu Blue ->%Lu\n\r",redABS,greenABS,blueABS); 
//PWMDOIntensity = PWMIntensity;  //Save the last PWM intensirty for the next go a round.
//	DOReading =  CalcaulateDO(redABS,sysOutput.wTemp);  //This holds the color intensity variable and the temperature in degrees C.
//	BTBasicTest();    //Check BT 
//	BTBasicTest();    //Check BT 


//********************************************************************
// Created Aug 5, 2015
//  This routine prints to the BT raw data where it can be collected on a terminal program.
//********************************************************************

if (toggleechoonoff)    // see if it needs to send the string to bluetooth.  Added July 14, 2015 
	{ 
	fprintf(BT,"Red->%Lu Green->%Lu Blue ->%Lu DO->%f PWM->%Lu\n\r",redABS,greenABS,blueABS,DOReading,PWMDOIntensity); 
	}
		return(DOReading);  //Return result.
	}





//*************************************************************************************
//
if (SensorChannel == 6)
	{
//	readingrange = 150;
    upperlimit = RequiredReading + DOreadingrange;
    lowerlimit = RequiredReading - DOreadingrange;
//	pwm_set_duty(DO_PWM,PWMIntensity); 
//	delay_ms(25);
	attemptcounter = 0;
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pgain = 0.0175;   //This the propotional gain for the PID loop.  old one
//	pgain = 0.0003125;   //This the propotional gain for the PID loop.  Added May 23, 2015
//	pwm_set_duty(DO_PWM,0x000);     // Turn off DO light to cool off LED junction.
	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;
/*
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
*/
//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.

if (redABS < 0)
	{
	redABS = 0;
	}
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


while (((blueABS < lowerlimit) || (blueABS > upperlimit)) && (attemptcounter < attempts))   // If it is in range, then exit.  If not in range, adjest and try again.
	{

	if (RequiredReading < blueABS)
		{
		difference = blueABS - (unsigned int32) RequiredReading;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity - (int16) difference;   //  As the PWM number goes up, the light goes up.
		}
		else
		{
		difference = (unsigned int32) RequiredReading - blueABS;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity + (int16) difference;   // As the PWM number goes down, the light goes down.
		}
/*
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
	BTBasicTest();    //Check BT 
*/
//	pwm_set_duty(DO_PWM,PWMIntensity); 
	attemptcounter++;
//	delay_ms(100);
	color = GetCurrentColorAVG(4, 1);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
//	fprintf(BT," PWM %Lu\n\r",PWMIntensity);
//	pwm_set_duty(DO_PWM,0x0000);     // Turn off DO light to cool off LED junction.


	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;
				sprintf(uffit,"B %Lu Red %Lu PWM %Lu  %Lu", blueABS, redABS,PWMIntensity,attemptcounter);
				Display_XYString(0, 1, &uffit);



if (redABS < 0)
	{
	redABS = 0;
	}
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



//********************************************************************
// Created Aug 5, 2015
//  This routine prints to the BT raw data where it can be collected on a terminal program.
//********************************************************************

if (toggleechoonoff)    // see if it needs to send the string to bluetooth.  Added July 14, 2015 
	{ 
	fprintf(BT,"Red,%Lu,Green,%Lu,Blue,%Lu,PWM,%Lu\n\r",redABS,greenABS,blueABS,PWMIntensity); 
	}


	}



PWMDOIntensity = PWMIntensity;  //Save the last PWM intensirty for the next go a round.
//		DOReading =  CalcaulateDO(redABS,sysOutput.wTemp);  //This holds the color intensity variable and the temperature in degrees C.
//	BTBasicTest();    //Check BT 
//	BTBasicTest();    //Check BT 


//********************************************************************
// Created Aug 5, 2015
//  This routine prints to the BT raw data where it can be collected on a terminal program.
//********************************************************************

if (toggleechoonoff)    // see if it needs to send the string to bluetooth.  Added July 14, 2015 
	{ 
	fprintf(BT,"Red,%Lu,Green,%Lu,Blue,%Lu,DO,%f,PWM,%Lu\n\r",redABS,greenABS,blueABS,DOReading,PWMDOIntensity); 
	}

		return(DOReading);  //Return result.
	}






if (SensorChannel == 2)
	{
	pwm_set_duty(PH_PWM,PWMIntensity); 
	delay_ms(200);
//	readingrange = 4000;
    upperlimit = RequiredReading + pHreadingrange;
    lowerlimit = RequiredReading - pHreadingrange;
	attemptcounter = 0;
	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
//	pgain = 0.125;   //This the propotional gain for the PID loop.  old one
	pgain = 0.001025;   //This the propotional gain for the PID loop.  Added May 23, 2015

	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;

//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.

if (redABS < 0)
	{
	redABS = 0;
	}
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


while (((blueABS < lowerlimit) || (blueABS > upperlimit)) && (attemptcounter < attempts))   // If it is in range, then exit.  If not in range, adjest and try again.
	{

	if (RequiredReading < blueABS)
		{
		difference = blueABS - (unsigned int32) RequiredReading;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity - (int16) difference;   //  As the PWM number goes up, the light goes up.
		}
		else
		{
		difference = (unsigned int32) RequiredReading - blueABS;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity + (int16) difference;   // As the PWM number goes down, the light goes down.
		}
	if (PWMIntensity > 0x0200)
		{
		PWMIntensity = 0x0200;
		}

//	BTBasicTest();    //Check BT 

	pwm_set_duty(PH_PWM,PWMIntensity); 
	attemptcounter++;
	delay_ms(250);
	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;
				sprintf(uffit,"B %Lu R %Lu", blueABS, redABS);
				Display_XYString(0, 1, &uffit);
				sprintf(uffit,"PWM %Lu Count %Lu",PWMIntensity,attemptcounter);
				Display_XYString(0, 2, &uffit);
	}
PWMPHIntensity = PWMIntensity;  //Save the last PWM intensirty for the next go a round.
	}







if (SensorChannel == 4)
	{
	pwm_set_duty(PH_PWM,PWMIntensity); 
//	delay_ms(200);
//	pHreadingrange = 200;   //Used to be 2000  July 27, 2015
    upperlimit = RequiredReading + pHreadingrange;
    lowerlimit = RequiredReading - pHreadingrange;
	attemptcounter = 0;
	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading


//	pgain = 0.125;   //This the propotional gain for the PID loop.  old one
	pgain = 0.00225;   //This the propotional gain for the PID loop.  Added May 23, 2015, Commented out by ZS on July 28, 2015.
//	pgain = 0.0175;   //This the propotional gain for the PID loop.  Added May 23, 2015
	pwm_set_duty(PH_PWM,0x0000);     //Added july 23, 2015.  Turn off lamp imidially to minimize thermal heating.
	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;


//***********************************************************************
// Created July 28, 2015
// This routine step changes gains for the PID feedback look.  The closer it get to the goal, the less the gain becomes.
//***********************************************************************

stepdifference = abs(blueABS - RequiredReading);
if (stepdifference < (3*pHreadingrange))
		{
		pgain = 0.00225;   //This the propotional gain for the PID loop.  Added May 23, 2015, Commented out by ZS on July 28, 2015.

		}
		else
		{
		pgain = 0.0175;   //This the propotional gain for the PID loop.  Added May 23, 2015
		}



//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.

if (redABS < 0)
	{
	redABS = 0;
	}
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


while (((blueABS < lowerlimit) || (blueABS > upperlimit)) && (attemptcounter < attempts))   // If it is in range, then exit.  If not in range, adjest and try again.
	{



if (redABS < 0)
	{
	redABS = 0;
	}
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


//***********************************************************************
// Created July 28, 2015
// This routine step changes gains for the PID feedback look.  The closer it get to the goal, the less the gain becomes.
//***********************************************************************

stepdifference = abs(blueABS - RequiredReading);
if (stepdifference < (pHreadingrange*3))
		{
		pgain = 0.00225;   //This the propotional gain for the PID loop.  Added May 23, 2015, Commented out by ZS on July 28, 2015.

		}
		else
		{
		pgain = 0.0075;   //This the propotional gain for the PID loop.  Added May 23, 2015
		}



	if (RequiredReading < blueABS)
		{
		difference = blueABS - (unsigned int32) RequiredReading;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity - (int16) difference;   //  As the PWM number goes up, the light goes up.
		}
		else
		{
		difference = (unsigned int32) RequiredReading - blueABS;
		tempoffset = pgain * (float) difference;
		difference =  (unsigned int32) tempoffset;
		PWMIntensity = PWMIntensity + (int16) difference;   // As the PWM number goes down, the light goes down.
		}


ttt=0;
while(ttt < 1000)    //Sit here and wait for the LED to cool off.
	{
//	BTBasicTest();    //Check BT 

	delay_ms(2);
	ttt++;
	}


	pwm_set_duty(PH_PWM,PWMIntensity); 
	attemptcounter++;

	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pwm_set_duty(PH_PWM,0x0000);     //Added july 23, 2015.  Turn off lamp imidially to minimize thermal heating.


	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;

				sprintf(uffit,"B %Lu R %Lu", blueABS, redABS);
				Display_XYString(0, 1, &uffit);
				sprintf(uffit,"PWM %Lu Count %Lu %Lu",PWMIntensity,attemptcounter,color);
				Display_XYString(0, 2, &uffit);
	}
PWMPHIntensity = PWMIntensity;  //Save the last PWM intensirty for the next go a round.
	}



//**************************************************************
// Created Jan 19, 2016
// This is a fixed PWM for the NH3.
// The variable is saved in seed
//**************************************************************


if (SensorChannel == 9)
	{

	pwm_set_duty(PH_PWM,PWMIntensity); 

	color = GetCurrentColorAVG(4, 4);   // The first number is the gain reading.  The second number is the measurement device.  4 is for nh3 which is the center LED and sensor.  Added Jan 20, 2016

	pwm_set_duty(PH_PWM,0x0000);     //Added july 23, 2015.  Turn off lamp imidially to minimize thermal heating.
	redABS = redABS - Ambientnh3Red;
	greenABS = greenABS - Ambientnh3Green;
	blueABS = blueABS - Ambientnh3Blue;
	clearABS = clearABS - Ambientnh3Clear;





//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.

if (redABS < 0)
	{
	redABS = 0;
	}
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


	pwm_set_duty(PH_PWM,PWMIntensity); 


	color = GetCurrentColorAVG(4, 4);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pwm_set_duty(PH_PWM,0x0000);     //Added july 23, 2015.  Turn off lamp imidially to minimize thermal heating.


	redABS = redABS - Ambientnh3Red;
	greenABS = greenABS - Ambientnh3Green;
	blueABS = blueABS - Ambientnh3Blue;
	clearABS = clearABS - Ambientnh3Clear;
		//		VacDisplayClear();
		//		sprintf(uffit,"B %Lu R %Lu", blueABS, redABS);
		//		Display_XYString(0, 1, &uffit);
		//		sprintf(uffit,"PWM %Lu",PWMIntensity);
		//		Display_XYString(0, 2, &uffit);

	}



//**************************************************************
// Created Aug 5, 2015
// This is a fixed PWM for the pH.
// The variable is saved in seed
//**************************************************************


if (SensorChannel == 7)
	{

	pwm_set_duty(PH_PWM,PWMIntensity); 

	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading



	pwm_set_duty(PH_PWM,0x0000);     //Added July 23, 2015.  Turn off lamp imidially to minimize thermal heating.
	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;





//if the number is less than 0, then set it to zero.  It's not possible to have negitave light.

if (redABS < 0)
	{
	redABS = 0;
	}
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


	pwm_set_duty(PH_PWM,PWMIntensity); 


	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pwm_set_duty(PH_PWM,0x0000);     //Added july 23, 2015.  Turn off lamp imidially to minimize thermal heating.


	redABS = redABS - AmbientPHRed;
	greenABS = greenABS - AmbientPHGreen;
	blueABS = blueABS - AmbientPHBlue;
	clearABS = clearABS - AmbientPHClear;
		//		VacDisplayClear();
		//		sprintf(uffit,"B %Lu R %Lu", blueABS, redABS);
		//		Display_XYString(0, 1, &uffit);
		//		sprintf(uffit,"PWM %Lu",PWMIntensity);
		//		Display_XYString(0, 2, &uffit);

	}



if (SensorChannel == 5)
	{
//	pwm_set_duty(PH_PWM,PWMIntensity); 
	delay_ms(200);
//	readingrange = 4000;
    upperlimit = RequiredReading + pHreadingrange;
    lowerlimit = RequiredReading - pHreadingrange;
	attemptcounter = 0;
	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
//	pgain = 0.125;   //This the propotional gain for the PID loop.  old one
	pgain = 0.0001025;   //This the propotional gain for the PID loop.  Added May 23, 2015
//	pwm_set_duty(PH_PWM,0x0000);     //Added july 23, 2015.  Turn off lamp imidially to minimize thermal heating.


while (1)   // If it is in range, then exit.  If not in range, adjest and try again.
	{


ttt=0;
while(ttt < 100)    //Sit here and wait for the LED to cool off.
	{
//	BTBasicTest();    //Check BT 
	delay_ms(100);
	ttt++;
	}

	pwm_set_duty(PH_PWM,0x0800); 


	color = GetCurrentColorAVG(4, 2);   // Number 1 is the blue DO PWM LED.  The 4 means it any gain reading
	pwm_set_duty(PH_PWM,0x0000);     //Added july 23, 2015.  Turn off lamp imidially to minimize thermal heating.


//	redABS = redABS - AmbientPHRed;
//	greenABS = greenABS - AmbientPHGreen;
//	blueABS = blueABS - AmbientPHBlue;
//	clearABS = clearABS - AmbientPHClear;

				sprintf(uffit,"B %Lu R %Lu", blueABS, redABS);
				Display_XYString(0, 1, &uffit);
				sprintf(uffit,"PWM %Lu %Lu",PWMIntensity,color);
				Display_XYString(0, 2, &uffit);
	}
	}




//Take the reading for real

switch (SensorChannel)
	{
	case 1:  //This is the DO Sensor
 
//	    pwm_set_duty(DO_PWM, PWMIntensity);	//  Turn off light for DO
        delay_ms(225);  //Delay to stablize PWM


		color = GetCurrentColorAVG(4, 1);   // Number 0 is the red PWM LED
 
 
	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

		//DOReading =  CalcaulateDO(redABS,sysOutput.wTemp);  //This holds the color intensity variable and the temperature in degrees C.
//	    pwm_set_duty(DO_PWM,0x00);	//250hz  Turn off light for DO

		delay_ms(1000);

				sprintf(uffit,"RED %Lu DO %f wTemp %f", redABS,DOReading,sysOutput.wTemp);
				Display_XYString(0, 3, &uffit);

		return(DOReading);  //Return result.
		break;
/*	case 2:  //This is the pH Sensor
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
		break;  */

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
        
       if (DeviceSelect == 9)  //Setup the PH offsets.
		{
		Ambientnh3Red = redABS;
		Ambientnh3Green = greenABS;
		Ambientnh3Blue = blueABS;
		Ambientnh3Clear = clearABS;
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
/*float FindWAGuysPH(void)
	{
		char uffit[80];
			calculateCoordinate();
			sprintf(uffit,"y %e %Lu",y,blueABS);
			Display_XYString(0, 4, &uffit);
			sprintf(uffit,"x %e %Lu",x,greenABS);
			Display_XYString(0, 3, &uffit);	
	return(0.0);
	}*/



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




