//C18/C30 defines to CCS device h mapping

#ifndef __DEFINES_TO_CCS_H__
#define __DEFINES_TO_CCS_H__

#define __CCS__

#if defined(__dsPIC14000__) || (getenv("DEVICE")=="DSPIC14000")
    #if !defined(__dsPIC14000__)
        #define __dsPIC14000__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <14000.h>
    #endif
    #if !defined(__dsPIC140000__)
        #define __dsPIC140000__
    #endif
    #include "14000_registers.h"
#endif

#if defined(__18C242) || (getenv("DEVICE")=="PIC18C242")
    #if !defined(__18C242)
        #define __18C242
    #endif
    #if !defined(GLOBAL)
        #include <18C242.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C242_registers.h"
#endif

#if defined(__18C252) || (getenv("DEVICE")=="PIC18C252")
    #if !defined(__18C252)
        #define __18C252
    #endif
    #if !defined(GLOBAL)
        #include <18C252.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C252_registers.h"
#endif

#if defined(__18C442) || (getenv("DEVICE")=="PIC18C442")
    #if !defined(__18C442)
        #define __18C442
    #endif
    #if !defined(GLOBAL)
        #include <18C442.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C442_registers.h"
#endif

#if defined(__18C452) || (getenv("DEVICE")=="PIC18C452")
    #if !defined(__18C452)
        #define __18C452
    #endif
    #if !defined(GLOBAL)
        #include <18C452.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C452_registers.h"
#endif

#if defined(__18C601) || (getenv("DEVICE")=="PIC18C601")
    #if !defined(__18C601)
        #define __18C601
    #endif
    #if !defined(GLOBAL)
        #include <18C601.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C601_registers.h"
#endif

#if defined(__18C658) || (getenv("DEVICE")=="PIC18C658")
    #if !defined(__18C658)
        #define __18C658
    #endif
    #if !defined(GLOBAL)
        #include <18C658.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C658_registers.h"
#endif

#if defined(__18C801) || (getenv("DEVICE")=="PIC18C801")
    #if !defined(__18C801)
        #define __18C801
    #endif
    #if !defined(GLOBAL)
        #include <18C801.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C801_registers.h"
#endif

#if defined(__18C858) || (getenv("DEVICE")=="PIC18C858")
    #if !defined(__18C858)
        #define __18C858
    #endif
    #if !defined(GLOBAL)
        #include <18C858.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18C858_registers.h"
#endif

#if defined(__18F1220) || (getenv("DEVICE")=="PIC18F1220")
    #if !defined(__18F1220)
        #define __18F1220
    #endif
    #if !defined(GLOBAL)
        #include <18F1220.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F1220_registers.h"
#endif

#if defined(__18F1230) || (getenv("DEVICE")=="PIC18F1230")
    #if !defined(__18F1230)
        #define __18F1230
    #endif
    #if !defined(GLOBAL)
        #include <18F1230.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F1230_registers.h"
#endif

#if defined(__18F1320) || (getenv("DEVICE")=="PIC18F1320")
    #if !defined(__18F1320)
        #define __18F1320
    #endif
    #if !defined(GLOBAL)
        #include <18F1320.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F1320_registers.h"
#endif

#if defined(__18F1330) || (getenv("DEVICE")=="PIC18F1330")
    #if !defined(__18F1330)
        #define __18F1330
    #endif
    #if !defined(GLOBAL)
        #include <18F1330.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F1330_registers.h"
#endif

#if defined(__18F13K22) || (getenv("DEVICE")=="PIC18F13K22")
    #if !defined(__18F13K22)
        #define __18F13K22
    #endif
    #if !defined(GLOBAL)
        #include <18F13K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F13K22_registers.h"
#endif

#if defined(__18F13K50) || (getenv("DEVICE")=="PIC18F13K50")
    #if !defined(__18F13K50)
        #define __18F13K50
    #endif
    #if !defined(GLOBAL)
        #include <18F13K50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F13K50_registers.h"
#endif

#if defined(__18F14K22) || (getenv("DEVICE")=="PIC18F14K22")
    #if !defined(__18F14K22)
        #define __18F14K22
    #endif
    #if !defined(GLOBAL)
        #include <18F14K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F14K22_registers.h"
#endif

/*
#if defined(__18F14K50-ICD) || (getenv("DEVICE")=="PIC18F14K50-ICD")
    #if !defined(__18F14K50-ICD)
        #define __18F14K50-ICD
    #endif
    #if !defined(GLOBAL)
        #include <18F14K50-ICD.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F14K50-ICD_registers.h"
#endif
*/

#if defined(__18F14K50) || (getenv("DEVICE")=="PIC18F14K50")
    #if !defined(__18F14K50)
        #define __18F14K50
    #endif
    #if !defined(GLOBAL)
        #include <18F14K50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F14K50_registers.h"
#endif

#if defined(__18F2220) || (getenv("DEVICE")=="PIC18F2220")
    #if !defined(__18F2220)
        #define __18F2220
    #endif
    #if !defined(GLOBAL)
        #include <18F2220.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2220_registers.h"
#endif

#if defined(__18F2221) || (getenv("DEVICE")=="PIC18F2221")
    #if !defined(__18F2221)
        #define __18F2221
    #endif
    #if !defined(GLOBAL)
        #include <18F2221.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2221_registers.h"
#endif

#if defined(__18F2320) || (getenv("DEVICE")=="PIC18F2320")
    #if !defined(__18F2320)
        #define __18F2320
    #endif
    #if !defined(GLOBAL)
        #include <18F2320.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2320_registers.h"
#endif

#if defined(__18F2321) || (getenv("DEVICE")=="PIC18F2321")
    #if !defined(__18F2321)
        #define __18F2321
    #endif
    #if !defined(GLOBAL)
        #include <18F2321.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2321_registers.h"
#endif

#if defined(__18F2331) || (getenv("DEVICE")=="PIC18F2331")
    #if !defined(__18F2331)
        #define __18F2331
    #endif
    #if !defined(GLOBAL)
        #include <18F2331.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2331_registers.h"
#endif

#if defined(__18F23K20) || (getenv("DEVICE")=="PIC18F23K20")
    #if !defined(__18F23K20)
        #define __18F23K20
    #endif
    #if !defined(GLOBAL)
        #include <18F23K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F23K20_registers.h"
#endif

#if defined(__18F23K22) || (getenv("DEVICE")=="PIC18F23K22")
    #if !defined(__18F23K22)
        #define __18F23K22
    #endif
    #if !defined(GLOBAL)
        #include <18F23K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F23K22_registers.h"
#endif

#if defined(__18F2410) || (getenv("DEVICE")=="PIC18F2410")
    #if !defined(__18F2410)
        #define __18F2410
    #endif
    #if !defined(GLOBAL)
        #include <18F2410.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2410_registers.h"
#endif

#if defined(__18F242) || (getenv("DEVICE")=="PIC18F242")
    #if !defined(__18F242)
        #define __18F242
    #endif
    #if !defined(GLOBAL)
        #include <18F242.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F242_registers.h"
#endif

#if defined(__18F2420) || (getenv("DEVICE")=="PIC18F2420")
    #if !defined(__18F2420)
        #define __18F2420
    #endif
    #if !defined(GLOBAL)
        #include <18F2420.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2420_registers.h"
#endif

#if defined(__18F2423) || (getenv("DEVICE")=="PIC18F2423")
    #if !defined(__18F2423)
        #define __18F2423
    #endif
    #if !defined(GLOBAL)
        #include <18F2423.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2423_registers.h"
#endif

#if defined(__18F2431) || (getenv("DEVICE")=="PIC18F2431")
    #if !defined(__18F2431)
        #define __18F2431
    #endif
    #if !defined(GLOBAL)
        #include <18F2431.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2431_registers.h"
#endif

#if defined(__18F2439) || (getenv("DEVICE")=="PIC18F2439")
    #if !defined(__18F2439)
        #define __18F2439
    #endif
    #if !defined(GLOBAL)
        #include <18F2439.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2439_registers.h"
#endif

#if defined(__18F2450) || (getenv("DEVICE")=="PIC18F2450")
    #if !defined(__18F2450)
        #define __18F2450
    #endif
    #if !defined(GLOBAL)
        #include <18F2450.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2450_registers.h"
#endif

#if defined(__18F2455) || (getenv("DEVICE")=="PIC18F2455")
    #if !defined(__18F2455)
        #define __18F2455
    #endif
    #if !defined(GLOBAL)
        #include <18F2455.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2455_registers.h"
#endif

#if defined(__18F2458) || (getenv("DEVICE")=="PIC18F2458")
    #if !defined(__18F2458)
        #define __18F2458
    #endif
    #if !defined(GLOBAL)
        #include <18F2458.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2458_registers.h"
#endif

#if defined(__18F248) || (getenv("DEVICE")=="PIC18F248")
    #if !defined(__18F248)
        #define __18F248
    #endif
    #if !defined(GLOBAL)
        #include <18F248.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F248_registers.h"
#endif

#if defined(__18F2480) || (getenv("DEVICE")=="PIC18F2480")
    #if !defined(__18F2480)
        #define __18F2480
    #endif
    #if !defined(GLOBAL)
        #include <18F2480.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2480_registers.h"
#endif

#if defined(__18F24J10) || (getenv("DEVICE")=="PIC18F24J10")
    #if !defined(__18F24J10)
        #define __18F24J10
    #endif
    #if !defined(GLOBAL)
        #include <18F24J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F24J10_registers.h"
#endif

#if defined(__18F24J11) || (getenv("DEVICE")=="PIC18F24J11")
    #if !defined(__18F24J11)
        #define __18F24J11
    #endif
    #if !defined(GLOBAL)
        #include <18F24J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F24J11_registers.h"
#endif

#if defined(__18F24J50) || (getenv("DEVICE")=="PIC18F24J50")
    #if !defined(__18F24J50)
        #define __18F24J50
    #endif
    #if !defined(GLOBAL)
        #include <18F24J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F24J50_registers.h"
#endif

#if defined(__18F24K20) || (getenv("DEVICE")=="PIC18F24K20")
    #if !defined(__18F24K20)
        #define __18F24K20
    #endif
    #if !defined(GLOBAL)
        #include <18F24K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F24K20_registers.h"
#endif

#if defined(__18F24K22) || (getenv("DEVICE")=="PIC18F24K22")
    #if !defined(__18F24K22)
        #define __18F24K22
    #endif
    #if !defined(GLOBAL)
        #include <18F24K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F24K22_registers.h"
#endif

#if defined(__18F24K50) || (getenv("DEVICE")=="PIC18F24K50")
    #if !defined(__18F24K50)
        #define __18F24K50
    #endif
    #if !defined(GLOBAL)
        #include <18F24K50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F24K50_registers.h"
#endif

#if defined(__18F2510) || (getenv("DEVICE")=="PIC18F2510")
    #if !defined(__18F2510)
        #define __18F2510
    #endif
    #if !defined(GLOBAL)
        #include <18F2510.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2510_registers.h"
#endif

#if defined(__18F2515) || (getenv("DEVICE")=="PIC18F2515")
    #if !defined(__18F2515)
        #define __18F2515
    #endif
    #if !defined(GLOBAL)
        #include <18F2515.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2515_registers.h"
#endif

#if defined(__18F252) || (getenv("DEVICE")=="PIC18F252")
    #if !defined(__18F252)
        #define __18F252
    #endif
    #if !defined(GLOBAL)
        #include <18F252.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F252_registers.h"
#endif

#if defined(__18F2520) || (getenv("DEVICE")=="PIC18F2520")
    #if !defined(__18F2520)
        #define __18F2520
    #endif
    #if !defined(GLOBAL)
        #include <18F2520.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2520_registers.h"
#endif

#if defined(__18F2523) || (getenv("DEVICE")=="PIC18F2523")
    #if !defined(__18F2523)
        #define __18F2523
    #endif
    #if !defined(GLOBAL)
        #include <18F2523.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2523_registers.h"
#endif

#if defined(__18F2525) || (getenv("DEVICE")=="PIC18F2525")
    #if !defined(__18F2525)
        #define __18F2525
    #endif
    #if !defined(GLOBAL)
        #include <18F2525.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2525_registers.h"
#endif

#if defined(__18F2539) || (getenv("DEVICE")=="PIC18F2539")
    #if !defined(__18F2539)
        #define __18F2539
    #endif
    #if !defined(GLOBAL)
        #include <18F2539.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2539_registers.h"
#endif

#if defined(__18F2550) || (getenv("DEVICE")=="PIC18F2550")
    #if !defined(__18F2550)
        #define __18F2550
    #endif
    #if !defined(GLOBAL)
        #include <18F2550.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2550_registers.h"
#endif

#if defined(__18F2553) || (getenv("DEVICE")=="PIC18F2553")
    #if !defined(__18F2553)
        #define __18F2553
    #endif
    #if !defined(GLOBAL)
        #include <18F2553.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2553_registers.h"
#endif

#if defined(__18F258) || (getenv("DEVICE")=="PIC18F258")
    #if !defined(__18F258)
        #define __18F258
    #endif
    #if !defined(GLOBAL)
        #include <18F258.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F258_registers.h"
#endif

#if defined(__18F2580) || (getenv("DEVICE")=="PIC18F2580")
    #if !defined(__18F2580)
        #define __18F2580
    #endif
    #if !defined(GLOBAL)
        #include <18F2580.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2580_registers.h"
#endif

#if defined(__18F2585) || (getenv("DEVICE")=="PIC18F2585")
    #if !defined(__18F2585)
        #define __18F2585
    #endif
    #if !defined(GLOBAL)
        #include <18F2585.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2585_registers.h"
#endif

#if defined(__18F25J10) || (getenv("DEVICE")=="PIC18F25J10")
    #if !defined(__18F25J10)
        #define __18F25J10
    #endif
    #if !defined(GLOBAL)
        #include <18F25J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F25J10_registers.h"
#endif

#if defined(__18F25J11) || (getenv("DEVICE")=="PIC18F25J11")
    #if !defined(__18F25J11)
        #define __18F25J11
    #endif
    #if !defined(GLOBAL)
        #include <18F25J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F25J11_registers.h"
#endif

#if defined(__18F25J50) || (getenv("DEVICE")=="PIC18F25J50")
    #if !defined(__18F25J50)
        #define __18F25J50
    #endif
    #if !defined(GLOBAL)
        #include <18F25J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F25J50_registers.h"
#endif

#if defined(__18F25K20) || (getenv("DEVICE")=="PIC18F25K20")
    #if !defined(__18F25K20)
        #define __18F25K20
    #endif
    #if !defined(GLOBAL)
        #include <18F25K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F25K20_registers.h"
#endif

#if defined(__18F25K22) || (getenv("DEVICE")=="PIC18F25K22")
    #if !defined(__18F25K22)
        #define __18F25K22
    #endif
    #if !defined(GLOBAL)
        #include <18F25K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F25K22_registers.h"
#endif

#if defined(__18F25K50) || (getenv("DEVICE")=="PIC18F25K50")
    #if !defined(__18F25K50)
        #define __18F25K50
    #endif
    #if !defined(GLOBAL)
        #include <18F25K50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F25K50_registers.h"
#endif

#if defined(__18F25K80) || (getenv("DEVICE")=="PIC18F25K80")
    #if !defined(__18F25K80)
        #define __18F25K80
    #endif
    #if !defined(GLOBAL)
        #include <18F25K80.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F25K80_registers.h"
#endif

#if defined(__18F2610) || (getenv("DEVICE")=="PIC18F2610")
    #if !defined(__18F2610)
        #define __18F2610
    #endif
    #if !defined(GLOBAL)
        #include <18F2610.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2610_registers.h"
#endif

#if defined(__18F2620) || (getenv("DEVICE")=="PIC18F2620")
    #if !defined(__18F2620)
        #define __18F2620
    #endif
    #if !defined(GLOBAL)
        #include <18F2620.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2620_registers.h"
#endif

#if defined(__18F2680) || (getenv("DEVICE")=="PIC18F2680")
    #if !defined(__18F2680)
        #define __18F2680
    #endif
    #if !defined(GLOBAL)
        #include <18F2680.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2680_registers.h"
#endif

#if defined(__18F2682) || (getenv("DEVICE")=="PIC18F2682")
    #if !defined(__18F2682)
        #define __18F2682
    #endif
    #if !defined(GLOBAL)
        #include <18F2682.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2682_registers.h"
#endif

#if defined(__18F2685) || (getenv("DEVICE")=="PIC18F2685")
    #if !defined(__18F2685)
        #define __18F2685
    #endif
    #if !defined(GLOBAL)
        #include <18F2685.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F2685_registers.h"
#endif

#if defined(__18F26J11) || (getenv("DEVICE")=="PIC18F26J11")
    #if !defined(__18F26J11)
        #define __18F26J11
    #endif
    #if !defined(GLOBAL)
        #include <18F26J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F26J11_registers.h"
#endif

#if defined(__18F26J13) || (getenv("DEVICE")=="PIC18F26J13")
    #if !defined(__18F26J13)
        #define __18F26J13
    #endif
    #if !defined(GLOBAL)
        #include <18F26J13.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F26J13_registers.h"
#endif

#if defined(__18F26J50) || (getenv("DEVICE")=="PIC18F26J50")
    #if !defined(__18F26J50)
        #define __18F26J50
    #endif
    #if !defined(GLOBAL)
        #include <18F26J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F26J50_registers.h"
#endif

#if defined(__18F26J53) || (getenv("DEVICE")=="PIC18F26J53")
    #if !defined(__18F26J53)
        #define __18F26J53
    #endif
    #if !defined(GLOBAL)
        #include <18F26J53.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F26J53_registers.h"
#endif

#if defined(__18F26K20) || (getenv("DEVICE")=="PIC18F26K20")
    #if !defined(__18F26K20)
        #define __18F26K20
    #endif
    #if !defined(GLOBAL)
        #include <18F26K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F26K20_registers.h"
#endif

#if defined(__18F26K22) || (getenv("DEVICE")=="PIC18F26K22")
    #if !defined(__18F26K22)
        #define __18F26K22
    #endif
    #if !defined(GLOBAL)
        #include <18F26K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F26K22_registers.h"
#endif

#if defined(__18F26K80) || (getenv("DEVICE")=="PIC18F26K80")
    #if !defined(__18F26K80)
        #define __18F26K80
    #endif
    #if !defined(GLOBAL)
        #include <18F26K80.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F26K80_registers.h"
#endif

#if defined(__18F27J13) || (getenv("DEVICE")=="PIC18F27J13")
    #if !defined(__18F27J13)
        #define __18F27J13
    #endif
    #if !defined(GLOBAL)
        #include <18F27J13.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F27J13_registers.h"
#endif

#if defined(__18F27J53) || (getenv("DEVICE")=="PIC18F27J53")
    #if !defined(__18F27J53)
        #define __18F27J53
    #endif
    #if !defined(GLOBAL)
        #include <18F27J53.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F27J53_registers.h"
#endif

#if defined(__18F4220) || (getenv("DEVICE")=="PIC18F4220")
    #if !defined(__18F4220)
        #define __18F4220
    #endif
    #if !defined(GLOBAL)
        #include <18F4220.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4220_registers.h"
#endif

#if defined(__18F4221) || (getenv("DEVICE")=="PIC18F4221")
    #if !defined(__18F4221)
        #define __18F4221
    #endif
    #if !defined(GLOBAL)
        #include <18F4221.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4221_registers.h"
#endif

#if defined(__18F4320) || (getenv("DEVICE")=="PIC18F4320")
    #if !defined(__18F4320)
        #define __18F4320
    #endif
    #if !defined(GLOBAL)
        #include <18F4320.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4320_registers.h"
#endif

#if defined(__18F4321) || (getenv("DEVICE")=="PIC18F4321")
    #if !defined(__18F4321)
        #define __18F4321
    #endif
    #if !defined(GLOBAL)
        #include <18F4321.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4321_registers.h"
#endif

#if defined(__18F4331) || (getenv("DEVICE")=="PIC18F4331")
    #if !defined(__18F4331)
        #define __18F4331
    #endif
    #if !defined(GLOBAL)
        #include <18F4331.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4331_registers.h"
#endif

#if defined(__18F43K20) || (getenv("DEVICE")=="PIC18F43K20")
    #if !defined(__18F43K20)
        #define __18F43K20
    #endif
    #if !defined(GLOBAL)
        #include <18F43K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F43K20_registers.h"
#endif

#if defined(__18F43K22) || (getenv("DEVICE")=="PIC18F43K22")
    #if !defined(__18F43K22)
        #define __18F43K22
    #endif
    #if !defined(GLOBAL)
        #include <18F43K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F43K22_registers.h"
#endif

#if defined(__18F4410) || (getenv("DEVICE")=="PIC18F4410")
    #if !defined(__18F4410)
        #define __18F4410
    #endif
    #if !defined(GLOBAL)
        #include <18F4410.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4410_registers.h"
#endif

#if defined(__18F442) || (getenv("DEVICE")=="PIC18F442")
    #if !defined(__18F442)
        #define __18F442
    #endif
    #if !defined(GLOBAL)
        #include <18F442.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F442_registers.h"
#endif

#if defined(__18F4420) || (getenv("DEVICE")=="PIC18F4420")
    #if !defined(__18F4420)
        #define __18F4420
    #endif
    #if !defined(GLOBAL)
        #include <18F4420.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4420_registers.h"
#endif

#if defined(__18F4423) || (getenv("DEVICE")=="PIC18F4423")
    #if !defined(__18F4423)
        #define __18F4423
    #endif
    #if !defined(GLOBAL)
        #include <18F4423.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4423_registers.h"
#endif

#if defined(__18F4431) || (getenv("DEVICE")=="PIC18F4431")
    #if !defined(__18F4431)
        #define __18F4431
    #endif
    #if !defined(GLOBAL)
        #include <18F4431.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4431_registers.h"
#endif

#if defined(__18F4439) || (getenv("DEVICE")=="PIC18F4439")
    #if !defined(__18F4439)
        #define __18F4439
    #endif
    #if !defined(GLOBAL)
        #include <18F4439.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4439_registers.h"
#endif

#if defined(__18F4450) || (getenv("DEVICE")=="PIC18F4450")
    #if !defined(__18F4450)
        #define __18F4450
    #endif
    #if !defined(GLOBAL)
        #include <18F4450.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4450_registers.h"
#endif

#if defined(__18F4455) || (getenv("DEVICE")=="PIC18F4455")
    #if !defined(__18F4455)
        #define __18F4455
    #endif
    #if !defined(GLOBAL)
        #include <18F4455.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4455_registers.h"
#endif

#if defined(__18F4458) || (getenv("DEVICE")=="PIC18F4458")
    #if !defined(__18F4458)
        #define __18F4458
    #endif
    #if !defined(GLOBAL)
        #include <18F4458.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4458_registers.h"
#endif

#if defined(__18F448) || (getenv("DEVICE")=="PIC18F448")
    #if !defined(__18F448)
        #define __18F448
    #endif
    #if !defined(GLOBAL)
        #include <18F448.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F448_registers.h"
#endif

#if defined(__18F4480) || (getenv("DEVICE")=="PIC18F4480")
    #if !defined(__18F4480)
        #define __18F4480
    #endif
    #if !defined(GLOBAL)
        #include <18F4480.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4480_registers.h"
#endif

#if defined(__18F44J10) || (getenv("DEVICE")=="PIC18F44J10")
    #if !defined(__18F44J10)
        #define __18F44J10
    #endif
    #if !defined(GLOBAL)
        #include <18F44J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F44J10_registers.h"
#endif

#if defined(__18F44J11) || (getenv("DEVICE")=="PIC18F44J11")
    #if !defined(__18F44J11)
        #define __18F44J11
    #endif
    #if !defined(GLOBAL)
        #include <18F44J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F44J11_registers.h"
#endif

#if defined(__18F44J50) || (getenv("DEVICE")=="PIC18F44J50")
    #if !defined(__18F44J50)
        #define __18F44J50
    #endif
    #if !defined(GLOBAL)
        #include <18F44J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F44J50_registers.h"
#endif

#if defined(__18F44K20) || (getenv("DEVICE")=="PIC18F44K20")
    #if !defined(__18F44K20)
        #define __18F44K20
    #endif
    #if !defined(GLOBAL)
        #include <18F44K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F44K20_registers.h"
#endif

#if defined(__18F44K22) || (getenv("DEVICE")=="PIC18F44K22")
    #if !defined(__18F44K22)
        #define __18F44K22
    #endif
    #if !defined(GLOBAL)
        #include <18F44K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F44K22_registers.h"
#endif

#if defined(__18F4510) || (getenv("DEVICE")=="PIC18F4510")
    #if !defined(__18F4510)
        #define __18F4510
    #endif
    #if !defined(GLOBAL)
        #include <18F4510.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4510_registers.h"
#endif

#if defined(__18F4515) || (getenv("DEVICE")=="PIC18F4515")
    #if !defined(__18F4515)
        #define __18F4515
    #endif
    #if !defined(GLOBAL)
        #include <18F4515.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4515_registers.h"
#endif

#if defined(__18F452) || (getenv("DEVICE")=="PIC18F452")
    #if !defined(__18F452)
        #define __18F452
    #endif
    #if !defined(GLOBAL)
        #include <18F452.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F452_registers.h"
#endif

#if defined(__18F4520) || (getenv("DEVICE")=="PIC18F4520")
    #if !defined(__18F4520)
        #define __18F4520
    #endif
    #if !defined(GLOBAL)
        #include <18F4520.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4520_registers.h"
#endif

#if defined(__18F4523) || (getenv("DEVICE")=="PIC18F4523")
    #if !defined(__18F4523)
        #define __18F4523
    #endif
    #if !defined(GLOBAL)
        #include <18F4523.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4523_registers.h"
#endif

#if defined(__18F4525) || (getenv("DEVICE")=="PIC18F4525")
    #if !defined(__18F4525)
        #define __18F4525
    #endif
    #if !defined(GLOBAL)
        #include <18F4525.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4525_registers.h"
#endif

#if defined(__18F4539) || (getenv("DEVICE")=="PIC18F4539")
    #if !defined(__18F4539)
        #define __18F4539
    #endif
    #if !defined(GLOBAL)
        #include <18F4539.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4539_registers.h"
#endif

#if defined(__18F4550) || (getenv("DEVICE")=="PIC18F4550")
    #if !defined(__18F4550)
        #define __18F4550
    #endif
    #if !defined(GLOBAL)
        #include <18F4550.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4550_registers.h"
#endif

#if defined(__18F4553) || (getenv("DEVICE")=="PIC18F4553")
    #if !defined(__18F4553)
        #define __18F4553
    #endif
    #if !defined(GLOBAL)
        #include <18F4553.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4553_registers.h"
#endif

#if defined(__18F458) || (getenv("DEVICE")=="PIC18F458")
    #if !defined(__18F458)
        #define __18F458
    #endif
    #if !defined(GLOBAL)
        #include <18F458.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F458_registers.h"
#endif

#if defined(__18F4580) || (getenv("DEVICE")=="PIC18F4580")
    #if !defined(__18F4580)
        #define __18F4580
    #endif
    #if !defined(GLOBAL)
        #include <18F4580.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4580_registers.h"
#endif

#if defined(__18F4585) || (getenv("DEVICE")=="PIC18F4585")
    #if !defined(__18F4585)
        #define __18F4585
    #endif
    #if !defined(GLOBAL)
        #include <18F4585.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4585_registers.h"
#endif

#if defined(__18F45J10) || (getenv("DEVICE")=="PIC18F45J10")
    #if !defined(__18F45J10)
        #define __18F45J10
    #endif
    #if !defined(GLOBAL)
        #include <18F45J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F45J10_registers.h"
#endif

#if defined(__18F45J11) || (getenv("DEVICE")=="PIC18F45J11")
    #if !defined(__18F45J11)
        #define __18F45J11
    #endif
    #if !defined(GLOBAL)
        #include <18F45J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F45J11_registers.h"
#endif

#if defined(__18F45J50) || (getenv("DEVICE")=="PIC18F45J50")
    #if !defined(__18F45J50)
        #define __18F45J50
    #endif
    #if !defined(GLOBAL)
        #include <18F45J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F45J50_registers.h"
#endif

#if defined(__18F45K20) || (getenv("DEVICE")=="PIC18F45K20")
    #if !defined(__18F45K20)
        #define __18F45K20
    #endif
    #if !defined(GLOBAL)
        #include <18F45K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F45K20_registers.h"
#endif

#if defined(__18F45K22) || (getenv("DEVICE")=="PIC18F45K22")
    #if !defined(__18F45K22)
        #define __18F45K22
    #endif
    #if !defined(GLOBAL)
        #include <18F45K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F45K22_registers.h"
#endif

#if defined(__18F45K50) || (getenv("DEVICE")=="PIC18F45K50")
    #if !defined(__18F45K50)
        #define __18F45K50
    #endif
    #if !defined(GLOBAL)
        #include <18F45K50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F45K50_registers.h"
#endif

#if defined(__18F45K80) || (getenv("DEVICE")=="PIC18F45K80")
    #if !defined(__18F45K80)
        #define __18F45K80
    #endif
    #if !defined(GLOBAL)
        #include <18F45K80.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F45K80_registers.h"
#endif

#if defined(__18F4610) || (getenv("DEVICE")=="PIC18F4610")
    #if !defined(__18F4610)
        #define __18F4610
    #endif
    #if !defined(GLOBAL)
        #include <18F4610.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4610_registers.h"
#endif

#if defined(__18F4620) || (getenv("DEVICE")=="PIC18F4620")
    #if !defined(__18F4620)
        #define __18F4620
    #endif
    #if !defined(GLOBAL)
        #include <18F4620.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4620_registers.h"
#endif

#if defined(__18F4680) || (getenv("DEVICE")=="PIC18F4680")
    #if !defined(__18F4680)
        #define __18F4680
    #endif
    #if !defined(GLOBAL)
        #include <18F4680.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4680_registers.h"
#endif

#if defined(__18F4682) || (getenv("DEVICE")=="PIC18F4682")
    #if !defined(__18F4682)
        #define __18F4682
    #endif
    #if !defined(GLOBAL)
        #include <18F4682.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4682_registers.h"
#endif

#if defined(__18F4685) || (getenv("DEVICE")=="PIC18F4685")
    #if !defined(__18F4685)
        #define __18F4685
    #endif
    #if !defined(GLOBAL)
        #include <18F4685.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F4685_registers.h"
#endif

#if defined(__18F46J11) || (getenv("DEVICE")=="PIC18F46J11")
    #if !defined(__18F46J11)
        #define __18F46J11
    #endif
    #if !defined(GLOBAL)
        #include <18F46J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F46J11_registers.h"
#endif

#if defined(__18F46J13) || (getenv("DEVICE")=="PIC18F46J13")
    #if !defined(__18F46J13)
        #define __18F46J13
    #endif
    #if !defined(GLOBAL)
        #include <18F46J13.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F46J13_registers.h"
#endif

#if defined(__18F46J50) || (getenv("DEVICE")=="PIC18F46J50")
    #if !defined(__18F46J50)
        #define __18F46J50
    #endif
    #if !defined(GLOBAL)
        #include <18F46J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F46J50_registers.h"
#endif

#if defined(__18F46J53) || (getenv("DEVICE")=="PIC18F46J53")
    #if !defined(__18F46J53)
        #define __18F46J53
    #endif
    #if !defined(GLOBAL)
        #include <18F46J53.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F46J53_registers.h"
#endif

#if defined(__18F46K20) || (getenv("DEVICE")=="PIC18F46K20")
    #if !defined(__18F46K20)
        #define __18F46K20
    #endif
    #if !defined(GLOBAL)
        #include <18F46K20.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F46K20_registers.h"
#endif

#if defined(__18F46K22) || (getenv("DEVICE")=="PIC18F46K22")
    #if !defined(__18F46K22)
        #define __18F46K22
    #endif
    #if !defined(GLOBAL)
        #include <18F46K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F46K22_registers.h"
#endif

#if defined(__18F46K80) || (getenv("DEVICE")=="PIC18F46K80")
    #if !defined(__18F46K80)
        #define __18F46K80
    #endif
    #if !defined(GLOBAL)
        #include <18F46K80.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F46K80_registers.h"
#endif

#if defined(__18F47J13) || (getenv("DEVICE")=="PIC18F47J13")
    #if !defined(__18F47J13)
        #define __18F47J13
    #endif
    #if !defined(GLOBAL)
        #include <18F47J13.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F47J13_registers.h"
#endif

#if defined(__18F47J53) || (getenv("DEVICE")=="PIC18F47J53")
    #if !defined(__18F47J53)
        #define __18F47J53
    #endif
    #if !defined(GLOBAL)
        #include <18F47J53.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F47J53_registers.h"
#endif

#if defined(__18F6310) || (getenv("DEVICE")=="PIC18F6310")
    #if !defined(__18F6310)
        #define __18F6310
    #endif
    #if !defined(GLOBAL)
        #include <18F6310.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6310_registers.h"
#endif

#if defined(__18F6390) || (getenv("DEVICE")=="PIC18F6390")
    #if !defined(__18F6390)
        #define __18F6390
    #endif
    #if !defined(GLOBAL)
        #include <18F6390.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6390_registers.h"
#endif

#if defined(__18F6393) || (getenv("DEVICE")=="PIC18F6393")
    #if !defined(__18F6393)
        #define __18F6393
    #endif
    #if !defined(GLOBAL)
        #include <18F6393.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6393_registers.h"
#endif

#if defined(__18F63J11) || (getenv("DEVICE")=="PIC18F63J11")
    #if !defined(__18F63J11)
        #define __18F63J11
    #endif
    #if !defined(GLOBAL)
        #include <18F63J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F63J11_registers.h"
#endif

#if defined(__18F63J90) || (getenv("DEVICE")=="PIC18F63J90")
    #if !defined(__18F63J90)
        #define __18F63J90
    #endif
    #if !defined(GLOBAL)
        #include <18F63J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F63J90_registers.h"
#endif

#if defined(__18F6410) || (getenv("DEVICE")=="PIC18F6410")
    #if !defined(__18F6410)
        #define __18F6410
    #endif
    #if !defined(GLOBAL)
        #include <18F6410.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6410_registers.h"
#endif

#if defined(__18F6490) || (getenv("DEVICE")=="PIC18F6490")
    #if !defined(__18F6490)
        #define __18F6490
    #endif
    #if !defined(GLOBAL)
        #include <18F6490.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6490_registers.h"
#endif

#if defined(__18F6493) || (getenv("DEVICE")=="PIC18F6493")
    #if !defined(__18F6493)
        #define __18F6493
    #endif
    #if !defined(GLOBAL)
        #include <18F6493.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6493_registers.h"
#endif

#if defined(__18F64J11) || (getenv("DEVICE")=="PIC18F64J11")
    #if !defined(__18F64J11)
        #define __18F64J11
    #endif
    #if !defined(GLOBAL)
        #include <18F64J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F64J11_registers.h"
#endif

#if defined(__18F64J90) || (getenv("DEVICE")=="PIC18F64J90")
    #if !defined(__18F64J90)
        #define __18F64J90
    #endif
    #if !defined(GLOBAL)
        #include <18F64J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F64J90_registers.h"
#endif

#if defined(__18F6520) || (getenv("DEVICE")=="PIC18F6520")
    #if !defined(__18F6520)
        #define __18F6520
    #endif
    #if !defined(GLOBAL)
        #include <18F6520.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6520_registers.h"
#endif

#if defined(__18F6525) || (getenv("DEVICE")=="PIC18F6525")
    #if !defined(__18F6525)
        #define __18F6525
    #endif
    #if !defined(GLOBAL)
        #include <18F6525.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6525_registers.h"
#endif

#if defined(__18F6527) || (getenv("DEVICE")=="PIC18F6527")
    #if !defined(__18F6527)
        #define __18F6527
    #endif
    #if !defined(GLOBAL)
        #include <18F6527.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6527_registers.h"
#endif

#if defined(__18F6585) || (getenv("DEVICE")=="PIC18F6585")
    #if !defined(__18F6585)
        #define __18F6585
    #endif
    #if !defined(GLOBAL)
        #include <18F6585.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6585_registers.h"
#endif

#if defined(__18F65J10) || (getenv("DEVICE")=="PIC18F65J10")
    #if !defined(__18F65J10)
        #define __18F65J10
    #endif
    #if !defined(GLOBAL)
        #include <18F65J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65J10_registers.h"
#endif

#if defined(__18F65J11) || (getenv("DEVICE")=="PIC18F65J11")
    #if !defined(__18F65J11)
        #define __18F65J11
    #endif
    #if !defined(GLOBAL)
        #include <18F65J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65J11_registers.h"
#endif

#if defined(__18F65J15) || (getenv("DEVICE")=="PIC18F65J15")
    #if !defined(__18F65J15)
        #define __18F65J15
    #endif
    #if !defined(GLOBAL)
        #include <18F65J15.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65J15_registers.h"
#endif

#if defined(__18F65J50) || (getenv("DEVICE")=="PIC18F65J50")
    #if !defined(__18F65J50)
        #define __18F65J50
    #endif
    #if !defined(GLOBAL)
        #include <18F65J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65J50_registers.h"
#endif

#if defined(__18F65J90) || (getenv("DEVICE")=="PIC18F65J90")
    #if !defined(__18F65J90)
        #define __18F65J90
    #endif
    #if !defined(GLOBAL)
        #include <18F65J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65J90_registers.h"
#endif

#if defined(__18F65J94) || (getenv("DEVICE")=="PIC18F65J94")
    #if !defined(__18F65J94)
        #define __18F65J94
    #endif
    #if !defined(GLOBAL)
        #include <18F65J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65J94_registers.h"
#endif

#if defined(__18F65K22) || (getenv("DEVICE")=="PIC18F65K22")
    #if !defined(__18F65K22)
        #define __18F65K22
    #endif
    #if !defined(GLOBAL)
        #include <18F65K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65K22_registers.h"
#endif

#if defined(__18F65K80) || (getenv("DEVICE")=="PIC18F65K80")
    #if !defined(__18F65K80)
        #define __18F65K80
    #endif
    #if !defined(GLOBAL)
        #include <18F65K80.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65K80_registers.h"
#endif

#if defined(__18F65K90) || (getenv("DEVICE")=="PIC18F65K90")
    #if !defined(__18F65K90)
        #define __18F65K90
    #endif
    #if !defined(GLOBAL)
        #include <18F65K90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F65K90_registers.h"
#endif

#if defined(__18F6620) || (getenv("DEVICE")=="PIC18F6620")
    #if !defined(__18F6620)
        #define __18F6620
    #endif
    #if !defined(GLOBAL)
        #include <18F6620.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6620_registers.h"
#endif

#if defined(__18F6621) || (getenv("DEVICE")=="PIC18F6621")
    #if !defined(__18F6621)
        #define __18F6621
    #endif
    #if !defined(GLOBAL)
        #include <18F6621.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6621_registers.h"
#endif

#if defined(__18F6622) || (getenv("DEVICE")=="PIC18F6622")
    #if !defined(__18F6622)
        #define __18F6622
    #endif
    #if !defined(GLOBAL)
        #include <18F6622.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6622_registers.h"
#endif

#if defined(__18F6627) || (getenv("DEVICE")=="PIC18F6627")
    #if !defined(__18F6627)
        #define __18F6627
    #endif
    #if !defined(GLOBAL)
        #include <18F6627.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6627_registers.h"
#endif

#if defined(__18F6628) || (getenv("DEVICE")=="PIC18F6628")
    #if !defined(__18F6628)
        #define __18F6628
    #endif
    #if !defined(GLOBAL)
        #include <18F6628.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6628_registers.h"
#endif

#if defined(__18F6680) || (getenv("DEVICE")=="PIC18F6680")
    #if !defined(__18F6680)
        #define __18F6680
    #endif
    #if !defined(GLOBAL)
        #include <18F6680.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6680_registers.h"
#endif

#if defined(__18F66J10) || (getenv("DEVICE")=="PIC18F66J10")
    #if !defined(__18F66J10)
        #define __18F66J10
    #endif
    #if !defined(GLOBAL)
        #include <18F66J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J10_registers.h"
#endif

#if defined(__18F66J11) || (getenv("DEVICE")=="PIC18F66J11")
    #if !defined(__18F66J11)
        #define __18F66J11
    #endif
    #if !defined(GLOBAL)
        #include <18F66J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J11_registers.h"
#endif

#if defined(__18F66J15) || (getenv("DEVICE")=="PIC18F66J15")
    #if !defined(__18F66J15)
        #define __18F66J15
    #endif
    #if !defined(GLOBAL)
        #include <18F66J15.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J15_registers.h"
#endif

#if defined(__18F66J16) || (getenv("DEVICE")=="PIC18F66J16")
    #if !defined(__18F66J16)
        #define __18F66J16
    #endif
    #if !defined(GLOBAL)
        #include <18F66J16.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J16_registers.h"
#endif

#if defined(__18F66J50) || (getenv("DEVICE")=="PIC18F66J50")
    #if !defined(__18F66J50)
        #define __18F66J50
    #endif
    #if !defined(GLOBAL)
        #include <18F66J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J50_registers.h"
#endif

#if defined(__18F66J55) || (getenv("DEVICE")=="PIC18F66J55")
    #if !defined(__18F66J55)
        #define __18F66J55
    #endif
    #if !defined(GLOBAL)
        #include <18F66J55.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J55_registers.h"
#endif

#if defined(__18F66J60) || (getenv("DEVICE")=="PIC18F66J60")
    #if !defined(__18F66J60)
        #define __18F66J60
    #endif
    #if !defined(GLOBAL)
        #include <18F66J60.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J60_registers.h"
#endif

#if defined(__18F66J65) || (getenv("DEVICE")=="PIC18F66J65")
    #if !defined(__18F66J65)
        #define __18F66J65
    #endif
    #if !defined(GLOBAL)
        #include <18F66J65.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J65_registers.h"
#endif

#if defined(__18F66J90) || (getenv("DEVICE")=="PIC18F66J90")
    #if !defined(__18F66J90)
        #define __18F66J90
    #endif
    #if !defined(GLOBAL)
        #include <18F66J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J90_registers.h"
#endif

#if defined(__18F66J93) || (getenv("DEVICE")=="PIC18F66J93")
    #if !defined(__18F66J93)
        #define __18F66J93
    #endif
    #if !defined(GLOBAL)
        #include <18F66J93.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J93_registers.h"
#endif

#if defined(__18F66J94) || (getenv("DEVICE")=="PIC18F66J94")
    #if !defined(__18F66J94)
        #define __18F66J94
    #endif
    #if !defined(GLOBAL)
        #include <18F66J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J94_registers.h"
#endif

#if defined(__18F66J99) || (getenv("DEVICE")=="PIC18F66J99")
    #if !defined(__18F66J99)
        #define __18F66J99
    #endif
    #if !defined(GLOBAL)
        #include <18F66J99.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66J99_registers.h"
#endif

#if defined(__18F66K22) || (getenv("DEVICE")=="PIC18F66K22")
    #if !defined(__18F66K22)
        #define __18F66K22
    #endif
    #if !defined(GLOBAL)
        #include <18F66K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66K22_registers.h"
#endif

#if defined(__18F66K80) || (getenv("DEVICE")=="PIC18F66K80")
    #if !defined(__18F66K80)
        #define __18F66K80
    #endif
    #if !defined(GLOBAL)
        #include <18F66K80.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66K80_registers.h"
#endif

#if defined(__18F66K90) || (getenv("DEVICE")=="PIC18F66K90")
    #if !defined(__18F66K90)
        #define __18F66K90
    #endif
    #if !defined(GLOBAL)
        #include <18F66K90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F66K90_registers.h"
#endif

#if defined(__18F6720) || (getenv("DEVICE")=="PIC18F6720")
    #if !defined(__18F6720)
        #define __18F6720
    #endif
    #if !defined(GLOBAL)
        #include <18F6720.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6720_registers.h"
#endif

#if defined(__18F6722) || (getenv("DEVICE")=="PIC18F6722")
    #if !defined(__18F6722)
        #define __18F6722
    #endif
    #if !defined(GLOBAL)
        #include <18F6722.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6722_registers.h"
#endif

#if defined(__18F6723) || (getenv("DEVICE")=="PIC18F6723")
    #if !defined(__18F6723)
        #define __18F6723
    #endif
    #if !defined(GLOBAL)
        #include <18F6723.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F6723_registers.h"
#endif

#if defined(__18F67J10) || (getenv("DEVICE")=="PIC18F67J10")
    #if !defined(__18F67J10)
        #define __18F67J10
    #endif
    #if !defined(GLOBAL)
        #include <18F67J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67J10_registers.h"
#endif

#if defined(__18F67J11) || (getenv("DEVICE")=="PIC18F67J11")
    #if !defined(__18F67J11)
        #define __18F67J11
    #endif
    #if !defined(GLOBAL)
        #include <18F67J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67J11_registers.h"
#endif

#if defined(__18F67J50) || (getenv("DEVICE")=="PIC18F67J50")
    #if !defined(__18F67J50)
        #define __18F67J50
    #endif
    #if !defined(GLOBAL)
        #include <18F67J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67J50_registers.h"
#endif

#if defined(__18F67J60) || (getenv("DEVICE")=="PIC18F67J60")
    #if !defined(__18F67J60)
        #define __18F67J60
    #endif
    #if !defined(GLOBAL)
        #include <18F67J60.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67J60_registers.h"
#endif

#if defined(__18F67J90) || (getenv("DEVICE")=="PIC18F67J90")
    #if !defined(__18F67J90)
        #define __18F67J90
    #endif
    #if !defined(GLOBAL)
        #include <18F67J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67J90_registers.h"
#endif

#if defined(__18F67J93) || (getenv("DEVICE")=="PIC18F67J93")
    #if !defined(__18F67J93)
        #define __18F67J93
    #endif
    #if !defined(GLOBAL)
        #include <18F67J93.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67J93_registers.h"
#endif

#if defined(__18F67J94) || (getenv("DEVICE")=="PIC18F67J94")
    #if !defined(__18F67J94)
        #define __18F67J94
    #endif
    #if !defined(GLOBAL)
        #include <18F67J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67J94_registers.h"
#endif

#if defined(__18F67K22) || (getenv("DEVICE")=="PIC18F67K22")
    #if !defined(__18F67K22)
        #define __18F67K22
    #endif
    #if !defined(GLOBAL)
        #include <18F67K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67K22_registers.h"
#endif

#if defined(__18F67K90) || (getenv("DEVICE")=="PIC18F67K90")
    #if !defined(__18F67K90)
        #define __18F67K90
    #endif
    #if !defined(GLOBAL)
        #include <18F67K90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F67K90_registers.h"
#endif

#if defined(__18F8310) || (getenv("DEVICE")=="PIC18F8310")
    #if !defined(__18F8310)
        #define __18F8310
    #endif
    #if !defined(GLOBAL)
        #include <18F8310.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8310_registers.h"
#endif

#if defined(__18F8390) || (getenv("DEVICE")=="PIC18F8390")
    #if !defined(__18F8390)
        #define __18F8390
    #endif
    #if !defined(GLOBAL)
        #include <18F8390.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8390_registers.h"
#endif

#if defined(__18F8393) || (getenv("DEVICE")=="PIC18F8393")
    #if !defined(__18F8393)
        #define __18F8393
    #endif
    #if !defined(GLOBAL)
        #include <18F8393.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8393_registers.h"
#endif

#if defined(__18F83J11) || (getenv("DEVICE")=="PIC18F83J11")
    #if !defined(__18F83J11)
        #define __18F83J11
    #endif
    #if !defined(GLOBAL)
        #include <18F83J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F83J11_registers.h"
#endif

#if defined(__18F83J90) || (getenv("DEVICE")=="PIC18F83J90")
    #if !defined(__18F83J90)
        #define __18F83J90
    #endif
    #if !defined(GLOBAL)
        #include <18F83J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F83J90_registers.h"
#endif

#if defined(__18F8410) || (getenv("DEVICE")=="PIC18F8410")
    #if !defined(__18F8410)
        #define __18F8410
    #endif
    #if !defined(GLOBAL)
        #include <18F8410.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8410_registers.h"
#endif

#if defined(__18F8490) || (getenv("DEVICE")=="PIC18F8490")
    #if !defined(__18F8490)
        #define __18F8490
    #endif
    #if !defined(GLOBAL)
        #include <18F8490.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8490_registers.h"
#endif

#if defined(__18F8493) || (getenv("DEVICE")=="PIC18F8493")
    #if !defined(__18F8493)
        #define __18F8493
    #endif
    #if !defined(GLOBAL)
        #include <18F8493.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8493_registers.h"
#endif

#if defined(__18F84J11) || (getenv("DEVICE")=="PIC18F84J11")
    #if !defined(__18F84J11)
        #define __18F84J11
    #endif
    #if !defined(GLOBAL)
        #include <18F84J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F84J11_registers.h"
#endif

#if defined(__18F84J90) || (getenv("DEVICE")=="PIC18F84J90")
    #if !defined(__18F84J90)
        #define __18F84J90
    #endif
    #if !defined(GLOBAL)
        #include <18F84J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F84J90_registers.h"
#endif

#if defined(__18F8520) || (getenv("DEVICE")=="PIC18F8520")
    #if !defined(__18F8520)
        #define __18F8520
    #endif
    #if !defined(GLOBAL)
        #include <18F8520.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8520_registers.h"
#endif

#if defined(__18F8525) || (getenv("DEVICE")=="PIC18F8525")
    #if !defined(__18F8525)
        #define __18F8525
    #endif
    #if !defined(GLOBAL)
        #include <18F8525.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8525_registers.h"
#endif

#if defined(__18F8527) || (getenv("DEVICE")=="PIC18F8527")
    #if !defined(__18F8527)
        #define __18F8527
    #endif
    #if !defined(GLOBAL)
        #include <18F8527.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8527_registers.h"
#endif

#if defined(__18F8585) || (getenv("DEVICE")=="PIC18F8585")
    #if !defined(__18F8585)
        #define __18F8585
    #endif
    #if !defined(GLOBAL)
        #include <18F8585.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8585_registers.h"
#endif

#if defined(__18F85J10) || (getenv("DEVICE")=="PIC18F85J10")
    #if !defined(__18F85J10)
        #define __18F85J10
    #endif
    #if !defined(GLOBAL)
        #include <18F85J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85J10_registers.h"
#endif

#if defined(__18F85J11) || (getenv("DEVICE")=="PIC18F85J11")
    #if !defined(__18F85J11)
        #define __18F85J11
    #endif
    #if !defined(GLOBAL)
        #include <18F85J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85J11_registers.h"
#endif

#if defined(__18F85J15) || (getenv("DEVICE")=="PIC18F85J15")
    #if !defined(__18F85J15)
        #define __18F85J15
    #endif
    #if !defined(GLOBAL)
        #include <18F85J15.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85J15_registers.h"
#endif

#if defined(__18F85J50) || (getenv("DEVICE")=="PIC18F85J50")
    #if !defined(__18F85J50)
        #define __18F85J50
    #endif
    #if !defined(GLOBAL)
        #include <18F85J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85J50_registers.h"
#endif

#if defined(__18F85J90) || (getenv("DEVICE")=="PIC18F85J90")
    #if !defined(__18F85J90)
        #define __18F85J90
    #endif
    #if !defined(GLOBAL)
        #include <18F85J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85J90_registers.h"
#endif

#if defined(__18F85J94) || (getenv("DEVICE")=="PIC18F85J94")
    #if !defined(__18F85J94)
        #define __18F85J94
    #endif
    #if !defined(GLOBAL)
        #include <18F85J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85J94_registers.h"
#endif

#if defined(__18F85K22) || (getenv("DEVICE")=="PIC18F85K22")
    #if !defined(__18F85K22)
        #define __18F85K22
    #endif
    #if !defined(GLOBAL)
        #include <18F85K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85K22_registers.h"
#endif

#if defined(__18F85K90) || (getenv("DEVICE")=="PIC18F85K90")
    #if !defined(__18F85K90)
        #define __18F85K90
    #endif
    #if !defined(GLOBAL)
        #include <18F85K90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F85K90_registers.h"
#endif

#if defined(__18F8620) || (getenv("DEVICE")=="PIC18F8620")
    #if !defined(__18F8620)
        #define __18F8620
    #endif
    #if !defined(GLOBAL)
        #include <18F8620.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8620_registers.h"
#endif

#if defined(__18F8621) || (getenv("DEVICE")=="PIC18F8621")
    #if !defined(__18F8621)
        #define __18F8621
    #endif
    #if !defined(GLOBAL)
        #include <18F8621.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8621_registers.h"
#endif

#if defined(__18F8622) || (getenv("DEVICE")=="PIC18F8622")
    #if !defined(__18F8622)
        #define __18F8622
    #endif
    #if !defined(GLOBAL)
        #include <18F8622.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8622_registers.h"
#endif

#if defined(__18F8627) || (getenv("DEVICE")=="PIC18F8627")
    #if !defined(__18F8627)
        #define __18F8627
    #endif
    #if !defined(GLOBAL)
        #include <18F8627.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8627_registers.h"
#endif

#if defined(__18F8628) || (getenv("DEVICE")=="PIC18F8628")
    #if !defined(__18F8628)
        #define __18F8628
    #endif
    #if !defined(GLOBAL)
        #include <18F8628.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8628_registers.h"
#endif

#if defined(__18F8680) || (getenv("DEVICE")=="PIC18F8680")
    #if !defined(__18F8680)
        #define __18F8680
    #endif
    #if !defined(GLOBAL)
        #include <18F8680.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8680_registers.h"
#endif

#if defined(__18F86J10) || (getenv("DEVICE")=="PIC18F86J10")
    #if !defined(__18F86J10)
        #define __18F86J10
    #endif
    #if !defined(GLOBAL)
        #include <18F86J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J10_registers.h"
#endif

#if defined(__18F86J11) || (getenv("DEVICE")=="PIC18F86J11")
    #if !defined(__18F86J11)
        #define __18F86J11
    #endif
    #if !defined(GLOBAL)
        #include <18F86J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J11_registers.h"
#endif

#if defined(__18F86J15) || (getenv("DEVICE")=="PIC18F86J15")
    #if !defined(__18F86J15)
        #define __18F86J15
    #endif
    #if !defined(GLOBAL)
        #include <18F86J15.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J15_registers.h"
#endif

#if defined(__18F86J16) || (getenv("DEVICE")=="PIC18F86J16")
    #if !defined(__18F86J16)
        #define __18F86J16
    #endif
    #if !defined(GLOBAL)
        #include <18F86J16.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J16_registers.h"
#endif

#if defined(__18F86J50) || (getenv("DEVICE")=="PIC18F86J50")
    #if !defined(__18F86J50)
        #define __18F86J50
    #endif
    #if !defined(GLOBAL)
        #include <18F86J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J50_registers.h"
#endif

#if defined(__18F86J55) || (getenv("DEVICE")=="PIC18F86J55")
    #if !defined(__18F86J55)
        #define __18F86J55
    #endif
    #if !defined(GLOBAL)
        #include <18F86J55.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J55_registers.h"
#endif

#if defined(__18F86J60) || (getenv("DEVICE")=="PIC18F86J60")
    #if !defined(__18F86J60)
        #define __18F86J60
    #endif
    #if !defined(GLOBAL)
        #include <18F86J60.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J60_registers.h"
#endif

#if defined(__18F86J65) || (getenv("DEVICE")=="PIC18F86J65")
    #if !defined(__18F86J65)
        #define __18F86J65
    #endif
    #if !defined(GLOBAL)
        #include <18F86J65.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J65_registers.h"
#endif

#if defined(__18F86J72) || (getenv("DEVICE")=="PIC18F86J72")
    #if !defined(__18F86J72)
        #define __18F86J72
    #endif
    #if !defined(GLOBAL)
        #include <18F86J72.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J72_registers.h"
#endif

#if defined(__18F86J90) || (getenv("DEVICE")=="PIC18F86J90")
    #if !defined(__18F86J90)
        #define __18F86J90
    #endif
    #if !defined(GLOBAL)
        #include <18F86J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J90_registers.h"
#endif

#if defined(__18F86J93) || (getenv("DEVICE")=="PIC18F86J93")
    #if !defined(__18F86J93)
        #define __18F86J93
    #endif
    #if !defined(GLOBAL)
        #include <18F86J93.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J93_registers.h"
#endif

#if defined(__18F86J94) || (getenv("DEVICE")=="PIC18F86J94")
    #if !defined(__18F86J94)
        #define __18F86J94
    #endif
    #if !defined(GLOBAL)
        #include <18F86J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J94_registers.h"
#endif

#if defined(__18F86J99) || (getenv("DEVICE")=="PIC18F86J99")
    #if !defined(__18F86J99)
        #define __18F86J99
    #endif
    #if !defined(GLOBAL)
        #include <18F86J99.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86J99_registers.h"
#endif

#if defined(__18F86K22) || (getenv("DEVICE")=="PIC18F86K22")
    #if !defined(__18F86K22)
        #define __18F86K22
    #endif
    #if !defined(GLOBAL)
        #include <18F86K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86K22_registers.h"
#endif

#if defined(__18F86K90) || (getenv("DEVICE")=="PIC18F86K90")
    #if !defined(__18F86K90)
        #define __18F86K90
    #endif
    #if !defined(GLOBAL)
        #include <18F86K90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F86K90_registers.h"
#endif

#if defined(__18F8720) || (getenv("DEVICE")=="PIC18F8720")
    #if !defined(__18F8720)
        #define __18F8720
    #endif
    #if !defined(GLOBAL)
        #include <18F8720.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8720_registers.h"
#endif

#if defined(__18F8722) || (getenv("DEVICE")=="PIC18F8722")
    #if !defined(__18F8722)
        #define __18F8722
    #endif
    #if !defined(GLOBAL)
        #include <18F8722.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8722_registers.h"
#endif

#if defined(__18F8723) || (getenv("DEVICE")=="PIC18F8723")
    #if !defined(__18F8723)
        #define __18F8723
    #endif
    #if !defined(GLOBAL)
        #include <18F8723.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F8723_registers.h"
#endif

#if defined(__18F87J10) || (getenv("DEVICE")=="PIC18F87J10")
    #if !defined(__18F87J10)
        #define __18F87J10
    #endif
    #if !defined(GLOBAL)
        #include <18F87J10.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J10_registers.h"
#endif

#if defined(__18F87J11) || (getenv("DEVICE")=="PIC18F87J11")
    #if !defined(__18F87J11)
        #define __18F87J11
    #endif
    #if !defined(GLOBAL)
        #include <18F87J11.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J11_registers.h"
#endif

#if defined(__18F87J50) || (getenv("DEVICE")=="PIC18F87J50")
    #if !defined(__18F87J50)
        #define __18F87J50
    #endif
    #if !defined(GLOBAL)
        #include <18F87J50.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J50_registers.h"
#endif

#if defined(__18F87J60) || (getenv("DEVICE")=="PIC18F87J60")
    #if !defined(__18F87J60)
        #define __18F87J60
    #endif
    #if !defined(GLOBAL)
        #include <18F87J60.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J60_registers.h"
#endif

#if defined(__18F87J72) || (getenv("DEVICE")=="PIC18F87J72")
    #if !defined(__18F87J72)
        #define __18F87J72
    #endif
    #if !defined(GLOBAL)
        #include <18F87J72.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J72_registers.h"
#endif

#if defined(__18F87J90) || (getenv("DEVICE")=="PIC18F87J90")
    #if !defined(__18F87J90)
        #define __18F87J90
    #endif
    #if !defined(GLOBAL)
        #include <18F87J90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J90_registers.h"
#endif

#if defined(__18F87J93) || (getenv("DEVICE")=="PIC18F87J93")
    #if !defined(__18F87J93)
        #define __18F87J93
    #endif
    #if !defined(GLOBAL)
        #include <18F87J93.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J93_registers.h"
#endif

#if defined(__18F87J94) || (getenv("DEVICE")=="PIC18F87J94")
    #if !defined(__18F87J94)
        #define __18F87J94
    #endif
    #if !defined(GLOBAL)
        #include <18F87J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87J94_registers.h"
#endif

#if defined(__18F87K22) || (getenv("DEVICE")=="PIC18F87K22")
    #if !defined(__18F87K22)
        #define __18F87K22
    #endif
    #if !defined(GLOBAL)
        #include <18F87K22.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87K22_registers.h"
#endif

#if defined(__18F87K90) || (getenv("DEVICE")=="PIC18F87K90")
    #if !defined(__18F87K90)
        #define __18F87K90
    #endif
    #if !defined(GLOBAL)
        #include <18F87K90.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F87K90_registers.h"
#endif

#if defined(__18F95J94) || (getenv("DEVICE")=="PIC18F95J94")
    #if !defined(__18F95J94)
        #define __18F95J94
    #endif
    #if !defined(GLOBAL)
        #include <18F95J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F95J94_registers.h"
#endif

#if defined(__18F96J60) || (getenv("DEVICE")=="PIC18F96J60")
    #if !defined(__18F96J60)
        #define __18F96J60
    #endif
    #if !defined(GLOBAL)
        #include <18F96J60.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F96J60_registers.h"
#endif

#if defined(__18F96J65) || (getenv("DEVICE")=="PIC18F96J65")
    #if !defined(__18F96J65)
        #define __18F96J65
    #endif
    #if !defined(GLOBAL)
        #include <18F96J65.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F96J65_registers.h"
#endif

#if defined(__18F96J94) || (getenv("DEVICE")=="PIC18F96J94")
    #if !defined(__18F96J94)
        #define __18F96J94
    #endif
    #if !defined(GLOBAL)
        #include <18F96J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F96J94_registers.h"
#endif

#if defined(__18F96J99) || (getenv("DEVICE")=="PIC18F96J99")
    #if !defined(__18F96J99)
        #define __18F96J99
    #endif
    #if !defined(GLOBAL)
        #include <18F96J99.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F96J99_registers.h"
#endif

#if defined(__18F97J60) || (getenv("DEVICE")=="PIC18F97J60")
    #if !defined(__18F97J60)
        #define __18F97J60
    #endif
    #if !defined(GLOBAL)
        #include <18F97J60.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F97J60_registers.h"
#endif

#if defined(__18F97J94) || (getenv("DEVICE")=="PIC18F97J94")
    #if !defined(__18F97J94)
        #define __18F97J94
    #endif
    #if !defined(GLOBAL)
        #include <18F97J94.h>
    #endif
    #if !defined(__18CXX)
        #define __18CXX
    #endif
    #include "18F97J94_registers.h"
#endif

#if defined(__dsPIC19111__) || (getenv("DEVICE")=="DSPIC19111")
    #if !defined(__dsPIC19111__)
        #define __dsPIC19111__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <19111.h>
    #endif
    #if !defined(__dsPIC191111__)
        #define __dsPIC191111__
    #endif
    #include "19111_registers.h"
#endif

#if defined(__PIC24EP128GP202__) || (getenv("DEVICE")=="PIC24EP128GP202")
    #if !defined(__PIC24EP128GP202__)
        #define __PIC24EP128GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP128GP202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP128GP202_registers.h"
#endif

#if defined(__PIC24EP128GP204__) || (getenv("DEVICE")=="PIC24EP128GP204")
    #if !defined(__PIC24EP128GP204__)
        #define __PIC24EP128GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP128GP204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP128GP204_registers.h"
#endif

#if defined(__PIC24EP128GP206__) || (getenv("DEVICE")=="PIC24EP128GP206")
    #if !defined(__PIC24EP128GP206__)
        #define __PIC24EP128GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP128GP206.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP128GP206_registers.h"
#endif

#if defined(__PIC24EP128MC202__) || (getenv("DEVICE")=="PIC24EP128MC202")
    #if !defined(__PIC24EP128MC202__)
        #define __PIC24EP128MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP128MC202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP128MC202_registers.h"
#endif

#if defined(__PIC24EP128MC204__) || (getenv("DEVICE")=="PIC24EP128MC204")
    #if !defined(__PIC24EP128MC204__)
        #define __PIC24EP128MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP128MC204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP128MC204_registers.h"
#endif

#if defined(__PIC24EP128MC206__) || (getenv("DEVICE")=="PIC24EP128MC206")
    #if !defined(__PIC24EP128MC206__)
        #define __PIC24EP128MC206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP128MC206.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP128MC206_registers.h"
#endif

#if defined(__PIC24EP256GP202__) || (getenv("DEVICE")=="PIC24EP256GP202")
    #if !defined(__PIC24EP256GP202__)
        #define __PIC24EP256GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256GP202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256GP202_registers.h"
#endif

#if defined(__PIC24EP256GP204__) || (getenv("DEVICE")=="PIC24EP256GP204")
    #if !defined(__PIC24EP256GP204__)
        #define __PIC24EP256GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256GP204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256GP204_registers.h"
#endif

#if defined(__PIC24EP256GP206__) || (getenv("DEVICE")=="PIC24EP256GP206")
    #if !defined(__PIC24EP256GP206__)
        #define __PIC24EP256GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256GP206.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256GP206_registers.h"
#endif

#if defined(__PIC24EP256GU810__) || (getenv("DEVICE")=="PIC24EP256GU810")
    #if !defined(__PIC24EP256GU810__)
        #define __PIC24EP256GU810__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256GU810.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256GU810_registers.h"
#endif

#if defined(__PIC24EP256GU814__) || (getenv("DEVICE")=="PIC24EP256GU814")
    #if !defined(__PIC24EP256GU814__)
        #define __PIC24EP256GU814__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256GU814.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256GU814_registers.h"
#endif

#if defined(__PIC24EP256MC202__) || (getenv("DEVICE")=="PIC24EP256MC202")
    #if !defined(__PIC24EP256MC202__)
        #define __PIC24EP256MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256MC202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256MC202_registers.h"
#endif

#if defined(__PIC24EP256MC204__) || (getenv("DEVICE")=="PIC24EP256MC204")
    #if !defined(__PIC24EP256MC204__)
        #define __PIC24EP256MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256MC204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256MC204_registers.h"
#endif

#if defined(__PIC24EP256MC206__) || (getenv("DEVICE")=="PIC24EP256MC206")
    #if !defined(__PIC24EP256MC206__)
        #define __PIC24EP256MC206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP256MC206.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP256MC206_registers.h"
#endif

#if defined(__PIC24EP32GP202__) || (getenv("DEVICE")=="PIC24EP32GP202")
    #if !defined(__PIC24EP32GP202__)
        #define __PIC24EP32GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP32GP202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP32GP202_registers.h"
#endif

#if defined(__PIC24EP32GP203__) || (getenv("DEVICE")=="PIC24EP32GP203")
    #if !defined(__PIC24EP32GP203__)
        #define __PIC24EP32GP203__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP32GP203.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP32GP203_registers.h"
#endif

#if defined(__PIC24EP32GP204__) || (getenv("DEVICE")=="PIC24EP32GP204")
    #if !defined(__PIC24EP32GP204__)
        #define __PIC24EP32GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP32GP204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP32GP204_registers.h"
#endif

#if defined(__PIC24EP32MC202__) || (getenv("DEVICE")=="PIC24EP32MC202")
    #if !defined(__PIC24EP32MC202__)
        #define __PIC24EP32MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP32MC202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP32MC202_registers.h"
#endif

#if defined(__PIC24EP32MC203__) || (getenv("DEVICE")=="PIC24EP32MC203")
    #if !defined(__PIC24EP32MC203__)
        #define __PIC24EP32MC203__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP32MC203.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP32MC203_registers.h"
#endif

#if defined(__PIC24EP32MC204__) || (getenv("DEVICE")=="PIC24EP32MC204")
    #if !defined(__PIC24EP32MC204__)
        #define __PIC24EP32MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP32MC204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP32MC204_registers.h"
#endif

#if defined(__PIC24EP512GP806__) || (getenv("DEVICE")=="PIC24EP512GP806")
    #if !defined(__PIC24EP512GP806__)
        #define __PIC24EP512GP806__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP512GP806.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP512GP806_registers.h"
#endif

#if defined(__PIC24EP512GU810__) || (getenv("DEVICE")=="PIC24EP512GU810")
    #if !defined(__PIC24EP512GU810__)
        #define __PIC24EP512GU810__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP512GU810.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP512GU810_registers.h"
#endif

#if defined(__PIC24EP512GU814__) || (getenv("DEVICE")=="PIC24EP512GU814")
    #if !defined(__PIC24EP512GU814__)
        #define __PIC24EP512GU814__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP512GU814.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP512GU814_registers.h"
#endif

#if defined(__PIC24EP64GP202__) || (getenv("DEVICE")=="PIC24EP64GP202")
    #if !defined(__PIC24EP64GP202__)
        #define __PIC24EP64GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64GP202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64GP202_registers.h"
#endif

#if defined(__PIC24EP64GP203__) || (getenv("DEVICE")=="PIC24EP64GP203")
    #if !defined(__PIC24EP64GP203__)
        #define __PIC24EP64GP203__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64GP203.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64GP203_registers.h"
#endif

#if defined(__PIC24EP64GP204__) || (getenv("DEVICE")=="PIC24EP64GP204")
    #if !defined(__PIC24EP64GP204__)
        #define __PIC24EP64GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64GP204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64GP204_registers.h"
#endif

#if defined(__PIC24EP64GP206__) || (getenv("DEVICE")=="PIC24EP64GP206")
    #if !defined(__PIC24EP64GP206__)
        #define __PIC24EP64GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64GP206.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64GP206_registers.h"
#endif

#if defined(__PIC24EP64MC202__) || (getenv("DEVICE")=="PIC24EP64MC202")
    #if !defined(__PIC24EP64MC202__)
        #define __PIC24EP64MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64MC202.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64MC202_registers.h"
#endif

#if defined(__PIC24EP64MC203__) || (getenv("DEVICE")=="PIC24EP64MC203")
    #if !defined(__PIC24EP64MC203__)
        #define __PIC24EP64MC203__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64MC203.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64MC203_registers.h"
#endif

#if defined(__PIC24EP64MC204__) || (getenv("DEVICE")=="PIC24EP64MC204")
    #if !defined(__PIC24EP64MC204__)
        #define __PIC24EP64MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64MC204.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64MC204_registers.h"
#endif

#if defined(__PIC24EP64MC206__) || (getenv("DEVICE")=="PIC24EP64MC206")
    #if !defined(__PIC24EP64MC206__)
        #define __PIC24EP64MC206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24EP64MC206.h>
    #endif
    #if !defined(__PIC24E__)
        #define __PIC24E__
    #endif
    #include "24EP64MC206_registers.h"
#endif

#if defined(__PIC24F04KA200__) || (getenv("DEVICE")=="PIC24F04KA200")
    #if !defined(__PIC24F04KA200__)
        #define __PIC24F04KA200__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F04KA200.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F04KA200_registers.h"
#endif

#if defined(__PIC24F04KA201__) || (getenv("DEVICE")=="PIC24F04KA201")
    #if !defined(__PIC24F04KA201__)
        #define __PIC24F04KA201__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F04KA201.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F04KA201_registers.h"
#endif

#if defined(__PIC24F04KL100__) || (getenv("DEVICE")=="PIC24F04KL100")
    #if !defined(__PIC24F04KL100__)
        #define __PIC24F04KL100__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F04KL100.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F04KL100_registers.h"
#endif

#if defined(__PIC24F04KL101__) || (getenv("DEVICE")=="PIC24F04KL101")
    #if !defined(__PIC24F04KL101__)
        #define __PIC24F04KL101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F04KL101.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F04KL101_registers.h"
#endif

#if defined(__PIC24F08KA101__) || (getenv("DEVICE")=="PIC24F08KA101")
    #if !defined(__PIC24F08KA101__)
        #define __PIC24F08KA101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KA101.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F08KA101_registers.h"
#endif

#if defined(__PIC24F08KA102__) || (getenv("DEVICE")=="PIC24F08KA102")
    #if !defined(__PIC24F08KA102__)
        #define __PIC24F08KA102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KA102.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F08KA102_registers.h"
#endif

#if defined(__PIC24F08KL200__) || (getenv("DEVICE")=="PIC24F08KL200")
    #if !defined(__PIC24F08KL200__)
        #define __PIC24F08KL200__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KL200.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KL200_registers.h"
#endif

#if defined(__PIC24F08KL201__) || (getenv("DEVICE")=="PIC24F08KL201")
    #if !defined(__PIC24F08KL201__)
        #define __PIC24F08KL201__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KL201.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KL201_registers.h"
#endif

#if defined(__PIC24F08KL301__) || (getenv("DEVICE")=="PIC24F08KL301")
    #if !defined(__PIC24F08KL301__)
        #define __PIC24F08KL301__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KL301.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KL301_registers.h"
#endif

#if defined(__PIC24F08KL302__) || (getenv("DEVICE")=="PIC24F08KL302")
    #if !defined(__PIC24F08KL302__)
        #define __PIC24F08KL302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KL302.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KL302_registers.h"
#endif

#if defined(__PIC24F08KL401__) || (getenv("DEVICE")=="PIC24F08KL401")
    #if !defined(__PIC24F08KL401__)
        #define __PIC24F08KL401__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KL401.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KL401_registers.h"
#endif

#if defined(__PIC24F08KL402__) || (getenv("DEVICE")=="PIC24F08KL402")
    #if !defined(__PIC24F08KL402__)
        #define __PIC24F08KL402__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KL402.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KL402_registers.h"
#endif

#if defined(__PIC24F08KM101__) || (getenv("DEVICE")=="PIC24F08KM101")
    #if !defined(__PIC24F08KM101__)
        #define __PIC24F08KM101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KM101.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KM101_registers.h"
#endif

#if defined(__PIC24F08KM102__) || (getenv("DEVICE")=="PIC24F08KM102")
    #if !defined(__PIC24F08KM102__)
        #define __PIC24F08KM102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KM102.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KM102_registers.h"
#endif

#if defined(__PIC24F08KM202__) || (getenv("DEVICE")=="PIC24F08KM202")
    #if !defined(__PIC24F08KM202__)
        #define __PIC24F08KM202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KM202.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KM202_registers.h"
#endif

#if defined(__PIC24F08KM204__) || (getenv("DEVICE")=="PIC24F08KM204")
    #if !defined(__PIC24F08KM204__)
        #define __PIC24F08KM204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F08KM204.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F08KM204_registers.h"
#endif

#if defined(__PIC24F16KA101__) || (getenv("DEVICE")=="PIC24F16KA101")
    #if !defined(__PIC24F16KA101__)
        #define __PIC24F16KA101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KA101.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F16KA101_registers.h"
#endif

#if defined(__PIC24F16KA102__) || (getenv("DEVICE")=="PIC24F16KA102")
    #if !defined(__PIC24F16KA102__)
        #define __PIC24F16KA102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KA102.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F16KA102_registers.h"
#endif

#if defined(__PIC24F16KA301__) || (getenv("DEVICE")=="PIC24F16KA301")
    #if !defined(__PIC24F16KA301__)
        #define __PIC24F16KA301__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KA301.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F16KA301_registers.h"
#endif

#if defined(__PIC24F16KA302__) || (getenv("DEVICE")=="PIC24F16KA302")
    #if !defined(__PIC24F16KA302__)
        #define __PIC24F16KA302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KA302.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F16KA302_registers.h"
#endif

#if defined(__PIC24F16KA304__) || (getenv("DEVICE")=="PIC24F16KA304")
    #if !defined(__PIC24F16KA304__)
        #define __PIC24F16KA304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KA304.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F16KA304_registers.h"
#endif

#if defined(__PIC24F16KL401__) || (getenv("DEVICE")=="PIC24F16KL401")
    #if !defined(__PIC24F16KL401__)
        #define __PIC24F16KL401__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KL401.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F16KL401_registers.h"
#endif

#if defined(__PIC24F16KL402__) || (getenv("DEVICE")=="PIC24F16KL402")
    #if !defined(__PIC24F16KL402__)
        #define __PIC24F16KL402__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KL402.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F16KL402_registers.h"
#endif

#if defined(__PIC24F16KM102__) || (getenv("DEVICE")=="PIC24F16KM102")
    #if !defined(__PIC24F16KM102__)
        #define __PIC24F16KM102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KM102.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F16KM102_registers.h"
#endif

#if defined(__PIC24F16KM104__) || (getenv("DEVICE")=="PIC24F16KM104")
    #if !defined(__PIC24F16KM104__)
        #define __PIC24F16KM104__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KM104.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F16KM104_registers.h"
#endif

#if defined(__PIC24F16KM202__) || (getenv("DEVICE")=="PIC24F16KM202")
    #if !defined(__PIC24F16KM202__)
        #define __PIC24F16KM202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KM202.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F16KM202_registers.h"
#endif

#if defined(__PIC24F16KM204__) || (getenv("DEVICE")=="PIC24F16KM204")
    #if !defined(__PIC24F16KM204__)
        #define __PIC24F16KM204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F16KM204.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24F16KM204_registers.h"
#endif

#if defined(__PIC24F32KA301__) || (getenv("DEVICE")=="PIC24F32KA301")
    #if !defined(__PIC24F32KA301__)
        #define __PIC24F32KA301__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F32KA301.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F32KA301_registers.h"
#endif

#if defined(__PIC24F32KA302__) || (getenv("DEVICE")=="PIC24F32KA302")
    #if !defined(__PIC24F32KA302__)
        #define __PIC24F32KA302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F32KA302.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F32KA302_registers.h"
#endif

#if defined(__PIC24F32KA304__) || (getenv("DEVICE")=="PIC24F32KA304")
    #if !defined(__PIC24F32KA304__)
        #define __PIC24F32KA304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24F32KA304.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24F32KA304_registers.h"
#endif

#if defined(__PIC24FJ128DA106__) || (getenv("DEVICE")=="PIC24FJ128DA106")
    #if !defined(__PIC24FJ128DA106__)
        #define __PIC24FJ128DA106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128DA106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128DA106_registers.h"
#endif

#if defined(__PIC24FJ128DA110__) || (getenv("DEVICE")=="PIC24FJ128DA110")
    #if !defined(__PIC24FJ128DA110__)
        #define __PIC24FJ128DA110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128DA110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128DA110_registers.h"
#endif

#if defined(__PIC24FJ128DA206__) || (getenv("DEVICE")=="PIC24FJ128DA206")
    #if !defined(__PIC24FJ128DA206__)
        #define __PIC24FJ128DA206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128DA206.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128DA206_registers.h"
#endif

#if defined(__PIC24FJ128DA210__) || (getenv("DEVICE")=="PIC24FJ128DA210")
    #if !defined(__PIC24FJ128DA210__)
        #define __PIC24FJ128DA210__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128DA210.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128DA210_registers.h"
#endif

#if defined(__PIC24FJ128GA006__) || (getenv("DEVICE")=="PIC24FJ128GA006")
    #if !defined(__PIC24FJ128GA006__)
        #define __PIC24FJ128GA006__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA006.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA006_registers.h"
#endif

#if defined(__PIC24FJ128GA008__) || (getenv("DEVICE")=="PIC24FJ128GA008")
    #if !defined(__PIC24FJ128GA008__)
        #define __PIC24FJ128GA008__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA008.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA008_registers.h"
#endif

#if defined(__PIC24FJ128GA010__) || (getenv("DEVICE")=="PIC24FJ128GA010")
    #if !defined(__PIC24FJ128GA010__)
        #define __PIC24FJ128GA010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA010.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA010_registers.h"
#endif

#if defined(__PIC24FJ128GA106__) || (getenv("DEVICE")=="PIC24FJ128GA106")
    #if !defined(__PIC24FJ128GA106__)
        #define __PIC24FJ128GA106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA106_registers.h"
#endif

#if defined(__PIC24FJ128GA108__) || (getenv("DEVICE")=="PIC24FJ128GA108")
    #if !defined(__PIC24FJ128GA108__)
        #define __PIC24FJ128GA108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA108_registers.h"
#endif

#if defined(__PIC24FJ128GA110__) || (getenv("DEVICE")=="PIC24FJ128GA110")
    #if !defined(__PIC24FJ128GA110__)
        #define __PIC24FJ128GA110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA110_registers.h"
#endif

#if defined(__PIC24FJ128GA306__) || (getenv("DEVICE")=="PIC24FJ128GA306")
    #if !defined(__PIC24FJ128GA306__)
        #define __PIC24FJ128GA306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA306.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA306_registers.h"
#endif

#if defined(__PIC24FJ128GA308__) || (getenv("DEVICE")=="PIC24FJ128GA308")
    #if !defined(__PIC24FJ128GA308__)
        #define __PIC24FJ128GA308__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA308.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA308_registers.h"
#endif

#if defined(__PIC24FJ128GA310__) || (getenv("DEVICE")=="PIC24FJ128GA310")
    #if !defined(__PIC24FJ128GA310__)
        #define __PIC24FJ128GA310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GA310.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GA310_registers.h"
#endif

#if defined(__PIC24FJ128GB106__) || (getenv("DEVICE")=="PIC24FJ128GB106")
    #if !defined(__PIC24FJ128GB106__)
        #define __PIC24FJ128GB106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GB106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GB106_registers.h"
#endif

#if defined(__PIC24FJ128GB108__) || (getenv("DEVICE")=="PIC24FJ128GB108")
    #if !defined(__PIC24FJ128GB108__)
        #define __PIC24FJ128GB108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GB108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GB108_registers.h"
#endif

#if defined(__PIC24FJ128GB110__) || (getenv("DEVICE")=="PIC24FJ128GB110")
    #if !defined(__PIC24FJ128GB110__)
        #define __PIC24FJ128GB110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GB110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GB110_registers.h"
#endif

#if defined(__PIC24FJ128GB206__) || (getenv("DEVICE")=="PIC24FJ128GB206")
    #if !defined(__PIC24FJ128GB206__)
        #define __PIC24FJ128GB206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GB206.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GB206_registers.h"
#endif

#if defined(__PIC24FJ128GB210__) || (getenv("DEVICE")=="PIC24FJ128GB210")
    #if !defined(__PIC24FJ128GB210__)
        #define __PIC24FJ128GB210__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ128GB210.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ128GB210_registers.h"
#endif

#if defined(__PIC24FJ16GA002__) || (getenv("DEVICE")=="PIC24FJ16GA002")
    #if !defined(__PIC24FJ16GA002__)
        #define __PIC24FJ16GA002__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ16GA002.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ16GA002_registers.h"
#endif

#if defined(__PIC24FJ16GA004__) || (getenv("DEVICE")=="PIC24FJ16GA004")
    #if !defined(__PIC24FJ16GA004__)
        #define __PIC24FJ16GA004__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ16GA004.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ16GA004_registers.h"
#endif

#if defined(__PIC24FJ16MC101__) || (getenv("DEVICE")=="PIC24FJ16MC101")
    #if !defined(__PIC24FJ16MC101__)
        #define __PIC24FJ16MC101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ16MC101.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ16MC101_registers.h"
#endif

#if defined(__PIC24FJ16MC102__) || (getenv("DEVICE")=="PIC24FJ16MC102")
    #if !defined(__PIC24FJ16MC102__)
        #define __PIC24FJ16MC102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ16MC102.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ16MC102_registers.h"
#endif

#if defined(__PIC24FJ192GA106__) || (getenv("DEVICE")=="PIC24FJ192GA106")
    #if !defined(__PIC24FJ192GA106__)
        #define __PIC24FJ192GA106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ192GA106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ192GA106_registers.h"
#endif

#if defined(__PIC24FJ192GA108__) || (getenv("DEVICE")=="PIC24FJ192GA108")
    #if !defined(__PIC24FJ192GA108__)
        #define __PIC24FJ192GA108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ192GA108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ192GA108_registers.h"
#endif

#if defined(__PIC24FJ192GA110__) || (getenv("DEVICE")=="PIC24FJ192GA110")
    #if !defined(__PIC24FJ192GA110__)
        #define __PIC24FJ192GA110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ192GA110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ192GA110_registers.h"
#endif

#if defined(__PIC24FJ192GB106__) || (getenv("DEVICE")=="PIC24FJ192GB106")
    #if !defined(__PIC24FJ192GB106__)
        #define __PIC24FJ192GB106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ192GB106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ192GB106_registers.h"
#endif

#if defined(__PIC24FJ192GB108__) || (getenv("DEVICE")=="PIC24FJ192GB108")
    #if !defined(__PIC24FJ192GB108__)
        #define __PIC24FJ192GB108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ192GB108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ192GB108_registers.h"
#endif

#if defined(__PIC24FJ192GB110__) || (getenv("DEVICE")=="PIC24FJ192GB110")
    #if !defined(__PIC24FJ192GB110__)
        #define __PIC24FJ192GB110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ192GB110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ192GB110_registers.h"
#endif

#if defined(__PIC24FJ256DA106__) || (getenv("DEVICE")=="PIC24FJ256DA106")
    #if !defined(__PIC24FJ256DA106__)
        #define __PIC24FJ256DA106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256DA106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256DA106_registers.h"
#endif

#if defined(__PIC24FJ256DA110__) || (getenv("DEVICE")=="PIC24FJ256DA110")
    #if !defined(__PIC24FJ256DA110__)
        #define __PIC24FJ256DA110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256DA110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256DA110_registers.h"
#endif

#if defined(__PIC24FJ256DA206__) || (getenv("DEVICE")=="PIC24FJ256DA206")
    #if !defined(__PIC24FJ256DA206__)
        #define __PIC24FJ256DA206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256DA206.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256DA206_registers.h"
#endif

#if defined(__PIC24FJ256DA210__) || (getenv("DEVICE")=="PIC24FJ256DA210")
    #if !defined(__PIC24FJ256DA210__)
        #define __PIC24FJ256DA210__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256DA210.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256DA210_registers.h"
#endif

#if defined(__PIC24FJ256GA106__) || (getenv("DEVICE")=="PIC24FJ256GA106")
    #if !defined(__PIC24FJ256GA106__)
        #define __PIC24FJ256GA106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GA106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GA106_registers.h"
#endif

#if defined(__PIC24FJ256GA108__) || (getenv("DEVICE")=="PIC24FJ256GA108")
    #if !defined(__PIC24FJ256GA108__)
        #define __PIC24FJ256GA108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GA108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GA108_registers.h"
#endif

#if defined(__PIC24FJ256GA110__) || (getenv("DEVICE")=="PIC24FJ256GA110")
    #if !defined(__PIC24FJ256GA110__)
        #define __PIC24FJ256GA110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GA110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GA110_registers.h"
#endif

#if defined(__PIC24FJ256GB106__) || (getenv("DEVICE")=="PIC24FJ256GB106")
    #if !defined(__PIC24FJ256GB106__)
        #define __PIC24FJ256GB106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GB106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GB106_registers.h"
#endif

#if defined(__PIC24FJ256GB108__) || (getenv("DEVICE")=="PIC24FJ256GB108")
    #if !defined(__PIC24FJ256GB108__)
        #define __PIC24FJ256GB108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GB108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GB108_registers.h"
#endif

#if defined(__PIC24FJ256GB110__) || (getenv("DEVICE")=="PIC24FJ256GB110")
    #if !defined(__PIC24FJ256GB110__)
        #define __PIC24FJ256GB110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GB110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GB110_registers.h"
#endif

#if defined(__PIC24FJ256GB206__) || (getenv("DEVICE")=="PIC24FJ256GB206")
    #if !defined(__PIC24FJ256GB206__)
        #define __PIC24FJ256GB206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GB206.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GB206_registers.h"
#endif

#if defined(__PIC24FJ256GB210__) || (getenv("DEVICE")=="PIC24FJ256GB210")
    #if !defined(__PIC24FJ256GB210__)
        #define __PIC24FJ256GB210__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ256GB210.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ256GB210_registers.h"
#endif

#if defined(__PIC24FJ32GA002__) || (getenv("DEVICE")=="PIC24FJ32GA002")
    #if !defined(__PIC24FJ32GA002__)
        #define __PIC24FJ32GA002__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ32GA002.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ32GA002_registers.h"
#endif

#if defined(__PIC24FJ32GA004__) || (getenv("DEVICE")=="PIC24FJ32GA004")
    #if !defined(__PIC24FJ32GA004__)
        #define __PIC24FJ32GA004__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ32GA004.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ32GA004_registers.h"
#endif

#if defined(__PIC24FJ32GA102__) || (getenv("DEVICE")=="PIC24FJ32GA102")
    #if !defined(__PIC24FJ32GA102__)
        #define __PIC24FJ32GA102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ32GA102.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ32GA102_registers.h"
#endif

#if defined(__PIC24FJ32GA104__) || (getenv("DEVICE")=="PIC24FJ32GA104")
    #if !defined(__PIC24FJ32GA104__)
        #define __PIC24FJ32GA104__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ32GA104.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ32GA104_registers.h"
#endif

#if defined(__PIC24FJ32GB002__) || (getenv("DEVICE")=="PIC24FJ32GB002")
    #if !defined(__PIC24FJ32GB002__)
        #define __PIC24FJ32GB002__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ32GB002.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ32GB002_registers.h"
#endif

#if defined(__PIC24FJ32GB004__) || (getenv("DEVICE")=="PIC24FJ32GB004")
    #if !defined(__PIC24FJ32GB004__)
        #define __PIC24FJ32GB004__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ32GB004.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ32GB004_registers.h"
#endif

#if defined(__PIC24FJ48GA002__) || (getenv("DEVICE")=="PIC24FJ48GA002")
    #if !defined(__PIC24FJ48GA002__)
        #define __PIC24FJ48GA002__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ48GA002.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ48GA002_registers.h"
#endif

#if defined(__PIC24FJ48GA004__) || (getenv("DEVICE")=="PIC24FJ48GA004")
    #if !defined(__PIC24FJ48GA004__)
        #define __PIC24FJ48GA004__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ48GA004.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ48GA004_registers.h"
#endif

#if defined(__PIC24FJ64GA002__) || (getenv("DEVICE")=="PIC24FJ64GA002")
    #if !defined(__PIC24FJ64GA002__)
        #define __PIC24FJ64GA002__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA002.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA002_registers.h"
#endif

#if defined(__PIC24FJ64GA004__) || (getenv("DEVICE")=="PIC24FJ64GA004")
    #if !defined(__PIC24FJ64GA004__)
        #define __PIC24FJ64GA004__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA004.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA004_registers.h"
#endif

#if defined(__PIC24FJ64GA006__) || (getenv("DEVICE")=="PIC24FJ64GA006")
    #if !defined(__PIC24FJ64GA006__)
        #define __PIC24FJ64GA006__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA006.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA006_registers.h"
#endif

#if defined(__PIC24FJ64GA008__) || (getenv("DEVICE")=="PIC24FJ64GA008")
    #if !defined(__PIC24FJ64GA008__)
        #define __PIC24FJ64GA008__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA008.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA008_registers.h"
#endif

#if defined(__PIC24FJ64GA010__) || (getenv("DEVICE")=="PIC24FJ64GA010")
    #if !defined(__PIC24FJ64GA010__)
        #define __PIC24FJ64GA010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA010.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA010_registers.h"
#endif

#if defined(__PIC24FJ64GA102__) || (getenv("DEVICE")=="PIC24FJ64GA102")
    #if !defined(__PIC24FJ64GA102__)
        #define __PIC24FJ64GA102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA102.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA102_registers.h"
#endif

#if defined(__PIC24FJ64GA104__) || (getenv("DEVICE")=="PIC24FJ64GA104")
    #if !defined(__PIC24FJ64GA104__)
        #define __PIC24FJ64GA104__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA104.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA104_registers.h"
#endif

#if defined(__PIC24FJ64GA106__) || (getenv("DEVICE")=="PIC24FJ64GA106")
    #if !defined(__PIC24FJ64GA106__)
        #define __PIC24FJ64GA106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA106_registers.h"
#endif

#if defined(__PIC24FJ64GA108__) || (getenv("DEVICE")=="PIC24FJ64GA108")
    #if !defined(__PIC24FJ64GA108__)
        #define __PIC24FJ64GA108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA108_registers.h"
#endif

#if defined(__PIC24FJ64GA110__) || (getenv("DEVICE")=="PIC24FJ64GA110")
    #if !defined(__PIC24FJ64GA110__)
        #define __PIC24FJ64GA110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA110_registers.h"
#endif

#if defined(__PIC24FJ64GA306__) || (getenv("DEVICE")=="PIC24FJ64GA306")
    #if !defined(__PIC24FJ64GA306__)
        #define __PIC24FJ64GA306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA306.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA306_registers.h"
#endif

#if defined(__PIC24FJ64GA308__) || (getenv("DEVICE")=="PIC24FJ64GA308")
    #if !defined(__PIC24FJ64GA308__)
        #define __PIC24FJ64GA308__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA308.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA308_registers.h"
#endif

#if defined(__PIC24FJ64GA310__) || (getenv("DEVICE")=="PIC24FJ64GA310")
    #if !defined(__PIC24FJ64GA310__)
        #define __PIC24FJ64GA310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GA310.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GA310_registers.h"
#endif

#if defined(__PIC24FJ64GB002__) || (getenv("DEVICE")=="PIC24FJ64GB002")
    #if !defined(__PIC24FJ64GB002__)
        #define __PIC24FJ64GB002__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GB002.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GB002_registers.h"
#endif

#if defined(__PIC24FJ64GB004__) || (getenv("DEVICE")=="PIC24FJ64GB004")
    #if !defined(__PIC24FJ64GB004__)
        #define __PIC24FJ64GB004__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GB004.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GB004_registers.h"
#endif

#if defined(__PIC24FJ64GB106__) || (getenv("DEVICE")=="PIC24FJ64GB106")
    #if !defined(__PIC24FJ64GB106__)
        #define __PIC24FJ64GB106__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GB106.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GB106_registers.h"
#endif

#if defined(__PIC24FJ64GB108__) || (getenv("DEVICE")=="PIC24FJ64GB108")
    #if !defined(__PIC24FJ64GB108__)
        #define __PIC24FJ64GB108__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GB108.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GB108_registers.h"
#endif

#if defined(__PIC24FJ64GB110__) || (getenv("DEVICE")=="PIC24FJ64GB110")
    #if !defined(__PIC24FJ64GB110__)
        #define __PIC24FJ64GB110__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ64GB110.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ64GB110_registers.h"
#endif

#if defined(__PIC24FJ96GA006__) || (getenv("DEVICE")=="PIC24FJ96GA006")
    #if !defined(__PIC24FJ96GA006__)
        #define __PIC24FJ96GA006__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ96GA006.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ96GA006_registers.h"
#endif

#if defined(__PIC24FJ96GA008__) || (getenv("DEVICE")=="PIC24FJ96GA008")
    #if !defined(__PIC24FJ96GA008__)
        #define __PIC24FJ96GA008__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ96GA008.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ96GA008_registers.h"
#endif

#if defined(__PIC24FJ96GA010__) || (getenv("DEVICE")=="PIC24FJ96GA010")
    #if !defined(__PIC24FJ96GA010__)
        #define __PIC24FJ96GA010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FJ96GA010.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FJ96GA010_registers.h"
#endif

#if defined(__PIC24FV08KM101__) || (getenv("DEVICE")=="PIC24FV08KM101")
    #if !defined(__PIC24FV08KM101__)
        #define __PIC24FV08KM101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV08KM101.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV08KM101_registers.h"
#endif

#if defined(__PIC24FV08KM102__) || (getenv("DEVICE")=="PIC24FV08KM102")
    #if !defined(__PIC24FV08KM102__)
        #define __PIC24FV08KM102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV08KM102.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV08KM102_registers.h"
#endif

#if defined(__PIC24FV08KM202__) || (getenv("DEVICE")=="PIC24FV08KM202")
    #if !defined(__PIC24FV08KM202__)
        #define __PIC24FV08KM202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV08KM202.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV08KM202_registers.h"
#endif

#if defined(__PIC24FV08KM204__) || (getenv("DEVICE")=="PIC24FV08KM204")
    #if !defined(__PIC24FV08KM204__)
        #define __PIC24FV08KM204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV08KM204.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV08KM204_registers.h"
#endif

#if defined(__PIC24FV16KA301__) || (getenv("DEVICE")=="PIC24FV16KA301")
    #if !defined(__PIC24FV16KA301__)
        #define __PIC24FV16KA301__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV16KA301.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24FV16KA301_registers.h"
#endif

#if defined(__PIC24FV16KA302__) || (getenv("DEVICE")=="PIC24FV16KA302")
    #if !defined(__PIC24FV16KA302__)
        #define __PIC24FV16KA302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV16KA302.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24FV16KA302_registers.h"
#endif

#if defined(__PIC24FV16KA304__) || (getenv("DEVICE")=="PIC24FV16KA304")
    #if !defined(__PIC24FV16KA304__)
        #define __PIC24FV16KA304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV16KA304.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24FV16KA304_registers.h"
#endif

#if defined(__PIC24FV16KM102__) || (getenv("DEVICE")=="PIC24FV16KM102")
    #if !defined(__PIC24FV16KM102__)
        #define __PIC24FV16KM102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV16KM102.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV16KM102_registers.h"
#endif

#if defined(__PIC24FV16KM104__) || (getenv("DEVICE")=="PIC24FV16KM104")
    #if !defined(__PIC24FV16KM104__)
        #define __PIC24FV16KM104__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV16KM104.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV16KM104_registers.h"
#endif

#if defined(__PIC24FV16KM202__) || (getenv("DEVICE")=="PIC24FV16KM202")
    #if !defined(__PIC24FV16KM202__)
        #define __PIC24FV16KM202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV16KM202.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV16KM202_registers.h"
#endif

#if defined(__PIC24FV16KM204__) || (getenv("DEVICE")=="PIC24FV16KM204")
    #if !defined(__PIC24FV16KM204__)
        #define __PIC24FV16KM204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV16KM204.h>
    #endif
    #if !defined(__PIC24F__)
        #define __PIC24F__
    #endif
    #include "24FV16KM204_registers.h"
#endif

#if defined(__PIC24FV32KA301__) || (getenv("DEVICE")=="PIC24FV32KA301")
    #if !defined(__PIC24FV32KA301__)
        #define __PIC24FV32KA301__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV32KA301.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24FV32KA301_registers.h"
#endif

#if defined(__PIC24FV32KA302__) || (getenv("DEVICE")=="PIC24FV32KA302")
    #if !defined(__PIC24FV32KA302__)
        #define __PIC24FV32KA302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV32KA302.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24FV32KA302_registers.h"
#endif

#if defined(__PIC24FV32KA304__) || (getenv("DEVICE")=="PIC24FV32KA304")
    #if !defined(__PIC24FV32KA304__)
        #define __PIC24FV32KA304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24FV32KA304.h>
    #endif
    #if !defined(__PIC24FK__)
        #define __PIC24FK__
    #endif
    #include "24FV32KA304_registers.h"
#endif

#if defined(__PIC24HJ128GP202__) || (getenv("DEVICE")=="PIC24HJ128GP202")
    #if !defined(__PIC24HJ128GP202__)
        #define __PIC24HJ128GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP202.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP202_registers.h"
#endif

#if defined(__PIC24HJ128GP204__) || (getenv("DEVICE")=="PIC24HJ128GP204")
    #if !defined(__PIC24HJ128GP204__)
        #define __PIC24HJ128GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP204.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP204_registers.h"
#endif

#if defined(__PIC24HJ128GP206__) || (getenv("DEVICE")=="PIC24HJ128GP206")
    #if !defined(__PIC24HJ128GP206__)
        #define __PIC24HJ128GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP206.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP206_registers.h"
#endif

#if defined(__PIC24HJ128GP206A__) || (getenv("DEVICE")=="PIC24HJ128GP206A")
    #if !defined(__PIC24HJ128GP206A__)
        #define __PIC24HJ128GP206A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP206A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP206A_registers.h"
#endif

#if defined(__PIC24HJ128GP210__) || (getenv("DEVICE")=="PIC24HJ128GP210")
    #if !defined(__PIC24HJ128GP210__)
        #define __PIC24HJ128GP210__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP210.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP210_registers.h"
#endif

#if defined(__PIC24HJ128GP210A__) || (getenv("DEVICE")=="PIC24HJ128GP210A")
    #if !defined(__PIC24HJ128GP210A__)
        #define __PIC24HJ128GP210A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP210A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP210A_registers.h"
#endif

#if defined(__PIC24HJ128GP306__) || (getenv("DEVICE")=="PIC24HJ128GP306")
    #if !defined(__PIC24HJ128GP306__)
        #define __PIC24HJ128GP306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP306.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP306_registers.h"
#endif

#if defined(__PIC24HJ128GP306A__) || (getenv("DEVICE")=="PIC24HJ128GP306A")
    #if !defined(__PIC24HJ128GP306A__)
        #define __PIC24HJ128GP306A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP306A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP306A_registers.h"
#endif

#if defined(__PIC24HJ128GP310__) || (getenv("DEVICE")=="PIC24HJ128GP310")
    #if !defined(__PIC24HJ128GP310__)
        #define __PIC24HJ128GP310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP310.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP310_registers.h"
#endif

#if defined(__PIC24HJ128GP310A__) || (getenv("DEVICE")=="PIC24HJ128GP310A")
    #if !defined(__PIC24HJ128GP310A__)
        #define __PIC24HJ128GP310A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP310A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP310A_registers.h"
#endif

#if defined(__PIC24HJ128GP502__) || (getenv("DEVICE")=="PIC24HJ128GP502")
    #if !defined(__PIC24HJ128GP502__)
        #define __PIC24HJ128GP502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP502.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP502_registers.h"
#endif

#if defined(__PIC24HJ128GP504__) || (getenv("DEVICE")=="PIC24HJ128GP504")
    #if !defined(__PIC24HJ128GP504__)
        #define __PIC24HJ128GP504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP504.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP504_registers.h"
#endif

#if defined(__PIC24HJ128GP506__) || (getenv("DEVICE")=="PIC24HJ128GP506")
    #if !defined(__PIC24HJ128GP506__)
        #define __PIC24HJ128GP506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP506.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP506_registers.h"
#endif

#if defined(__PIC24HJ128GP506A__) || (getenv("DEVICE")=="PIC24HJ128GP506A")
    #if !defined(__PIC24HJ128GP506A__)
        #define __PIC24HJ128GP506A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP506A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP506A_registers.h"
#endif

#if defined(__PIC24HJ128GP510__) || (getenv("DEVICE")=="PIC24HJ128GP510")
    #if !defined(__PIC24HJ128GP510__)
        #define __PIC24HJ128GP510__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP510.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP510_registers.h"
#endif

#if defined(__PIC24HJ128GP510A__) || (getenv("DEVICE")=="PIC24HJ128GP510A")
    #if !defined(__PIC24HJ128GP510A__)
        #define __PIC24HJ128GP510A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ128GP510A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ128GP510A_registers.h"
#endif

#if defined(__PIC24HJ12GP201__) || (getenv("DEVICE")=="PIC24HJ12GP201")
    #if !defined(__PIC24HJ12GP201__)
        #define __PIC24HJ12GP201__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ12GP201.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ12GP201_registers.h"
#endif

#if defined(__PIC24HJ12GP202__) || (getenv("DEVICE")=="PIC24HJ12GP202")
    #if !defined(__PIC24HJ12GP202__)
        #define __PIC24HJ12GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ12GP202.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ12GP202_registers.h"
#endif

#if defined(__PIC24HJ16GP304__) || (getenv("DEVICE")=="PIC24HJ16GP304")
    #if !defined(__PIC24HJ16GP304__)
        #define __PIC24HJ16GP304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ16GP304.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ16GP304_registers.h"
#endif

#if defined(__PIC24HJ256GP206__) || (getenv("DEVICE")=="PIC24HJ256GP206")
    #if !defined(__PIC24HJ256GP206__)
        #define __PIC24HJ256GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ256GP206.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ256GP206_registers.h"
#endif

#if defined(__PIC24HJ256GP206A__) || (getenv("DEVICE")=="PIC24HJ256GP206A")
    #if !defined(__PIC24HJ256GP206A__)
        #define __PIC24HJ256GP206A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ256GP206A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ256GP206A_registers.h"
#endif

#if defined(__PIC24HJ256GP210__) || (getenv("DEVICE")=="PIC24HJ256GP210")
    #if !defined(__PIC24HJ256GP210__)
        #define __PIC24HJ256GP210__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ256GP210.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ256GP210_registers.h"
#endif

#if defined(__PIC24HJ256GP210A__) || (getenv("DEVICE")=="PIC24HJ256GP210A")
    #if !defined(__PIC24HJ256GP210A__)
        #define __PIC24HJ256GP210A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ256GP210A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ256GP210A_registers.h"
#endif

#if defined(__PIC24HJ256GP610__) || (getenv("DEVICE")=="PIC24HJ256GP610")
    #if !defined(__PIC24HJ256GP610__)
        #define __PIC24HJ256GP610__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ256GP610.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ256GP610_registers.h"
#endif

#if defined(__PIC24HJ256GP610A__) || (getenv("DEVICE")=="PIC24HJ256GP610A")
    #if !defined(__PIC24HJ256GP610A__)
        #define __PIC24HJ256GP610A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ256GP610A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ256GP610A_registers.h"
#endif

#if defined(__PIC24HJ32GP202__) || (getenv("DEVICE")=="PIC24HJ32GP202")
    #if !defined(__PIC24HJ32GP202__)
        #define __PIC24HJ32GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ32GP202.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ32GP202_registers.h"
#endif

#if defined(__PIC24HJ32GP204__) || (getenv("DEVICE")=="PIC24HJ32GP204")
    #if !defined(__PIC24HJ32GP204__)
        #define __PIC24HJ32GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ32GP204.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ32GP204_registers.h"
#endif

#if defined(__PIC24HJ32GP302__) || (getenv("DEVICE")=="PIC24HJ32GP302")
    #if !defined(__PIC24HJ32GP302__)
        #define __PIC24HJ32GP302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ32GP302.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ32GP302_registers.h"
#endif

#if defined(__PIC24HJ32GP304__) || (getenv("DEVICE")=="PIC24HJ32GP304")
    #if !defined(__PIC24HJ32GP304__)
        #define __PIC24HJ32GP304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ32GP304.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ32GP304_registers.h"
#endif

#if defined(__PIC24HJ64GP202__) || (getenv("DEVICE")=="PIC24HJ64GP202")
    #if !defined(__PIC24HJ64GP202__)
        #define __PIC24HJ64GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP202.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP202_registers.h"
#endif

#if defined(__PIC24HJ64GP204__) || (getenv("DEVICE")=="PIC24HJ64GP204")
    #if !defined(__PIC24HJ64GP204__)
        #define __PIC24HJ64GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP204.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP204_registers.h"
#endif

#if defined(__PIC24HJ64GP206__) || (getenv("DEVICE")=="PIC24HJ64GP206")
    #if !defined(__PIC24HJ64GP206__)
        #define __PIC24HJ64GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP206.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP206_registers.h"
#endif

#if defined(__PIC24HJ64GP206A__) || (getenv("DEVICE")=="PIC24HJ64GP206A")
    #if !defined(__PIC24HJ64GP206A__)
        #define __PIC24HJ64GP206A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP206A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP206A_registers.h"
#endif

#if defined(__PIC24HJ64GP210__) || (getenv("DEVICE")=="PIC24HJ64GP210")
    #if !defined(__PIC24HJ64GP210__)
        #define __PIC24HJ64GP210__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP210.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP210_registers.h"
#endif

#if defined(__PIC24HJ64GP210A__) || (getenv("DEVICE")=="PIC24HJ64GP210A")
    #if !defined(__PIC24HJ64GP210A__)
        #define __PIC24HJ64GP210A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP210A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP210A_registers.h"
#endif

#if defined(__PIC24HJ64GP502__) || (getenv("DEVICE")=="PIC24HJ64GP502")
    #if !defined(__PIC24HJ64GP502__)
        #define __PIC24HJ64GP502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP502.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP502_registers.h"
#endif

#if defined(__PIC24HJ64GP504__) || (getenv("DEVICE")=="PIC24HJ64GP504")
    #if !defined(__PIC24HJ64GP504__)
        #define __PIC24HJ64GP504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP504.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP504_registers.h"
#endif

#if defined(__PIC24HJ64GP506__) || (getenv("DEVICE")=="PIC24HJ64GP506")
    #if !defined(__PIC24HJ64GP506__)
        #define __PIC24HJ64GP506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP506.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP506_registers.h"
#endif

#if defined(__PIC24HJ64GP506A__) || (getenv("DEVICE")=="PIC24HJ64GP506A")
    #if !defined(__PIC24HJ64GP506A__)
        #define __PIC24HJ64GP506A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP506A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP506A_registers.h"
#endif

#if defined(__PIC24HJ64GP510__) || (getenv("DEVICE")=="PIC24HJ64GP510")
    #if !defined(__PIC24HJ64GP510__)
        #define __PIC24HJ64GP510__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP510.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP510_registers.h"
#endif

#if defined(__PIC24HJ64GP510A__) || (getenv("DEVICE")=="PIC24HJ64GP510A")
    #if !defined(__PIC24HJ64GP510A__)
        #define __PIC24HJ64GP510A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <24HJ64GP510A.h>
    #endif
    #if !defined(__PIC24H__)
        #define __PIC24H__
    #endif
    #include "24HJ64GP510A_registers.h"
#endif

#if defined(__dsPIC30F1010__) || (getenv("DEVICE")=="DSPIC30F1010")
    #if !defined(__dsPIC30F1010__)
        #define __dsPIC30F1010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F1010.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F1010_registers.h"
#endif

#if defined(__dsPIC30F2010__) || (getenv("DEVICE")=="DSPIC30F2010")
    #if !defined(__dsPIC30F2010__)
        #define __dsPIC30F2010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F2010.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F2010_registers.h"
#endif

#if defined(__dsPIC30F2011__) || (getenv("DEVICE")=="DSPIC30F2011")
    #if !defined(__dsPIC30F2011__)
        #define __dsPIC30F2011__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F2011.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F2011_registers.h"
#endif

#if defined(__dsPIC30F2012__) || (getenv("DEVICE")=="DSPIC30F2012")
    #if !defined(__dsPIC30F2012__)
        #define __dsPIC30F2012__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F2012.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F2012_registers.h"
#endif

#if defined(__dsPIC30F2020__) || (getenv("DEVICE")=="DSPIC30F2020")
    #if !defined(__dsPIC30F2020__)
        #define __dsPIC30F2020__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F2020.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F2020_registers.h"
#endif

#if defined(__dsPIC30F2023__) || (getenv("DEVICE")=="DSPIC30F2023")
    #if !defined(__dsPIC30F2023__)
        #define __dsPIC30F2023__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F2023.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F2023_registers.h"
#endif

#if defined(__dsPIC30F3010__) || (getenv("DEVICE")=="DSPIC30F3010")
    #if !defined(__dsPIC30F3010__)
        #define __dsPIC30F3010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F3010.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F3010_registers.h"
#endif

#if defined(__dsPIC30F3011__) || (getenv("DEVICE")=="DSPIC30F3011")
    #if !defined(__dsPIC30F3011__)
        #define __dsPIC30F3011__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F3011.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F3011_registers.h"
#endif

#if defined(__dsPIC30F3012__) || (getenv("DEVICE")=="DSPIC30F3012")
    #if !defined(__dsPIC30F3012__)
        #define __dsPIC30F3012__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F3012.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F3012_registers.h"
#endif

#if defined(__dsPIC30F3013__) || (getenv("DEVICE")=="DSPIC30F3013")
    #if !defined(__dsPIC30F3013__)
        #define __dsPIC30F3013__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F3013.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F3013_registers.h"
#endif

#if defined(__dsPIC30F3014__) || (getenv("DEVICE")=="DSPIC30F3014")
    #if !defined(__dsPIC30F3014__)
        #define __dsPIC30F3014__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F3014.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F3014_registers.h"
#endif

#if defined(__dsPIC30F4011__) || (getenv("DEVICE")=="DSPIC30F4011")
    #if !defined(__dsPIC30F4011__)
        #define __dsPIC30F4011__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F4011.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F4011_registers.h"
#endif

#if defined(__dsPIC30F4012__) || (getenv("DEVICE")=="DSPIC30F4012")
    #if !defined(__dsPIC30F4012__)
        #define __dsPIC30F4012__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F4012.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F4012_registers.h"
#endif

#if defined(__dsPIC30F4013__) || (getenv("DEVICE")=="DSPIC30F4013")
    #if !defined(__dsPIC30F4013__)
        #define __dsPIC30F4013__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F4013.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F4013_registers.h"
#endif

#if defined(__dsPIC30F5011__) || (getenv("DEVICE")=="DSPIC30F5011")
    #if !defined(__dsPIC30F5011__)
        #define __dsPIC30F5011__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F5011.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F5011_registers.h"
#endif

#if defined(__dsPIC30F5013__) || (getenv("DEVICE")=="DSPIC30F5013")
    #if !defined(__dsPIC30F5013__)
        #define __dsPIC30F5013__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F5013.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F5013_registers.h"
#endif

#if defined(__dsPIC30F5015__) || (getenv("DEVICE")=="DSPIC30F5015")
    #if !defined(__dsPIC30F5015__)
        #define __dsPIC30F5015__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F5015.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F5015_registers.h"
#endif

#if defined(__dsPIC30F5016__) || (getenv("DEVICE")=="DSPIC30F5016")
    #if !defined(__dsPIC30F5016__)
        #define __dsPIC30F5016__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F5016.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F5016_registers.h"
#endif

#if defined(__dsPIC30F6010__) || (getenv("DEVICE")=="DSPIC30F6010")
    #if !defined(__dsPIC30F6010__)
        #define __dsPIC30F6010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6010.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6010_registers.h"
#endif

#if defined(__dsPIC30F6010A__) || (getenv("DEVICE")=="DSPIC30F6010A")
    #if !defined(__dsPIC30F6010A__)
        #define __dsPIC30F6010A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6010A.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6010A_registers.h"
#endif

#if defined(__dsPIC30F6011__) || (getenv("DEVICE")=="DSPIC30F6011")
    #if !defined(__dsPIC30F6011__)
        #define __dsPIC30F6011__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6011.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6011_registers.h"
#endif

#if defined(__dsPIC30F6011A__) || (getenv("DEVICE")=="DSPIC30F6011A")
    #if !defined(__dsPIC30F6011A__)
        #define __dsPIC30F6011A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6011A.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6011A_registers.h"
#endif

#if defined(__dsPIC30F6012__) || (getenv("DEVICE")=="DSPIC30F6012")
    #if !defined(__dsPIC30F6012__)
        #define __dsPIC30F6012__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6012.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6012_registers.h"
#endif

#if defined(__dsPIC30F6012A__) || (getenv("DEVICE")=="DSPIC30F6012A")
    #if !defined(__dsPIC30F6012A__)
        #define __dsPIC30F6012A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6012A.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6012A_registers.h"
#endif

#if defined(__dsPIC30F6013__) || (getenv("DEVICE")=="DSPIC30F6013")
    #if !defined(__dsPIC30F6013__)
        #define __dsPIC30F6013__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6013.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6013_registers.h"
#endif

#if defined(__dsPIC30F6013A__) || (getenv("DEVICE")=="DSPIC30F6013A")
    #if !defined(__dsPIC30F6013A__)
        #define __dsPIC30F6013A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6013A.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6013A_registers.h"
#endif

#if defined(__dsPIC30F6014__) || (getenv("DEVICE")=="DSPIC30F6014")
    #if !defined(__dsPIC30F6014__)
        #define __dsPIC30F6014__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6014.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6014_registers.h"
#endif

#if defined(__dsPIC30F6014A__) || (getenv("DEVICE")=="DSPIC30F6014A")
    #if !defined(__dsPIC30F6014A__)
        #define __dsPIC30F6014A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6014A.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6014A_registers.h"
#endif

#if defined(__dsPIC30F6015__) || (getenv("DEVICE")=="DSPIC30F6015")
    #if !defined(__dsPIC30F6015__)
        #define __dsPIC30F6015__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <30F6015.h>
    #endif
    #if !defined(__dsPIC30F__)
        #define __dsPIC30F__
    #endif
    #include "30F6015_registers.h"
#endif

#if defined(__dsPIC33EP128GM304__) || (getenv("DEVICE")=="DSPIC33EP128GM304")
    #if !defined(__dsPIC33EP128GM304__)
        #define __dsPIC33EP128GM304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GM304.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GM304_registers.h"
#endif

#if defined(__dsPIC33EP128GM306__) || (getenv("DEVICE")=="DSPIC33EP128GM306")
    #if !defined(__dsPIC33EP128GM306__)
        #define __dsPIC33EP128GM306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GM306.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GM306_registers.h"
#endif

#if defined(__dsPIC33EP128GM310__) || (getenv("DEVICE")=="DSPIC33EP128GM310")
    #if !defined(__dsPIC33EP128GM310__)
        #define __dsPIC33EP128GM310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GM310.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GM310_registers.h"
#endif

#if defined(__dsPIC33EP128GM604__) || (getenv("DEVICE")=="DSPIC33EP128GM604")
    #if !defined(__dsPIC33EP128GM604__)
        #define __dsPIC33EP128GM604__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GM604.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GM604_registers.h"
#endif

#if defined(__dsPIC33EP128GM706__) || (getenv("DEVICE")=="DSPIC33EP128GM706")
    #if !defined(__dsPIC33EP128GM706__)
        #define __dsPIC33EP128GM706__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GM706.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GM706_registers.h"
#endif

#if defined(__dsPIC33EP128GM710__) || (getenv("DEVICE")=="DSPIC33EP128GM710")
    #if !defined(__dsPIC33EP128GM710__)
        #define __dsPIC33EP128GM710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GM710.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GM710_registers.h"
#endif

#if defined(__dsPIC33EP128GP502__) || (getenv("DEVICE")=="DSPIC33EP128GP502")
    #if !defined(__dsPIC33EP128GP502__)
        #define __dsPIC33EP128GP502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GP502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GP502_registers.h"
#endif

#if defined(__dsPIC33EP128GP504__) || (getenv("DEVICE")=="DSPIC33EP128GP504")
    #if !defined(__dsPIC33EP128GP504__)
        #define __dsPIC33EP128GP504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GP504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GP504_registers.h"
#endif

#if defined(__dsPIC33EP128GP506__) || (getenv("DEVICE")=="DSPIC33EP128GP506")
    #if !defined(__dsPIC33EP128GP506__)
        #define __dsPIC33EP128GP506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128GP506.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128GP506_registers.h"
#endif

#if defined(__dsPIC33EP128MC202__) || (getenv("DEVICE")=="DSPIC33EP128MC202")
    #if !defined(__dsPIC33EP128MC202__)
        #define __dsPIC33EP128MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128MC202.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128MC202_registers.h"
#endif

#if defined(__dsPIC33EP128MC204__) || (getenv("DEVICE")=="DSPIC33EP128MC204")
    #if !defined(__dsPIC33EP128MC204__)
        #define __dsPIC33EP128MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128MC204.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128MC204_registers.h"
#endif

#if defined(__dsPIC33EP128MC206__) || (getenv("DEVICE")=="DSPIC33EP128MC206")
    #if !defined(__dsPIC33EP128MC206__)
        #define __dsPIC33EP128MC206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128MC206.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128MC206_registers.h"
#endif

#if defined(__dsPIC33EP128MC502__) || (getenv("DEVICE")=="DSPIC33EP128MC502")
    #if !defined(__dsPIC33EP128MC502__)
        #define __dsPIC33EP128MC502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128MC502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128MC502_registers.h"
#endif

#if defined(__dsPIC33EP128MC504__) || (getenv("DEVICE")=="DSPIC33EP128MC504")
    #if !defined(__dsPIC33EP128MC504__)
        #define __dsPIC33EP128MC504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128MC504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128MC504_registers.h"
#endif

#if defined(__dsPIC33EP128MC506__) || (getenv("DEVICE")=="DSPIC33EP128MC506")
    #if !defined(__dsPIC33EP128MC506__)
        #define __dsPIC33EP128MC506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP128MC506.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP128MC506_registers.h"
#endif

#if defined(__dsPIC33EP256GM304__) || (getenv("DEVICE")=="DSPIC33EP256GM304")
    #if !defined(__dsPIC33EP256GM304__)
        #define __dsPIC33EP256GM304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GM304.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GM304_registers.h"
#endif

#if defined(__dsPIC33EP256GM306__) || (getenv("DEVICE")=="DSPIC33EP256GM306")
    #if !defined(__dsPIC33EP256GM306__)
        #define __dsPIC33EP256GM306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GM306.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GM306_registers.h"
#endif

#if defined(__dsPIC33EP256GM310__) || (getenv("DEVICE")=="DSPIC33EP256GM310")
    #if !defined(__dsPIC33EP256GM310__)
        #define __dsPIC33EP256GM310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GM310.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GM310_registers.h"
#endif

#if defined(__dsPIC33EP256GM604__) || (getenv("DEVICE")=="DSPIC33EP256GM604")
    #if !defined(__dsPIC33EP256GM604__)
        #define __dsPIC33EP256GM604__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GM604.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GM604_registers.h"
#endif

#if defined(__dsPIC33EP256GM706__) || (getenv("DEVICE")=="DSPIC33EP256GM706")
    #if !defined(__dsPIC33EP256GM706__)
        #define __dsPIC33EP256GM706__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GM706.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GM706_registers.h"
#endif

#if defined(__dsPIC33EP256GM710__) || (getenv("DEVICE")=="DSPIC33EP256GM710")
    #if !defined(__dsPIC33EP256GM710__)
        #define __dsPIC33EP256GM710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GM710.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GM710_registers.h"
#endif

#if defined(__dsPIC33EP256GP502__) || (getenv("DEVICE")=="DSPIC33EP256GP502")
    #if !defined(__dsPIC33EP256GP502__)
        #define __dsPIC33EP256GP502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GP502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GP502_registers.h"
#endif

#if defined(__dsPIC33EP256GP504__) || (getenv("DEVICE")=="DSPIC33EP256GP504")
    #if !defined(__dsPIC33EP256GP504__)
        #define __dsPIC33EP256GP504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GP504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GP504_registers.h"
#endif

#if defined(__dsPIC33EP256GP506__) || (getenv("DEVICE")=="DSPIC33EP256GP506")
    #if !defined(__dsPIC33EP256GP506__)
        #define __dsPIC33EP256GP506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256GP506.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256GP506_registers.h"
#endif

#if defined(__dsPIC33EP256MC202__) || (getenv("DEVICE")=="DSPIC33EP256MC202")
    #if !defined(__dsPIC33EP256MC202__)
        #define __dsPIC33EP256MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MC202.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MC202_registers.h"
#endif

#if defined(__dsPIC33EP256MC204__) || (getenv("DEVICE")=="DSPIC33EP256MC204")
    #if !defined(__dsPIC33EP256MC204__)
        #define __dsPIC33EP256MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MC204.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MC204_registers.h"
#endif

#if defined(__dsPIC33EP256MC206__) || (getenv("DEVICE")=="DSPIC33EP256MC206")
    #if !defined(__dsPIC33EP256MC206__)
        #define __dsPIC33EP256MC206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MC206.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MC206_registers.h"
#endif

#if defined(__dsPIC33EP256MC502__) || (getenv("DEVICE")=="DSPIC33EP256MC502")
    #if !defined(__dsPIC33EP256MC502__)
        #define __dsPIC33EP256MC502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MC502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MC502_registers.h"
#endif

#if defined(__dsPIC33EP256MC504__) || (getenv("DEVICE")=="DSPIC33EP256MC504")
    #if !defined(__dsPIC33EP256MC504__)
        #define __dsPIC33EP256MC504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MC504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MC504_registers.h"
#endif

#if defined(__dsPIC33EP256MC506__) || (getenv("DEVICE")=="DSPIC33EP256MC506")
    #if !defined(__dsPIC33EP256MC506__)
        #define __dsPIC33EP256MC506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MC506.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MC506_registers.h"
#endif

#if defined(__dsPIC33EP256MU806__) || (getenv("DEVICE")=="DSPIC33EP256MU806")
    #if !defined(__dsPIC33EP256MU806__)
        #define __dsPIC33EP256MU806__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MU806.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MU806_registers.h"
#endif

#if defined(__dsPIC33EP256MU810__) || (getenv("DEVICE")=="DSPIC33EP256MU810")
    #if !defined(__dsPIC33EP256MU810__)
        #define __dsPIC33EP256MU810__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MU810.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MU810_registers.h"
#endif

#if defined(__dsPIC33EP256MU814__) || (getenv("DEVICE")=="DSPIC33EP256MU814")
    #if !defined(__dsPIC33EP256MU814__)
        #define __dsPIC33EP256MU814__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP256MU814.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP256MU814_registers.h"
#endif

#if defined(__dsPIC33EP32GP502__) || (getenv("DEVICE")=="DSPIC33EP32GP502")
    #if !defined(__dsPIC33EP32GP502__)
        #define __dsPIC33EP32GP502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32GP502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32GP502_registers.h"
#endif

#if defined(__dsPIC33EP32GP503__) || (getenv("DEVICE")=="DSPIC33EP32GP503")
    #if !defined(__dsPIC33EP32GP503__)
        #define __dsPIC33EP32GP503__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32GP503.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32GP503_registers.h"
#endif

#if defined(__dsPIC33EP32GP504__) || (getenv("DEVICE")=="DSPIC33EP32GP504")
    #if !defined(__dsPIC33EP32GP504__)
        #define __dsPIC33EP32GP504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32GP504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32GP504_registers.h"
#endif

#if defined(__dsPIC33EP32MC202__) || (getenv("DEVICE")=="DSPIC33EP32MC202")
    #if !defined(__dsPIC33EP32MC202__)
        #define __dsPIC33EP32MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32MC202.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32MC202_registers.h"
#endif

#if defined(__dsPIC33EP32MC203__) || (getenv("DEVICE")=="DSPIC33EP32MC203")
    #if !defined(__dsPIC33EP32MC203__)
        #define __dsPIC33EP32MC203__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32MC203.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32MC203_registers.h"
#endif

#if defined(__dsPIC33EP32MC204__) || (getenv("DEVICE")=="DSPIC33EP32MC204")
    #if !defined(__dsPIC33EP32MC204__)
        #define __dsPIC33EP32MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32MC204.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32MC204_registers.h"
#endif

#if defined(__dsPIC33EP32MC502__) || (getenv("DEVICE")=="DSPIC33EP32MC502")
    #if !defined(__dsPIC33EP32MC502__)
        #define __dsPIC33EP32MC502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32MC502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32MC502_registers.h"
#endif

#if defined(__dsPIC33EP32MC503__) || (getenv("DEVICE")=="DSPIC33EP32MC503")
    #if !defined(__dsPIC33EP32MC503__)
        #define __dsPIC33EP32MC503__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32MC503.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32MC503_registers.h"
#endif

#if defined(__dsPIC33EP32MC504__) || (getenv("DEVICE")=="DSPIC33EP32MC504")
    #if !defined(__dsPIC33EP32MC504__)
        #define __dsPIC33EP32MC504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP32MC504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP32MC504_registers.h"
#endif

#if defined(__dsPIC33EP512GM304__) || (getenv("DEVICE")=="DSPIC33EP512GM304")
    #if !defined(__dsPIC33EP512GM304__)
        #define __dsPIC33EP512GM304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512GM304.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512GM304_registers.h"
#endif

#if defined(__dsPIC33EP512GM306__) || (getenv("DEVICE")=="DSPIC33EP512GM306")
    #if !defined(__dsPIC33EP512GM306__)
        #define __dsPIC33EP512GM306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512GM306.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512GM306_registers.h"
#endif

#if defined(__dsPIC33EP512GM310__) || (getenv("DEVICE")=="DSPIC33EP512GM310")
    #if !defined(__dsPIC33EP512GM310__)
        #define __dsPIC33EP512GM310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512GM310.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512GM310_registers.h"
#endif

#if defined(__dsPIC33EP512GM604__) || (getenv("DEVICE")=="DSPIC33EP512GM604")
    #if !defined(__dsPIC33EP512GM604__)
        #define __dsPIC33EP512GM604__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512GM604.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512GM604_registers.h"
#endif

#if defined(__dsPIC33EP512GM706__) || (getenv("DEVICE")=="DSPIC33EP512GM706")
    #if !defined(__dsPIC33EP512GM706__)
        #define __dsPIC33EP512GM706__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512GM706.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512GM706_registers.h"
#endif

#if defined(__dsPIC33EP512GM710__) || (getenv("DEVICE")=="DSPIC33EP512GM710")
    #if !defined(__dsPIC33EP512GM710__)
        #define __dsPIC33EP512GM710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512GM710.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512GM710_registers.h"
#endif

#if defined(__dsPIC33EP512GP806__) || (getenv("DEVICE")=="DSPIC33EP512GP806")
    #if !defined(__dsPIC33EP512GP806__)
        #define __dsPIC33EP512GP806__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512GP806.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512GP806_registers.h"
#endif

#if defined(__dsPIC33EP512MC806__) || (getenv("DEVICE")=="DSPIC33EP512MC806")
    #if !defined(__dsPIC33EP512MC806__)
        #define __dsPIC33EP512MC806__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512MC806.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512MC806_registers.h"
#endif

#if defined(__dsPIC33EP512MU810__) || (getenv("DEVICE")=="DSPIC33EP512MU810")
    #if !defined(__dsPIC33EP512MU810__)
        #define __dsPIC33EP512MU810__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512MU810.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512MU810_registers.h"
#endif

#if defined(__dsPIC33EP512MU814__) || (getenv("DEVICE")=="DSPIC33EP512MU814")
    #if !defined(__dsPIC33EP512MU814__)
        #define __dsPIC33EP512MU814__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP512MU814.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP512MU814_registers.h"
#endif

#if defined(__dsPIC33EP64GP502__) || (getenv("DEVICE")=="DSPIC33EP64GP502")
    #if !defined(__dsPIC33EP64GP502__)
        #define __dsPIC33EP64GP502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64GP502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64GP502_registers.h"
#endif

#if defined(__dsPIC33EP64GP503__) || (getenv("DEVICE")=="DSPIC33EP64GP503")
    #if !defined(__dsPIC33EP64GP503__)
        #define __dsPIC33EP64GP503__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64GP503.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64GP503_registers.h"
#endif

#if defined(__dsPIC33EP64GP504__) || (getenv("DEVICE")=="DSPIC33EP64GP504")
    #if !defined(__dsPIC33EP64GP504__)
        #define __dsPIC33EP64GP504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64GP504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64GP504_registers.h"
#endif

#if defined(__dsPIC33EP64GP506__) || (getenv("DEVICE")=="DSPIC33EP64GP506")
    #if !defined(__dsPIC33EP64GP506__)
        #define __dsPIC33EP64GP506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64GP506.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64GP506_registers.h"
#endif

#if defined(__dsPIC33EP64MC202__) || (getenv("DEVICE")=="DSPIC33EP64MC202")
    #if !defined(__dsPIC33EP64MC202__)
        #define __dsPIC33EP64MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC202.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC202_registers.h"
#endif

#if defined(__dsPIC33EP64MC203__) || (getenv("DEVICE")=="DSPIC33EP64MC203")
    #if !defined(__dsPIC33EP64MC203__)
        #define __dsPIC33EP64MC203__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC203.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC203_registers.h"
#endif

#if defined(__dsPIC33EP64MC204__) || (getenv("DEVICE")=="DSPIC33EP64MC204")
    #if !defined(__dsPIC33EP64MC204__)
        #define __dsPIC33EP64MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC204.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC204_registers.h"
#endif

#if defined(__dsPIC33EP64MC206__) || (getenv("DEVICE")=="DSPIC33EP64MC206")
    #if !defined(__dsPIC33EP64MC206__)
        #define __dsPIC33EP64MC206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC206.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC206_registers.h"
#endif

#if defined(__dsPIC33EP64MC502__) || (getenv("DEVICE")=="DSPIC33EP64MC502")
    #if !defined(__dsPIC33EP64MC502__)
        #define __dsPIC33EP64MC502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC502.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC502_registers.h"
#endif

#if defined(__dsPIC33EP64MC503__) || (getenv("DEVICE")=="DSPIC33EP64MC503")
    #if !defined(__dsPIC33EP64MC503__)
        #define __dsPIC33EP64MC503__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC503.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC503_registers.h"
#endif

#if defined(__dsPIC33EP64MC504__) || (getenv("DEVICE")=="DSPIC33EP64MC504")
    #if !defined(__dsPIC33EP64MC504__)
        #define __dsPIC33EP64MC504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC504.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC504_registers.h"
#endif

#if defined(__dsPIC33EP64MC506__) || (getenv("DEVICE")=="DSPIC33EP64MC506")
    #if !defined(__dsPIC33EP64MC506__)
        #define __dsPIC33EP64MC506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33EP64MC506.h>
    #endif
    #if !defined(__dsPIC33E__)
        #define __dsPIC33E__
    #endif
    #include "33EP64MC506_registers.h"
#endif

#if defined(__dsPIC33FJ06GS001__) || (getenv("DEVICE")=="DSPIC33FJ06GS001")
    #if !defined(__dsPIC33FJ06GS001__)
        #define __dsPIC33FJ06GS001__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ06GS001.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ06GS001_registers.h"
#endif

#if defined(__dsPIC33FJ06GS101__) || (getenv("DEVICE")=="DSPIC33FJ06GS101")
    #if !defined(__dsPIC33FJ06GS101__)
        #define __dsPIC33FJ06GS101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ06GS101.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ06GS101_registers.h"
#endif

#if defined(__dsPIC33FJ06GS101A__) || (getenv("DEVICE")=="DSPIC33FJ06GS101A")
    #if !defined(__dsPIC33FJ06GS101A__)
        #define __dsPIC33FJ06GS101A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ06GS101A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ06GS101A_registers.h"
#endif

#if defined(__dsPIC33FJ06GS102__) || (getenv("DEVICE")=="DSPIC33FJ06GS102")
    #if !defined(__dsPIC33FJ06GS102__)
        #define __dsPIC33FJ06GS102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ06GS102.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ06GS102_registers.h"
#endif

#if defined(__dsPIC33FJ06GS102A__) || (getenv("DEVICE")=="DSPIC33FJ06GS102A")
    #if !defined(__dsPIC33FJ06GS102A__)
        #define __dsPIC33FJ06GS102A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ06GS102A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ06GS102A_registers.h"
#endif

#if defined(__dsPIC33FJ06GS202__) || (getenv("DEVICE")=="DSPIC33FJ06GS202")
    #if !defined(__dsPIC33FJ06GS202__)
        #define __dsPIC33FJ06GS202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ06GS202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ06GS202_registers.h"
#endif

#if defined(__dsPIC33FJ06GS202A__) || (getenv("DEVICE")=="DSPIC33FJ06GS202A")
    #if !defined(__dsPIC33FJ06GS202A__)
        #define __dsPIC33FJ06GS202A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ06GS202A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ06GS202A_registers.h"
#endif

#if defined(__dsPIC33FJ09GS302__) || (getenv("DEVICE")=="DSPIC33FJ09GS302")
    #if !defined(__dsPIC33FJ09GS302__)
        #define __dsPIC33FJ09GS302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ09GS302.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ09GS302_registers.h"
#endif

#if defined(__dsPIC33FJ128GP202__) || (getenv("DEVICE")=="DSPIC33FJ128GP202")
    #if !defined(__dsPIC33FJ128GP202__)
        #define __dsPIC33FJ128GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP202_registers.h"
#endif

#if defined(__dsPIC33FJ128GP204__) || (getenv("DEVICE")=="DSPIC33FJ128GP204")
    #if !defined(__dsPIC33FJ128GP204__)
        #define __dsPIC33FJ128GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP204.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP204_registers.h"
#endif

#if defined(__dsPIC33FJ128GP206__) || (getenv("DEVICE")=="DSPIC33FJ128GP206")
    #if !defined(__dsPIC33FJ128GP206__)
        #define __dsPIC33FJ128GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP206.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP206_registers.h"
#endif

#if defined(__dsPIC33FJ128GP206A__) || (getenv("DEVICE")=="DSPIC33FJ128GP206A")
    #if !defined(__dsPIC33FJ128GP206A__)
        #define __dsPIC33FJ128GP206A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP206A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP206A_registers.h"
#endif

#if defined(__dsPIC33FJ128GP306__) || (getenv("DEVICE")=="DSPIC33FJ128GP306")
    #if !defined(__dsPIC33FJ128GP306__)
        #define __dsPIC33FJ128GP306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP306.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP306_registers.h"
#endif

#if defined(__dsPIC33FJ128GP306A__) || (getenv("DEVICE")=="DSPIC33FJ128GP306A")
    #if !defined(__dsPIC33FJ128GP306A__)
        #define __dsPIC33FJ128GP306A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP306A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP306A_registers.h"
#endif

#if defined(__dsPIC33FJ128GP310__) || (getenv("DEVICE")=="DSPIC33FJ128GP310")
    #if !defined(__dsPIC33FJ128GP310__)
        #define __dsPIC33FJ128GP310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP310.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP310_registers.h"
#endif

#if defined(__dsPIC33FJ128GP310A__) || (getenv("DEVICE")=="DSPIC33FJ128GP310A")
    #if !defined(__dsPIC33FJ128GP310A__)
        #define __dsPIC33FJ128GP310A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP310A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP310A_registers.h"
#endif

#if defined(__dsPIC33FJ128GP706__) || (getenv("DEVICE")=="DSPIC33FJ128GP706")
    #if !defined(__dsPIC33FJ128GP706__)
        #define __dsPIC33FJ128GP706__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP706.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP706_registers.h"
#endif

#if defined(__dsPIC33FJ128GP706A__) || (getenv("DEVICE")=="DSPIC33FJ128GP706A")
    #if !defined(__dsPIC33FJ128GP706A__)
        #define __dsPIC33FJ128GP706A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP706A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP706A_registers.h"
#endif

#if defined(__dsPIC33FJ128GP708__) || (getenv("DEVICE")=="DSPIC33FJ128GP708")
    #if !defined(__dsPIC33FJ128GP708__)
        #define __dsPIC33FJ128GP708__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP708.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP708_registers.h"
#endif

#if defined(__dsPIC33FJ128GP708A__) || (getenv("DEVICE")=="DSPIC33FJ128GP708A")
    #if !defined(__dsPIC33FJ128GP708A__)
        #define __dsPIC33FJ128GP708A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP708A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP708A_registers.h"
#endif

#if defined(__dsPIC33FJ128GP710__) || (getenv("DEVICE")=="DSPIC33FJ128GP710")
    #if !defined(__dsPIC33FJ128GP710__)
        #define __dsPIC33FJ128GP710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP710.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP710_registers.h"
#endif

#if defined(__dsPIC33FJ128GP710A__) || (getenv("DEVICE")=="DSPIC33FJ128GP710A")
    #if !defined(__dsPIC33FJ128GP710A__)
        #define __dsPIC33FJ128GP710A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP710A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP710A_registers.h"
#endif

#if defined(__dsPIC33FJ128GP802__) || (getenv("DEVICE")=="DSPIC33FJ128GP802")
    #if !defined(__dsPIC33FJ128GP802__)
        #define __dsPIC33FJ128GP802__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP802.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP802_registers.h"
#endif

#if defined(__dsPIC33FJ128GP804__) || (getenv("DEVICE")=="DSPIC33FJ128GP804")
    #if !defined(__dsPIC33FJ128GP804__)
        #define __dsPIC33FJ128GP804__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128GP804.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128GP804_registers.h"
#endif

#if defined(__dsPIC33FJ128MC202__) || (getenv("DEVICE")=="DSPIC33FJ128MC202")
    #if !defined(__dsPIC33FJ128MC202__)
        #define __dsPIC33FJ128MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC202_registers.h"
#endif

#if defined(__dsPIC33FJ128MC204__) || (getenv("DEVICE")=="DSPIC33FJ128MC204")
    #if !defined(__dsPIC33FJ128MC204__)
        #define __dsPIC33FJ128MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC204.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC204_registers.h"
#endif

#if defined(__dsPIC33FJ128MC506__) || (getenv("DEVICE")=="DSPIC33FJ128MC506")
    #if !defined(__dsPIC33FJ128MC506__)
        #define __dsPIC33FJ128MC506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC506.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC506_registers.h"
#endif

#if defined(__dsPIC33FJ128MC506A__) || (getenv("DEVICE")=="DSPIC33FJ128MC506A")
    #if !defined(__dsPIC33FJ128MC506A__)
        #define __dsPIC33FJ128MC506A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC506A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC506A_registers.h"
#endif

#if defined(__dsPIC33FJ128MC510__) || (getenv("DEVICE")=="DSPIC33FJ128MC510")
    #if !defined(__dsPIC33FJ128MC510__)
        #define __dsPIC33FJ128MC510__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC510.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC510_registers.h"
#endif

#if defined(__dsPIC33FJ128MC510A__) || (getenv("DEVICE")=="DSPIC33FJ128MC510A")
    #if !defined(__dsPIC33FJ128MC510A__)
        #define __dsPIC33FJ128MC510A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC510A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC510A_registers.h"
#endif

#if defined(__dsPIC33FJ128MC706__) || (getenv("DEVICE")=="DSPIC33FJ128MC706")
    #if !defined(__dsPIC33FJ128MC706__)
        #define __dsPIC33FJ128MC706__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC706.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC706_registers.h"
#endif

#if defined(__dsPIC33FJ128MC706A__) || (getenv("DEVICE")=="DSPIC33FJ128MC706A")
    #if !defined(__dsPIC33FJ128MC706A__)
        #define __dsPIC33FJ128MC706A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC706A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC706A_registers.h"
#endif

#if defined(__dsPIC33FJ128MC708__) || (getenv("DEVICE")=="DSPIC33FJ128MC708")
    #if !defined(__dsPIC33FJ128MC708__)
        #define __dsPIC33FJ128MC708__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC708.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC708_registers.h"
#endif

#if defined(__dsPIC33FJ128MC708A__) || (getenv("DEVICE")=="DSPIC33FJ128MC708A")
    #if !defined(__dsPIC33FJ128MC708A__)
        #define __dsPIC33FJ128MC708A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC708A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC708A_registers.h"
#endif

#if defined(__dsPIC33FJ128MC710__) || (getenv("DEVICE")=="DSPIC33FJ128MC710")
    #if !defined(__dsPIC33FJ128MC710__)
        #define __dsPIC33FJ128MC710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC710.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC710_registers.h"
#endif

#if defined(__dsPIC33FJ128MC710A__) || (getenv("DEVICE")=="DSPIC33FJ128MC710A")
    #if !defined(__dsPIC33FJ128MC710A__)
        #define __dsPIC33FJ128MC710A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC710A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC710A_registers.h"
#endif

#if defined(__dsPIC33FJ128MC802__) || (getenv("DEVICE")=="DSPIC33FJ128MC802")
    #if !defined(__dsPIC33FJ128MC802__)
        #define __dsPIC33FJ128MC802__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC802.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC802_registers.h"
#endif

#if defined(__dsPIC33FJ128MC804__) || (getenv("DEVICE")=="DSPIC33FJ128MC804")
    #if !defined(__dsPIC33FJ128MC804__)
        #define __dsPIC33FJ128MC804__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ128MC804.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ128MC804_registers.h"
#endif

#if defined(__dsPIC33FJ12GP201__) || (getenv("DEVICE")=="DSPIC33FJ12GP201")
    #if !defined(__dsPIC33FJ12GP201__)
        #define __dsPIC33FJ12GP201__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ12GP201.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ12GP201_registers.h"
#endif

#if defined(__dsPIC33FJ12GP202__) || (getenv("DEVICE")=="DSPIC33FJ12GP202")
    #if !defined(__dsPIC33FJ12GP202__)
        #define __dsPIC33FJ12GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ12GP202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ12GP202_registers.h"
#endif

#if defined(__dsPIC33FJ12MC201__) || (getenv("DEVICE")=="DSPIC33FJ12MC201")
    #if !defined(__dsPIC33FJ12MC201__)
        #define __dsPIC33FJ12MC201__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ12MC201.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ12MC201_registers.h"
#endif

#if defined(__dsPIC33FJ12MC202__) || (getenv("DEVICE")=="DSPIC33FJ12MC202")
    #if !defined(__dsPIC33FJ12MC202__)
        #define __dsPIC33FJ12MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ12MC202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ12MC202_registers.h"
#endif

#if defined(__dsPIC33FJ16GP101__) || (getenv("DEVICE")=="DSPIC33FJ16GP101")
    #if !defined(__dsPIC33FJ16GP101__)
        #define __dsPIC33FJ16GP101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16GP101.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16GP101_registers.h"
#endif

#if defined(__dsPIC33FJ16GP102__) || (getenv("DEVICE")=="DSPIC33FJ16GP102")
    #if !defined(__dsPIC33FJ16GP102__)
        #define __dsPIC33FJ16GP102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16GP102.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16GP102_registers.h"
#endif

#if defined(__dsPIC33FJ16GP304__) || (getenv("DEVICE")=="DSPIC33FJ16GP304")
    #if !defined(__dsPIC33FJ16GP304__)
        #define __dsPIC33FJ16GP304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16GP304.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16GP304_registers.h"
#endif

#if defined(__dsPIC33FJ16GS402__) || (getenv("DEVICE")=="DSPIC33FJ16GS402")
    #if !defined(__dsPIC33FJ16GS402__)
        #define __dsPIC33FJ16GS402__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16GS402.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16GS402_registers.h"
#endif

#if defined(__dsPIC33FJ16GS404__) || (getenv("DEVICE")=="DSPIC33FJ16GS404")
    #if !defined(__dsPIC33FJ16GS404__)
        #define __dsPIC33FJ16GS404__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16GS404.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16GS404_registers.h"
#endif

#if defined(__dsPIC33FJ16GS502__) || (getenv("DEVICE")=="DSPIC33FJ16GS502")
    #if !defined(__dsPIC33FJ16GS502__)
        #define __dsPIC33FJ16GS502__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16GS502.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16GS502_registers.h"
#endif

#if defined(__dsPIC33FJ16GS504__) || (getenv("DEVICE")=="DSPIC33FJ16GS504")
    #if !defined(__dsPIC33FJ16GS504__)
        #define __dsPIC33FJ16GS504__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16GS504.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16GS504_registers.h"
#endif

#if defined(__dsPIC33FJ16MC101__) || (getenv("DEVICE")=="DSPIC33FJ16MC101")
    #if !defined(__dsPIC33FJ16MC101__)
        #define __dsPIC33FJ16MC101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16MC101.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16MC101_registers.h"
#endif

#if defined(__dsPIC33FJ16MC102__) || (getenv("DEVICE")=="DSPIC33FJ16MC102")
    #if !defined(__dsPIC33FJ16MC102__)
        #define __dsPIC33FJ16MC102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16MC102.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16MC102_registers.h"
#endif

#if defined(__dsPIC33FJ16MC304__) || (getenv("DEVICE")=="DSPIC33FJ16MC304")
    #if !defined(__dsPIC33FJ16MC304__)
        #define __dsPIC33FJ16MC304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ16MC304.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ16MC304_registers.h"
#endif

#if defined(__dsPIC33FJ256GP506__) || (getenv("DEVICE")=="DSPIC33FJ256GP506")
    #if !defined(__dsPIC33FJ256GP506__)
        #define __dsPIC33FJ256GP506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256GP506.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256GP506_registers.h"
#endif

#if defined(__dsPIC33FJ256GP506A__) || (getenv("DEVICE")=="DSPIC33FJ256GP506A")
    #if !defined(__dsPIC33FJ256GP506A__)
        #define __dsPIC33FJ256GP506A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256GP506A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256GP506A_registers.h"
#endif

#if defined(__dsPIC33FJ256GP510__) || (getenv("DEVICE")=="DSPIC33FJ256GP510")
    #if !defined(__dsPIC33FJ256GP510__)
        #define __dsPIC33FJ256GP510__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256GP510.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256GP510_registers.h"
#endif

#if defined(__dsPIC33FJ256GP510A__) || (getenv("DEVICE")=="DSPIC33FJ256GP510A")
    #if !defined(__dsPIC33FJ256GP510A__)
        #define __dsPIC33FJ256GP510A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256GP510A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256GP510A_registers.h"
#endif

#if defined(__dsPIC33FJ256GP710__) || (getenv("DEVICE")=="DSPIC33FJ256GP710")
    #if !defined(__dsPIC33FJ256GP710__)
        #define __dsPIC33FJ256GP710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256GP710.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256GP710_registers.h"
#endif

#if defined(__dsPIC33FJ256GP710A__) || (getenv("DEVICE")=="DSPIC33FJ256GP710A")
    #if !defined(__dsPIC33FJ256GP710A__)
        #define __dsPIC33FJ256GP710A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256GP710A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256GP710A_registers.h"
#endif

#if defined(__dsPIC33FJ256MC510__) || (getenv("DEVICE")=="DSPIC33FJ256MC510")
    #if !defined(__dsPIC33FJ256MC510__)
        #define __dsPIC33FJ256MC510__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256MC510.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256MC510_registers.h"
#endif

#if defined(__dsPIC33FJ256MC510A__) || (getenv("DEVICE")=="DSPIC33FJ256MC510A")
    #if !defined(__dsPIC33FJ256MC510A__)
        #define __dsPIC33FJ256MC510A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256MC510A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256MC510A_registers.h"
#endif

#if defined(__dsPIC33FJ256MC710__) || (getenv("DEVICE")=="DSPIC33FJ256MC710")
    #if !defined(__dsPIC33FJ256MC710__)
        #define __dsPIC33FJ256MC710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256MC710.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256MC710_registers.h"
#endif

#if defined(__dsPIC33FJ256MC710A__) || (getenv("DEVICE")=="DSPIC33FJ256MC710A")
    #if !defined(__dsPIC33FJ256MC710A__)
        #define __dsPIC33FJ256MC710A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ256MC710A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ256MC710A_registers.h"
#endif

#if defined(__dsPIC33FJ32GP101__) || (getenv("DEVICE")=="DSPIC33FJ32GP101")
    #if !defined(__dsPIC33FJ32GP101__)
        #define __dsPIC33FJ32GP101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GP101.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GP101_registers.h"
#endif

#if defined(__dsPIC33FJ32GP102__) || (getenv("DEVICE")=="DSPIC33FJ32GP102")
    #if !defined(__dsPIC33FJ32GP102__)
        #define __dsPIC33FJ32GP102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GP102.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GP102_registers.h"
#endif

#if defined(__dsPIC33FJ32GP104__) || (getenv("DEVICE")=="DSPIC33FJ32GP104")
    #if !defined(__dsPIC33FJ32GP104__)
        #define __dsPIC33FJ32GP104__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GP104.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GP104_registers.h"
#endif

#if defined(__dsPIC33FJ32GP202__) || (getenv("DEVICE")=="DSPIC33FJ32GP202")
    #if !defined(__dsPIC33FJ32GP202__)
        #define __dsPIC33FJ32GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GP202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GP202_registers.h"
#endif

#if defined(__dsPIC33FJ32GP204__) || (getenv("DEVICE")=="DSPIC33FJ32GP204")
    #if !defined(__dsPIC33FJ32GP204__)
        #define __dsPIC33FJ32GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GP204.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GP204_registers.h"
#endif

#if defined(__dsPIC33FJ32GP302__) || (getenv("DEVICE")=="DSPIC33FJ32GP302")
    #if !defined(__dsPIC33FJ32GP302__)
        #define __dsPIC33FJ32GP302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GP302.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GP302_registers.h"
#endif

#if defined(__dsPIC33FJ32GP304__) || (getenv("DEVICE")=="DSPIC33FJ32GP304")
    #if !defined(__dsPIC33FJ32GP304__)
        #define __dsPIC33FJ32GP304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GP304.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GP304_registers.h"
#endif

#if defined(__dsPIC33FJ32GS406__) || (getenv("DEVICE")=="DSPIC33FJ32GS406")
    #if !defined(__dsPIC33FJ32GS406__)
        #define __dsPIC33FJ32GS406__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GS406.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GS406_registers.h"
#endif

#if defined(__dsPIC33FJ32GS606__) || (getenv("DEVICE")=="DSPIC33FJ32GS606")
    #if !defined(__dsPIC33FJ32GS606__)
        #define __dsPIC33FJ32GS606__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GS606.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GS606_registers.h"
#endif

#if defined(__dsPIC33FJ32GS608__) || (getenv("DEVICE")=="DSPIC33FJ32GS608")
    #if !defined(__dsPIC33FJ32GS608__)
        #define __dsPIC33FJ32GS608__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GS608.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GS608_registers.h"
#endif

#if defined(__dsPIC33FJ32GS610__) || (getenv("DEVICE")=="DSPIC33FJ32GS610")
    #if !defined(__dsPIC33FJ32GS610__)
        #define __dsPIC33FJ32GS610__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32GS610.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32GS610_registers.h"
#endif

#if defined(__dsPIC33FJ32MC101__) || (getenv("DEVICE")=="DSPIC33FJ32MC101")
    #if !defined(__dsPIC33FJ32MC101__)
        #define __dsPIC33FJ32MC101__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32MC101.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32MC101_registers.h"
#endif

#if defined(__dsPIC33FJ32MC102__) || (getenv("DEVICE")=="DSPIC33FJ32MC102")
    #if !defined(__dsPIC33FJ32MC102__)
        #define __dsPIC33FJ32MC102__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32MC102.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32MC102_registers.h"
#endif

#if defined(__dsPIC33FJ32MC104__) || (getenv("DEVICE")=="DSPIC33FJ32MC104")
    #if !defined(__dsPIC33FJ32MC104__)
        #define __dsPIC33FJ32MC104__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32MC104.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32MC104_registers.h"
#endif

#if defined(__dsPIC33FJ32MC202__) || (getenv("DEVICE")=="DSPIC33FJ32MC202")
    #if !defined(__dsPIC33FJ32MC202__)
        #define __dsPIC33FJ32MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32MC202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32MC202_registers.h"
#endif

#if defined(__dsPIC33FJ32MC204__) || (getenv("DEVICE")=="DSPIC33FJ32MC204")
    #if !defined(__dsPIC33FJ32MC204__)
        #define __dsPIC33FJ32MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32MC204.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32MC204_registers.h"
#endif

#if defined(__dsPIC33FJ32MC302__) || (getenv("DEVICE")=="DSPIC33FJ32MC302")
    #if !defined(__dsPIC33FJ32MC302__)
        #define __dsPIC33FJ32MC302__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32MC302.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32MC302_registers.h"
#endif

#if defined(__dsPIC33FJ32MC304__) || (getenv("DEVICE")=="DSPIC33FJ32MC304")
    #if !defined(__dsPIC33FJ32MC304__)
        #define __dsPIC33FJ32MC304__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ32MC304.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ32MC304_registers.h"
#endif

#if defined(__dsPIC33FJ64GP202__) || (getenv("DEVICE")=="DSPIC33FJ64GP202")
    #if !defined(__dsPIC33FJ64GP202__)
        #define __dsPIC33FJ64GP202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP202_registers.h"
#endif

#if defined(__dsPIC33FJ64GP204__) || (getenv("DEVICE")=="DSPIC33FJ64GP204")
    #if !defined(__dsPIC33FJ64GP204__)
        #define __dsPIC33FJ64GP204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP204.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP204_registers.h"
#endif

#if defined(__dsPIC33FJ64GP206__) || (getenv("DEVICE")=="DSPIC33FJ64GP206")
    #if !defined(__dsPIC33FJ64GP206__)
        #define __dsPIC33FJ64GP206__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP206.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP206_registers.h"
#endif

#if defined(__dsPIC33FJ64GP206A__) || (getenv("DEVICE")=="DSPIC33FJ64GP206A")
    #if !defined(__dsPIC33FJ64GP206A__)
        #define __dsPIC33FJ64GP206A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP206A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP206A_registers.h"
#endif

#if defined(__dsPIC33FJ64GP306__) || (getenv("DEVICE")=="DSPIC33FJ64GP306")
    #if !defined(__dsPIC33FJ64GP306__)
        #define __dsPIC33FJ64GP306__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP306.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP306_registers.h"
#endif

#if defined(__dsPIC33FJ64GP306A__) || (getenv("DEVICE")=="DSPIC33FJ64GP306A")
    #if !defined(__dsPIC33FJ64GP306A__)
        #define __dsPIC33FJ64GP306A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP306A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP306A_registers.h"
#endif

#if defined(__dsPIC33FJ64GP310__) || (getenv("DEVICE")=="DSPIC33FJ64GP310")
    #if !defined(__dsPIC33FJ64GP310__)
        #define __dsPIC33FJ64GP310__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP310.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP310_registers.h"
#endif

#if defined(__dsPIC33FJ64GP310A__) || (getenv("DEVICE")=="DSPIC33FJ64GP310A")
    #if !defined(__dsPIC33FJ64GP310A__)
        #define __dsPIC33FJ64GP310A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP310A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP310A_registers.h"
#endif

#if defined(__dsPIC33FJ64GP706__) || (getenv("DEVICE")=="DSPIC33FJ64GP706")
    #if !defined(__dsPIC33FJ64GP706__)
        #define __dsPIC33FJ64GP706__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP706.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP706_registers.h"
#endif

#if defined(__dsPIC33FJ64GP706A__) || (getenv("DEVICE")=="DSPIC33FJ64GP706A")
    #if !defined(__dsPIC33FJ64GP706A__)
        #define __dsPIC33FJ64GP706A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP706A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP706A_registers.h"
#endif

#if defined(__dsPIC33FJ64GP708__) || (getenv("DEVICE")=="DSPIC33FJ64GP708")
    #if !defined(__dsPIC33FJ64GP708__)
        #define __dsPIC33FJ64GP708__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP708.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP708_registers.h"
#endif

#if defined(__dsPIC33FJ64GP708A__) || (getenv("DEVICE")=="DSPIC33FJ64GP708A")
    #if !defined(__dsPIC33FJ64GP708A__)
        #define __dsPIC33FJ64GP708A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP708A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP708A_registers.h"
#endif

#if defined(__dsPIC33FJ64GP710__) || (getenv("DEVICE")=="DSPIC33FJ64GP710")
    #if !defined(__dsPIC33FJ64GP710__)
        #define __dsPIC33FJ64GP710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP710.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP710_registers.h"
#endif

#if defined(__dsPIC33FJ64GP710A__) || (getenv("DEVICE")=="DSPIC33FJ64GP710A")
    #if !defined(__dsPIC33FJ64GP710A__)
        #define __dsPIC33FJ64GP710A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP710A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP710A_registers.h"
#endif

#if defined(__dsPIC33FJ64GP802__) || (getenv("DEVICE")=="DSPIC33FJ64GP802")
    #if !defined(__dsPIC33FJ64GP802__)
        #define __dsPIC33FJ64GP802__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP802.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP802_registers.h"
#endif

#if defined(__dsPIC33FJ64GP804__) || (getenv("DEVICE")=="DSPIC33FJ64GP804")
    #if !defined(__dsPIC33FJ64GP804__)
        #define __dsPIC33FJ64GP804__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GP804.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GP804_registers.h"
#endif

#if defined(__dsPIC33FJ64GS406__) || (getenv("DEVICE")=="DSPIC33FJ64GS406")
    #if !defined(__dsPIC33FJ64GS406__)
        #define __dsPIC33FJ64GS406__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GS406.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GS406_registers.h"
#endif

#if defined(__dsPIC33FJ64GS606__) || (getenv("DEVICE")=="DSPIC33FJ64GS606")
    #if !defined(__dsPIC33FJ64GS606__)
        #define __dsPIC33FJ64GS606__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GS606.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GS606_registers.h"
#endif

#if defined(__dsPIC33FJ64GS608__) || (getenv("DEVICE")=="DSPIC33FJ64GS608")
    #if !defined(__dsPIC33FJ64GS608__)
        #define __dsPIC33FJ64GS608__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GS608.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GS608_registers.h"
#endif

#if defined(__dsPIC33FJ64GS610__) || (getenv("DEVICE")=="DSPIC33FJ64GS610")
    #if !defined(__dsPIC33FJ64GS610__)
        #define __dsPIC33FJ64GS610__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64GS610.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64GS610_registers.h"
#endif

#if defined(__dsPIC33FJ64MC202__) || (getenv("DEVICE")=="DSPIC33FJ64MC202")
    #if !defined(__dsPIC33FJ64MC202__)
        #define __dsPIC33FJ64MC202__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC202.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC202_registers.h"
#endif

#if defined(__dsPIC33FJ64MC204__) || (getenv("DEVICE")=="DSPIC33FJ64MC204")
    #if !defined(__dsPIC33FJ64MC204__)
        #define __dsPIC33FJ64MC204__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC204.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC204_registers.h"
#endif

#if defined(__dsPIC33FJ64MC506__) || (getenv("DEVICE")=="DSPIC33FJ64MC506")
    #if !defined(__dsPIC33FJ64MC506__)
        #define __dsPIC33FJ64MC506__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC506.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC506_registers.h"
#endif

#if defined(__dsPIC33FJ64MC506A__) || (getenv("DEVICE")=="DSPIC33FJ64MC506A")
    #if !defined(__dsPIC33FJ64MC506A__)
        #define __dsPIC33FJ64MC506A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC506A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC506A_registers.h"
#endif

#if defined(__dsPIC33FJ64MC508__) || (getenv("DEVICE")=="DSPIC33FJ64MC508")
    #if !defined(__dsPIC33FJ64MC508__)
        #define __dsPIC33FJ64MC508__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC508.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC508_registers.h"
#endif

#if defined(__dsPIC33FJ64MC508A__) || (getenv("DEVICE")=="DSPIC33FJ64MC508A")
    #if !defined(__dsPIC33FJ64MC508A__)
        #define __dsPIC33FJ64MC508A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC508A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC508A_registers.h"
#endif

#if defined(__dsPIC33FJ64MC510__) || (getenv("DEVICE")=="DSPIC33FJ64MC510")
    #if !defined(__dsPIC33FJ64MC510__)
        #define __dsPIC33FJ64MC510__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC510.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC510_registers.h"
#endif

#if defined(__dsPIC33FJ64MC510A__) || (getenv("DEVICE")=="DSPIC33FJ64MC510A")
    #if !defined(__dsPIC33FJ64MC510A__)
        #define __dsPIC33FJ64MC510A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC510A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC510A_registers.h"
#endif

#if defined(__dsPIC33FJ64MC706__) || (getenv("DEVICE")=="DSPIC33FJ64MC706")
    #if !defined(__dsPIC33FJ64MC706__)
        #define __dsPIC33FJ64MC706__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC706.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC706_registers.h"
#endif

#if defined(__dsPIC33FJ64MC706A__) || (getenv("DEVICE")=="DSPIC33FJ64MC706A")
    #if !defined(__dsPIC33FJ64MC706A__)
        #define __dsPIC33FJ64MC706A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC706A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC706A_registers.h"
#endif

#if defined(__dsPIC33FJ64MC710__) || (getenv("DEVICE")=="DSPIC33FJ64MC710")
    #if !defined(__dsPIC33FJ64MC710__)
        #define __dsPIC33FJ64MC710__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC710.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC710_registers.h"
#endif

#if defined(__dsPIC33FJ64MC710A__) || (getenv("DEVICE")=="DSPIC33FJ64MC710A")
    #if !defined(__dsPIC33FJ64MC710A__)
        #define __dsPIC33FJ64MC710A__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC710A.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC710A_registers.h"
#endif

#if defined(__dsPIC33FJ64MC802__) || (getenv("DEVICE")=="DSPIC33FJ64MC802")
    #if !defined(__dsPIC33FJ64MC802__)
        #define __dsPIC33FJ64MC802__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC802.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC802_registers.h"
#endif

#if defined(__dsPIC33FJ64MC804__) || (getenv("DEVICE")=="DSPIC33FJ64MC804")
    #if !defined(__dsPIC33FJ64MC804__)
        #define __dsPIC33FJ64MC804__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <33FJ64MC804.h>
    #endif
    #if !defined(__dsPIC33F__)
        #define __dsPIC33F__
    #endif
    #include "33FJ64MC804_registers.h"
#endif

#if defined(__dsPIC81010__) || (getenv("DEVICE")=="DSPIC81010")
    #if !defined(__dsPIC81010__)
        #define __dsPIC81010__
    #endif
    #if !defined(INTR_GLOBAL)
        #include <81010.h>
    #endif
    #if !defined(__dsPIC810100__)
        #define __dsPIC810100__
    #endif
    #include "81010_registers.h"
#endif


#endif
