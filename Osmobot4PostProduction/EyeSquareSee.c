//**********************************************************************
// Created March 17, 2016
// These routine are used to take with the I2C EEPROM that replaces the SD Card.
// Both I2C and SD Card can be laid out, but one or the other is used.
// These routines save and read the I2C EEPROM for calibrations, configurations and data buffer.  
// There is only a 100 slot data buffer for when the unit can not talk with the server.  This is 24 hours of data taken at 15 minutes.
// The addresses will be kept low to allow for cheaper chips.
// Sequential read address boundaries are 0000h to
//7FFFh and 8000h to FFFFh. The internal Address
//Pointer will automatically roll over from address 7FFF
//to address 0000 if the master acknowledges the byte
//received from the array address 7FFF. 

//  Data address location(s)
//  Server and Device ID:  0x64
////********************************************************************
//defs




//**********************************************************************
// Created March 17, 2016
// The I2C EEPROM can only buffer 64 bytes before a stop bit has to be issued.  If not, it will overwrite the beginning data.
// Data needs to end with a \0.  If not, there is a limit on the length and a \0 will be placed.
//  Returns a 0 if successful and a 1 if there is an error.
//**********************************************************************
int WriteITwoSeeString(int16 startaddress, char* SavingData)
{
   byte addresshigh, addresslow;
   int zz,returnedchar;
   
    zz = 0;
    // Set the decoders to address the EEPROM.  It's located after all of the Sensors 
    selectsensor(6);     // This is the decoding for the EEPROM I2C
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    while(SavingData[zz]!=0)
    {
    returnedchar = (int) SavingData[zz];

    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
   
        i2c_start(PH_LIGHT);
		i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
		i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
        i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
      	i2c_write(PH_LIGHT,returnedchar);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
		i2c_stop(PH_LIGHT);
        //delay_ms(50);
        zz++;
        startaddress++;
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
      delay_ms(50);
      //  fprintf(BT,"Write high %i low %u  %c   %u\n\r",addresshigh,addresslow,returnedchar,returnedchar);
    }
    returnedchar = (int) SavingData[zz];   //save the null character
    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
   
     i2c_start(PH_LIGHT);
     i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
	 i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
     i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
     i2c_write(PH_LIGHT,returnedchar);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
     i2c_stop(PH_LIGHT);
    return(0);
}




//**********************************************************************
// Created May 18, 2016
// The I2C EEPROM can only buffer 64 bytes before a stop bit has to be issued.  If not, it will overwrite the beginning data.
// Thsi routine deletes all cha
//  Returns a 0 if successful and a 1 if there is an error.
// The inputs is only the start address.  It goes for 255 byte of 0xFFs
//**********************************************************************
int ResetEEPRROMSector(int16 startaddress)
{
   byte addresshigh, addresslow;
   int zz;
   
    // Set the decoders to address the EEPROM.  It's located after all of the Sensors 
    selectsensor(6);     // This is the decoding for the EEPROM I2C

    for (zz=0; zz < 255; zz++)
           {
    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
   
        i2c_start(PH_LIGHT);
		i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
		i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
        i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
      	i2c_write(PH_LIGHT,0xFF);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
		i2c_stop(PH_LIGHT);
        restart_wdt();   // restart the WD timer.  It set for 65 seconds 
        startaddress++;
              delay_ms(50);
       //fprintf(BT," Clearing Location  to 0xFF -> high %i low %u  \n\r",addresshigh,addresslow);
        }
    return(0);
}





//**********************************************************************
// Created March 17, 2016
// This routine reads a string of characters from the EEPROM
// A single read sets the address and then reads one location.  
//  For sequential reads to what ever length up to 0x7FFF, just doe a AUX. To stop it, send a stop bit.
// The command requires a starting address and a pointer to where the data will be left.  A \0 will signify the end of the string; just like the I2C.
// Returns a 0 if there is data present in a string.  A 1 is returned if there is an error.
//**********************************************************************
int readITwoSeeString(int16 startaddress, char* ReturnedData)
{
 
    byte addresshigh, addresslow, returnedchar;
    int x;
    char* CollectedStuff;
    
    
    CollectedStuff = ReturnedData;    // save pointer to local varible so the starting address does not get messed up.
    // Set the decoders to address the EEPROM.  It's located after all of the Sensors 
    selectsensor(6);     // This is the decoding for the EEPROM I2C
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
    // split the "start address" into two 8 bit numbers.
    
    //PH_LIGHT is the common I2C port for all of the I2C interface.
    
    	i2c_start(PH_LIGHT);
		i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
		i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
        i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
        i2c_start(PH_LIGHT);
   		i2c_write(PH_LIGHT,0xA9);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
        for (x = 0; x < 255; x++)
        {
      	returnedchar = i2c_read(PH_LIGHT,1);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
   //     fprintf(BT,"Reading high %i low %u  %c  %u\n\r",addresshigh,addresslow,returnedchar,returnedchar);
        addresslow++;   // kick to the next one to show the movement.
        CollectedStuff[x]=returnedchar;
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
        if (returnedchar == "\0")
            {
            CollectedStuff[x]="\0";
            i2c_stop(PH_LIGHT);
            return(0);
            }
        }
//fprintf(BT,"%i",ReturnedData[0]);
    i2c_stop(PH_LIGHT);   // just in case there is no other stopbit.
    return(0);
}



//**********************************************************************
// Created March 17, 2016
// This routine reads a string of characters from the EEPROM
// A single read sets the address and then reads one location.  
//  For sequential reads to what ever length up to 0x7FFF, just doe a AUX. To stop it, send a stop bit.
// The command requires a starting address and a pointer to where the data will be left.  A \0 will signify the end of the string; just like the I2C.
// Returns a 0 if there is data present in a string.  A 1 is returned if there is an error.
//**********************************************************************
int readOneEEPROMCharacter(int16 startaddress)
{
 
    byte addresshigh, addresslow, returnedchar;
  
  
    
    
    // Set the decoders to address the EEPROM.  It's located after all of the Sensors 
    selectsensor(6);     // This is the decoding for the EEPROM I2C
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
    // split the "start address" into two 8 bit numbers.
    
    //PH_LIGHT is the common I2C port for all of the I2C interface.
    
    	i2c_start(PH_LIGHT);
		i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
		i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
        i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
        i2c_start(PH_LIGHT);
   		i2c_write(PH_LIGHT,0xA9);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
      	returnedchar = i2c_read(PH_LIGHT,0);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
        i2c_stop(PH_LIGHT);   // just in case there is no other stopbit.
     //   fprintf(BT,"Single Access  address high %i address low %i  %c   %i\n\r",addresshigh,addresslow,returnedchar,returnedchar);


    return(returnedchar);   //this returns th character
}





//**********************************************************************
// Created March 17, 2016
// Modified on May 11, 2016
// This routine writes a single character to the EEPROM
// A single read sets the address and then reads one location.  
//  For sequential reads to what ever length up to 0x7FFF, just doe a AUX. To stop it, send a stop bit.
// The command requires a starting address and a pointer to where the data will be left.  A \0 will signify the end of the string; just like the I2C.
// Returns nothing
//**********************************************************************
void writeOneEEPROMCharacter(int16 startaddress, int writtendata)
{
 
    byte addresshigh, addresslow;

    char* CollectedStuff;
    
    
    // Set the decoders to address the EEPROM.  It's located after all of the Sensors 
    selectsensor(6);     // This is the decoding for the EEPROM I2C
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
    // split the "start address" into two 8 bit numbers.
    
    //PH_LIGHT is the common I2C port for all of the I2C interface.
    
    	i2c_start(PH_LIGHT);
		i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
		i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
        i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
       // i2c_start(PH_LIGHT);
   	//	i2c_write(PH_LIGHT,0xA1);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
      	i2c_write(PH_LIGHT,writtendata);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
        i2c_stop(PH_LIGHT);   // just in case there is no other stopbit.
       
        delay_ms(50);
       // fprintf(BT,"Single Access  address high %i address low %i  %c   %i\n\r",addresshigh,addresslow,writtendata,writtendata);

}