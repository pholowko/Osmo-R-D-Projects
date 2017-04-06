


//**********************************************************************************************
// Created July 17, 2015
// These reoutines are tested seperatly from the orginal routines to keep the system running.
//  They will be replaced when completed.  The first task it to complete getting the latest FW off the server.
//**********************************************************************************************


//**********************************************************************************************
// Created July 17, 2015
// Put the WIFI unit into a mode where it accepts AT commands.
// The rourtine returns a 0 when succefull.
// A number is returned when it could not be succefull after three times.
// Errors given:  
// 1  - Wifi device is not ready.
// 2
//  Inputs
//**********************************************************************************************
int getintoATmode(void)
	{

int16  counter = 0;   //This is a general purpose counter for timing out.
int16 timeoutcounter = 0;
char lastcharacter;
// test to see if the WIFI module is in resust mode.  Wait for a while to see if it gets out.

	while (xReadyWiFi())
		{
		//delay_ms(100);
		BTBasicTest();
		calldebug();  // Added July 13, 2015  Test to see if there is a required debug routine called.  When returned, it continues where it left off at this point.
		counter++;
		if (counter > 62000)
			{
			return(1);   // This error
			}
		}

//clear input buffer.
		next_in  = 0;
		next_out = 0;
		fprintf(WIFI,"+++");   ///Send out the returned "a" to tell the WiFI moduule I'm here.
		while(next_in != next_out)
		{
		lastcharacter = bgetc();  //Get the last character out of the buffer if there is a new one.
    	if (lastcharacter == 0x61)   // this should be an "a"
			{
			break;
			}
			else
			{
			timeoutcounter++;
	//	delay_ms(60);
			}
			if (timeoutcounter > 10)   //If the time is too long, time out and send the error return.
				{
           	 return(2);   //An "a" is never returned  and the "a" return error is retured.
				break;
				}
		}

//  We recevied an "a", not send one back.

while(next_in != next_out)
	{
	lastcharacter = bgetc();  //Get the last character out of the buffer if there is a new one.
    if (lastcharacter == 0x2B)    //  This is a "+" for the "+OK"
		{ 
		break;
		}
		else
		{
		timeoutcounter++;
//		delay_ms(60);
		}
		if (timeoutcounter > 50)   //If the time is too long, time out and send the error return.
			{
            return(2);   //An "+" is never returned  and the "+" return error is retured.
			break;
			}
	}




	return(0);
	}