//**********************************************************************************************
// Created November 23, 2016
//these are the calibration varibles so far on the tester.  
//**********************************************************************************************

typedef struct {
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
float eccal1x;
float eccal2x;
float eccal3x;
float eccal1y;
float eccal2y;
float eccal3y;
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
char unittype[5];  // This is a string of no more than 5 characters to describe the unit type.  Needs to end with a null.
}Calstuff;
Calstuff sysInput; 
/*

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
}inputData;
inputData sysInput;

*/

#ifdef SLAVE

float Temp1DOOne;
float Temp1DOTwo;
float Temp1DOThree;
float Temp2DOOne;
float Temp2DOTwo;
float Temp2DOThree;
float Temp3DOOne;
float Temp3DOTwo;
float Temp3DOThree;
float Temp1ReadingOne;
float Temp1ReadingTwo;
float Temp1ReadingThree;
float Temp2ReadingOne;
float Temp2ReadingTwo;
float Temp2ReadingThree;
float Temp3ReadingOne;
float Temp3ReadingTwo;
float Temp3ReadingThree;

unsigned int16 TempOne;
unsigned int16 TempTwo;
unsigned int16 TempThree;

#endif