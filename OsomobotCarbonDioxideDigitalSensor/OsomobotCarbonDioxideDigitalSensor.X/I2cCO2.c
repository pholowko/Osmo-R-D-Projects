

//****************************************************************************************
// Added Jan 24, 2012
// This is a file for all the routines to connect with a CO2 K-30 sensor.
//The changes below are for the internal sensor inside the CELSS system.
//****************************************************************************************

//#define DATACO2  PIN_A2    /*set DATACO2 to PortA1 and SCKCO2 to portA2*/ //Old ones
//#define SCKCO2   PIN_A1     // Old ones

//#define DATACO2  PIN_B2    /*set DATACO2 to PortB3 and SCKCO2 to portB2*/ 
//#define SCKCO2   PIN_B3    //This is set up for BioSphere2  Added June 20, 2013

#define DATACO2  PIN_B11    /*set DATACO2 to PortB3 and SCKCO2 to portB2*/ 
#define SCKCO2   PIN_B10    //This is set up for BioSphere2  Added June 20, 2013

//****************************************************************************************
// Added Jan 28, 2012
// This routine is used to send the timing for reading one Byte of data from the I2c.
//****************************************************************************************
BYTE CO2ReadByte(void)
{

  int i;
	BYTE lVal1;   //Add September 3, 2012.  This def needed to be added.
   long lTmp,lValue;
	lVal1=0;
   output_low(SCKCO2);
   delay_us(5);
	output_float(DATACO2);
   for (i=0; i<8; i++)         //Read CO2 sensor without ACK.
	   {
		lVal1<<=1;
    	output_high(SCKCO2);  //Clock High is when the data is legal.
    	delay_us(10);
    	lTmp = input(DATACO2);
   	    delay_us(10);
    	output_low(SCKCO2);
    	delay_us(10);
    	if (lTmp) lVal1|=1; 
   		} 
		output_low(DATACO2);
 		delay_us(5);
    	output_high(SCKCO2);  //Clock High is when the data is legal.
 		delay_us(5);
    	output_low(SCKCO2);
		delay_us(5);
	    output_float(DATACO2);
		delay_us(5);

return(lVal1);
}


void CO2SendStopBit(void)
//****************************************************************************************
// Added Jan 28, 2012
// This routine sends a start bit only.
//Starting with the clock and data lines low for data SDA change.  
//Leaving Data lines  high.
//****************************************************************************************
{

	output_high(DATACO2);
    delay_us(6);
    output_high(SCKCO2);
    delay_us(6);
	output_low(DATACO2);
    delay_us(10);
	output_high(DATACO2);
	
}


//****************************************************************************************
// Added Jan 28, 2012
// This routine is used to send the timing to send one Byte of data to the CO2 sensor.
//This routines makes about 10 attempts of writing one byte of data with ACK.  If the ACk is not present, then it tries again until 10 times are up.
//The routine returns a 0 ieverything is OK, it returns a 1 if it failed.
//This routines assumes a startbit has occured.
//****************************************************************************************
int CO2WriteByte(BYTE command)
{

int i,ii;
int lTmp;
int state;
//Make sure the start bit is active.
// All data lines are coming in Low

	//Setup first bit of data to write.

//for (ii=0; ii<10; ii++)  //loop through 10 tries
//****************************************************************
//Added 2/13/2012
//*  data is sent to the CO2 sensor in a backwards way.  For instance the command address 0x68 is b01101000.  The LSB is send firt and the last bit is the MSB.  
//*  The wave form looks like   b00010110.  All numbers are like that for the CO2 sensor.
//*  To receive data from the CO2 sensor.
//*   Master Transmit:
//*   <68> <04> <00> <03> <00> <01> <C8> <F3>      
//*  This means 
//*  0x68 is the command.  In the I2C world this needs to be shifted to 0xD0  or  0x68 = b01101000 to 11010000  padded 0 shift left. 
//*  0x04 is the register
//*  0x00 and 0x03 is the register.  It is sent in this order.
//*  0x00 and 0x01 is the number of bytes read back in this case 2.
//*  The last two are the check Sum where the LSByte is send first and the high one last.
//*  All data is reversted.


//*   Slave Reply:
//*   <68> <04> <02> <03> <01> <24> <09>   This gives the nuimger of 0x301 ppm.

//{
   output_low(SCKCO2);
   delay_us(5);
	ii = 0x80;
   for (i=1; i<=8; i++)
   {if (ii & command) 
		{
		output_high(DATACO2);
		}
    else 
		{ 
		output_low(DATACO2);
		}	
		ii/=2;  
		  delay_us(10); 
          output_high(SCKCO2);
          delay_us(10);
          output_low(SCKCO2);
      }  
 delay_us(7);
  output_float(DATACO2);
   delay_us(7);
          output_high(SCKCO2);
          delay_us(10);
 
        //  output_low(SCKCO2);
	//	  delay_us(10);

 //  output_high(SCKCO2);

 state = 0;
	lTmp=input(DATACO2);   //Check to see if the Data line is high.  Low means sensor can take a command.  A Low means sensor is not ready.
if(lTmp != 0)
		{
		state = 0;  //This means the device is not ready.
//		CO2SendStopBit();
		}
		else
		{
		state = 1;  //This means the device is ready or ACK worked
		//break;
		} 
output_low(SCKCO2);

output_high(DATACO2);

//start to setup stop bit if needed or loop back and do it again.
//	output_low(DATACO2);
	
 //   delay_us(10);
//}


return(state);   //If it returns a 0, then is failed.  If it reutrns a 1, it worked.
}








void CO2SendStartBit(void)
//****************************************************************************************
// Added Jan 24, 2012
// This routine sends a start bit only.
//Leaving the clock low for data SDA change.  
//Leaving Data high.
//This routine assumes all lines are high for a while.
//****************************************************************************************
{
  output_high(SCKCO2);
   output_high(DATACO2);
	delay_ms(20);
  output_low(DATACO2);   //High to low on the data line  Start Condition
	delay_us(10);

}




int WakeUpCO2Sensor(void)
//****************************************************************************************
//  Added Jan 24, 2012
//This wakes up the CO2 scensor and then keeps the clock going until the first command
// can be set to the CO2 Sensor.
//****************************************************************************************

{


int lTmp;
int state;


CO2SendStartBit();
lTmp=CO2WriteByte(0xFE);  //This is a test wakeup.

CO2SendStopBit();

	
	return(lTmp);
}	
	
//int ReadCOSensor(BYTE &ReturnedReadSuccess, BYTE &data1, BYTE &data2, BYTE &CheckSum)
int16 ReadCOSensor(void)
//******************************************************************************************
// Added Jan 24, 2012
// This routine sends the sequence of bytes to the CO2 device and then waits for the return data line to go low.
//  At the time, the program starts to read the data coming back from the CO2.
//******************************************************************************************

	{
int16 lTmp;	
int i,lTmp2;
BYTE first,second,third,forth, checksum;


lTmp = 0;
CO2SendStartBit();
//lTmp=CO2WriteByte(0x7E);  //This Sensor address  that is 0x68  shifted left one with a zoer padded   0b01101000  -> 0b11010000
lTmp=CO2WriteByte(0xD0);  //This Sensor address  that is 0x68  shifted left one with a zoer padded   0b01101000  -> 0b11010000
if (lTmp == 1)
	{
	lTmp = 0;
	lTmp=CO2WriteByte(0x22); 
	if (lTmp == 1)
		{
		lTmp = 0;
		lTmp=CO2WriteByte(0x00); 
		if (lTmp == 1)
			{
			lTmp = 0;
			lTmp=CO2WriteByte(0x08); 
			if (lTmp == 1)
			{	
				lTmp = 0;
				lTmp=CO2WriteByte(0x2A); 
				if (lTmp == 1)
				{	
					lTmp = 5; 
					}
				}
			}
		}
	}
  
CO2SendStopBit();

if (lTmp == 5)
	{

delay_ms(10);  //Wait for sensor to come back with numbers and then send command.

//******************************************************************************
//Added Feb 13, 2012
//This part waits for a start bit from the Slave.
//******************************************************************************
//Slave Reply:
//*   <68> <04> <02> <03> <01> <24> <09>   This gives the nuimger of 0x301 ppm.
lTmp=0;
CO2SendStartBit();
lTmp=CO2WriteByte(0xD1);  //This Sensor address  that is 0x68  shifted left one with a zoer padded   0b01101000  -> 0b11010000


 	if (lTmp == 1)
		{
		first = CO2ReadByte();
		second = CO2ReadByte();
		third = CO2ReadByte();
		forth = CO2ReadByte();
		CO2SendStopBit();
		lTmp = lTmp+1;
		}
		else    //This is the else command for writing succesyy the first read command
		{
		CO2SendStopBit();
		lTmp = -1;
		return(lTmp);  //If is does not work, then return failed.
		}
	}
	else    //This is the else command for writing succesyy the first read command
	{
	CO2SendStopBit();
	lTmp = -1;
	return(lTmp);  //If is does not work, then return failed.
	}
//******************************************************
//Added Oct. 11, 2012
//This section does a checksum of the returned three values and tells the calling routine if the data
// is valid or returns the new CO2 measurement.
//******************************************************

checksum = first + second + third;
if ((checksum == forth) & (first == 0x21))
	{
//This sectoin agress that check sum is OK
//Added Oct 11, 2012
// Second is the upper part of the integer. 
    lTmp = second;
	lTmp = lTmp * 256;
	lTmp = lTmp + third;
	}
	else
	{
	lTmp = -1;  // This routines an error if the check sum does not come out.
	}
return(lTmp);
}


void CalibrateCO2(void)
//******************************************************************************************
// Added Jan 24, 2012
// This routines start the CO2 device to do a background CO2 calibration.  This routine is used once a month for
// now.  How to use this program is TBD.
//******************************************************************************************
{




}


void InitCO2(void)
//******************************************************************************************
// Added Jan 26, 2012
// This routine sets up the two control bits for output.
//******************************************************************************************
{
   output_high(DATACO2);
	output_high(SCKCO2);

}


