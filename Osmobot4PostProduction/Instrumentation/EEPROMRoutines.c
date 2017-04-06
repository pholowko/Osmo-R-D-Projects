






//Data Structure to define Measurement output data for TCP/IP Mesages
typedef struct ConfigurationDataStruct{
char deviceID[16];

float aone;    //This is the first temp comp for DO
float atwo;    //This is the second temp comp for DO
float athree;   //This is the third temp comp for DO
float bone;     //This is the first temp comp for DO
float btwo;     //This is the second temp comp for DO
float bthree;   //This is the third temp comp for DO
float cone;     //This is the third temp comp for DO
float ctwo;    //This is the first temp comp for DO
float cthree;   //This is the second temp comp for DO
float phone;   // ph constant one
float phtwo;    // ph constant two
float phthree;  //  ph conatant three
float pk;      //  B for ph
float slope;   // m for ph

}OsmobotConfigData;
OsmobotConfigData SystemConfigData;

//*********************************************************
//  This file contains all of the routine to get, save and calcualte climte profile
//  for a 24 hour period.
//  This area also has the routines to read and save data into the I2C.
//  Create June 4, 2012
//*********************************************************

void Select_ext_eeprom(void) 
{  
	output_bit(PIN_C5,1);   //This sets the mux to postion 3  
	output_bit(PIN_C0,1);   // This is not used by the light sensors
}

BOOLEAN ext_eeprom_ready() 
{
   int1 ack;
   i2c_start();            // If the write command is acknowledged,
   ack = i2c_write(0xa0);  // then the device is ready.
   i2c_stop();
   return !ack;
}



//***********************************************************\
//Added December 18, 2012
//•n is an offset into the eeprom. 
//•For example if the first float is at 0 the second 
//•For floats you must increment it by 4. 
//•one should be at 4 and the third at 8. 
//***********************************************************

WRITE_FLOAT_EXT_EEPROM(long n, float data) { 
   int32 i;

   Select_ext_eeprom();
   for (i = 0; i < 4; i++) 
      write_ext_eeprom(i + n, *((int8*)&data + i) ) ; 
}

float READ_FLOAT_EXT_EEPROM(long n) { 
   int i; 
   float data;

   Select_ext_eeprom();
   for (i = 0; i < 4; i++) 
      *((int8*)&data + i) = read_ext_eeprom(i + n);

   return(data); 
}

//**************************************************************************
//This is all experimanetal EEPROM programming for an exterinal EEPROM.

/*void write_ext_eeprom(long int address, BYTE data)
{
   short int status;
   int lowaddress, highaddress;
   i2c_start();
   i2c_write(0xa0);  // how find this address//
   highaddress=(address>>8)&0x7f;
   i2c_write(highaddress);    // not understand//
   lowaddress = address;
   i2c_write(address);
   i2c_write(data);
   i2c_stop();
   i2c_start();
   status=i2c_write(0xa0);
   while(status==1)
   { 
      i2c_start();
      status=i2c_write(0xa0);
   }
   i2c_stop();
}

BYTE read_ext_eeprom(long int address) {
   BYTE data;
   i2c_start();
   i2c_write(0xa0);    // how find this address //
   i2c_write((address>>8)&0x7f);
   i2c_write(address);
   i2c_start();
   i2c_write(0xa1);
   data=i2c_read(0);
   i2c_stop();
   return(data);
} 

*/

//**********************************************************************************************
// Created Oct. 14, 2012
// This rouinte saves all of the control limits and other needed setpoints into memeory.  The EEPROm on the system can place up to 1 meg bits.
// The other I2C ports needs to connect to another I2C EEPROM for climate profiles.
//The required information for saving the data is listed below:
//  Address is a long and it needs to always be the same for desired saved strings
//  c is a pointer to an array where the string sits.  I needs to be ended with a null or "!" to set the end of the string.
// The return value is the length of the string.  This is also saved in the EEPROM for double checking the length of the string.
//  It's the last byte before the "!"
//**********************************************************************************************
int SaveStringInEEPROM(long address, BYTE *c)
	{

	int datacounter;
	long i;
    BYTE initchar;
	datacounter = 0; //Set this to zero for init.
	initchar = c[datacounter];
    Select_ext_eeprom();
	for (i=address; initchar != 0x21; i++)
		{
		initchar = c[datacounter];
		write_ext_eeprom(i, initchar);  //  Call the routine to save this byte in this location.
		datacounter++;
		}
//  Save the last number in EEPROM at the next address.  Save the end "!".
	i++;  // Kick counter to next location.
	write_ext_eeprom(i, datacounter);  //Save the data string length
	datacounter = 0x21;
	i++;  // Kick counter to next location.
	write_ext_eeprom(i, datacounter);   //Add the end of the string in EEPROM.

	return(datacounter);
	}

//**********************************************************************************************
// Created Oct. 14, 2012
// The purpose of this funtion is to concatinate all of the control varaibles into one long string terminated with a null or "!" character.
//The string is saved in the global string called EEBuffer.
// When the string is concatinated, it calls the EE saving routines to place the concatinated varibles into EEPROM stating 
// at address location 0x0001.
// Ther returned value is the length of the string saved in EEPROM.
//**********************************************************************************************


void SaveControlsInEEPROM(void)
	{

    float dummyfloatveriable;  //This is used as the dummy float value for each varaible.  The varaible is converted to a float and then back again.
//Created May 4, 2014
//These varaibles are saved in the interal EEPROM of the CPU chip.

    Select_ext_eeprom();  //Change the input and out mux for the EEPROM  This is shared with the Light sensors  Added May 5, 2014

//Save data in this section 
	WRITE_FLOAT_EXT_EEPROM(0x18, SystemConfigData.aone);   //Save the upper limit of temperature  It takes up 4 bytes
	dummyfloatveriable = (float) SystemConfigData.atwo;
	WRITE_FLOAT_EXT_EEPROM(0x1C, dummyfloatveriable);   //Save the lower limit of temperature  It takes up 4 bytes

//Re-read the data and save them in the current working varibles.
	SystemConfigData.aone = 0.0;
	SystemConfigData.atwo = 0.0;
	SystemConfigData.aone = READ_FLOAT_EXT_EEPROM(0x18);     //Read the upper limit of temperature  It takes up 4 bytes
	SystemConfigData.atwo = READ_FLOAT_EXT_EEPROM(0x1C);     //Read the lower limit of temperature  It takes up 4 bytes


	}



//***************************************************************
//Created December 18, 2012
// Fill all control values from EEPROM.  This reads all of the data from the EEPROM to init NV varables, but are changeable by the user.
//***************************************************************

void ReadAllEEPROMVariables(void)
	{
// So far there is one variable that is placed in EEPROM.
//The variable is Min and Max temperature.

    Select_ext_eeprom();  //Change the input and out mux for the EEPROM  This is shared with the Light sensors  Added May 5, 2014

	SystemConfigData.aone = 0.0;
	SystemConfigData.atwo = 0.0;
	SystemConfigData.aone = READ_FLOAT_EXT_EEPROM(0x18);     //Read the upper limit of temperature  It takes up 4 bytes
	SystemConfigData.atwo = READ_FLOAT_EXT_EEPROM(0x1C);     //Read the lower limit of temperature  It takes up 4 byt

	}

//**************************************************************
//Created December 18, 2012
// This routine inits the EEPROM with default values after programming from the compiler.
//**************************************************************
void InitAllEEPROMVarblesAfterProgramming(void)
	{
//  Check to see if the EEPROM is blank.  This is done by checking for the first value in the EEPROOM.  If it is zero, then init the values.
 	float dummyfloatveriable;  //This is used as the dummy float value for each varaible.  The varaible is converted to a float and then back again.
	int junk;	
    Select_ext_eeprom();  //Change the input and out mux for the EEPROM  This is shared with the Light sensors  Added May 5, 2014

	junk = read_ext_eeprom(0x0A);   // Get the updated EEPROM setting.
	

	SystemConfigData.aone = 1.123;
    SystemConfigData.atwo = 4.233;
    SaveControlsInEEPROM();
	if (junk == 0xFF)     //Read the lower limit of temperature  It takes up 4 bytes  If the EEPROM is blank, then init it. 
		{
		//Init the first time read to a non-zero byte.
		write_ext_eeprom(0x0A, 0x00);

		//Intit the Temperature control limits.
	//	ControlTemperatureUpper = 23;   //These are the starting values for the temperature control loop.
//		ControlTemperatureLower = 22;   //These are the starting values for the temperature control loop.
//		dummyfloatveriable = (float) ControlTemperatureUpper;
//		WRITE_FLOAT_EXT_EEPROM(0x10, dummyfloatveriable);   //Save the upper limit of temperature  It takes up 4 bytes
//		dummyfloatveriable = (float) ControlTemperatureLower;
//		WRITE_FLOAT_EXT_EEPROM(0x14, dummyfloatveriable);   //Save the lower limit of temperature  It takes up 4 bytes


	}	
	}
