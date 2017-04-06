//see about.txt in filesystem/ for information

#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

// If you cannot find these files, then change your include path
// to include the "CCSIncludes" directory.  This directory contains
// files that help port code from Microchip C to CCS C.
#if defined(__PCH__)
   #include <p18cxxx.h> //Microchip C18 C Compiler to CCS PCH Conversion
#elif defined(__PCD__)
   #define __CONST_IS_READONLY__ //work around for a difference between how CCS and C30 treats 'const' pointers
   #include <PCDxxxx.h>  //Microchip C30 C Compiler to CCS PCH Conversion
#else
   #error PIC18 or dsPIC/PIC24 support ONLY
#endif

#include "HardwareProfile.h"

#include "FSConfig.h"

#include "MDD File System\FSIO.h"

#endif
