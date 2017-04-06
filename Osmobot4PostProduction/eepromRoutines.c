//*********************************************************************************************
//Created April 3, 2015
// Changed to EEPROM March 23, 2016
// This routine updates the configuration file  with the latest configureations.
//  At this time there are only items the needs to be saved:
//  Serial Number
// Router Name
// Router Password
// Additions:
//  Encriptions
//  Communcations
//  Returns a zero if all is well.
//*********************************************************************************************
int SaveConfigEE(void)
	{
char configdata[255];
int zz,x;

zz=0;
//Make a new file and save the current configurations

//compile the string to save in the file
for (x=0; x < 20; x++)
	{
	configdata[zz] = sysOutput.deviceID[x];
	if ( sysOutput.deviceID[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}

for (x=0; x < 40; x++)
	{
	configdata[zz] = STA_SSID[x];
	if ( STA_SSID[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}


for (x=0; x < 20; x++)
	{
	configdata[zz] =STA_PW[x];
	if ( STA_PW[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}


//****************************************************************************
// Added July 22, 2015
// This section adds the security and the type of Router encoding to the config.txt file.
//  STA_AUTH
//  STA_ENC
//****************************************************************************
for (x=0; x < 20; x++)
	{
	configdata[zz] =STA_AUTH[x];
	if ( STA_AUTH[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}


for (x=0; x < 20; x++)
	{
	configdata[zz] =STA_ENC[x];
	if ( STA_ENC[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}

//*****************************************End of addition  *****************************

configdata[zz]=0x7E;   //Place the tilda here to end the string
zz++;
configdata[zz]=0x00;  //End of line
	fprintf(BT,"Data before sent to routine   -> %s\r\n", configdata);
WriteITwoSeeString(0x0010, configdata);
delay_ms(2700);  // delay enough time to get the I2c information out to the EEPROM
fprintf(BT,"Displaying saved data in Configuration Location on EEPROM\n\r");
delay_ms(1700);  // delay enough time to get the I2c information out to the EEPROM
//Re-read the data and make sure it got saved.
	fprintf(BT,"%s\r\n", configdata);
	return(0);
	}




//******************************************************************************
//Created March 25, 2015
// Changed over to EEPROM May 4, 2016
// This routine makes a new configuration file if on does not exist.   Read Configureation file
//  The Osmobot configureation starting at address 0x0010  and going on for 255 characters
//  The information in the file contains the serial number of this unit and all of the instrumentation numbers from calibration.
// Format 
//
// UnitSerialNumber
// Wifi RouterName
//  Wifi Password
//******************************************************************************
void ReadConfigEEPROM(void)
	{

int returnedfileerror,x;
char tempstuff[255];
	
	returnedfileerror = readOneEEPROMCharacter(0x0010);  //Get eh first character.  if it is 0xFF, then there is no configuration.
    //fprintf(BT,"First number returned from the EEPROM %i\n\r",returnedfileerror);
	if (returnedfileerror == -1)
		{
        fprintf(BT,"Writing data to EEPROM for the first time\n\r");
        sprintf(tempstuff,"PaulsBoard,NETGEAR31,royalumbrella053,WPA2PSK,AES,~");   // save this bogus data to introduce some information when the card is not configured.
        WriteITwoSeeString(0x0010, tempstuff);
        delay_ms(50);   // make a delay to let the eeprom save the last data.
        writeOneEEPROMCharacter(0x0410, 0x00);   // Set the pointer for the address of the upload buffer to zero.  It's default is 0xFF and needs to be set to zero.  Added June 17, 2016
		}

readITwoSeeString(0x0010, scr);   // read the data what ever it is.
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015

fprintf(BT,"Configuration Raw data ->  %s\n\r",scr);
split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global variables   SplitResult[20][20];

	//	VacDisplayClear();


for (x=0; x < 20; x++)
	{
	sysOutput.deviceID[x] = SplitResult[0][x];
	if ( SplitResult[0][x] == 0)
		{
		sysOutput.deviceID[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
//sysOutput.deviceID="Eriks_Board:WTP";
//  Once it is in the array, save it in the Serial number global variable.

//  Get the SSID off the SDCard
for (x=0; x < 40; x++)
	{
	STA_SSID[x] = SplitResult[1][x];
	if ( SplitResult[1][x] == 0)
		{
		STA_SSID[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

//  Get the PW password off the SDCard
for (x=0; x < 20; x++)
	{
	STA_PW[x] = SplitResult[2][x];
	if ( SplitResult[2][x] == 0)
		{
		STA_PW[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}


//  Get the STA_AUTH off the SDCard
for (x=0; x < 20; x++)
	{
	STA_AUTH[x] = SplitResult[3][x];
	if ( SplitResult[3][x] == 0)
		{
		STA_AUTH[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}


//  Get the STA_ENC off the SDCard
for (x=0; x < 20; x++)
	{
	STA_ENC[x] = SplitResult[4][x];
	if ( SplitResult[4][x] == 0)
		{
		STA_ENC[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

 
return;
	}

//*************************************************************************
// Created May 4, 2015
// Updated and changed to EEPROM May 11, 2016
//  This routine gets the name of the next item in the buffer.  It only returns one item.
//  The returned value of the function is a good and bad.  It tells the error if there is one.
//  The global string returns the data of the record for the next item in the buffer.
//*************************************************************************

int GetNextBufferRecord(void)
{
    
    int returnedrecordaddress;
    int16 readingaddress;
 //  Here is the address of the last record placed in the buffer.
    //  Each buffer record is 255 characters longs and takes two different sequental address in memory.
    //  The first address is an even number and the second is an odd in all cases.  The begging address of the string is saved in one location in EEPROM
    returnedrecordaddress = readOneEEPROMCharacter(0x0410);  //Get eh first character.  if it is 0xFF, then there is no configuration.
    // the first 200 characters are placed in part 1 of the string.  The rest is in part 2.
    
    //  EEPROM memory map   Updated Aug 11, 2016
    //  0x0010 to 0x0020    Router configuration data
    //  0x0030 to 0x0060    EC and pH bulb calibration data
    //  0x0070 to 0x0080    Unit type string
    //  0x0110 to 0x01FF    Calibration data
    //  0x0210 to 0x02FF    Calibration data part 2
    //  0x0310 to 0x0310    Buffer Record location in memory.  If it is FF, there is nothing in the buffer to send.  253 records can be saved.
    //  0x0400 to 0x04FF    The start of the first buffer record part 1
    //  0x0500 to 0x05FF    The start of the first buffer record part 2
    //  0x0600 to 0x06FF    The start of the second buffer record part 1
    //  0x0700 to 0x07FF    The start of the second buffer record part 2   
    
    // etc...
    
    // Added Jan. 17, 2017  The buffer for downloading is only good for 100 data points in a 24 hour period.
    //  The EEPROM needs to be 2Meg chip.  Right now it's a 64K chip.
    //  The starting address for the FW has to be at B0 = 1.  It goes all the way up to the top.
    //  0x6400 is last updated line is saved in this location.  It is kicked up one for the next read.  This needs to be updated as a global varaible for the next time hitting the server.
    
    fprintf(BT,"Address of first buffer location  %u\n\r",returnedrecordaddress);
    if (returnedrecordaddress != 0x00)   // this means there is data in the buffer and it needs to be returned.
    {
        //  make the address to read
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        readITwoSeeString(readingaddress, scr);    // Get the data.
        fprintf(BT,"  First part of record (starting address) %X\n\r",readingaddress);
        fprintf(BT,"%s\n\r",scr);
        //Display_XYString(0,3, &scr);
        fprintf(BT,"  First part of record\n\r");
        
        // get the second string
        returnedrecordaddress++;  // kick the address counter to the next one.
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        readITwoSeeString(readingaddress, scr);    // Get the second data.
        fprintf(BT,"  Second part of record (starting address) %X\n\r",readingaddress);
        fprintf(BT,"%s\n\r",scr);
        //Display_XYString(0,3, &scr);
        fprintf(BT,"  Second part of record\n\r");
        return(0);  // this means the data is returned but the counter is not bumped down one.
    }
  return(1);  //  A returned 1 means there is no data ready to present.   
}



//*************************************************************************
// Created May 11, 2016
//  This routine puts the next item in the buffer.  It only returns one item.
//  The returned value of the function is a good and bad.  It tells the error if there is one.
//  The global string saves the data of the record for the next item in the buffer.
//*************************************************************************

int SaveNextBufferRecord(char* passeddata)
{
    
    int returnedrecordaddress;
    int16 readingaddress;
    char* pointertobuff;

 //  Here is the address of the last record placed in the buffer.
    //  Each buffer record is 255 characters longs and takes two different sequelntal address in memory.
    //  The first address is an even number and the second is an odd in all cases.  The begging address of the string is saved in one location in EEPROM
    returnedrecordaddress = readOneEEPROMCharacter(0x0410);  //Get eh first character.  if it is 0xFF, then there is no configuration.
    // the first 200 characters are placed in part 1 of the string.  The rest is in part 2.
    
    //  EEPROM memory map
    //  0x0010 to 0x0020    Router configuration data
    //  0x0110 to 0x01FF    Calibration data
    //  0x0210 to 0x02FF    Calibration data part 2
    //  0x0410 to 0x0410    Buffer Record location in memory.  If it is FF, there is nothing in the buffer to send.  253 records can be saved.
    //  0x0500 to 0x05FF    The start of the first buffer record part 1
    //  0x0600 to 0x06FF    The start of the first buffer record part 2
    //  0x0700 to 0x07FF    The start of the second buffer record part 1
    //  0x0800 to 0x08FF    The start of the second buffer record part 2   
    // etc...
  
 fprintf(BT,"The number of records in the current buffer at location 0x0410 is %i\n\r",returnedrecordaddress);
 
     if (returnedrecordaddress == -1)   // this means there is data in the buffer and it needs to be returned.
     {
         returnedrecordaddress = 0x00;
     }
     else
     {
         returnedrecordaddress = returnedrecordaddress+5;   // Shift it over 16 places to make the high number of the address
     }
    
//    for (x=0; x <= 200; x++)   // This goes through the first 201 locations and fills them up.  the last character is a \0.
 //   {      
//    }

    
    if (returnedrecordaddress != 0x00)   // this means there is data in the buffer and it needs to be returned.
    {
        //  make the address to read
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        readITwoSeeString(readingaddress, scr);    // Get the data.
        fprintf(BT,"  First part of record (starting address) %X\n\r",readingaddress);

        Display_XYString(0,3, &scr);
        fprintf(BT,"  First part of record\n\r");
        
        // get the second string
        returnedrecordaddress++;  // kick the address counter to the next one.
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        fprintf(BT,"  Second part of record (starting address) %X\n\r",readingaddress);
        readITwoSeeString(readingaddress, scr);    // Get the second data.
        Display_XYString(0,3, &scr);
        fprintf(BT,"  Second part of record\n\r");
        return(0);  // this means the data is returned but the counter is not bumped down one.
    }
  return(1);  //  A returned 1 means there is no data ready to present.   
}

//*********************************************************************************************
// Created May 11, 2016
// This routine removes the last record from the buffer.  It just decrements the counter by two.
//  the data is never removed from the EEPROM.
// Returns nothing.
//*********************************************************************************************
void removebufferrecord(void)
{
    
    int returnedrecordaddress;
    
     returnedrecordaddress = readOneEEPROMCharacter(0x0410);  //Get eh first character.  if it is 0xFF, then there is no configuration.
     if (returnedrecordaddress != 0x00)
     {
         returnedrecordaddress--;  // kick it down by two
         returnedrecordaddress--;
         
         if (returnedrecordaddress == 0)  // if the number is zero or there is nothing in the buffer, set it to FF for indicating there is nothing in the buffer.
         {
             returnedrecordaddress=0xFF;  
         }
         // save the number back into memory.
        writeOneEEPROMCharacter(0x0410, returnedrecordaddress); 
     }
}   



//****************************************************************************
// Created June 7, 2016
// This routine displayes the current status of the upload buffer.  It does not cange the contents nor does any uploading.  It's called by the
// BT routines to check what is working.
//  It returns nothing.
//****************************************************************************
void dipslaybufferstatus(void)
{
    
    int x,returnedrecordaddress;
    int16 readingaddress;
     // find the number of records in the current buffer.
    returnedrecordaddress = readOneEEPROMCharacter(0x0410);  //Get eh first character.  if it is 0xFF, then there is no configuration.
    fprintf(BT,"The number of records in the current buffer at location 0x0410 is %i\n\r",returnedrecordaddress);
    
    // THis section shows all of the data waiting to be sent to the server.
    for (x=returnedrecordaddress; x >= 0; x=x-2)
    {
        
       fprintf(BT,"RecordNumber - > %i\n\r",x); 
        
       if (returnedrecordaddress != 0x00)   // this means there is data in the buffer and it needs to be returned.
    {
        //  make the address to read
           returnedrecordaddress = 5 + x-1;
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        readITwoSeeString(readingaddress, scr);    // Get the data.
        Display_XYString(0,3, &scr);
        fprintf(BT,"  First part of record (starting address) %X\n\r",readingaddress);
        
        // get the second string
        returnedrecordaddress = 5 + x;  // kick the address counter to the next one.
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        readITwoSeeString(readingaddress, scr);    // Get the second data.
        Display_XYString(0,3, &scr);
        fprintf(BT,"  Second part of record  (starting address) %X\n\r",readingaddress);
        
    }
    }
       
    
    
}


//*********************************************************************
// Created June 7, 2016
// This routine deletes all of the contents of the buffer and resets the counter/pointer to the locations in the buffer.
// It displays all of the information removed and returns nothing.
//*********************************************************************
void clearbuffer(void)
{
    
    int x,returnedrecordaddress;
    int16 readingaddress;
     // find the number of records in the current buffer.
    returnedrecordaddress = readOneEEPROMCharacter(0x0410);  //Get eh first character.  if it is 0xFF, then there is no configuration.
    fprintf(BT,"The number of records in the current buffer at location 0x0410 is %i\n\r",returnedrecordaddress);
    
    
    //writeOneEEPROMCharacter(0x0410, 0xFF);
    
    
    // THis section shows all of the data waiting to be sent to the server.
    for (x=returnedrecordaddress; x >= 0; x=x-2)
    {
        
       fprintf(BT,"RecordNumber - > %i\n\r",x); 
        
       if (returnedrecordaddress != 0xFF)   // this means there is data in the buffer and it needs to be returned.
    {
        //  make the address to read
        returnedrecordaddress = 4 + x-1;
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        readITwoSeeString(readingaddress, scr);    // Get the data.
        Display_XYString(0,3, &scr);
        fprintf(BT,"  First part of record (starting address) %X\n\r",readingaddress);
        
        ResetEEPRROMSector(readingaddress);
        fprintf(BT,"First part of record removed \n\r");
        readITwoSeeString(readingaddress, scr);    // Get the data.
        Display_XYString(0,3, &scr);
        // get the second string
        returnedrecordaddress = 4 + x;  // kick the address counter to the next one.
        readingaddress = returnedrecordaddress << 8;   // Shift it over 16 places to make the high number of the address
        readITwoSeeString(readingaddress, scr);    // Get the second data.
        Display_XYString(0,3, &scr);
        fprintf(BT,"  Second part of record  (starting address) %X\n\r",readingaddress);
        
        ResetEEPRROMSector(readingaddress);
        fprintf(BT,"Second part of record removed \n\r");
        readITwoSeeString(readingaddress, scr);    // Get the data.
        Display_XYString(0,3, &scr);
    }   
    }   
    
}





//******************************************************************************
//Created Aug 11, 2016
//This routine reads the unit type from the EEPROM.  If it has nothing recogniable, it puts in a default of HD. 
//Theses are the options for the unit type.  There are three unit types, HD, AQ and AC
//******************************************************************************
void ReadunittypeEEPROM(void)
	{

int returnedfileerror,x;
char tempstuff[255];
	
	returnedfileerror = readOneEEPROMCharacter(0x0070);  //Get the first character.  if it is 0xFF, then there is no configuration.
    //fprintf(BT,"First number returned from the EEPROM %i\n\r",returnedfileerror);
	if (returnedfileerror == -1)
		{
        fprintf(BT,"Writing unit type to EEPROM for the first time.  Default is HD.\n\r");
        sprintf(tempstuff,"HD,~");   // save this bogus data to introduce some information when the card is not configured.
        WriteITwoSeeString(0x0070, tempstuff);
        delay_ms(50);   // make a delay to let the eeprom save the last data.
      //  writeOneEEPROMCharacter(0x0410, 0x00);   // Set the pointer for the address of the upload buffer to zero.  It's default is 0xFF and needs to be set to zero.  Added June 17, 2016
		}

readITwoSeeString(0x0070, scr);   // read the data what ever it is.
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015

fprintf(BT,"Unit Type ->  %s\n\r",scr);
//split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global variables   SplitResult[20][20];


for (x=0; x < 3; x++)
	{
	sysInput.unittype[x] = scr[x];
	if ( scr[x] == ',')
		{
		sysInput.unittype[x]=0x00;  //This is the end of string for the unit type
		break;
		}
	}
return;
	}

//******************************************************************************
// Created Jan 18, 2017
// this routine reads FW lines from the EEPROM.  It returns it in some array to be determined.
// The passed variable is the line number to be checked.
// *****************************************************************************
void readFWline(int fwlinenumber)
{
    
    
}



//******************************************************************************
// Created Jan 17, 2017
// This routine determines if the current firmware is current. or it needs to be updated.
// A 0 returned means the current installed FW is not current and needs to be updated.
// A 1 means nothing needs to be done.
//
//******************************************************************************
int currentFW(void)
{
    
    return(0);  // this means the FW needs to be downloaded.  It's a place marker for now.
}


//******************************************************************************
// Created Jan 17, 2017
// This routine saves one line of data into FW eeprom section.  It also saves the line number and the version somehow
//  A 1 is returned if it failed.
//A 0 is returned if it saved correctly.  This means it read the line over and confirmed.
// The default array of chars is uffit.  This routine needs to be called quicly after uffit is filled.  This is a general purpose array of char.
//******************************************************************************
int writeFWline(void)
{
    
   byte addresshigh, addresslow;
   int zz,returnedchar,xx;
   char stringnumber[6];  // this is the temp string for the string index number.
   int32 startaddress;   // this is the internal calculated starting address in 2 meg memory.
   
    zz = 0;
    returnedchar = 0;
    // isolate the line number into a varaible
    // take the first few characters off the string to get the first number.  The first number is the string number.  It starts after the "~"  and ends with a ":"
    // loop through the string to find the number and end with a null.
    for (xx=0; uffit[xx] != atoi(':'); xx++)  // once the loop hits a ':', then is exits.
    {
        if (returnedchar == 1)
        {
            stringnumber[zz] = uffit[xx];  // move the numberical character into the string array.
            zz++;  // kick the counter to the next location and place a null there.
            stringnumber[zz] = 0x00;   // this will be the end of the string until something else replaces it.
        }
        if (atoi(uffit[xx]) == atoi('~'))
        {
             returnedchar = 1;
        }  
    }
   
    startaddress = atol(stringnumber);   // change the string to a number that is the index number for the line of code.
    returnedchar = (int)startaddress;
    startaddress = startaddress * 44;   // this calculates the location of the first address for the string dependent on the line number.  the line number starts with 0.
    // this means the first line starts at 
    
    // find the location address for this line of code
    // Since the new EEPROM chip is still not installed, we are starting on block B0 and going up.  This starts at address zero in Block B0 = 1.
    
    //************************************************************************
    // Created Jan 18, 2017
    // Memory map for hex file.
    // The input from the web server is hex ascii code.  This needs to be translated into 8 bit byte to put into EEPROM
    //  The general length of the string is around 44 characters.  I think.
   
    // Set the decoders to address the EEPROM.  It's located after all of the Sensors 
    selectsensor(6);     // This is the decoding for the EEPROM I2C
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
    while(uffit[zz]!=0)
    {
    returnedchar = atoi(uffit[zz]);

    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
   
        i2c_start(PH_LIGHT);
		i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is B0 = 1.  Or the addition of 0xA8
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
    returnedchar = atoi(uffit[zz]);   //save the null character
    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
   
     i2c_start(PH_LIGHT);
     i2c_write(PH_LIGHT,0xA8);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is B0 = 1.  Or the addition of 0xA8
	 i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
     i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
     i2c_write(PH_LIGHT,returnedchar);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
     i2c_stop(PH_LIGHT);

      
    // save the data at that location
    
    // confirm the writing.
    
    
    // update the currently downloaded line range
    startaddress = 0x6400;   // this is the location for the last updated line.
    returnedchar = (atoi(stringnumber));   //save the next line number to be downloaded from the server.
    returnedchar++;
    if (returnedchar == 255)
           returnedchar = 0x00;   // to zero for now 
    blocklocation = returnedchar;
    addresshigh = make8(startaddress,1);
    addresslow = make8(startaddress,0);
   
     i2c_start(PH_LIGHT);
     i2c_write(PH_LIGHT,0xA0);  //The command for the I2C is 0XAx.  The "A" is always present.  The 1 means it's a read.  A 0 is a write.  The address block is 0
	 i2c_write(PH_LIGHT,addresshigh);  //Send the high address byte
     i2c_write(PH_LIGHT,addresslow);  //Send the low address byte
     i2c_write(PH_LIGHT,returnedchar);   // read the data with an ACK.  The "1" means it sends an ACK.  A 0 means it does not.
     i2c_stop(PH_LIGHT);

    // send back the confirmation.   
         return(0);
}