// This file contains routines to multiplex and set up the paths for the I2C and the PWM to talk with sensors and LEDs

//************************************************************************
// Created December 2, 2015
// This routine sets up the ports for the sensors and PWM drivers
// There is nothing returned.
// It needs to be called at the beginnging of booting.
// there are a total of six optical sensors
//************************************************************************
void intimultiplex(void)
	{

	int x,gainof,returnedversion;

	output_low(PIN_E0);   //This pin is connected to the A input of the 74139.  It picks the high and or the low end of the six sensors.
// The line below is the SCL for the I2C.  It does not need to be init for a bit output.
//#use i2c(stream=DO_Light, MASTER, sda=PIN_E7, scl=PIN_E6, FORCE_HW, SLOW)    // SDA3 
//	output_low(PIN_E6);   //This needs to be connected to the SCL for the I2C.


	output_low(PIN_B3);   // This is connected to the input for the A on both 74139 chips.
	output_low(PIN_B4);   // This is connected to the input for the B on both 74139 chips.

	//  a low on B3 and B4 will give the left most sensor.



	output_low(PIN_E3);   // This is the input to the selector for the PWM.  A
	output_low(PIN_E2);   // This is the input to the selector for the PWM.  B
	output_low(PIN_E1);   // This is the input to the selector for the PWM.  C


// This section also goes through all of the light at power up to make sure everything is working.
		pwm_set_duty(PH_PWM,0);	//250hz
/*
	while(1)
		{
		for (x=0; x < 6; x++)
			{
			returnedversion = getTAOSVersion(x);
        	fprintf(BT,"Sensor %i  Version Number -> %i\n\r",x,returnedversion);
			}
		}

*/

	InitTAOS();
    fprintf(BT,"\r\n");


	for (x=0; x < 6; x++)
		{
		selectsensor(x);
		pwm_set_duty(PH_PWM,200);	//250hz
		delay_ms(250);
        
		gainof = GetCurrentColor(4, x);
		sysOutput.lLevelRed=red;
		sysOutput.lLevelGreen=green;
		sysOutput.lLevelBlue=blue;
		sysOutput.lLevelClear=clear;
		sysOutput.lLevelScale=gainof;

		fprintf(BT,"Sensor  %i  -> Red %Lu\r\n",x,red);

		pwm_set_duty(PH_PWM,0);	//250hz
		}

	}



//***************************************************************************
// Created December 2, 2015
// This routine sets the encoder to select where the I2C clock signal goes to.
// It returns nothing.
// The input is number for 0 to 5;  each one selecting a sensor.
//***************************************************************************
void selectsensor(int sensornumber)
	{

	if (sensornumber > 3)   // Set the high bit
		{
		output_high(PIN_E0);
		output_high(PIN_E1);   // This is the input to the selector for the PWM.  C

		sensornumber = sensornumber - 4;    // Remove the offset so the bottom part of the byte can be accessed
		}
		else
		{
		output_low(PIN_E0);
	    output_low(PIN_E1);   // This is the input to the selector for the PWM.  C
		}

	if (sensornumber == 0)   // Set the lower bits.
		{
		output_low(PIN_B3);   // This is connected to the input for the A on both 74139 chips.
		output_low(PIN_B4);   // This is connected to the input for the B on both 74139 chips.


		output_low(PIN_E3);   // This is the input to the selector for the PWM.  A
		output_low(PIN_E2);   // This is the input to the selector for the PWM.  B


		}

	if (sensornumber == 1)
		{
		output_high(PIN_B3);   // This is connected to the input for the A on both 74139 chips.
		output_low(PIN_B4);   // This is connected to the input for the B on both 74139 chips.

		output_high(PIN_E3);   // This is the input to the selector for the PWM.  A
		output_low(PIN_E2);   // This is the input to the selector for the PWM.  B


		}
	if (sensornumber == 2)
		{
		output_low(PIN_B3);   // This is connected to the input for the A on both 74139 chips.
		output_high(PIN_B4);   // This is connected to the input for the B on both 74139 chips.
	
		output_high(PIN_E3);   // This is the input to the selector for the PWM.  A
		output_high(PIN_E2);   // This is the input to the selector for the PWM.  B
		}
	if (sensornumber == 3)
		{
		output_high(PIN_B3);   // This is connected to the input for the A on both 74139 chips.
		output_high(PIN_B4);   // This is connected to the input for the B on both 74139 chips.

		output_low(PIN_E3);   // This is the input to the selector for the PWM.  A
		output_high(PIN_E2);   // This is the input to the selector for the PWM.  B


		}

	}





