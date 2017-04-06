/////////////////////////////////////////////////////////////////////////
////
//// ex_mdd_common.h
////
//// Common header file for CCS's MDD examples
////
/////////////////////////////////////////////////////////////////////////
////        (C) Copyright 2007 Custom Computer Services              ////
//// This source code may only be used by licensed users of the CCS  ////
//// C compiler.  This source code may only be distributed to other  ////
//// licensed users of the CCS C compiler.  No other use,            ////
//// reproduction or distribution is permitted without written       ////
//// permission.  Derivative programs created using this software    ////
//// in object code form are not restricted in any way.              ////
/////////////////////////////////////////////////////////////////////////

//#define HW_CCS_3V_ETHERNET
//#define HW_CCS_DSP_AUDIO    //dsPIC33FJ
//#define HW_CCS_DSP_AUDIO2   //dsPIC33EP
#define HW_CCS_PIC24USB



#if defined(HW_CCS_PIC24USB)
 //  #include <24FJ256GA106.h>

//   #fuses HS,PR_PLL,NOWDT,ICSP2,PLL5  did noy like
//   #fuses HS,PR_PLL,NOWDT,ICSP2
   //C30/XC16 compiler to CCS PCH compiler compatability.
   //also includes the filesystem.
   //since this changes some #device settings, this needs to be include
   //fairly soon in the build process.
   #include "filesystem\filesystem.h" 

 //  #use fast_io(ALL)

 //  #use delay(clock=32M)
//#use delay( crystal=8mhz, clock=32mhz )

//   #pin_select U1TX = PIN_D5
//   #pin_select U1RX = PIN_D4
   
   //hardwareprofile.h is using spi2 for sd card, so pin select those
  // #pin_select SDI2 = PIN_F5
  // #pin_select SDO2 = PIN_B15
  // #pin_select SCK2OUT = PIN_F4

//   #pin_select SDI1 = PIN_F6
//   #pin_select SDO1 = PIN_F2
//   #pin_select SCK1OUT = PIN_F3



//   #pin_select SDI2 = PIN_F6
//   #pin_select SDO2 = PIN_F2
//   #pin_select SCK2OUT = PIN_F3

   #define AN_HOST_VOLTAGE 2
   #define AN_POT          0

//   #define MY_ANALOG_PORTS (sAN2 | sAN0)
   
//   #define MY_ADC_SETUP    (ADC_CLOCK_INTERNAL|ADC_TAD_MUL_2)
   
//  #use rs232(UART1, baud=9600, stream=STREAM_USER_UART)
   #define PIN_SDPOWER  PIN_G9
//   #define PIN_LED1  PIN_B11
//   #define PIN_LED2  PIN_B10
//   #define PIN_LED3  PIN_B9

//   #define GREEN_LED    PIN_B11
//   #define YELLOW_LED   PIN_B10
//   #define RED_LED      PIN_B9
   
//   #define LED_ON(x)    output_high(x)
//   #define LED_OFF(x)   output_low(x)
   
//   #define BUTTON_PRESSED()   !input(PIN_F0)
#endif

#if defined(__DEBUG_UART)
   // these are microchip's style debugs
   #define InitUART()
   #define PrintROMASCIIStringUART(s)  fprintf(STREAM_USER_UART, s)
   void PrintRAMBytesUART(char *p, unsigned int16 n) 
   {
      while(n--)
      {
         fprintf(STREAM_USER_UART, "%X ", *p++);
      }
   }
   #define UARTSendLineFeedCarriageReturn() fprintf(STREAM_USER_UART, "\r\n")
#endif

#if 0
   #warning CCS Debugs Enabled
   
  #if defined(__PCH__)  //uart1
   #bit UART_TBE=getenv("BIT:TX1IF")
   //#define WAIT_FOR_TX()   while(!UART_TBE)
   #define WAIT_FOR_TX()
  #else  //uart2
   #word U2STA=getenv("SFR:U2STA")
   #bit U2STA_TRMT=U2STA.8
   #define UART_TBE  U2STA_TRMT
   #define WAIT_FOR_TX()   while(!UART_TBE)
  #endif
      
   // application level debugs
   #define DEBUG_STR(str, x) printf("\r\n"); printf("%s", str); printf(" 0x%LX", x); WAIT_FOR_TX()
   #define DEBUG_STR2(str1, str2) printf("\r\n%s '%s'", str1, str2); WAIT_FOR_TX()
   
   // library level debugs
   #define DEBUG_FS_STR(str, x) printf("\r\n"); printf("%s", str); printf(" 0x%LX", x); WAIT_FOR_TX()
   #define DEBUG_FS_STR2(str1, str2) printf("\r\n%s '%s'", str1, str2); WAIT_FOR_TX()
   
   void DEBUG_FS_ARRAY(unsigned int8 *p, unsigned int16 len)
   {
      unsigned int16 i=0;
      while(i < len)
      {
         if ((i%32) == 0)
            printf("\r\n0x%LX: ", i);
         printf("%02X", *p++);
         i++;
      }
   }
#endif

#if defined(DEBUG_STR)
#include <pcd_traps.c>
#endif

#ifndef HW_INIT
#define HW_INIT()
#endif

//#if defined(__PCD__)
#if 0
   #define DEBUG_SPI()  printf("\r\n0x260=%LX 0x262=%LX 0x264=%LX\r\n", (unsigned int16*)*0x260, (unsigned int16*)*0x262, (unsigned int16*)*0x264);
#else
   #define DEBUG_SPI()
#endif

// disable application level debug macros if not defined
#ifndef DEBUG_STR
 #define DEBUG_STR(str, x)
 #define DEBUG_STR2(str1, str2)
#endif

// disable library level debug macros if not defined
#ifndef DEBUG_FS_STR
 #define DEBUG_FS_STR(str, x)
 #define DEBUG_FS_STR2(str1, str2)
 #define DEBUG_FS_ARRAY(p, len)
#endif

#if defined(__USE_MDD_BOOTLOADER__)
#include "ex_mdd_boot.h"
#endif

#include <stdint.h>

#include "filesystem\filesystem.c"
