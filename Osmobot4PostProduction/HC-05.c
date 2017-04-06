//************************************************************************
// Created Augest 17, 2015
// This routine sets the WiFi device into Master or Slave mode.  It depends what on what version chip is installed on the Osmobot board.
// Updated September 8 2015
// Added the command parser for lines retuened from the bluetooth device when in configuration role.
// This set of commands are seperate from the normal operation of bluetooth where it talkes with a remove bluetooth device.
// The system needs to be in this mode to connect and disconnect to a nother bluetooth device.
// It's assumed all bluetooth devices are going to be HC-05 and HC-06s are being kicked out.
//************************************************************************


//********************************************************************************
// Updated September 8, 2015
// This program is stollen from the Wifi for sending and receving commands from the BT device.
// Created Aug 6, 2015
// This routine sends a string to the WiFi in command mode and then returns the response in the "char* receivingstring"  part of the argument.  It's just an address
//  passed back and forth.  The array needs to be 100 characters in lengeth.  It can be a local.
//********************************************************************************



int SendBTquestion(char* sendingstring, char receivingstring[])
	{

	int c;  // This is the input character.
    int junk,returnedcounter;
	int16  timeoutcounter = 65000;   //This is set to the high number and is then counted down to nothing.
    char retstring[50];
//  Clear out characters in the buffer at the current time.
	while(1)
		{
		junk = PaulBTbgetc();   // get charters from BT.
		if (junk == 0xFFFE)
			{
			break;
			}
		}
;   // When the return charactrer is a blank, get out.

// Send out the required string.

	fprintf(BT,"%s",sendingstring);   // this sends the string to the WIFI modcule.

	returnedcounter = 0;  //Set to the beginning of the array.
//	receivingstring[returnedcounter] = 0x00;   // Place a null to signify the end of a string.

	while(timeoutcounter)   // Wait until you get all of the required chararacters back from the BT; or timeout and send the error flag.
		{
		timeoutcounter--;
        delay_us(120);   //Set up some delay to allow the BT to come back with some thing.
// get characters from BT
		c = PaulBTbgetc();


		if (c != 0xFFFE)    // If there is a good character, place it in the buffer and compare it to the ACK string.
			{
			
			retstring[returnedcounter] = c;   //Place the character into the array.
			returnedcounter++;   // Kick the counter and put a null at the end.
			retstring[returnedcounter] = '\0';   // Place a null to signify the end of a string.
		// Check to see if the result string is equal to the ACK string.
//			if (strstr(receivingstring, &retstring)!=0)
//			if (stricmp(receivingstring, &retstring)==0)
			}
			else
			{
			if ((stricmp(receivingstring, &retstring)==0) && (returnedcounter > 0))
         		return(0);
		
			}

		}
	return(1);  // This is the timeouit value for the wrong string sent back.  The execption needs to be handled.
	}




//********************************************************************************
// Created Sept 6, 2015
// This routine sends a string to the BT in command mode and then returns the response in the "char* receivingstring"  part of the argument.  It's just an address
//  passed back and forth.  The array needs to be 100 characters in length.  It can be a local.
//********************************************************************************



int SendBTCommand(char* sendingstring, char receivingstring[])
	{

	int c;  // This is the input character.
    int junk,returnedcounter;
	int16  timeoutcounter = 65000;   //This is set to the high number and is then counted down to nothing.
//  Clear out characters in the buffer at the current time.
	while(1)
		{
		junk = PaulBTbgetc();
		if (junk == 0xFFFE)
			{
			break;
			}
		}
;   // When the return charactrer is a blank, get out.

// Send out the required string.

	fprintf(BT,"%s",sendingstring);   // this sends the string to the WIFI modcule.

	returnedcounter = 0;  //Set to the beginning of the array.
	receivingstring[returnedcounter] = 0x00;   // Place a null to signify the end of a string.

	while(timeoutcounter)   // Wait until you get all of the required chararacters back from the WIFI; or timeout and send the error flag.
		{
		timeoutcounter--;
        delay_us(120);   //Set up some delay to allow the WIFI to come back with some thing.
// get characters from WIFI
		c = PaulBTbgetc();
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




//*************************************************************************************
// Created Sept 8, 2015
// This routine gets the BT unit out of Admin mode and into slave mode.
// It returns a 0 if all is well.
//*************************************************************************************
int EnterBTSlavemode(void)
	{



    return(0);
	}



//***************************************************************************************
// Created Sept 8, 2015
// This routine makes the BT unit into master mode.  It leaves the BT device in Admin or AT command mode.
// It returns a 0 if all is well.
// **************************************************************************************
int MakeBTMaster(void)
	{






    return(0);
	}


