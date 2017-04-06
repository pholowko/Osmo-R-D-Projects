

#define I2CDEBUG 0
char STA_SSID[40]="NETGEAR31";
char STA_PW[64]="royalumbrella053";
char STA_AUTH[8]="WPA2PSK";
char STA_ENC[4]="AES";
char ATBUFF[100];




#ifdef PIC24
//#use delay(clock=8100000 )
#define BAUDR 9600
#pin_select U3TX=PIN_B15 
#pin_select U3RX=PIN_B14 
//XMIT=PIN_B15, RCV=PIN_B14,
#use rs232(uart3, baud=57600, xmit=PIN_B15, rcv=PIN_B14, stream=WIFI)
//#use delay(clock=800000)
#else
/*
#define BAUDR 115200
#use rs232(uart1, baud=BAUDR, FLOW_CONTROL_MODE, stream=WIFI)
*/
#endif




////////////////////////RS232 Interrupt//////////////////////
#ifndef WIFI_BUFF_SIZE 
#define WIFI_BUFF_SIZE 800
#endif

//int8 buffer[255];

int8 buffer[WIFI_BUFF_SIZE];

//int8 next_in  = 0;
//int8 next_out = 0;

int16 next_in  = 0;
int16 next_out = 0;


#INT_RDA3
void RDA3_isr()
{
   int8 t;
output_High(PIN_D1);
   buffer[next_in] = fgetc(WIFI);
   t = next_in;
   next_in = (next_in+1) % sizeof(buffer);
   if(next_in == next_out)
		{
      	next_in=t;        // Buffer full !!
		}

	//ADDED Crap
	if(next_in==WIFI_BUFF_SIZE)
	{
		next_in=0;
	}	
	//ADDED Crap
	if(next_out==WIFI_BUFF_SIZE)
	{
		next_out=0;
	}

}

////////////////////////////////////////////////////////////

#define bkbhit (next_in != next_out)
//#define bkbhitDebug (next_in != next_outDebug)

int8 bgetc()
{
   int8 c;

   while(!bkbhit);
   c = buffer[next_out];
   next_out = (next_out+1) % sizeof(buffer); 
   return c;
}


int8 bpeekc()
{
   int8 c;

   while(!bkbhit);
   c = buffer[next_out];
   return c;
}

////////////////////////////////////////////////////////////

	#if I2CDEBUG

#USE I2C(MASTER,I2C1, sda=PIN_C4, scl=PIN_C3,FAST=10000,  NOINIT)

charI2CWrite(int8 c)
{
		i2c_start();
		i2c_write(0xa0);
		i2c_write(c);
		i2c_stop(); 
}
	#endif

//////////////////////////////////////////

	int8 getWIFIChar()
{
	int8 c = bgetc();

		//Bake the I2C Debug right in
		#if I2CDEBUG
		i2c_start();
		i2c_write(0xa0);
		i2c_write(c);
		i2c_stop(); 
		#endif


	return c;
}



///////////////////////////
///////////////////////////
///////WIFI NONSENSE///////
///////////////////////////
///////////////////////////


void enableWIFIModule()
{

   enable_interrupts(INT_RDA);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
}

int8 WIFIBasicTest(){
	if(bkbhit){
	//if(kbhit()){
		//putc('!');
		//putc(getc());
		//char cvl= getc();

		//char cvl = bgetc();
		char cvl = bgetc(); //getWIFIChar();
		fputc(cvl,WIFI);
		return cvl;
	}
}


void WIFIBasicBroadcast(){
		if(bkbhit){
		fputc('T',WIFI);
		fputc('e',WIFI);
		fputc('s',WIFI);
		fputc('t',WIFI);
		fputc('\r',WIFI);
		fputc('\n',WIFI);
		delay_ms(500);
		}
}



//*************************************************************************
// Created December 23, 2014
// This routine returns the nLink State of the WiFi
//*************************************************************************
int8 nLinkWiFi()
	{
	int8 tempvalue;
    //This returns a 1 when the WiFi Module is n link connected.
	//get the current inputstate of the WiFi
	tempvalue = input(PIN_B8);
//	tempvalue=!tempvalue;
	return(tempvalue);
	}





//*************************************************************************
// Created December 23, 2014
// This routine returns the Ready State of the WiFi
//*************************************************************************
int8 xReadyWiFi()
	{
	int8 tempvalue;
    //This returns a 1 when the WiFi Module is ready to recevie commands.
	//get the current inputstate of the WiFi
	tempvalue = input(PIN_B11);
//	tempvalue=!tempvalue;
	return(tempvalue);
	}

//*************************************************************************
// Created December 23, 2014
// This routine resets the  WiFi device
//*************************************************************************
void xRST()
	{
output_high(PIN_D5);   //reset.  needs to be at least 300 ms	
delay_ms(600);    //Delay for 600 ms to make sure
output_low(PIN_D5);
	}

//////////////////////////////
//MCU WIFI MODULE FACTORY RESET
//////////////////////////////
void wifiRestore(){
#ifdef PIC24
output_high(PIN_B10);   //reload
delay_ms(8000);
output_low(PIN_B10);

#endif
}




////////////////////////////////
//WIFI SETUP
////////////////////////////////
void wifiInit(){
output_low(PIN_D5);   //reset modula
output_low(PIN_B10);  //WiFi Restore input signal - Active High
input(PIN_B11);   //This is the xReady signal
input(PIN_B8);   //This is the nLink signal
}




//////////////////////////////////////////////
//AT COMMANDS
//////////////////////////////////////////////






/////////////////////////
//Enter AT Command Mode
/////////////////////////
void WIFI_enter_setup(){
fprintf(WIFI,"+++");
//while(!bkbhit)
delay_ms(600);
fprintf(WIFI,"a");
delay_ms(600);
//fprintf(WIFI,"AT+E");
//while(!bkbhit)
{

}
}



/////////////////////////
//Reset Module
/////////////////////////
void WIFI_reset()
{
fprintf(WIFI,"AT+Z\r");
//while(!bkbhit)
{

}
//delay_ms(500);
wifisetup=1;
}


/////////////////////////
//Query Ap's
/////////////////////////
void WIFI_ap_scan(){
fprintf(WIFI,"AT+WSCAN\r");
//while(!bkbhit)
{

}
}


void WIFI_AT_Help()
{
fprintf(WIFI,"AT+H\r");
}


void WIFI_APSTA(int1 enable)
{
if(enable)
{
sprintf(ATBUFF,"AT+FAPSTA=on\r");
}
else
{
sprintf(ATBUFF,"AT+FAPSTA=off\r");
}

fprintf(WIFI,ATBUFF);
}

void WIFI_STA_SSID()
{
fprintf(WIFI,"AT+WSSSID=%s\r",STA_SSID);
}

void WIFI_STA_KEY()
{
fprintf(WIFI,"AT+WSKEY=%s,%s,%s\r",STA_AUTH,STA_ENC,STA_PW);
//fprintf(WIFI,ATBUFF);
}



void purgeBuff()
{
while(bkbhit)
	{
	char c=bgetc();
	}

}



void readCharCFG()
{
delay_ms(100);
while(bkbhit)
	{
	char c=bgetc();
	//VacWriteChar(c);
	putc(c,BT);
	}
delay_ms(200);
}


#define WFSETUPDEBUG 1
#define USETCPB 0

void WIFI_STA_CCONFIG(int1 resetConfig)
{
char cntrstr[4];
static int8 WFSetupState=0;
static int1 WFHasWritten=0;
static int16 jankycntr=0;
USEAT=1;
	if(resetConfig)
	{
	purgeBuff();
	WFSetupState=0;
	WFHasWritten=0;
	jankycntr=0;
	}

	if(ATisOK==1)
	{
	ATisOK=0;
	WFSetupState++;
	WFHasWritten=0;
	#if WFSETUPDEBUG
	delay_ms(5000);
	VacDisplayClear();
	#endif
	}
	else
	{
	jankycntr++;
	}

	if(jankycntr>=100)
	{
	jankycntr=0;
	WFHasWritten=0;	
	}

sprintf(cntrstr,"%d%d%d-%LD",WFSetupState,ATisOK,WFHasWritten,jankycntr);
Display_XYString(12,1,cntrstr);

if(WFHasWritten==0)
{
switch(WFSetupState)
{

//Enter AT Command Mode
case 0:
//xRST();
delay_ms(50);
	while (xReadyWiFi())
		{
		delay_ms(100);
		}
WIFI_enter_setup();
delay_ms(50);
//fprintf(WIFI,"AT+E=off\r");
WFHasWritten=1;
WFSetupState++;
break;
//readCharCFG();
//VacSetXY(1,1);

//Setup AP and STA mode
case 1:
//WIFI_APSTA(1);
fprintf(WIFI,"AT+FAPSTA=on\r");
WFHasWritten=1;
break;

//fprintf(WIFI,"AT+NETP\r");
//delay_ms(20);
//readCharCFG();
//fprintf(WIFI,"AT+UART\r");
//readCharCFG();

//delay_ms(20);

//delay_ms(20);
//fprintf(WIFI,"AT+WMODE=STA\r");



case 2:
fprintf(WIFI,"AT+WMODE=STA\r");
//WIFI_APSTA(1);

WFHasWritten=1;
break;


case 3:
WIFI_STA_SSID();
//WIFI_APSTA(1);

WFHasWritten=1;
break;



case 4:
WIFI_STA_KEY();

WFHasWritten=1;
break;





//VacSetXY(1,2);

case 5:
delay_ms(2000);
fprintf(WIFI,"AT+WAP=11BGN,OSMOBOT_AP,AUTO\r");
//WFSetupState++;
//WFHasWritten=1;
break;

case 6:
fprintf(WIFI,"AT+WAKEY=WPAPSK,AES,osmopass!\r");
WFHasWritten=1;
//WFSetupState++;
break;
//readCharCFG();

//VacSetXY(1,3);

//readCharCFG();


case 7:
#if USETCPB
fprintf(WIFI,"AT+NETP=TCP,SERVER,8899,10.10.100.254\r");
#else
//fprintf(WIFI,"AT+NETP=TCP,CLIENT,80,osmobot.org\r");
#endif

WFHasWritten=1;
//WFSetupState++;
break;

case 8:
fprintf(WIFI,"AT+TCPTO=3\r");
WFHasWritten=1;
//WFSetupState++;
break;




case 9:

#if USETCPB
fprintf(WIFI,"AT+TCPB=on\r");
WFHasWritten=1;
//WFSetupState++;

#else
fprintf(WIFI,"AT+TCPB=off\r");
WFHasWritten=1;

#endif

break;

case 10:
#if USETCPB
fprintf(WIFI,"AT+TCPPTB=80\r");
WFHasWritten=1;
#else
WFSetupState=13;
#endif


//WFSetupState++;
break;

case 11:
fprintf(WIFI,"AT+TCPADDB=osmobot.org\r");
WFHasWritten=1;
//WFSetupState++;
break;

case 12:
fprintf(WIFI,"AT+TCPTOB=5\r");
WFHasWritten=1;
//WFSetupState++;
break;

case 13:
//fprintf(WIFI,"AT+WSCAN\r");
//WFHasWritten=1;
WFSetupState++;
break;


case 14:
WIFI_reset();
delay_ms(5000);
VacDisplayClear();
WFSetupState=0;
WFIsConfig=1;
USEAT=0;
//WFSetupState++;
break;

case 15:
WFSetupState=0;
WFIsConfig=1;
USEAT=0;
VacDisplayClear();
ROUTERHOLD=1;
delay_ms(5000);
break;

//readCharCFG();
	}
	}
}


void WIFI_CONFIG_ROUTER_SETTINGS()
{

char cntrstr[4];
static int8 WFSetupState=0;
static int1 WFHasWritten=0;
static int16 jankycntr=0;
while(WFSetupState<4)
{
USEAT=1;
	if(ATisOK==1)
	{
	ATisOK=0;
	WFSetupState++;
	WFHasWritten=0;
	#if WFSETUPDEBUG
	delay_ms(5000);
	VacDisplayClear();
	#endif
	}
	else
	{
	jankycntr++;
	}

	if(jankycntr>=100)
	{
	jankycntr=0;
	WFHasWritten=0;	
	}

sprintf(cntrstr,"%d%d%d-%LD",WFSetupState,ATisOK,WFHasWritten,jankycntr);
Display_XYString(12,1,cntrstr);

switch(WFSetupState)
{
	case 0:
	WIFI_enter_setup();
	delay_ms(30);
	fprintf(WIFI,"AT+E=off\r");
	WFHasWritten=1;
	//WFSetupState++;
	break;
	
	case 1:
	WIFI_STA_SSID();
	
	WFHasWritten=1;
	break;



	case 2:
	WIFI_STA_KEY();
	
	WFHasWritten=1;
	break;

	case 3:
	WIFI_reset();
	VacDisplayClear();
	WFSetupState=0;
	USEAT=0;
	//WFSetupState++;
	break;

	case 4:
	break;
	}

}
}




void scanForRouters(int rst)
{
char dispBuff[20];

static int scanState=0;
static int wroteCmd=0;

if(SCANERROR>0)
{
delay_ms(1000);
scanState=1;
wroteCmd=0;
SCANERROR=0;
}


switch(scanState)
{

//Enter Config Mode
case 0:
delay_ms(50);
	while (xReadyWiFi())
		{
		delay_ms(100);
		}
WIFI_enter_setup();
delay_ms(50);
ROUTERSCANING=1;
delay_ms(50);
scanState++;
break;

//Start The Scan
case 1:
if(wroteCmd==0)
{
fprintf(WIFI,"AT+WSCAN\r");
wroteCmd=1;
}
if(ROUTERSCANING==0)
{
scanState++;
wroteCmd=0;
}



break;

//Reset The module
case 2:
WIFI_reset();
delay_ms(500);
ROUTERHOLD=0;
scanState=0;
resetParsing=1;
break;

default:
scanState=0;
break;


}
sprintf(dispBuff,"Scan,%d,%d,%d"scanState,ROUTERSCANING,ROUTERHOLD);

Display_XYString(0,3,dispBuff);
}



void setClient()//Configures WIFI module to be server
{
WIFI_enter_setup();
delay_ms(1000);
fprintf(WIFI,"AT+NETP=TCP,CLIENT,80,osmobot.org\r");

delay_ms(7000);
	WIFI_reset();
	VacDisplayClear();
clientOrServer=CLIENT;
}


void setServer()
{
WIFI_enter_setup();
delay_ms(1000);
fprintf(WIFI,"AT+NETP=TCP,SERVER,8899,10.10.100.254\r");
delay_ms(7000);
	WIFI_reset();
	VacDisplayClear();
clientOrServer=SERVER;
}