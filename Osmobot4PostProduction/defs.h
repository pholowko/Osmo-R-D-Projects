 
#pin_select U1TX=PIN_B1 
#pin_select U1RX=PIN_B0 

#use rs232(uart1, baud=38400, xmit=PIN_B1, rcv=PIN_B0, stream=BT)


#pin_select U3TX=PIN_B15 
#pin_select U3RX=PIN_B14 
//XMIT=PIN_B15, RCV=PIN_B14,
//#use rs232(uart3, baud=57600, xmit=PIN_B15, rcv=PIN_B14, stream=WIFI)   // Changed on March 9, 2017   This is the USR wifi modem speed
#use rs232(uart3, baud=115200, xmit=PIN_B15, rcv=PIN_B14, stream=WIFI)



////////////////////////RS232 Interrupt//////////////////////

#define BT_BUFF_SIZE 128
#define I2C_SIZE 100
int16 next_in  = 0;
int16 next_out = 0;

////////////////////////RS232 Interrupt//////////////////////

#define WIFI_BUFF_SIZE 2048

int8 rec_buffer[I2C_SIZE];
int8 buffer[WIFI_BUFF_SIZE];
//int8 WFHasWritten=0;   //THis is made into a global variable to help with timeouts.  Added April 29, 2015
//int8 next_in  = 0;
//int8 next_out = 0;


//************************************************************************
// Addded Sept 2, 2015
// Global varables for decay solution
//************************************************************************
float eccalibrationy[4];    //The four numbers for the y axis or the ppm axis.
float eccalibrationx[4];    //The four numbers for the x axis or the count axis.





//******************************************************************************
// Created July 17, 2015
// This routine takes a singgle charater from the input buffer and returns it.  If there is one, it does it.  If not, it returns a -1  or 128.
//  This routine is used along side the RS232 vector intrupt routine.
// ****************************************************************************

#define bkbhit (next_in != next_out)

#define SPLIT_COMMAND_LENGTH 35
char scr[500];  //This is used to read files and save the string contents in it for sending to the server.  Added May 7, 2015
char SplitResult[45][SPLIT_COMMAND_LENGTH];     //This is where the result of the split in saved.  Each line has 20 character between delimiters.  Added March 25, 2015
char bt_cmd[50];  // buffer where the command is kept for parsing.  Added July 10, 2015   Changred to 50 from 20 on Sept 30, 2016.  User names and passwords are getting longer.








//************************************************************************************************************
// Created March 25, 2015
// This is a general parsing routine where it takes a sting and seperates it into sections with a delimiter and an end of sting.
//  The parameters going into this routine are as follows:
//  String as a pointer
//  delimiter
//  endofstring
// The output is in some array I have not figured out yet.
//  Each Item can not be more than 20 characters long
//************************************************************************************************************
void split(char *parsingstring, char *delimiter, char *EndOfLine)
	{

int counter, row, letterlocation;   //This is the row for each item.  It is bumped up one when a delimieter is found.  letterlocation is the place where the cureent charater is saved.

char  counter2,currentchar,endofchar, endoflinechar,junkcheck;
counter = 0;  //This is the start of the first location in the given string.
endoflinechar = EndOfLine[0];
for (row = 0; row < 43; row++)
	{
	for (letterlocation=0; letterlocation < 35; letterlocation++)
		{

		counter2 = delimiter[0];
		currentchar = parsingstring[counter];
		junkcheck = scr[counter];
		if (currentchar != counter2)
			{
			if (parsingstring[counter] != 0x0A)   // Added July 13, 2015.  Remove pre 0x0A from the text line.  Fixing an Apple Corporation bug to allow parsing to contine.
				{
				SplitResult[row][letterlocation]=parsingstring[counter];
				}
				else
				{
				letterlocation--;   //If it is a forbidden character, then back spaace one.
				}
			}
			else
			{
			SplitResult[row][letterlocation]=0x00;
			counter++;
			break;
			}
		counter++;
		}
 
	endofchar = parsingstring[counter];
	if (endofchar == endoflinechar)
		{
		break;
		}
	}

}


//Associated functions to automate the setup and communication with the wifi module

//#define BAUDR 115200

#define I2CDEBUG 0
char STA_SSID[64];     //These are the loaded router off the SD Card  Changed Sept 30, 2016 from 40 to 64
char STA_PW[64];     // And its password
//char STA_SSID[32]="NETGEAR31";
//char STA_PW[64]="royalumbrella053";
//char STA_AUTH[8]="WPA2PSK";
//char STA_ENC[4]="AES";
char STA_AUTH[8];
char STA_ENC[10];
//char ATBUFF[100];


//*************************************************************************
// Created December 23, 2014
// This routine resets the  WiFi device
//*************************************************************************
void xRST(void)
	{
output_high(PIN_D5);   //reset.  needs to be at least 300 ms	
delay_ms(600);    //Delay for 600 ms to make sure
output_low(PIN_D5);
	}




////////////////////////////////////////////////////////////
// Updated April 17, 2015
//This routine take characters back from the RS232 and puts them in c
// Because next_in is not equal next_out, the event occures.  It waits until something happens.  It may get stuck if the module is too slow to respond or it not working.
//*********************************************************

//#define bkbhit (next_in != next_out)
//#define bkbhitDebug (next_in != next_outDebug)

int8 bgetc()
{
   int8 c;

	c = 0;
   while(!bkbhit);
   c = buffer[next_out];
   next_out = (next_out+1) % sizeof(buffer); 
   return c;
}
    char Configuration[256];   /// This is used by the I2C EEPROM for testing.
    char Configreturn[256];   /// This is used by the I2C EEPROM for testing.
float phbulbgain;  // This is the gain for the pHbulb  Added May 19, 2016
float datatable[12];   //This is the array of data used for pH calibration.  Added June 18, 2015
int SaveConfigEE(void);
int WriteITwoSeeString(int16 startaddress, char* SavingData);
void ReadCalEEPROM(void);
int readOneEEPROMCharacter(int16 startaddress);
int readITwoSeeString(int16 startaddress, char* ReturnedData);
void writeOneEEPROMCharacter(int16 startaddress, int writtendata);
int SaveSendReadings(void);
int SaveNextBufferRecord(char* passeddata);
int ResetEEPRROMSector(int16 startaddress);
unsigned int32 UTF8Decode(char *scr);
int BTMeasureTimer = 0;   // This is the global varaible used to trigger a BT dumping a line of data on the BT connection.  If this non-zero, there is no upload to the server.
void dipslaybufferstatus(void);
void clearbuffer(void);
void DecodeWebPageCode(void);
void ReadunittypeEEPROM(void);
