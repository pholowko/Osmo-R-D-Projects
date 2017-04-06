
//***********************************************************
//•n is an offset into the eeprom. 
//•For example if the first float is at 0 the second 
//•For floats you must increment it by 4. 
//•one should be at 4 and the third at 8. 
//***********************************************************

WRITE_FLOAT_EXT_EEPROM(long int n, float data) { 
   int i;

   for (i = 0; i < 4; i++) 
      write_eeprom(i + n, *((int8*)&data + i) ) ; 
}

float READ_FLOAT_EXT_EEPROM(long int n) { 
   int i; 
   float data;

   for (i = 0; i < 4; i++) 
      *((int8*)&data + i) = read_eeprom(i + n);

   return(data); 
}


//********************************************************************
// Created Nov. 8, 2012
//  This routine turns on and off the water pump.
//  A zero turns the pump off; a 1 turns it on.
//********************************************************************
void WaterPump(int state)
	{

char buffer[40];  //This sets the string area for the display.
	if (state)
		{
		output_high(PIN_B0);   //This sets the SSR or what whatever to be on.  It's supposed to be the pump.
        sprintf(buffer,"Pump On  ");
		WriteString(buffer,1,4);   //Send the message to the display
		}
		else
		{
		output_low(PIN_B0);   //This turns off the pump.
        sprintf(buffer,"Pump Off ");
		WriteString(buffer,1,4);   //Send the message to the display
		}
	}	



//*********************************************************************
// Created Nov. 8, 2012
//  This routine turns on the water pump when the Solar collector is greater than the spread temperature
//  above the current water temperature.
//  The SpreadTemp is the temperature difference between the water and the solar before it turns on the pump.
//  The same goes for the lower end to cool the water.
//*********************************************************************
void CheckTemperatureControl(void)
	{

//For the pump to turn on, the solar needs to be greater by SpreadTemp
//For the pump to turn off at the heating end, the tank temp needs to be greater by the hysitrisis.
// For a pump to turn on, the current temperature in the water needs to be at least the spread.
//For the pump to turn off, it needs to be within the spread.

//	hysteresis
//SpreadTemp
//UpperSetPoint
//ADCValueSolar
//ADCValueTank
//LowerSetPoint

//ADCValueTank = 10.3;
//ADCValueSolar = 25.4;


		if (((ADCValueTank + SpreadTemp) < ADCValueSolar) && pump == 0)
			{
			WaterPump(1);   //Turn on pump.
			pump = 1;
			return;
			}
		if (((ADCValueTank + SpreadTemp) > (ADCValueSolar + hysteresis)) && pump == 1)
			{
			WaterPump(0);   // Turn off pump.
			pump = 0;
			return;
			}

	}