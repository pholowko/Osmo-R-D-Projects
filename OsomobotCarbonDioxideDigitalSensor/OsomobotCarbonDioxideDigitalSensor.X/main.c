// CO2 Sensor RH temp Main.c file
#include <24FV32KA302.h>
#DEVICE ICD=TRUE
#device ADC=10
#include <stdio.h>
#include <stdlib.h>
#define SDAPIN PIN_B2
#define SCLPIN PIN_B3

#define SDATPIN PIN_B9
#define SCLTPIN PIN_B8

#fuses  NOWDT, NOBROWNOUT, NOPROTECT, PUT 

#use delay( crystal=8mhz, clock=32mhz )
//#use delay(crystal=25000000, clock=25000000)   // this is commented out for the new board.  It is the old 25MHz crystal.

//#use I2C(stream=SENSOR, SLAVE, sda=SDAPIN,scl=SCLPIN, I2C2, address=0xa0)   // this is I2C 1
#use I2C(stream=PH_LIGHT, MASTER, sda=SDATPIN, scl=SCLTPIN, I2C1, force_hw)    // this is the master I2c for talking with removote sensor boards.  There is only one I2c on this chip.
#define RHTEMP PIN_B15      //  this is the pin used for talking to the RH and Temp sensor


#define TESTER
#define COTWOSENSOR 1
#define SLAVE 1
#define SENSORNUMBER 0xd9   // this means it is CO2

int8 startupdate = 0; // this is the flag to start an upload 
int16 th,tl,hh,hl;  // variables for 1050 RH and temp sensor

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

//*****************************************************************************
// Created Febuary 20, 2017
// This is the selection routine where it picks which I2C to talk with.  
//  It does not exist on the CO2 since there is only one I2C used for talking with the RH/Temp sensor
//******************************************************************************

void selectsensor(int junk)  //This is added in this module to perform a dummy select.  It's used in the OSmobot only.
{
    return;
}



#include "C:\Aquarium Software\Debug Monitor\CommonPassedDataFromMaterToSlave.h"
#include <G:\Osmobot4PostProduction\Instrumentation\CheapRHAndTemp.c>
#include "I2cCO2.c"
#include "ITwoSeeGeneralCommunicationSlave.c"     // this is included to connect to the master Osmobot.



//******************************************************************************
// Documented Febuary 12, 2017
// This is the call for slave operation for a sensor board.
// It does the following functions:
// 1  Receives incoming data from the host
// 2  Sets the command register for sending back this modules ID
// 3
//******************************************************************************
/*
#INT_SI2C2

void si2c2_interrupt()
    {

unsigned int8  incoming, state;

        state=i2c_isr_state(SENSOR);

   if(state <= 0x80)                      //Master is sending data
   {
      incoming = i2c_read(SENSOR,1); 
      if(state == 1)                     //First received byte is address 
      {//First received byte is address
         address = incoming;
         streamCntr=0;
      }
      if(state == 2)                     //Second received byte is data 
          {  
          rcv_buffer[address] = incoming; 
          streamCntr=0;
          }
      
      if(state == 1)                      //First received byte is address
         address = incoming;
      else if(state >= 2 && state != 0x80)   //Received byte is data auto from the master
           {
            rcv_buffer[address++] = incoming;
            streamCntr=0;
            }
   }

   if((state >= 0x80) & (rcv_buffer[0x66] != 0x01))               //Master is requesting data
   {
      i2c_write(SENSOR,send_buffer[streamCntr++]);
   }
      if((state >= 0x80) & (rcv_buffer[0x66] == 0x01))               //Master is requesting data
   {
      i2c_write(SENSOR,SENSORNUMBER);
      rcv_buffer[0x66]=0x00;
   }
	}

*/


/*
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
*/
//***********************************************************



int main() {

    int16 returneditem;  // this is the returned item
    int8 highbyte, lowbyte;
    
    float returnedresultit,titemp;
    int returnedresult;
    InitCO2();

  //  enable_interrupts(INT_SI2C2);    // this starts the slave communication.
    initTransMitBuffer();   // Clear the buffer to send no data.
    while(1)
    {
        returneditem = ReadCOSensor();  // get the CO2 data
        // split it into two numbers.  High Byte and Low Byte.
        lowbyte = 0x00FF & returneditem;
        returneditem = 0xFF00 & returneditem;
        highbyte = returneditem>>8;  // this moves it over to the low part
        send_buffer[8] = lowbyte;   // update this on the send buffer  Added Oct 16, 2016
        send_buffer[7] = highbyte;   // update this on the send buffer  Added Oct 16, 2016    this is all that is needed to send the data.  When the master asks for the 
        // array, it will get the updated array. 
       
// *********************************************************************************
// Created No2. 3, 2014
// Find the RH and Temperature for the environment and send it to the server.
//  This routine talks with the cheap RH and Temperature sensor
// ********************************************************************************
/*
if (!GetTempRH())
	{
	sysOutput.aTemp = Temperature;  //This is the float temperature
    
    	if (sysOutput.aTemp < 0.0)
        {
		sysOutput.aTemp = 0.0;
        Temperature = 0.0;
        }
    
    send_buffer[9] =  (int) Temperature;  // high whole number byte
    send_buffer[10] =  (int) ((Temperature - (float) (int) Temperature)*100);  // high whole number byte
    

		
	sysOutput.rH = RHData;  //This is a float send into ta RH value.
	if (sysOutput.rH < 0.0)
		sysOutput.rH = 0.0;
	}
   send_buffer[11] =  (int) sysOutput.rH;  // high whole number byte
   send_buffer[12] =  (int) ((sysOutput.rH - (float) (int) sysOutput.rH)*100);  // high whole number byte
*/ 
        
        
    
//*********************************************************************************
// Created Jan 17, 2017
// This calls and saves the current air temp and rh
//*********************************************************************************
//   while(1) 
 //  {
 //  returneditem = GetHDC1080Version(1);     
//   }
        
        
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

    
    send_buffer[9] =  (int) sysOutput.aTemp;  // high whole number byte
    send_buffer[10] =  (int) ((sysOutput.aTemp - (float) (int) sysOutput.aTemp)*100);  // high whole number byte
    
    
    send_buffer[11] =  (int) sysOutput.rH;  // high whole number byte
    send_buffer[12] =  (int) ((sysOutput.rH - (float) (int) sysOutput.rH)*100);  // high whole number byte
  
 
// ********************************************************************************
// Created Nov. 3, 2014
// This routines borrows the calcaulaton from the expensive SHt11 chip to calcaulate DP
// ********************************************************************************

//sysOutput.dPoint=sht1x_calc_dewpoint(RHData,Temperature);


 
  //      CalculateCRC();  // update the CRC for sending to the Master unit
    }
    
    

}

