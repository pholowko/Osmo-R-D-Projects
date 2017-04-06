//***********************************************************************
// Created Augest 27, 2015
// This routine measures the DO by decay.  The input is a phototrnasistor where it
// watches for the edge of Schmidt trigger on one of the inputs.  The system is 
//  cycled around 1 KHz.  An LED at around 500 nm is used to excit the patch and it watches for 
//  decay.  As O2 is less, the edge is longer.  As the DO is high, the edge comes quick.
//  The return value is the counters beteen cessing of excitation to the egde of the schmidt edge.
//  The number of counts for the cycle is input into the routine.
//  RD11 controls the 510 nm LED
//  RD0 is the input for the phototransisor.
//***********************************************************************
int GetDO(int numberofcounts)
	{
	int x;
// Set up ports
	output_low(PIN_D8);
//	output_float(PIN_D0);

	while(1)
		{
		
		for (x=0; x < numberofcounts; x++)
			{
	

			delay_us(1);


			}
		output_low(PIN_D8);
		for (x=0; x < numberofcounts; x++)
			{
	

			delay_us(1);


			}
		output_high(PIN_D8);
		}
	return(0);
	}