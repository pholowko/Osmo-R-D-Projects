////////////////////////////////////////////////////////////////////////////////
//
// sst25vf_mdd.c
//
// Microchip MDD Library <-> CCS SST25VF Driver layer
//
////////////////////////////////////////////////////////////////////////////////
////                                                                        ////
////        (C) Copyright 1996, 2011 Custom Computer Services               ////
////  This source code may only be used by licensed users of the CCS C      ////
////  compiler.  This source code may only be distributed to other          ////
////  licensed users of the CCS C compiler.  No other use, reproduction     ////
////  or distribution is permitted without written permission.              ////
////  Derivative programs created using this software in object code        ////
////  form are not restricted in any way.                                   ////
////                                                                        ////
////////////////////////////////////////////////////////////////////////////////

// standard header files for MDD library
#include "Compiler.h"
#include "MDD File System/FSIO.h"
#include "GenericTypeDefs.h"
#include "MDD File System/FSDefs.h"

// configure CCS's sst25vf driver
#define FLASH_SIZE         USE_SST25_INTERFACE
#define FLASH_SECTOR_SIZE  MEDIA_SECTOR_SIZE 

#if 0
#error/warning TEMPORARY CODE
#define FLASH_STREAM
#define FLASH_XFER   FlashXfer
unsigned int16 FlashXfer(unsigned int16 d)
{
   bit_clear(*0x260, 6); //overflow
   (int16*)*0x268 = d;
   while(bit_test(*0x260, 1));
   while(!bit_test(*0x260, 0));
   d = (int16*)*0x268;
   return(d);
}
#endif

// include CCS's sst25vf driver
#include "_sst25vf.c"

static MEDIA_INFORMATION mediaInformation;

MEDIA_INFORMATION *  MDD_MediaInitialize(void)
{
   #if 0
   #error/warning TEMPORARY CODE
   (int16*)*0x264 = (int16)0;
   (int16*)*0x262 = (int16)0x013A;
   (int16*)*0x260 = (int16)0x8000;
//   output_drive(PIN_G6);
 //  output_float(PIN_G7);
   output_drive(PIN_G8);
   #endif
   
   ext_flash_init();
   ext_flash_protect(FLASH_PROTECT_NONE);
   memset(&mediaInformation, 0x00, sizeof(mediaInformation));
   mediaInformation.errorCode = MEDIA_NO_ERROR;    //assume always success
   mediaInformation.validityFlags.bits.sectorSize = TRUE;
   mediaInformation.sectorSize = MEDIA_SECTOR_SIZE;
   return(&mediaInformation);
}

// returns TRUE if media is detected
BYTE MDD_MediaDetect (void)
{
   return(TRUE);  //assume always connected
}

// returns TRUE if sector read correctly.
BYTE MDD_SectorRead(DWORD sector_addr, BYTE* buffer)
{
   DEBUG_FS_STR("MDD_SectorRead()", sector_addr);
   sector_addr *= MEDIA_SECTOR_SIZE;
   ext_flash_read(sector_addr, buffer, MEDIA_SECTOR_SIZE);
   return(TRUE);  //assume always success
}

// allowWriteToZero is TRUE if writes to the MBR (sector 0) are allowed.
// returns TRUE if sector written correctly.
BYTE MDD_SectorWrite(DWORD sector_addr, BYTE* buffer, BYTE allowWriteToZero)
{
   if ((sector_addr == 0) && (!allowWriteToZero))
   {
      DEBUG_FS_STR2("MDD_SectorWrite()", "NO SEC 0 WRITE");
      return(FALSE);
   }
   DEBUG_FS_STR("MDD_SectorWrite()", sector_addr);
   sector_addr *= MEDIA_SECTOR_SIZE;
   ext_flash_address_erase(sector_addr, FLASH_ERASE_BLOCK_4KB);
   ext_flash_write(sector_addr, buffer, MEDIA_SECTOR_SIZE);
   return(TRUE);  //assume always success
}

void MDD_InitIO(void)
{
   ext_flash_init();
   ext_flash_protect(FLASH_PROTECT_NONE);
}

BYTE MDD_ShutdownMedia(void)
{
   return(0);
}

// returns TRUE if chip is write protected.
BYTE MDD_WriteProtectState(void)
{
   return(FALSE);
}
    
// returns capacity of device
DWORD MDD_ReadCapacity(void)
{
   return(USE_SST25_INTERFACE);
}
    
WORD MDD_ReadSectorSize(void)
{
    return(MEDIA_SECTOR_SIZE);
}
