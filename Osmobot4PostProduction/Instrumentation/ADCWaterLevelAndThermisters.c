float tempa1, tempa2, tempa3;   //Addded May 15, 2014 These are the coefecents for thermister calculation
float lastwaterlevel=0;   // Added July 21, 2015  This keeps track of the last water level for abrupt changes.



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

//*************************************************************
// Created May 15, 2015
// This routine solves for the coefficents for thermisters ai
// This routine reads the EEPROM (when completed) and calculates the curve and temperature from four thermal points.
//*************************************************************

void DetermineTempCoef(void)
{
//This has been removed and placed in TaosLightSensor.h  May 21, 2015
//float temp1,reading1,temp2,reading2,temp3,reading3;
float temp1in,temp2in,temp3in;
float reading1in,reading2in,reading3in;
float det, det1, det2, det3;   //These are the other dets for each solution
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

//*****************************************************************
// Created May 19, 2016
// This takes a sampling of the pHBulb and averages them all together.
// The result is the raw data from the ADC.  In this case it is connected to AD7
// It returns a float
//****************************************************************

float ConvertADCTophBulb(void)
	{
int16 ReturnedADC;
int x;
float tempfloater, tempsummer;
tempsummer = 0.0;
for (x=0; x < 10; x++)
    {
    
   // fprintf(BT,"Getting Reading %f\r\n",tempfloater);
	ReturnedADC = GetADCValue(9);  //This gets the current ADC conversion for the channel number.

  tempfloater = (float) ReturnedADC;
    tempsummer = tempsummer + tempfloater;
    
    }
    tempfloater = tempsummer / 10.0;
	return(tempfloater);
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
	ReturnedADC = GetADCValue(ADCInputNumber);  //This gets the current ADC convertion for the channel number.
//    ADCVoltageIn = ReturnedADC * 5.0 / 1024.0;  //Recycled the same float variable.  This is for the 5 volts version.
  tempfloater = (float) ReturnedADC;
  ADCVoltageIn = (float) ReturnedADC * 3.3 / 1024.0;  //Recycled the same float variable.  This converts the input into scaling

//Added May 18, 2015  - The current/last thermister is RL0503-7.56K-96-MS  it's a 30K thermister.

//	ADCVoltageIn = 5100.0*ADCVoltageIn/(3.3 - ADCVoltageIn);  // Calulate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K

ADCVoltageIn = 4999.0*ADCVoltageIn/(3.3 - ADCVoltageIn);  // Calulate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K



//ADCVoltageIn=12000.0;

DetermineTempCoef();

//Kelvin = (1/(tempa1 + tempa2*(log(ADCVoltageIn)) + tempa3*(log(ADCVoltageIn)*log(ADCVoltageIn))))-273.15;   //This is the old line of code used to find the thermister temperature
Kelvin = (1/(tempa1 + tempa2*(log(ADCVoltageIn)) + tempa3*(log(ADCVoltageIn)*log(ADCVoltageIn))))-273.15;
	return(Kelvin);
	}




//*******************************************************************
// Created June 26, 2015
// This routine creates the offset for air/pressure/temperature variations.  The temperature changes the air pressure inside the
// water depth hose and makes an offset.  This routine comenstates for the offset.
// The current temperature and is read into the routine and the output is calcaulated as an offset from the current measurement.  
//  It is assumed the temperature variations will be dependent on the hose length, perhaps.  This is an attempt to find out.
//  Returns the depth relative offset.
//*******************************************************************
float WaterDepthCompensation(float currenttemperature)
	{

//This routine first tries the y = mx + b routine before doing anything weirder.

	float m,x,y;
	float lowtemp, hightemp, lowlevel, highlevel;

	lowtemp = 23.3;    //This is retreived from experimental data.  (20.3 , 23.3)
	hightemp = 27.0;   //C   (23.1, 27.0)
	lowlevel = 20.3;    //CM    (20.3 , 23.3)
	highlevel = 24.1;  //CM   (23.1, 27.0)   // This is change from  23.1 to increase the strength.  Changed June 30, 2015

	// m= x/y.  This is the invsere of the tradiational equation.  We want temperature differnce to make an offset.

	m = (highlevel - lowlevel)/(hightemp - lowtemp);

	//Find b
	//Use one of the points.  When there is a zero temperature difference, there needs to be a zero offset. That means b is equal to zero in all cases.
	y = currenttemperature - StartWaterTemperature;
	x = m*y;

	return (x);
	}



//********************************************************************
// Created Nov 6, 2012
// ReCreated for Osmobot October 3, 2014
// This inits all of the ADC convereters for input.
//  There is no output from this funtion.+
//********************************************************************
void SetupADC(void)
	{
    setup_adc(ADC_CLOCK_INTERNAL);
 //   setup_adc_ports( sAN9 | sAN5 | sAN2 |VSS_VDD );
   setup_adc_ports( sAN7 | sAN9 | sAN5  |VSS_VDD );    // AN2 has been removed to use it for the orginal reason as a I/O pin for the blue tooth device.  Changed Augest 17, 2015
 //  setup_adc_ports( sAN7 | sAN5  |VSS_VDD );    // AN2 has been removed to use it for the orginal reason as a I/O pin for the blue tooth device.  Changed Augest 17, 2015  sAN9 is removed for pressure sensor  Jan 12, 2017

}

//************************************************************************
// Created May 19, 2016
// This finds the current raw and calculated reading for the pHbulb.
// it returns the calculated ph off the gain and current set offset.
// The raw data has to be returned through a global variable.
//************************************************************************
float phBulb(void)
{
    float currentphreading;
    currentphreading = ConvertADCTophBulb();
    
    return(currentphreading);
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
	temparray[x] = ConvertADCToKalvin(5);   //This called current thermisting reading routine. It returns a temperature reading in C.
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





//********************************************************************
// Created June 12, 2013
// This routine uses AN4 input from the pressure sensor to deteminen the depth of water via. pressure.
// AN4 is read and scaled between 0 volts and a little less than 5 volts.
// The retuend result is the measurement in inches.  The input is the ADC 4 converter number.
// The returned number is a float.
// The fuill range is 1024 and is 5 volts.  There are 1024 levels
//********************************************************************
float MeasureWaterDepth(void)
	{
	signed int16 ADCReading;
	float Measurit,stuff;

	ADCReading = GetADCValue(9);   //Read current pressure value.
//	ADCReading = ADCReading - 0x005E;   // Remove the offset for this diff sensor
	ADCReading = ADCReading - (int) pHreadingrange;   // Remove the offset for this diff sensor

/*
	if (ADCReading < 0)
		{
		ADCReading = 0;
		}*/
//	Measurement = (float) ADCReading / 7.047 ;   //Convert the ADC converstion in to cm.  Commented out on July 9, 2015
//	Measurement = (float) ADCReading / 6.947 ;   //Convert the ADC converstion in to cm. Commented out on July 21, 2015
		Measurit = (float) ADCReading / 7.31;   //Convert the ADC converstion in to cm.  





//	Measurit = (float) ADCReading ;   //Convert the ADC converstion in to cm.


//*****************************
// Added June 26, 2015
// Do water depth compensation according to temperauter
//*****************************
/*
if (!GetTempRH())
	{
	sysOutput.aTemp = Temperature;  //This is the float temperature
	sysOutput.rH = RHData;  //This is a float send into ta RH value.
	}


Measurement =  Measurement - WaterDepthCompensation(sysOutput.aTemp);

	if (Measurement < 0.5)
		{
		Measurement = 0.0;
		}
*/
stuff = Measurit - lastwaterlevel;
if (stuff > 0.0)
	{
	if (stuff < 2.50)
		{
		Measurit = lastwaterlevel;
		}
	}

lastwaterlevel = Measurit;

	return(Measurit);
//	return(Measurement);
	}


