////////////////////////////////////////////////////////////////
//HC-06.c
//
//By: Erik Gokbora
//
//Associated functions to automate the setup and communication with the bluetooth module



//int32 baudArray[20]={50,75,110,134,150,200,300,600,1200,2400,9600,19200,38400,57600,115200,230400,345600,460800};

#ifdef PIC24
#pin_select U1TX=PIN_B1 
#pin_select U1RX=PIN_B0 
#use rs232(UART1, baud=9600, stream=BT)
#else
#use rs232(uart1, baud=9600, xmit=PIN_C6, rcv=PIN_C7, stream=BT)
//#use rs232(uart1, baud=BTBAUDR, parity=N,bits=8,stop=1, stream=BT)
#endif
////////////////////////RS232 Interrupt//////////////////////
#ifndef BT_BUFF_SIZE 
#define BT_BUFF_SIZE 255
#endif




//int8 buffer[255];

int8 BTbuffer[BT_BUFF_SIZE];

//int8 next_in  = 0;
//int8 next_out = 0;

int16 BTnext_in  = 0;
int16 BTnext_out = 0;




#ifdef PIC24
#INT_RDA
#else
#INT_RDA
#endif
void RDA_isr()
{
   int8 tbt;

   BTbuffer[BTnext_in] = fgetc(BT);
   tbt = BTnext_in;
   BTnext_in = (BTnext_in+1) % sizeof(BTbuffer);
   if(BTnext_in == BTnext_out)
		{
      	BTnext_in=tbt;        // Buffer full !!
		}
	//ADDED Crap
	if(BTnext_in==BT_BUFF_SIZE)
	{
		BTnext_in=0;
	}	
	//ADDED Crap
	if(BTnext_out==BT_BUFF_SIZE)
	{
		BTnext_out=0;
	}









}

////////////////////////////////////////////////////////////

#define BTbkbhit (BTnext_in != BTnext_out)
//#define bkbhitDebug (next_in != next_outDebug)

int8 BTbgetc()
{
   int8 c;

   while(!BTbkbhit);
   c = BTbuffer[BTnext_out];
   BTnext_out = (BTnext_out+1) % sizeof(BTbuffer); 
   return c;
}

////////////////////////////////////////////////////////////

void BTBasicTest(){
	if(BTbkbhit){
	//if(kbhit()){
		//putc('!');
		//putc(getc());
		//char cvl= getc();

		//char cvl = bgetc();
		char cvl =BTbgetc(); 		//getWIFIChar();
		putc(cvl,BT);
		putc('\n',BT);
	}
}

///////////////////////////////////////////////////////////

void setupBT()
{
printf("AT+NAMEPaul's Tesla Meter");
}