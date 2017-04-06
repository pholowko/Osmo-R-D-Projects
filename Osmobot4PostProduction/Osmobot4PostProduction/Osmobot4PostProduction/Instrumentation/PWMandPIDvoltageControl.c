//*********************************************************************************
// Created March 28, 2013
// This routine sets up the ADC converter for read in 10 bit ADC converstions for
//  the feed back voltage from the PWM.
//  The returned value is the raw ADC averaged reading.
//  40 samples are read and averaged.
//*********************************************************************************
int16 readNixieADC(int selection)
	{
	int16 ReturnedADC, Summer;	
	int f;
					set_adc_channel(selection); 
					Summer=0;
					for (f=0; f < 40; f++)
						{
					delay_us(4);
					Summer = Summer + read_adc(); // Read adc channel 0 
						}
					ReturnedADC = Summer/40;
	return(ReturnedADC);	
	}


//*********************************************************************************
// Created March 28, 2013
// This routine calcaultes the voltage from the incomping ADC reading.
// Voltage is calculated from the resistance values in the circute
// Current is also calculated.
// The returned value is the voltage passing across the reisistor.
float FindTubeVoltage(int selection)
	{
	float t;
	t=5 + 1.185*readNixieADC(selection);
	return(t);
	}


