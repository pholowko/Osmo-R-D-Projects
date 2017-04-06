

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

	float temp1,reading1,temp2,reading2,temp3,reading3;
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

if (lightsensor==3)   // changed March 23, 2016.  The passing number is the true sensor number, not the index   Used to be 1
	{
    PrescalerGain = 1;
	//PrescalerGain = ExposurescaleDO;
	}

if (lightsensor==1)  // changed March 23, 2016.  The passing number is the true sensor number, not the index   Used to be 2
	{
	//PrescalerGain = ExposurescalepH;
    PrescalerGain = 1;
	}

if (lightsensor==0)   // This is now for NH4
	{
    //PrescalerGain = ExposurescaleLight;
	PrescalerGain = 1;
	}


if (AnalogGain > 3)
	{
	AnalogGain = 3;
	}

// Concatinate the control byte.
controlword = AnalogGain*16 + PrescalerGain;  //This is the offset for gain to placeinto the chip.  Added March 4, 2015
	selectsensor(lightsensor);   // make the selection to talk with this sensor.

// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x72);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x87);  //The 0x80 is used to tell it's a command.  This is for register 0x07.
	i2c_write(PH_LIGHT,controlword);  //Move the address number left on and add a zero.
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

unsigned int gainMultiplyer;

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
int x,GainOut,averagesamples = 10;
unsigned int gainMultiplyer;



if (DeviceSelect == 3)   //If this is for DO and the light sensor
	{
	averagesamples = 5;
	ageraging = 5.0;
    selectsensor(3);

	}

if (DeviceSelect == 0)   //If this is for NH4 and the light sensor
	{
	averagesamples = 5;
	ageraging = 5.0;
    selectsensor(0);

	}
if (DeviceSelect == 1)   //If this is for NH4 and the light sensor
	{
	averagesamples = 5;
	ageraging = 5.0;
    selectsensor(1);

	}

	tempred = 0.0;
	tempblue = 0.0;
	tempgreen = 0.0;
	tempclear = 0.0;
	for (x = 0; x < averagesamples; x++)
		{
		GainOut = GetCurrentColor(GainIn, DeviceSelect);

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
//*****************************************************************************************
void InitTAOS(void)
{

int8 x;



//setTAOSGain(1,0); //Gain and then scale
//setTAOSGain(gain,1); //Gain and then scale
//setTAOSGain(1,2); //Gain and then scale
//setTAOSGain(gain,3); //Gain and then scale
//setTAOSGain(1,4); //Gain and then scale
//setTAOSGain(gain,5); //Gain and then scale

ExposureTimeTAOS(2,0);   // this is for Dph   intigration time of 400ms at number 2
ExposureTimeTAOS(0,1);   //This is for the DO  // Changed to 400ms exposure and then more light.  
ExposureTimeTAOS(2,3);   //This is for the NH4  // 

/*
for (x=0; x < 4; x++)	    // This runs through all of the sensors and starts them up.  Updated December 8, 2015
	{
	StartUpTAOS(x);
	}
*/


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
    output_high(PIN_B10);  // turn off red
 
    
    output_high(PIN_B5);  // turn on white DpH LED
    delay_ms(250);
    output_low(PIN_B5);  // turn off orange DpH LED
    output_high(PIN_B12);  // turn on blue for DO   
     delay_ms(250);
    output_low(PIN_B12);  // turn off blue DO
    output_low(PIN_B10);  // turn on red   
    delay_ms(250);


    output_high(PIN_B11);  // turn off blue
    output_high(PIN_B10);  // turn off red
    output_low(PIN_B5);  // turn off red for p 
}