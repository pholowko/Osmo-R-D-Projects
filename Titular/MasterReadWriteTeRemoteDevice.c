

#ifdef NOTOSMOBOT
#include "CommonPassedDataFromMaterToSlave.h"
int16 CO2Raw,NHredRaw,NHGreenRaw,NHBlueRaw,NHWhiteRaw,DpHredRaw,DpHGreenRaw,DpHBlueRaw,DpHWhiteRaw;
#else
int16  DORaw, WTRaw, NH4Raw, CO2Raw,NHredRaw,NHGreenRaw,NHBlueRaw,NHWhiteRaw;
#endif





#ifndef BTTestEvent
void BTTestEvent(void);
#endif
//  See the slave include file calle ITwoSeeGeneralCommunicationSlave.c  for the data structure for sending data to the master.  All 
//  updates to the data structure are done on the Slave include file.  Not the master.

// Added Oct 24, 2016
// These routines are moved to a sharable file for the Osmobot and all other programs to read/write to i2c sensors.
// This routine is used in the Osmobot where there are no printf for a display.
int ReadRemoteDeviceOsmobot(int deviceaddress)
{
    
    int x;
    //  Selection of 0  internal Digital DO and NH4 sensor
    //  Selection of 1  Top RJ45 connector
    //  Selection of 2  Bottom RJ45 connector    
    //  Selection of 3  no connection
            selectsensor(deviceaddress);  // this sets the SCL to the right I2C device.
    
    	    i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0xa0);  //Move the address number left on and add a zero.  This is the command with address to write data to the address pointer
			i2c_write(PH_LIGHT,0x00);  //This is the locations of the first buffer to address
			i2c_stop(PH_LIGHT);
            
            i2c_start(PH_LIGHT);  // start again
            i2c_write(PH_LIGHT,0xa1);   // this starts the reading from the device.  Remember that a 1 in the first place is the command to send data from the device to the Master.
            delay_ms(75);
            for (x=0; x < 65; x++)            // read 128 locations and quit.  Put this in the returned array.  
            {
                rec_buffer[x] =  i2c_read(PH_LIGHT,FALSE);
             //   sprintf(adcBuff, "%i",rec_buffer[x]);

             //  adcStrCntr=0;

            //    while(adcBuff[adcStrCntr]!= '\0')
             //   {
            //    writeCharPos(adcStrCntr,0,adcBuff[adcStrCntr]);
             //   adcStrCntr++;
             //   }
                 delay_ms(1);
            }
            x++;
            rec_buffer[x] =  i2c_read(PH_LIGHT,FALSE);
            i2c_stop(PH_LIGHT);
    
    return(1);
}



//  See the slave include file calle ITwoSeeGeneralCommunicationSlave.c  for the data structure for sending data to the master.  All 
//  updates to the data structure are done on the Slave include file.  Not the master.



int ReadRemoteDevice(int deviceaddress)
{
    
    int x;

    //  Selection of 0  internal Digital DO and NH4 sensor
    //  Selection of 1  Top RJ45 connector
    //  Selection of 2  Bottom RJ45 connector    
    //  Selection of 3  no connection
            selectsensor(deviceaddress);  // this sets the SCL to the right I2C device.
    
    	    i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0xa0);  //Move the address number left on and add a zero.  This is the command with address to write data to the address pointer
			i2c_write(PH_LIGHT,0x00);  //This is the locations of the first buffer to address
			i2c_stop(PH_LIGHT);
            
            i2c_start(PH_LIGHT);  // start again
            i2c_write(PH_LIGHT,0xa1);   // this starts the reading from the device.  Remember that a 1 in the first place is the command to send data from the device to the Master.
            delay_ms(75);
            for (x=0; x < 65; x++)            // read 128 locations and quit.  Put this in the returned array.  
            {
                rec_buffer[x] =  i2c_read(PH_LIGHT);
               // sprintf(adcBuff, "%i %i",rec_buffer[x],deviceaddress);
              //  Display_XYString(0,1,adcBuff); 
                //adcStrCntr=0;

                //while(adcBuff[adcStrCntr]!= '\0')
                //{
                //writeCharPos(adcStrCntr,0,adcBuff[adcStrCntr]);
               // adcStrCntr++;
                //}
#if OSMOBOT
                BTBasicTest();
#else
                BTTestEvent();   // check for the data coming back to displayable
#endif               
                delay_ms(10);
            }
            x++;
            rec_buffer[x] =  i2c_read(PH_LIGHT,FALSE);
            i2c_stop(PH_LIGHT);
    
    return(1);
}

 
   
//*******************************************************************************
// Created October 28, 2016
// This routine takes the returned array of data from the remote device and moves it into the selected data startures.
//  It returns nothing.
// if the data in the returned array is 0xFF, nothing is done.  
//  The data structure is connected with the listing above.
//  The input is the array that needs to have the data moved into.  The numbering starts at 0 and goes through 4.  This means five different sensors can be used at the same time.
// If the same sensor is used, it is kept straight where the data sits and is sent to the server.
//  As of now, the input is ignorned because there is only one array.  
//*******************************************************************************
    void  moveReceivedData(int portid)
    {
        float tempvar;
        int16 tempvarint;
         // there are 100 points in the transmit buffer.
           // water temperature
            if ((rec_buffer[6] != 0xFF) && (rec_buffer[5] != 0xFF))
            {
              tempvar = (float) rec_buffer[5];
              sysOutput.wTemp = tempvar  + ((float) rec_buffer[6])/100;
            }
        
        
            // CO2
            if ((rec_buffer[7] != 0xFF) && (rec_buffer[8] != 0xFF))
            {
                 tempvarint = rec_buffer[7];
                 tempvarint = tempvarint*256 + rec_buffer[8];
                 sysOutput.cO2 = tempvarint;
            }       
             // Air Temperature
            if ((rec_buffer[9] != 0xFF) && (rec_buffer[10] != 0xFF))
            {
            tempvar = (float) rec_buffer[9];
            sysOutput.aTemp = tempvar  + ((float) rec_buffer[10])/100;
            }         
            // Air RH
            if ((rec_buffer[11] != 0xFF) && (rec_buffer[12] != 0xFF))
            {
            tempvar = (float) rec_buffer[11];
            sysOutput.rH = tempvar  + ((float) rec_buffer[12])/100;
            }   
 
            // DO
            if ((rec_buffer[3] != 0xFF) && (rec_buffer[4] != 0xFF))
            {
            tempvar = (float) rec_buffer[3];
            sysOutput.dOxy = tempvar  + ((float) rec_buffer[4])/100;
            }  
              // NH4-NH3
            if ((rec_buffer[1] != 0xFF) && (rec_buffer[2] != 0xFF))
            {
            tempvar = (float) rec_buffer[1];
            sysOutput.nh3 = tempvar  + ((float) rec_buffer[2])/100;
            }    
            if ((rec_buffer[15] != 0xFF) && (rec_buffer[16] != 0xFF))
            {
                 tempvarint = rec_buffer[15];
                 tempvarint = tempvarint*256 + rec_buffer[16];
                 DORaw = tempvarint;
            } 
            if ((rec_buffer[17] != 0xFF) && (rec_buffer[18] != 0xFF))
            {
                 tempvarint = rec_buffer[17];
                 tempvarint = tempvarint*256 + rec_buffer[18];
                 NH4Raw = tempvarint;
            } 
            if ((rec_buffer[13] != 0xFF) && (rec_buffer[14] != 0xFF))
            {
                 tempvarint = rec_buffer[13];
                 tempvarint = tempvarint*256 + rec_buffer[14];
                 WTRaw = tempvarint;
            } 
        // Added Feb 26, 2017
        // these items are the raw numbers for NH4
        //RED
            if ((rec_buffer[19] != 0xFF) && (rec_buffer[20] != 0xFF))
            {
                 tempvarint = rec_buffer[19];
                 tempvarint = tempvarint*256 + rec_buffer[20];
                 NHredRaw = tempvarint;
            }
        //GREEN
            if ((rec_buffer[21] != 0xFF) && (rec_buffer[22] != 0xFF))
            {
                 tempvarint = rec_buffer[21];
                 tempvarint = tempvarint*256 + rec_buffer[22];
                 NHGreenRaw = tempvarint;
            }
        //BLUE
            if ((rec_buffer[23] != 0xFF) && (rec_buffer[24] != 0xFF))
            {
                 tempvarint = rec_buffer[23];
                 tempvarint = tempvarint*256 + rec_buffer[24];
                 NHBlueRaw = tempvarint;
            } 
        //WHITE
            if ((rec_buffer[25] != 0xFF) && (rec_buffer[26] != 0xFF))
            {
                 tempvarint = rec_buffer[25];
                 tempvarint = tempvarint*256 + rec_buffer[26];
                 NHWhiteRaw = tempvarint;
            }         
        // Added April 3, 2017        
             //RED
                // these items are the raw numbers for the Oscean Optics DpH Patch
            if ((rec_buffer[27] != 0xFF) && (rec_buffer[28] != 0xFF))
            {
                 tempvarint = rec_buffer[27];
                 tempvarint = tempvarint*256 + rec_buffer[28];
                 DpHredRaw = tempvarint;
            }
        //GREEN
            if ((rec_buffer[31] != 0xFF) && (rec_buffer[32] != 0xFF))
            {
                 tempvarint = rec_buffer[31];
                 tempvarint = tempvarint*256 + rec_buffer[32];
                 DpHGreenRaw = tempvarint;
            }
        //BLUE
            if ((rec_buffer[33] != 0xFF) && (rec_buffer[34] != 0xFF))
            {
                 tempvarint = rec_buffer[33];
                 tempvarint = tempvarint*256 + rec_buffer[34];
                 DpHBlueRaw = tempvarint;
            } 
        //WHITE
            if ((rec_buffer[35] != 0xFF) && (rec_buffer[36] != 0xFF))
            {
                 tempvarint = rec_buffer[35];
                 tempvarint = tempvarint*256 + rec_buffer[36];
                DpHWhiteRaw = tempvarint;
            }           
        
        
        }    
        
    
    
//******************************************************************************
// Created November 24, 2016
// Calibrations Data is sent to the remote unit.  Another routine call this routine.
// Data input:
// int DeviceSelected  -- this is the IO port
// int VariableIDNumber  -- this is the same on the receiving device.  This is defined here
// int Variable Length
// pointer to the Variable  -- this is used to send the data to the remote device.  Characters are not sent to the remote device, but data
// Returned data:
// A 0 is returned if all is well.  A 1 is returned if it did not hear it.
// Each calibration number is sent with an address and pointer.  There is no dump of multi cal numbers.  
//*******************************************************************************
int sendConfigData(int deviceaddress, int8 VarIDNumber) 
{
       int x;
       unsigned int8 *data;
       unsigned char length;

    //  Selection of 0  internal Digital DO and NH4 sensor
    //  Selection of 1  Top RJ45 connector
    //  Selection of 2  Bottom RJ45 connector    
    //  Selection of 3  no connection
            selectsensor(deviceaddress);  // this sets the SCL to the right I2C device.
 
            
    	    i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0xa0);  //Move the address number left on and add a zero.  This is the command with address to write data to the address pointer
			i2c_write(PH_LIGHT,VarIDNumber);  //This is the locations of the first buffer to address
            length = sizeof(sysInput.nh4pt1cal1of3);
            data = &sysInput.nh4pt1cal1of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt1cal2of3);
            data = &sysInput.nh4pt1cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt1cal3of3);
            data = &sysInput.nh4pt1cal3of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt2cal1of3);
            data = &sysInput.nh4pt2cal1of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt2cal2of3);
            data = &sysInput.nh4pt2cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                }     
            length = sizeof(sysInput.nh4pt2cal3of3);
            data = &sysInput.nh4pt2cal3of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt3cal1of3);
            data = &sysInput.nh4pt3cal1of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt3cal2of3);
            data = &sysInput.nh4pt3cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                }     
            length = sizeof(sysInput.nh4pt3cal3of3);
            data = &sysInput.nh4pt3cal1of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            
           
            
            length = sizeof(sysInput.nh4pt1returnednumber);
            data = &sysInput.nh4pt1returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt2returnednumber);
            data = &sysInput.nh4pt2returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.nh4pt3returnednumber);
            data = &sysInput.nh4pt3returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            
            
            
            // this is sending all of the DO stuff
            
            length = sizeof(sysInput.DOpt1cal1of3);
            data = &sysInput.DOpt1cal1of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt1cal2of3);
            data = &sysInput.DOpt1cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt1cal3of3);
            data = &sysInput.DOpt1cal3of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt2cal1of3);
            data = &sysInput.DOpt2cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt2cal2of3);
            data = &sysInput.DOpt2cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                }     
            length = sizeof(sysInput.DOpt2cal3of3);
            data = &sysInput.DOpt2cal3of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt3cal1of3);
            data = &sysInput.DOpt3cal1of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt3cal2of3);
            data = &sysInput.DOpt3cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                }     
            length = sizeof(sysInput.DOpt3cal3of3);
            data = &sysInput.DOpt3cal3of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            
           
            
            length = sizeof(sysInput.DOpt1returnednumber);
            data = &sysInput.nh4pt1returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt2returnednumber);
            data = &sysInput.nh4pt2returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.DOpt3returnednumber);
            data = &sysInput.nh4pt3returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                }        
        
            
            // This is the therimister stuff
            
            
            length = sizeof(sysInput.Thermisterpt1cal1of3);
            data = &sysInput.Thermisterpt1cal1of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.Thermisterpt1cal2of3);
            data = &sysInput.Thermisterpt1cal2of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                }     
            length = sizeof(sysInput.Thermisterpt1cal3of3);
            data = &sysInput.Thermisterpt1cal3of3;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            
            
               length = sizeof(sysInput.Thermisterpt1returnednumber);
            data = &sysInput.Thermisterpt1returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.Thermisterpt2returnednumber);
            data = &sysInput.Thermisterpt2returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                } 
            length = sizeof(sysInput.Thermisterpt3returnednumber);
            data = &sysInput.Thermisterpt3returnednumber;
            while (length--) {
               i2c_write(PH_LIGHT, *data++);
                }          
            
      //  this is where additional calibrations are added.  It has to be before the stop and the last I2C write to trigger the receiving unit for saving data.
			i2c_stop(PH_LIGHT);
            
    	    i2c_start(PH_LIGHT);
			i2c_write(PH_LIGHT,0xa0);  //Move the address number left on and add a zero.  This is the command with address to write data to the address pointer
			i2c_write(PH_LIGHT,0x02);  //This is the locations of the first buffer to address           
			i2c_write(PH_LIGHT,0x01);  //Set this location (0x02) to 1 to tell the receiver that all calibrations are uploaded and ready for EEPROMing.           
 			i2c_stop(PH_LIGHT);           
            
     return(0);       
}
    
   
        
