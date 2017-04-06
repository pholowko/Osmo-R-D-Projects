
//#include <timing.c>

//#define RS PIN_E2
//#define WR PIN_E1
//#define E PIN_E0

void VacDisplayinit(void)
{
	//wait(1000000);	
	delay_ms(1000);
	output_high(RDPIN); // Pin 11 E/(~RD)
	output_high(WRPIN);//pin 10 R/~WR
	output_d(0x0F);	//  Dispaly Turns ON, Blink Off.
	output_low(RSPIN); // Pin 9 RS 
	output_low(WRPIN); //Pin 10 ~WR
	output_high(WRPIN);//pin 10 R/~WR
}

void VacWriteChar(char letter)
{
	//wait(10);
    int stuff;
	//delay_us(100);
	//output_high(RSPIN);  //RS
	//output_d(letter);	
	//output_low(WRPIN); // write pin low
	//delay_us(100);
	//wait(10);
	//output_high(WRPIN); // write pin high
    
    stuff = writeChar(letter);
    
	}

void VacDisplayClear(void)
{
	//wait(1000000);
	delay_ms(1000);
	output_low(RSPIN);  //RS
	output_d(0x01);	
	output_low(WRPIN); // write pin low
	output_high(WRPIN); // write pin high
}

void VacSetXY(int X, int Y)
{
	//output_low(RSPIN);
	//output_d(0x06); //  Address counter incremented, cursor shift en
//	output_low(WRPIN); //Pin 10 ~WR
	//output_high(WRPIN);//pin 10 R/~WR*/
    writeByte(0,0x06);	//Address counter incremented, cursor shift en
    writeByte(0,0x02);	//Move cursor home
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
    //    writeByte(0,0x0d);	//Clear Display
    writeByte(0,location);	//Clear Display
//	output_d(location);
//	wait(100);
//	delay_us(100);
//	output_low(WRPIN); // write pin low
//	wait(100);
	delay_us(100);
//	output_high(WRPIN); // write pin high
}

void VacDisplayString(char* string)
{
	
	int i;
	int len = strlen(string);
	//for length of string, take i-th position and output
	for (i = 0; i < len; i++)
	{
		VacWriteChar(string[i]);
	}

}
void Display_XYString(int x, int y, char* string)
{
	VacSetXY(x,y);
//	wait(50);
	delay_ms(100);
	VacDisplayString(string);
}

/*
void RandomNum_Task(void)
{
	LocX = 2;
	LocY = 2;
}
*/

/*
long long RandX(void)
{
	unsigned long long tickval = get_ticks();

	return tickval % 4;
}
long long RandY(void)
{
	return get_ticks() % 20;
}

*/