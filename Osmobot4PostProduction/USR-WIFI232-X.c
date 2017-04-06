

#ifdef PIC24

#INT_RDA3
void RDA3_isr()
{
   int8 t;
  // output_High(PIN_D1);
   buffer[next_in] = fgetc(WIFI);
   t = next_in;
   next_in = (next_in+1) % sizeof(buffer);
   if(next_in == next_out)
		{
      	next_in=t;        // Buffer full !!
		}

	//ADDED Crap
	if(next_in==WIFI_BUFF_SIZE)
	{
		next_in=0;
	}	
	//ADDED Crap
	if(next_out==WIFI_BUFF_SIZE)
	{
		next_out=0;
	}

}


//****************************************************************
// Created July 29, 2015
//  This routing will send out a string to the WIFI chip and receive and ACK.
// There are two parameters are passed through the funtcion.  They are pointers.
// The first one is the string to send to the WIFI chip.  The second is the require ACK string that needs to be returned from the
// WIFI to make sure it understands the input.  The function returns a series of error numbers, but when there is
// no error, it returns a zero.
// The routine does not call anything else for allowing interlacing processes.  Timeout occures in this routine for failed responces.
//  Error codes:
//	0     no error
//****************************************************************
int SendWiFICommand(char* sendingstring, char* receivingstring)
	{

	int c;  // This is the input character.
    int junk,returnedcounter;
	int16  timeoutcounter = 65000;   //This is set to the high number and is then counted down to nothing.
    char retstring[100];
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
//  Clear out characters in the buffer at the current time.
	while(1)
		{
		junk = Paulbgetc();
		if (junk == 0xFFFE)
			{
			break;
			}
		}
;   // When the return charactrer is a blank, get out.

// Send out the required string.

	fprintf(WIFI,"%s",sendingstring);   // this sends the string to the WIFI modcule.

	returnedcounter = 0;  //Set to the beginning of the array.
	retstring[returnedcounter] = 0x00;   // Place a null to signify the end of a string.

	while(timeoutcounter)   // Wait until you get all of the required chararacters back from the WIFI; or timeout and send the error flag.
		{
		timeoutcounter--;
        delay_us(120);   //Set up some delay to allow the WIFI to come back with some thing.
// get characters from WIFI
		c = Paulbgetc();
		if (c != 0xFFFE)    // If there is a good character, place it in the buffer and compare it to the ACK string.
			{
			retstring[returnedcounter] = c;   //Place the character into the array.
			returnedcounter++;   // Kick the counter and put a null at the end.
			retstring[returnedcounter] = 0x00;   // Place a null to signify the end of a string.

		// Check to see if the result string is equal to the ACK string.
			if (stricmp(receivingstring, &retstring)==0)
         		return(0);
			}
		}
	return(1);  // This is the timeouit value for the wrong string sent back.  The execption needs to be handled.
	}


//********************************************************************************
// Created Aug 6, 2015
// This routine sends a string to the WiFi in command mode and then returns the response in the "char* receivingstring"  part of the argument.  It's just an address
//  passed back and forth.  The array needs to be 100 characters in lengeth.  It can be a local.
//********************************************************************************



int SendWiFIquestion(char* sendingstring, char receivingstring[])
	{

	int c;  // This is the input character.
    int junk,returnedcounter;
	int16  timeoutcounter = 65000;   //This is set to the high number and is then counted down to nothing.
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
//  Clear out characters in the buffer at the current time.
	while(1)
		{
		junk = Paulbgetc();
		if (junk == 0xFFFE)
			{
			break;
			}
		}
;   // When the return charactrer is a blank, get out.

// Send out the required string.

	fprintf(WIFI,"%s",sendingstring);   // this sends the string to the WIFI modcule.

	returnedcounter = 0;  //Set to the beginning of the array.
	receivingstring[returnedcounter] = 0x00;   // Place a null to signify the end of a string.

	while(timeoutcounter)   // Wait until you get all of the required chararacters back from the WIFI; or timeout and send the error flag.
		{
		timeoutcounter--;
        delay_us(120);   //Set up some delay to allow the WIFI to come back with some thing.
// get characters from WIFI
		c = Paulbgetc();
		if (c != 0xFFFE)    // If there is a good character, place it in the buffer and compare it to the ACK string.
			{
			
			receivingstring[returnedcounter] = c;   //Place the character into the array.
			returnedcounter++;   // Kick the counter and put a null at the end.
			receivingstring[returnedcounter] = '\0';   // Place a null to signify the end of a string.

		// Check to see if the result string is equal to the ACK string.
		//	if (stricmp(receivingstring, &retstring)==0)
        // 		return(0);
			}
		}
	return(0);  // This is the timeouit value for the wrong string sent back.  The execption needs to be handled.
	}

//**************************************************************
// Created May 7, 2015
// Set up all of the pointers for the circuler buffer for the WifI and RS232.  Both the WiFI and the Bluetooth needs to be set up.
// This is also done doing the compile predefine, but it has not been always working with reset.
// *************************************************************
void SetupRSBufferPointers(void)
	{
	next_in=0;
	next_out=0;
	}

/*
void purgeBuff()
{
while(bkbhit)
	{
	char c=bgetc();
	}

}

*/

///////////////////////////
///////////////////////////
///////WIFI NONSENSE///////
///////////////////////////
///////////////////////////


void enableWIFIModule()
{
   	enable_interrupts(INT_RDA);    //This starts up s the Blue tooth module enterupt for taking in charters.  Added July 8, 2015
   	enable_interrupts(INT_RDA3);   // This starts up the WIFI chip character inputs.
//  	enable_interrupts(INT_TIMER1);            // Start RTC  
  	enable_interrupts(GLOBAL);    //and the rest.
}

//*************************************************************************
// Created December 23, 2014
// This routine returns the nLink State of the WiFi
//*************************************************************************
int8 nLinkWiFi()
	{
	int8 tempvalue;
    //This returns a 1 when the WiFi Module is n link connected.
	//get the current inputstate of the WiFi
	tempvalue = input(PIN_B8);
//	tempvalue=!tempvalue;
	return(tempvalue);
	}





//*************************************************************************
// Created December 23, 2014
// This routine returns the Ready State of the WiFi
//*************************************************************************
int8 xReadyWiFi()
	{
	int8 tempvalue;
    //This returns a 1 when the WiFi Module is ready to recevie commands.
	//get the current inputstate of the WiFi
	tempvalue = input(PIN_B11);
//	tempvalue=!tempvalue;
	return(tempvalue);
	}

//*************************************************************************
// Created December 23, 2014
// This routine resets the  WiFi device
//*************************************************************************
/*void xRST()
	{
output_high(PIN_D5);   //reset.  needs to be at least 300 ms	
//delay_ms(600);    //Delay for 600 ms to make sure
output_low(PIN_D5);
delay_ms(600);    //Delay for 600 ms to make sure
output_high(PIN_D5);   //reset.  needs to be at least 300 ms
	}*/

//////////////////////////////
//MCU WIFI MODULE FACTORY RESET
//////////////////////////////
void wifiRestore(){
#ifdef PIC24
output_high(PIN_B10);   //reload
delay_ms(8000);
output_low(PIN_B10);

#endif
}




////////////////////////////////
//WIFI SETUP
////////////////////////////////
void wifiInit(){
output_low(PIN_D5);   //reset modula
output_low(PIN_B10);  //WiFi Restore input signal - Active High
input(PIN_B11);   //This is the xReady signal
input(PIN_B8);   //This is the nLink signal
}




//////////////////////////////////////////////
//AT COMMANDS
//////////////////////////////////////////////






/////////////////////////
//Enter AT Command Mode
/////////////////////////
int WIFI_enter_setup()
	{
	int timeoutcounter;
	timeoutcounter = 0;


	if (SendWiFICommand("+++", "a"))
		{
		return(1);   //Some error
		}
	if (SendWiFICommand("a", "+ok\r\n"))
		{
		return(2);   //Some error
		}
	delay_ms(1000);   //There needs to be a delay in the commands where the WIFI can not take it too fast.
	if (SendWiFICommand("AT+E\r", "AT+E\n\r+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
		{
		return(3);   //Some error
		}

ATisOK=1;   //Set this flag to true for kicking the scripter to the next step.
return(0);
/*

return(0);*/
}



/////////////////////////
//Reset Module
/////////////////////////
void WIFI_reset()
{

	SendWiFICommand("AT+Z\r", "+ok\r\n\r\n");

{

}
//delay_ms(500);
wifisetup=1;
}




//************************************************************************************
// Updated Augest 15, 2015
// Below finds all of the routiners in the area for the Wifi.  It puts all of the data about the routers in an array for it to be selected on the webpage.
//  **********************************************************************************




int scanForRouters(void)
{


	char returningstring[1000],junkstring[10];


    char* pointer;
	int returnedresult,countie,xxx;

pointer = returningstring;   // Set the array pointer to the start address of the local array.
sprintf(junkstring,"+ok=\r\n\0");

	if (SendWiFIquestion("AT+WSCAN\r", pointer)==0)
		{
		countie = 0;
		while(junkstring[countie]=='\0');
		while(countie < 4)

			{
			if (junkstring[countie] != returningstring[countie])
				{
				return(2);  // This means there is no match.
				}
				else
				{
				countie++;
				}
			}   // if it makes it this far, it has the first set of character from the WiFi.
        for (xxx = 0; xxx < 1000; xxx++)
				delay_ms(1);   
        fprintf(BT,"%s\n\r",returningstring);   // print the returned sting on the BT.
        returnedresult = 0;
		returnedresult =  seperateRouter(pointer);    // Split the returned data into routertable
		}
// Place the list of routers and their signal streanth into the array for showing on the remote website.
}



//******************************************************************
// Added April 30, 2015
// This routine below puts in the router name.
//  There is a time delay for WiFi module time response.
//******************************************************************

void WIFI_STA_SSID()
{
fprintf(WIFI,"AT+WSSSID=%s\r",STA_SSID);
delay_ms(3000);   //Add delay here for the OK to be returned from the module.  The slower or more delay the better.  Moduules all have differnt timing.  They are cheap.

}


//*******************************************************************
// Added April 30, 2015
// Updated and Changed over to new OS Aug 6, 2015
//  ***  This assumes that unti is in Command mode.....
// This is the routines the has some delay added to it for working with the OS
// This routine also reamoves the "2" in WPA2PSK" so it will work with a router.  There is some software thing in the Wifi that does not work with "2"
//*******************************************************************

int WIFI_STA_KEY()
{

// Set up the command line from the user's SD Card.

char tempdata[30];  //This is used as a temp array for sending in varaible commands to the Wifi Chip
	sprintf(tempdata,"AT+WSKEY=%s,%s,%s\r",STA_AUTH,STA_ENC,STA_PW);
	if (SendWiFICommand(&tempdata, "\r\n\r\n"))
		{
		return(1);   //Some error 
		}

	return(0);  //this is returned when there is no error and all is well.
}



#define WFSETUPDEBUG 1
#define USETCPB 0



int WIFI_STA_CCONFIG(int1 resetConfig)
{

int returnedresult;  //This is the returned result for any function routine.  The returned number is the error.  A zero means everything is OK.

char stuffed[50];   //This is used as a temp varable for sending off commands.


//******************************************************************************8
//Created Aug 6, 2015
// This is the new routine to setup the WIFi off the SD Card varaibles.
//*******************************************************************************
delay_ms(50);
fprintf(BT,"Waiting for WiFi device to become ready.\n\r");
	while (xReadyWiFi())
		{
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
		delay_ms(100);
		BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

		}
delay_ms(2000);   // Delay to make the unit get ready.
returnedresult = WIFI_enter_setup();
if (returnedresult != 0)
	{
	return(returnedresult);
	}
fprintf(BT,"Setting up client side of Wifi for connecting to the server.\n\r");
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.


if (SendWiFICommand("AT+WMODE=STA\r", "+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
	{
	return(2);   //Some writing error
	}




//Reset the unit to make sure it's in STA mode.
WIFI_reset();
fprintf(BT,"Waiting for WiFi device to become ready.\n\r");
delay_ms(1000);
	while (xReadyWiFi())
		{
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
		delay_ms(100);
		BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

		}
delay_ms(2000);   // Delay to make the unit get ready.
returnedresult = WIFI_enter_setup();
if (returnedresult != 0)
	{
	return(returnedresult);
	}





BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+WSSSID=%s\r",STA_SSID);   // this used to be AT+WSSSIDA=  Changed Sept 14, 2015

if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
	{
	return(3);   //Some writing error
	}


BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+WAP=11BGN,OSMOBOT_%s,AUTO\r",sysOutput.deviceID);
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(5);   //Some error 
		}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+NETP=TCP,CLIENT,80,osmobot.org\r");
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(6);   //Some error 
		}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.


if (SendWiFICommand("AT+FAPSTA=on\r", "+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
	{
	return(1);   //Some writing error
	}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.




sprintf(stuffed,"AT+WAKEY=%s,%s,%s\r",STA_AUTH,STA_ENC,"osmopass");   // This used to be WSKEYA.  Changed over on Sept 14, 2015  // This is for the password while in AP mode.
	SendWiFICommand(&stuffed, "+ok\r\n\r\n");
	
	returnedresult = SendWiFICommand(&stuffed, "+ok\r\n\r\n");
/*	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(4);   //Some error in the password or the type.  Needs to move one instead of stopping.
		}

*/



sprintf(stuffed,"AT+WSKEY=%s,%s,%s\r",STA_AUTH,STA_ENC,STA_PW);   // This used to be WSKEYA.  Changed over on Sept 14, 2015  // This is the password in STA mode.
	SendWiFICommand(&stuffed, "+ok\r\n\r\n");
	
	returnedresult = SendWiFICommand(&stuffed, "+ok\r\n\r\n");
/*	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(4);   //Some error in the password or the type.  Needs to move one instead of stopping.
		}

*/


BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

//  *****************************************************************************
// Created Aug 12, 2015
// This is a good place to check for all of the local routers.
//*******************************************************************************
fprintf(BT,"Scanning for local routers.\n\r");
scanForRouters();   //Scan for routers and place them in an data array.



WIFI_reset();
fprintf(BT,"Waiting for WiFi device to become ready after client setup.\n\r");
delay_ms(1000);
restart_wdt();   // restart the WD timer.  It set for 65 seconds
	while (xReadyWiFi())
		{
		delay_ms(100);
		BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

		}
delay_ms(2000);   // Delay to make the unit get ready.
returnedresult = WIFI_enter_setup();
if (returnedresult != 0)
	{
	return(returnedresult);
	}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.


/*

sprintf(stuffed,"AT+WSKEYA=%s,%s,%s\r",STA_AUTH,STA_ENC,STA_PW);
	SendWiFICommand(&stuffed, "+ok\r\n\r\n");
	
	returnedresult = SendWiFICommand(&stuffed, "+ok\r\n\r\n");
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(4);   //Some error in the password or the type.  Needs to move one instead of stopping.
		}



fprintf(BT,"Setting up second network port for connecting to Osmobot.org.\n\r");
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
*/
sprintf(stuffed,"AT+TCPPTB=80\r");
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(7);   //Some error 
		}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+TCPADDB=osmobot.org\r");
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(7);   //Some error 
		}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+TCPTO=3\r");
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(8);   //Some error 
		}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.


sprintf(stuffed,"AT+TCPB=on\r");
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(9);   //Some error 
		}

BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

fprintf(BT,"Setting up the local server to accept connections for configurations.\n\r");

sprintf(stuffed,"AT+NETP=TCP,SERVER,8899,10.10.100.254\r");
	if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))
		{
		return(6);   //Some error 
		}


BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.



//**********************************************************************************
// End of routine
//**********************************************************************************


fprintf(BT,"Resetting Wifi Unit.\n\r");
WIFI_reset();
clientOrServer=ATCOMMAND;
fprintf(BT,"Resetting Wifi\n\rContinuing on to main lexical analyzer.\n\r");
return(0);
}



int setServer(void)//Configures WIFI module to be server
{

	int returnedresult;

WIFI_enter_setup();

	if (returnedresult != 0)
		{
		return(returnedresult);
		}
delay_ms(3000);
	if (!returnedresult)
		{
if (SendWiFICommand("AT+NETP=TCP,SERVER,8899,10.10.100.254\r", "+ok\r\n\r\n"))
	{
	return(1);  //This is an error where it does not take this command.
	}
if (SendWiFICommand("AT+WMODE=AP\r", "+ok\r\n\r\n"))
	{
	return(2);  //This is an error where it does not take this command.
	}
		fprintf(BT,"Resetting and going into AP mode.\n\r");

		}
xRST();

clientOrServer=SERVER;

	while (xReadyWiFi())
		{
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
		delay_ms(100);
//		BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

		}
return(0);
}




int setClient(void)//Configures WIFI module to be client
{
WIFI_enter_setup();

if (SendWiFICommand("AT+NETP=TCP,CLIENT,80,osmobot.org\r", "+ok\r\n\r\n"))
	{
	return(1);  //This is an error where it does not take this command.
	}
if (SendWiFICommand("AT+WMODE=STA\r", "+ok\r\n\r\n"))
	{
	return(2);  //This is an error where it does not take this command.
	}
Display_XYString(0,3,"Rebooting into STA mode");
xRST();

clientOrServer=CLIENT;
return(0);
}

//**********************************************************************
// Created Augest 19, 2015
// This routine checks to see if the Wifi is in FAPSTA or AP+STA mode.  If it is not, then there must be no connection to the server.
// If there is a connection to the server and everything is OK, then is should be in that mode. 
// If there is no connection to the server, then put the unit in AP mode to handle all of the setup stuff.  Once the setup stuff has been updated, then try to reconfig. 
// This routine returns an interger
// 0  there is a connection to the sever and all is well
// 1  it is not in AP+STA mode and needs go into AP mode.
// 2 means it never asked the question
//**********************************************************************
int isinapstamode(void)
	{

	int returnedresult;
	char returningstring[100];
    char* pointer;
	int returnvalue =2;  //This is the returned state of the WiFi returned to the calling routine.

fprintf(BT,"Waiting for WiFi device to become ready for checking AP+STA mode.\n\r");
	while (xReadyWiFi())
		{
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
		delay_ms(100);
		BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

		}

//  This routine assumes the Wifi is in transmissive mode.  It will leave it in transmisve mode when complete.
	delay_ms(10000);   // Delay to make the unit get ready.
	returnedresult = WIFI_enter_setup();

	if (returnedresult != 0)
		return(returnedresult);

		fprintf(BT,"Checking to see if Wifi went into AP+STA mode.\n\r");	
//		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

	pointer = returningstring;   // Set the array pointer to the start address of the local array.
	if (!returnedresult)
		{
	if (SendWiFIquestion("AT+TCPLKB\r", pointer)==0)
		{
		if (stricmp("+ok=on\r\n\r\n", returningstring)==0)
			{
         	returnvalue = 0;   // This error means the WIFI is not connected to the server in any way.  It needs to be connected or setup.
			}
		else 
			{
			returnvalue = 1;   // This unit is not in AP+STA mode.
			}
   		 }
		}
		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
		BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

if (!returnedresult)    // send the command to go back into transparent mode.
	{
	SendWiFIquestion("AT+ENTM\r", pointer);
	}

	return(returnvalue);
	}

//******************************************************************
// Created May 6, 2015
// Updated and Changed on Aug 6, 2015
//  This is updated to the new communcations and setup for the newer version of Wifi.  
// This program assumes the Wifi module is in transmissive mode like after a reset.
// Check to see if the WifI is connected to the internet in STA mode.
// A 1 is returned if it's connected to the internet.
// A 0 is returned if it is not connected to the internet.  That means there is no connection.
//******************************************************************
int ConnectedToInternet(void)
	{

	int timeoutcounter,result;
	timeoutcounter = 0;
	int returnvalue =0;  //This is the returned state of the WiFi returned to the calling routine.
	char returningstring[100];
    char* pointer;


	while (xReadyWiFi())
		{
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
		delay_ms(100);
		}
// Put the Wifi module into Command AT mode.
delay_ms(2000);   // wait for the WIfi to come back with responses after a reset.

result = WIFI_enter_setup();


// Send the requirest connection command.  AT+WELK
pointer = returningstring;   // Set the array pointer to the start address of the local array.
if (!result)
	{
	if (SendWiFIquestion("AT+WSLK\r", pointer)==0)
		{
		if (stricmp("+ok=Disconnected\r\n\r\n", returningstring)==0)
//		if (stricmp(returningstring, "+ok=Disconnected")==0)
         		returnvalue = 3;   // This is not an error; means the WIFI is  connected to the server in any way.  
		}
		else if (stricmp("+ERR=-5\r\n\r\n", returningstring)==0)
		{
		returnvalue = 2;   // This unit is in AP mode.
		}
    }
	else
	{
	returnvalue = 1;  //This error means no answer back from the WiFI chip.
	}

		//	if (stricmp(receivingstring, &retstring)==0)
        // 		return(0);
if (!result)    // send the command to go back into transparent mode.
	{
	SendWiFIquestion("AT+ENTM\r", pointer);
	}

//		next_in = next_out;  // Throuw out the rest of the characters.
		ATisOK=0;  //This clears the response to it can allow parsing.

	return(returnvalue);
	}


//*****************************************************************************
// Created Augest 25, 2015
// Added Oct 30, 2015
// Save the returned time and date if there is something coming back.  This should be good for first and later contacts to the server for saving data to the SD Card.
// This routine sends a requiest to the server to see if it gets anything back.
// A preset of data connection is setup to tickle the server and see if there is anything coming back.  Once there is some sort of ACK, it sets the SDCardResults = 0.
// It returns the state
//*****************************************************************************
int ServerUp(void)
	{


	for (int x=1; x < 10; x++)   // Try to send the text four times and then quit.
	{

//	fprintf(WIFI,"GET /welcomeyou.php?name=Crab$La Titular$21:15:14$2015-08-13$-0.978380$17.472433$6.500000$-7.113543$20.000000$9002.095703$0.000000$0$200.000000$65535$65535$65535$65535$0.000000$142.702133&chksm=183 HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",);
	fprintf(WIFI,"GET /welcomeyou.php?name=ACK HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",);
	fprintf(BT,".");
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
		for (int zz=0; zz < 20000; zz++)
			{ 
              restart_wdt();   // restart the WD timer.  It set for 65 seconds.  This is added for longer server weight times.
			if (webmarshaller() == 1)   // this means the result came through.
				{
				webmarshallerpointer = 0;

//**************************************************************
//  This means the time and data is correct and needs to be update on the Osmobot.
//  If there is no time and data coming back from the server, that means no connection, then leave things along.
//**************************************************************


				StoreACKdatafromserver();
				//storeRecievedData(char strBuff[], unsigned int8 index, unsigned int8 dataSet)


				reloadTime();   //  Load the time and date from the input sysInput.hour and etc.....  This moves the time from sysinput to sysoutput
  				cleanWebPageTxtBuff();   // Clear out the buffer for the next returned data.
   	                 orLEDmessage(0x02);  // this turns off the RED led with exceptions to other errors.
				return(0);   //This means it got the correct message back
				}
			}
		}
    
    //*******************************************************************************
    //Created/Added October 29, 2016
    // If there is a timeout for a response from the server, check to see if still connected to the router.  If there is no router
    //connection and no response, then the connection is broken.  If there is a router connection and no reposne, then the packets got lost.
    
    if (xReadyWiFi())   // If a zero is returned, the means there is a connection to the router but not response.  This may mean its a bad frequency or bad router
         {                  //  Exit the program with changing the light to something other than RED.
    	 orLEDmessage(0x04);  // this turns off the RED led with exceptions to other errors.
		 return(6);   //This means it got nothing back   
         }
    else
    {    // this means the router connection is broken.
      orLEDmessage(0x01);  // this turns on the RED led with no exception considerations.
	  return(1);  //this means no connection	
	}
    }


//***************************************************************************
// Created Nov. 20, 2015
// This routine changes the internet connection from the RJ45 to the wifi and back.
// The CPU needs to be rebooted for the items to take effect.
// The returned paramter is a 0 if it's successfull.
// The input command is the coded number from the array for "on" or "off"
//***************************************************************************

int changeconnection(int commandnumber)
	{


int returnedresult;  //This is the returned result for any function routine.  The returned number is the error.  A zero means everything is OK.

char stuffed[50];   //This is used as a temp varable for sending off commands.


//******************************************************************************8
//Created Aug 6, 2015
// Updated Nov. 20, 2015
// This is the new routine to change the connection meadium between RJ45 and wifi
//*******************************************************************************
delay_ms(50);
fprintf(BT,"Waiting for WiFi device to become ready.\n\r");
	while (xReadyWiFi())
		{
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
		delay_ms(100);
//		BTBasicTest();   // Added July 13, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//		calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.

		}
delay_ms(2000);   // Delay to make the unit get ready.
returnedresult = WIFI_enter_setup();
if (returnedresult != 0)
	{
	return(returnedresult);
	}
fprintf(BT,"Changing communcations through RJ45 connector.\n\r");
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.




//**************************************************************************
//Added September 29, 2015
// Here are some commands used to force the wifi to work with only cable.
//AT+FEPTP=on<CR> Quey/set default ethernet PHY-PHY on/off 
//AT+FEPHY=on<CR> Open ethernet function permanently 
//AT+RELD<CR> Command with F need to be affective after AT+RELD
//After module reset, command effect, then will not impact by Reload
// This needs to be added into the code somehow.
//*************************************************************************


if (commandnumber == 13)    // If the resulting command is 12, then turn on the rj45 command
	{

			fprintf(BT,"Setting Internet communications to Wifi.\r\n");

if (SendWiFICommand("AT+FEPTP=on\r", "+ok\r\n\r\n"))   // Turn on the  rj45 port.
	{
	return(1);   //Some writing error
	}


//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+FEPHY=on\r");   // this used to be AT+WSSSIDA=  Changed Sept 14, 2015

if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
	{
	return(2);   //Some writing error
	}


//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+RELD\r");   // Turn on the  rj45 port.  

if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
	{
	return(3);   //Some writing error
	}

	}





	if (commandnumber == 12)     // If the resulting command is 13, then turn off the rj45 command
	{

	fprintf(BT,"Setting Internet communications to RJ45 connector.\r\n");

if (SendWiFICommand("AT+FEPTP=off\r", "+ok\r\n\r\n"))   // Turn on the  rj45 port.
	{
	return(1);   //Some writing error
	}


//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+FEPHY=off\r");   // this used to be AT+WSSSIDA=  Changed Sept 14, 2015

if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
	{
	return(2);   //Some writing error
	}


//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.
//BTBasicTest();   // Added July 10, 2015.  This routine calls the BT routine to kick it out of normal user operations into debug or whatever commmand.

sprintf(stuffed,"AT+RELD\r");   // Turn on the  rj45 port.  

if (SendWiFICommand(&stuffed, "+ok\r\n\r\n"))   // Turn off the echo so there are no extra characters to screw with.
	{
	return(3);   //Some writing error
	}

	}		





	return(0);
	}