

float RHData, Temperature;

//****************************************************************************
// Created Sept 22, 2014
// Init all of the I/O bits to make the RH/Temp sensor work
// Returns nothing
//****************************************************************************
void initRHTemp(void)
	{
	output_high(PIN_D0);   //This sets the output high.
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
	output_high(PIN_D0);   //This sets the output high.
	output_low(PIN_D0);   //This sets the output high.
	delay_ms(5);
	output_high(PIN_D0);   //This sets the output high.
	delay_us(40);
	output_float(PIN_D0);
	delay_us(20);

	for (x=0; x < 5; x++) ///This waits to get out of the MCU command
		{
		y=input_state(PIN_D0);
		if (!y) break;
		delay_us(10);
		}
	for (x=0; x < 20; x++)   //This waits through the zero and finds a 1
		{
		y=input_state(PIN_D0);
		if (y) break;
		delay_us(10);
		}

	for (x=0; x < 15; x++)   //This waits through the one and finds a 0 for the beginning of the first bit
		{
		y=input_state(PIN_D0);   //wait for the first bit to pop up  Assuming is less than 200 us
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
		y=input_state(PIN_D0);   //wait for the bit to time out the zero for the next bit
		if (y) break;
		delay_us(5);
		}
		w=y;
	for (x=0; x < 15; x++)   //This waits through the 1 to see how long it is.
		{
		y=input_state(PIN_D0);   //wait for the first bit to pop up  Assuming is less than 200 us
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
		y=input_state(PIN_D0);   //wait for the bit to time out the zero for the next bit
		if (y) break;
		delay_us(5);
		}

	for (x=0; x < 15; x++)   //This waits through the 1 to see how long it is.
		{
		y=input_state(PIN_D0);   //wait for the first bit to pop up  Assuming is less than 200 us
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
		y=input_state(PIN_D0);   //wait for the bit to time out the zero for the next bit
		if (y) break;
		delay_us(5);
		}

	for (x=0; x < 15; x++)   //This waits through the 1 to see how long it is.
		{
		y=input_state(PIN_D0);   //wait for the first bit to pop up  Assuming is less than 200 us
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