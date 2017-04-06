//***************************************************************************************
// Created October 16, 2016
// This file is included in project to make this unit a slave for the Osmobot.
// include this in the top of the project and update the data array with the data wanting to be returned.
//**************************************************************************************
//#define SDAPIN PIN_B2
//#define SCLPIN PIN_B3

//#use I2C(stream=SENSOR, SLAVE, sda=SDAPIN,scl=SCLPIN, FORCE_HW, address=0xa0, NO_STRETCH)   // this is I2C 1

char send_buffer[65];   // this is filled by this unit for sending data.
unsigned int8 rcv_buffer[65];   // this is the received data from the master 
unsigned  int8 address, streamCntr=0; 


//***************************************************************************
// Created Oct 7, 2016
// Updated Oct 16, 2016  -- Added CO2 structure for sending data.  -- Changed the number of registers to 100 from 20.
// This routine sets the protocal for communicating to a remote custom I2c device.
// The frames and commands are as follows:
// Address 0x12  for this device.
// write a command to the command register before reading or writing to the device
// Command Register  :    01    // A one for R reads all data points from the unit   //  A one for W writes calibration numbers for all instruments
//      MSB                  LSB
//       7  6  5  4  3  2  1  0
//       X  X  X  X  X  X  R  W
// There are 20 registers (bytes) for reading data from the unit
// There are 40 registers (bytes) for writing data to the unit
// Reading frame definition     --  has to be done in sequence each time.
// 1: HN4  whole number portion of reading
// 2: NH4  fraction of the reading
// 3: DO  whole number portion of reading
// 4: DO  fraction of the reading
// 5: Water Temperature  whole number portion of reading
// 6: Water Temperature  fraction of the reading
// 7: CO2 High byte    Updated Oct 16, 2016
// 8: CO2 Low Byte   Updated Oct 16, 2016
// 9: Air Temperature whole number    Updated Oct 24, 2016
// 10: Air Temperature fractional part   Updated Oct 24, 2016
// 11: Air RH  whole number   Updated Oct 24, 2016
// 12: Air RH fractional part    Updated Oct 24, 2016
// 13: Water Temperature High Byte raw data   Updated Feb 15, 2017
// 14: Water Temperature Low Byte raw data   Updated Feb 15, 2017
// 15: DO  RawData High Byte
// 16: DO  RawData Low Byte
// 17: NH4 RawData High Byte
// 18: NH4 RawData Low Byte
        // Added Fab 26, 2017
        // these items are the raw numbers for NH4
// 19: NH4 Patch RED RawData High Byte
// 20: NH4 Patch RED RawData Low Byte
// 21: NH4 Patch GREEN RawData High Byte
// 22: NH4 Patch GREEN RawData Low Byte
// 23: NH4 Patch BLUE RawData High Byte
// 24: NH4 Patch blue RawData Low Byte
// 25: NH4 Patch WHITE RawData High Byte
// 26: NH4 Patch WHITE RawData Low Byte
// 27: DpH  Digital Red RawData High Byte
// 28: DpH  Digital Red RawData Low Byte
// 29:  DpH Reading  whole number  updated March 30, 2017
// 30:  DpH fractional part  updated March 30, 2017
// 31: DpH  Digital Green RawData High Byte   updated April 3, 2017
// 32: DpH  Digital Green RawData Low Byte   updated April 3, 2017
// 33: DpH  Digital Blue RawData High Byte   updated April 3, 2017
// 34: DpH  Digital Blue RawData Low Byte   updated April 3, 2017
// 35: DpH  Digital White RawData High Byte   updated April 3, 2017
// 36: DpH  Digital White RawData Low Byte   updated April 3, 2017
// XX:  TBD


/*
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
 */





// Writing frame definition  --  has to be done in sequence each time.
// 1: HN4  whole number portion of HN4 calibration for point 1
// 2: NH4  fraction of the reading of HN4 calibration for point 1
// 3: HN4  whole number portion of HN4 calibration for point 2
// 4: NH4  fraction of the reading of HN4 calibration for point 2
// 5: HN4  whole number returned value of HN4 calibration for point 1
// 6: NH4  fraction of the returned value of HN4 calibration for point 1
// 7: HN4  whole number returned value of HN4 calibration for point 2
// 8: NH4  fraction of the returned value of HN4 calibration for point 2
// 9: TBD   all zeros
// 10: TBD
// 11: TBD
// 12: TBD
// 13: TBD
// 14: TBD
// 15: TBD
// 16: TBD
// 17: TBD
// 18: TBD
// 19: TBD
// 20: TBD
//  ......
// 99: checksum high byte
// 100: checksum low byte
// returns a 1 if the checksum is OK and it receives data
//******************************************************************************


//*******************************************************************************
// Create November 2, 2016
// Save this float into eeprom
// returns nothing.
//  give the pointer to the number, the location in eeprom and length
//******************************************************************************
void eeprom_write_block(int16 *ptr, unsigned int8 addr, unsigned char len)
{
  unsigned int16 *data = ptr;
    unsigned int16 bufferin[4];
    unsigned int8 stuffit = addr;
    len=len>>1;    // Since we are using 16 bits, two bytes are used at a time because of defs.
    addr=addr<<1;   //mult by two offset to the correct location.

    //read back the data
   while (len--) {
        write_eeprom(addr, *data++);
        addr=addr+2;  // need to skip two bytes since this is a 16 bit CPU  
    } 
//    bufferin[0] = read_eeprom[0];
 //   bufferin[1] = read_eeprom[2];       
 stuffit= stuffit+1;    
}




float READ_FLOAT_EEPROM(long int n) 
{ 
   int i; 
   float data;

   for (i = 0; i < 2; i++) 
      *((int16*)&data + i) = read_eeprom(2*i + 2*n);

   return(data); 
}

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
    
//******************************************************************************
// Created October 17, 2016
// This is a check sum for the data sent through the I2C back to the master.  The numbers are split and put into the
// last two locations of the upload send_buffer[].
//  Nothing is returned, but the data is updated in this function.
//******************************************************************************
void CalculateCRC(void)
{
    unsigned int16 checksum;
    unsigned int8 checksumhigh, checksumlow, x;
    for (x=0; x < 98; x++)
    {
    checksum = checksum + send_buffer[x];
    }
    //seperate the numbers into high and low
    checksumlow = 0x00FF & checksum;
    //  place the numbers in the array
    checksumhigh = (0xFF00 & checksum)>>8;
    send_buffer[98]=checksumhigh;
    send_buffer[99]=checksumlow;
}    
    
//******************************************************************************
// Created Oct. 16, 2016
// this routine clears the data in the return buffer to all 0xFF.  This means if the data is 0xFF, there is no sensor data avaible and is ignored by the
// master CPU.  That means the main CPU master needs to go through all of the returned data and check to see if it is not 0xFF for all sets of bytes.
//******************************************************************************

    void initTransMitBuffer(void)
    {
        // there are 100 points in the transmit buffer.
        int x;
        for (x = 0; x < 65; x++)   // set all of the returned data to 0xFF.  If there is data to be returned, it will change it to non 0xFF
        {
            send_buffer[x] = 0xFF;
        }
      
    }
      
    
//*****************************************************************
//Created November 2, 2016
//  This is the eeprom read function to load all of the calibration data from the eeprom
// This routine can be triggered from the program and from one of the commands from the I2C
// It returns all of the data read from the internal data eeprom
//******************************************************************
int LoadConfiguration(void)
{
    float checkvalue;   // this is used for returning the value and checking to see if it took.
    
   /*
    float Temp1DOOne = 9.5;            //These are the set points where we want to read these numbers at temperature 1
	float Temp1DOTwo = 4.0;            //This is at 10 degrees
	float Temp1DOThree = 0.0;
*/ 
    Temp1DOOne = READ_FLOAT_EEPROM(0);
    Temp1DOTwo = READ_FLOAT_EEPROM(1);
    Temp1DOThree = READ_FLOAT_EEPROM(2);
    /*

	float Temp2DOOne = 7.5;            //These are the set points where we want to read these numbers at temperature 2
	float Temp2DOTwo = 4.0;				//This is at 20 degrees
	float Temp2DOThree = 0.0;

     */
    Temp2DOOne = READ_FLOAT_EEPROM(3);
    Temp2DOTwo = READ_FLOAT_EEPROM(4);
    Temp2DOThree = READ_FLOAT_EEPROM(5);
    /*
	float Temp3DOOne = 6.7;            //These are the set points where we want to read these numbers temperature 3
	float Temp3DOTwo = 4.0;            //This is at 25 degrees
	float Temp3DOThree = 0.0;  
 */
    Temp3DOOne = READ_FLOAT_EEPROM(6);
    Temp3DOTwo = READ_FLOAT_EEPROM(7);
    Temp3DOThree = READ_FLOAT_EEPROM(8);
    /*
     
    float Temp1ReadingOne = 10752.0;       //Readings for Temp3  10 degrees C
	float Temp1ReadingTwo = 11000.0;      //Readings for Temp3
	float Temp1ReadingThree = 12000.0;    //Readings for DOOne    this is no DO.
     
     */
    Temp1ReadingOne = READ_FLOAT_EEPROM(9);
    Temp1ReadingTwo = READ_FLOAT_EEPROM(10);
    Temp1ReadingThree = READ_FLOAT_EEPROM(11);
     /* 
     
	float Temp2ReadingOne = 11266.0;       //Readings for Temp3    20 degrees C
	float Temp2ReadingTwo = 12000.0;      //Readings for Temp3
	float Temp2ReadingThree = 13000.0;    //Readings for DOOne
*/
    Temp2ReadingOne = READ_FLOAT_EEPROM(12);
    Temp2ReadingTwo = READ_FLOAT_EEPROM(13);
    Temp2ReadingThree = READ_FLOAT_EEPROM(14);
    /*
	float Temp3ReadingOne = 12425.0;       //Readings for Temp3   25 degrees C
	float Temp3ReadingTwo = 13000.0;      //Readings for Temp3
	float Temp3ReadingThree = 14000.0;    //Readings for DOOne
*/
    Temp3ReadingOne = READ_FLOAT_EEPROM(15);
    Temp3ReadingTwo = READ_FLOAT_EEPROM(16);
    Temp3ReadingThree = READ_FLOAT_EEPROM(17);
    /*
   
	float TempOne = 10.0;       //Calibration temperatures for DO   Added April 7, 2015
 	float TempTwo =  20.0;      //Calibration temperatures for DO  Added April 7, 2015
	float TempThree =  25.0;     //Calibration temperatures for DO  Added April 7, 2015

     */
    TempOne = READ_FLOAT_EEPROM(18);
    TempTwo = READ_FLOAT_EEPROM(19);
    TempThree = READ_FLOAT_EEPROM(20);
    
    return(0);   // if it makes it to here, everything is ok.
}

//*******************************************************************************
// Create November 2, 2016
// Save this float into eeprom
// returns nothing.
//  give the pointer to the number, the location in eeprom and length
//******************************************************************************
void eeprom_write_blocktest(int16 *ptr, unsigned int8 addr, unsigned char len)
{
  unsigned int16 *data = ptr;
    unsigned int16 bufferin[4];
    unsigned int8 stuff = addr;
    len=len>>1;    // Since we are using 16 bits, two bytes are used at a time because of defs.
    addr=addr<<1;   //mult by two offset to the correct location.

    //read back the data
   while (len--) {
        write_eeprom(addr, *data++);
        addr=addr+2;  // need to skip two bytes since this is a 16 bit CPU  
    } 
 //   bufferin[0] = read_eeprom[stuff];
 //   bufferin[1] = read_eeprom[stuff+2];       
 stuff= stuff+1;    
}



//*****************************************************************
//Created Oct. 19, 2016
//  This is the eeprom write function to save all of the calibration data to the eeprom
// This routine can be triggered from the program and from one of the commands from the I2C
// It returns a 0 if everything is OK,  A 1 is returned when it failed.
//  It does a write and reads back the data to make it made it.
//******************************************************************
int SaveConfiguration(void)
{
    float checkvalue;   // this is used for returning the value and checking to see if it took.
    
   /*
    float Temp1DOOne = 9.5;            //These are the set points where we want to read these numbers at temperature 1
	float Temp1DOTwo = 4.0;            //This is at 10 degrees
	float Temp1DOThree = 0.0;
*/ 
    eeprom_write_blocktest(&Temp1DOOne, 0, sizeof Temp1DOOne);
    checkvalue = READ_FLOAT_EEPROM(0);
    if (Temp1DOOne != checkvalue)
        return(1);    // return this error
    eeprom_write_blocktest(&Temp1DOTwo, 1, sizeof Temp1DOTwo);
    checkvalue = READ_FLOAT_EEPROM(1);
    if (Temp1DOTwo != checkvalue)
        return(2);    // return this error
     eeprom_write_blocktest(&Temp1DOThree, 2, sizeof Temp1DOThree);
    checkvalue = READ_FLOAT_EEPROM(2);
    if (Temp1DOThree != checkvalue)
        return(3);    // return this error
    
    // this routine saves the data for the NH4, EC, DO and temperature
    /*

	float Temp2DOOne = 7.5;            //These are the set points where we want to read these numbers at temperature 2
	float Temp2DOTwo = 4.0;				//This is at 20 degrees
	float Temp2DOThree = 0.0;

     */
    eeprom_write_block(&Temp2DOOne, 3, sizeof Temp2DOOne);
    checkvalue = READ_FLOAT_EEPROM(3);
    if (Temp2DOOne != checkvalue)
        return(4);    // return this error
    eeprom_write_block(&Temp2DOTwo, 4, sizeof Temp2DOTwo);
    checkvalue = READ_FLOAT_EEPROM(4);
    if (Temp2DOTwo != checkvalue)
        return(5);    // return this error
     eeprom_write_block(&Temp2DOThree, 5, sizeof Temp2DOThree);
    checkvalue = READ_FLOAT_EEPROM(5);
    if (Temp2DOThree != checkvalue)
        return(6);    // return this error
   
    /*
	float Temp3DOOne = 6.7;            //These are the set points where we want to read these numbers temperature 3
	float Temp3DOTwo = 4.0;            //This is at 25 degrees
	float Temp3DOThree = 0.0;  
 */
    
    eeprom_write_block(&Temp3DOOne, 6, sizeof Temp3DOOne);
    checkvalue = READ_FLOAT_EEPROM(6);
    if (Temp3DOOne != checkvalue)
        return(7);    // return this error
    eeprom_write_block(&Temp3DOTwo, 7, sizeof Temp3DOTwo);
    checkvalue = READ_FLOAT_EEPROM(7);
    if (Temp3DOTwo != checkvalue)
        return(8);    // return this error
     eeprom_write_block(&Temp3DOThree, 8, sizeof Temp3DOThree);
    checkvalue = READ_FLOAT_EEPROM(8);
    if (Temp3DOThree != checkvalue)
        return(9);    // return this error  
    /*
     
    float Temp1ReadingOne = 10752.0;       //Readings for Temp3  10 degrees C
	float Temp1ReadingTwo = 11000.0;      //Readings for Temp3
	float Temp1ReadingThree = 12000.0;    //Readings for DOOne    this is no DO.
     
     */
    
    eeprom_write_block(&Temp1ReadingOne, 9, sizeof Temp1ReadingOne);
    checkvalue = READ_FLOAT_EEPROM(9);
    if (Temp1ReadingOne != checkvalue)
        return(10);    // return this error
    eeprom_write_block(&Temp1ReadingTwo, 10, sizeof Temp1ReadingTwo);
    checkvalue = READ_FLOAT_EEPROM(10);
    if (Temp1ReadingTwo != checkvalue)
        return(11);    // return this error
     eeprom_write_block(&Temp1ReadingThree, 11, sizeof Temp1ReadingThree);
    checkvalue = READ_FLOAT_EEPROM(11);
    if (Temp1ReadingThree != checkvalue)
        return(12);    // return this error
    
     /* 
     

	float Temp2ReadingOne = 11266.0;       //Readings for Temp3    20 degrees C
	float Temp2ReadingTwo = 12000.0;      //Readings for Temp3
	float Temp2ReadingThree = 13000.0;    //Readings for DOOne
*/
    eeprom_write_block(&Temp2ReadingOne, 12, sizeof Temp2ReadingOne);
    checkvalue = READ_FLOAT_EEPROM(12);
    if (Temp2ReadingOne != checkvalue)
        return(13);    // return this error
    eeprom_write_block(&Temp2ReadingTwo, 13, sizeof Temp2ReadingTwo);
    checkvalue = READ_FLOAT_EEPROM(13);
    if (Temp2ReadingTwo != checkvalue)
        return(14);    // return this error
     eeprom_write_block(&Temp2ReadingThree, 14, sizeof Temp2ReadingThree);
    checkvalue = READ_FLOAT_EEPROM(14);
    if (Temp2ReadingThree != checkvalue)
        return(15);    // return this error
    /*
	float Temp3ReadingOne = 12425.0;       //Readings for Temp3   25 degrees C
	float Temp3ReadingTwo = 13000.0;      //Readings for Temp3
	float Temp3ReadingThree = 14000.0;    //Readings for DOOne
*/
    eeprom_write_block(&Temp3ReadingOne, 15, sizeof Temp3ReadingOne);
    checkvalue = READ_FLOAT_EEPROM(15);
    if (Temp3ReadingOne != checkvalue)
        return(16);    // return this error
    eeprom_write_block(&Temp3ReadingTwo, 16, sizeof Temp3ReadingTwo);
    checkvalue = READ_FLOAT_EEPROM(16);
    if (Temp3ReadingTwo != checkvalue)
        return(17);    // return this error
     eeprom_write_block(&Temp3ReadingThree, 17, sizeof Temp3ReadingThree);
    checkvalue = READ_FLOAT_EEPROM(17);
    if (Temp3ReadingThree != checkvalue)
        return(18);    // return this error
    /*
   
	float TempOne = 10.0;       //Calibration temperatures for DO   Added April 7, 2015
 	float TempTwo =  20.0;      //Calibration temperatures for DO  Added April 7, 2015
	float TempThree =  25.0;     //Calibration temperatures for DO  Added April 7, 2015

     
float DOpt1returnednumber;   // this is the returned DO number used for solving the equations at different temperatures
float DOpt2returnednumber;
float DOpt3returnednumber;
     */
    
    eeprom_write_block(&sysInput.DOpt1returnednumber, 18, sizeof sysInput.DOpt1returnednumber);
    checkvalue = READ_FLOAT_EEPROM(18);
    if (sysInput.DOpt1returnednumber != checkvalue)
        return(19);    // return this error
    eeprom_write_block(&sysInput.DOpt2returnednumber, 19, sizeof sysInput.DOpt2returnednumber);
    checkvalue = READ_FLOAT_EEPROM(19);
    if (sysInput.DOpt2returnednumber != checkvalue)
        return(20);    // return this error
     eeprom_write_block(&sysInput.DOpt3returnednumber, 20, sizeof sysInput.DOpt3returnednumber);
    checkvalue = READ_FLOAT_EEPROM(20);
    if (sysInput.DOpt3returnednumber != checkvalue)
        return(21);    // return this error
     /*
unsigned int16 Thermisterpt1cal1of3;
unsigned int16 Thermisterpt1cal2of3;
unsigned int16 Thermisterpt1cal3of3;
    */
    
    
    eeprom_write_block(&sysInput.Thermisterpt1cal1of3, 21, sizeof sysInput.Thermisterpt1cal1of3);
    checkvalue = READ_FLOAT_EEPROM(21);
    if (sysInput.Thermisterpt1cal1of3 != checkvalue)
        return(22);    // return this error
    eeprom_write_block(&sysInput.Thermisterpt1cal2of3, 22, sizeof sysInput.Thermisterpt1cal2of3);
    checkvalue = READ_FLOAT_EEPROM(22);
    if (sysInput.Thermisterpt1cal2of3 != checkvalue)
        return(23);    // return this error
     eeprom_write_block(&sysInput.Thermisterpt1cal3of3, 23, sizeof sysInput.Thermisterpt1cal3of3);
    checkvalue = READ_FLOAT_EEPROM(23);
    if (sysInput.Thermisterpt1cal3of3 != checkvalue)
        return(24);    // return this error
    
/*
float Thermisterpt1returnednumber;
float Thermisterpt2returnednumber;
float Thermisterpt3returnednumber;
  */
    
   eeprom_write_block(&sysInput.Thermisterpt1returnednumber, 24, sizeof sysInput.Thermisterpt1returnednumber);
    checkvalue = READ_FLOAT_EEPROM(24);
    if (sysInput.Thermisterpt1returnednumber!= checkvalue)
        return(25);    // return this error
    eeprom_write_block(&sysInput.Thermisterpt2returnednumber, 25, sizeof sysInput.Thermisterpt2returnednumber);
    checkvalue = READ_FLOAT_EEPROM(25);
    if (sysInput.Thermisterpt2returnednumber != checkvalue)
        return(26);    // return this error
     eeprom_write_block(&sysInput.Thermisterpt3returnednumber, 26, sizeof sysInput.Thermisterpt3returnednumber);
    checkvalue = READ_FLOAT_EEPROM(26);
    if (sysInput.Thermisterpt3returnednumber != checkvalue)
        return(27);    // return this error
     
    
    return(0);   // if it makes it to here, everything is ok.
}



//*********************************************************************************************
// Created November 28, 2016
// This moves the data from the recieve buffer into the configuation varaubles.
// Returns nothing.  This is called when rcv_buffer[2] == 0x01
//*********************************************************************************************
void movercvbuffertocolibration(void)
{
 
    int8 lowbyte,highbyte;
    unsigned int16 items;
    int i; 
   float data;
       
    //these are the two byte int16s
    lowbyte = rcv_buffer[3];
    highbyte = rcv_buffer[4];
    items = (int16) highbyte;
    sysInput.nh4pt1cal1of3 = (items<<8) +  lowbyte;  
 
    lowbyte = rcv_buffer[5];
    highbyte = rcv_buffer[6];
    items = (int16) highbyte;
    sysInput.nh4pt1cal2of3 = (items<<8) +  lowbyte;  
    
    lowbyte = rcv_buffer[7];
    highbyte = rcv_buffer[8];
    items = (int16) highbyte;
    sysInput.nh4pt1cal3of3 = (items<<8) +  lowbyte;  
    
        
    lowbyte = rcv_buffer[9];
    highbyte = rcv_buffer[10];
    items = (int16) highbyte;
    sysInput.nh4pt2cal1of3 = (items<<8) +  lowbyte;  
 
    lowbyte = rcv_buffer[11];
    highbyte = rcv_buffer[12];
    items = (int16) highbyte;
    sysInput.nh4pt2cal2of3 = (items<<8) +  lowbyte;  
    
    lowbyte = rcv_buffer[13];
    highbyte = rcv_buffer[14];
    items = (int16) highbyte;
    sysInput.nh4pt2cal3of3 = (items<<8) +  lowbyte;  
            
    lowbyte = rcv_buffer[15];
    highbyte = rcv_buffer[16];
    items = (int16) highbyte;
    sysInput.nh4pt3cal1of3 = (items<<8) +  lowbyte;  
 
    lowbyte = rcv_buffer[17];
    highbyte = rcv_buffer[18];
    items = (int16) highbyte;
    sysInput.nh4pt3cal2of3 = (items<<8) +  lowbyte;  
    
    lowbyte = rcv_buffer[19];
    highbyte = rcv_buffer[20];
    items = (int16) highbyte;
    sysInput.nh4pt3cal3of3 = (items<<8) +  lowbyte;  
    
    // these are the four byte floats
    
   for (i = 0; i < 4; i++)    // this needs to read in four bytes
      *((int8*)&data + i) = rcv_buffer[i + 21];
    sysInput.nh4pt1returnednumber = data;

   for (i = 0; i < 4; i++)    // this needs to read in four bytes
      *((int8*)&data + i) = rcv_buffer[i + 25];
    sysInput.nh4pt1returnednumber = data;

   for (i = 0; i < 4; i++)    // this needs to read in four bytes
      *((int8*)&data + i) = rcv_buffer[i + 29];
    sysInput.nh4pt1returnednumber = data;    
    
}