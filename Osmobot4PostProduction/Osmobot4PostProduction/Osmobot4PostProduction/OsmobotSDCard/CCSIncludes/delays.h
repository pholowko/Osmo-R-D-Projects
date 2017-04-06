/////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2012 Custom Computer Services         ////
//// This source code may only be used by licensed users of the CCS  ////
//// C compiler.  This source code may only be distributed to other  ////
//// licensed users of the CCS C compiler.  No other use,            ////
//// reproduction or distribution is permitted without written       ////
//// permission.  Derivative programs created using this software    ////
//// in object code form are not restricted in any way.              ////
/////////////////////////////////////////////////////////////////////////

/// file compatible with C18's delays.h

/// just provides prototypes.  to get the functions you also need to
/// add the p18cxxx.c to your project.

#ifndef __DELAYS_H__
#define __DELAYS_H__

/*
   definitions that we are porting:

   void Delay1TCY ( void ); // Delay one instruction cycle. 
   void Delay10TCYx ( unsigned char unit ); // Delay in multiples of 10 instruction cycles. 
   void Delay100TCYx ( unsigned char unit ); // Delay in multiples of 100 instruction cycles. 
   void Delay1KTCYx ( unsigned char unit ); // Delay in multiples of 1,000 instruction cycles. 
   void Delay10KTCYx ( unsigned char unit ); // Delay in multiples of 10,000 instruction cycles. 
   
   Notes: 
   1. The letter ‘x’ in the function name above stands for ‘times’ or ‘multiplication’. It is not to be replaced by a number as done in some other function names. 
   2. unit is an 8-bit value in the range [0,255]. unit = 0 is equivalent to unit = 256. 
   3. TCY stands for ‘instruction cycle’. The 18F4550 is running at 20MHz oscillator frequency, but the internal frequency is 48MHz! 
   TCY = 4/48MHz = 1/12 us      
*/

#define PARAM_SCLASS

void Delay10TCYx(unsigned char x);
void Delay100TCYx(unsigned char x);
void Delay1KTCYx(unsigned char x);
void Delay10KTCYx(unsigned char x);

#endif