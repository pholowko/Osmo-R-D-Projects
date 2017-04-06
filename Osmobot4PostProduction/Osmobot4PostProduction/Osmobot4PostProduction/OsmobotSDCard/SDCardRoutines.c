
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
#define MEDIA_SOFT_DETECT    //This means it uses talking to the card to see if there is a card present
//#define __DEBUG_UART

#define ALLOW_GET_DISK_PROPERTIES   //used by 'info' command

#include "Osmobotsdcard\ex_mdd_common.h"

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

   char scr[65];

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
void DisplayPrompt(void)
{
   char scr[65], *p;

   if (g_IsMounted)
   {
      p = FSgetcwd(scr, sizeof(scr)-1);
      if (!p)
      {
         sprintf(scr, "!!!ERROR!!!");
      }
   }
   else
   {
      sprintf(scr, "!!!NOT MOUNTED!!!");
   }

   printf("\r\n\n%s> ", scr);
}

/*
Summary: Deletes a file.
Param: The full path of the file to delete.
Returns: None.
*/
void DeleteFile(char *fileName)
{
   if (!g_IsMounted)
   {
      printf("\r\nMedia not mounted, not going to delete file!");
      return;
   }

   //printf("\r\nDeleting '%s': ", fileName);
   if(FSremove(fileName))
   {
      printf("Error deleting file");
      return;
   }
   printf("OK");
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
      printf("\r\nMedia not mounted, not going to make file!");
      return;
   }

 //  printf("\r\nMaking file '%s': ", fileName);

   f = FSfopen (fileName, "w");
   if (!f)
   {
      printf("Error (open error %X)", FSerrno);
   }
   else
   {
      ret = FSfclose(f);
      if (ret)
      {
         printf("Error (close error %X %X)", ret, FSerrno);
      }
      else
      {
         printf("OK");
      }
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
   char newLine[]="\r\n";
   int ret;

   if (!g_IsMounted)
   {
      printf("\r\nMedia not mounted, not going to append file!");
      return;
   }

   printf("\r\nAppending '%s' to '%s': ", appendString, fileName);
   f = FSfopen(fileName, "a");
   if(!f)
   {
      printf("Error (%X)", FSerrno);
      return;
   }

   FSfwrite(appendString, sizeof(char), strlen(appendString), f);
   FSfwrite(newLine, sizeof(char), strlen(newLine), f);

   ret = FSfclose(f);
   if(ret)
   {
      printf("Error (%X %X)", ret, FSerrno);
      return;
   }
   printf("OK");
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
void ChangeDirectory(char *newCWD)
{
   if (!g_IsMounted)
   {
      printf("\r\nMedia not mounted, not going to change directory!");
      return;
   }

   if (FSchdir(newCWD))
   {
      printf("\r\nError changing directory");
   }
}

/*
Summary: Display the contents of the working directory.
Param: The full path of the directory contents to display.
Returns: None.
Example Usage: /> dir
*/
void DisplayDirectory(void)
{
   SearchRec s;
   int ret;
   char str[20];

   if (!g_IsMounted)
   {
      printf("\r\nMedia not mounted, not going to display directory!");
      return;
   }

   memset(&s, 0x00, sizeof(s));

   ret = FindFirst("*.*", ATTR_MASK, &s);

   for(;;)
   {
      if (ret != 0)
      {
         printf("\r\n\nDirectory search completed");

         if (FSerrno != CE_FILE_NOT_FOUND)
         {
            printf(" (FSerrno = %u)", FSerrno);
         }
         break;
      }

      if ((s.attributes & ATTR_VOLUME) != ATTR_VOLUME)
      {
         if ((s.attributes & ATTR_DIRECTORY) == ATTR_DIRECTORY)
            sprintf(str, "<DIR>  ");
         else
            sprintf(str, "       ");

         printf("\r\n%lu\t\t%s%s", s.filesize, str, s.filename);
      }

      ret = FindNext(&s);
   }
}

/*
Summary: Create a directory.
Param: The full path of the directory to create.
Returns: None.
Example Usage: /> mkdir "Backlog"
*/
void MakeDirectory(char *dir)
{
   if (!g_IsMounted)
   {
      printf("\r\nMedia not mounted, not going to make directory!");
      return;
   }

   printf("\r\nMaking directory '%s': ", dir);

   if(FSmkdir(dir))
   {
      printf("Error creating directory (FSerrno = %u)", FSerrno);
      return;
   }
   printf("OK");
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
      printf("\r\nMedia not mounted, not going to remove directory!");
      return;
   }

   printf("\r\nRemoving directory '%s': ", dir);

   if(FSrmdir(dir, FALSE))
   {
      printf("Error removing directory");
      return;
   }
   printf("OK");
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
void PrintFile(char *fileName, int1 startFromEnd)
{
 //  char scr[65];
   size_t len;
   FSFILE* f;

   if (!g_IsMounted)
   {
      printf("\r\nMedia not mounted, not going to display file!");
      return;
   }

   f = FSfopen(fileName, "r");
   if (!f)
   {
      printf("\r\nError opening file (Error %X)", FSerrno);
      return;
   }

   printf("\r\n");

   if(startFromEnd)
      FSfseek(f, 80, SEEK_END);

   do
   {
      len = FSfread(scr, sizeof(char), (sizeof(scr)-1), f);
      if (FSerrno && (FSerrno != CE_EOF))
      {
         printf("\r\n!!! Error reading file (Error %X)", FSerrno);
         len = 0;
         break;
      }
      if (len)
      {
         scr[len] = 0;
         //DEBUG_STR("PrintFile() got", len);
         printf("%s", scr);
      }
   } while(FSerrno != CE_EOF);

   FSfclose(f);
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
		TRISGbits.TRISG9 = OUTPUT;
		PORTGbits.RG9 =  0;
		//output_low(PIN_SDPOWER);
		}	
	if (state == 1)
		{
		TRISGbits.TRISG9 = OUTPUT;
		PORTGbits.RG9 =  1;
		}
	}


void MountMedia(void)
{
   g_IsMounted = FALSE;


PowerSDCard(0);  //Power up the card
	

   MDD_InitIO();

   if (!MDD_MediaDetect())
   {
      printf("\r\nError, Media not found!");
      return;
   }

   if (FSInit())
   {
      g_IsMounted = TRUE;

      printf("\r\nOK (Sector Size=%LU, Sec Per Clus=%U, Type=%U)",
            gDiskData.sectorSize,
            gDiskData.SecPerClus,
            gDiskData.type
         );
   }
   else
   {
      printf("\r\nError, file system not mounted (FSerrno=%U)!!!", FSerrno);
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
   printf("\r\nError, formatting disabled!!!");
  #else
   uint32_t size;
   int scr;
   int1 ok = FALSE;
   char c;
   MEDIA_INFORMATION *m;

   #define MEDIA_SERIAL_NUMBER   "123"
   #define MEDIA_VOLUME_ID       "123"

   g_IsMounted = FALSE;

   MDD_InitIO();

   if (!MDD_MediaDetect())
   {
      printf("\r\nError, media not found!");
      return;
   }

   m = MDD_MediaInitialize();
   if (m->errorCode != MEDIA_NO_ERROR)
   {
      printf("\r\nMedia not initialized (ec = %X), media not formatted!", m->errorCode);
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

   printf("\r\nFormatting media (size=%LU, sector size=%LU): ", size, MEDIA_SECTOR_SIZE);

   if (!FSCreateMBR(1, size/MEDIA_SECTOR_SIZE))
   {
      if (!FSformat (1, MEDIA_SERIAL_NUMBER, MEDIA_VOLUME_ID))
      {
         ok = TRUE;
      }
   }

   if(!ok)
   {
      printf("Error formatting media");
      return;
   }

   MountMedia();
  #endif
}

void MediaInfo(void)
{
   FS_DISK_PROPERTIES p;



   if (g_IsMounted)
   {
      printf("\r\nGetting media info (this may take seconds to minutes)...");
      p.new_request = TRUE;

      do
      {
         FSGetDiskProperties(&p);
      } while(p.properties_status == FS_GET_PROPERTIES_STILL_WORKING);

      if (p.properties_status == FS_GET_PROPERTIES_DISK_NOT_MOUNTED)
      {
         printf("\r\n\nFile system thinks media isn't mounted, try mounting again!");
      }
      else if (p.properties_status != FS_GET_PROPERTIES_NO_ERRORS)
      {
         printf("\r\n\nError getting info");
      }
      else
      {
         printf("\r\n\nBytes per sector: %LU", p.results.sector_size);
         printf("\r\nSectors per cluster: %U", p.results.sectors_per_cluster);
         printf("\r\nTotal size of media: %LU", p.results.total_clusters*p.results.sectors_per_cluster*p.results.sector_size);
         printf("\r\nFree space of media: %LU", p.results.free_clusters*p.results.sectors_per_cluster*p.results.sector_size);
      }
   }
   else
   {
      printf("\r\nMedia not mounted, not getting info!");
   }
}

/*
Summary: Shows a help prompt.
Param: None.
Returns: None.
Example Usage: /> help
*/
void ShowHelp()
{
   printf("\r\nFAT Shell Help - Compiled with CCS C Compiler ");
  #if defined(__PCD__)
   printf("PCD ");
   printf(__PCD__);
  #else
   printf("PCH ");
   printf(__PCH__);
  #endif
   printf("\r\n mount --- initialize and mount file system.  required before file access");
   printf("\r\n del filename --- Deletes the file");
   printf("\r\n make filename --- Creates an empty file");
   printf("\r\n append filename string --- Appends string to the end of the file");
   printf("\r\n cd dir --- Change the working directory");
   printf("\r\n dir --- Shows the contents of the directory");
   printf("\r\n cat filename --- Displays content of file");
   printf("\r\n tail filename --- Displays the last 80 characters of file");
   printf("\r\n mkdir dir --- Create a directory");
   printf("\r\n rmdir dir --- Deletes the directory");
   printf("\r\n format size --- Format card.  (Example: 'format 536870912' -or- 'format 512M' ");
   printf("\r\n                 formats a 512MB card).  Creates MBR and Partition 0.  This is ");
   printf("\r\n                 not recommended on devices which you can use a computer to");
   printf("\r\n                 format the drive (such as an SD or CF device).");
   printf("\r\n info --- Show some info about the media/file system.  Can take several seconds!");
   printf("\r\n help\tYou are here");
   printf("\r\n\n Put a parameter in quotes if it has spaces");

   DEBUG_STR("SPICON1", SPICON1);
   DEBUG_STR("SPISTAT", SPISTAT);
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



//*************************************************************************
//Created January 27, 2015
// This routine splits all of the data from a string into integers with a delimmeiter of a ","
// Numbers in this splitter are changed to integersa and numbers.
//*************************************************************************





//*************************************************************************
//Created January 27, 2015
// This routine reads the SDCard Calib.txt and sets all of the instrumentation calibration values.
//  This routine is run at the beginiing when Osmobot is setting up.
//************************************************************************

void ReadOsmobotCalibration(char *fileName)
	{

	PrintFile(fileName, 0);
	Display_XYString(0, 1, &scr);


	}



/*
void main(void)
{
   char buffer[255];
   char *cmd, *option1, *option2;

   int i;   // pointer to the buffer





 //  HW_INIT();


   //printf("\r\n\nex_fat.c - MDD Example");
MountMedia();

            if (!g_IsMounted)
            {
               sprintf(buffer, "mount");
            }
            else
            {
               sprintf(buffer, "append log.txt button pressed!!");
            }


   // main loop


//option1 = GetOption(cmd + strlen(cmd) + 1);
//MakeFile("testfile.txt");

AppendFile("testfile.txt", "Hello World");




*/