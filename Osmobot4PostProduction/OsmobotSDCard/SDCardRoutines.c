

//char TokenTemp[20];    //This is the temp variable to move the array into a string
char NextBufferFileName[20];   // This only has the next file name to upload data to the server.
char NextFileName[20];   // This only has the next file name to upload data to the server. for deleting files

char CurrentFolder[65];   //This is the return of the current location of the point in the SD Card.




/////////////////////////////////////////////////////////////////////////
////                                                                 ////
////                           fat_ex.c                              ////
////                                                                 ////
////    This is a neat little shell utility that resembles a DOS or  ////
//// UNIX type shell in order to manipulate files on the FAT file    ////
//// system. This is mostly for demonstration purposes on how to use ////
//// some of the basic functionality of the FAT library.             ////
////                                                                 ////
//// Type 'help' and press enter at the console prompt to get a list ////
//// of commands.                                                    ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////
////                                                                 ////
////  Version History:                                               ////
////     FEB 14th 2011                                               ////
////        * Updated example to use Microchip's MDD library.        ////
////        * Code will not automatically init/mount file system.    ////
////           'mount' command must be performed to do this.         ////
////        * You cannot use path-names when performing file         ////
////           actions (cat, tail, append, make, del).  Instead      ////
////           you have to be in the proper directory, and file      ////
////           actions happen to files in that directory.            ////
////        * 'format' command can now have 'k', 'm' or 'g' postfix  ////
////           for size (k = 1024, m=1024*1024, etc).                ////
////        * 'info' command added.                                  ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////
////        (C) Copyright 2007 Custom Computer Services              ////
//// This source code may only be used by licensed users of the CCS  ////
//// C compiler.  This source code may only be distributed to other  ////
//// licensed users of the CCS C compiler.  No other use,            ////
//// reproduction or distribution is permitted without written       ////
//// permission.  Derivative programs created using this software    ////
//// in object code form are not restricted in any way.              ////
/////////////////////////////////////////////////////////////////////////

// define this to make it compatible with the ex_boot_ldr.c bootloader.
// otherwise don't define this.
//#define __USE_MDD_BOOTLOADER__
//#define MEDIA_SOFT_DETECT    //This means it uses talking to the card to see if there is a card present
//#define __DEBUG_UART

//#define ALLOW_GET_DISK_PROPERTIES   //used by 'info' command
#define SDCardDisplay 0    //used to show the SD Card data for calibrations.  Set to 1 for it to be displayed on the LCD.
#include "..\Osmobotsdcard\ex_mdd_common.h"

//////////////////////
///                ///
/// Useful Defines ///
///                ///
//////////////////////

#define COMMAND_SIZE 10
#define NUM_COMMANDS 13

////////////////////////
///                  ///
/// Global Variables ///
///                  ///
////////////////////////


char commands[NUM_COMMANDS][COMMAND_SIZE]=
{
   "del",      //option1=filename.  delete file.
   "make",     //option1=filename.  create an empty file, give error if file already exists
   "append",   //option1=filename, option2=string.  append string to end of file
   "cd",    //option1=new cwd.  change working directory.  / is root.
   "dir",    //show files in directory
   "cat",    //option1=filename.  display full contents in ascii
   "tail",  //option1=filename.  display the last 20 lines of file.
   "mkdir", //option1=dir.  create directory.  see 'cd' for rules on dir
   "rmdir",  //option1=dir.  remove directory.  see 'cd' for rules on dir.
   "format",   // option1=media size in bytes. formats the media.
   "help",   // help!
   "mount",  //mount filesystem.
   "info"    //get and display FS_DISK_PROPERTIES
};
#ifndef EEPROMCONFIG
int1 g_IsMounted = FALSE;

////////////////////////////////
///                          ///
/// Function Implementations ///
///                          ///
////////////////////////////////

/*
Summary: Finds a command from the global list of commands.
Param: A pointer to the command string.
Returns: The command number if the command is found in the command list.
         0xFF if the command isn't found
*/
int FindCommand(char *cmd)
{
   char buf[COMMAND_SIZE];
   int i;

   for (i=0; i<NUM_COMMANDS; i++)
   {
      strcpy(buf, &commands[i][0]);
      if (stricmp(buf, cmd)==0)
         return(i);
   }

   return(0xFF);
}

/*
Summary: Displays the current working directory.
Param: None.
Returns: None.
*/
int DisplayPrompt(void)
{
   char  *p;

   if (g_IsMounted)
   {
      p = FSgetcwd(CurrentFolder, sizeof(CurrentFolder)-1);
      if (!p)
      {
		return(1);  //This means file card in not installed.
       //  sprintf(scr, "!!!ERROR!!!");
      }
   }
   else
   {
	   return(2);  //This means file card in not installed.
      //sprintf(scr, "!!!NOT MOUNTED!!!");
   }
 //  sprintf(CurrentFolder,"\r\n\n%s> ", scr);
   return(0);
}

/*
Summary: Deletes a file.
Param: The full path of the file to delete.
Returns: None.
*/
int DeleteFile(char *fileName)
{

   if (!g_IsMounted)
   {
    //  printf("\r\nMedia not mounted, not going to delete file!");
      return(2);
   }

   //printf("\r\nDeleting '%s': ", fileName);
   if(FSremove(fileName))
   {
     // printf("Error deleting file");
 
      return(1);
   }
   //printf("OK");

	return(0);
}

/*
Summary: Creates a file.
Param: The full path of the file to create.
Returns: None.
Example Usage: \> make "Log.txt"
*/
void MakeFile(char *fileName)
{
   FSFILE *f = NULL;
   int ret;

   if (!g_IsMounted)
   {
 //     printf("\r\nMedia not mounted, not going to make file!");
      return;
   }

 //  printf("\r\nMaking file '%s': ", fileName);

   f = FSfopen (fileName, "w");
   if (!f)
   {
//      printf("Error (open error %X)", FSerrno);
   }
   else
   {
      ret = FSfclose(f);

   }

}

/*
Summary: Append a string to a file.
Param: The full path of the file to append to.
Param: A pointer to a string to append to the file.
Returns: None.
Example Usage: \> append "Log.txt" "This will be appended to the end of Log.txt"
Note: A "\r\n" will be appended after the appendString.
*/
void AppendFile(char *fileName, char *appendString)
{
   FSFILE* f;
//   char newLine[]="\r\n";
   int ret;

   if (!g_IsMounted)
   {
//      printf("\r\nMedia not mounted, not going to append file!");
      return;
   }

//   printf("\r\nAppending '%s' to '%s': ", appendString, fileName);
   f = FSfopen(fileName, "a");
   if(!f)
   {
//      printf("Error (%X)", FSerrno);
      return;
   }

   FSfwrite(appendString, sizeof(char), strlen(appendString), f);
  // FSfwrite(newLine, sizeof(char), strlen(newLine), f);

   ret = FSfclose(f);
   if(ret)
   {
//      printf("Error (%X %X)", ret, FSerrno);
      return;
   }
//   printf("OK");
}

/*
Summary: Change the working directory.
Param: The new working directory to switch to.
Returns: None.
Example Usage: \> cd ftp/     -> /ftp/
               \ftp\> cd files/  -> /ftp/files/
               \ftp\files> cd..  -> /ftp/
               \ftp\> cd ..      -> /
               \> cd /ftp/files/ -> /ftp/files/

Note: Changing the directory to .. will go up a directory.
*/
int ChangeDirectory(char *newCWD)
{

   if (!g_IsMounted)
   {
    //  printf("\r\nMedia not mounted, not going to change directory!");
      return(1);   //This is a non mounted error
   }

   if (FSchdir(newCWD))
   {
    //  printf("\r\nError changing directory");

	return(2);   //This is a non existent dir
   }

return(0);   //This means all is well.
}

/*
Summary: Display the contents of the working directory.
Param: The full path of the directory contents to display.
Returns: None.
Example Usage: /> dir
*/
int DisplayDirectory(void)
{
   SearchRec s;
   int ret,i;
   char str[20];
   char folderit[100];

   if (!g_IsMounted)
   {
     // printf("\r\nMedia not mounted, not going to display directory!");
      return(1);
   }

   memset(&s, 0x00, sizeof(s));

   ret = FindFirst("*.*", ATTR_MASK, &s);

   for(;;)
   {
      if (ret != 0)
      {
//         printf("\r\n\nDirectory search completed");

         if (FSerrno != CE_FILE_NOT_FOUND)
         {
//            printf(" (FSerrno = %u)", FSerrno);
         }
         break;
      }

      if ((s.attributes & ATTR_VOLUME) != ATTR_VOLUME)
      {
         if ((s.attributes & ATTR_DIRECTORY) == ATTR_DIRECTORY)
            sprintf(str, "<DIR>  ");
         else
            sprintf(str, " ");

         sprintf(folderit,"%lu\t\t%s%s", s.filesize, str, s.filename);
         i++;
      }

      ret = FindNext(&s);
   }
}

#endif




#ifndef EEPROMCONFIG

//*************************************************************************
// Created May 4, 2015
//  This routine gets the file name of the next item in the buffer.  It only returns one item.
//  The returned value of the function is a good and bad.  It tells the error if there is one.
//  The global string returns the name of the file for the next item in the buffer.
//*************************************************************************



int GetNextBufferFile(void)
{
   SearchRec s;
   int ret,i=0;
   char str[20];


   if (!g_IsMounted)
   {
     // printf("\r\nMedia not mounted, not going to display directory!");
      return(1);
   }

   memset(&s, 0x00, sizeof(s));

   ret = FindFirst("*.*", ATTR_MASK, &s);

   for(;;)
   {
      if (ret != 0)
      {
//         printf("\r\n\nDirectory search completed");

         if (FSerrno != CE_FILE_NOT_FOUND)
         {
           // printf(" (FSerrno = %u)", FSerrno);
		     return(2);
         }
         break;
      }

      if ((s.attributes & ATTR_VOLUME) != ATTR_VOLUME)
      {
         if ((s.attributes & ATTR_DIRECTORY) == ATTR_DIRECTORY)
            {
		 	sprintf(str, "<DIR>  ");
			}
         else
			if (i==0)
			{
         	sprintf(NextBufferFileName,"%s",s.filename);
         	i++;
			}
      }
      ret = FindNext(&s);
   }
   return(0);
}


//***************************************************************
// Created/Copied Nov. 6, 2015
//  This returns the next filename in a folder.  It is used for getting a list of all the files and deleteing them.  This is called from the BT routines.
//***************************************************************


int GetNextFile(void)
{
   SearchRec s;
   int ret,i=0;
   int exitt = 1;
   char str[20];


   if (!g_IsMounted)
   {
     // printf("\r\nMedia not mounted, not going to display directory!");
      return(1);
   }

   memset(&s, 0x00, sizeof(s));

   ret = FindFirst("*.*", ATTR_MASK, &s);

   for(;;)
   {
      if (ret != 0)
      {
//         printf("\r\n\nDirectory search completed");

         if (FSerrno != CE_FILE_NOT_FOUND)
         {
           // printf(" (FSerrno = %u)", FSerrno);
		     return(2);
         }
         break;
      }

      if ((s.attributes & ATTR_VOLUME) != ATTR_VOLUME)
      {
         if ((s.attributes & ATTR_DIRECTORY) == ATTR_DIRECTORY)
            {
		 	sprintf(str, "<DIR>  ");
			}
         else
			if (i==0)
			{
         	sprintf(NextFileName,"%s",s.filename);
			exitt = 0;
         	i++;
			}
      }
      ret = FindNext(&s);
   }
   return(exitt);
}









/*
Summary: Create a directory.
Param: The full path of the directory to create.
Returns: None.
Example Usage: /> mkdir "Backlog"
*/
int MakeDirectory(char *dir)
{
   if (!g_IsMounted)
   {
     // printf("\r\nMedia not mounted, not going to make directory!");
      return(2);
   }

  // printf("\r\nMaking directory '%s': ", dir);

   if(FSmkdir(dir))
   {
  //    printf("Error creating directory (FSerrno = %u)", FSerrno);
      return(1);
   }
 //  printf("OK");
return(0);
}

/*
Summary: Remove a directory.
Param: The full path of the directory to remove.
Returns: None.
Example Usage: /> rmdir "Backlog"
Note: The directory needs to be empty in order for this command to work.
*/
void RemoveDirectory(char *dir)
{
   if (!g_IsMounted)
   {
//      printf("\r\nMedia not mounted, not going to remove directory!");
      return;
   }

//   printf("\r\nRemoving directory '%s': ", dir);

   if(FSrmdir(dir, FALSE))
   {
//      printf("Error removing directory");
      return;
   }
//   printf("OK");
}

#define CAT_FROM_START  FALSE
#define CAT_FROM_END    TRUE
/*
Summary: Prints either all of or the last 80 characters in a file.
Param: The full path of the file to print off.
Param: If true, this function will print off the last 80 characters in the file.
       If false, this funciton will print off the entire file.
Returns: None.
Example Usage: /> cat "Logs.txt" (this will display the entire file)
Example Usage: /> tail "Logs.txt" (this will display the last 80 characters in the file)
*/
int PrintFile(char *fileName, int1 startFromEnd)
{
 //  char scr[65];
   size_t len;
   FSFILE* f;

   if (!g_IsMounted)
   {
    //  printf("\r\nMedia not mounted, not going to display file!");
      return(1);
   }

   f = FSfopen(fileName, "r");
   if (!f)
   {
   //   printf("\r\nError opening file (Error %X)", FSerrno);
      return(2);
   }

   //printf("\r\n");

   if(startFromEnd)
      FSfseek(f, 80, SEEK_END);

   do
   {
      len = FSfread(scr, sizeof(char), (sizeof(scr)-1), f);
      if (FSerrno && (FSerrno != CE_EOF))
      {
       //  printf("\r\n!!! Error reading file (Error %X)", FSerrno);
         len = 0;
		return(3);
         break;
      }
      if (len)
      {
         scr[len] = 0;
         //DEBUG_STR("PrintFile() got", len);
      //   printf("%s", scr);
      }
   } while(FSerrno != CE_EOF);

   FSfclose(f);
   return(0);
}

//*****************************************************************************
// Created Dacember 30, 2014
// Turn on power to card.
// This is done through Pin_RG9
//  This input into the function is as follows:
// Put power to the SD Card:  1
// Take away power to the SD Card: 0
//*****************************************************************************

void PowerSDCard(int8 state)
	{

	if (state == 0)
		{

// Changed on December 3, 2015
// The output pin for turning on and off the SD Card moved to RG8 from RG9.  RG9 is used as the chip select.
// The file called hardwareProfile.h is also changed to reflect the pin movement.
	//	TRISGbits.TRISG9 = OUTPUT;
	//	PORTGbits.RG9 =  0;
		TRISGbits.TRISG8 = OUTPUT;
		PORTGbits.RG8 =  0;
		//output_low(PIN_SDPOWER);
		}	
	if (state == 1)
		{
//		TRISGbits.TRISG9 = OUTPUT;
//		PORTGbits.RG9 =  1;
		TRISGbits.TRISG8 = OUTPUT;
		PORTGbits.RG8 =  1;
		}
	}


int MountMedia(void)
{
   g_IsMounted = FALSE;


PowerSDCard(0);  //Power up the card
	

   MDD_InitIO();

   if (!MDD_MediaDetect())
   {
      printf("\r\nError, Media not found!");
   }



   if (FSInit())
   {
      g_IsMounted = TRUE;

  //    printf("\r\nOK (Sector Size=%LU, Sec Per Clus=%U, Type=%U)",
    //        gDiskData.sectorSize,
  //          gDiskData.SecPerClus,
  //          gDiskData.type
  //       );
		return(0);   //something  found
   }
   else
   {
  //    printf("\r\nError, file system not mounted (FSerrno=%U)!!!", FSerrno);
      return(1);   //nothing found
   }
}

/*
Summary: Formats the media to a specified size.
Param: The size of the media, in kB, in string form.
Returns: None.
Example Usage: /> format 524288 (format a 512MB card)
*/
void FormatMedia(char *mediaSize)
{
  #if !defined(ALLOW_FORMATS)
   fprintf(BT,"\r\nError, formatting disabled!!!");
  #else
   uint32_t size;
   int scr;
   int1 ok = FALSE;
   char c;
   MEDIA_INFORMATION *m;

   #define MEDIA_SERIAL_NUMBER   "123"
   #define MEDIA_VOLUME_ID       "Paul"

   g_IsMounted = FALSE;

   MDD_InitIO();

   if (!MDD_MediaDetect())
   {
      fprintf(BT,"\r\nError, media not found!");
      return;
   }

   m = MDD_MediaInitialize();
   if (m->errorCode != MEDIA_NO_ERROR)
   {
      fprintf(BT,"\r\nMedia not initialized (ec = %X), media not formatted!", m->errorCode);
      return;
   }

   size = atoi32(mediaSize);
   scr = strlen(mediaSize);
   if (scr)
   {
      c = toupper(mediaSize[scr-1]);
      if (c == 'K')
         size *= (uint32_t)1024;
      else if (c == 'M')
         size *= (uint32_t)1024*1024;
      else if (c == 'G')
         size *= (uint32_t)1024*1024*1024;
   }

   fprintf(BT,"\r\nFormatting media (size=%LU, sector size=%LU): ", size, MEDIA_SECTOR_SIZE);

   if (!FSCreateMBR(1, size/MEDIA_SECTOR_SIZE))
   {
      if (!FSformat (1, MEDIA_SERIAL_NUMBER, MEDIA_VOLUME_ID))
      {
         ok = TRUE;
      }
   }

   if(!ok)
   {
      fprintf(BT,"Error formatting media");
      return;
   }
	else
	{
	fprintf(BT,"Media formatted\n\r");
	}

   MountMedia();
  #endif
}

void MediaInfo(void)
{
   FS_DISK_PROPERTIES p;



   if (g_IsMounted)
   {
      fprintf(BT,"\r\nGetting media info (this may take seconds to minutes)...");
      p.new_request = TRUE;

      do
      {
         FSGetDiskProperties(&p);
      } while(p.properties_status == FS_GET_PROPERTIES_STILL_WORKING);

      if (p.properties_status == FS_GET_PROPERTIES_DISK_NOT_MOUNTED)
      {
         fprintf(BT,"\r\n\nFile system thinks media isn't mounted, try mounting again!");
      }
      else if (p.properties_status != FS_GET_PROPERTIES_NO_ERRORS)
      {
         fprintf(BT,"\r\n\nError getting info");
      }
      else
      {
         fprintf(BT,"\r\n\nBytes per sector: %LU", p.results.sector_size);
         fprintf(BT,"\r\nSectors per cluster: %U", p.results.sectors_per_cluster);
         fprintf(BT,"\r\nTotal size of media: %LU", p.results.total_clusters*p.results.sectors_per_cluster*p.results.sector_size);
         fprintf(BT,"\r\nFree space of media: %LU\r\n", p.results.free_clusters*p.results.sectors_per_cluster*p.results.sector_size);
      }
   }
   else
   {
      fprintf(BT,"\r\nMedia not mounted, not getting info!");
   }
}



char * GetCMD(char *in)
{
   char tokens[]=" \r\n";
   return(strtok(in,tokens));
}

char * GetOption(char *in)
{
   char tokensSpace[]=" \r\n";
   char tokensQuote[]="\"\r\n";

   //trim leading spaces
   while (*in==' ')
      in++;

   //if first char is a quote, then end token on a quote.  ELSE end token on a space
   if (*in == '\"')
      return(strtok(in,tokensQuote));
   else
      return(strtok(in,tokensSpace));
}


//****************************************************************************
// Created January 27, 2015
// This routine warms up the SCCard and Mounts the drive for it to be used.
//  This needs to be run at the beginning when bringing up the chip
// It returns a 1 if the SDCArd is working.
//  It returns a 0 if the SDCard is not working or not installed.
//***************************************************************************
int initUpSDCard(void)
	{


MountMedia();

            if (!g_IsMounted)
            {


				return(0);  //This means the SDCard is not working or installed.
               //sprintf(buffer, "mount");
            }
            else
            {


			return(1);  // This means the SCCard is installed and working.
              	sprintf(buffer, "append log.txt button pressed!!");
            }
	}

#endif


#ifndef EEPROMCONFIG 
//******************************************************************************
//Created March 25, 2015
// This routine makes a new configuration file if on does not exist.   Read Configureation file
//  The Osmobot configureation file is called config.sys
//  The information in the file contains the serial number of this unit and all of the instrumentation numbers from calibration.
// Format 
//
// UnitSerialNumber
// Wifi RouterName
//  Wifi Password
//******************************************************************************
void ReadConfigurationFile(char *fileName)
	{

int returnedfileerror,x;

	
	returnedfileerror = PrintFile(fileName, 0);   //try to print the file and see if it exsits.  If not, then make it exist with default values.

	if (returnedfileerror == 0)
		{
	//	Display_XYString(0,3, &scr);
		}
		else
		{
		Display_XYString(0, 1, "error opening config.txt");
		if (returnedfileerror == 2)	   // Check to see if there is an SD Card but no file.
			{
			// This means there is a card but no file
			MakeFile("Config.txt");   //This makes the default file.
			AppendFile("Config.txt", "PaulsBoard,RouterName,RouterPassword,WPA2PSK,AES,~");   // Now put the default information into the file.
			returnedfileerror = PrintFile(fileName, 0); 
			if (returnedfileerror == 0)
			{
				Display_XYString(0,3, &scr);
			}
			}
		}
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015
split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global varialbes   SplitResult[20][20];

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
#if SDCardDisplay
				Display_XYString(0,2, &sysOutput.deviceID);
#endif
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
#if SDCardDisplay
				Display_XYString(0,3, &STA_SSID);
#endif
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


//*********************************************************************************************
//Created April 3, 2015
// This routine updates the configuration file  with the latest configureations.
//  At this time there are only items the needs to be saved:
//  Serial Number
// Router Name
// Router Password
// Additions:
//  
//  Returns a zero if all is well.
//*********************************************************************************************
int SaveConfigFile(char *fileName)
	{
char configdata[100];
int zz,x,returnedfileerror,result;
//make sure you are pointing to root
//junk = ChangeDirectory("");

//delete the current file

result = DeleteFile(fileName);

zz=0;
//Make a new file and save the current configureations

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


MakeFile("Config.txt");   //This makes the default file.
AppendFile("Config.txt", &configdata);   // Now put the default information into the file.
returnedfileerror = PrintFile(fileName, 0); 


Display_XYString(0,0, "Display saved data in Config file");

//Re-read the data and make sure it got saved.
	if (returnedfileerror == 0)
		{
		Display_XYString(0,3, &scr);
		}
 

	return(0);
	}


#endif


// *****************************************************************
// Added Nov 12, 2014
//  This find the string length
// *****************************************************************


int16 strlenn(char stri[])
	{
	int16 i=0;
//	char stri[50];
	while(stri[i]!='\0')
		{
		i++;
		}
		return i;
}



//*************************************************************************************************
// Created April 3, 2015
//THis routine saves the current data read from all of the instrument into the Server.  If there is no connection, the data is saved in the buffer.
// A folder is named as todays date and the file name for each record is saved at the date and time combined
//************************************************************************************************

int SaveSendingReadings(void)
	{
int results,t;
char olderstring[12];  //This is the array that holds the current folder to put the data for the day.
char HTTPoutput[BUFFERSIZE-100];
char FinalHTTP[BUFFERSIZE];
unsigned int8 checksum;
//char FinalHTTP[BUFFERSIZE];
// Make sure you are in root
//Determine the current folder to place the data.  It is made up of the date.


//*******************************************************************
// Added May 5 2015
// This section below makes the file name for each data point.  This point is saved in the artchives and is saved in the download buffer.
// The format is as follows:
//  HHMMSS  It's in UCT time, not the local time and date.
//*******************************************************************
//sprintf(olderstring,"%02u%02u%02u.txt",sysOutput.hour,sysOutput.minute,sysOutput.second);

sprintf(timeString,"%02u:%02u:%02u$%04lu-%02u-%02u",sysOutput.hour,sysOutput.minute,sysOutput.second,sysOutput.year,sysOutput.month,sysOutput.day,);

sprintf(HTTPoutput,"Crab$%s$%s$%05.1f$%05.1f$%05.1f$%05.1f$%05.1f$%05.1f$%05.1f$%ld$%05.3f$%lu$%lu$%lu$%lu$%05.1f$%05.1f$%05.1f$%07.1f$%05.1f",sysOutput.deviceID,timeString,sysOutput.dOxy,sysOutput.wTemp,sysOutput.pH,sysOutput.wLevel,sysOutput.lLevelX,sysOutput.rH,sysOutput.aTemp,sysOutput.cO2,sysOutput.nh3,sysOutput.lLevelRed,sysOutput.lLevelGreen,sysOutput.lLevelBlue,sysOutput.lLevelClear,sysOutput.lLevelScale,sysOutput.dPoint,sysOutput.WhiteBalance,sysOutput.tdsLevel,sysOutput.pHLow);
checksum = Calc_Crc8(HTTPoutput,strlenn(HTTPoutput));
sprintf(FinalHTTP,"GET /welcomeyou.php?name=%s&chksm=%u HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",HTTPoutput,checksum);   //This sends the whole sting into the buffer.  Nothing needs to be parsed when it comes out.


//  this is the old format.  it does not save to the SD Card because it's too long.  Saved for reference.
//sprintf(HTTPoutput,"Crab$%s$%s$%2f$%2f$%2f$%2f$%2f$%2f$%2f$%ld$%2f$%lu$%lu$%lu$%lu$%2f$%2f$%2f$%2f$%2f",sysOutput.deviceID,timeString,sysOutput.dOxy,sysOutput.wTemp,sysOutput.pH,sysOutput.wLevel,sysOutput.lLevelX,sysOutput.rH,sysOutput.aTemp,sysOutput.cO2,sysOutput.nH3,sysOutput.lLevelRed,sysOutput.lLevelGreen,sysOutput.lLevelBlue,sysOutput.lLevelClear,sysOutput.lLevelScale,sysOutput.dPoint,sysOutput.WhiteBalance,sysOutput.tdsLevel,sysOutput.pHLow);
//checksum = Calc_Crc8(HTTPoutput,strlenn(HTTPoutput));
//sprintf(FinalHTTP,"GET /welcomeyou.php?name=%s&chksm=%u HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",HTTPoutput,checksum);   //This sends the whole sting into the buffer.  Nothing needs to be parsed when it comes out.


//Display_XYString(0,1, &FinalHTTP);   //Show the current data in the file to download  Added Nov. 3, 2015
 				fprintf(WIFI,"%s",FinalHTTP);   //Send the data off to the server.
				fprintf(BT,"%s\n\r",FinalHTTP);   //Send the data off to the server and send it to the connected bluetooth unit for display read.       

for (t=0; t < 20; t++)
{
delay_ms(1000);
//if ((ACKFROMSERVER != 0) && (!BTMeasureTimer) && (firstimethrough == 0))
if ((ACKFROMSERVER != 0) && (!BTMeasureTimer))
	{
    return(0);
    } 
}

//******************************************************************************
// Created May 11 2016
// This section sets up the folder for the download buffer.  If it does not exists, then is makes it exist.
//  The name of the downloading buffer is called buffer.
//******************************************************************************

    results = SaveNextBufferRecord(&FinalHTTP);  // it places it in the buffer because it did not confirm

	return(1);
	}



#ifdef EEPROMCONFIG


//******************************************************************************
//Created May 19, 2015
// Changed and designed out the SD Card  May 7, 2015
// This routine gets all of the data for calibrations off the EEPROM.  The address starts at 
// 0x0110 to 0x0310    The data can not be longer than 256 bytes.  So far it's split into three sections.
// If there is not data up front, then the default data is placed in the varaibles and then used.

// This routine make and reads the calibration file if on does not exist.   Read instrumenetation calibration file

//  Here is the format for the order of the number in the file.  this is edited using a text editor and then it completed for this unit.
//The top is for DO 
//	float Temp1ReadingOne = 10752.0;       //Readings for Temp3  10 degrees C
//	float Temp1ReadingTwo = 11000.0;      //Readings for Temp3
//	float Temp1ReadingThree = 12000.0;    //Readings for DOOne    this is no DO.

//	float Temp2ReadingOne = 11266.0;       //Readings for Temp3    20 degrees C
//	float Temp2ReadingTwo = 12000.0;      //Readings for Temp3
//	float Temp2ReadingThree = 13000.0;    //Readings for DOOne

//	float Temp3ReadingOne = 12425.0;       //Readings for Temp3   25 degrees C
//	float Temp3ReadingTwo = 13000.0;      //Readings for Temp3
//	float Temp3ReadingThree = 14000.0;    //Readings for DOOne



//	float Temp1DOOne = 9.5;            //These are the set points where we want to read these numbers at temperature 1
//	float Temp1DOTwo = 4.0;            //This is at 10 degrees
//	float Temp1DOThree = 0.0;

//	float Temp2DOOne = 7.5;            //These are the set points where we want to read these numbers at temperature 2
//	float Temp2DOTwo = 4.0;				//This is at 20 degrees
//	float Temp2DOThree = 0.0;

//	float Temp3DOOne = 6.7;            //These are the set points where we want to read these numbers temperature 3
//	float Temp3DOTwo = 4.0;            //This is at 25 degrees
//	float Temp3DOThree = 0.0;



// The second order is for pH


//	pHHigh = 9.0;
//	pHMiddle = 7.5;
//	pHLower = 6.5;

//	pHHighCalibration =  0.72;    //Used to be  0.93
//	pHMiddleCalibration =  0.705;   //Used to be   0.97
//	pHLowerCalibration = 0.69;    //Used to be  0.985



//  The Osmobot configureation file is called config.sys
//  The information in the file contains the serial number of this unit and all of the instrumentation numbers from calibration.
// Format 

//******************************************************************************
void ReadCalEEPROM(void)
	{

int returnedfileerror,x;
char tempstuff[255];
int changefolder;
char tempholder[20];  //This is used for collecting the string of characters from SD Card for Cal and later converting them into a real float value.
 
	returnedfileerror = readOneEEPROMCharacter(0x0110);  //Get eh first character.  if it is 0xFF, then there is no configuration.
	if (returnedfileerror == -1)
		{
        fprintf(BT,"Writing Calibration data to EEPROM for the first time.\n\r");
        sprintf(tempstuff,"2350,4400,5080,2295,3757,5000,2144,3160,4953,  14.50,4.00,1.00,10.51,4.00,1.00,9.31,4.00,1.00,~");   // save this bogus data to introduce some information when the card is not configured.
        WriteITwoSeeString(0x0110, tempstuff);
		}

readITwoSeeString(0x0110, scr);   // read the data what ever it is.
    
 fprintf(BT,"Cal1 Raw data ->  %s\n\r",scr);   
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015

// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015
split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global varialbes   SplitResult[20][20];



//**********************************************************************************
// First data point as raw data

//This token is for "Temp1ReadingOne"  1

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[0][x];
	if ( SplitResult[0][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp1ReadingOne =  atof(tempholder);  //This converts the number from string to float.



//This token is for "Temp1ReadingTwo"   2
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[1][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1ReadingTwo =  atof(tempholder);  //This converts the number from string to float.


//This token is for "Temp1ReadingThree"  3
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[2][x];
	if ( SplitResult[2][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1ReadingThree =  atof(tempholder);  //This converts the number from string to float.



//**********************************************************************************
// Second data point as raw data

//This token is for "Temp2ReadingOne"   4

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[3][x];
	if ( SplitResult[3][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp2ReadingOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "Temp2ReadingTwo"   5
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[4][x];
	if ( SplitResult[4][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2ReadingTwo =  atof(tempholder);  //This converts the number from string to float.


//This token is for "Temp2ReadingThree"   6
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[5][x];
	if ( SplitResult[5][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2ReadingThree =  atof(tempholder);  //This converts the number from string to float.


//*************************************************************************************
// Third data point as raw data

//This token is for "Temp1ReadingOne"   7

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[6][x];
	if ( SplitResult[6][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp3ReadingOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "Temp1ReadingTwo"    8
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[7][x];
	if ( SplitResult[7][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3ReadingTwo =  atof(tempholder);  //This converts the number from string to float.


//This token is for "Temp1ReadingThree"   9
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[8][x];
	if ( SplitResult[8][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3ReadingThree =  atof(tempholder);  //This converts the number from string to float.



//*************************************************************************************
// Created May 20, 2015
// This section is the DO values.  There are 9 in total.
//*************************************************************************************



//**********************************************************************************
// First data point as raw data

//This token is for "Temp1DOOne"   10

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[9][x];
	if ( SplitResult[9][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp1DOOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "Temp1DOTwo"  11
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[10][x];
	if ( SplitResult[10][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1DOTwo =  atof(tempholder);  //This converts the number from string to float.


//This token is for "Temp1DOThree"  12
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[11][x];
	if ( SplitResult[11][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1DOThree =  atof(tempholder);  //This converts the number from string to float.



//**********************************************************************************
// Second data point as raw data

//This token is for "Temp2DOOne"  13

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[12][x];
	if ( SplitResult[12][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp2DOOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "Temp2DOTwo"  14
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[13][x];
	if ( SplitResult[13][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2DOTwo =  atof(tempholder);  //This converts the number from string to float.


//This token is for "Temp2DOThree"   15
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[14][x];
	if ( SplitResult[14][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2DOThree =  atof(tempholder);  //This converts the number from string to float.


//*************************************************************************************
// Third data point as raw data

//This token is for "Temp3DOOne"  16

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[15][x];
	if ( SplitResult[15][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp3DOOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "Temp3DOTwo"  17
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[16][x];
	if ( SplitResult[16][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3DOTwo =  atof(tempholder);  //This converts the number from string to float.


//This token is for "Temp3DOThree"  18
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[17][x];
	if ( SplitResult[17][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3DOThree =  atof(tempholder);  //This converts the number from string to float.


                
 	returnedfileerror = readOneEEPROMCharacter(0x0210);  //Get eh first character.  if it is 0xFF, then there is no configuration.

	if (returnedfileerror == -1)
		{
        fprintf(BT,"Writing configuration data to the second location to EEPROM for the first time\n\r");
        sprintf(tempstuff,"19517.00,19200.00,18000.00,14800.00,11700.00,11300.00,9618.00,8500.00,5800.00,6.50,19517.00,9.00,40.00,20.00,6.00,5140.00,11700.00,21594.00,6000,5000,96,100,100,151,78,~");   // save this bogus data to interoduce some information when the card is not configured.
        WriteITwoSeeString(0x0210, tempstuff);
		}

    readITwoSeeString(0x0210, scr);   // read the data what ever it is.
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015
 fprintf(BT,"Cal2 Raw data ->  %s\n\r",scr); 
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015
split(&scr, ",", "~");               
                
                
                
                
//***********************************************************************************
// Created May 20, 2015
// This section below sucks in the pH calibration values.  They are all float and there are only three of them.  That means there is three values for pH and three raw data points.
//***********************************************************************************
// Updated and Changed July 2, 2015
// This has been changed to a convoltion of 3X3 matrix for system charatization.  The input matrix is RGB for three points
// for calculating pH.  This needs to be saved into non-volitale varaibles.

//**********************************************************************************
// First data point as raw data for pH

//This token is for RGB for the lowest pH value.  This is for Red  19

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[0][x];
	if ( SplitResult[0][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
datatable[0] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for RGB for the lowest pH value.  This is for Green  20
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[1][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[1] =  atof(tempholder);  //This converts the number from string to float.


//This token is for RGB for the lowest pH value.  This is for Blue  21
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[2][x];
	if ( SplitResult[2][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[2] =  atof(tempholder);  //This converts the number from string to float.


//*************************************************************************************
// Second  data point as raw data for pH

//This token is for RGB for the middle pH value.  This is for Red   22

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[3][x];
	if ( SplitResult[3][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
datatable[3] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for RGB for the middle pH value.  This is for Green   23
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[4][x];
	if ( SplitResult[4][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[4] =  atof(tempholder);  //This converts the number from string to float.


//This token is for RGB for the middle pH value.  This is for Blue  24
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[5][x];
	if ( SplitResult[5][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[5] =  atof(tempholder);  //This converts the number from string to float.



//This token is for RGB for the high pH value.  This is for Red  25
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[6][x];
	if ( SplitResult[6][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[6] =  atof(tempholder);  //This converts the number from string to float.


//This token is for RGB for the high pH value.  This is for Green   26
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[7][x];
	if ( SplitResult[7][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[7] =  atof(tempholder);  //This converts the number from string to float.


//This token is for RGB for the high pH value.  This is for Blue   27
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[8][x];
	if ( SplitResult[8][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[8] =  atof(tempholder);  //This converts the number from string to float.


//This token is for RGB for the low pH value.  This is for the euqation solution  28
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[9][x];
	if ( SplitResult[9][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[9] =  atof(tempholder);  //This converts the number from string to float.



//This token is for RGB for the middle pH value.  This is for the euqation solution  29
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[10][x];
	if ( SplitResult[10][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[10] =  atof(tempholder);  //This converts the number from string to float.


//This token is for RGB for the high pH value.  This is for the euqation solution  30
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[11][x];
	if ( SplitResult[11][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[11] =  atof(tempholder);  //This converts the number from string to float.


//************************************************************************************
// Created May 21, 2015
// These three numbers are used for calibrating the thermister for the temperature sensor..  There are three numbers doing the calcaultations.
// The numbers are saved as the last three numbers in the cal file.

//temp1 = 40;
//temp2 = 21;
//temp3 = 6;

//reading1 = 12000;   //this one is measured at 45 degrees C
//reading2 = 40000;   //this is measured at 22 C  Checked on May 14, 2015
//reading3 = 72000;   // this tempature is measured at 12 degrees C

//************************************************************************************ 



//**********************************************************************************
// First data point as raw data for thermister

//This token is for "temp1"   31

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[12][x];
	if ( SplitResult[12][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
temp1 =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "temp2"   32
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[13][x];
	if ( SplitResult[13][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

temp2 =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "temp3"   33
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[14][x];
	if ( SplitResult[14][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

temp3 =  atof(tempholder);  //This converts the number from string to float.


//*************************************************************************************
// Second  data point as raw data for thermisters

//This token is for "preading1"   34

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[15][x];
	if ( SplitResult[15][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
reading1 =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "reading2"  35
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[16][x];
	if ( SplitResult[16][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

reading2 =  atof(tempholder);  //This converts the number from string to float.


//This token is for "reading3"  37
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[17][x];
	if ( SplitResult[17][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

reading3 =  atof(tempholder);  //This converts the number from string to float.


//*****************************************************************************
//Created June 26, 2015
// This value is the feedback number for the blue light for any DO setup.  The setup can vary depening on who does the glueing..
// When the patch is on the boat and there is no water, the DO position should be around 20000 with a 2000 reading for Red.
//  When the unit is in water, it goes much down.  The readings start aroudn 5000.  And Red is around 500.
//  Below is the saved variable for the Blue value.
//*****************************************************************************


//This token is for "BlueLimit"  37
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[18][x];
	if ( SplitResult[18][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

BlueLimit =  atoi32(tempholder);  //This converts the number from string to float.


//This token is for "WhileLimit"   38
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[19][x];
	if ( SplitResult[19][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

WhiteLimit =  atoi32(tempholder);  //This converts the number from string to float.
	

//***********************************************************************
// Added July 27, 2015
// These four values change the tolorances for color brighnest from the the DO and pH PWM.
//  The other two are the seeds for the start of the PWM search.  Once the unit finds the good PWM, it keeps in memory, not on the SD Card.
//***********************************************************************



//This token is for "PWMDOIntensity"  39
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[20][x];
	if ( SplitResult[20][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

PWMDOIntensity =  atoi32(tempholder);  //This converts the number from string to float.
	


//This token is for "PWMPHIntensity"  40
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[21][x];
	if ( SplitResult[21][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

PWMPHIntensity =  atoi32(tempholder);  //This converts the number from string to float.


//This token is for "PWMnh3Intensity"   41
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[22][x];
	if ( SplitResult[22][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

PWMnh3Intensity =  atoi32(tempholder);  //This converts the number from string to float.
	


//This token is for "DOreadingrange"   42
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[23][x];
	if ( SplitResult[23][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

DOreadingrange =  atoi32(tempholder);  //This converts the number from string to float.  
	


//This token is for "pHreadingrange"   43
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[24][x];
	if ( SplitResult[24][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

pHreadingrange =  atoi32(tempholder);  //This converts the number from string to float.
	

 	returnedfileerror = readOneEEPROMCharacter(0x0310);  //Get eh first character.  if it is 0xFF, then there is no configuration.

	if (returnedfileerror == -1)
		{
        fprintf(BT,"Writing configuration data to the third location to EEPROM for the first time\n\r");
        sprintf(tempstuff,"2350.00,4400.00,5080.00,2295.00,3757.00,5000.00,~");   // save this bogus data to interoduce some information when the card is not configured.
        WriteITwoSeeString(0x0310, tempstuff);
		}

    readITwoSeeString(0x0310, scr);   // read the data what ever it is.
 fprintf(BT,"Cal3 Raw data ->  %s\n\r",scr); 
split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global varialbes   SplitResult[20][20];

//**********************************************************************************
// First data point as raw data

//This token is for "eccalibrationx[0]"   44

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[0][x];
	if ( SplitResult[0][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
eccalibrationx[0] =  atof(tempholder);  //This converts the number from string to float.



//This token is for "eccalibrationx[1]"   45
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[1][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationx[1] =  atof(tempholder);  //This converts the number from string to float.

//  Once it is in the array, save it in the Serial number global variable.

//This token is for "eccalibrationx[2]"   46
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[2][x];
	if ( SplitResult[2][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationx[2] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "eccalibrationy[0]"  47
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[3][x];
	if ( SplitResult[3][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationy[0] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "eccalibrationy[0]"   48
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[4][x];
	if ( SplitResult[4][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationy[1] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "eccalibrationy[0]"   49
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[5][x];
	if ( SplitResult[5][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationy[2] =  atof(tempholder);  //This converts the number from string to float.



return;
	}

#endif
#ifndef EEPROMCONFIG
//******************************************************************************
//Created May 19, 2015

// This routine make and reads the calibration file if on does not exist.   Read instrumenetation calibration file

//  Here is the format for the order of the number in the file.  this is edited using a text editor and then it completed for this unit.
//The top is for DO 
//	float Temp1ReadingOne = 10752.0;       //Readings for Temp3  10 degrees C
//	float Temp1ReadingTwo = 11000.0;      //Readings for Temp3
//	float Temp1ReadingThree = 12000.0;    //Readings for DOOne    this is no DO.

//	float Temp2ReadingOne = 11266.0;       //Readings for Temp3    20 degrees C
//	float Temp2ReadingTwo = 12000.0;      //Readings for Temp3
//	float Temp2ReadingThree = 13000.0;    //Readings for DOOne

//	float Temp3ReadingOne = 12425.0;       //Readings for Temp3   25 degrees C
//	float Temp3ReadingTwo = 13000.0;      //Readings for Temp3
//	float Temp3ReadingThree = 14000.0;    //Readings for DOOne



//	float Temp1DOOne = 9.5;            //These are the set points where we want to read these numbers at temperature 1
//	float Temp1DOTwo = 4.0;            //This is at 10 degrees
//	float Temp1DOThree = 0.0;

//	float Temp2DOOne = 7.5;            //These are the set points where we want to read these numbers at temperature 2
//	float Temp2DOTwo = 4.0;				//This is at 20 degrees
//	float Temp2DOThree = 0.0;

//	float Temp3DOOne = 6.7;            //These are the set points where we want to read these numbers temperature 3
//	float Temp3DOTwo = 4.0;            //This is at 25 degrees
//	float Temp3DOThree = 0.0;



// The second order is for pH


//	pHHigh = 9.0;
//	pHMiddle = 7.5;
//	pHLower = 6.5;

//	pHHighCalibration =  0.72;    //Used to be  0.93
//	pHMiddleCalibration =  0.705;   //Used to be   0.97
//	pHLowerCalibration = 0.69;    //Used to be  0.985



//  The Osmobot configureation file is called config.sys
//  The information in the file contains the serial number of this unit and all of the instrumentation numbers from calibration.
// Format 

//******************************************************************************
void ReadCalibration(char *fileName)
	{

int returnedfileerror,x;
int changefolder;
char tempholder[20];  //This is used for collecting the string of characters from SD Card for Cal and later converting them into a real float value.
 


changefolder = ChangeDirectory("..");   // Go back up to root for the next data point.   This goes back to root

	returnedfileerror = PrintFile(fileName, 0);   //try to print the file and see if it exsits.  If not, then make it exist with default values.

	if (returnedfileerror == 0)
		{
	//	Display_XYString(0,3, &scr);
		}
		else
		{
		Display_XYString(0, 1, "error opening Cal.txt");
		if (returnedfileerror == 2)	   // Check to see if there is an SD Card but no file.
			{
			// This means there is a card but no file
			MakeFile("Cal.txt");   //This makes the default file.
			AppendFile("Cal.txt", "439,520,1950,420,500,1950,407,475,1950,11.5,4.0,0.0,8.4,4.0,0.0,7.0,4.0,0.0,208683.125,175036.875,119306.25,183777.5,186245.75,118059.5,154917.75,149782.0,117312.75,6.5,7.4,9.0,40,20,6,5140,12120,22594,6000,120000,~");   // Now put the default information into the file.
			returnedfileerror = PrintFile(fileName, 0); 
			if (returnedfileerror == 0)
			{
				Display_XYString(0,3, &scr);
			}
			}
		}
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015
split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global varialbes   SplitResult[20][20];




//**********************************************************************************
// First data point as raw data

//This token is for "Temp1ReadingOne"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[0][x];
	if ( SplitResult[0][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp1ReadingOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "Temp1ReadingTwo"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[1][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1ReadingTwo =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "Temp1ReadingThree"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[2][x];
	if ( SplitResult[2][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1ReadingThree =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif


//**********************************************************************************
// Second data point as raw data

//This token is for "Temp2ReadingOne"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[3][x];
	if ( SplitResult[3][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp2ReadingOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "Temp2ReadingTwo"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[4][x];
	if ( SplitResult[4][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2ReadingTwo =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "Temp2ReadingThree"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[5][x];
	if ( SplitResult[5][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2ReadingThree =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//*************************************************************************************
// Third data point as raw data

//This token is for "Temp1ReadingOne"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[6][x];
	if ( SplitResult[6][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp3ReadingOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "Temp1ReadingTwo"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[7][x];
	if ( SplitResult[7][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3ReadingTwo =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "Temp1ReadingThree"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[8][x];
	if ( SplitResult[8][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3ReadingThree =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif


//*************************************************************************************
// Created May 20, 2015
// This section is the DO values.  There are 9 in total.
//*************************************************************************************



//**********************************************************************************
// First data point as raw data

//This token is for "Temp1DOOne"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[9][x];
	if ( SplitResult[9][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp1DOOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "Temp1DOTwo"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[10][x];
	if ( SplitResult[10][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1DOTwo =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "Temp1DOThree"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[11][x];
	if ( SplitResult[11][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp1DOThree =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif


//**********************************************************************************
// Second data point as raw data

//This token is for "Temp2DOOne"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[12][x];
	if ( SplitResult[12][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp2DOOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "Temp2DOTwo"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[13][x];
	if ( SplitResult[13][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2DOTwo =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "Temp2DOThree"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[14][x];
	if ( SplitResult[14][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp2DOThree =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//*************************************************************************************
// Third data point as raw data

//This token is for "Temp3DOOne"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[15][x];
	if ( SplitResult[15][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
Temp3DOOne =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "Temp3DOTwo"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[16][x];
	if ( SplitResult[16][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3DOTwo =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "Temp3DOThree"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[17][x];
	if ( SplitResult[17][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

Temp3DOThree =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//***********************************************************************************
// Created May 20, 2015
// This section below sucks in the pH calibration values.  They are all float and there are only three of them.  That means there is three values for pH and three raw data points.
//***********************************************************************************
// Updated and Changed July 2, 2015
// This has been changed to a convoltion of 3X3 matrix for system charatization.  The input matrix is RGB for three points
// for calculating pH.  This needs to be saved into non-volitale varaibles.

//**********************************************************************************
// First data point as raw data for pH

//This token is for RGB for the lowest pH value.  This is for Red

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[18][x];
	if ( SplitResult[18][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
datatable[0] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for RGB for the lowest pH value.  This is for Green
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[19][x];
	if ( SplitResult[19][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[1] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for RGB for the lowest pH value.  This is for Blue
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[20][x];
	if ( SplitResult[20][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[2] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//*************************************************************************************
// Second  data point as raw data for pH

//This token is for RGB for the middle pH value.  This is for Red

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[21][x];
	if ( SplitResult[21][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
datatable[3] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for RGB for the middle pH value.  This is for Green
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[22][x];
	if ( SplitResult[22][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[4] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for RGB for the middle pH value.  This is for Blue
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[23][x];
	if ( SplitResult[23][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[5] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif



//This token is for RGB for the high pH value.  This is for Red
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[24][x];
	if ( SplitResult[24][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[6] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for RGB for the high pH value.  This is for Green
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[25][x];
	if ( SplitResult[25][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[7] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif


//This token is for RGB for the high pH value.  This is for Blue
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[26][x];
	if ( SplitResult[26][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[8] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for RGB for the low pH value.  This is for the euqation solution
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[27][x];
	if ( SplitResult[27][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[9] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif


//This token is for RGB for the middle pH value.  This is for the euqation solution
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[28][x];
	if ( SplitResult[28][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[10] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for RGB for the high pH value.  This is for the euqation solution
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[29][x];
	if ( SplitResult[29][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

datatable[11] =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//************************************************************************************
// Created May 21, 2015
// These three numbers are used for calibrating the thermister for the temperature sensor..  There are three numbers doing the calcaultations.
// The numbers are saved as the last three numbers in the cal file.

//temp1 = 40;
//temp2 = 21;
//temp3 = 6;

//reading1 = 12000;   //this one is measured at 45 degrees C
//reading2 = 40000;   //this is measured at 22 C  Checked on May 14, 2015
//reading3 = 72000;   // this tempature is measured at 12 degrees C

//************************************************************************************ 



//**********************************************************************************
// First data point as raw data for thermister

//This token is for "temp1"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[30][x];
	if ( SplitResult[30][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
temp1 =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "temp2"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[31][x];
	if ( SplitResult[31][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

temp2 =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//This token is for "temp3"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[32][x];
	if ( SplitResult[32][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

temp3 =  atof(tempholder);  //This converts the number from string to float.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif

//*************************************************************************************
// Second  data point as raw data for thermisters

//This token is for "preading1"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[33][x];
	if ( SplitResult[33][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
reading1 =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.

//This token is for "reading2"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[34][x];
	if ( SplitResult[34][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

reading2 =  atof(tempholder);  //This converts the number from string to float.


//This token is for "reading3"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[35][x];
	if ( SplitResult[35][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

reading3 =  atof(tempholder);  //This converts the number from string to float.


//*****************************************************************************
//Created June 26, 2015
// This value is the feedback number for the blue light for any DO setup.  The setup can vary depening on who does the glueing..
// When the patch is on the boat and there is no water, the DO position should be around 20000 with a 2000 reading for Red.
//  When the unit is in water, it goes much down.  The readings start aroudn 5000.  And Red is around 500.
//  Below is the saved variable for the Blue value.
//*****************************************************************************


//This token is for "BlueLimit"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[36][x];
	if ( SplitResult[36][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

BlueLimit =  atoi32(tempholder);  //This converts the number from string to float.




//This token is for "WhileLimit"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[37][x];
	if ( SplitResult[37][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

WhiteLimit =  atoi32(tempholder);  //This converts the number from string to float.
	


//***********************************************************************
// Added July 27, 2015
// These four values change the tolorances for color brighnest from the the DO and pH PWM.
//  The other two are the seeds for the start of the PWM search.  Once the unit finds the good PWM, it keeps in memory, not on the SD Card.
//***********************************************************************



//This token is for "PWMDOIntensity"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[38][x];
	if ( SplitResult[38][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

PWMDOIntensity =  atoi32(tempholder);  //This converts the number from string to float.
	


//This token is for "PWMPHIntensity"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[39][x];
	if ( SplitResult[39][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

PWMPHIntensity =  atoi32(tempholder);  //This converts the number from string to float.


//This token is for "PWMnh3Intensity"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[40][x];
	if ( SplitResult[40][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

PWMnh3Intensity =  atoi32(tempholder);  //This converts the number from string to float.
	



//This token is for "DOreadingrange"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[41][x];
	if ( SplitResult[41][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

DOreadingrange =  atoi32(tempholder);  //This converts the number from string to float.
	

//This token is for "pHreadingrange"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[42][x];
	if ( SplitResult[42][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}

pHreadingrange =  atoi32(tempholder);  //This converts the number from string to float.
	


return;
	}

#endif



#ifndef EEPROMCONFIG

//*****************************************************************************************
// Creaded July 22, 2015
//  This routine saves the current calibration onto the SD Card.
//  The old file is first deleted and then an new one is overwritten in its place.
//  There is nothing return.  All data it takes is global varaibles.
//  Flushing may be required.  
// ****************************************************************************************



int SaveCalibrations(void)
	{
char configdata[400];
char tempconfigdata[256];
char dummystring[20];  //Added July 22, 2015  This is used to convert the number into a string.
int zz,x,returnedfileerror,result,junk,temptrans,cc,rr;
//make sure you are pointing to root




junk = ChangeDirectory("..");

//delete the current file

result = DeleteFile("Cal.txt");

zz=0;
//Make a new file and save the current configureations

//compile the string to save in the file


temptrans = (int) Temp1ReadingOne;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
		configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}
temptrans = (int) Temp1ReadingTwo;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;     
	}

temptrans = (int) Temp1ReadingThree;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}


temptrans = (int) Temp2ReadingOne;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }                   




temptrans = (int) Temp2ReadingTwo;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
   }


temptrans = (int) Temp2ReadingThree;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  



temptrans = (int) Temp3ReadingOne;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  

temptrans = (int) Temp3ReadingTwo;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	
        configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
   }


temptrans = (int) Temp3ReadingThree;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	if (dummystring[x] != 0x20)
		{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }   
	}

//***********************************************************************
// Start for DO readings
//***********************************************************************



sprintf(dummystring,"%7.2f",Temp1DOOne);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  


sprintf(dummystring,"%7.2f",Temp1DOTwo);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }



sprintf(dummystring,"%7.2f",Temp1DOThree);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  





sprintf(dummystring,"%7.2f",Temp2DOOne);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  


sprintf(dummystring,"%7.2f",Temp2DOTwo);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }   



sprintf(dummystring,"%7.2f",Temp2DOThree);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  





sprintf(dummystring,"%7.2f",Temp3DOOne);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  


sprintf(dummystring,"%7.2f",Temp3DOTwo);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  



sprintf(dummystring,"%7.2f",Temp3DOThree);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  



//******************************************************************************
// ph readings
//******************************************************************************


sprintf(dummystring,"%7.2f",datatable[0]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[1]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[2]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[3]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[4]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[5]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[6]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[7]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[8]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[9]);    //This is the vaiable used for pH offset calibration.  It's a pH number.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[10]);    //This is the vaiable used for pH offset calibration.  It's the red number for the calibration of the pH.  Chenged Aug 28, 2015  Switched datatable 9 and 10.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}




sprintf(dummystring,"%7.2f",datatable[11]);    //Currently not used.   Augest 17, 2015
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

//**********************************************************************************
//  Thermister calibration
//**********************************************************************************


sprintf(dummystring,"%7.2f",temp1);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}
sprintf(dummystring,"%7.2f",temp2);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%7.2f",temp3);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}




sprintf(dummystring,"%7.2f",reading1);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%7.2f",reading2);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{


	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}


sprintf(dummystring,"%7.2f",reading3);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

//*********************************************************************************
// Color limits
//*********************************************************************************

sprintf(dummystring,"%i",BlueLimit);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  

sprintf(dummystring,"%i",WhiteLimit);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

//***********************************************************************
// Added July 27, 2015
// These four values change the tolorances for color brighnest from the the DO and pH PWM.
//  The other two are the seeds for the start of the PWM search.  Once the unit finds the good PWM, it keeps in memory, not on the SD Card.
//***********************************************************************

sprintf(dummystring,"%i",PWMDOIntensity);    //Converts the varaible into a string. This is the seed PWM value for the DO
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%i",PWMPHIntensity);    //Converts the variable into a string.  This is the seed PWM value for the pH
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%i",PWMnh3Intensity);    //Converts the variable into a string.  This is the seed PWM value for the pH
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}


sprintf(dummystring,"%i",DOreadingrange);    //Converts the varaible into a string. This is the loight feedback range value for the DO
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%i",pHreadingrange);    //Converts the varaible into a string.  This is the light feedback range value for the pH
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}





configdata[zz]=0x7E;   //Place the tilda here to end the string
zz++;
configdata[zz]=0x00;  //End of line


//configdata = "123439,520,1950,420,500,1950,407,475,1950,11.5,4.0,0.0,8.4,4.0,0.0,7.0,4.0,0.0,208683.125,175036.875,119306.25,183777.5,186245.75,118059.5,154917.75,149782.0,117312.75,6.5,7.4,9.0,40,20,6,5140,12120,22594,6000,120000,123439,520,1950,420,500,1950,407,475,1950,11.5,4.0,0.0,8.4,4.0,0.0,7.0,4.0,0.0,208683.125,175036.875,119306.25,183777.5,186245.75,118059.5,154917.75,149782.0,~";

MakeFile("Cal.txt");   //This makes the default file.

//***********************************************************************
// Created July 27, 2015
//  This routine is added to help save more characters to the SD Card. 
// Currently only 255 characers can be saved at one routine call.
//  This routine splits the array into section of 200 and ends it with a zero to append it to the end
// of the same file.
//***********************************************************************

for (cc = 0; cc < 2; cc++)
	{
	for (rr=0; rr < 200; rr++)
		{ 
		tempconfigdata[rr] = configdata[cc*200+rr];
		}
		rr++;
		tempconfigdata[rr]= '\r';
		rr++;
		tempconfigdata[rr]= '\n';    //Set to the end of the line for saving into the file.
		rr++;
		tempconfigdata[rr]= 0x00;
		AppendFile("Cal.txt", &tempconfigdata);   // Now put the default information into the file.
	}
	

returnedfileerror = PrintFile("CAL.txt", 0); 

		Display_XYString(0,0, "CAL data saved");
        fprintf(BT,"CAL data saved.  Wait for data return.\n\r");
//Re-read the data and make sure it got saved.
	if (returnedfileerror == 0)
		{
		Display_XYString(0,3, &scr);
		}


	return(0);
	}

#else


//*****************************************************************************************
// Creaded July 22, 2015
// Changed over to EEPROM May 6, 2016
//  This routine saves the current calibration onto the EEPROM
//  The old data is first deleted and then an new one is overwritten in its place.
//  There is nothing return.  All data it takes is global varaibles.
//  Flushing may be required.  
//  The lengther of each line of data is not longer thatn 256 bytes.
// The First address of the data is a 0x0110   The next is as 0x0210.  
//  0x0010 contains the WIFI configuration.
// ****************************************************************************************



int SaveCalEEPROM(void)
	{
char configdata[400];
char tempconfigdata[256];
char dummystring[20];  //Added July 22, 2015  This is used to convert the number into a string.
int zz,x,returnedfileerror,result,junk,temptrans,cc,rr;
//make sure you are pointing to root


zz=0;
//Make a new file and save the current configurations

//compile the string to save in the EEPROM

temptrans = (int) Temp1ReadingOne;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
		configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}
temptrans = (int) Temp1ReadingTwo;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;     
	}

temptrans = (int) Temp1ReadingThree;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}


temptrans = (int) Temp2ReadingOne;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }                   




temptrans = (int) Temp2ReadingTwo;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
   }


temptrans = (int) Temp2ReadingThree;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  



temptrans = (int) Temp3ReadingOne;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  

temptrans = (int) Temp3ReadingTwo;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	
        configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
   }


temptrans = (int) Temp3ReadingThree;
sprintf(dummystring,"%i",temptrans);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{
	if (dummystring[x] != 0x20)
		{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }   
	}

//***********************************************************************
// Start for DO readings
//***********************************************************************



sprintf(dummystring,"%7.2f",Temp1DOOne);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  


sprintf(dummystring,"%7.2f",Temp1DOTwo);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }



sprintf(dummystring,"%7.2f",Temp1DOThree);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  





sprintf(dummystring,"%7.2f",Temp2DOOne);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  


sprintf(dummystring,"%7.2f",Temp2DOTwo);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }   



sprintf(dummystring,"%7.2f",Temp2DOThree);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  





sprintf(dummystring,"%7.2f",Temp3DOOne);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  


sprintf(dummystring,"%7.2f",Temp3DOTwo);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  



sprintf(dummystring,"%7.2f",Temp3DOThree);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  


//******************************************************************************
// Created May 7, 2016
// Add this data to the EEPROM at address 0x0110

configdata[zz]=0x7E;   //Place the tilda here to end the string
zz++;
configdata[zz]=0x00;  //End of line


// Save to data area 0x0110
returnedfileerror = WriteITwoSeeString(0x0110, configdata);  // Save the data   This need to be less than 255 or it can not read it later



        fprintf(BT,"CAL data saved 0x0110.  Wait for data return.\n\r");
//Re-read the data and make sure it got saved.
	if (returnedfileerror == 0)
		{
		Display_XYString(0,3, &configdata);
		}


zz=0;

//******************************************************************************

//******************************************************************************
// ph readings
//******************************************************************************


sprintf(dummystring,"%7.2f",datatable[0]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[1]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[2]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[3]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[4]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[5]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[6]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[7]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[8]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[9]);    //This is the vaiable used for pH offset calibration.  It's a pH number.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}



sprintf(dummystring,"%7.2f",datatable[10]);    //This is the vaiable used for pH offset calibration.  It's the red number for the calibration of the pH.  Chenged Aug 28, 2015  Switched datatable 9 and 10.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}




sprintf(dummystring,"%7.2f",datatable[11]);    //Currently not used.   Augest 17, 2015
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

//**********************************************************************************
//  Thermister calibration
//**********************************************************************************


sprintf(dummystring,"%7.2f",temp1);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}
sprintf(dummystring,"%7.2f",temp2);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%7.2f",temp3);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}




sprintf(dummystring,"%7.2f",reading1);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%7.2f",reading2);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{


	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}


sprintf(dummystring,"%7.2f",reading3);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

//*********************************************************************************
// Color limits
//*********************************************************************************

sprintf(dummystring,"%i",BlueLimit);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
  }  

sprintf(dummystring,"%i",WhiteLimit);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

//***********************************************************************
// Added July 27, 2015
// These four values change the tolorances for color brighnest from the the DO and pH PWM.
//  The other two are the seeds for the start of the PWM search.  Once the unit finds the good PWM, it keeps in memory, not on the SD Card.
//***********************************************************************

sprintf(dummystring,"%i",PWMDOIntensity);    //Converts the varaible into a string. This is the seed PWM value for the DO
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%i",PWMPHIntensity);    //Converts the variable into a string.  This is the seed PWM value for the pH
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%i",PWMnh3Intensity);    //Converts the variable into a string.  This is the seed PWM value for the pH
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}


sprintf(dummystring,"%i",DOreadingrange);    //Converts the varaible into a string. This is the loight feedback range value for the DO
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}

sprintf(dummystring,"%i",pHreadingrange);    //Converts the varaible into a string.  This is the light feedback range value for the pH
for (x=0; x < 20; x++)
	{

	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
}


configdata[zz]=0x7E;   //Place the "~" here to end the string
zz++;
configdata[zz]=0x00;  //End of line


//configdata = "123439,520,1950,420,500,1950,407,475,1950,11.5,4.0,0.0,8.4,4.0,0.0,7.0,4.0,0.0,208683.125,175036.875,119306.25,183777.5,186245.75,118059.5,154917.75,149782.0,117312.75,6.5,7.4,9.0,40,20,6,5140,12120,22594,6000,120000,123439,520,1950,420,500,1950,407,475,1950,11.5,4.0,0.0,8.4,4.0,0.0,7.0,4.0,0.0,208683.125,175036.875,119306.25,183777.5,186245.75,118059.5,154917.75,149782.0,~";

returnedfileerror = WriteITwoSeeString(0x0210, configdata);   // This saves the second set of data.  This need to be less than 256 characters or it can not be read.


        fprintf(BT,"CAL data saved 0x0210.  Wait for data return.\n\r");
//Re-read the data and make sure it got saved.
	if (returnedfileerror == 0)
		{
		Display_XYString(0,3, &configdata);
		}

     
        
 zz=0;
//Make a new file and save the current configurations

//compile the string to save in the file



sprintf(dummystring,"%f",eccalibrationx[0]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec ppm value for high
for (x=0; x < 20; x++)
	{
		configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}
sprintf(dummystring,"%f",eccalibrationx[1]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec ppm value for mid
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;     
	}

sprintf(dummystring,"%f",eccalibrationx[2]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec ppm value for low
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}

sprintf(dummystring,"%f",eccalibrationy[0]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec input value for high
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}

sprintf(dummystring,"%f",eccalibrationy[1]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec input value for mid
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}

sprintf(dummystring,"%f",eccalibrationy[2]);    //Converts the varible into a string.  This makes it easy to do all of the varaibles.  set the ec input value for low
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}


configdata[zz]=0x7E;   //Place the tilda here to end the string
zz++;
configdata[zz]=0x00;  //End of line

returnedfileerror = WriteITwoSeeString(0x0310, configdata);   // This saves the second set of data.  This need to be less than 256 characters or it can not be read.

        fprintf(BT,"CAL data saved 0x0310.  Wait for data return.\n\r");
//Re-read the data and make sure it got saved.
	if (returnedfileerror == 0)
		{
		Display_XYString(0,3, &configdata);
		}



	return(0);
	}




#endif


#ifndef EEPROMCONFIG
//******************************************************************************
//Created September 14, 2015
//This routine loads in the current list of BT devices that it needs to scan through connection to get their data.
// There is no input.
// The serical number of the BT device is first and then the connection name or the AT+RNAME
// The list is a seriers of serical numbers for each BT list.  It ends with a comma and a "~"   
//******************************************************************************
void ReadBTFile(char *fileName)
	{

int returnedfileerror,x;
int y = 0;  // This is the device counter for the main parsing loop.
 

	returnedfileerror = PrintFile(fileName, 0);   //try to print the file and see if it exsits.  If not, then make it exist with default values.

	if (returnedfileerror == 0)
		{
	//	Display_XYString(0,3, &scr);
		}
		else
		{
		Display_XYString(0, 1, "error opening BT.txt");
		if (returnedfileerror == 2)	   // Check to see if there is an SD Card but no file.
			{
			// This means there is a card but no file
			MakeFile("BT.txt");   //This makes the default file.
			AppendFile("BT.txt", ",~");   // Now put the default information into the file.
			returnedfileerror = PrintFile(fileName, 0); 
			if (returnedfileerror == 0)
			{
				Display_XYString(0,3, &scr);
			}
			}
		}
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015
split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global varialbes   SplitResult[20][20];

// The results is veraible.  It can be from 0 to many.  The last on ends with a "~".  The items are saved in an array stucture. 

while(SplitResult[0][y]!="~")
	{

for (x=0; x < 20; x++)
	{
	sysOutput.deviceID[x] = SplitResult[0][x];
	if ( SplitResult[0][x] == 0)
		{
		sysOutput.deviceID[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
	}


MaxBTScanningNumber = y;  //Save the max number of BT deivces to cycle through.


return;
	}

#endif

#ifndef EEPROMCONFIG


//*****************************************************************************************
// Creaded September 15, 2015
//  This routine saves the current calibration for ec onto the SD Card.
//  The old file is first deleted and then an new one is overwritten in its place.
//  There is nothing return.  All data it takes is global varaibles.
//  Flushing may be required.  
// ****************************************************************************************


int SaveCalibrationsTwo(void)
	{
char configdata[400];
char tempconfigdata[256];
char dummystring[20];  //Added July 22, 2015  This is used to convert the number into a string.
int zz,x,returnedfileerror,result,junk,cc,rr;
//make sure you are pointing to root



junk = ChangeDirectory("..");




/*

   "echigh",           // set the ec ppm value for high
   "ecmid",           // set the ec ppm value for mid
   "eclow",           // set the ec ppm value for low
   "ecvalh",           // set the ec input value for high
   "ecvalm",           // set the ec input value for mid
   "ecvall"           // set the ec input value for low

*/


//delete the current file

result = DeleteFile("Cal2.txt");

zz=0;
//Make a new file and save the current configureations

//compile the string to save in the file



sprintf(dummystring,"%f",eccalibrationx[0]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec ppm value for high
for (x=0; x < 20; x++)
	{
		configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;
	}
sprintf(dummystring,"%f",eccalibrationx[1]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec ppm value for mid
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;     
	}

sprintf(dummystring,"%f",eccalibrationx[2]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec ppm value for low
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}

sprintf(dummystring,"%f",eccalibrationy[0]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec input value for high
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}

sprintf(dummystring,"%f",eccalibrationy[1]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec input value for mid
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}

sprintf(dummystring,"%f",eccalibrationy[2]);    //Converts the varaible into a string.  This makes it easy to do all of the varaibles.  set the ec input value for low
for (x=0; x < 20; x++)
	{
	configdata[zz] = dummystring[x];
	if ( dummystring[x] == 0)
		{
		configdata[zz]=0x2C;  //This is the end of string for the serial number with a comma
		zz++;
		break;
		}
	zz++;    
	}










configdata[zz]=0x7E;   //Place the tilda here to end the string
zz++;
configdata[zz]=0x00;  //End of line

MakeFile("Cal2.txt");   //This makes the default file.

//***********************************************************************
// Created July 27, 2015
//  This routine is added to help save more characters to the SD Card. 
// Currently only 255 characers can be saved at one routine call.
//  This routine splits the array into section of 200 and ends it with a zero to append it to the end
// of the same file.
//***********************************************************************

for (cc = 0; cc < 2; cc++)
	{
	for (rr=0; rr < 200; rr++)
		{ 
		tempconfigdata[rr] = configdata[cc*200+rr];
		}
		rr++;
		tempconfigdata[rr]= '\r';
		rr++;
		tempconfigdata[rr]= '\n';    //Set to the end of the line for saving into the file.
		rr++;
		tempconfigdata[rr]= 0x00;
		AppendFile("Cal.txt", &tempconfigdata);   // Now put the default information into the file.
	}
	

returnedfileerror = PrintFile("CAL2.txt", 0); 


		Display_XYString(0,0, "CAL2 data saved");
        fprintf(BT,"CAL2 data saved.  Wait for data return.\n\r");
//Re-read the data and make sure it got saved.
	if (returnedfileerror == 0)
		{
		Display_XYString(0,3, &scr);
		}


	return(0);
	}

#endif


#ifndef EEPROMCONFIG
//******************************************************************************
// Created September 15, 2015
// This routine reads the second calibtation file.
// In this case there is only EC in the file.
// Filename is called Cal2.txt
//******************************************************************************
void ReadCalibrationTwo(char *fileName)
	{

int returnedfileerror,x;
int changefolder;
char tempholder[20];  //This is used for collecting the string of characters from SD Card for Cal and later converting them into a real float value.





changefolder = ChangeDirectory("..");   // Go back up to root for the next data point.   This goes back to root

	returnedfileerror = PrintFile(fileName, 0);   //try to print the file and see if it exsits.  If not, then make it exist with default values.

	if (returnedfileerror == 0)
		{
	//	Display_XYString(0,3, &scr);
		}
		else
		{
		Display_XYString(0, 1, "error opening Cal2.txt");
		if (returnedfileerror == 2)	   // Check to see if there is an SD Card but no file.
			{
			// This means there is a card but no file
			MakeFile("Cal2.txt");   //This makes the default file.
			AppendFile("Cal2.txt", "447.0,44.0,19.0,33.0,481.0,1718.0,~");   // Now put the default information into the file.
			returnedfileerror = PrintFile(fileName, 0); 
			if (returnedfileerror == 0)
			{
				Display_XYString(0,3, &scr);
			}
			}
		}
// Now that we have the file made from nature or artifical means, parse the data and present it to the system  Created March 25, 2015
split(&scr, ",", "~");

// After splitting the tokens, they are placed in their global varialbes   SplitResult[20][20];

//**********************************************************************************
// First data point as raw data

//This token is for "eccalibrationx[0]"

for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[0][x];
	if ( SplitResult[0][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for this number.  When the string is completed, then convert it into a float.
		break;
		}
	}
// Convert the string on the array into a float.
eccalibrationx[0] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "eccalibrationx[1]"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[1][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationx[1] =  atof(tempholder);  //This converts the number from string to float.

//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "eccalibrationx[2]"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[2][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationx[2] =  atof(tempholder);  //This converts the number from string to float.




//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "eccalibrationy[0]"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[3][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationy[0] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "eccalibrationy[0]"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[4][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationy[1] =  atof(tempholder);  //This converts the number from string to float.


//  Once it is in the array, save it in the Serial number global variable.
#if SDCardDisplay
				Display_XYString(0,2, &tempholder);
#endif
//This token is for "eccalibrationy[0]"
for (x=0; x < 20; x++)
	{
	tempholder[x] = SplitResult[5][x];
	if ( SplitResult[1][x] == 0)
		{
		tempholder[x]=0x00;  //This is the end of string for the serial number
		break;
		}
	}
eccalibrationy[2] =  atof(tempholder);  //This converts the number from string to float.


return;
	}
#endif

//*******************************************************************************************
// Created Jan 10, 2017
// This routine asks the server for the next avalaible serial number.  It is only used when the 
// board is brought up for the first time. If there is no error, then the serial number is updated
// and replaces PaulsBoard
// A 0 is returned if there is no error
// A 1 is returned if the returened data is not a number.
// This is assuming this routine is called if PaulsBoard is the serial Number and is connected to the server
//*******************************************************************************************
int GetNextSerialNumber(void)
{
    int t;
    char FinalHTTP[BUFFERSIZE];

    
    sprintf(FinalHTTP,"GET /nextserialnumber.php HTTP/1.1\r\nHost: osmobot.org\r\n\r\n");   //This sends the whole sting into the buffer.  Nothing needs to be parsed when it comes out.

 	fprintf(WIFI,"%s",FinalHTTP);   //Send the data off to the server.
	fprintf(BT,"%s\n\r",FinalHTTP);   //Send the data off to the server and send it to the connected bluetooth unit for display read.   
    
for (t=0; t < 20; t++)
{
delay_ms(1000);
if ((ACKFROMSERVER != 0) && (!BTMeasureTimer))
	{
    return(0);
    } 
}
      
    return(0);
}


//******************************************************************************
// Created Jan 17, 2017
// This routine asks the server for the next block of FW data if a new version of firmware is a vaiable.
// A 0 is returned if all is well.
// A 1 is returned with an error from the server.
// The data received is later in the main while loop routine.
// Each pieces of block of FW is saved in EEPROM upper memory.
// This routine calls a routine to sort through when a FW is correct and when it is completed and ready for programming the CPU.  
// The FW is programmed/copied from the EEPROM in to the main memory through the bootloader.
//******************************************************************************
int GetNextFirmWareBlock(void)
{
   int t;
    char FinalHTTP[BUFFERSIZE];

    
    sprintf(FinalHTTP,"GET /OsmobotFW.php?startline=%i HTTP/1.1\r\nHost: osmobot.org\r\n\r\n",blocklocation);   //This sends the whole sting into the buffer.  Nothing needs to be parsed when it comes out.

 	fprintf(WIFI,"%s",FinalHTTP);   //Send the data off to the server.
	fprintf(BT,"%s\n\r",FinalHTTP);   //Send the data off to the server and send it to the connected bluetooth unit for display read.   
    
for (t=0; t < 20; t++)
{
delay_ms(1000);
if ((ACKFROMSERVER != 0) && (!BTMeasureTimer))
	{
    return(0);   // return if there is something to look at.
    } 
}
      
    return(1);    // return if nothing came back.
    
    
}

