/******************************************************************************
 *
 *                Microchip Memory Disk Drive File System
 *
 ******************************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    None
 * Processor:       PIC18/PIC24/dsPIC30/dsPIC33/PIC32
 * Compiler:        C18/C30/C32
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PICmicro� Microcontroller is intended and
 * supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
*****************************************************************************/


#ifndef _MDD_HARDWAREPROFILE_H_
#define _MDD_HARDWAREPROFILE_H_

/*********************************************************************/
/******************* Pin and Register Definitions ********************/
/*********************************************************************/

/* SD Card definitions: Change these to fit your application when using
   an SD-card-based physical layer                                   */

#if defined(HW_CCS_PIC24USB) && (!defined(USE_SD_INTERFACE_WITH_SPI)&&!defined(USE_CF_INTERFACE_WITH_PMP)&&!defined(USE_MANUAL_CF_INTERFACE)&&!defined(USE_USB_INTERFACE)&&!defined(USE_SST25_INTERFACE))
// ccs dsp analog board with sd connector

         // Select your interface type
         // This library currently only supports a single physical interface layer at a time
         // Description: Macro used to enable the SD-SPI physical layer (SD-SPI.c and .h)
         #define USE_SD_INTERFACE_WITH_SPI
         // Description: Macro used to enable the CF-PMP physical layer (CF-PMP.c and .h)
         //#define USE_CF_INTERFACE_WITH_PMP
         // Description: Macro used to enable the CF-Manual physical layer (CF-Bit transaction.c and .h)                                                                
         //#define USE_MANUAL_CF_INTERFACE
         // Description: Macro used to enable the USB Host physical layer (USB host MSD library)
         //#define USE_USB_INTERFACE


        //unless you are doing something exotic, you can use the following
        //definitions for all hardware - it will get clock speed from your
        //#use delay() statement.
//        #define GetSystemClock() getenv("CLOCK")
//        #define GetPeripheralClock()    GetSystemClock()
 //       #define GetInstructionClock()   (GetSystemClock() / 2)
       
        // Description: SD-SPI Chip Select Output bit
// Changed on Dece ber 3, 2015
// The SD_CS has moved from G8 to G9.  The power SD Card power pin moved to G8 from B9.  B9 is used as an ADC pin because of Tony.
        #define SD_CS            LATGbits.LATG9      //pin_G9

        //#define SD_CS            LATGbits.LATG8      //pin_G8
        // Description: SD-SPI Chip Select TRIS bit
        //#define SD_CS_TRIS          TRISGbits.TRISG8

        #define SD_CS_TRIS          TRISGbits.TRISG9 //pin_G9

//This is the old setup  December 30, 2014
        // Description: SD-SPI Chip Select Output bit
        //#define SD_CS            LATBbits.LATB14      //pin_b14
        // Description: SD-SPI Chip Select TRIS bit
        //#define SD_CS_TRIS          TRISBbits.TRISB14

        #define SD_CD            PORTBbits.RB12      //pin_b12
        #define SD_CD_TRIS       TRISBbits.TRISB12

         //NO SD_WE_TRIS        
         int1 SD_WE_TRIS;
         int1 SD_WE=0;

        // Registers for the SPI module you want to use

        // Description: The main SPI control register
        #define SPICON1             SPI1CON1
        // Description: The SPI status register
        #define SPISTAT             SPI1STAT
        // Description: The SPI Buffer
        #define SPIBUF              SPI1BUF
        // Description: The receive buffer full bit in the SPI status register
        #define SPISTAT_RBF         SPI1STATbits.SPIRBF
        #define SPISTAT_TBF         SPI1STATbits.SPITBF
        // Description: The bitwise define for the SPI control register (i.e. _____bits)
        #define SPICON1bits         SPI1CON1bits
        // Description: The bitwise define for the SPI status register (i.e. _____bits)
        #define SPISTATbits         SPI1STATbits
        // Description: The enable bit for the SPI module
        #define SPIENABLE           SPISTATbits.SPIEN


//This is the orginal settings   This is the old setup  December 31, 2014

        // Description: The main SPI control register
        //#define SPICON1             SPI2CON1
        // Description: The SPI status register
        //#define SPISTAT             SPI2STAT
        // Description: The SPI Buffer
        //#define SPIBUF              SPI2BUF
        // Description: The receive buffer full bit in the SPI status register
        //#define SPISTAT_RBF         SPI2STATbits.SPIRBF
        //#define SPISTAT_TBF         SPI2STATbits.SPITBF
        // Description: The bitwise define for the SPI control register (i.e. _____bits)
        //#define SPICON1bits         SPI2CON1bits
        // Description: The bitwise define for the SPI status register (i.e. _____bits)
        //#define SPISTATbits         SPI2STATbits
        // Description: The enable bit for the SPI module
        //#define SPIENABLE           SPISTATbits.SPIEN



        // Tris pins for SCK/SDI/SDO lines


       // Description: The TRIS bit for the SCK pin
        #define SPICLOCK            TRISFbits.TRISF3
        // Description: The TRIS bit for the SDI pin
        #define SPIIN               TRISFbits.TRISF6
        // Description: The TRIS bit for the SDO pin
        #define SPIOUT              TRISFbits.TRISF2


//This is the orginal settings   This is the old setup  December 31, 2014

        // Description: The TRIS bit for the SCK pin
        //#define SPICLOCK            TRISGbits.TRISG6
        // Description: The TRIS bit for the SDI pin
        //#define SPIIN               TRISGbits.TRISG7
        // Description: The TRIS bit for the SDO pin
        //#define SPIOUT              TRISGbits.TRISG8
#endif

#endif
