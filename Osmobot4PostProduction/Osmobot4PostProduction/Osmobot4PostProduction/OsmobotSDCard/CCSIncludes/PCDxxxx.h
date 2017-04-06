/////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2012 Custom Computer Services         ////
//// This source code may only be used by licensed users of the CCS  ////
//// C compiler.  This source code may only be distributed to other  ////
//// licensed users of the CCS C compiler.  No other use,            ////
//// reproduction or distribution is permitted without written       ////
//// permission.  Derivative programs created using this software    ////
//// in object code form are not restricted in any way.              ////
/////////////////////////////////////////////////////////////////////////

// pcdxxxx.h
//
// Microchip C30 to CCS conversion library.

#ifndef __PCDXXXX_H__
#define __PCDXXXX_H__

#case

#include "ccspics.h"

//#device PSV=16   this is done sooner in the code
/*
#if defined(__CONST_IS_READONLY__)
   #device CONST=READ_ONLY
#else
   //this is normally how C30 operates
   #device CONST=ROM
#endif

#device PASS_STRINGS=IN_RAM
*/

#type signed
#type short=16 int=16 long=32

#zero_ram
#zero_local_ram

#if defined(TRUE)
#undef TRUE
#endif

#if defined(FALSE)
#undef FALSE
#endif

#if defined(BYTE)
#undef BYTE
#endif

#if defined(BOOLEAN)
#undef BOOLEAN
#endif

#define GetSystemClock()       getenv("CLOCK")
#define GetInstructionClock()  (GetSystemClock()/2)
#define GetPeripheralClock()   (GetSystemClock()/2)

//#define Reset()            reset_cpu()   //not needed, this is defined in Microchip's Compiler.h
//#define FAR                        //not needed, this is defined in Microchip's Compiler.h

#define ClrWdt()         restart_wdt()

#define Nop()            delay_cycles(1)

//#warning need eds support
#define __eds__

#define __prog__  rom

#define __C30__

#define __CCS_STDLIB_DYNAMIC_MEMORY__

#endif
