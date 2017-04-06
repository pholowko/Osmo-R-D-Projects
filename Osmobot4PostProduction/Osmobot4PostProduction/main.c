#include <24FJ256GA106.h>
#define PIC24 1
#device PASS_STRINGS = IN_RAM
#DEVICE ICD=2
#device ADC=10
#device PSV=16
#device CONST=READ_ONLY
#use delay( crystal=8mhz, clock=32mhz )




#define debugDisplay 0
#define BUFFERSIZE 600
#define USEWEBSERVER 1
int16 testcntr=0;

#define USESENSORS 1

#define BTDEBUG 0
int1 wifisetup = 0;


#define SENDINTERVAL 800



int1 ROUTERHOLD=0;
int1 SCANERROR=0;
int1 ROUTERSCANING=0;
int1 checkScanError=0;

int1 ISWWWPARSE=0;

#define CLIENT 0
#define SERVER 1

int1 clientOrServer=SERVER;	//0 for client, 1 for server



char requestURLBuff[255];
char WebPageTxtBuff[4000];


int1 checkATOK =0;
int1 ATisOK=0;
int1 WFIsConfig=0;
int1 USEAT=0;
int1 resetParsing=0;


typedef struct outputDataStruct{
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
float wLevel;
float lLevelX;
float lLevelY;

int16 lLevelRed;
int16 lLevelGreen;
int16 lLevelBlue;
int16 lLevelClear;
int8 time;
int16 date;


float lLevelScale;
float rH,averagepH;
float aTemp;
int16 cO2;
float nH4;
float dPoint;
char DIEHARD[8];
}outputData;


outputData sysOutput;
char timeString[28];
int16 xp,yy;
float averagepH;

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
}inputData;
inputData sysInput;





#include <float.h>

#include "HC-06.c"
#include "crc8.c"
#include <math.h>

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <stddef.h>
#include "C:\Aquarium Software\OSMOBOT_PROTOTYPES\MCU_WEB_SERVER\VacDisplayRoutines.c"
#include "USR-WIFI232-X.c"
#include <routerParse.h>
#include "wwwParser.c"
#include "osmoWebServer.c"
#include <Stringsplitter.h>


#define ALLOW_GET_DISK_PROPERTIES q  //used by 'info' command










#USE PWM(OUTPUT=PIN_D1, FREQUENCY=8000Hz, STREAM=PH_PWM)      //Pin 49
#USE PWM(OUTPUT=PIN_D2, FREQUENCY=8000Hz, STREAM=DO_PWM)    //Pin 48


//#USE PWM(OUTPUT=PIN_D1, STREAM=PH_PWM)      //Pin 49
//#USE PWM(OUTPUT=PIN_D2, STREAM=DO_PWM)    //Pin 48

#if USESENSORS 


#use i2c(stream=PH_Light, MASTER, sda=PIN_F4, scl=PIN_F5, FORCE_HW, SLOW)    // SDA2
#use i2c(stream=DO_Light, MASTER, sda=PIN_E7, scl=PIN_E6, FORCE_HW, SLOW)    // SDA3 
#use i2c(stream=Room_Light, MASTER, sda=PIN_G3, scl=PIN_G2, FORCE_HW, SLOW)    // SDA1


#include "sdcard\ex_mdd_common.h"



#include "Instrumentation\humidity.c"
#include "Instrumentation\TaosLightSensor.c"
#include "Instrumentation\ADCWaterLevelAndThermisters.c"
#include "Instrumentation\CheapRHAndTemp.c"

#include "OsmobotSDCard\SDCardRoutines.c"
#include "SensorAndMultiplexor.c"  // Added December 2, 2015 for the new board.   


#use fast_io(c)



#endif


//#define MMCSD_PIN_SCL     PIN_F3 //o
//#define MMCSD_PIN_SDI     PIN_F6 //i
//#define MMCSD_PIN_SDO     PIN_F2 //o
//#define MMCSD_PIN_SELECT  PIN_B9 //o
#define MMCSD_PIN_POWER   PIN_G9 //o
//#include "mmcsd.c"
//#include "fat.c"



char HTTPwString[1000];
//char HTTPrString[BUFFERSIZE];
char HTTPoutput[BUFFERSIZE-100];
//unsigned int8 newChksum=0;

//int uio;






////////////////////////////////////////
//Data Structure Initialization
////////////////////////////////////////

/////////////////////////////////////////
//End Data Structures
/////////////////////////////////////////



//////////////////////////////////////////
//Osmobot Hardware Initialization
//////////////////////////////////////////
void osmoInit(){




/////////////////////////////////
//NOTES:
//ON R1 of osmobot board DO LED is not hooked up to a PWM capable (RP) pin
//it is instead on an RPI pin and cannot use the PWM module
/////////////////////////////////


//pwm_set_duty(PH_PWM,9900);	//250hz
}
//////////////////////////////////////////
//End osmobot hardware initialization
//////////////////////////////////////////





//////////////////////////////////
//SSR ROUTINE
//////////////////////////////////

void writeSSR()
{
#if USESENSORS 
//////CHANGE THESE PINS TO SSR PINS
//output_bit(PIN_F5,sysInput.io1);
//output_bit(PIN_F6,sysInput.io2);
//output_bit(PIN_F7,sysInput.io3);
#endif
}


///////////////////////////////////////////
//END SSR
///////////////////////////////////////////



///////////////////////////////////
//SENSOR READ
//Created Nov. 3, 2014
// This routine reads all of the sensors at one time at this moment
// It needs to be split where it's time sliced to all RS232 interfacing
// A global variable needs to be set to indicate which sensor needs to be updated.
//  For now all of them are tested and send as local data.
///////////////////////////////////
int16 gainof; 

unsigned int8 sensorRead()
{

#if USESENSORS
//char uffit[40];
// **********************************************************************************
// Created Nov 3, 2014
//  Find the water depth and set it to the download variable
// This routine check the ADC and scales the pressure sensor
// **********************************************************************************
sysOutput.wLevel = MeasureWaterDepth();   //This returns the water depth in CM.

// *********************************************************************************
// Created Nov. 3, 2014
// Find the current water temperature and send the to the download variable
// This routine takes the thermister reading to the ADC and scales it to degrees C.
// *********************************************************************************
sysOutput.wTemp = ConvertADCToKalvin(5);


// *********************************************************************************
// Created No2. 3, 2014
// Find the RH and Temperature for the environment and send it to the server.
//  This routine talks with the cheap RH and Temperature sensor
// ********************************************************************************

if (!GetTempRH())
	{
	sysOutput.aTemp = Temperature;  //This is the float temperature
	sysOutput.rH = RHData;  //This is a float send into ta RH value.
	}

// ********************************************************************************
// Created Nov. 3, 2014
// This routines borrows the calcaulaton from the expensive SHt11 chip to calcaulate DP
// ********************************************************************************

sysOutput.dPoint=sht1x_calc_dewpoint(RHData,Temperature);


// ********************************************************************************
// Created Nov. 3, 2014
// This routines find the current ambnt light spectrum and uploads it to the server.
// ********************************************************************************
gainof = GetCurrentColor(4, 3);
sysOutput.lLevelRed=red;
sysOutput.lLevelGreen=green;
sysOutput.lLevelBlue=blue;
sysOutput.lLevelClear=clear;
sysOutput.lLevelScale=gainof;


//sysOutput.dOxy = FindMiddlePWMSensor(1, 1);   //Leave this in for calibration  Created May 21, 2014

//FindAmbientLight(1);
//sysOutput.dOxy = TakeLightReading(1, PWMDOIntensity, 20000);   // This routine takes a reading of DO which channel 1 and knows it's DO.  Channel 2 is pH.

//				sprintf(uffit,"RED %Lu DO %f  ", red, sysOutput.dOxy);
//				Display_XYString(0, 2, &uffit);
//FindAmbientLight(2);


//*******************************************************************************
//Created March 1, 2015
// This routine averages 10 pH readings together before releasing it to the server..
//*******************************************************************************
averagepH = 0.0;
for (yy=0; yy < 10; yy++)
	{
		
		xp = SetPWMWithPhotoTransistor(xp, 200);
//		sprintf(uffit,"ADC %Lu  %Lu %f ",  GetADCValue(2), xp, ConvertTopH());
//		Display_XYString(0, 2, &uffit);
		averagepH = ConvertTopH() + averagepH;
	}

sysOutput.pH = averagepH/10.0;

delay_ms(1000);
#endif
return (1);
}

////////////////////////////////////////////
//End Sensor Read
////////////////////////////////////////////

void dataInit(void){

sysOutput.deviceID="Eriks_Board:WTS";

sysOutput.dOxy=.20;
//sysOutput.time=0;
sysOutput.nH4=200;
sysOutput.rH=9001;
sysOutput.lLevelX=20;
//sysInput.uploadinterval=UPDATEINTERVALHARDWIRED;
//R_Minutes=sysInput.uploadinterval;
}



void printTime( unsigned int16 Year, unsigned int8 Month, unsigned int8 Day, unsigned int8 Hour, unsigned int8 Minute, unsigned int8 Second)
{
//sprintf(timeString,"%4lu-%2u-%2u$%2u:%2u:%2u",Year,Month,Day,Hour,Minute,Second);
sprintf(timeString,"%02u:%02u:%02u$%04lu-%02u-%02u",Hour,Minute,Second,Year,Month,Day,);
}




void reloadTime(void){
sysOutput.year=sysInput.year;
sysOutput.month=sysInput.month;
sysOutput.day=sysInput.day;
sysOutput.hour=sysInput.hour;
sysOutput.minute=sysInput.minute;
sysOutput.second=sysInput.second;
Display_XYString(0,1,"reloading Time\n\r");
}






// *****************************************************************
// Added Nov 12, 2014
//  This find the string length
// *****************************************************************


int16 strlenn(char stri[])
	{
	int16 i=0;
//	char stri[50];
	while(stri[i]!='\0')
		{
		i++;
		}
		return i;
}





void main(){
clearRouters(routerTable);	//Ensures router table is empty

intimultiplex();  // init the sensor multiplexor  This is for the new board.  Added Dec. 2, 2015


char uffit[80];

		VacDisplayinit();   //This sets the VFD into nibble mode and ready to send characters to the display.
		VacDisplayClear();
//		wifiRestore();



		SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
	       InitTAOS();

//ExposureTimeTAOS(1, 3);
		initRHTemp();
//Light Sensor testing   -  To be removied
Display_XYString(0,1,"Initialize: ");

	pwm_set_duty(DO_PWM,0);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0);	//250hz

xp=350;         //Starting PWM


while(1)
	{


selectsensor(0);  // This seclects the sensor to test.

gainof = GetCurrentColor(4, 3);
sysOutput.lLevelRed=red;
sysOutput.lLevelGreen=green;
sysOutput.lLevelBlue=blue;
sysOutput.lLevelClear=clear;
sysOutput.lLevelScale=gainof;

delay_ms(1000);
//		xp = SetPWMWithPhotoTransistor(xp, 200);

//		sprintf(uffit,"ADC %Lu  %Lu %f ",  GetADCValue(2), xp, ConvertTopH());
//		Display_XYString(0, 2, &uffit);

	}


//while(1)
//	{
//sysOutput.wTemp = ConvertADCToKalvin(5);
//	setTAOSGain(0,0, 3);


//PWMPHIntensity = FindMiddlePWMSensor(PWMPHIntensity, 2);

	
//MeasureWAGuyspH(26250);
//	sensorRead();

//	sprintf(uffit,"Gain %Lu Temp %f ",GetCurrentColorAVG(4, 1),sysOutput.wTemp);
//	Display_XYString(0, 2, &uffit);
//	sprintf(uffit,"ADC %Lu  ",  GetADCValue(2));
//	Display_XYString(0, 3, &uffit);

//	}




Display_XYString(0,1,"Loading");
xRST();
	//	wifiRestore();
Display_XYString(0,1,"Check Link");




		while (xReadyWiFi())
			{
			delay_ms(2);
			}
		delay_ms(10000);   //Delay time for WiFi to come up from zero power.  Added Nov. 23, 2014
	






//InitTAOS();  // Inint all of the light spectrum sensors  Added April 27, 2014





WFIsConfig=1;	//Check for wifi link, if linked then you're good
delay_ms(2000);
if(nLinkWiFi())
	{
	WFIsConfig=0;
	Display_XYString(0,1,"Initialize: ");
	}
else
	{
	Display_XYString(0,1,"Already Linked    ");
	}

		   enable_interrupts(INT_RDA3);
		   enable_interrupts(INT_RDA3);
		   enable_interrupts(GLOBAL);

		dataInit();
		initRHTemp();

		wifiInit();




	#if USESENSORS
		InitTAOS();  // Inint all of the light spectrum sensors  Added April 27, 2014
		SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
	#endif



/////////BEGIN INFINITE LOOP


while(1)
{
dataSplitter();



if(WFIsConfig==0)
//if(0==1)
{
WIFI_STA_CCONFIG(0);
}
else
{
char testcntrStr[5];
#if LCD_EN
sprintf(testcntrStr,"%5ld",testcntr);
Display_XYString(0,2,testcntrStr);
#endif

writeSSR();
//if(testcntr>5000000&&startText==0)

/*
///////CHANGE HERE!
if(testcntr>600)
{
WFIsConfig=0;
testcntr=0;
}
*/


if((clientOrServer==SERVER) && testcntr>(SENDINTERVAL-100))
{
setClient();
}


if(ISWWWPARSE && testcntr>100)
{
setServer();
resetParsing=1;
}


if(testcntr>SENDINTERVAL)
//if(1==0)
{



#if USESENSORS 

Display_XYString(0,1,"Reading sensors\n\r");
sensorRead();

#endif
{
testcntr=0;

//sysOutput.cO2=sysInput.chksum;
reloadTime();    // do it twice?
sysOutput.rH=sysOutput.rH+0.1;
printTime(sysOutput.year,sysOutput.month,sysOutput.day,sysOutput.hour,sysOutput.minute,sysOutput.second);


//this sends it out to the server.
Display_XYString(0,1,"Sending data to sever.\n\r");
sprintf(HTTPoutput,"Crab$%s$%s$%5f$%5f$%5f$%5f$%5f$%5f$%5f$%ld$%5f$%lu$%lu$%lu$%lu$%5f$%5f",sysOutput.deviceID,timeString,sysOutput.dOxy,sysOutput.wTemp,sysOutput.pH,sysOutput.wLevel,sysOutput.lLevelX,sysOutput.rH,sysOutput.aTemp,sysOutput.cO2,sysOutput.nH4,sysOutput.lLevelRed,sysOutput.lLevelGreen,sysOutput.lLevelBlue,sysOutput.lLevelClear,sysOutput.lLevelScale,sysOutput.dPoint);
unsigned int8 checksum = Calc_Crc8(HTTPoutput,strlenn(HTTPoutput));

//sprintf(HTTPwString,"GET /welcomeyou.php?name=%s&chksm=%u HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",HTTPoutput,checksum);
fprintf(WIFI,"GET /welcomeyou.php?name=%s&chksm=%u HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",HTTPoutput,checksum);


sysOutput.second=sysOutput.second+1;

//fprintf(WIFI,HTTPwString);
//Display_XYString(0,3,"Last Post At:");
//Display_XYString(0,3,timeString);
				}			
			}
		if(nLinkWiFi()==0)
			{
			testcntr++;	//Increment the counter if the device is connected to something	
			}
		}	
	}
}