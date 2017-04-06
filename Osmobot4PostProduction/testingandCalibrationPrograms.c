void findPAR(void);
//*******************************************************************************
// Created March 2, 2016
// This routines shows the current WDepth.
//This is usec from the BT debugging routine.
//*******************************************************************************
void WDSensor(void)
{
  while(checkbtnumber(104))
	{  
      float junk;
      
    	junk = MeasureWaterDepth();
		fprintf(BT,"WD  = %f cm\n\r", junk);
    BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
		
  }
}

//********************************************************************************
// Created March 29, 2016
// this routine shows the current EC or TDS in the water.
// It is called from the BT command CAL EC
//*******************************************************************************
void TDSSensor(void)
{
  float junk;
  while(checkbtnumber(108))
	{  
   	junk =  measureTDS();
    fprintf(BT,"Total Dissolved Solids  = %f ppm\n\r", junk);
    BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	delay_ms(2000);   // delay some time between measurements.  Added May 31, 2016	
  }
}





//*********************************************************************************
// Created September 15, 2015
// This routine runs the real time caluclations for the water temperature readings.
//*********************************************************************************


void WTTempSensor(void)

	{
float stuff;   // General purpose variables

while(checkbtnumber(110))
	{

	stuff = WaterTemperature();

	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 

	fprintf(BT, "Current Water Temperature in C -> %f\n\r",stuff);

	}	

	}




//*********************************************************************************
// Created November 10, 2015
// This routine runs the real time caluclations for the PAR and raw light data readings.
//*********************************************************************************


void GetLastLightReading(void)

	{

while(checkbtnumber(111))
	{


	int	gainof;
	int exit = 0;   // exit loop.
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
	ExposureTimeTAOS(0,5);   //Set this exposure time to 12ms to help with max out gains.  Changed April 7, 2014

	ExposurescaleLight=0;
       gainof = GetCurrentColor(1, 5);   //This get the current reading off the harnis.

/*	
	do {

    gainof = GetCurrentColor(4, 5);   //This get the current reading off the harnis.

	if ((gainof == 0) && (red >= 65535) && (green >= 65535) && (blue >= 65535) && (ExposurescaleLight < 9))
		{
		exit = 0;
		ExposurescaleLight++;  // Kick the gain to the next level and measure again.
	//	setTAOSGain(gain,3); //Gain and then scale
		}
		else
		{
		exit = 1;  // Get out if it's just right.
		}

	}  while (exit == 0);


unsigned int32	scalingfactor = (unsigned int32) pow(2.0,(float) ExposurescaleLight);

	redABS = redABS * scalingfactor;
	greenABS = greenABS * scalingfactor;
	blueABS = blueABS * scalingfactor;
	clearABS = clearABS *  scalingfactor;

*/
       
       
    BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	fprintf(BT, "Current Red   -> %lx\n\r",redABS);
	fprintf(BT, "Current Green -> %lx\n\r",greenABS);
	fprintf(BT, "Current Blue  -> %lx\n\r",blueABS);
	fprintf(BT, "Current Clear -> %lx\n\r",clearABS);
	fprintf(BT, "Current ND    -> %lx\n\r\n\r",gainof);

	}	

	}


//*********************************************************************************
// May 19, 2016
//  This routine takes readings from the ph bulb if it is installed.  It then displays the raw and caulcated data.
//  Returns nothing
// Its used by the BT calling routines.
//********************************************************************************


void phbulbsensor(void)

	{
float stuff,stuff2;   // General purpose variables

while(checkbtnumber(105))
	{

	stuff = phBulb();

	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 
	BTBasicTest();   //Check BT 

	fprintf(BT, "pH Bulb data (raw) -> %f   (calculated) -> %f\n\r",stuff,stuff2);
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
	}	

}

//***********************************************************************************
// Added May 4, 2015
// This is the play section for debugging the SD card buffer program.
//  This sections needs to be removed of normal operation.
//***********************************************************************************

void DisplayRawpHData(void)
	{
	  InitTAOS();

while(checkbtnumber(103))
	{
	//	SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
		BTBasicTest();   //Check BT 


//while(1)
//	{
//	pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.
//	pwm_set_duty(DO_PWM,0x0000);	//Start at some number and move up or down from here.
//	delay_ms(200);

//Check the pH white light first.  Get the ambient light


	//sysOutput.pH = ReadpHAVG();  // call the pH reading averaging routine
	}
//	pwm_set_duty(DO_PWM,0);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0);	//250hz

	}






//***********************************************************************************
// Added Jan 19, 2016
// This is the play section for debugging the SD card buffer program.
//  This sections needs to be removed of normal operation.
//***********************************************************************************

void DisplayRawNH3Data(void)
	{
	  InitTAOS();

while(checkbtnumber(112))
	{
	//	SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
		BTBasicTest();   //Check BT 
		BTBasicTest();   //Check BT 
		BTBasicTest();   //Check BT 
		BTBasicTest();   //Check BT 
		BTBasicTest();   //Check BT 
        restart_wdt();   // restart the WD timer.  It set for 65 seconds
//Check the pH white light first.  Get the ambient light


//	sysOutput.nh3 = ReadNH3AVG();  // call the pH reading averaging routine
	}
//	pwm_set_duty(DO_PWM,0);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0);	//250hz

	}



//**************************************************************************
// Updated July 13, 2015
// This routine check all of the instermnations at the same time.  Make sure the harniess is plugged in.
//  This is thread number 101
//**************************************************************************


void RHTempSensor(void)

	{


int gino;      // General purpose variables
float  junk,junk2,junk3;   // General purpose variables
int16 gainof; 
int32 clearABSpH;

while(checkbtnumber(101))
	{
		SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
	    InitTAOS();
restart_wdt();   // restart the WD timer.  It set for 65 seconds

#ifdef TIRHTEMP

float returnedresultit,titemp;
    int returnedresult;
//*********************************************************************************
// Created Jan 17, 2017
// This calls and saves the current air temp and rh
//*********************************************************************************
 returnedresultit = GetHDC1080RHTemp(8);
   returnedresult = th;
   returnedresult = tl;
   titemp = (float) (th << 8 | tl);    
    titemp = titemp * 165.0 / 65536.0 - 40.0;
 sysOutput.aTemp = titemp;
  	if (sysOutput.aTemp < 0.0)
		sysOutput.aTemp = 0.0;
 
    returnedresult = hh;
   returnedresult = hl;
   titemp = (float) (th << 8 | tl);    
   titemp = titemp * 100.0 / 65536.0;
	sysOutput.rH = titemp;  //This is a float send into ta RH value.
	if (sysOutput.rH < 0.0)
		sysOutput.rH = 0.0;

#else

if (!GetTempRH())
	{
	sysOutput.aTemp = Temperature;  //This is the float temperature
	sysOutput.rH = RHData;  //This is a float send into ta RH value.
	}

#endif


	BTBasicTest();   //Check BT 
    BTBasicTest();   //Check BT 
    BTBasicTest();   //Check BT 
    BTBasicTest();   //Check BT 
	//	pwm_set_duty(PH_PWM,0x01FF);	//Start at some number and move up or down from here.
//	junk2 = ReadpHAVG();

		pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.
		gino = GetCurrentColor(4,1);
		junk3 = WaterTemperature();
        junk = MeasureWaterDepth();
	BTBasicTest();   //Check BT 
    BTBasicTest();   //Check BT 
    BTBasicTest();   //Check BT 
    BTBasicTest();   //Check BT 
  		fprintf(BT,"**********************************************************************************************\r\n");  
        fprintf(BT,"Unit Serial Number: %s\n\r",sysOutput.deviceID);
		fprintf(BT,"RH %f\r\n", sysOutput.rH);
		fprintf(BT,"WT %f\r\n", junk3);
		fprintf(BT,"DO %Lu \r\n", clear);
		fprintf(BT,"pH Patch %f \r\n", junk2);
		fprintf(BT,"AT %f\r\n", sysOutput.aTemp);
        fprintf(BT,"WD %f\r\n", junk);
        junk = ConvertADCTophBulb();
        fprintf(BT,"pH Bulb %f\r\n", junk); 
        junk = measureTDS(); 
        fprintf(BT,"EC (tds) %f\r\n", junk);
        findPAR();
        //gainof = GetCurrentColor(4, 5);   //This get the current reading off the harnis.  This is set to autogain.
		//fprintf(BT,"PAR Light %Lu Gain %Lu\r\n", clear, gainof);
//        junk = ReadNH3AVG();
        fprintf(BT,"NH3 %f\r\n", junk);
	}	
delay_ms(10000);   // wait a few seconds (5 seconds) between readings
		pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.
	}



//******************************************************************************
// Updated July 13, 2015
//  This shows DO numbers for its raw data and the completed data.
//  This is thread number 102
//**************************************************************************


void CalibrateDO(void)
	{

SetupADC();
//PWMDOIntensity=0x0650;
while(checkbtnumber(102))
	{
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
#ifdef TIRHTEMP

float returnedresultit,titemp;
    int returnedresult;
//*********************************************************************************
// Created Jan 17, 2017
// This calls and saves the current air temp and rh
//*********************************************************************************
 returnedresultit = GetHDC1080RHTemp(8);
   returnedresult = th;
   returnedresult = tl;
   titemp = (float) (th << 8 | tl);    
    titemp = titemp * 165.0 / 65536.0 - 40.0;
 sysOutput.aTemp = titemp;
  	if (sysOutput.aTemp < 0.0)
		sysOutput.aTemp = 0.0;
 
    returnedresult = hh;
   returnedresult = hl;
   titemp = (float) (th << 8 | tl);    
   titemp = titemp * 100.0 / 65536.0;
	sysOutput.rH = titemp;  //This is a float send into ta RH value.
	if (sysOutput.rH < 0.0)
		sysOutput.rH = 0.0;

#else

if (!GetTempRH())
	{
	sysOutput.aTemp = Temperature;  //This is the float temperature
	sysOutput.rH = RHData;  //This is a float send into ta RH value.
	}

#endif


	sysOutput.wTemp = WaterTemperature();

	BTBasicTest();   //Check BT 
FindAmbientLight(1);   //Find ambient light for DO

sysOutput.dOxy = TakeLightReading(8, PWMDOIntensity,BlueLimit);
//		sprintf(uffit,"%f      ",sysOutput.dOxy);
	//	Display_XYString(0, 3, &uffit);
		sprintf(uffit,"sysOutput.aTemp-> %f sysOutput.dOxy-> %f sysOutput.wTemp-> %f ",  sysOutput.aTemp, sysOutput.dOxy, sysOutput.wTemp);
		Display_XYString(0, 4, &uffit);
	BTBasicTest();   //Check BT 
    BTBasicTest();   //Check BT
    BTBasicTest();   //Check BT
    BTBasicTest();   //Check BT
//	pwm_set_duty(DO_PWM,0);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0);	//250hz
delay_ms(2500);
	BTBasicTest();   //Check BT 

	}
//	pwm_set_duty(DO_PWM,0);	//250hz  Turn off light for DO
	pwm_set_duty(PH_PWM,0);	//250hz
	}







//***********************************************************************************
// Created June 18, 2015
// This routine displays the four numbers for the DO values.  It also sets the PWM to half intensitiry.
//***********************************************************************************
void PositionDOSensor(void)
	{


int gino;      // General purpose variables
float stuff;   // General purpose variables


//	pwm_set_duty(DO_PWM,0x02FF);	//Start at some number and move up or down from here.

while(checkbtnumber(104))
	{
//	pwm_set_duty(DO_PWM,0x0000);	//Start at some number and move up or down from here.
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
	delay_ms(200);
	BTBasicTest();    //Check BT 
		GetCurrentColorAVG(4,1); //This igets the imediate color with no averaging.

AmbientOxyRed = redABS;
AmbientOxyGreen = greenABS;
AmbientOxyBlue = blueABS;
AmbientOxyClear = clearABS;
	BTBasicTest();    //Check BT 
//	pwm_set_duty(DO_PWM,0x01FF);	//Start at some number and move up or down from here.
	delay_ms(200);
	//	gino = GetCurrentColor(4,2); //This igets the imediate color with no averaging.
		gino = GetCurrentColorAVG(4,1);  //This gets the average color numbers from the pH sensor.  It's sensor number 2 and the 4 is free autogain.

	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

		sprintf(uffit,"Clear %Lu  %Lu  ", clearABS, redABS+greenABS+blueABS);
		Display_XYString(0, 1, &uffit);
		stuff = (float)redABS / (float) clearABS;
		sprintf(uffit,"Red %Lu %f  %i  ", redABS,stuff,gino);
		Display_XYString(0, 2, &uffit);
		stuff = (float)greenABS / (float) clearABS;
		sprintf(uffit,"Green %Lu %f  ", greenABS,stuff);
		Display_XYString(0, 3, &uffit);
		stuff = (float)blueABS / (float) clearABS;
		sprintf(uffit,"Blue %Lu %f   ", blueABS,stuff);
		Display_XYString(0, 4, &uffit);
	BTBasicTest();    //Check BT 
}
//	pwm_set_duty(DO_PWM,0x0000);	//Start at some number and move up or down from here.


}


//******************************************************************************
//Created June 19, 2015
// This routine is used to seat the light pipes for DO and pH while construting the Osmobot.
//******************************************************************************



void SetpHDOLightTube(void)
	{


int gino;      // General purpose variables
float stuff, junk, DOReading;   // General purpose variables


int32 clearABSpH,redABSpH,greenABSpH,blueABSpH;


SetupADC();   //Added October 3, 2014.  This inits the water depth and water temperature sensors
while(checkbtnumber(104))
	{
restart_wdt();   // restart the WD timer.  It set for 65 seconds
do {

	pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.
//	pwm_set_duty(DO_PWM,0x0000);	//Start at some number and move up or down from here.
	delay_ms(200);

	BTBasicTest();    //Check BT 
//Check the pH white light first.  Get the ambient light

		gino = GetCurrentColorAVG(4,2); //This gets the imediate color with no averaging.

AmbientOxyRed = redABS;
AmbientOxyGreen = greenABS;
AmbientOxyBlue = blueABS;
AmbientOxyClear = clearABS;
	pwm_set_duty(PH_PWM,0x0195);	//Start at some number and move up or down from here.

//	pwm_set_duty(DO_PWM,0x01B0);	//Start at some number and move up or down from here.
	delay_ms(200);
		gino = GetCurrentColor(4,2); //This igets the imediate color with no averaging.
	//	gino = GetCurrentColorAVG(4,2);  //This gets the average color numbers from the pH sensor.  It's sensor number 2 and the 4 is free autogain.


	redABSpH = redABS - AmbientOxyRed;
	greenABSpH = greenABS - AmbientOxyGreen;
	blueABSpH = blueABS - AmbientOxyBlue;
	clearABSpH = clearABS - AmbientOxyClear;



	pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.
//	pwm_set_duty(DO_PWM,0x0000);	//Start at some number and move up or down from here.
	delay_ms(200);

		stuff = (float)redABSpH / (float) clearABSpH;
	BTBasicTest();    //Check BT 

} while (stuff > 0.6);
/*
//Check the DO white light first.  Get the ambient light

		GetCurrentColorAVG(4,1); //This gets the imediate color with no averaging.

AmbientOxyRed = redABS;
AmbientOxyGreen = greenABS;
AmbientOxyBlue = blueABS;
AmbientOxyClear = clearABS;
	pwm_set_duty(DO_PWM,0x01FF);	//Start at some number and move up or down from here.

//	pwm_set_duty(DO_PWM,0x01B0);	//Start at some number and move up or down from here.
	delay_ms(200);
		gino = GetCurrentColor(4,1); //This gets the imediate color with no averaging.
//		gino = GetCurrentColorAVG(4,1);  //This gets the average color numbers from the pH sensor.  It's sensor number 2 and the 4 is free autogain.


	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;

*/

//This is the sections where it shows the results on the telescreen. It shows the ratio of each light  

		junk = WaterTemperature();
//		DOReading =  CalcaulateDO(redABS,junk);

		stuff = (float)blueABS / (float) clearABS;    //This makes the ratio for blue
		sprintf(uffit,"DO WT %f Rto %f  ", junk, stuff);
		Display_XYString(0, 1, &uffit);
		sprintf(uffit,"B%Lu R%Lu DO%f", blueABS, redABS, DOReading);
		Display_XYString(0, 2, &uffit);


		stuff = (float)redABSpH / (float) clearABSpH;
		sprintf(uffit,"pH %Lu Rto %f",  clearABSpH, stuff);
		Display_XYString(0, 3, &uffit);
//		junk = colorpH(redABSpH);
		sprintf(uffit,"Red %Lu %f", redABSpH,junk);
		Display_XYString(0, 4, &uffit);
	BTBasicTest();    //Check BT 
}

	pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.
//	pwm_set_duty(DO_PWM,0x0000);	//Start at some number and move up or down from here.

}



//***********************************************************************************
// Created June 11, 2015
// This routine displays the four numbers for the pH values.  It also sets the PWM to half intensitiry.
// Updated on July 13, 2015 to a calling routine.
//***********************************************************************************


void PositionpHSensor(void)
	{

int gino;      // General purpose variables
float stuff, junk;   // General purpose variables

	pwm_set_duty(PH_PWM,0x01FF);	//Start at some number and move up or down from here.

while(checkbtnumber(100))   //It's funtion number 1.  This means it has to match the global varaible for it to continue in this loop.  Or it exits back to the main loop.
	{
    restart_wdt();   // restart the WD timer.  It set for 65 seconds
	pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.

//	pwm_set_duty(DO_PWM,0x0000);	//Start at some number and move up or down from here.
	delay_ms(200);
		GetCurrentColorAVG(4,2); //This igets the imediate color with no averaging.
	BTBasicTest();   //Check BT 
AmbientOxyRed = redABS;
AmbientOxyGreen = greenABS;
AmbientOxyBlue = blueABS;
AmbientOxyClear = clearABS;
	pwm_set_duty(PH_PWM,0x01FF);	//Start at some number and move up or down from here.

//	pwm_set_duty(DO_PWM,0x01B0);	//Start at some number and move up or down from here.
	delay_ms(200);
	//	gino = GetCurrentColor(4,2); //This igets the imediate color with no averaging.
		gino = GetCurrentColorAVG(4,2);  //This gets the average color numbers from the pH sensor.  It's sensor number 2 and the 4 is free autogain.
	BTBasicTest();    //Check BT 

	redABS = redABS - AmbientOxyRed;
	greenABS = greenABS - AmbientOxyGreen;
	blueABS = blueABS - AmbientOxyBlue;
	clearABS = clearABS - AmbientOxyClear;


		sprintf(uffit,"Clear %Lu  %Lu  ", clearABS, redABS+greenABS+blueABS);
		Display_XYString(0, 1, &uffit);
		stuff = (float)redABS / (float) clearABS;
		sprintf(uffit,"Red %Lu %f  %i  ", redABS,stuff,gino);
		Display_XYString(0, 2, &uffit);
		stuff = (float)greenABS / (float) clearABS;
		sprintf(uffit,"Green %Lu %f  ", greenABS,stuff);
		Display_XYString(0, 3, &uffit);
		stuff = (float)blueABS / (float) clearABS;
//		junk = colorpH(redABS);
		sprintf(uffit,"Blue %Lu %f %f  ", blueABS,stuff,junk);
		Display_XYString(0, 4, &uffit);
	BTBasicTest();    //Check BT 

	}
	pwm_set_duty(PH_PWM,0x0000);	//Start at some number and move up or down from here.

	}



//*****************************************************************************
// Created July 13, 2015
// This is the calling routine for the debuge and calibration routines for BT commands
// All of the called routine are above in this file.  
// A number in "debugnumber" is switched and calls the routine.
// When the return exits, there is nothing return and the stack is cleared.
// Since the varible "debugnumber" is global, it does not need to be passed.  
//  If the number is zero, nothing is called and returns back to the main loop.
//  If it is a non zero-number, then it calls the routine.
// ****************************************************************************
void calldebug(void)
	{

    int commandnumber,portnumberkey;  //this is used for parsing a yes and no command for RJ45

	switch(debugnumber)
		{
		case 0:   
			break;
		case 100:
			fprintf(BT,"Starting routine to display the four numbers for the pH values.\n\r");  
			PositionpHSensor();  // This routine displays the four numbers for the pH values.  It also sets the PWM to half intensitiry.
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;
		case 101:
			fprintf(BT,"Starting routine to test all sensors.\n\r"); 
			RHTempSensor();
			debugnumber = 0;   // turns off the debugging command when exited.  Added July 17, 2015
			break;
		case 102:
			fprintf(BT,"Starting routine to Setup DO.\n\r"); 
			CalibrateDO();
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;
		case 103:
			fprintf(BT,"Starting routine to Setup pH.\n\r"); 
			DisplayRawpHData();
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;
		case 104:
			fprintf(BT,"Starting routine display the water depth\n\r"); 
			WDSensor();
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;
		case 105:
			fprintf(BT,"Starting routines to display phbulb readings.\n\r"); 
			phbulbsensor();
			debugnumber = 0;   // turns off the debugging command when exited.  Added July 17, 2015
			break;
		case 106:
            fprintf(BT,"Device ID -> %s  Unit Type -> %s\n\r",sysOutput.deviceID,sysInput.unittype); 
			fprintf(BT,"Printing all Calibration Varaibles.\n\r"); 
			fprintf(BT,"Temp1ReadingOne = %f\n\r",Temp1ReadingOne); 
			fprintf(BT,"Temp1ReadingTwo = %f\n\r",Temp1ReadingTwo); 
			fprintf(BT,"Temp1ReadingThree = %f\n\r",Temp1ReadingThree); 
			fprintf(BT,"Temp2ReadingOne = %f\n\r",Temp2ReadingOne); 
			fprintf(BT,"Temp2ReadingTwo = %f\n\r",Temp2ReadingTwo); 
			fprintf(BT,"Temp2ReadingThree = %f\n\r",Temp2ReadingThree); 
			fprintf(BT,"Temp3ReadingOne = %f\n\r",Temp3ReadingOne);
			fprintf(BT,"Temp3ReadingTwo = %f\n\r",Temp3ReadingTwo);
			fprintf(BT,"Temp3ReadingThree = %f\n\r",Temp3ReadingThree);

			fprintf(BT,"lowdoreadone = %f\n\r",Temp1DOOne);
			fprintf(BT,"lowdoreadtwo = %f\n\r",Temp1DOTwo);
			fprintf(BT,"lowdoreadthree = %f\n\r",Temp1DOThree);

			fprintf(BT,"Temp2DOOne = %f\n\r",Temp2DOOne);
			fprintf(BT,"Temp2DOTwo = %f\n\r",Temp2DOTwo);
			fprintf(BT,"Temp2DOThree = %f\n\r",Temp2DOThree);

			fprintf(BT,"Temp3DOOne = %f\n\r",Temp3DOOne);
			fprintf(BT,"Temp3DOTwo = %f\n\r",Temp3DOTwo);
			fprintf(BT,"Temp3DOThree = %f\n\r",Temp3DOThree);

			fprintf(BT,"pH calibration 1 ->  datatable[0] = %f\n\r",datatable[0]);
			fprintf(BT,"pH calibration 2 ->  datatable[1] = %f\n\r",datatable[1]);
			fprintf(BT,"pH calibration 3 ->  datatable[2] = %f\n\r",datatable[2]);
			fprintf(BT,"pH calibration 4 ->  datatable[3] = %f\n\r",datatable[3]);
			fprintf(BT,"pH calibration 5 ->  datatable[4] = %f\n\r",datatable[4]);
			fprintf(BT,"pH calibration 6 ->  datatable[5] = %f\n\r",datatable[5]);
			fprintf(BT,"pH calibration 7 ->  datatable[6] = %f\n\r",datatable[6]);
			fprintf(BT,"pH calibration 8 ->  datatable[7] = %f\n\r",datatable[7]);
			fprintf(BT,"pH calibration 9 ->  datatable[8] = %f\n\r",datatable[8]);
			fprintf(BT,"pH datatable[9] pH calibration offset = %f\n\r",datatable[9]);
			fprintf(BT,"pH datatable[10] pH red color offset = %f\n\r",datatable[10]);
			fprintf(BT,"pH datatable[11] not used = %f\n\r",datatable[11]);

			fprintf(BT,"Thermister high temp1 = %f\n\r",temp1);
			fprintf(BT,"Thermister mid temp2 = %f\n\r",temp2);
			fprintf(BT,"Thermister low temp3 = %f\n\r",temp3);

			fprintf(BT,"Thermister reading values high (temp1) = %f\n\r",reading1);
			fprintf(BT,"Thermister reading values mid (temp2) = %f\n\r",reading2);
			fprintf(BT,"Thermister reading values low (temp3) = %f\n\r",reading3);

			fprintf(BT,"Blue DO Reference = %Lu\n\r",BlueLimit);
			fprintf(BT,"White pH Reference = %Lu\n\r",WhiteLimit);
			fprintf(BT,"Blueseed = %Lu\n\r",PWMDOIntensity);
			fprintf(BT,"Whiteseed = %Lu\n\r",PWMPHIntensity);
			fprintf(BT,"BlueRange = %Lu\n\r",DOreadingrange);
			fprintf(BT,"Water Depth Offset = %Lu\n\r",pHreadingrange);


			fprintf(BT,"EC ppm value for high = %f\n\r",eccalibrationx[0]);
			fprintf(BT,"EC ppm value for mid = %f\n\r",eccalibrationx[1]);
			fprintf(BT,"EC ppm value for low = %f\n\r",eccalibrationx[2]);
			fprintf(BT,"EC input value for high = %f\n\r",eccalibrationy[0]);
			fprintf(BT,"EC input value for mid = %f\n\r",eccalibrationy[1]);
			fprintf(BT,"EC input value for low = %f\n\r",eccalibrationy[2]);
  			fprintf(BT,"EC calibration eccal1x = %f\n\r",sysInput.eccal1x); 
  			fprintf(BT,"EC calibration eccal1y = %f\n\r",sysInput.eccal1y); 
            fprintf(BT,"EC calibration eccal2x = %f\n\r",sysInput.eccal2x); 
            fprintf(BT,"EC calibration eccal2y = %f\n\r",sysInput.eccal2y); 
            fprintf(BT,"EC calibration eccal3x = %f\n\r",sysInput.eccal3x); 
            fprintf(BT,"EC calibration eccal3y = %f\n\r",sysInput.eccal3y); 
                       
            
 			fprintf(BT,"pH Bulb Calibration at %f gives a ADC reading  of = %f\n\r",sysInput.phnumberupper,sysInput.phcalhigh); 
  			fprintf(BT,"pH Bulb Calibration at 4 gives a ADC reading  of = %f\n\r",sysInput.phcallow);            



/*
   "wthigh",           //  sets water temperature measurement high
   "wtmid",              //  sets water temperature measurement mid
   "wtlow",            //  sets water temperature measurement low
   "wtvalh",           //  sets water temperature measurement high reading/value
   "wtvalm",           //  sets water temperature measurement mid reading/value
   "wtvall",           //  sets water temperature measurement low reading/value
   "echigh",           // set the ec ppm value for high
   "ecmid",           // set the ec ppm value for mid
   "eclow",           // set the ec ppm value for low
   "ecvalh",           // set the ec input value for high
   "ecvalm",           // set the ec input value for mid
   "ecvall"           // set the ec input value for low

*/



			debugnumber = 0;   // turns off the debugging command when exited.  Added July 17, 2015
			break;

		case 107:   // not used.  this is the parameter for the password

			debugnumber = 0;   // turns off the debugging command when exited.  Added July 17, 2015

			break;


		case 108:   // start the EC routines.
			fprintf(BT,"Starting routine to setup EC or TDS for cap decay.\n\r"); 
			TDSSensor();
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;


		case 109:     // This is the brother's DO patch.  Start running the routine
			fprintf(BT,"Starting routine to setup DO for light decay.\n\r"); 
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			GetDO(1000);    //Run program.
			break;

		case 110:     // This is the current water temperature.  Start running the routine
			fprintf(BT,"Starting routine to setup calculating and displaying current water temperature.\n\r"); 
			WTTempSensor();    //Run program.
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;
 
		case 111:     // This is the PAR levle.  Start running the routine
			fprintf(BT,"Starting routine to setup calculating and displaying raw light and PAR data.\n\r"); 
			findPAR();
            //GetLastLightReading();    //Run program.
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;

		case 112:
			fprintf(BT,"Starting routine to Setup NH3.\n\r"); 
			DisplayRawNH3Data();
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 17, 2015
			break;
            

		case 200:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp1ReadingOne = atof(bt_cmd);
		//	Temp1ReadingOne  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp1ReadingOne set to %f.\n\r",Temp1ReadingOne); 
			break;
		case 201:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp1ReadingTwo = atof(bt_cmd);
		//	Temp1ReadingTwo  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp1ReadingTwp set to %f.\n\r",Temp1ReadingTwo); 
			break;
		case 202:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp1ReadingThree = atof(bt_cmd);
		//	Temp1ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp1ReadingThree set to %f.\n\r",Temp1ReadingThree); 
			break;
		case 203:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp2ReadingOne = atof(bt_cmd);
		//	Temp2ReadingOne  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp2ReadingOne set to %f.\n\r",Temp2ReadingOne); 
			break;
		case 204:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp2ReadingTwo = atof(bt_cmd);
		//	Temp2ReadingTwo  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp2ReadingTwo set to %f.\n\r",Temp2ReadingTwo); 
			break;
		case 205:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp2ReadingThree = atof(bt_cmd);
		//	Temp2ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp2ReadingThree set to %f.\n\r",Temp2ReadingThree); 
			break;
		case 206:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp3ReadingOne = atof(bt_cmd);
		//	Temp3ReadingOne  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp3ReadingOne set to %f.\n\r",Temp3ReadingOne); 
			break;
		case 207:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp3ReadingTwo = atof(bt_cmd);
		//	Temp3ReadingTwo  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp3ReadingTwo set to %f.\n\r",Temp3ReadingTwo); 
			break;
		case 208:
			BT_GetLastCMD();  // get the number from the third parameter.
			Temp3ReadingThree = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Temp3ReadingThree set to %f.\n\r",Temp3ReadingThree); 
			break;



		case 209:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[0] = atof(bt_cmd);
		//	datatable[0]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[0] set to %f.\n\r",datatable[0]); 
			break;
		case 210:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[1] = atof(bt_cmd);
		//	datatable[1]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[1] set to %f.\n\r",datatable[1]); 
			break;
		case 211:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[2] = atof(bt_cmd);
		//	datatable[2] 
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[2] set to %f.\n\r",datatable[2]); 
			break;
		case 212:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[3] = atof(bt_cmd);
		//	datatable[3]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[3] set to %f.\n\r",datatable[3]); 
			break;
		case 213:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[4] = atof(bt_cmd);
		//	datatable[4]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[4] set to %f.\n\r",datatable[4]); 
			break;
		case 214:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[5] = atof(bt_cmd);
		//	datatable[5]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[5] set to %f.\n\r",datatable[5]); 
			break;
		case 215:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[6]  = atof(bt_cmd);
		//	datatable[6]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[6]  set to %f.\n\r",datatable[6] ); 
			break;
		case 216:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[7]  = atof(bt_cmd);
		//	datatable[7]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[7] set to %f.\n\r",datatable[7]); 
			break;
		case 217:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[8] = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"datatable[8] set to %f.\n\r",datatable[8]); 
			break;



		case 218:
			BT_GetLastCMD();  // get the number from the third parameter.
			BlueLimit  = atoi32(bt_cmd);
		//	BlueLevel  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"BlueLimit set to %Lu.\n\r",BlueLimit); 
			break;
		case 219:
			BT_GetLastCMD();  // get the number from the third parameter.
			WhiteLimit = atoi32(bt_cmd);
		//	WhiteLimit 
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"WhiteLimit set to %Lu.\n\r",WhiteLimit); 
			break;



		case 220:
			BT_GetLastCMD();  // get the number from the third parameter.
			PWMDOIntensity  = atoi32(bt_cmd);  //This sets the current PWM for DO to the new value.
		//	BlueLevel  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Current start PWM DO is set to %Lu.\n\r",PWMDOIntensity); 
			break;
		case 221:
			BT_GetLastCMD();  // get the number from the third parameter.
			PWMPHIntensity = atoi32(bt_cmd);   //This sets the current PWM for pH to the new value.
		//	WhiteLimit 
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Current PWM seed for pH is set to %Lu.\n\r",PWMPHIntensity); 
            break;


		case 222:
			BT_GetLastCMD();  // get the number from the third parameter.
			DOreadingrange  = atoi32(bt_cmd);  //This sets the current PWM for DO to the new value.
		//	BlueLevel  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015  Changed Oce 29, 2015    Changed the wording of the report.
			fprintf(BT,"Current PWM DO range (Disolved Oxy) is set to %Lu.\n\r",DOreadingrange); 
			break;
		case 223:
			BT_GetLastCMD();  // get the number from the third parameter.
            pHreadingrange = (int16) GetADCValue(9); // this gets the water depth informration when the tube is no in the water.  Added March 2, 2016
			//pHreadingrange = atoi32(bt_cmd);   //This sets the current PWM for pH to the new value.  This is the old method.
		//	This has been changed to the offset water depth.  This number is not nomally viewd.
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"The pressure offset is set to %Lu.\n\r",pHreadingrange); 
            break;


		case 224:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[9]  = atof(bt_cmd);
		//	datatable[7]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting pH calibration offset number.  datatable[9] set to %f.\n\r",datatable[9]); 
			break;
		case 225:
			BT_GetLastCMD();  // get the number from the third parameter.
			datatable[10] = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting pH calibration red color.  datatable[10] set to %f.\n\r",datatable[10]); 
			break;

		case 226:
			BT_GetLastCMD();  // get the number from the third parameter.
			strncpy(STA_ENC, bt_cmd+'\0', strlen(bt_cmd)+1);   // Move the last infomration into the variable
           //set aes
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"AES is set to %s.\n\r",STA_ENC); 
			break;
		case 227:
			BT_GetLastCMD();  // get the number 
			strncpy(STA_SSID, bt_cmd+'\0', strlen(bt_cmd)+1);   // Move the last infomration into the variable
           //set ssid
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"SSID is set to %s.\n\r",STA_SSID); 
			break;
		case 228:
			BT_GetLastCMD();  // get the number from the third parameter.
			strncpy(STA_PW, bt_cmd+'\0', strlen(bt_cmd)+1);   // Move the last infomration into the variable
           //set password
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Password is set to %s.\n\r",STA_PW); 
			break;
		case 229:
			BT_GetLastCMD();  // get the number from the third parameter.
			strncpy(STA_AUTH, bt_cmd+'\0', strlen(bt_cmd)+1);   // Move the last infomration into the variable
           //set auth
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"AUTH is set to %s.\n\r",STA_AUTH); 
			break;
		case 242:
			BT_GetLastCMD();  // get the number from the third parameter.  In this case it is for yes and no for the set RJ45 command.
 			commandnumber = atoi(bt_cmd) + 12;
            //set yes or no
            
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the RJ45 connection to %s.\n\r",bt_cmd); 
            commandnumber = changeconnection(commandnumber);
            fprintf(BT,"Completed and Restarting.....%i  Make sure the Cable is connected and live or it resorts back to Wifi.\n\r",commandnumber);
            delay_ms(3000);  // delay to allow infomration to be saved.  Added September 6, 2015
		    reset_cpu();   // resets the unit from a CPU reboot.  
			break;


//*********************************************
// Added on December 16, 2015
// These are additional DO commands for updating the table for DO readings.
//*********************************************



		case 243:
			BT_GetLastCMD();  // get the number for "lowdoreadone"  10 degree reading
			Temp1DOOne = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 10 degrees one %f.\n\r",Temp1DOOne); 
			break;
		case 244:
			BT_GetLastCMD();  // get the number for "lowdoreadtwo"  10 degree reading
			Temp1DOTwo = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 10 degrees two %f.\n\r",Temp1DOTwo); 
			break;
		case 245:
			BT_GetLastCMD();  // get the number for "lowdoreadthree"  10 degree reading
			Temp1DOThree = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 10 degrees three %f.\n\r",Temp1DOThree); 
			break;
		case 246:
			BT_GetLastCMD();  // get the number for "middoreadone"  20 degree reading
			Temp2DOOne = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 20 degrees one %f.\n\r",Temp2DOOne); 
			break;
		case 247:
			BT_GetLastCMD();  // get the number for "middoreadtwo"  20 degree reading
			Temp2DOTwo = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 20 degrees two %f.\n\r",Temp2DOTwo); 
			break;
		case 248:
			BT_GetLastCMD();  // get the number for "middoreadthree"  20 degree reading
			Temp2DOThree = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 20 degrees three %f.\n\r",Temp2DOThree); 
			break;
		case 249:
			BT_GetLastCMD();  // get the number for "highdoreadone"  25 degree reading.
			Temp3DOOne = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 25 degrees one %f.\n\r",Temp3DOOne); 
			break;
		case 250:
			BT_GetLastCMD();  // get the number for "highdoreadtwo"  25 degree reading.
			Temp3DOTwo = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 25 degrees two %f.\n\r",Temp3DOTwo); 
			break;
		case 251:
			BT_GetLastCMD();  // get the number for "highdoreadthree"  25 degree reading.
			Temp3DOThree = atof(bt_cmd);
		//	Temp3ReadingThree  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Reading for DO @ 25 degrees three %f.\n\r",Temp3DOThree); 
			break;
         case 252:
			BT_GetLastCMD();  //    "set nh3  xxx"           // set the ec input value for low
			PWMnh3Intensity  = atof(bt_cmd); 
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the PWMnh3Intensity to the new value.  PWMnh3Intensity set to %Lu.\n\r",PWMnh3Intensity); 
			break;
         case 253:
			BT_GetLastCMD();  //    "set sn  xxx"           // set the device ID into sysOutput.deviceID
			strncpy(sysOutput.deviceID, bt_cmd+'\0', strlen(bt_cmd)+1);   // Move the last infomration into the variable
           //set sn for this device.  This is an internal command not to be given out.
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the Unit ID to %s.\n\r",sysOutput.deviceID); 
			break;

         case 254:
			BT_GetLastCMD();  //    "set phbulbgain  x.xx"           // sets the gain for multipying the voltage in and the output for ph on the phbulb
			phbulbgain  = atof(bt_cmd); 
            //strncpy(sysOutput.deviceID, bt_cmd+'\0', strlen(bt_cmd)+1);   // Move the last infomration into the variable
           //set sn for this device.  This is an internal command not to be given out.
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the Unit ID to %s.\n\r",sysOutput.deviceID); 
			break;
            
         case 255:
			BT_GetLastCMD();  //    "set phbulb7"           // set the phbulb offset when it is reading 7.  Added May 19, 2016
			
            // run the zero program for 7.
           //set sn for this device.  This is an internal command not to be given out.
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the Unit ID to %s.\n\r",sysOutput.deviceID); 
			break;
        case 256:
			BT_GetLastCMD();  //    "set port"           // used to set and reset port lines for SSR and for clearing SSR.  The format is characters of zeros and ones.  all on -> 11,  all off -> 00    Added June 29, 2016
			portnumberkey  = atoi(bt_cmd);
         
            switch(portnumberkey)
            {
                case 0:
                       sysInput.io1 = 0;    // Turn off SSR  Added June 29, 2015
                       sysInput.io2 = 0;    // Turn off SSR     Added June 29, 2015
                    break;
                  case 1:
                       sysInput.io1 = 1;    // Turn on SSR  Added June 29, 2015
                       sysInput.io2 = 0;    // Turn off SSR     Added June 29, 2015

                    break;              
                 case 10:
                       sysInput.io1 = 0;    // Turn off SSR  Added June 29, 2015
                       sysInput.io2 = 1;    // Turn on SSR     Added June 29, 2015

                    break;
                 case 11:
                       sysInput.io1 = 1;    // Turn on SSR  Added June 29, 2015
                       sysInput.io2 = 1;    // Turn on SSR     Added June 29, 2015
                    break;
            default:
                       sysInput.io1 = 0;    // Turn off SSR  Added June 29, 2015
                       sysInput.io2 = 0;    // Turn off SSR     Added June 29, 2015
                break;
            }
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting ports to %i.\n\r  Wait for OS to turn on/off ports\n\r",portnumberkey); 
			break;


/*
   "wthigh",           //  sets water temperature measurement high
   "wtmid",              //  sets water temperature measurement mid
   "wtlow",            //  sets water temperature measurement low
   "wtvalh",           //  sets water temperature measurement high reading/value
   "wtvalm",           //  sets water temperature measurement mid reading/value
   "wtvall",           //  sets water temperature measurement low reading/value
   "echigh",           // set the ec ppm value for high
   "ecmid",           // set the ec ppm value for mid
   "eclow",           // set the ec ppm value for low
   "ecvalh",           // set the ec input value for high
   "ecvalm",           // set the ec input value for mid
   "ecvall"           // set the ec input value for low

*/


		case 230:
			BT_GetLastCMD();  //    "wthigh",           //  sets water temperature measurement high
			temp1  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting wthigh water temperature measurement high.  temp1 set to %f.\n\r",temp1); 
			break;
		case 231:
			BT_GetLastCMD();  //    "wtmid",              //  sets water temperature measurement mid
			temp2  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting wtmid water temperature measurement mid.  temp2 set to %f.\n\r",temp2); 
			break;
		case 232:
			BT_GetLastCMD();  //    "wtlow",            //  sets water temperature measurement low
			temp3  = atof(bt_cmd); 
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting wtlow water temperature measurement low.  temp3 set to %f.\n\r",temp3); 
			break;
		case 233:
			BT_GetLastCMD();  //    "wtvalh",           //  sets water temperature measurement high reading/value
			reading1  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting water temperature measurement high reading/value.  reading1 set to %f.\n\r",reading1); 
			break;
		case 234:
			BT_GetLastCMD();  //    "wtvalm",           //  sets water temperature measurement mid reading/value
			reading2  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting water temperature measurement mid reading/value.  reading2 set to %f.\n\r",reading2); 
			break;
		case 235:
			BT_GetLastCMD();  //    "wtvall",           //  sets water temperature measurement low reading/value
			reading3  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting water temperature measurement low reading/value.  reading3 set to %f.\n\r",reading3); 
			break;
		case 236:
			BT_GetLastCMD();  //    "echigh",           // set the ec ppm value for high
			eccalibrationy[0]  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the ec ppm value for high.  eccalibrationy[0] set to %f.\n\r",eccalibrationy[0]); 
			break;
		case 237:
			BT_GetLastCMD();  //    "ecmid",           // set the ec ppm value for mid
			eccalibrationy[1]  = atof(bt_cmd);
		//	datatable[7]  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the ec ppm value for mid.  eccalibrationy[1] set to %f.\n\r",eccalibrationy[1]); 
			break;
		case 238:
			BT_GetLastCMD();  //    "eclow",           // set the ec ppm value for low
			eccalibrationy[3]  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the ec ppm value for low.  eccalibrationy[2] set to %f.\n\r",eccalibrationy[2]); 
			break;
		case 239:
			BT_GetLastCMD();  //    "ecvalh",           // set the ec input value for high
			eccalibrationx[0]  = atof(bt_cmd);
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the ec input value for high.  eccalibrationx[0] set to %f.\n\r",eccalibrationx[0]); 
			break;
		case 240:
			BT_GetLastCMD();  //    "ecvalm",           // set the ec input value for mid
			eccalibrationx[1]  = atof(bt_cmd);  
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the ec input value for mid.  eccalibrationx[1] set to %f.\n\r",eccalibrationx[1]); 
			break;
		case 241:
			BT_GetLastCMD();  //    "ecvall"           // set the ec input value for low
			eccalibrationx[2]  = atof(bt_cmd); 
			debugnumber = 0;   // turns off the debuging command when exited.  Added July 23, 2015
			fprintf(BT,"Setting the ec input value for low.  eccalibrationx[2] set to %f.\n\r",eccalibrationx[2]); 
			break;



	default: 
		return;
		}
	}

