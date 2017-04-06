int globalLEDstate;  // This is used for keeping track of which color LEDs are on and off.  This is not modified outside of the colling set routines.

//***************************************************************************
// Updated and Changed December 7, 2015
// The two defs below are used for the BT pin reset.  This needs to be set high for no reset.
// The Fault LED is used for a general purpose fault indicator.  It needs to go through a lamp test  at the beginnging.
//***************************************************************************

#define BT_ResetPIN PIN_E5   // Changed December 7, 2015
#define Fault_LED_RED PIN_E4     // Added December 7, 2015
#define BT_AT PIN_B2     // Added December 7, 2015  // This is the BT attention flag.  This is used to send commands to the BT chip.
#define Fault_LED_BLUE PIN_G7     // Added December 7, 2015
#define Fault_LED_GREEN PIN_G6     // Added December 7, 2015




void Display_XYString(int x, int y, char* string)
{
//	VacSetXY(x,y);    //Removed December 7, 2015 for new board
//	wait(50);
//	delay_ms(100);         //Removed December 7, 2015 for new board
//	VacDisplayString(string);   //Removed December 7, 2015 for new board


//********************************************************************
// Created Aug 5, 2015
//  This routine prints to the BT raw data where it can be collected on a terminal program.
//********************************************************************

if (toggleechoonoff)    // see if it needs to send the string to bluetooth.  Added July 14, 2015 
	{ 
	fprintf(BT,"%s\n\r",string); 
	}



}



//*********************************************************************************
// Added December 7, 2015
// This routine inits the two lines for BT reset and the Fault LED.
// It also does a lamp test of the Fault LED.
//  This routine returns nothing.
//*********************************************************************************
void LEDinit(void)
	{

int x;  // dummy variable for cycling through color lamps

	output_high(BT_ResetPIN);    // Clear the flag
	output_high(Fault_LED_RED);	     // Clear the flag
	output_high(Fault_LED_GREEN);	     // Clear the flag
	output_high(Fault_LED_BLUE);	     // Clear the flag

	globalLEDstate = 0;   // Set this to off for all LEDs in the RGB LED.
	output_low(BT_AT);	     // Clear the AT pin on the BT.


// do a lamp test on the Fault LEDs.
// Added and updated December 18, 2015
// Each LED color (RGB) has a different resistor and lamp intensity.  The intensity is processed through adding resistors to each one to make them all light the same intensity
// Cycle through all of the combinations of colors for lamp test.
	
for (x = 0; x < 8; x++)
	{
			delay_ms(250);
 switch(x)
	{
	case 0:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 1:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag
	
			break;
	case 2:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 3:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 4:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 5:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 6:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 7:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	default:
			break;
	}
	}
    delay_ms(250);
	output_high(Fault_LED_RED);	     // Clear the flag
	output_high(Fault_LED_GREEN);	     // Clear the flag
	output_high(Fault_LED_BLUE);	     // Clear the flag

	}


//*********************************************************************************
// Created December 7, 2015
// This routine sets and/or clears the Fault Flag LED.
//  It returns nothing.
// Input varaible is a one or a zero.
//********************************************************************************
void FaultFlag(int state)
	{
	if (state > 0)
		{
		output_low(Fault_LED_RED);	     // Set the flag
		}
		else
		{
		output_high(Fault_LED_RED);	     // Clear the flag
		}
	}



//*********************************************************************************
// Created December 18, 2015
// This routine sends the error code or message to the RGB led.  Any number is used.
// Nothing is returned.  The global varible is updated.
//*********************************************************************************
void restoreLEDmessage(void)
	{


 switch(globalLEDstate)
	{
	case 0:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 1:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 2:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 3:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 4:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 5:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 6:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 7:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	default:
			break;
	}


	}


//*********************************************************************************
// Created December 27, 2015
// This routine sends the error code or message to the RGB led.  t's a straight number to the leds
// Nothing is returned.  The global varible is updated.
//*********************************************************************************
void orLEDmessage(int datain)
	{

		globalLEDstate|=datain;   //  ORs the current data with the changed data.


 switch(globalLEDstate)
	{
	case 0:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 1:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 2:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 3:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 4:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 5:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 6:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag
			delay_ms(250);
			break;
	case 7:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag
			delay_ms(250);
			break;
	default:
			break;
	}


	}



//*********************************************************************************
// Created December 27, 2015
// This routine sends the error code or message to the RGB led.  t's a straight number to the leds
// Nothing is returned.  The global varible is updated.
//*********************************************************************************
void LEDmessage(int datain)
	{

    
#if WHITELED    
		globalLEDstate&=datain;   //  ANDs the current data with the changed data.


 switch(globalLEDstate)
	{
	case 0:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 1:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 2:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 3:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_high(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 4:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 5:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_high(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag

			break;
	case 6:
			output_high(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag
			delay_ms(250);
			break;
	case 7:
			output_low(Fault_LED_RED);	     // Clear the flag
			output_low(Fault_LED_GREEN);	     // Clear the flag
			output_low(Fault_LED_BLUE);	     // Clear the flag
			delay_ms(250);
			break;
	default:
			break;
	}
#else
 
 if (datain > 0)
 {
     output_high(Fault_LED_RED);	     // Clear the flag
 }
 else
 {
     output_low(Fault_LED_RED);	     // Clear the flag
 }
 
#endif

	}
    
    


//********************************************************************************
// Created December 7, 2015
// This routine does a hard reset on the BT chip/board.
// It returns nothing.  This reset is used for chaninig the BT chip between master and slave.
//********************************************************************************
