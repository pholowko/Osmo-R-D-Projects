


#define RS PIN_E0
#define E PIN_E1

#define LCD_DB7 PIN_E5
#define LCD_DB6 PIN_E4
#define LCD_DB5 PIN_E3
#define LCD_DB4 PIN_E2



//Create an override condition to replace lcd function calls with blank macros
#define LCD_EN 1

#if LCD_EN

//********************************************************************************
// Created Sept 30, 2014
// This routine sends the whole byte into two nibbles to the upper nibble of the display
//********************************************************************************

void SendByteToVFDNibble(byte data)
{
byte temp;
	output_high(E); // Pin 11 E/(~RD)
//	delay_us(25);
//Setup the bottom nibble on the inputs.

//Setup the top nibble on the inputs.
	temp=data&0x80;
	if (temp)
		{
		output_high(PIN_E5);		
		}	
		else
		{
		output_low(PIN_E5);
		}
	temp=data&0x40;
	if (temp)
		{
		output_high(PIN_E4);		
		}	
		else
		{
		output_low(PIN_E4);
		}
	temp=data&0x20;
	if (temp)
		{
		output_high(PIN_E3);		
		}	
		else
		{
		output_low(PIN_E3);
		}
	temp=data&0x10;
	if (temp)
		{
		output_high(PIN_E2);		
		}	
		else
		{
		output_low(PIN_E2);
		}


	delay_us(10);
	output_low(E); // Pin 11 E/(~RD)
	delay_us(10);
	output_high(E); // Pin 11 E/(~RD)
//delay_us(25);



	temp=data&0x08;
	if (temp)
		{
		output_high(PIN_E5);		
		}	
		else
		{
		output_low(PIN_E5);
		}
	temp=data&0x04;
	if (temp)
		{
		output_high(PIN_E4);		
		}	
		else
		{
		output_low(PIN_E4);
		}
	temp=data&0x02;
	if (temp)
		{
		output_high(PIN_E3);		
		}	
		else
		{
		output_low(PIN_E3);
		}
	temp=data&0x01;
	if (temp)
		{
		output_high(PIN_E2);		
		}	
		else
		{
		output_low(PIN_E2);
		}

	delay_us(10);
	output_low(E); // Pin 11 E/(~RD)  return to the init state
	delay_us(10);
}



void VacDisplayinit(void)
{
	output_low(RS); // Pin 9 RS This means it's a command.  A 1 means it's data
	output_low(E); // Pin 11 E/(~RD)

	delay_ms(1000);
	output_low(RS); // Pin 9 RS This means it's a command.  A 1 means it's data
	output_high(E); // Pin 11 E/(~RD)
	delay_us(25);
//  First set up the command where we are only using 4 bits in M68 mode, not Intel86 mode.
	output_low(PIN_E5);   //This sends byte 0x2X  to the upper part of the nibble.
	output_low(PIN_E4);   //This command sets the display to take nibbles, not bytes.
	output_high(PIN_E3);
	output_low(PIN_E2);


	delay_us(100);
	output_low(E); // Pin 11 E/(~RD)
	delay_us(100);
/*	output_high(E); // Pin 11 E/(~RD)
	delay_us(25);
//  First set up the command where we are only using 4 bits in M68 mode, not Intel86 mode.
	output_low(PIN_E5);   //This sends byte 0x2X  to the upper part of the nibble.
	output_low(PIN_E4);   //This command sets the display to take nibbles, not bytes.
	output_high(PIN_E3);
	output_low(PIN_E2);


	delay_us(100);
	output_low(E); // Pin 11 E/(~RD)
	delay_us(100);
	output_high(E); // Pin 11 E/(~RD)  
	delay_us(25);

//  First set up the command where we are only using 4 bits in M68 mode, not Intel86 mode.
	output_low(PIN_E5);   //This sends byte 0x2X  to the upper part of the nibble.
	output_low(PIN_E4);   //This command sets the display to take nibbles, not bytes.
	output_high(PIN_E3);
	output_low(PIN_E2);


	delay_us(100);
	output_low(E); // Pin 11 E/(~RD)
	delay_us(100);
	output_low(RS); // Pin 9 RS 
	output_high(E); // Pin 11 E/(~RD)
	delay_us(25);
*/
    SendByteToVFDNibble(0x0E);
//	output_d(0x0F);	//  Dispaly Turns ON, Blink Off.
	output_low(RS); // Pin 9 RS 
	delay_us(100);
//	output_low(E); // Pin 11 E/(~RD)

}

void VacWriteChar(char letter)
{
	//wait(10);

	output_high(RS);  //RS  set to data mode

    SendByteToVFDNibble(letter);	



	}

void VacDisplayClear(void)
{

	delay_ms(500);
	output_low(RS);  //RS
    SendByteToVFDNibble(0x01);
//	output_d(0x01);	
	output_high(RS);  //RS
}

void VacSetXY(int X, int Y)
{
	output_low(RS);
   SendByteToVFDNibble(0x06);
//	output_d(0x06); //  Address counter incremented, coursor shift en

	int location=0;
	switch (Y)
	{
	case 1 :
		location = 128;
		break;	

	case 2 :
		location = 160;
		break;	
		
	case 3 :
		location = 192;
		break;	
	
	case 4 :
		location = 224;
		break;	
	}
	location = location + x;
//	output_d(location);
   SendByteToVFDNibble(location);

	delay_us(100);


}

void VacDisplayString(char* string)
{
	
	int i;
	int len = strlen(string);
	//for length of string, take i-th position and output
	for (i = 0; i < len; i++)
	{
		VacWriteChar(string[i]);
		//sprintf
	}

}
void Display_XYString(int x, int y, char* string)
{
	VacSetXY(x,y);
//	wait(50);
	delay_ms(100);
	VacDisplayString(string);
}



#else //If you dont want to use the LCD display
#define SendByteToVFDNibble(d)
#define VacDisplayinit()
#define VacWriteChar(c)
#define VacDisplayClear()
#define VacDisplayString(s)
#define Display_XYString(x, y, s)
#endif