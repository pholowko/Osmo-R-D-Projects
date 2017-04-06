float tempa1, tempa2, tempa3;   //Addded May 15, 2014 These are the coefecents for thermister calculation

//*************************************************************
// Created May 15, 2015
// This routine solves for the coefficents for thermisters ai
// This routine reads the EEPROM (when completed) and calculates the curve and temperature from four thermal points.
//*************************************************************

void DetermineTempCoef(void)
{

float temp1,reading1,temp2,reading2,temp3,reading3;
float det, det1, det2, det3;   //These are the other dets for each solution
// This is the raw data.  Added May 15, 2015

temp1 = 42;
temp2 = 21;
temp3 = 6;

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

reading1 = 16000;
reading2 = 36021;   //this is measured at 21 C
reading3 = 65000;


temp1 = 1.0/(temp1 + 273.0);
temp2 = 1.0/(temp2 + 273.0);
temp3 = 1.0/(temp3 + 273.0);


reading1 = log(reading1);
reading2 = log(reading2);
reading3 = log(reading3);


//  This part solves for tempa1, tempa2, tempa3 4
// Find the divistion determinent

matx[0][0] = 1.0;
matx[1][0] = 1.0;
matx[2][0] = 1.0;
matx[0][1] = reading1;
matx[1][1] = reading2;
matx[2][1] = reading3;
matx[0][2] = reading1*reading1;
matx[1][2] = reading2*reading2;
matx[2][2] = reading3*reading3;

det = FindTheDetermint();

//Find the det for tempa1

matx[0][0] = temp1;
matx[1][0] = temp2;
matx[2][0] = temp3;
matx[0][1] = reading1;
matx[1][1] = reading2;
matx[2][1] = reading3;
matx[0][2] = reading1*reading1;
matx[1][2] = reading2*reading2;
matx[2][2] = reading3*reading3;

det1 = FindTheDetermint();
tempa1=det1/det;   //  This finds the value for the first a1

matx[0][0] = 1.0;
matx[1][0] = 1.0;
matx[2][0] = 1.0;
matx[0][1] = temp1;
matx[1][1] = temp2;
matx[2][1] = temp3;
matx[0][2] = reading1*reading1;
matx[1][2] = reading2*reading2;
matx[2][2] = reading3*reading3;


det2 = FindTheDetermint();
tempa2=det2/det;   //  This finds the value for the first a2



matx[0][0] = 1.0;
matx[1][0] = 1.0;
matx[2][0] = 1.0;
matx[0][1] = reading1;
matx[1][1] = reading2;
matx[2][1] = reading3;
matx[0][2] = temp1;
matx[1][2] = temp2;
matx[2][2] = temp3;

det3 = FindTheDetermint();
tempa3=det3/det;   //  This finds the value for the first a2


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
//    ADCVoltageIn = ReturnedADC * 5.0 / 1024.0;  //Recycled the same float variable.
  tempfloater = (float) ReturnedADC;
  ADCVoltageIn = (float) ReturnedADC * 3.3 / 1024.0;  //Recycled the same float variable.


	ADCVoltageIn = 5100.0*ADCVoltageIn/(3.3 - ADCVoltageIn);  // Calulate the thermister reistance over a voltage divider.  It's at the bottom of a 0 to 5 volts divider.  The resistance is 4.999K

//ADCVoltageIn=12000.0;

DetermineTempCoef();

Kelvin = (1/(tempa1 + tempa2*(log(ADCVoltageIn)) + tempa3*(log(ADCVoltageIn)*log(ADCVoltageIn))))-273.15;

	return(Kelvin);
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
	float Measurement;

	ADCReading = GetADCValue(9);   //Read current pressure value.
	ADCReading = ADCReading - 0x0057;   // Remove the offset for this diff sensor
	if (ADCReading < 0)
		{
		ADCReading = 0;
		}
	Measurement = (float) ADCReading / 7.047 ;   //Convert the ADC converstion in to cm.
	if (Measurement < 0.5)
		{
		Measurement = 0.0;
		}
	return(Measurement);
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
    setup_adc_ports( sAN9 | sAN5 | sAN2 |VSS_VDD );
	}

