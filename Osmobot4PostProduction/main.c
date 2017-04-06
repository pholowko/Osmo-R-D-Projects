// Osmobot Main.c file
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
#define RAND_MAX 65536



//***************************************************************
// Created May 21, 2015
// These two flags set the unit into pH calibrtation of DO calibration.  The unit will not 
// connect to the server or do anything else.
//  Make sure these are set to zero when shipping the unit
//***************************************************************

#define TIRHTEMP 1   // This tells the compiler to use the routines for the Ti RH and temp chip
#define WHITELED 1    //  A zero means there is an LED on the output.  A 1 means the white LED is used.
#define BTD 0   // This is used for testing the BT connections and is removed when completed.  Added July 8, 2015
#define DOin 1   // A one will put in the DO routines.
#define WifiSetupit 1   //  1 means sets up wifi,  0 means not.  This allows the Wifi chip to setup or it goes direcly into uploading to the server.  It's used for debugging the uploading.
//*Where is the test all sensors program? It's important for QC. It was called testRH
int toggleechoonoff = 0;   // Added July 14, 2015  This is the varaible where it sends text to the bluetooth from the LCD.  The "echo" command changes its state.

int16 testcntr=0;
#define TESTER
#define USESENSORS 1
//#define TIRHTEMP 0   // this means no old DHM22 sensosr
#define EEPROMCONFIG       // This tells the compiler to use the new EEPROM instead of the SD CARD
#define OSMOBOT 1    // this sets the parameters to compile all shared routines for calling by Osmobot
#define BTDEBUG 0
int1 wifisetup = 0;


#define SENDINTERVAL 3200
#define IS_LEAP(year) (year%4 == 0) 

#HEXCOMMENT Version 5.0.0  January 17, 2017
int8 const version[50] = "Version 5.0.0  January 17, 2017";
int th,tl,hh,hl;

int1 ROUTERHOLD=0;
int1 ROUTERUPDATE=0;
int  CURRENTCONNECTIONTOSERVER = 0;
int RUNTIMERCLOCK = 0;  // This is used to stop and start download timer.  It's used to stop things for setting up the WiFI and the bluetooth module.
int ACKFROMSERVER = 0;  //Added May 8, 2015   This flag is used to signal to remove the last file uploaded to the server.
int savetrigger = 0;  // this is the flag to save the CONFIG.TXT to the SD Card.
int blocklocation = 0;  // this is the global number used to get the next block from the server for FW updating.  For now it starts at zero and goes up.
int CapturedWebStringFlag = 0; // this is used to tell the system to check for another string until the one in the holding buffer is complete.


int1 ISWWWPARSE=0;
#define CHEAPEC 1
#define CHEAPRHTEMP 1
#define CLIENT 0
#define SERVER 1
#define ATCOMMAND 2  //This means the module is not in either server mode or client , but in command mode.  It needs to be set to something after it's out.
#define WEBTEXTLENGTH 1500     // This is used to make the length of the webpage input text buffer.
#define RHTEMP PIN_D0      //  this is the pin used for talking to the RH and Temp sensor


int8 clientOrServer=ATCOMMAND;   // 0 for client, 1 for server, 2 for AT command


char requestURLBuff[255];
char WebPageTxtBuff[WEBTEXTLENGTH];
char uffit[200];
rtc_time_t write_clock, read_clock;


int1 ATisOK=0;
int1 WFIsConfig=0;
int1 USEAT=0;
int1 resetParsing=0;
int16 webmarshallerpointer = 0;  // This is used to point to the last location in the WebpageTetBuff.  Added Augest 12, 2015
int APSTAmode;
int SDCardResults;
float lastoxyreading;
int InBTCommandmode = 0;

typedef struct BTScanningStruct{
char rserialnumber[30];   //this is the serical number for one of the BT deivces that connects to the Osmo
char rname[15];   // This is the RNAME for each of the BTs
} BTList;     
BTList BTScanningList[15];    //This is the array where the data is saved.
int MaxBTScanningNumber = 0;   //This is the variable that is the max number of BT device this device needs to scan.
char adcBuff[40];   // this is the scratch array used for displaying items on the  VFD


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
float pHLow;
float WhiteBalance;
float tdsLevel;
float wLevel;
float lLevelX;
float lLevelY;

int32 lLevelRed;
int32 lLevelGreen;
int32 lLevelBlue;
int32 lLevelClear;
int8 time;
int16 date;


float lLevelScale;
float rH,averagepH;
float aTemp;
int16 cO2;
float nh3;
float dPoint;
char DIEHARD[8];
}outputData;
outputData sysOutput;


char timeString[28];
int16 xp;

#include "C:\Aquarium Software\Debug Monitor\CommonPassedDataFromMaterToSlave.h"



#include <unicode.h>
#include <float.h>
#include "string.h"
#include "crc8.c"
#include <math.h>

#include "stdlib.h"
#include "stdio.h"
#include <stddef.h>


#include "defs.h"    ///Added July 22, 2015.  THis is an attepmt to untangle the defs over the whole project.

#include "VacDisplayRoutines.c"
#include <routerParse.h>
#include "wwwParser.c"
#include "osmoWebServer.c"
#include <Stringsplitter.h>

#define ALLOW_GET_DISK_PROPERTIES q  //used by 'info' command

#USE PWM(OUTPUT=PIN_D1, FREQUENCY=2000Hz, STREAM=PH_PWM)      //Pin 49



//#use i2c(stream=DO_LIGHT, MASTER, sda=PIN_F4, scl=PIN_F5, FORCE_HW, SLOW)    // SDA2
#use i2c(stream=PH_LIGHT, MASTER, sda=PIN_E7, scl=PIN_E6, FORCE_HW, SLOW)    // SDA3 
#use i2c(stream=ROOM_LIGHT, MASTER, sda=PIN_G3, scl=PIN_G2, FORCE_HW, SLOW)    // SDA1
#include "OsmobotSDCard\encription.c"   
#include "Instrumentation\TaosLightSensor.h"
#include "DORoutines.c"
#include "sdcard\ex_mdd_common.h"
#include "OsmobotSDCard\SDCardRoutines.c"
#include "HC-06.c"
#include "HC-05.c"
#include "HC-12.c"
#include "USR-WIFI232-X.c"
#include "Stringsplitter.c"
#include "Instrumentation\humidity.c"

#include "C:\Aquarium Software\Debug Monitor\MasterReadWriteTeRemoteDevice.c"

#include "Instrumentation\TaosLightSensor.c"
#include "Instrumentation\CheapRHAndTemp.c"
#include "Instrumentation\ADCWaterLevelAndThermisters.c"
#include "testingandCalibrationPrograms.c"
#include "SensorAndMultiplexor.c"  // Added December 2, 2015 for the new board.  
#include "EyeSquareSee.c"   // Added March 17, 2016 for designing out the SD Card and putting in a I2C EEPROM.
#include "eepromRoutines.c"   //  Added March 23, 2016   These are the routines to dave configurations and data to the EEPROM
#include "Instrumentation\ECcalculation.c"    // Created Added July 18, 2016  This calculates the EC value using regression

//#include "rtc.c"   // this is removed because it's a software clock and interferiers with the SD Card
#use fast_io(c)



//#define MMCSD_PIN_SCL     PIN_F3 //o
//#define MMCSD_PIN_SDI     PIN_F6 //i
//#define MMCSD_PIN_SDO     PIN_F2 //o
//#define MMCSD_PIN_SELECT  PIN_B9 //o
#define MMCSD_PIN_POWER   PIN_G9 //o


//////////////////////////////////////////
//Osmobot Hardware Initialization
//////////////////////////////////////////
//void osmoInit()




/////////////////////////////////
//NOTES:
//ON R1 of osmobot board DO LED is not hooked up to a PWM capable (RP) pin
//it is instead on an RPI pin and cannot use the PWM module
/////////////////////////////////



//////////////////////////////////
//SSR ROUTINE
//////////////////////////////////

void writeSSR()
{
//////CHANGE THESE PINS TO SSR PINS
output_bit(PIN_F5,sysInput.io1);   // Added June 29, 2016
output_bit(PIN_D2,sysInput.io2);    // Added June 29, 2016
//output_bit(PIN_F7,sysInput.io3);   // Added June 29, 2016  Not used yet

}


//*****************************************************************************
// Created November 30, 2016
//  this is the seperated routine for PAR.  It's used for averaging and setting the TSC3414 chip to max limits.
// Returns nothing.
//*****************************************************************************
void findPAR(void)
{
    
// ********************************************************************************
// Created Nov. 3, 2014
// Updated and Changed Nov. 10, 2015
// An auto scaling routine is added to scale the output.  The exposuer time is also set to 100ms from 12ms.
// This routines find the current ambnt light spectrum and uploads it to the server.
// ********************************************************************************
//	ExposureTimeTAOS(0,5);   //Set this exposure time to 12ms to help with max out gains.  Changed April 7, 2014
 //   ExposureTimeTAOS(2,5);   //Set this exposure time to 400ms to help with max out gains.  Changed October 29, 2016
    //  this is changed because of HID lights turning on and off quickly where the exposure time is too short to capture a on state.
int32 redavg,blueavg,greenavg,clearavg,circlethrough,counting;   // these are the temp averages for the PAR light
float gainof;
//	ExposurescaleLight=0;

circlethrough=32;   // the number of samples
redavg=0;   // clear all
greenavg=0;
blueavg=0;
clearavg=0;
counting = circlethrough;
while(counting--)
    {  
       gainof = GetCurrentColor(0, 5);   //This get the current reading off the harnis.  Set the first item to 4 so it is auto gain for reading
        redavg=redavg+redABS;   // clear all
        greenavg=greenavg+greenABS;
        blueavg=blueavg+blueABS;
        clearavg=clearavg+clearABS;
        
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
}
redavg=redavg/circlethrough;
greenavg=greenavg/circlethrough;
blueavg=blueavg/circlethrough;
clearavg=clearavg/circlethrough;

sysOutput.lLevelRed= redavg;
sysOutput.lLevelGreen= greenavg;
sysOutput.lLevelBlue=blueavg;
sysOutput.lLevelClear= clearavg;
/*
sysOutput.lLevelRed= redABS;
sysOutput.lLevelGreen= greenABS;
sysOutput.lLevelBlue=blueABS;
sysOutput.lLevelClear= clearABS;
 */
 //   BTBasicTest();   //Check BT 
//	BTBasicTest();   //Check BT 
//	BTBasicTest();   //Check BT 
//	BTBasicTest();   //Check BT 
//	BTBasicTest();   //Check BT 
//	BTBasicTest();   //Check BT 
	fprintf(BT, "Current Red   -> %lx\n\r",sysOutput.lLevelRed);
	fprintf(BT, "Current Green -> %lx\n\r",sysOutput.lLevelGreen);
	fprintf(BT, "Current Blue  -> %lx\n\r",sysOutput.lLevelBlue);
	fprintf(BT, "Current Clear -> %lx\n\r",sysOutput.lLevelClear);
	fprintf(BT, "Current ND    -> %lx\n\r\n\r",gainof);
 
sysOutput.lLevelScale=(float) gainof;

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
float returnedresultit,titemp;
    int returnedresult;
     InitTAOS();  // Inint all of the light spectrum sensors  Added April 27, 2014  Added Sept 30, 2016  Inits all spectrims chips so people can plug and unplug at will
    LEDmessage(0x00);


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
//sysOutput.wTemp = ConvertADCToKalvin(5);   //This is the old version that does not have filtering for turbulent waters.  Removed June 26, 2015
sysOutput.wTemp = WaterTemperature();

// *********************************************************************************
// Created Nov 2.  2014
// Find the RH and Temperature for the environment and send it to the server.
//  This routine talks with the cheap RH and Temperature sensor
// ********************************************************************************
/*   Removed on Jan 16, 2017
if (!GetTempRH())
	{
	sysOutput.aTemp = Temperature;  //This is the float temperature

	if (sysOutput.aTemp < 0.0)
		sysOutput.aTemp = 0.0;
		
	sysOutput.rH = RHData;  //This is a float send into ta RH value.
	if (sysOutput.rH < 0.0)
		sysOutput.rH = 0.0;
	}
*/
//*********************************************************************************
// Created Jan 17, 2017
// This calls and saves the current air temp and rh
//*********************************************************************************
 returnedresultit = GetHDC1080RHTemp(8);
   returnedresult = th;
   returnedresult = tl;
   titemp = (float) (th << 8 | tl);    
    titemp = titemp * 165.0 / 65536.0 - 40.0;
 sysOutput.aTemp = titemp;
  	if (sysOutput.aTemp < 0.0)
		sysOutput.aTemp = 0.0;
 
    returnedresult = hh;
   returnedresult = hl;
   titemp = (float) (th << 8 | tl);    
   titemp = titemp * 100.0 / 65536.0;
	sysOutput.rH = titemp;  //This is a float send into ta RH value.
	if (sysOutput.rH < 0.0)
		sysOutput.rH = 0.0;



// ********************************************************************************
// Created Nov. 3, 2014
// This routines borrows the calcaulaton from the expensive SHt11 chip to calcaulate DP
// ********************************************************************************

sysOutput.dPoint=sht1x_calc_dewpoint(sysOutput.rH,sysOutput.aTemp);


//if ((sysInput.unittype[0] == 'H') && (sysInput.unittype[0] == 'D'))
 //     {
    //***********************************************************
    // Created June 2, 2016
    // This routine samples the ph-bulb and puts the raw data as a float. 
    //  It sends it to the server as is,  there is no data scaling.  It takes 10 raw readings.
    //***********************************************************
  //  fprintf(BT,"Reading pH Bulb\r\n");
 //   restart_wdt();   // restart the WD timer.  It set for 65 seconds
 //   sysOutput.pHLow = ConvertADCTophBulb();
  //    }    


findPAR();   // measure PAR and update varaibles.
 
/*

if ((sysInput.unittype[0] == 'A') && (sysInput.unittype[0] == 'P'))
{
//**********************************************************************
//  This is the begging loop for the DO.  It stays in this loop until a values comes out that is similar to that one previouse.
exit=1;
averageDOreading = 0.0;   //Set to zero.
do
{
restart_wdt();   // restart the WD timer.  It set for 65 seconds
	pwm_set_duty(PH_PWM,0);	//250hz
        delay_ms(200);
FindAmbientLight(1);   // get dark light reading for BLUE

sysOutput.dOxy = TakeLightReading(8, PWMDOIntensity,BlueLimit);

	if (sysOutput.dOxy < 0.0)
		sysOutput.dOxy = 0.0;

if (lastoxyreading < 0)    // this is for the first time through to set the limit
    lastoxyreading = sysOutput.dOxy;   // save the last value


difference = abs(lastoxyreading - sysOutput.dOxy);
if (difference < 1.75)   // If the difference is greater than 0.75 of  a point, the do the measurement again.  This needs to be changed to a larger value when the upload time is set to 15 minutes.
{
        lastoxyreading = sysOutput.dOxy;   // save the last value
        exit=0;    
}
	pwm_set_duty(PH_PWM,0);	//250hz
    trying++;
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    averagenumber = (float) trying;   // change over the counter from an in to a float.
    averageDOreading = averageDOreading + sysOutput.dOxy;
    averagenumber = averageDOreading / averagenumber;   //Set the output to the average.
    fprintf(BT,"Current Reading DO %f   Previous Reading DO %f  exit value %i  AmbientOxyBlue=%Ld  blueABS=%Ld  Loop count %i   Current DO average ->  %f\r\n",sysOutput.dOxy,lastoxyreading,exit, AmbientOxyBlue,blueABS,trying,averagenumber);
    
    
    if (trying == 5)
        {
        averagenumber = (float) trying;   // change over the counter from an in to a float.
        sysOutput.dOxy = averageDOreading / averagenumber;   //Set the output to the average.
        lastoxyreading = sysOutput.dOxy;   // save the last value
        exit = 0;   // leave the loop if there are five numbers in the average.
        }
    }
while(exit==1);   //this releases the loop to 
}

*/


/*
	sysOutput.nh3 = ReadNH3AVG();  // call the pH reading averaging routine

    
    	if (sysOutput.nh3 < 0.0)
		sysOutput.nh3 = 0.0;

*/
//sysOutput.pH = averagepH/10.0;
//	pwm_set_duty(DO_PWM,0);	//250hz  Turn off light for DO
//	pwm_set_duty(PH_PWM,0);	//250hz
    
    //************************************************************
    // Created/Added March 28, 2016
    // EC measurement is added to the data uploading
    //************************************************************
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    sysOutput.tdsLevel = measureTDS();     // Get the TDS and send it up to the server.  Added March 28, 2016
    
    //sysOutput.tdsLevel = findec(float inputreading)

    

restoreLEDmessage();


return (1);
}

////////////////////////////////////////////
//End Sensor Read
////////////////////////////////////////////


//***********************************************************************
// Created Oct 5, 2016
//  This routine does another set of measurements for instruments sensitive to ECmeasurements because of electrical ion discharge.
//  This returns a 1
//  It only measure pH so far.  It is triggered by a timing measurement from the main loop.
//***********************************************************************
unsigned int8 sensorRead2(void)
{

//if ((sysInput.unittype[0] == 'H') && (sysInput.unittype[0] == 'D'))
 //     {
    //***********************************************************
    // Created June 2, 2016
    // This routine samples the ph-bulb and puts the raw data as a float. 
    //  It sends it to the server as is,  there is no data scaling.  It takes 10 raw readings.
    //***********************************************************
    fprintf(BT,"Reading pH Bulb\r\n");
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    sysOutput.pHLow = ConvertADCTophBulb();
  //    }    

restoreLEDmessage();


return (1);
}





void dataInit(void){

sysOutput.tdsLevel=100.0;
sysOutput.WhiteBalance=10000;
sysOutput.pHLow=4.0;
sysOutput.dOxy=.20;
//sysOutput.time=0;
sysOutput.nh3=200;
sysOutput.rH=9001;
sysOutput.lLevelX=20;

}



void printTime( unsigned int16 Year, unsigned int8 Month, unsigned int8 Day, unsigned int8 Hour, unsigned int8 Minute, unsigned int8 Second)
{
//sprintf(timeString,"%4lu-%2u-%2u$%2u:%2u:%2u",Year,Month,Day,Hour,Minute,Second);
sprintf(timeString,"%02u:%02u:%02u$%04lu-%02u-%02u",Hour,Minute,Second,Year,Month,Day,);
}




void reloadTime(void){

write_clock.tm_year = sysInput.year;
write_clock.tm_mon = sysInput.month;
write_clock.tm_mday =sysInput.day;
write_clock.tm_hour =sysInput.hour;
write_clock.tm_min =sysInput.minute;
write_clock.tm_sec = sysInput.second;

sysOutput.year=sysInput.year;
sysOutput.month=sysInput.month;
sysOutput.day=sysInput.day;
sysOutput.hour=sysInput.hour;
sysOutput.minute=sysInput.minute;
sysOutput.second=sysInput.second;

   rtc_write(&write_clock);         //writes new clock setting to RTCC

}




void main()
{

	int stuff, ScaleLevel,lastsecond,lastestversion;
    int8 stuffit;
    int returnedresult,xx,returnserialnumber;
    char string1[11] = "PaulsBoard";
    char string2[16];   // this is the test string for serialnumber
    int stiffcounter = 0;  // this var is used to count the number of times there is a router connection but not data connection.  It resets after 10 times.
	int firstimethrough =  1;   // this varaible is used to prevent measurements if the clock is not set or it the first time through.
    unsigned int32 junkoutput;
	float ClearTemp,ScaleLevelfloat,returnedresultit,titemp;
 //   char Configuration[256],charout;   /// This is used by the I2C EEPROM for testing.
 //   char Configreturn[256];   /// This is used by the I2C EEPROM for testing.
    char charout;
   TurnOffBT();  // turn off the BT to make sure the right setup is done.

   lastestversion = 0;
   

   
 //  output_high(PIN_F4);    // These are SSR that needs to be turned off as soon as power is applied.   Added June 29, 2015
 //  output_high(PIN_F5);    // These are SSR that needs to be turned off as soon as power is applied.   Added June 29, 2015
   output_low(PIN_D2);    // These are SSR that needs to be turned off as soon as power is applied.   Added June 29, 2015
   output_low(PIN_F5);    // These are SSR that needs to be turned off as soon as power is applied.   Added June 29, 2015
//   }
   
   intimultiplex();  // init the sensor multiplexor  This is for the new board.  Added Dec. 2, 2015

LEDinit();  // init the leds and resets.  Do a lamp test on Fault LED.
    
orLEDmessage(0x07);  // this turns on all of the lights.  When all of them are off, that means everything is working.
clearRouters(routerTable);	//Ensures router table is empty
lastoxyreading = -1.0;   // set the first oxy level to this value to trigger setting to the first real value.  Added March 23, 2016
//Testing routine to be removed.



setup_rtc(RTC_ENABLE,0);         //enables internal RTCC

int changefolder;  //This shows the results from changing a folder in the SD Card.


//Initialize_RTC();    // Added Oct 15, 2015  This inits the software RTC clock for triggering downloads to the server.
enableWIFIModule();



setup_wdt(WDT_65S);    // This sets the WD timer length before reset.  Added Jan 4, 2016.

PWMPHIntensity = 0x0200;  //starting guess
xRST();    //Call resetting the WIFI to get it going on timing.
//	pwm_set_duty(DO_PWM,0);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0);	//250hz
	PWMDOIntensity=0x600;   //This is the global values for the last PWM for the DO.  It's reused to get quickly there.  Added June 23, 2015

 
        delay_ms(10000);

        ReadConfigEEPROM();
        ReadCalEEPROM();   // Added May 7, 2016   This reads all of the eeprom.  If it's not inited, it will set default data.
       // ReadunittypeEEPROM();  // Added Aug 11, 2016  This gets the unit type and prevents certain instrumneation from measuring to save on power, time and my nerves.

setupBT(); // Added July 14. 2015  This changes the Bluetooth.  This sets up the BT and turns it on for operation.

InitTAOS();  // Inint all of the light spectrum sensors  Added April 27, 2014
SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
//initRHTemp();


		SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors

//setupbluetooth();   // Set up the bluetooth for talking with other units or itself.

	    InitTAOS();

	//	initRHTemp();


//*********************************************************************
// Created Nov. 9, 2015
// This section is used to kick out all of the Wifi stuff and only to BT commands.  Must use rst to get out of it.
//  A flag is set to kick it in this routine.
//*********************************************************************

	if (btonly == 1)
			{
			while(1)
				{
                restart_wdt();   // restart the WD timer.  It set for 65 seconds
				BTBasicTest();
				calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
				}
			}	



xp=350;         //Starting PWM


SetupRSBufferPointers();   //Set up the circulre RS232 buffer pointers.
	//	wifiRestore();
sysInput.hour=30;    //Set the hours to 30 where the server will bump the first non-date and time entry into the DB.
Display_XYString(0,1,"Setting WiFi Module");


		wifiInit();   //This needs to reset the module where it is always at a point we can know.

		while (xReadyWiFi())
			{
//			delay_ms(2);
            restart_wdt();   // restart the WD timer.  It set for 65 seconds
			BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
			calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

			}

delay_ms(1000);

/*
//************************************************************
// Created May 7, 2015
// In all cases, it's needed to find if the current settings will connect to the server.
//  This is only done when the WiFi is in STA modes.  It is not prdicitable to assume the until will be in STA mode.
// Before doing anything, set the WiFi mode and reset before testing any condition and knowing where anything is at.
//***************************************************************************
if (setClient())
	{
	VacDisplayClear();
	Display_XYString(0,1,"Client Failed");
	delay_ms(5000);
	}

//******************************************************
// Created May 6, 2015
// This routine checks to see if the WiFi is connected to the website and/or the router.
//  A 0 is returned if it is not connected.
// This routine can be used for checking the connection before sending something to the server.
//******************************************************

		while (xReadyWiFi())
			{
			delay_ms(2);
			BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
			calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

			}
*/
SDCardResults = ServerUp();
if (SDCardResults == 1)
{
delay_ms(3000);   //The unit is reset again with a hardware reset.  This is the time the WiFi is connecting to the server.

	WIFI_STA_CCONFIG(0);    // This is calling the setup routine.  Do not use it elsewhere.

delay_ms(5000);   //The unit is reset again with a hardware reset.  This is the time the WiFi is connecting to the server.


BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

delay_ms(15000);   //The unit is reset again with a hardware reset.  This is the time the WiFi is connecting to the server.

SDCardResults = ServerUp();
}
   else
    {
    	LEDmessage(0x02);   // set this LED on.
    }

//if (APSTAmode)
if (SDCardResults)
	{
	//  This means Osomobot can no connection to the server.  Something wrong with the configureations.
	//  Place it in AP mode to it can service the configurations.
	fprintf(BT,"Not connected to Server and proceeding to wait for correct Router connection information.\r\n");
	setServer();
	SDCardResults=3;   // This means it is not connected to the server.
	LEDmessage(0x01);   // This means it's in only AP mode and the phone is used to connect for changing the connection configurations.

	}
	else
	{
	fprintf(BT,"Connected to Server and proceeding to collect data\r\n");
	firstimethrough = 0;   // this sets the flag to start collecting data.
	SDCardResults = ConnectedToInternet();   // if it is in AS+SPA mode, then check for connection.  Continue normally.
  	LEDmessage(0x00);   // This means it's in STA mode and is connected to the sever for real
	}
 


WFIsConfig=1;	//Check for wifi link, if linked then you're good
//delay_ms(7000);   //The unit is reset again with a hardware reset.

/*
if(SDCardResults==3)    //This is a hardware pin that is checked to see if the unit is automaticly connected to the router.
	{
	WIFI_STA_CCONFIG(0);    // This is calling the setup routine.  Do not use it elsewhere.
	SDCardResults = ConnectedToInternet();
	}
*/
if(SDCardResults==3)    //This is a hardware pin that is checked to see if the unit is automaticly connected to the router.
	{
//	WIFI_STA_CCONFIG(0);    // This is calling the setup routine.  Do not use it elsewhere.
	WFIsConfig=0;
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
//	Display_XYString(0,1,"Initialize: ");
	ROUTERUPDATE=0;    //Added April 24, 2015  Update the flags to trigger into getting the local router list and go into server mode.
	ROUTERHOLD=1;      //Added April 24, 2015  Update the flags to trigger into getting the local router list and go into server mode.
	CURRENTCONNECTIONTOSERVER = 0;
	RUNTIMERCLOCK=0;    // Stop the autotimer from running to setup the Wifi and Bluetooth.
	}


if (SDCardResults==0)
	{
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
	WFIsConfig=1;
	Display_XYString(0,1,"Already Linked    ");
	ROUTERHOLD=0;
	clientOrServer=CLIENT;
	CURRENTCONNECTIONTOSERVER = 1;
	RUNTIMERCLOCK = 1;   // Run the timer because there is a connection to the outside when the unit is started up.
	}


//	WFIsConfig=0;   //This is added to trigger a manditory setup.  This needs to be removed for normal operation.  Added April 29, 2015
//	ROUTERUPDATE=0;    //Added April 24, 2015  Update the flags to trigger into getting the local router list and go into server mode.
//	ROUTERHOLD=1;      //Added April 24, 2015  Update the flags to trigger into getting the local router list and go into server mode.
	
		dataInit();
//		initRHTemp();


	#if USESENSORS
		InitTAOS();  // Inint all of the light spectrum sensors  Added April 27, 2014
		SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
	#endif

cleanWebPageTxtBuff();   // Clean all data out of the array to prevent old data from an ubrupt power loss.
/////////BEGIN INFINITE LOOP





while(1)
{


restart_wdt();   // restart the WD timer.  It set for 65 seconds

//*********************************************************************
// Created Nov. 9, 2015
// This section is used to kick out all of the Wifi stuff and only to BT commands.  Must use rst to get out of it.
//  A flag is set to kick it in this routine.
//*********************************************************************

	if (btonly == 1)
			{
			while(1)
				{
				BTBasicTest();
				calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
				}
			}	



BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

if ((!CapturedWebStringFlag) && (!BTMeasureTimer))
	{
	CapturedWebStringFlag = webmarshaller();
	}	


//*****************************************************
// Created Aug 15, 2015
// This section takes the data from the capture device and processes it.
//  this has been changed over into a case statement to handle all sorts of events for the web pages.
//  The case numbers goes as follows:
//  0  :  no operation
//  1  :  This means there is a response from the server
//  2  :   This means something needs to be done for the local iphone webpages.
//
//  Note:  Before something can be sent back, it needs to have a valid open connection.
//*****************************************************


switch(CapturedWebStringFlag)
	{
	case 0:
		    break;
	case 1:
			StoreACKdatafromserver();     // Parse the returned data and set the ACK flag.
			CapturedWebStringFlag = 0;  // clear the flag fo rthe next set of data.
			cleanWebPageTxtBuff();   // Clear out the buffer to let the next input come in.
			webmarshallerpointer = 0;
			break;
	case 2:
			webhandle();
			CapturedWebStringFlag = 0;  // clear the flag fo rthe next set of data.
			cleanWebPageTxtBuff();   // Clear out the buffer to let the next input come in.
			webmarshallerpointer = 0;

			if (savetrigger)
				{
				fprintf(BT,"Saving Configurations to EEPROM\r\n");
                SaveConfigEE();     
                savetrigger = 0;  // Clear flag
				fprintf(BT,"Saving Completed\r\n");
				reset_cpu();  //This reboots the CPU and does a reconnection.  
				}
		    break;
    case 5:  
            returnserialnumber =  ParseNewSerialNumberfromserver();   // get the new serial number from the returned server data.
            CapturedWebStringFlag = 0;  // clear the flag fo rthe next set of data.
 			cleanWebPageTxtBuff();   // Clear out the buffer to let the next input come in.
			webmarshallerpointer = 0;       
                       
            if (!returnserialnumber)
                {
                SaveConfigEE();   // save the serialnumber to the EEPROM
                reset_cpu();   // resets the unit from a CPU reboot.
                }
        break;
        
    case 6:
            returnserialnumber =  ParseNewFirmWarefromserver();    // get the returned information and see what is there.
            CapturedWebStringFlag = 0;  // clear the flag fo rthe next set of data.
            cleanWebPageTxtBuff();   // Clear out the buffer to let the next input come in.
			webmarshallerpointer = 0;
            
                if (!returnserialnumber)
                {
                writeFWline();   // save the FW line to the EEPROM
              //  reset_cpu();   // resets the unit from a CPU reboot.
                }
            
        break;
        
	default:
		 	break;
	}

//   fprintf(BT,"%s %s %s %s\r\n",STA_SSID,STA_AUTH,STA_ENC,STA_PW);
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.


     rtc_read(&read_clock);        //reads clock value from RTCC

char testcntrStr[5];
sprintf(testcntrStr,"%5ld  time -> %i:%i,%i    RTCC %i:%i,%i",testcntr,sysOutput.hour,sysOutput.minute,sysOutput.second,read_clock.tm_hour,read_clock.tm_min,read_clock.tm_sec);
Display_XYString(0,2,testcntrStr);

writeSSR();   //  This is open on June 29, 2016 

if((testcntr==(SENDINTERVAL-598) && (SDCardResults == 0)) && (!BTMeasureTimer))
	{
//	setClient();  //If there a connection established, then go into Clent mode and send data.  If there is no connection to the internet, then go into server mode.
	testcntr++;
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
	}					



if((ISWWWPARSE && testcntr>100) && (!BTMeasureTimer))
	{
//	setServer();
	resetParsing=1;
	}





//********************************************************************************************************************************
// Created October 15, 2015
//  This sections of code triggers a measurement of sensors and prints it off to the BT.  It then resets everything back to the orginal numbers and counts down again.
//  This operation is commanded from "autodump"  
//  the paramater after "autodump is the number in minutes to wait for each dump to the screen.  THe auto wigi upload is disabled.
//********************************************************************************************************************************
if (BTMeasureTimer != 0)
	{
	if ((BTMeasureTimer <= Minutes) && (Seconds > 0))
		{
					sensorRead();
					stuff = (int) sysOutput.lLevelScale;
						if (stuff == 3)
   							  {
   							  ScaleLevel =  1;
     						  }
						if (stuff == 2)
 						    {
  						    ScaleLevel =  4;
  						   }
						if (stuff == 1)
 						    {
 					      ScaleLevel =  16;
  							   }
						if (stuff == 0)
 						    {
  						     ScaleLevel =  64;
  						   }
					ScaleLevelfloat = (float) ScaleLevel;
					ClearTemp = (float) sysOutput.lLevelClear;
				    ClearTemp = ClearTemp  *  8.33 * 4.5454545 * ScaleLevelfloat / 10000.0 / .769 ;

 			  fprintf(BT,"DO,%f,wtemp,%f,pH,%f,wlevel,%f,lLevelX,%f,lLevelY,%f,lLevelRed,%Lu,lLevelgreen,%Lu,lLevelBlue,%Lu,lLevelClear,%Lu,rH,%f,aTemp,%f,PAR,%f~\n\r",sysOutput.dOxy,sysOutput.wTemp,sysOutput.pH,sysOutput.wLevel,sysOutput.lLevelX,sysOutput.lLevelY,sysOutput.lLevelRed,sysOutput.lLevelGreen,sysOutput.lLevelBlue,sysOutput.lLevelClear,sysOutput.rH, sysOutput.aTemp,ClearTemp);    
			Minutes = 1;   //reset evertyhing back to the beginning.
			Seconds = 0;
		}
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

//		else
//		{
//		fprintf(BT,"Current Minute  %i Second %i  Set limit %i\n\r", Minutes, Seconds,BTMeasureTimer);
//		}
	}

if((testcntr==(SENDINTERVAL-2000)) && (!BTMeasureTimer))    //This is the remote meassure for the pH bulb.  There is a ton of time between EC measurement and Ph bulb.
	{

//***************************************************************
//***************************************************************
// Added Oct 5, 2016
// This is commented out to help get past uploading to the server for testing.  It needs to be removed for normal operations.
//****************************************************************
    if (firstimethrough == 0)   // If this is the first time through for this power up, then don't collect data.
	{	
	sensorRead2();   //  Read the ph bulb only.
	//reloadTime();
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
      
	testcntr++;    //Kick to the next count to get away from this condition.
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
	}
}





if((testcntr==(SENDINTERVAL-298)) && (!BTMeasureTimer))    // This time spot is used to save the current readings in the buffer and in the vault.

	{


//***************************************************************
//***************************************************************
// Added Aug 12, 2015
// This is commented out to help get past uploading to the server for testing.  It needs to be removed for normal operations.
//****************************************************************
    if (firstimethrough == 0)   // If this is the first time through for this power up, then don't collect data.
	{	
	sensorRead();
	//reloadTime();
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    ReadRemoteDevice(0x07);   // this selects the only I2C port on this board   Added October 29, 2016
  //  moveReceivedData(0);  // Added October 29, 2016   This call is used to move the data from the recive buffer from a I2C remote sensor board.
    
    
	sysOutput.rH=sysOutput.rH+0.1;
	printTime(sysOutput.year,sysOutput.month,sysOutput.day,sysOutput.hour,sysOutput.minute,sysOutput.second);

    SaveSendingReadings();
      
      }
	testcntr++;    //Kick to the next count to get away from this condition.
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
	
	}


//*******************************************************************
// Created May 8, 2015
// This routine is used to check if a file needs to be deleted.  It uses a flag from parsedata and deletes the 
// current file in the buffer called ->  NextBufferFileName  in the "buffer" folder.
// The flag is cleared until the next time it is set.  This flag is used to as an ack from the server that it recevied something and it saying it
// is completed.  The trigger routine is in wwwParser.c
//*******************************************************************

// Check it see if the flag is set
if ((ACKFROMSERVER != 0) && (!BTMeasureTimer) && (firstimethrough == 0))
	{
orLEDmessage(0x03);
// Move to the buffer folder if it existes

        		Display_XYString(0,4,"Clearing last file");
                removebufferrecord();  // Get rid of the last record.

        LEDmessage(0x00);
	}
ACKFROMSERVER = 0; // Set this back to zero to make sure it's clear.
// Skip all if there is no buffer folder or the SD Card is not installed.



//*******************************************************************
// Created May 7, 2015
// This if statment sends the data to the sever if there is a connection.
// It first checks to see if there is any data in the buffer to send.
// This is checked twice every cycle.  This means it get rid of two points max every cycle.  This can be changed to more frequene once the server connection is back up.
// The first task is to check if are any files in the buffer to send.
// If there are data points to send, then send it at this time.
// Once there is some ack that the point is on the server, it is deleted.
//*******************************************************************
if((((testcntr==(SENDINTERVAL-398)) || (testcntr==(SENDINTERVAL-498)))  && (SDCardResults == 0)  ) && (!BTMeasureTimer) && (firstimethrough == 0))
	{
	//  Change to the folder to get a dir.
	//	 VacDisplayClear();
orLEDmessage(0x06);
		fprintf(BT,"Checking Buffer\n\r");
        

    
    changefolder = GetNextBufferRecord();  // see if you can find the next item to send in the buffer
	if (changefolder == 0)  //If the folder exists and can move to it, then get the rest of the data.
    {
 				fprintf(WIFI,"%s",scr);   //Send the data off to the server.
				fprintf(BT,"%s\n\r",scr);   //Send the data off to the server and send it to the connected bluetooth unit for display read.       
    }
    else
    {
        fprintf(BT,"Buffer Empty\n\r");
    }

LEDmessage(0x00);
	testcntr++;   //Kick to the next state
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

	}

//**********************************************************************
// Created May 7, 2015
// This if statement checks to see if there is a true connection to the server.  
// If there is, it then sets SDCardResults == 3.
//  Once there is a connection once to the server, this state can not be changed.  If ther sever goes out
// or the connection is broken, it will remain loading things to the buffer.
//**********************************************************************
//if((testcntr==(SENDINTERVAL-98)) && (!BTMeasureTimer))
if (firstimethrough == 0)
	{
if ((!BTMeasureTimer) && (read_clock.tm_sec == 1) && (lastsecond != read_clock.tm_sec))   // Changed December 28 to use the RTC for the server checking
	{
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
	fprintf(BT,"Tickling Server to see if Connection really exists\n\r");
	SDCardResults = ServerUp();
	//SDCardResults = ConnectedToInternet();
	fprintf(BT,"Connection Report %i\n\r",SDCardResults);
    if (SDCardResults == 6)
    {
       stiffcounter++;
       if (stiffcounter >9)   // there there are more than 9 times no connection but still connected to the router, reset the system
       {
           reset_cpu();   //reset the CPU if there is no connection to the server, but there is a connection to the router.
       }
        
    }
    for (xx=0; xx < 16;xx++)
        string2[xx]=sysOutput.deviceID[xx];
    
   if ((SDCardResults == 0) && (strstr(string1,string2)!=0))
    {
        fprintf(BT,"Asking Server for the Next Avaliable Serial Number\n\r");
        returnedresult = GetNextSerialNumber();
    }
    
   lastestversion=  currentFW();   // determine if the firmware needs to be downloaded.
   if ((SDCardResults == 0) && (lastestversion==0))
    {
        fprintf(BT,"Asking Server for the Block of FirmWare\n\r");
        returnedresult = GetNextFirmWareBlock();
    }    
	 //If the Default serial number is PaulsBoard, then ask the server a new serial number
    
	testcntr++;
	BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
	calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

	}
	}
	lastsecond = read_clock.tm_sec;

//***************************************************************************
// Added Oct 30, 2015
//  This is the fake real time clock.  It is removed on the next board.
//  Time is bumbed up every time through by 1 second.  It is assumed the data collection will compensate for the quick timing.
//***************************************************************************
//delay_ms(900);  // this is the one second delay for each tick of the counter.  Added Nov. 3, 2015  This needs to be removed when the RTC is installed.
sysOutput.second=sysOutput.second+1;   //This stays here to count the seconds.

  if (sysOutput.second == 60) {sysOutput.minute++; sysOutput.second=0; 
    if (sysOutput.minute == 60) {sysOutput.hour++; sysOutput.minute=0; 
      if (sysOutput.hour == 24) {sysOutput.day++; sysOutput.hour=0; 
        if (  (sysOutput.day == 29 && sysOutput.month==2 && !IS_LEAP(sysOutput.year))                        // February in leap year 
           || (sysOutput.day == 30 && sysOutput.month==2)                                          // February in normal years 
           || (sysOutput.day == 31 && (sysOutput.month==4 ||sysOutput.month==6 || sysOutput.month==9 || sysOutput.month==11 ))  // All months with 30 days 
           || (sysOutput.day == 32)                                                      // All months with 31 days 
           ) {sysOutput.month++; sysOutput.day=1;} 
        if (sysOutput.month == 13) {sysOutput.year++; sysOutput.month=1;} 
  }}} 


// End of timer.
//***************************************************************************




//*********************************************************************
// Created Nov. 9, 2015
// This section is used to kick out all of the Wifi stuff and only to BT commands.  Must use rst to get out of it.
//  A flag is set to kick it in this routine.
//*********************************************************************

	if (btonly == 1)
			{
			while(1)
				{
				BTBasicTest();
				calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
				}
			}	




if((testcntr>SENDINTERVAL) && (!BTMeasureTimer))
{

testcntr=0;

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.


}			

			testcntr++;	//Increment the counter if the device is connected to something	
            restart_wdt();   // restart the WD timer.  It set for 65 seconds
            delay_ms(100);
			BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
			calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
			}

}	
