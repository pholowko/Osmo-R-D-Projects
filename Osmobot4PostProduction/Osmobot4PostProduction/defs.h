



#pin_select U1TX=PIN_B1 
#pin_select U1RX=PIN_B0 

//#use rs232(uart1, baud=9600, xmit=PIN_B1, rcv=PIN_B0, stream=BT)
#use rs232(uart1, baud=38400, xmit=PIN_B1, rcv=PIN_B0, stream=BT)


#pin_select U3TX=PIN_B15 
#pin_select U3RX=PIN_B14 
//XMIT=PIN_B15, RCV=PIN_B14,
#use rs232(uart3, baud=57600, xmit=PIN_B15, rcv=PIN_B14, stream=WIFI)



////////////////////////RS232 Interrupt//////////////////////

#define BT_BUFF_SIZE 255

int16 next_in  = 0;
int16 next_out = 0;

////////////////////////RS232 Interrupt//////////////////////

#define WIFI_BUFF_SIZE 2048


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


char scr[500];  //This is used to read files and save the string contents in it for sending to the server.  Added May 7, 2015
char SplitResult[45][20];     //This is where the result of the split in saved.  Each line has 20 character between delimiters.  Added March 25, 2015
char bt_cmd[20];  // buffer where the command is kept for parsing.  Added July 10, 2015








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
for (row = 0; row < 42; row++)
	{
	for (letterlocation=0; letterlocation < 20; letterlocation++)
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
char STA_SSID[40];     //These are the loaded router off the SD Card
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


float datatable[12];   //This is the array of data used for pH calibration.  Added June 18, 2015


