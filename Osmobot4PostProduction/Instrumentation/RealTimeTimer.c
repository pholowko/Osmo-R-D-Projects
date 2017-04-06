#define XTAL_FREQUENCY  25000000 
#define TIMER1_FREQUENCY (XTAL_FREQUENCY / 4)      // 1 clock tick = 1 instr. cycle = crystal frequency / 4 

//#define INCVAL 65536
#define INCVAL 32768


//Function used to initialize the Timer
void Initialize_RTT(void) 
{ 
  R_Ticker = TIMER1_FREQUENCY;                  // initialize clock counter to number of clocks per second 
  setup_timer_3( T3_DIV_BY_1 | T3_INTERNAL); // initialize 16-bit Timer2 to interrupt 
                                              // exactly every 65536 clock cycles 
                                              // (about 76 times per second) 
  enable_interrupts( INT_TIMER3 );            // Start RTC 
}

//ISR routinte for timer
#int_TIMER3                                
void TIMER3_isr()                          
{ 
  R_Ticker -=  INCVAL;                        // Decrement ticker by clocks per interrupt 
  if ( R_Ticker < INCVAL){
	R_Seconds++;
    R_Ticker = TIMER1_FREQUENCY;
	}
  if ( R_Seconds >= 60 ){
	R_Seconds=0;
	R_Minutes++;

	}
}
//Checks if timer has reached setTime then resets timer
int1 reachedTimeMins(unsigned int8 setTime)
{
  if(R_Minutes>=setTime){
	R_Seconds=0;
	R_Minutes=0;

	return 1;
	}
  else{
	return 0;
	}
}

