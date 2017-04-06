
//****************************************************************
// Created/Moved May 20, 2015
// These varables are moved here to be global.
//  They are all for the DO only.
//****************************************************************
int debugnumber = 0;  //Added July 13, 2015.  It keeps the current state of the debug routine calls.  Default is zero; or not in debug/calibration mode.


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


	float TempOne = 10.0;       //Calibration temperatures for DO   Added April 7, 2015
 	float TempTwo =  20.0;      //Calibration temperatures for DO  Added April 7, 2015
	float TempThree =  25.0;     //Calibration temperatures for DO  Added April 7, 2015


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
