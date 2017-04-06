

#define BT_COMMAND_SIZE 18
#define BT_NUM_COMMANDS 30     //This needs to be updated to the next command when a command is added.
#define BT_ESC_COMMANDS 4   //THis is the sequence of commands used by bluetooth for operating the terminal.
//optional: 
 int8 Year=11, Month=1, Minutes=0;  // 2011-01-01 00:00 
int8 Seconds=0; 

int btonly=0;

unsigned char bluetoothesc[BT_ESC_COMMANDS][BT_COMMAND_SIZE];




const char bluetoothcommand[BT_NUM_COMMANDS][BT_COMMAND_SIZE]=
{
   "?",      //option1=none  show help list.
   "help",     //option1=none  show help list
   "exit",   //option1=none  exit out of calibration and debug mode.
   "cal",    //option1= "the debug/cal routine wanted.
   "mode",    ///There are no options.  It shows the mode number.
   "version",    //This shows the curretn software version
   "echo",      //This turns on and off echoing text from the LCD to bluetooth.
   "blversion",   //This returns the latest version of the bootloader version number.
   "chup",       //This command tells the osmobot to go online and find the latest version of FW.
   "wifiterm",    // Command to go into direction connection to the WIFI module for debugging and developing the WIFI connections.  Testing also the routines for time slicing and buffer control.
   "savecal",     //  This saves the current calibrations on to the SD Card.
   "set",         // This sets the internal varables for calibration or anything to the last number.
   "senddata",        // This routine is used between bluetooth devices to share data for uploading to the server.  It is used for remote boards being a slave to master unit.  Created Augest 17, 2015
   "showconfig",     // This lists out all of the Wifi communication settings saved on the SD Card
   "showunits"       // This shows a list of the serial numbers for Osmobot units as remote units attached to this device.
   "addunit",       // This adds a unit to list of remote sensors
   "removeunit",       // This removes a unit from the list remote sensors.
   "pingserver",     // Pings the server and sends back and waits for the server to say yes or no.
   "startweb",      // Command the OSMO to go into AP mode.
   "saveconfig",       //Save the current router configuerations
   "rst",
   "autodump",        // this sends the data to the bluetooth device at a set interval.  It can only be stopped by reboot.
   "setupwifi",      //This sets up the wifi configuration, password and communcation using bluetooth.  It resets the CPU after completion.
   "showconstate",     // This command shows the last complete connection to the server.  This regardless if the router is connected.
   "openforuse",     // This removes all of the current files in the upload buffer.  It's used for debug and clearning out bad data.
   "commandmode",     // This forces the Osmobot to go only into command mode and forget trying to connect to the server.  Must use rst to get out.
   "dumpbuff",        // this shows the current media information.  It does not format it.
   "clearbuff",      //  this clears the EEPROM back to all FFs for the upload buffer
   "lamptest",          // This cycles through all of the LEDs and returns the sensor readings.  It's used for testing.
   "reseteeprom",     // This command is used to clear the EEPROM to prefactory settings
   "showunitype"       // This shows the unit type on the BT.
};

#define BT_NUM_SUBCOMMANDS 13     //This needs to be updated to the next command when a command is added.


const unsigned char bluetoothsecond[BT_NUM_SUBCOMMANDS][BT_COMMAND_SIZE]=
{
   "pph",      //Option 1, position of the pH sensors.  It displays all of the light values.
   "ta",     //Show all data from all instruments
   "do",      //   for DO
   "ph",
   "wd",  //Show the current water depth
   "phbulb",   //Changed from -> This sets up the position for the DO light pipe.  This is changed to showing current reading of the ph bulb.  May 19, 2016
   "show",     ///This command prints out all of the current calibration varaibles to see if evertyhing is OK.
   "skirt",    //  this is the command used show the full command set for Bluetooth.  If this is not correct, it shows a "users" version.  Added Augest 17, 2015.
   "ec",    //Returns constant readings from the ec measurement.
   "do2",    // This starts the program to run the DO patch with decay
   "wt",      // this displays the current water temperature
   "par",     // this displays the current water temperature
   "nh3"     // this displays the current ammonia in the water  Added Jan 19, 2016
};


#define VAR_NAMESFORSETTING 58     //Created July 22, 2015    This is the number of varaibles to be parsed for setting new values to.


const unsigned char settingvariables[VAR_NAMESFORSETTING][BT_COMMAND_SIZE]=
{
   "lowdoone",      //10 degree highest DO conentration reading
   "lowdotwo",      //10 degree mid DO conentration reading
   "lowdothree",        //10 degree lowest DO conentration reading
   "middoone",        //20 degree highest DO conentration reading
   "middotwo",    //20 degree mid DO conentration reading
   "middothree",     //20 degree lewest DO conentration reading
   "highdoone",       //25 degree highest DO conentration reading
   "highdotwo",         //25 degree mid DO conentration reading
   "highdothree",         //25 degree lowest DO conentration reading
   "phredone",      //Option 1,ph calibration value 1
   "phredtwo",      //Option 1,ph value 2
   "phredthree",        //Option 1,ph value 3
   "phredfour",        //Option 1,ph value 4
   "phredfive",    //Option 1,ph value. 5
   "phredsix",     //Option 1,ph value  6
   "phredseven",       //Option 1,ph value 7
   "phredeight",         //Option 1,ph value  8
   "phrednine",         //Option 1,ph value  9
   "bluelimit",        // Option 1, maxblue level for DO PWM feedback
   "whitelimit",        // Option 1, maxblue level for ph PWM feedback
   "blueseed",         //This is the PWM start number for DO
   "whiteseed",       //This is the PWM start number for pH
   "bluerange",         //This is the feedback range for reference light for DO
   "wd",       //This is the offset for the water depth pressure sensor.  Changed 3/2/1016
   "phoffset",       //This is the ph calibration offset
   "phredvalue",      // this is the red value of the ph offset
   "enc",             // Sets the aes for wifi
   "ssid",            // Sets the wifi router name
   "pass",            // Sets the router password
   "auth",            //  Sets the router auth
   "wthigh",           //  sets water temperature measurement high
   "wtmid",              //  sets water temperature measurement mid
   "wtlow",            //  sets water temperature measurement low
   "wtvalh",           //  sets water temperature measurement high reading/value
   "wtvalm",           //  sets water temperature measurement mid reading/value
   "wtvall",           //  sets water temperature measurement low reading/value
   "echigh",           // set the ec ppm value for high
   "ecmid",           // set the ec ppm value for mid
   "eclow",           // set the ec ppm value for low
   "ecvalh",           // set the ec input value for high
   "ecvalm",           // set the ec input value for mid
   "ecvall",           // set the ec input value for low
   "rj45",              // This command sets the default for all communications to go through the RJ45 connector and not the wifi.  This can be set to 1 or 0.  A 1 means it's connected to the RJ45.
   "lowdoreadone",      //  10 degree actual highest reading
   "lowdoreadtwo",      //10 degree actual mid reading
   "lowdoreadthree",      //10 degree actual lowest reading
   "middoreadone",      //20 degree actual highest reading
   "middoreadtwo",      //20 degree actual mid reading
   "middoreadthree",      //20 degree actual lowest reading
   "highdoreadone",      //25 degree actual highest reading
   "highdoreadtwo",      //25 degree actual mid reading
   "highdoreadthree",      //25 degree actual lowest reading
   "nh3seed",         //This is the PWM start number for nh3  Added Jan 19, 2015-    
   "sn",               // This sets the serial number for the device.  It's saved in sysOutput.deviceID     
   "phbulbgain",       // This sets the gain of the ph bulb
   "phbulb7",           // used to zero the ph bulb at a ph of 7
   "port",           // used to set and reset port lines for SSR and for clearing SSR.  The format is characters of zeros and ones.  all on -> 11,  all off -> 00 
   "unittype"         // this is used to set the unit type on this unit.  It's used in production.  Added Aug 11, 2016 
};




//*****************************************************************************
// Created July 10, 2015
// See below:
//Summary: Finds a command from the global list of commands.
//Param: A pointer to the command string.
//Returns: The command number if the command is found in the command list.
//         0xFF if the command isn't found
//*****************************************************************************

int BT_FindCommand(void)
{
   unsigned char buf[BT_COMMAND_SIZE];
   int i;

   for (i=0; i<BT_NUM_COMMANDS; i++)
   {
      strcpy(buf, &bluetoothcommand[i][0]);
      if (stricmp(buf, bt_cmd)==0)
         return(i);
   }
   return(0xFF);
}



//*****************************************************************************
// Created July 22, 2015
// See below:
//Summary: Finds a command from the global list of veraibles to set values to.
//Param: A pointer to the command string.
//Returns: The command number if the command is found in the command list.
//         0xFF if the command isn't found
//*****************************************************************************

int FindVaraiable(void)
{
   unsigned char buf[BT_COMMAND_SIZE];
   int i;

   for (i=0; i<VAR_NAMESFORSETTING; i++)
   {
      strcpy(buf, &settingvariables[i][0]);
      if (stricmp(buf, bt_cmd)==0)
      if (stricmp(buf, bt_cmd)==0)
         return(i);
   }
   return(0xFF);
}






int8 Paulbgetc(void)
{
   int8 c;
	int item;

	c = 0;
		item = sizeof(buffer)/sizeof(int8);
		item = sizeof(buffer);
   if (bkbhit)
		{
   		c = buffer[next_out];
   		next_out = (next_out+1) % sizeof(buffer); 

   		return c;	
		}
		else
		{
		return(0xFE);
		}
}




//*****************************************************************************
// Created July 10, 2015
// See below:
//Summary: Finds a command from the global list of commands.
//Param: A pointer to the command string.
//Returns: The command number if the command is found in the command list.
//         0xFF if the command isn't found
//*****************************************************************************

int BT_FindSubCommand(void)
{
   unsigned char buf[BT_COMMAND_SIZE];
   int i;

   for (i=0; i<BT_NUM_SUBCOMMANDS; i++)
   {
      strcpy(buf, &bluetoothsecond[i][0]);
      if (stricmp(buf, bt_cmd)==0)
         return(i);
   }

   return(0xFF);
}




int8 BTbuffer[BT_BUFF_SIZE];


int16 BTnext_in  = 0;
int16 BTnext_out = 0;


#INT_RDA
void RDA_isr()
{
   int8 tbt;

   BTbuffer[BTnext_in] = fgetc(BT);
   tbt = BTnext_in;
   BTnext_in = (BTnext_in+1) % sizeof(BTbuffer);
   if(BTnext_in == BTnext_out)
		{
      	BTnext_in=tbt;        // Buffer full !!
		}
	//ADDED Crap
	if(BTnext_in==BT_BUFF_SIZE)
	{
		BTnext_in=0;
	}	
	//ADDED Crap
	if(BTnext_out==BT_BUFF_SIZE)
	{
		BTnext_out=0;
	}

}

////////////////////////////////////////////////////////////

#define BTbkbhit (BTnext_in != BTnext_out)
//#define bkbhitDebug (next_in != next_outDebug)

int8 BTbgetc()
{
   int8 c;

   while(!BTbkbhit);
   c = BTbuffer[BTnext_out];
   BTnext_out = (BTnext_out+1) % sizeof(BTbuffer); 
   return c;
}

//****************************************************************************************************
//  Created July 17, 2015
//  This routines checks the circular buffer if there is a new character.  If there is none, it then leaves and returns a -1
//  If there is a good character, then returns a non-natvie character.
//****************************************************************************************************

int8 PaulBTbgetc(void)
{
   int8 c;
	int item;
		item = sizeof(BTbuffer);
   if (BTbkbhit)
		{
   		c = BTbuffer[BTnext_out];
   		BTnext_out = (BTnext_out+1) % sizeof(BTbuffer); 
   		return c;
		}
		else
		{
		return(0xFE);
		}
}




//***************************************************************************
// Created July 10,2015
// Updated Augest 17, 2015
// Added a feature where one a subset of the commands can be see for users.  
// Help prints on the bluetooth screen when the word "help" or "?" is typed in and followed by a CR.
// Returns nothing.  Bluetooth needs to be preconnected before it can be viewed.
// Here is a list of the current commands:  
// (Note: for a command to officeally added, it need to be first added to this list then called.  ALL COMMANDS ARE SORTED ALPHABETILY BY THE FIRST LETTERS OF THE COMMAND)
// Command:				Notes:				
// --------------------------------------------------------------------------	
// exit					excapes out of any debugging or calibration program into normal download.  This is default when the unit is turned on.
// help					print a list of all possible commands
// ?       				print a list of all possible commands
//***************************************************************************
void blueboothhelp(int usernunmber)
	{
	fprintf(BT,"OSMOBOT Bluetooth command summary - Updated July 23, 2015\r\n");
	fprintf(BT,"blversion        -Displays the bootloader version.\r\n");
	fprintf(BT,"setupwifi        -Setup Wifi using Bluetooth connection.\r\n");

	if (usernunmber)
		{

		fprintf(BT,"cal xxx          -starts calibration program - choices:\r\n");
		fprintf(BT,"                    pph - Display all colors for pH\r\n");
		fprintf(BT,"                    ta - Test all sensors\r\n");
		fprintf(BT,"                    do - Test DO (Dissolved Oxygen for color intensity)\r\n");
		fprintf(BT,"                    ph - Test pH (Power of Hydrogen)\r\n");
		fprintf(BT,"                    wd - Shows the current water depth.\r\n");
		fprintf(BT,"                    ec - Shows the current electrical conductivity.\r\n");
		fprintf(BT,"                    show - Prints to the screen all of the current calibration variables.\r\n");
		fprintf(BT,"                    do2 - Test DO (Dissolved Oxygen for decay).\r\n");
		fprintf(BT,"                    wt - Show the current water temperature and raw data.\r\n");
		fprintf(BT,"                    par - Show the current raw data for light sensor and the PAR.\r\n");
		fprintf(BT,"                    nh3 - Show the current raw data for light sensor and the NH3\r\n");
        fprintf(BT,"                    phbulb - Shows the raw and calculated readings for the ph bulb\r\n");

		fprintf(BT,"chup             -Checks on the Internet for the lastest version of FW.\r\n");
		fprintf(BT,"echo             -Toggles echoing the commands on the LCD to BlueBooth.\r\n");
		fprintf(BT,"exit             -Excapes out of any debugging or calibration program into normal download.\r\n");
		fprintf(BT,"help             -Prints a list of all possible commands.\r\n");
		fprintf(BT,"mode             -Displays the current Debug and Cal mode.  If not in mode, then 0.\r\n");
		fprintf(BT,"savecal          - Saves the current instrumentation calirations.  This is used by automation.  Password TBD.\r\n");
		fprintf(BT,"saveconfig       - Saves the current Internet/router connections.  This is used by automation.  Password TBD.\r\n");

		fprintf(BT,"set xxx number   - Sets a new number for a variable.  It is not automatically saved in EEPROM.\r\n");
		fprintf(BT,"                      lowdoone - Set DO low red color.\r\n");     //Option 1,ph value
		fprintf(BT,"                      lowdotwo - Set DO low green color.\r\n");       //Option 1,ph value
		fprintf(BT,"                      lowdothree - Set DO low blue color.\r\n");         //Option 1,ph value
		fprintf(BT,"                      middoone - Set DO med red color.\r\n");         //Option 1,ph value
		fprintf(BT,"                      middotwo - Set DO med green color.\r\n");     //Option 1,ph value.
		fprintf(BT,"                      middothree - Set DO med blue color.\r\n");     //Option 1,ph value
		fprintf(BT,"                      highdoone - Set DO high red color.\r\n");      //Option 1,ph value
		fprintf(BT,"                      highdotwo - Set DO high green color.\r\n");         //Option 1,ph value
		fprintf(BT,"                      highdothree - Set DO high blue color.\r\n");         //Option 1,ph value

		fprintf(BT,"                      lowdoreadone - Set DO @ 10 degrees one \r\n");     //Option 1,ph value
		fprintf(BT,"                      lowdoreadtwo - Set  DO @ 10 degrees two \r\n");       //Option 1,ph value
		fprintf(BT,"                      lowdoreadthree - Set  DO @ 10 degrees three .\r\n");         //Option 1,ph value
		fprintf(BT,"                      middoreadone -  Set DO high number for 20 degrees C one.\r\n");         //Option 1,ph value
		fprintf(BT,"                      middoreadtwo - Set DO high number for 20 degrees C two.\r\n");     //Option 1,ph value.
		fprintf(BT,"                      middoreadthree - Set DO high number for 20 degrees C three.\r\n");     //Option 1,ph value
		fprintf(BT,"                      highdoreadone - Set DO high number for 25 degrees C one. \r\n");      //Option 1,ph value
		fprintf(BT,"                      highdoreadtwo - Set DO high number for 25 degrees C two. \r\n");         //Option 1,ph value
		fprintf(BT,"                      highdoreadthree - Set DO high number for 25 degrees three C. \r\n");         //Option 1,ph value

		fprintf(BT,"                      phredone - Set pH calibration reading 1.\r\n");     //Option 1,ph value
		fprintf(BT,"                      phredtwo - Set pH calibration reading 2.\r\n");       //Option 1,ph value
		fprintf(BT,"                      phredthree - Set pH calibration reading 3.\r\n");         //Option 1,ph value
		fprintf(BT,"                      phredfour - Set pH calibration reading 4.\r\n");         //Option 1,ph value
		fprintf(BT,"                      phredfive - Set pH calibration reading 5.\r\n");     //Option 1,ph value.
		fprintf(BT,"                      phredsix - Set pH calibration reading 6.\r\n");     //Option 1,ph value
		fprintf(BT,"                      phredseven - Set pH calibration reading 7.\r\n");      //Option 1,ph value
		fprintf(BT,"                      phredeight - Set pH calibration reading 8.\r\n");         //Option 1,ph value
		fprintf(BT,"                      phbluehigh - Set pH calibration reading 9.\r\n");         //Option 1,ph value
		fprintf(BT,"                      bluelimit - Sets the max PWM level for DO.\r\n");         //Option 1,ph value
		fprintf(BT,"                      phlimit - Sets the max PWM for pH.\r\n");         //Option 1,ph value
		fprintf(BT,"                      blueseed - Sets the starting seed PWM for DO.\r\n");         //Option 1,ph value
		fprintf(BT,"                      whiteseed - Sets the starting seed PWM for pH.\r\n");         //Option 1,ph value
		fprintf(BT,"                      bluerange - Sets the tolerance range reference light for DO.\r\n");         //Option 1,ph value
		fprintf(BT,"                      wd - Sets the offset for the pressure sensor.  Make sure the tube is out of the water.\r\n");         //Option 1,ph value

		fprintf(BT,"                      phoffset - Sets the sliding scale offset for pH.  This is a pH number value.  This works with phredvalue.\r\n");         //Option 1,ph value
		fprintf(BT,"                      phredvalue - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value

		fprintf(BT,"                      wthigh - Sets water temperature measurement high.\r\n");         //Option 1,ph value
		fprintf(BT,"                      wtmid - Sets water temperature measurement mid.\r\n");         //Option 1,ph value
		fprintf(BT,"                      wtlow - Sets water temperature measurement low.\r\n");         //Option 1,ph value
		fprintf(BT,"                      wtvalh - Sets water temperature measurement high reading/value.\r\n");         //Option 1,ph value
		fprintf(BT,"                      wtvalm - Sets water temperature measurement mid reading/value.\r\n");         //Option 1,ph value
		fprintf(BT,"                      wtvall - Sets water temperature measurement low reading/value.\r\n");         //Option 1,ph value
		fprintf(BT,"                      echigh - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value
		fprintf(BT,"                      ecmid - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value
		fprintf(BT,"                      eclow - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value
		fprintf(BT,"                      ecvalh - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value
		fprintf(BT,"                      ecvalm - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value
		fprintf(BT,"                      ecvall - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value

		fprintf(BT,"                      phbulbgain - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value
		fprintf(BT,"                      phbulb7 - Sets the red value for the sliding scale for pH. Works with phoffset.\r\n");         //Option 1,ph value
		fprintf(BT,"                      port - This turns on and off ports.  All on is 11  All off is 00\r\n");         //Added June 29, 2016





		fprintf(BT,"                      enc  - Sets the Wifi Encoder (ie. enc   AES).\r\n");         //Option 1,ph value
		fprintf(BT,"                      ssid  - Sets the Wifi Router ID Name.\r\n");         //Option 1,ph value
		fprintf(BT,"                      pass  - Sets the Wifi Password. Minimum of 8 characters.\r\n");         //Option 1,ph value
		fprintf(BT,"                      auth  - Sets the Wifi Auth. (i.e. auth WPAPSK)\r\n");         //Option 1,ph value
 		fprintf(BT,"                      nh3seed  - Set the PWM level for NH3\r\n");         //Option 1,ph value
 	    fprintf(BT,"                      rj45 - This sets the default for all Internet communications to go through RJ45 connector. This can be set to 1 or 0.  A 1 means it's connected to the RJ45.  \r\n");         //turns on and off the rj45 connection


		}
	fprintf(BT,"version          - Shows the current software version\r\n");
	fprintf(BT,"showconfig       - Shows the current settings for the Wifi saved in the SD Card.\r\n");
	fprintf(BT,"showunits        - Shows the current list of OsmoBot serial numbers for remote units attached to this device saved in the SD Card.\r\n");
	fprintf(BT,"addunit          - Adds an OsmoBot serial number for remote units attached to this device saved in the SD Card.\r\n");
	fprintf(BT,"removeunit       - Removes OsmoBot and serial number for remote units attached to this device saved in the SD Card.\r\n");
	fprintf(BT,"pingserver       - Pings server and sees if there is a direct connection to the server existing through the current setup router.\r\n");
	fprintf(BT,"startweb         - Forces unit to enter into Web Hosting Mode.\r\n");
	fprintf(BT,"rst              - Reboots unit.\r\n");
	fprintf(BT,"autodump X       - Starts reading all of the sensors and dumps to the BT one line of data delimited by commas. X is the number of minutes between dumps.\r\n");
	fprintf(BT,"showconstate     - Shows the last connection check to the server.  Use this to see if the internet provider is working.\r\n");
	fprintf(BT,"clearbuff        - Clears all of the contents of the upload buffer.  Used for clearing out bad data and starting over.\r\n");
	fprintf(BT,"commandmode      - Puts the unit in only BT command mode.  It does not try to connect to the server.  Restart the unit with the 'rst' command.\r\n");
	fprintf(BT,"dumpbuff         - Display the current upload buffer (contents) information.\r\n");
	fprintf(BT,"clearbuff        - Clears upload buffer\r\n");
	fprintf(BT,"lamptest         - Tests all LEDs and color sensors.  The returned results are the reflected light measurement for each sensor.\r\n");
	fprintf(BT,"                   This can be turned on or off.  Setting it on, the unit needs to be rst.\r\n");         //second line of help
    fprintf(BT,"showunitype      - Shows the unit type\r\n");


	if (usernunmber)
		fprintf(BT,"wifiterm         - Goes into a direction connection to WIFI from BlueTooth.  Used for debugging and testing.\r\n");
	fprintf(BT,"?                -Prints a list of all possible commands.\r\n");
	fprintf(BT,"END OF LINE\r\n");

	}


//char * BT_GetCMD(char *in)
void BT_GetCMD(void)
	{
	int8 x;
	for (x=0; x< 35; x++)
		{
		bt_cmd[x] = SplitResult[0][x];
		}
	}


//char * BT_GetCMD(char *in)
void BT_GetNextCMD(void)
	{
	int8 x;
	for (x=0; x< 35; x++)
		{
		bt_cmd[x] = SplitResult[1][x];
		}
	}





//char * BT_GetCMD(char *in)
void BT_GetLastCMD(void)
	{
	int8 x;
	for (x=0; x< 35; x++)
		{
		bt_cmd[x] = SplitResult[2][x];
		}
	}


//*********************************************************************
// Created Augest 18, 2015
// This routine gets the next token on the command line after the first command.  It returns it into bt_cmd[]
//char * BT_GetCMD(char *in)
// Note the SplitResult is set to 1, not to 2 for the third token.
//*********************************************************************
void BT_GetSecondCMD(void)
	{
	int8 x;
	for (x=0; x< 35; x++)
		{
		bt_cmd[x] = SplitResult[1][x];
		}
	}




//****************************************************************************************
// Created July 17, 2015
// This is a bluetooth and WIFI data terminal.  The bluetooth is used as an RS232 connection to the direct line to 
// WIW chips.  There are no limitations.  It's stricly used for debugging and development for the WIFI connections.
//  There are no inputs and output to this routine. The unit needs to be turned off and back on to get out of this routine.
// Building this routine tests the RS232 interupt setup and speeds.
//****************************************************************************************
void bluetoothWifiTerm(void)
	{
int cv;   //This is a dummy varible used for moving characters around.

//  Clear all buffers for the Wifi and the Bluetooth.
	next_in=0;
	next_out=0;
	BTnext_in  = 0;
	BTnext_out = 0;

	while(1)
		{
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
//  Check to see if there is anything to get from the Bluetooth side.

	cv = PaulBTbgetc();
	
//  Get is and send to the WiFI.
	if (cv != 0xFFFE)
		{
 	fprintf(WIFI,"%c",cv);
		}
//  Check to see if there is anything get from the Wifi side.

	cv = Paulbgetc();
	if (cv != 0xFFFE)
		{
	fprintf(BT,"%c",cv);
		}
//  Get it and send it to the Bluewtooth.
		}

	}




//*********************************************************************************
// Created Oct 19, 2015
//  This routine waits for a single numerical charracter to come back from the bluetooth input.  It throuws out all none-numbers and does not need a CR or LF at the end.
//  Returns the numberical value of what is pressed on the bluetooth.
//*********************************************************************************
int returnbluetoothchoice(void)
	{

int cv;   //This is a dummy veraible used for moving characters around.

	next_in=0;
	next_out=0;
	BTnext_in  = 0;
	BTnext_out = 0;

	while(1)
		{
//  Check to see if there is anything to get from the Bluetooth side.

	cv = PaulBTbgetc();
	
//  Get is and send to the WiFI.
	if (cv != 0xFFFE)
		{
		 if (isdigit(cv))
			{
		    fprintf(BT,"%c\r\n",cv);
			cv = cv - 0x30;   //Subtract the character value out.
			return(cv);   // return the value as a value, not as a character.
			}
		}
//  Get it and send it to the Bluewtooth.
		}
	}



//*********************************************************************************
// Created Oct 19, 2015
//  This routine waits for a single numerical charracter o r Escape sequence.  
//  Returns the numberical value of what is pressed on the bluetooth.
//*********************************************************************************
void printbluetooth(void)
	{

int cv;   //This is a dummy veraible used for moving characters around.

	next_in=0;
	next_out=0;
	BTnext_in  = 0;
	BTnext_out = 0;

	while(1)
		{
//  Check to see if there is anything to get from the Bluetooth side.

	cv = PaulBTbgetc();
	
//  Get is and send to the WiFI.
	if (cv != 0xFFFE)
		{
	//	 if (isdigit(cv))
	//		{
		    fprintf(BT,"%x",cv);
	//		cv = cv - 0x30;   //Subtract the character value out.
	//		return(cv);   // return the value as a value, not as a character.
	//		}
		}
//  Get it and send it to the Bluewtooth.
		}
	}


//**************************************************************************
// Created Oct. 20, 2015
// This routine listens for a password.  It uses ESC commands to edit the password from the Bluetooth device.
// A similar routine is used later to edit commands on the Bluetooth.
// There is nothing return through the function.
//  The password is set into the global varaible be itself.
// This routine does not let go to the operating system.  The OS needs to be reset after these functions are used for setting up the wifi.
//**************************************************************************
void listenforpassword(void)
	{

static int8 countcharacter;

while(1)
	{

	if(BTbkbhit){

		char cvl =BTbgetc(); 		//getWIFIChar();
		putc(cvl,BT);
//  This is a carraige return.  This section takes the line sent from the command line and places it into a string where 
//  it will be parsed into commands through the operating system.
if (cvl == 0x0D)  
	{
		putc('\r',BT);    //Send back to the terminal the CR and LF.
		putc('\n',BT);

	scr[countcharacter] = '\0';    // Insert the CR to end the command string.  
	split(&scr, " ", '\r');    //Split the command into the array of tokens.  The first location starts at 0 which is the command requested.
	scr[countcharacter] = '\0';    // Insert the CR to end the command string.  
	// return the string as inside the password varaible.
	strncpy(STA_PW,scr,strlen(scr)+1);
	return;
	}
	else
	{
	//This section adds the current typed charater to the array called "scr".  When there is a CR, it then resets to zero and parses the command line.
	scr[countcharacter]=cvl;   // Add the current character to the array; waiting for the rest of the command.
	countcharacter++;   // Kick the counter to the pointer location.
				//  Return back to the operating system to do other stuff.


//****************************************************
// Created Oct. 20, 2015
// This sections checks for ESC sequencies and then does them.
//****************************************************



	}

	}
	}	
	}





//****************************************************************************
// Created July 9, 2015
// This is the main parsing routine for call fuctions commanded by Bluetooth.  This is called when a completed
// CR and LF are found from the remote bluetooth device.  
// The output of this routine are called routines and the returned value is a -1 if there is an parsing error.
//  Return -1 if error
//  Return 0 if no error
//  The input to the function is an array of commands split into each command on each array pointer.
//  The end of the parsed line is a CR and/or LF.
// Updated/completed  July 10, 2015
// This is the main parsing routine for bluetooth.  It takes the remove commands from the Osmobot and/or the terminal and runs them.
// The inputs are as follows:
// The split command array is global and does not need to be passed.
// 
// The output are as follows:  it returns an int8 where a -1 means it failed and a 0 means it made it.
//****************************************************************************
int8 parsebluetoothcommand(void)
	{
	int stuff, ScaleLevel,routernumber,exit,choice,changefolder;
	float ClearTemp,ScaleLevelfloat;
    char arryit[255];
	BT_GetCMD();
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
	switch(BT_FindCommand())
         {
            case 0:  //help  as command "?"
			   BT_GetNextCMD();
			   debugnumber = BT_FindSubCommand();
			   if (debugnumber == 7)
						{
      					blueboothhelp(1);   // The one in the passing field indicates it's a user with the password
						}
						else
						{
						blueboothhelp(0);   //  The zero means it shows only the items for users out in the field.
						}
               break;
            case 1:  //help as in the command "help"
			   BT_GetNextCMD();
			   debugnumber = BT_FindSubCommand();
			   if (debugnumber == 7)
						{
      					blueboothhelp(1);   // The one in the passing field indicates it's a user with the password
						}
						else
						{
						blueboothhelp(0);   //  The zero means it shows only the items for users out in the field.
						}
               break;
            case 2:  //exit debug and calibration mode as in "exit"
               debugnumber = 0;    //This clears the desired routine and exits back to the main loop.  Added July 13, 2015
			   fprintf(BT,"Exiting Calibration and/or Debugging Routines.\n\r");
               break;
            case 3:  //debug and calibration mode as in "cal"
				BT_GetNextCMD();
				debugnumber = BT_FindSubCommand();
				debugnumber = debugnumber + 100;   //Offsets it so it is not confused with only single commands.
 			   fprintf(BT,"Entering into first CAL routine.  Number %i\n\r",debugnumber);
               break;
            case 4:  //What mode is the device in?
               fprintf(BT,"The current mode is:%i \n\r", debugnumber);
                break;
            case 5:  //Show software version
               fprintf(BT,"%s\n\r",version);
                break;
	        case 6:  //Toggles on and off sending text to bluetooth.
				if (toggleechoonoff == 0)  //Check the state and update it to the new value.  Added July 14, 2015
					{
					toggleechoonoff = 1;   //This means turn on the text to bluetooth
                    fprintf(BT,"Beginning to send LCD data to bluetooth\n\r");
					}
					else
					{
					toggleechoonoff = 0;
                    fprintf(BT,"Terminating to send LCD data to bluetooth\n\r");
					}
                break;
            case 7:  //Show software version
               fprintf(BT,"Boot loader version contonrol.  Not impletmeneted.\n\r");
                break;
            case 8:  //Show software version
               fprintf(BT,"Get latest FW.  Not impletmeneted.\n\r");
                break;
          	case 9:  //This goes into a bluetooth terminal program directly connected to the WiFI.  It's used for debugging.
                fprintf(BT,"Entering WIFI~Bluetooth Term.\n\r");
                fprintf(BT,"Turn the unit off and then on again to get out of this mode.\n\r");
				bluetoothWifiTerm();
                break;
            default:
           //    fprintf(BT,"\r\nUnknown Command '%s', use 'help' or '?' to get list of commands\n\r", SplitResult[0][0]);
               fprintf(BT,"\r\n>");
               break;
            case 10:  //Show software version
               fprintf(BT,"Saving current Calibrations to the SD Card.\n\r");  
#ifndef EEPROMCONFIG
                SaveCalibrations();    //Save all of the current calibrations varaibles.   cal.txt
				SaveCalibrationsTwo();   // This saves everything to the second file.    cal2.txt
#else
                SaveCalEEPROM();
                
#endif
                break;
            case 11:  //debug and calibration mode as in "set"   The numbers for the next postion are in the 200s.  updated Nov. 11, 2015
				BT_GetNextCMD();
				debugnumber = FindVaraiable();   //Get the variable name.
				debugnumber = debugnumber + 200;   //Offsets it so it is not confused with only single commands.
 			   fprintf(BT,"Setting debugnumber.  Number %i\n\r",debugnumber);
               break;
            case 12:  // this command is "senddata".  It's used to send data between bluetooth modules.  In this case it sends all current measured data.  It also includes the serical number, but not the date and time.  
					//  Created Augest 17, 2015
                    //  the data is comma delimited with a "~" at the end.  
					// it takes data from 
					sensorRead();
					stuff = (int) sysOutput.lLevelScale;
						if (stuff == 3)
   							  {
   							  ScaleLevel =  1;
     						  }
						if (stuff == 2)
 						    {
  						    ScaleLevel =  4;
  						   }
						if (stuff == 1)
 						    {
 					      ScaleLevel =  16;
  							   }
						if (stuff == 0)
 						    {
  						     ScaleLevel =  64;
  						   }
					ScaleLevelfloat = (float) ScaleLevel;
					ClearTemp = (float) sysOutput.lLevelClear;
				    ClearTemp = ClearTemp  *  8.33 * 4.5454545 * ScaleLevelfloat / 10000.0 / .769 ;

 			  fprintf(BT,"DO,%f,wtemp,%f,pH,%f,wlevel,%f,lLevelX,%f,lLevelY,%f,lLevelRed,%Lu,lLevelgreen,%Lu,lLevelBlue,%Lu,lLevelClear,%Lu,rH,%f,aTemp,%f,PAR,%f~\n\r",sysOutput.dOxy,sysOutput.wTemp,sysOutput.pH,sysOutput.wLevel,sysOutput.lLevelX,sysOutput.lLevelY,sysOutput.lLevelRed,sysOutput.lLevelGreen,sysOutput.lLevelBlue,sysOutput.lLevelClear,sysOutput.rH, sysOutput.aTemp,ClearTemp);
               break;

            case 13:  //   showconfig command

				fprintf(BT,"Unit Serial Number: %s\n\r",sysOutput.deviceID);
			    fprintf(BT,"SSID: %s\n\r",STA_SSID);
			   	fprintf(BT,"STA_AUTH: %s\n\r",STA_AUTH);
			   	fprintf(BT,"STA_ENC: %s\n\r",STA_ENC);
			   	fprintf(BT,"Paswword: %s\n\r",STA_PW);

               break;
            case 14:  //   showunits command
 			   fprintf(BT,"debugnumber  Number %i\n\r",debugnumber);
               break;
            case 15:  //   addunit command
				BT_GetSecondCMD();
 			   fprintf(BT,"debugnumber  Number %i\n\r",debugnumber);
               break;
      /*      case 16:  //   removeunit command
				BT_GetSecondCMD();
 			   fprintf(BT,"debugnumber  Number %i\n\r",debugnumber);
               break;*/
            case 16:  //   ping the server to see if there is a connection.

				// send the test GET statement
 			   fprintf(BT,"Sending testing string.\n\r");
				if (ServerUp())
					{
					fprintf(BT,"No Connection\n\r");
					}
					else
					{
					fprintf(BT,"Connection Made\n\r");
					}
               break;
            case 17:  //   Entering into web hosting mode
				// send the test GET statement
 			   fprintf(BT,"Going into Web Hosting mode.  Please wait for Wifi device to restart.\n\r");
			   setServer();
               break;
            case 18:  //   Entering into web hosting mode
				// send the test GET statement
 			    fprintf(BT,"Saving Wifi Configurations to EEPROM.  Need to restart unit to take effect.\n\r");
#ifndef EEPROMCONFIG
				SaveConfigFile("Config.txt");
#else
                SaveConfigEE();
                delay_ms(2000);
                readITwoSeeString(0x0010,arryit);
#endif         
   			   // fprintf(BT,"Booting Unit.\n\r");
				//delay_ms(3000);  // delay to allow infomration to be saved.  Added September 6, 2015
				//reset_cpu();   // resets the unit from a CPU reboot.  
               break;
           case 19:  //   Entering into web hosting mode
				// send the test GET statement
 			    fprintf(BT,"Booting Unit.\n\r");
				reset_cpu();   // resets the unit from a CPU reboot.
               break;

            case 20:  // this command is "autodump"  and then the number of minutes between dumps and readings.  It's used to send data between bluetooth modules.  In this case it sends all current measured data.  It also includes the serical number, but not the date and time.  
					BT_GetNextCMD();   // get the second number which is the minutes.
					BTMeasureTimer = atoi(bt_cmd);  
					// if this value is non-zero, it will be used to count a data dump on to the BT.

					if ((BTMeasureTimer != 0) && (BTMeasureTimer < 60))
						{
						fprintf(BT,"All data will be displayed every %i minutes\n\r",BTMeasureTimer);
						fprintf(BT,"Use the rst command to stop data dumping.\n\r");

						BTMeasureTimer = BTMeasureTimer + 1;
						}
						else
						{
						fprintf(BT,"In correct value.  The second paramater needs to be between 1 and 59 minutes.\n\rNothing is started.\n\r");
						Minutes = 1;   ///Set the minutes to one and let it count.
						Seconds = 0;   // Set to zero and allow the trigger to happen when the connections for both are correct.
						}
               break;

            case 21:  // this command is "setupwifi"  It's used to set the wifi password and configtureations using the bluetooth connection.
					//  When configuring his device, this program will hang on to the CPU and not let it go back to the operating system.  All timers are turned off.  And the CPU is reset after configuration is done.
				//setup_wdt(WDT_OFF);
				fprintf(BT,"Current Router list:\n\r");
				routernumber = 0;  // set to the first position in the router table.
				fprintf(BT,"Choice   SSID   secType   authType   Signalstreangth  maxaddress\n\r");

				while (routerTable[routernumber].sigStr	!= 0xffff)
					{
					fprintf(BT,"[%i] %s  ",routernumber,routerTable[routernumber].SSID);
					fprintf(BT,"%s  ",routerTable[routernumber].secType);
					fprintf(BT,"%s  ",routerTable[routernumber].authType);
					fprintf(BT,"%s  ",routerTable[routernumber].signalstreangth);
					fprintf(BT,"%s\n\r",routerTable[routernumber].macaddr);
					routernumber++;   // Kick to the next record/router
					}
				exit = 0;
				fprintf(BT,"\n\rPlease enter the number of the router for connection.  Do not press Enter.\n\r");
				while(exit == 0)
					{
				choice = returnbluetoothchoice();
				if ((choice >=0) && (choice < routernumber))
					{
					exit = 1;   // getout of this routine and go to the next.
					}
					else
					{
					fprintf(BT,"This not valid choice, try again.\n\r");
					}
					}



				strncpy(STA_SSID,routerTable[choice].SSID,strlen(routerTable[choice].SSID));
				strncpy(STA_AUTH,routerTable[choice].authType,strlen(routerTable[choice].authType));
				strncpy(STA_ENC,routerTable[choice].secType,strlen(routerTable[choice].secType));

				fprintf(BT,"Please enter the password for that router.  Press Enter when completed.\n\r");

				listenforpassword();


				fprintf(BT,"Unit Serial Number: %s\n\r",sysOutput.deviceID);
			    fprintf(BT,"SSID: %s\n\r",STA_SSID);
			   	fprintf(BT,"STA_AUTH: %s\n\r",STA_AUTH);
			   	fprintf(BT,"STA_ENC: %s\n\r",STA_ENC);
			   	fprintf(BT,"Password: %s\n\r",STA_PW);


				fprintf(BT,"Is this correct?  Yes/No\n\r");

			    fprintf(BT,"Saving Wifi Configurations to EEPROM.  Need to restart unit to take effect.\n\r");
#ifndef EEPROMCONFIG
				SaveConfigFile("Config.txt");
#else
                 SaveConfigEE();     
#endif

 			    fprintf(BT,"re-Booting Unit.\n\r");
				delay_ms(10000);
				reset_cpu();   // resets the unit from a CPU reboot.

               break;
            case 22:  // "showconstate" This command shows the last state for a connection to the server.  Added Nov. 11, 2015
				if (SDCardResults == 1)
					{
					fprintf(BT,"The latest data connection state to the server failed.\n\r");
					fprintf(BT,"There is a connection to the router, but the connection from the router to the server does not exist.\n\r");
					}
					else
					{
					fprintf(BT,"The latest data connection state to the server succeeded.\n\r");
					fprintf(BT,"There is a connection to the router, but the connection from the router to the server does exist.\n\r");
					}

               break;


            case 23:  // "cnot defined" This command clears out the upload buffer without taking the EEPROM out. Re-done June 17, 2016

			fprintf(BT,"Deleting and Resetting buffer in EEPROM.\n\r");
                        writeOneEEPROMCharacter(0x0410, 0x00);   // Set the pointer for the address of the upload buffer to zero.  It's default is 0xFF and needs to be set to zero.  Added June 17, 2016
            break;

		    case 24:  // "commandmode" This command only cicles through and only does commands.  Do a rst to get out.
		//	setup_wdt(WDT_OFF);
			fprintf(BT,"Switching over to command mode only. Use 'rst' to get out of the mode.");
			fprintf(BT,"You're good to go.");

			btonly = 1;   // this flag to one to kick it into this mode.
			break;


		    case 25:  // "dumpbuff" This command shows the eeprom bufferdata  on the current installed EEPROM.
			dipslaybufferstatus();
			break;


		    case 26:  // "clearbuff" Clears the current buffer of all data.
     
		    //clearbuffer();
            fprintf(BT,"Deleting and Resetting buffer in EEPROM.\n\r");
            writeOneEEPROMCharacter(0x0410, 0x00);   // Set the pointer for the address of the upload buffer to zero.  It's default is 0xFF and needs to be set to zero.  Added June 17, 2016
    
			break;

		    case 27:  // "lamptest" This command goes through all of the lamps and returns the sensor results. It's used a part of the testing automation.
               
            LEDinit();  // init the leds and resets.  Do a lamp test on Fault LED.       
            intimultiplex();
			LEDinit();  // init the leds and resets.  Do a lamp test on Fault LED.
            break;
            
            case 28:  // "resetEEPROM" This command returns all EEPROMS data location back to factory settings
            fprintf(BT,"Clearing Wifi, Serial Number and all configurations\n\r");    
			ResetEEPRROMSector(0x0010);   // Clear the Wifi configurations
            fprintf(BT,"0x0010 Completed\n\r");
            ResetEEPRROMSector(0x0110);   // Clear all cal   Added May 31, 2016
            fprintf(BT,"0x0110 Completed\n\r");
            ResetEEPRROMSector(0x0210);   // Clear all cal
            fprintf(BT,"0x0210 Completed\n\r");
            ResetEEPRROMSector(0x0310);   // Clear all cal
            fprintf(BT,"0x0310 Completed\n\r");
			break;
            
            case 29:  // "This reads the EEPROM for the current unit type.    
            ReadunittypeEEPROM();   // this reads the EEPROM.  If it's new, then it makes it a HD and displays the data.
            fprintf(BT,"Unit Type -> %s\n\r",sysInput.unittype);    
			break;
         }



	return(0);
	}





//*********************************************************************
// Updated July 10, 2015
// Below tests for a character from the bluetooth and then parses the command.  It does not run the command that is done in the 
// lexal analyzer.  
// Tokens are seperated by spaces
// Lines are teminated by CR/LF  depending on the terminal program used.
// The result returned is a -1 for fail and a 0 for OK.
//*********************************************************************


void BTBasicTest(void)
	{
	
static int8 countcharacter;

	if(BTbkbhit){

		char cvl =BTbgetc(); 		//getWIFIChar();
		if (InBTCommandmode == 0)
        {
         putc(cvl,BT);
        }
//  This is a carraige return.  This section takes the line sent from the command line and places it into a string where 
//  it will be parsed into commands through the operating system.
if (cvl == 0x0D)  
	{
    	if (InBTCommandmode == 0)
            {
		putc('\r',BT);    //Send back to the terminal the CR and LF.
		putc('\n',BT);
            }
	scr[countcharacter] = '\0';    // Insert the CR to end the command string.  
	split(&scr, " ", '\r');    //Split the command into the array of tokens.  The first location starts at 0 which is the command requested.
	countcharacter = 0;
	parsebluetoothcommand();   // Parse and execut the command(s)....
	}
	else
	{
	//This section adds the current typed charater to the array called "scr".  When there is a CR, it then resets to zero and parses the command line.
	scr[countcharacter]=cvl;   // Add the current character to the array; waiting for the rest of the command.
	countcharacter++;   // Kick the counter to the pointer location.
				//  Return back to the operating system to do other stuff.


//****************************************************
// Created Oct. 20, 2015
// This sections checks for ESC sequencies and then does them.
//****************************************************

	}

	}
}


//*****************************************************************************
// Created July 13, 2015
// This routine checks to see if a debug or cal routine is still valid.
// The number presented is the routine that it is curretnly working.  When an "exit" or another command is issued,
//  it goes to that new command the next time around in the main loop.
//*****************************************************************************
int checkbtnumber(int currentnumber)
	{

// compare the currentnumber to the global vaiable set.  if it is the same, then it returns a 1.
// if the numbers are not the same, that means the number changed in the BTBasicTest routine, it returns a zero and the routine exits.
//  There is no cleanup.  The main loop continues where it left off.

	if(debugnumber == currentnumber)
		{
		return(1);   //Return a 1 if to stay in the calibration routine.
		}
		else
		{
		return(0);   // Exit this routine and return to main loop.
		}
	}


//***************************************************************
// Created September 30, 2016
// This routine turns off the BT for configurations and for delay.
// 	output_high(PIN_B2);   // It should be put into command mode.
//  The routine returns nothing and there is no time delay.
//****************************************************************
void TurnOffBT(void)
{
       output_high(PIN_D3);    // This sets the BT to turn on.  A zero turns on the transitor for the BT.
}




///////////////////////////////////////////////////////////

void setupBT()
{


char comebackstring[100];

 

	output_high(PIN_B2);   // It should be in command mode.
    output_low(PIN_D3);    // This sets the BT to turn on.  A zero turns on the transitor for the BT.

    delay_ms(1000);   // Delay for a second	

    InBTCommandmode=1;  // this set the global varible for the BT serial port intrrupt routine to not echo characters back to the BT.
//sprintf(comebackstring,"AT+NAME=Osmobot %s\r\n",sysOutput.deviceID);

    
fprintf(BT,"AT+NAME=Osmobot %s\r\n",sysOutput.deviceID);
//SendBTCommand(comebackstring, comebackstring);
    delay_ms(1000);   // Delay for a second	
//fprintf(BT,"AT+RESET\r\n");
// delay_ms(1000);   // Delay for a second	
output_high(PIN_D3);   // turn the unit off    
output_low(PIN_B2);   // go into communication mode.
delay_ms(1000);   // wait for thee discharge gods
output_low(PIN_D3);   // turn unit back on and is in communication mode.

// Find the current serial number of the device.
//SendBTCommand("AT+NAME", comebackstring);


//Created Oct 20, 2015
//  Setup the varaibles for the array of ESC commands
// Delete command
/*
bluetoothesc[0][0] = 0x1B;
bluetoothesc[0][1] = 0x5B;
bluetoothesc[0][2] = 0x32;
bluetoothesc[0][3] = 0x34;
bluetoothesc[0][4] = 0x7E;
bluetoothesc[0][5] = 0x00;

// left arrow
bluetoothesc[1][0] = 0x1B;
bluetoothesc[1][1] = 0x5B;
bluetoothesc[1][2] = 0x41;
bluetoothesc[1][3] = 0x00;
// BS   Back Space
bluetoothesc[2][0] = 0x7F;
bluetoothesc[2][1] = 0x00;
*/
//

//output_low(PIN_B2);

//SendBTCommand("AT+RESET", comebackstring);

   InBTCommandmode=0;   //  Allow BT echo of characters
}


