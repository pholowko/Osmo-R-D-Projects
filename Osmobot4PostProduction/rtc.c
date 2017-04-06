//RTC variables 
#define XTAL_FREQUENCY  32000000 
#define TIMER1_FREQUENCY (XTAL_FREQUENCY / 4)      // 1 clock tick = 1 instr. cycle = crystal frequency / 4 
int32 Ticker; 




//////////////////////////////////////////////////////////////////////////////// 
// Test whether a given year is a leap year. 
// This optimized version only works for the period 1901 - 2099 
//////////////////////////////////////////////////////////////////////////////// 
#define IS_LEAP(year) (year%4 == 0) 

//optional: 
// int8 Year=11, Month=1, Days=1, Hours=0, Minutes=0;  // 2011-01-01 00:00 

//////////////////////////////////////////////////////////////////////////////// 
//    Initialize RTC 
//////////////////////////////////////////////////////////////////////////////// 
void Initialize_RTC(void) 
{ 
  Ticker = TIMER1_FREQUENCY;                  // initialize clock counter to number of clocks per second 
  setup_timer1( TMR_INTERNAL | TMR_DIV_BY_1 ); // initialize 16-bit Timer1 to interrupt 
                                              // exactly every 65536 clock cycles 
                                              // (about 76 times per second) 
//  enable_interrupts( INT_TIMER1 );            // Start RTC 
} 




//////////////////////////////////////////////////////////////////////////////// 
//  -=Process Zero Drift Real Time Clock Information=- 
// 
// Most algorithms configure the timer to generate an interrupt every 100ms, and 
// then count the number of interrupts. The problem in that approach is that most 
// clock frequencies can't be divided by 256 and you don't get an exact 100ms. 
// The small errors will add up to an error of several seconds a day. 
// 
// The algorithm presented here is exact in the long run because it doesn't 
// count the number of interrupts but counts the number of clock cycles. 
//////////////////////////////////////////////////////////////////////////////// 
#int_TIMER1                                
void TIMER1_isr()                          
{ 
  Ticker -= 65536;                        // Decrement ticker by clocks per interrupt 
  if ( Ticker < 65536 )                   // If second has expired 
  {  Ticker += TIMER1_FREQUENCY;          //   Increment ticker by clocks per second 
     Seconds++;                           //   Increment number of seconds 
  } 

//  --- Optional part start --- 
  if (Seconds == 60) {Minutes++; Seconds=0; 
    if (Minutes == 60) {Hours++; Minutes=0; 
      if (Hours == 24) {Days++; Hours=0; 
        if (  (Days == 29 && Month==2 && !IS_LEAP(Year))                        // February in leap year 
           || (Days == 30 && Month==2)                                          // February in normal years 
           || (Days == 31 && (Month==4 || Month==6 || Month==9 || Month==11 ))  // All months with 30 days 
           || (Days == 32)                                                      // All months with 31 days 
           ) {Month++; Days=1;} 
        if (Month == 13) {Year++; Month=1;} 
  }}} 
 //  --- Optional part end ---  
} 
