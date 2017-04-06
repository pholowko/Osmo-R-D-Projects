                                                                                                                                                                                                                                                       #include "24FJ256GB106.h"
#define PIC24 1
#device PASS_STRINGS = IN_RAM
#DEVICE ICD=2
#device ADC=10
#use delay( crystal=8mhz, clock=32mhz )

#Pin_select OC1=PIN_D1 
#Pin_select OC2=PIN_C14


#define debugDisplay 0
#define BUFFERSIZE 600



#define USESENSORS 1

#define BTDEBUG 0
int1 wifisetup =0;



#include <float.h>
#include "HC-06.c"
#include "crc8.c"
#include <math.h>
#include "USR-WIFI232-X.c"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <stddef.h>
//#include "dataSpliter.c"



#USE PWM(OUTPUT=PIN_D1, FREQUENCY=250Hz, STREAM=PH_PWM)      //Pin 49
#USE PWM(OUTPUT=PIN_D2, FREQUENCY=250Hz, STREAM=DO_PWM)    //Pin 48


#if USESENSORS 
int1 sensorsRead=0;
//#use i2c(stream=light, MASTER, sda=PIN_G3, scl=PIN_G2, FORCE_HW, SLOW)    // SDA1
#use i2c(stream=PH_Light, MASTER, sda=PIN_F4, scl=PIN_F5, FORCE_HW, SLOW)    // SDA2
#use i2c(stream=DO_Light, MASTER, sda=PIN_E7, scl=PIN_E6, FORCE_HW, SLOW)    // SDA3 

#include "C:\Aquarium Software\OSMOBOT_PROTOTYPES\MCU_WEB_SERVER\VacDisplayRoutines.c"
#include "Instrumentation\humidity.c"
#include "Instrumentation\TaosLightSensor.c"
#include "Instrumentation\PWMandPIDvoltageControl.c"
#include "Instrumentation\ADCWaterLevelAndThermisters.c"

#use fast_io(c)



#endif


//#define MMCSD_PIN_SCL     PIN_F3 //o
//#define MMCSD_PIN_SDI     PIN_F6 //i
//#define MMCSD_PIN_SDO     PIN_F2 //o
//#define MMCSD_PIN_SELECT  PIN_B9 //o
#define MMCSD_PIN_POWER   PIN_G9 //o
#include "mmcsd.c"
#include "fat.c"



char HTTPwString[1000];
//char HTTPrString[BUFFERSIZE];
char HTTPoutput[BUFFERSIZE-100];
unsigned int8 newChksum=0;
int16 ttt;
int uio;





////////////////////////////////////////
//Data Structure Initialization
////////////////////////////////////////

typedef struct outputDataStruct{
char deviceID[16];
//volatile? 
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
/*
float lLevelRed;
float lLevelGreen;
float lLevelBlue;
float lLevelClear;
*/

int16 lLevelRed;
int16 lLevelGreen;
int16 lLevelBlue;
int16 lLevelClear;
int8 time;
int16 date;


float lLevelScale;
float rH;
float aTemp;
int16 cO2;
float nH4;
float dPoint;
char DIEHARD[8];
}outputData;

outputData sysOutput;
char timeString[28];


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

/////////////////////////////////////////
//End Data Structures
/////////////////////////////////////////



//////////////////////////////////////////
//Osmobot Hardware Initialization
//////////////////////////////////////////
void osmoInit(){

//while(1)
//	{
//	for (ttt=65500; ttt<65536; ttt++)
//		{
//		pwm_set_duty(PH_PWM,65536-ttt);	//250hz
//		pwm_set_duty(DO_PWM,65536-ttt);
  //      delay_us(50);
//		}
//
//	}



//Use PWM For LEDs



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
///////////////////////////////////
int16 gainof; 

unsigned int8 sensorRead()
{

#if USESENSORS

int32 resultit;   
int DOCommandit;   //Retuened value for DO PWM intensity  Added Sept 8, 2014
//This is the dummy result for the Do measurement.
//sysOutput.wTemp=ConvertADCToKalvin(3);
///*

//************************************************
//  Created April 24, 2014
// Set the correct varables to send to the DB.
   //PhsysOutput.rH=fRh_true;
sysOutput.aTemp=fTemp_true;
sysOutput.dPoint=fDew_point;


gainof = GetCurrentColor(4, 2);
sysOutput.lLevelRed=red;
sysOutput.lLevelGreen=green;
sysOutput.lLevelBlue=blue;
sysOutput.lLevelClear=clear;
sysOutput.lLevelScale=gainof;

/*
for (tt=0; tt < 20; tt++)
	{
	sysOutput.cO2 = ReadCOSensor();
	if (sysOutput.cO2 != 0xFFFF)
		{
		break;
		}
	}


sysOutput.dPoint=fDew_point;


//**********************************************
// Created May 1, 2014
// Read the DO and pH and do all calulcations.  The retuened value
// is the measurement
//**********************************************
resultit =  TakeLightReading(1, 0x2A);   // Take DO reading with middle of the sensor PWM LED value
//sysOutput.dOxy = FindMiddlePWMSensor(1, 1);   //Leave this in for calibration  Created May 21, 2014
//TakeADOReading(resultit);
sysOutput.dOxy = CalcaulateDO(resultit, 25.0);   //This calculates the DO from any reading after calibration
resultit =  TakeLightReading(2, 0x2A);    // Take pH reading with middle of the sensor PWM LED value
//sysOutput.pH = CalcaulatepH(resultit);   //Find the ph from the clibration tables
sysOutput.wLevel = MeasureWaterDepth();
sensorsRead=1;  */
#endif
return (1);
}

////////////////////////////////////////////
//End Sensor Read
////////////////////////////////////////////





void dataInit(void){

sysOutput.deviceID="Pauls_Board:WFP";

sysOutput.dOxy=12;
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
}








int16 strlenn(char stri[]){
int16 i=0;
while(stri[i]!='\0')
	{
	i++;
	}
return i;

}




void main(){


   enable_interrupts(INT_RDA);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
char c='a';
fprintf(WIFI,"test\n");
while(1){
//fprintf(WIFI,"%c\r\n",'a');
//WIFIBasicBroadcast();
WIFIBasicTest();
//fprintf(WIFI,"huh\r\n");
delay_ms(100);
//dataSplitter();
delay_ms(1000);
}

/*

int number=30;
char stingit[30];
float asif;
dataInit();
//osmoInit();
//wifiInit();
SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
VacDisplayinit();   //This sets the VFD into nibble mode and ready to send characters to the display.
VacDisplayClear();
//output_high(PIN_D1);
//output_high(PIN_D2);
output_high(PIN_C14);

char stuffit[40] = "Hello World";

   enable_interrupts(INT_RDA);
   enable_interrupts(INT_RDA3);
   enable_interrupts(GLOBAL);
//sprintf(HTTPoutput,"Crab$%s$%s$%5f$%5f$%5f$%5f$%5f$%5f$%5f$%ld$%5f$%lu$%lu$%lu$%lu$%5f$%5f",sysOutput.deviceID,timeString,sysOutput.dOxy,sysOutput.wTemp,sysOutput.pH,sysOutput.wLevel,sysOutput.lLevelX,sysOutput.rH,sysOutput.aTemp,sysOutput.cO2,sysOutput.nH4,sysOutput.lLevelRed,sysOutput.lLevelGreen,sysOutput.lLevelBlue,sysOutput.lLevelClear,sysOutput.lLevelScale,sysOutput.dPoint);


#if USESENSORS 
//	InitAllEEPROMVarblesAfterProgramming();

int16  ttt;
float typ;


   char buffer[255];
   char opt_buffer[255];
   char *cmd, *option1 =  "524288";
char *option2;
   
   int i;   // pointer to the buffer

	pwm_set_duty(DO_PWM,0x7FFF);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0xFFFF);	//250hz



output_high(MMCSD_PIN_POWER);
delay_ms(200);
output_low(MMCSD_PIN_SELECT);
delay_ms(200);
   // initialize the FAT
   //  keep in mind that this will automagically initialize the media
while(1)
	{
//	MMCSD_SPI_XFER(0xaa);

//   FormatMedia(option1);
//	delay_ms(20);
	}
 //  i = fat_init();
//   if (i)
  //    printf("\r\n\nERROR INITIALIZING FAT\r\n\n");



InitTAOS();  // Inint all of the light spectrum sensors  Added April 27, 2014
SetupADC();   //Added May 1, 2014  Setup up the ADC
//    SetupPWM();   // Setup the PWm for DO and pH meters
//	InitCO2();    // Init the CO2 lines



//fprintf(BT,"Bluetooth On\r\n");
	delay_us(100);
sysOutput.wTemp = ConvertADCToKalvin(5);
	delay_us(100);
asif = MeasureWaterDepth();
//WIFI_AT_Help();

//wifiRestore();
//////////////////////////////
/*
int16 testercntr=0;

if(wifisetup==0)
{
while (bkbhit){
char c=getWIFIChar();
putc(c,BT);

}


if(testercntr==2000)
{
WIFI_enter_setup();
}


if(testercntr==25000)
{
WIFI_ap_scan();
}

if(testercntr==50000)
{
WIFI_reset();
}

testercntr++;
}

/////////////////////////////////




*/


/*


while(1)
	{
for (ttt=0x0100; ttt < 0x7FFF; ttt+=0x0001)
	{
	pwm_set_duty(DO_PWM,ttt);  //250hz
	delay_us(100);
    ttt++;
    ttt--;
	}
}

*/



/*
while(1)
	{
//while(1)
//	{

//	sprintf(stingit, "Water Level %f",MeasureWaterDepth());
//	Display_XYString(2, 2, stingit);
//	}
	uio = FindMiddlePWMSensor(1, 2);   //Set for DO  and Do Channe

	delay_ms(1);
	}

//ReadColorTAOS(4);  //blue

#endif


unsigned int32 testcntr=0;
//unsigned int16 testcntr2=0;
while(1){
testcntr++;


///*

//WIFIBasicTest();
//WIFIBasicBroadcast();
BTBasicTest();

if(input(PIN_B8)==0)
{
pwm_set_duty(PH_PWM,9100);	//250hz
}
else
{
pwm_set_duty(PH_PWM,20000);	//250hz
}


/*










//resultit =  TakeLightReading(2, 0x2A);   //



writeSSR();


//if((testcntr>5000000)&&startText==0)

if(testcntr>5000000&&startText==0)



//*/
/*

#if USESENSORS 

sensorRead();
if(sensorsRead==1)
#else
if(1==1)
#endif


{
testcntr=0;

//sysOutput.cO2=sysInput.chksum;
reloadTime();
sysOutput.rH=sysOutput.rH+0.1;
printTime(sysOutput.year,sysOutput.month,sysOutput.day,sysOutput.hour,sysOutput.minute,sysOutput.second);
//pwm_set_duty(PH_PWM,9100);	//250hz
sprintf(HTTPoutput,"Crab$%s$%s$%5f$%5f$%5f$%5f$%5f$%5f$%5f$%ld$%5f$%lu$%lu$%lu$%lu$%5f$%5f",sysOutput.deviceID,timeString,sysOutput.dOxy,sysOutput.wTemp,sysOutput.pH,sysOutput.wLevel,sysOutput.lLevelX,sysOutput.rH,sysOutput.aTemp,sysOutput.cO2,sysOutput.nH4,sysOutput.lLevelRed,sysOutput.lLevelGreen,sysOutput.lLevelBlue,sysOutput.lLevelClear,sysOutput.lLevelScale,sysOutput.dPoint);
unsigned int8 checksum = Calc_Crc8(HTTPoutput,strlenn(HTTPoutput));

sprintf(HTTPwString,"GET /welcomeyou.php?name=%s&chksm=%u HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",HTTPoutput,checksum);
sysOutput.second=sysOutput.second+1;

fprintf(WIFI,HTTPwString);
//pwm_set_duty(PH_PWM,15000);	//250hz
#if USESENSORS 
sensorsRead=0;
#endif 


				
			}

			
		}	
*/	
	}	

//}