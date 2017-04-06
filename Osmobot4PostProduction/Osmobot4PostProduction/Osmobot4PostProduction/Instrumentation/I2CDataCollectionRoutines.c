


#include<config.h>
#include <sht11.h>

BYTE buffer[0x20];

//**************************************************************************************
// Added 12/31/2011
//  This reads the RH from the SHT11 Humidity & Temperature Sensor
//  This reads the temperature from the i2c SHT11 .
// This routine returns the T and RH in global variables.
//**************************************************************************************




//**************************************************************************************
// The SHT11 is set to 12bit mode. 
// Formula for RH from the  chip.
// RH_linear = C1 + C2*SORH + C3*SORH^2
//  C1 = -4, C2 = 0.0405, C3 = -2.8X10^-6
// Compensation for Temperature
// RH_True = (T in C - 25)*(t1 + t2*SO_RH) + RH_linear
// t1 = 0.01, t2 = 0.00008
//
// Temperature formula from sensor
// Temperature = d1 + d2*SO_T
// d1 = -40.00, d2 = 0.04.  All temps are in degrees C
//
// Dewpoint Calculations
// See Data sheets.  Needs LOG math fucntion.
//*************************************************************************************


void sht15_send_byte (unsigned int sht15_command)
{
//	 int i;

//	for(i = 0x80 ; i > 0 ; i/=2) 
//		{
//		if (i & 0x05) 
//			{
//			output_high(PIN_B0);
//			}
  //    	else 
//			{ 
//			output_low(PIN_B0);
//			}
  //    	delay_us(10); 
	//	output_high(PIN_B1);
//      	delay_us(10); 
//		output_low(PIN_B1);
  //} 
//Do the Ack.
//   	output_float(PIN_B0);  delay_us(10);
   	output_high(PIN_B1);    delay_us(10);
   	output_low(PIN_B1);     delay_ms(100);
}

/*SHT11 Transmission Start Sequence*/
void sht1x_xmission_start()
{
	output_high(DATA);
	output_low(SCK);
	delay_us(2);
 	output_high(SCK);
	delay_us(2);
	output_low(DATA);
	delay_us(2);
 	output_low(SCK);
	delay_us(2);
	delay_us(2);
	delay_us(2);
 	output_high(SCK);
	delay_us(2);
 	output_high(DATA);
	delay_us(2);
 	output_low(SCK);
	delay_us(2);
}

/*SHT11 Connection Reset Sequence*/
void sht11_connection_reset()
{  int i;

   output_high(PIN_B0);
   for (i=0; i<9; i++)
   {output_high(PIN_B1);
    delay_us(2);
    output_low(PIN_B1);
    delay_us(2);}
   sht1x_xmission_start();}

/*SHT11 Address & Command Mode with address=000*/
void sht11_command_mode(int iMode)
{
   int i;
   for (i=128; i>0; i/=2)
   {if (i & iMode) output_high(DATA);
    else  output_low(DATA);
          delay_us(2);
          output_high(SCK);
          delay_us(2);
          output_low(SCK);}

   output_float(DATA);
   delay_us(2);
   output_high(SCK);
   delay_us(2);
   output_low(SCK);
   
   /*delay >55ms for 12-bit measurement*/
   /*delay >210ms for 14-bit measurement*/
   delay_ms(250);  /*250ms is chosen as delay time*/
}

/*SHT11Soft Reset - resets the interface, clears the status register to default values*/
/*wait minimum 11ms before next command*/
void sht11_soft_reset()
{
  sht11_connection_reset();
  sht11_command_mode(RESET);
}
// read data from SHT11 and store
long sht1x_read_data()
{  int i;
   long lTmp,lValue;
	lVal1=0;
	lVal2=0;

   for (i=0; i<8; i++)          /*get MSB from SHT11*/
   {lVal1<<=1;
    output_high(SCK);
    lTmp = input(DATA);
    delay_us(2);
    output_low(SCK);
    delay_us(2);
    if (lTmp) lVal1|=1; 
   } 
   output_low(DATA);   /*acknowledge routine*/
   delay_us(2);
   output_high(SCK);
   delay_us(2);
   output_low(SCK);
   output_float(DATA);
   delay_us(2);

   for (i=0; i<8; i++)          /*get LSB from SHT11*/
   {lVal2<<=1;
    output_high(SCK);
    lTmp = input(DATA);
    delay_us(2);
    output_low(SCK);
    delay_us(2);
    if (lTmp) lVal2|=1;
   }
   lValue = make16(lVal1,lVal2);
   return(lValue);
    }

// SHT1x Connection Reset Sequence
void sht1x_connection_reset()
{  int i;
   output_high(DATA);
   for (i=0; i<9; i++)
    {
	output_high(SCK);
	delay_us(2);
	output_low(SCK);
	delay_us(2);
	}
    sht1x_xmission_start();
}

// SHT1x Address & Command Mode with address=000
void sht1x_command_mode(int iMode)
{  int i;
   for (i=128; i>0; i/=2)
   {  if (i & iMode) 
		{
		output_high(DATA);
		}
      else  
		{
		output_low(DATA);
		}
      	delay_us(2); 
		output_high(SCK);
      	delay_us(2); 
		output_low(SCK);
   }
   output_float(DATA);  
	delay_us(2);
   output_high(SCK);    
	delay_us(2);
   output_low(SCK);     
	delay_ms(400);
}


// read DATA_SHT from SHT1x and store
long sht1x_read_DATA_SHT()
{  int i;
   long lTmp;
   long lVal1=0;
   long lVal2=0;
   long lValue;
   // get MSB from SHT1x
   for (i=0; i<8; i++)
   {
      lVal1<<=1;
      output_high(SCK);
      lTmp = input(DATA);
      delay_us(2);
      output_low(SCK);
      delay_us(2);
      if (lTmp) lVal1|=1;
   }
   // acknowledge routine
output_low(DATA); 
delay_us(2);
output_high(SCK); 
delay_us(2);
output_low(SCK);
output_float(DATA);
delay_us(2);
   // get LSB from SHT1x
   for (i=0; i<8; i++)
   {
      lVal2<<=1;
      output_high(SCK);
      lTmp = input(DATA);
      delay_us(2);
      output_low(SCK);
      delay_us(2);
      if (lTmp) lVal2|=1;
   }
   lValue = make16(lVal1,lVal2);
   return(lValue);
}

// calculate dewpoint
float sht1x_calc_dewpoint(float h,float t)
{
float logEx,dew_point;
logEx=-2+0.66077+((7.5*t)/(237.3+t))+log10(h);
dew_point = (logEx - 0.66077)*237.3/(0.66077+7.5-logEx);
return dew_point;
}


 void read_sht11()
{
	  sht1x_connection_reset();
      delay_ms(12);
      sht1x_xmission_start();
      sht1x_command_mode(MEASURE_TEMP);
      lValue_temp = sht1x_read_data();

	  fTemp_true = ((0.01*lValue_temp) - 40.0);  //This is the formala from the manual


      delay_ms(12);

      sht1x_xmission_start();

      sht1x_command_mode(MEASURE_HUMI);
      lValue_rh = sht1x_read_data();


 	  if((lValue_temp==65535)||(lValue_rh==65535))
       {sht1x_connection_reset();}
       else
		{
	  delay_ms(12);

	//  fRh_lin = ((0.0405*lValue_rh) - (0.0000028*lValue_rh*lValue_rh)- 4.0);  //This is the formala from the manual 	

      fRh_lin = (C1+(C2*lValue_rh)+(C3*lValue_rh*lValue_rh));
      fRh_true = (((fTemp_true-25)*(T1+(T2*lValue_rh)))+fRh_lin);
      fDew_point = sht1x_calc_dewpoint(fRh_true,fTemp_true);
      delay_ms(1000);  
  }   
}