/////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2012 Custom Computer Services         ////
//// This source code may only be used by licensed users of the CCS  ////
//// C compiler.  This source code may only be distributed to other  ////
//// licensed users of the CCS C compiler.  No other use,            ////
//// reproduction or distribution is permitted without written       ////
//// permission.  Derivative programs created using this software    ////
//// in object code form are not restricted in any way.              ////
/////////////////////////////////////////////////////////////////////////

// CCS PCH C Compiler to Microchip C18 Compiler compatability layer.

#ifndef __P18CXXXX_H__
#define __P18CXXXX_H__

#case

#include "ccspics.h"

#device PASS_STRINGS=IN_RAM
#device CONST=READ_ONLY

#case
#type signed
#type short=16 int=16 long=32

#zero_ram
#zero_local_ram

#define _asm #asm
#define _endasm #endasm

#define COMPILER_MPLAB_C18

#define GetSystemClock()      getenv("CLOCK")
#define GetInstructionClock()   (GetSystemClock()/4)
#define GetPeripheralClock()   (unsigned int32)GetInstructionClock()

#if defined(__18F97J60) || defined(__18F96J65) || defined(__18F96J60) || defined(__18F87J60) || defined(__18F86J65) || defined(__18F86J60) || defined(__18F67J60) || defined(__18F66J65) || defined(__18F66J60)
   #reserve 0xE80:0xEFF
   #reserve 0xF00:0xFFF
#endif

#if defined(TRUE)
   #undef TRUE
#endif

#if defined(FALSE)
   #undef FALSE
#endif

#if defined(BYTE)
   #undef BYTE
#endif

      #define Reset()            reset_cpu()
        #define far
        #define ClrWdt()         restart_wdt()
      #define Nop()            delay_cycles(1)      

#define ultoa(a,b)   itoa(a,8,b)
      
signed int8 memcmppgm2ram(void * s1, rom char *s2, unsigned int8 n);
signed int8 strcmppgm2ram(char *s1, __ADDRESS__ s2);
char *strchrpgm(__ADDRESS__ s, unsigned int8 c);
char *strstrrampgm(char *s1, __ADDRESS__ s2);
unsigned int8 strlenpgm(__ADDRESS__ s);
void memcpypgm2ram(unsigned int8 *d, __ADDRESS__ s, unsigned int16 n);
//char* strupr(char *s);   now in string.h
void strcpypgm2ram(char *d, __ADDRESS__ s);
char *strcatpgm2ram(char * destination, rom char * source);

#define Delay1TCY() delay_cycles(1)
#define Delay10TCY() delay_cycles(10)

#endif
