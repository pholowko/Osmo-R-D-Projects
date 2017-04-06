#ifdef TESTER
//******************************************************************************
// Created Jan 12, 2017
// This routine gets the current model number and serial number of the HDC1080 RH/Temp chip.  
// Returned values are valid if the function returns a zero.
// The RH and Temp is saved in the normal OUTPUT varaibles if the devices is attached to the usnit.
// The index is used to select the RJ45 port needed.  
// For this set of boards, it's set to one port as a default.  It still needs to be called with the default value in place.
//******************************************************************************
int16 GetHDC1080Version(int index)
{
    int16 version, tempver;
#ifndef COTWOSENSOR
	selectsensor(index);   // make the selection to talk with this sensor.
#endif
// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.


	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x80);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0xFF);  //Send the command for reading the version
	i2c_stop(PH_LIGHT);
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x81);  //Move the address number left on and add a one to make is a read command.
	tempver = i2c_read(PH_LIGHT);
    version = i2c_read(PH_LIGHT);
	i2c_stop(PH_LIGHT);
     version = version + (tempver<<8);
    return(version);
}


//******************************************************************************
// Created Jan 13, 2017
// This routine inits the HDC1080 RH/Temp chip.  
// No returned value.  Sets all measurements to max resolution which is 14 bits
// The index is used to select the RJ45 port needed.  
// For this set of boards, it's set to one port as a default.  It still needs to be called with the default value in place.
//******************************************************************************
void GetHDC1080init(int index)
{
    int version, tempver;

#ifndef COTWOSENSOR
	selectsensor(index);   // make the selection to talk with this sensor.
#endif
// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.

    // set the configuration register
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x80);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x02);  //Point the next two  bytes to the command register.
    i2c_write(PH_LIGHT,0x00);  // Send the MSB first.  In this case it is the default witch is 14 bits
	i2c_write(PH_LIGHT,0x00);  //Send the configuration LSB
	i2c_stop(PH_LIGHT);
    delay_ms(45);  //This is the time it takes to get the first measurement
     
}


//******************************************************************************
// Created Jan 11, 2017
// This routine gets the current reading of the HDC1080 RH/Temp chip.  
// Returned values are valid if the runction returns a zero.
// The RH and Temp is saved in the normal OUTPUT varaibles if the devices is attached to the usnit.
// The index is used to select the RJ45 port needed.  
// For this set of boards, it's set to one port as a default.  It still needs to be called with the default value in place.
//******************************************************************************
float GetHDC1080RHTemp(int index)
{
    unsigned int8 temphigh,templow,rhhigh, rhlow;
    float t,h;
    //int th,tl,hh,hl;
    GetHDC1080init(index);
#ifndef COTWOSENSOR
	selectsensor(index);   // make the selection to talk with this sensor.
#endif
// then send the command down to the sensor.  All of the communcatiuon is done through the I2C on PH_LIGHT.

// trigger tempeerature  measurement
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x80);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x00);  //Send the command for reading the version
//	i2c_stop(PH_LIGHT);
    delay_ms(20);   // wait for measurement
    
    
    
 //   Start over to read the measurement.  This kicks the chip out of low power mode.
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x81);  //Move the address number left on and add a one to make is a read command.
	temphigh = i2c_read(PH_LIGHT);
    delay_ms(10);   // wait for measurement
     
    templow = i2c_read(PH_LIGHT,0);
  	i2c_stop(PH_LIGHT);  
  
    
    // trigger rh  measurement
	i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x80);  //Move the address number left on and add a zero.
	i2c_write(PH_LIGHT,0x01);  //Send the command for reading the version
//	i2c_stop(PH_LIGHT);
    delay_ms(20);   // wait for measurement
    
  //   Start over to read the measurement.  This kicks the chip out of low power mode.
    i2c_start(PH_LIGHT);
	i2c_write(PH_LIGHT,0x81);  //Move the address number left on and add a one to make is a read command.   
    rhhigh = i2c_read(PH_LIGHT);
       delay_ms(10);   // wait for measurement
    rhlow = i2c_read(PH_LIGHT,0);
	i2c_stop(PH_LIGHT);
    
    th = (int) temphigh;
    tl = (int) templow;
    hh = (int) rhhigh;
    hl = (int) rhlow;
    
 //   t = (float) (th << 8 | tl);
 //   h = (float) (hh << 8 | hl);
 //   t = t * 165.0 / 65536.0 - 40.0;
//	h = h * 100.0 / 65536.0;	

    
    
    return(t);
}

#endif

#ifndef TIRHTEMP

float RHData, Temperature;   // These are the values for the coefenents for decay solutions.

//****************************************************************************
// Created Sept 22, 2014
// Init all of the I/O bits to make the RH/Temp sensor work
// Returns nothing
//****************************************************************************
void initRHTemp(void)
	{
	output_high(RHTEMP);   //This sets the output high.
	}



//****************************************************************************
// Created Sept 22, 2014
// Find the check sum number
//  0 - all is good, 1 - all is bad
//****************************************************************************
int16 CheckSumRHTemp(long RawRH, long RawTemp)
	{
	int16 checksum2,checksum3;

	checksum2 = (int16) 0xFF00 & RawRH;
    checksum2 = checksum2>>8;
	checksum2 = checksum2 + (int16) (0x00FF & RawRH);

	checksum3 = (int16) (0xFF00 & RawTemp);
    checksum3 = checksum3>>8;
	checksum2 = checksum3 + checksum2 + (int16) (0x00FF & RawTemp);

	return(0x00FF & checksum2);
	}


//***************************************************************************
// Created Sept 22, 2014
// This routine returns the RH and Temps as float through global variables
// Returns 1 if there is an error.  a zero if there none
// All calculations for converion and reading the sensor is done here.
//***************************************************************************
int GetTempRH(void)
	{
	int x,y,w,counter;
    long  RawRH, RawTemp, CheckSum;//These are the global varaibles for RH and Temperature


//  Send command out to the I/O pin
	output_high(RHTEMP);   //This sets the output high.
	output_low(RHTEMP);   //This sets the output high.
	delay_ms(5);
	output_high(RHTEMP);   //This sets the output high.
	delay_us(40);
	output_float(RHTEMP);
	delay_us(20);

	for (x=0; x < 5; x++) ///This waits to get out of the MCU command
		{
		y=input_state(RHTEMP);
		if (!y) break;
		delay_us(10);
		}
	for (x=0; x < 20; x++)   //This waits through the zero and finds a 1
		{
		y=input_state(RHTEMP);
		if (y) break;
		delay_us(10);
		}

	for (x=0; x < 15; x++)   //This waits through the one and finds a 0 for the beginning of the first bit
		{
		y=input_state(RHTEMP);   //wait for the first bit to pop up  Assuming is less than 200 us
		if (!y) break;
		delay_us(10);
		}
	
//beginning of first bit zero
//Setup the for loop
RawRH = 0; /// Clear out the variable
for (counter=0; counter < 16; counter++)
	{
//This section collects the bits from the first 16 bits and places it in one varible.
	for (x=0; x < 15; x++)   //This waits through the one and finds a 0 for the beginning of the first bit
		{
		y=input_state(RHTEMP);   //wait for the bit to time out the zero for the next bit
		if (y) break;
		delay_us(5);
		}
		w=y;
	for (x=0; x < 15; x++)   //This waits through the 1 to see how long it is.
		{
		y=input_state(RHTEMP);   //wait for the first bit to pop up  Assuming is less than 200 us
		if (!y) break;
		delay_us(5);
		}

	RawRH=RawRH<<1;	// Shift the whole word one bit left.
	if (x > 6)
		{
		RawRH = RawRH + 0x0001;
		}
	}
	


RawTemp = 0; /// Clear out the variable
for (counter=0; counter < 16; counter++)
	{
//This section collects the bits from the first 16 bits and places it in one varible.
	for (x=0; x < 15; x++)   //This waits through the one and finds a 0 for the beginning of the first bit
		{
		y=input_state(RHTEMP);   //wait for the bit to time out the zero for the next bit
		if (y) break;
		delay_us(5);
		}

	for (x=0; x < 15; x++)   //This waits through the 1 to see how long it is.
		{
		y=input_state(RHTEMP);   //wait for the first bit to pop up  Assuming is less than 200 us
		if (!y) break;
		delay_us(5);
		}
	

	RawTemp=RawTemp<<1;	// Shift the whole word one bit left.
	if (x > 6)
		{
		RawTemp = RawTemp + 0x0001;
		}
	}



CheckSum = 0; /// Clear out the variable
for (counter=0; counter < 8; counter++)
	{
//This section collects the bits from the first 16 bits and places it in one varible.
	for (x=0; x < 15; x++)   //This waits through the one and finds a 0 for the beginning of the first bit
		{
		y=input_state(RHTEMP);   //wait for the bit to time out the zero for the next bit
		if (y) break;
		delay_us(5);
		}

	for (x=0; x < 15; x++)   //This waits through the 1 to see how long it is.
		{
		y=input_state(RHTEMP);   //wait for the first bit to pop up  Assuming is less than 200 us
		if (!y) break;
		delay_us(5);
		}
	

	CheckSum=CheckSum<<1;	// Shift the whole word one bit left.
	if (x > 6)
		{
		CheckSum = CheckSum + 0x0001;
		}
	}

	RHData = (float)RawRH;

if (CheckSum == CheckSumRHTemp(RawRH,RawTemp))
	{
	RHData = (float)RawRH/10.0;
    Temperature = ((float)RawTemp)/10.0;
	return(0);
	}
	else
	{
	return(1);
	}
	}

#endif

#ifdef CHEAPEC 
//*************************************************************************************
// Created September 2, 2015
// This routines calculated all of the values for a given set of decay equation.
//  The equation is y = AA + BBexp^-CCx.  This is an electrcial decay equation that has to be run several times to get the values for AA, BB and CC.
// It's assumed the first value is the highest ppm  with the lowst value for x as in imput.
// The result are gloabe variables for AA, BB and BC.
// AA is calculated by knowing the first assmetopt.

float solvefordecay(int32 measurement)	
	{

	float eccheck;    //These are used for holding the caluclated values for the current returned iteration.  The x input is not needed because it's already defined.
	int x;


//**********************************************************************
// Added Sept 3, 2015
// Updated with regression equations May 31, 2016
// The attempt to solve for a decaying curve is stopped for now.  
// Currently a liner approach is used for three points.
//**********************************************************************
// Form the calibration data proved on the EEPROM, find all of the coef for the lineized LOG function.
//  Y = B + m(ln(x))
// B = 
// Find Y    
    
    
    
    
    
    
eccheck = (float) measurement;   /// Change over the data type to a float for correct operations in the range testing.


if (eccheck > eccalibrationx[0])   
	{
	y = 0.0;
	return(y);   //Send out the result if it's to a limit.
	}

if (eccheck <= eccalibrationx[2])
	{
	y = 2000.0;
	return(y);  //Send out the result if it's to a limit.
	}

}



//************************************************************************************
// Created Augest 24, 2015
// This routine measures the time delay for EC  or TDS.  It does this by cycling through a decay of an RC circute.
// The pinouts are as follwos:
// PICCPU    Function
// RC14     - C+
// RC13     - C-
// RD0      - EC+
// RD11     - EC-
// This is the firing order for measurement:
// EC1     input   low       low               input        measuere decay    high
// C+      high    input     measuere decay    high         low               input
// C-      low     low       low               high         high              high
// The returned results is an average of 16 measurements of plus and mnues measurentents at 1Khz
// returns a float with the current EC value.
//*************************************************************************************
float measureTDS(void)
	{

	int statecounter,x;
	int32 currentreadingunder=0,y,z;  // This is used as the state counter for the measurmeents.  It goes between 1 to seven.
	int32 measurement=0, currentreading;   //This is the measurement accumlator and then it's averaged.
	float result;

//  Set up the output and input for the EC meter.
/*
while(1)
	{
	output_high(PIN_D10);    //  Define as EC1
	output_low(PIN_D10);    //  Define as EC1
	}
*/
output_high(PIN_D10);    //  Define as EC1-

//*************************************************
// Changed from the old board to the last version on March 28, 2016
// The two C+ and C- are changed from D0  & C13 to D8 and RD9 for C+ and RD8 for C-
// Old settings are below.
//output_high(PIN_D0);     // Define as C+   // Added September 6, 2015  Needs to be changed to RD9 for the new board
//output_float(PIN_C13);           // Define as C-   // Added September 6, 2015  Needs to be changed to RD8 for the new board
//**************************************************************

output_high(PIN_D9);     // Define as C+   // Added September 6, 2015  Needs to be changed to RD9 for the new board
output_float(PIN_D8);           // Define as C-   // Added September 6, 2015  Needs to be changed to RD8 for the new board

output_high(PIN_D11);    //  Define as EC2+   This is the negative direction charge compared to ground. 
// input_state();
//while(1)
//	{
restart_wdt();   // restart the WD timer.  It set for 65 seconds
for (x = 1; x <=16; x++)
	{

	for (statecounter = 1; statecounter < 7; statecounter++)
		{
		switch(statecounter)
			{
			case 1:     //  Charge Cap to max in + direction.
				output_float(PIN_D10);    //  Define as EC-
				input(PIN_D11);    //  Define as EC+    keep floarting to no interferiw with measurement.				
				//output_high(PIN_D0);     // Define as C+
                output_high(PIN_D9);     // Define as C+  New Board I/O pin  March 28, 2016
				//output_low(PIN_C13);           // Define as C-
                output_low(PIN_D8);           // Define as C-  New Board I/O pin  March 28, 2016
				delay_us(100);   // Wait for the CAP to charge to Vcc.  Check on scope.
				break;
			case 2:
				output_low(PIN_D11);    //  Define as EC+
				output_float(PIN_D10);    //  Define as EC-    keep floarting to no interferiw with measurement.				
//				input(PIN_D0);     // Define as C+

		//		output_low(PIN_D0);     // Define as C+
				//output_low(PIN_C13);           // Define as C-
                output_low(PIN_D8);           // Define as C-  New Board I/O pin  March 28, 2016
			//	currentreading = input(PIN_D11);   // update the output for the first one.
				for (currentreading = 0; currentreading < 20000; currentreading++)
					{
				//	fprintf(BT,"Current EC currentreading %i\n\r",currentreading);
				/*	if (!input(PIN_D0))
							{
							 y = currentreading;   //this is the count for the 1/3 of the trigger.
							break;
							}  */
 					if (!input(PIN_D9))   //New Board I/O pin  March 28, 2016
							{
							 y = currentreading;   //this is the count for the 1/3 of the trigger.
							break;
							}                   
					}
				break;
			case 3:
			    input(PIN_D10);    //  Define as EC-
				output_float(PIN_D11);    //  Define as EC+    keep floarting to no interferiw with measurement.				

				//output_high(PIN_D0);     // Define as C+   //Discharge the CAP in the other direction.
                output_high(PIN_D9);     // Define as C+  New Board I/O pin  March 28, 2016
				//output_high(PIN_C13);           // Define as C-
                output_high(PIN_D8);           // Define as C-  New Board I/O pin  March 28, 2016
				delay_us(100);   // Wait for the CAP to charge to Vcc.  Check on scope.

				break;
			case 4:
				//output_high(PIN_C13);     // Define as C+
                output_high(PIN_D8);           // Define as C-  New Board I/O pin  March 28, 2016
				//output_low(PIN_D0);           // Define as C-
                output_low(PIN_D9);     // Define as C+  New Board I/O pin  March 28, 2016
				delay_us(100);   // Wait for the CAP to charge to Vcc.  Check on scope.
				break;
			case 5:
				output_high(PIN_D10);    //  Define as EC-
				output_float(PIN_D11);    //  Define as EC+    keep floarting to no interferiw with measurement.				
//				input(PIN_D0);     // Define as C+

		//		output_low(PIN_D0);     // Define as C+
			//	output_high(PIN_D0);           // Define as C+
			//	currentreading = input(PIN_D11);   // update the output for the first one.
				for (currentreadingunder = 0; currentreadingunder < 20000; currentreadingunder++)
					{
				//	fprintf(BT,"Current EC currentreading %i\n\r",currentreading);
				/*	if (input(PIN_D0))    //  measure using C-
							{
							 z = currentreadingunder;   //this is the count for the 1/3 of the trigger.
							break;
							}  */
                    if (input(PIN_D9))    //  measure using C-  New Board I/O pin  March 28, 2016
							{
							 z = currentreadingunder;   //this is the count for the 1/3 of the trigger.
							break;
							}
					}
				break;

			case 6:

				//output_low(PIN_D0);     // Define as C+   //Discharge the CAP in the other direction.
                output_low(PIN_D9);     // Define as C+  New Board I/O pin  March 28, 2016
				//output_low(PIN_C13);           // Define as C-
                output_low(PIN_D8);           // Define as C-  New Board I/O pin  March 28, 2016



				break;
			default:


				break;
			}

	 measurement =  measurement + y;   // Add together all of the 16 numbers.
currentreadingunder = currentreadingunder + z;
restart_wdt();   // restart the WD timer.  It set for 65 seconds
		}


	}
currentreadingunder = currentreadingunder/16;
	measurement = measurement/16;   // Do the average


//*********************************************************************************
// Created Aug 10, 2016
// Set all EC probe levels to zero when leaving the routine.
//********************************************************************************
  output_low(PIN_D8);     //Set to low to prevent interference with pH bulb.
  output_low(PIN_D9);
  output_low(PIN_D10);
  output_low(PIN_D11);

//************************************************************************************************
// Created Sept 1, 2015
// Below takes the decay value from the C+ side and converts it into ppm.  
// At this time there is no temperature compensation.
// At this time the calibration values are not saved in SD Card.
//************************************************************************************************

//  Current measured data
//  Reading            ppm
//  36                 1553
//  51                 468
//  700                24

eccalibrationx[0] = 447.0;
eccalibrationx[1] = 44.0;
eccalibrationx[2] = 19.0;


eccalibrationy[0]  = 33.0;
eccalibrationy[1]  = 481.0;
eccalibrationy[2]  = 1718.0;


result = solvefordecay(measurement); // Solve for the current value for calibration for this EC meter
fprintf(BT,"Current EC reading top %Lu under %Lu  ppm %f\n\r",measurement,currentreadingunder,result);
result =  (float) measurement;
//measurement=0;
//}
//return(result);   // this is the old return  Changed April 14, 2016
return(result);	
	}   // end of function.

#endif