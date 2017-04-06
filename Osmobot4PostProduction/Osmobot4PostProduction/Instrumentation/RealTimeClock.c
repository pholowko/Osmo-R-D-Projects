//RTC variables 
//***********************************************************
//Added July 12, 2012
//This routine is a zero slip Real Time Clock.  It is used
// as the main clock for the entire system.  It sends the data out
// to all of the other modules for timing and time stamping.
//It is kept here becuase the defroster uses the information and this
// CPU is not loaded down too much.
//************************************************************
#define XTAL_FREQUENCY  41000000 
#define TIMER1_FREQUENCY (XTAL_FREQUENCY / 4)      // 1 clock tick = 1 instr. cycle = crystal frequency / 4 



//////////////////////////////////////////////////////////////////////////////// 
// Test whether a given year is a leap year. 
// This optimized version only works for the period 1901 - 2099 
//////////////////////////////////////////////////////////////////////////////// 
#define IS_LEAP(year) (year%4 == 0) 


//********************************************************************
//Added July 12, 2012
// This is the init of the Real Time Clock. It sets up the timer and the interupts for counting.
//********************************************************************
void Initialize_RTC(void) 
{ 
  Ticker = TIMER1_FREQUENCY;                  // initialize clock counter to number of clocks per second 
  setup_timer_1( T1_INTERNAL | T1_DIV_BY_1 ); // initialize 16-bit Timer1 to interrupt 
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
     sysOutput.second++; //   Increment number of seconds 
	 LinearTimeSeconds++;		 //   Increment number of seconds.  This is used for timing intervals
                          
  } 

  if (sysOutput.second == 60) {sysOutput.minute++; sysOutput.second=0; 
    if (sysOutput.minute == 60) {sysOutput.hour++; sysOutput.minute=0; 
      if (sysOutput.hour == 24) {sysOutput.day++; sysOutput.hour=0; 
        if (  (sysOutput.day == 29 && sysOutput.month==2 && !IS_LEAP(sysOutput.year))                        // February in leap year 
           || (sysOutput.day == 30 && sysOutput.month==2)                                          // February in normal years 
           || (sysOutput.day == 31 && (sysOutput.month==4 ||sysOutput.month==6 || sysOutput.month==9 || sysOutput.month==11 ))  // All months with 30 days 
           || (sysOutput.day == 32)                                                      // All months with 31 days 
           ) {sysOutput.month++; sysOutput.day=1;} 
        if (sysOutput.month == 13) {sysOutput.year++; sysOutput.month=1;} 
  }}} 
} 



//****************************************************************************
// Created April 16, 2013
// This routine returns a 1 if the time interval is reached.  A 0 if it is not.
// The variable "LinearTimeSeconds" is kicked up one number each time a second passes buy.
// It keeps track of time regardless of long processes running in the background.  It may appear to 
// skip a few numbers each time, but it keeps it on track.
// The input to the funtion is the interval wanting to reach.
// Once the interval is reached, varialbe "LinearTimeSeconds" is set to zero.
//****************************************************************************
int TimeEvent(int32 TimeInterval)
	{
	if (TimeInterval < LinearTimeSeconds)
		{
		LinearTimeSeconds = 0;  //reset the time interval.  
		return(1);   // Return a signal where the event is triggered.
		}
	return(0);  //If it is not time, it returns a zero where the event is not run.
	}


//****************************************************************************
// Created May 21, 2014
// Take the current time and add what the next minutes be for trigging uploading.
//  Program returns the new minutes.
//****************************************************************************
int FindNextTime(int timeinterval)
	{	
	return((sysOutput.minute + timeinterval)%60);  //Do a modulas 60 for the minutest.
	}