#include <18F4550.h>
#DEVICE ICD=TRUE
#device ADC=10
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <STDIO.h>

#define SDAPIN PIN_B0
#define SCLPIN PIN_B1

#define ADCREZ 1024

char adcBuff[20];

char rcv_buffer[255];
unsigned  int8 streamCntr=0; 
unsigned  int8 dispCntr=0;
int1 writeReady=0;
unsigned  int8 xCntr=0;
unsigned  int8 yCntr=0;
int32 clk = 0;
#fuses  HS, NOWDT, NOLVP, NOBROWNOUT, NOPROTECT, PUT 
#use delay(crystal=20000000, clock=20000000)

#use I2C(SLAVE,sda=SDAPIN,scl=SCLPIN, address=0xa0,SLOW)
//#use i2c(SLAVE, I2C1, address=0xA0)






#include <CU20045SCPB-U1J.c>



//GPIO Initialization
#USE STANDARD_IO(d)
#USE STANDARD_IO(e)


typedef struct inputDataStruct{
unsigned int8 chksum;
unsigned int8 hour;
unsigned int8 minute;
unsigned int8 second;
unsigned int8 day;
unsigned int8 month;
unsigned int16 year;
unsigned int1 io1;
unsigned int1 io2;
unsigned int1 io3;
unsigned int8 uploadinterval;   //This is the upload time interval  It's default to 2 minutes for now.
float eccal1x;    //  This the EC data point  Added July 18, 2016
float eccal2x;    //  This the EC data point  Added July 18, 2016
float eccal3x;    //  This the EC data point  Added July 18, 2016
float eccal1y;    //  This the EC data point  Added July 18, 2016
float eccal2y;    //  This the EC data point  Added July 18, 2016
float eccal3y;    //  This the EC data point  Added July 18, 2016
char unittype[5];  // This is a string of no more than 5 characters to describe the unit type.  Needs to end with a null.
float phcallow;       //  This is the lower ADC value count.  It is assocatred always with a pH of 4.  The default is 275.
float phcalhigh;       //  This is the ADC value used to associate with the phnumberupper.  The default is 500, but it can change.
float phnumberupper;    // this is the upper variable pH number.  the default is 10, but it can change
}inputData;
inputData sysInput;


#INT_SSP
	void ssp_interrupt(){

unsigned int8 state=i2c_isr_state();

		if(state==0){
			char sestICD=i2c_read();
			//writeChar('a');
//			i@c_read();
		}
		if(state==0x80)
		{
			i2c_read(2);
			//writeChar('b');
		}
		if(state>=0x80){
		//	i2c_write(send_buffer[state-0x80]);
		//	writeChar('c');
		}
		else if(state>0){
	//	rcv_buffer[state-1] = i2c_read();
		rcv_buffer[streamCntr]= i2c_read();
		streamCntr++;
	//	writeReady=1;
		//writeChar('d');
		}	

	}

//***********************************************************************
//Created September 26, 2016
// This routines returns the calucated pH from the given system inputs and of the calibration derived from the server.
// It returns a float
//***********************************************************************
float CalculatepH(float ADCNumber)
{
    
    float mm,b,result;
    
    mm = (sysInput.phnumberupper - 4.0)/(sysInput.phcalhigh - sysInput.phcallow);
    //y = mx +b
    // find b
    // b = y - mx
    b = sysInput.phnumberupper - mm*sysInput.phcalhigh;
    result = ADCNumber*mm + b;
    
    
    
    return(result);
}
    
    

//*********************************************************************
// Created July 15, 2015
// Splash screen for 1 second before going into the main loop;
//  Give Version, credit to Erik and Paul
// Provide Version Date
//*********************************************************************
void splash(void)
	{
    clearDisplay();
char teststr4[20]="Ver 1.0 9/26/16";
char teststr1[20]="pH Bulb Tester";
char teststr2[20]=" ";
char teststr3[20]=" ";
writeString(0,0,teststr1);
writeString(0,1,teststr2);
writeString(0,2,teststr3);
writeString(0,3,teststr4);
delay_ms(2000);
    clearDisplay();
	}




int1 parseChar(char vala){
char tempBuff[2];

int1 newLine=0;
////////OLD
/*
	writeChar(val);
	dispCntr++;
	writeReady=0;
*/

if(vala==10)
	{	
	xCntr=0;
	yCntr++;
	newLine=1;
	}
else{
writeCharPos(xCntr,yCntr,vala);
xCntr++;
	}
return newLine;
}



int16 GetADCValue(int selection)
	{
	int16 ReturnedADC, Summer;	
	int f;
					//setup_adc(ADC_CLOCK_INTERNAL);  //Setup the ADC to run..
					set_adc_channel(selection); 
                    //		delay_ms(10);
					Summer=0;
					for (f=0; f < 32; f++)
						{
					//delay_us(10);
					Summer = Summer + read_adc(); // Read adc channel 10 
						}
					ReturnedADC = Summer>>5;
	return(ReturnedADC);	
	}



//*****************************************************************
// Created May 19, 2016
// This takes a sampling of the pHBulb and averages them all together.
// The result is the raw data from the ADC.  In this case it is connected to AD7
// It returns a float
//****************************************************************

float ConvertADCTophBulb(void)
	{
int16 ReturnedADC;
int x;
float tempfloater, tempsummer;
tempsummer = 0.0;
for (x=0; x < 10; x++)
    {
    
   // fprintf(BT,"Getting Reading %f\r\n",tempfloater);
	ReturnedADC = GetADCValue(0);  //This gets the current ADC conversion for the channel number.

  tempfloater = (float) ReturnedADC;
    tempsummer = tempsummer + tempfloater;
    
    }
    tempfloater = tempsummer / 10.0;
	return(tempfloater);
	}



void main(void){
i2c_init(TRUE);


int8 adcStrCntr;


sysInput.phcallow = 67;
sysInput.phcalhigh = 1+03;
sysInput.phnumberupper = 10;


initDispIO();
initDisplay();

splash();

 // enable_interrupts(GLOBAL);
 // enable_interrupts(INT_SSP);


  setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel( 0 );


while(1)
{


//unsigned int16 adcVal=read_adc();
float adcVal = ConvertADCTophBulb();
float voltage = (5*(float)adcVal/ADCREZ);
//sprintf(adcBuff, "GVM:%6lu Volts",adcVal);


float ph = CalculatepH(adcVal);   // enter the adc and make a ph value
sprintf(adcBuff, "ph = %3.2f",ph);
adcStrCntr=0;

while(adcBuff[adcStrCntr]!= '\0')
{
writeCharPos(adcStrCntr,2,adcBuff[adcStrCntr]);
adcStrCntr++;
}
sprintf(adcBuff, "%3.2f Volts %f",voltage,adcVal);
adcStrCntr=0;

while(adcBuff[adcStrCntr]!= '\0')
{
writeCharPos(adcStrCntr,3,adcBuff[adcStrCntr]);
adcStrCntr++;
}

}




}


