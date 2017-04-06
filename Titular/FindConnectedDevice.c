

//******************************************************************************
// Created Febuary 20, 2017
// This table shows the returned results for board used to IDing through the I2C
// Board Name            Returned ID
// Digital Board             0x39
// RH/Temp                   0x1050
// Light Chip                0x22
// Analog DO & NH4           0xa9
// CO2                       0xd9
//******************************************************************************


//******************************************************************************
// Created Jan 23, 2017
// This routine searches for a plugged in device for any port.  It is a general purpose used for osmobot for finding whih i2c is plugged in.
// The returned value is the device ID number used by osmobot. 
// The the returned value is a 1, that means nothing is plugged in or it's not working. (communicating)
//******************************************************************************
int FindRJ45Device(int portnumber,int deviceid)
{
    
    

    int16 returnedvalue;  // this is the dummy returned value from checking I2C connections
    int struuu;
    float nhthree,NHCalHigh,NHCalLow,NHReadingLow,NHReadingHigh,wtemper,b,phtemper,nhslope;
    int16 ReturnedADC;  // this is the returned value from the Vernier Sensor
    char teststr4[20];
    if (deviceid==0x02)
    {
    clearDisplay();
    sprintf(teststr4,"Identifying");
     writeString(0, 0, teststr4);
    }


    //*************************************************************************
    // Created March 14, 2017
    // This sections reads the Vernier Sensor and displays it on the bottom.
    // The sensor is connected to the back of the used using the British RJ45 connection (right handed)
    //*************************************************************************)
    
    // read the sensor  ADC sAN3 off pin 5.
    ReturnedADC = GetADCValue(3); //This gets the current ADC convertion for the channel number.
    // show the result all the time a devices is not being accessed.
    
    //**************************************************************************
    // Created March 14, 2017
    // This is the first attempt at seperating the NH3 and NH4 from the reading.
    //  Neede varaibles
    //  Total (NH3+NH4)-Nitrogen Concentration (mg/L)    (NitConcentration)
    // pH                     sysOutput.pH
    // temperature in C       sysOutput.wTemp
    //  Free NH3 in (mg/L)
    //  form.product.value = Number(form.one.value)/(1+Math.pow(10,(0.0902-Number(form.two.value)+(2730/(273.2+Number(form.three.value))))));
//  (mg/L NH3) = NitConcentration/(1 + 10^(0.0902-sysOutput.pH +(2730/(273.2+sysOutput.wTemp)))
    
    
    NHCalHigh = 100.0;
    NHCalLow = 1.0;
    NHReadingHigh = 25.0;
    NHReadingLow = 6.0;
    wtemper = 19.0;
    phtemper= 7.0;
    
    nhslope = ((NHCalHigh - NHCalLow)/(NHReadingHigh-NHReadingLow));
    b = NHCalHigh - nhslope * NHReadingHigh;
    nhthree = (float) ReturnedADC;
    
    // find the number from the slope equation
    nhthree = nhslope*nhthree + b;  // this is the calculated NH4 and NH3
    
    
    nhthree = nhthree/(1 + pow(10,(0.0902-phtemper +(2730/(273.2+wtemper)))));
    
    sprintf(teststr4,"Vernier %Lu NH3 %f  ",ReturnedADC,nhthree);
     writeString(0, 3, teststr4);
     
   // selectsensor(portnumber);  // this sets the SCL to the right I2C device.
    

        
        // check for 1050
        returnedvalue = GetHDC1080Version(0x01);
        if (returnedvalue == 0x1050)
        {
              // this is the TO rH and temp sensor
            return(0x22);
        }
        
        // this finds the light sensor version and then tests the device.
        struuu = getTAOSVersion(0x01);
        if (struuu == 0x11)
        {
              // this is the number for the light sensor/PAR,
            return(0x23);  // returns a 23 for the light sensor test.
        }        
        
        struuu = GetAnalogDONHFourVersion(0x01);
        if (struuu == 0xA9)  //  this is the code for the Analog DO and NH4 sensor
        {
              // this is the Analog DO, Temperature and NH4 sensor
            return(0x24);
        }      
        if (struuu == 0x39)  //  this is the code for the Digital DO and NH4 sensor
        {
              // this is the Digital DO, Temperature and NH4 sensor
            return(0x25);
        }         
         if (struuu == 0xd9)  //  this is the code for the CO2, RH and Temp sensor
        {
              // this is the CO2, RH and Temp sensor
            return(0x26);
        }         
    //clear display and put up display searching for plugged in device.
    
    // loop through all of version and device IDs that are provided by the manufacturer.
   
    // If a result is one of the known devices, return the device index number. 
    
    //  The device is then tested by another routine.
    
    return(0x01);
}


//*****************************************************************************
// Create January 23, 2017
// This routine is used to test the TI 1050 chip on the optical board.
// It clears the display and sends the raw and calculated data to the display in real time.
// when the cable is pulled out, there is an error with the version number and then it releases back
// to the operating system to check for the next connection.
//  Returns nothing.
//*****************************************************************************
int TestRHTemp(void)
{
    
    int16 returnedvalue,returnedresult;
    float returnedresultit,titemp;
    
    clearDisplay();
    char teststr4[20];
    sprintf(teststr4,"TI 1015 RH/Temp");
    writeString(0, 0, teststr4);
    while(1)
    {
        returnedvalue = GetHDC1080Version(0x01);
        if (returnedvalue == 0x1050)
        {
// this means the device is still plugged in.  Get the real-time temp and RH.
    //    returnedvalue = GetHDC1080RHTemp(0x01);
            
   returnedresultit = GetHDC1080RHTemp(0x01);
   
   readlineararray();
   returnedresult = th;
   returnedresult = tl;
   titemp = (float) (th << 8 | tl);    
    titemp = titemp * 165.0 / 65536.0 - 40.0;
     sprintf(teststr4,"Temp %f",titemp);   
    writeString(0, 3, teststr4);

    returnedresult = hh;
   returnedresult = hl;
   titemp = (float) (hh << 8 | hl);    
   titemp = titemp * 100.0 / 65536.0;
  //    titemp = titemp * 100.0 / 32768.0;
     sprintf(teststr4,"RH %f",titemp); 
        writeString(0, 2, teststr4);        
        }
        else
        {
        return(0x02);    // exit the routine when the chip is not installed.
        }
    }   
}



//*****************************************************************************
// Create January 24, 2017
// This routine is used to test the PAR chip on the optical board.
// It clears the display and sends the raw and calculated data to the display in real time.
// when the cable is pulled out, there is an error with the version number and then it releases back
// to the operating system to check for the next connection.
//  Returns nothing.
//*****************************************************************************
int TestPARchip(void)
{
    
    int16 returnedvalue,returnedresult;
    float returnedresultit,titemp;
    int struuu;
    
    clearDisplay();
    char teststr4[20];
    sprintf(teststr4,"       TAOS 3414");
    writeString(0, 0, teststr4);
    while(1)
    {
        struuu = getTAOSVersion(0x01);
        if (struuu == 0x11)
        {
// this means the device is still plugged in.  Get the real-time temp and RH.
      ExposureTimeTAOS(0x00, 0x01);
      StartUpTAOS(0x01);
      
		ReadColorTAOS(2,0x01);  //green
		green = colorlow + colorhigh * 256;

		ReadColorTAOS(1,0x01);  //red
		red = colorlow + colorhigh * 256;

		ReadColorTAOS(4,0x01);  //clear
		clear = colorlow + colorhigh * 256;

		ReadColorTAOS(3,0x01);  //blue
		blue = colorlow + colorhigh * 256;
      
      
      
     sprintf(teststr4,"red %Lu",red);   
    writeString(0, 1, teststr4);
     sprintf(teststr4,"green %Lu",green);   
    writeString(0, 2, teststr4);
      sprintf(teststr4,"blue %Lu",blue);   
    writeString(0, 3, teststr4);      
        }
        else
        {
        return(0x02);    // exit the routine when the chip is not installed.
        }
    }   
}


//*****************************************************************************
// Create Fabuary 12, 2017
// This routine is used to test the AnalogDO and NH4 board.
// It clears the display and sends the raw and calculated data to the display in real time.
// when the cable is pulled out, there is an error with the version number and then it releases back
// to the operating system to check for the next connection.
//  Returns no data other than the flag if nothing is connected
//*****************************************************************************
int TestAnalogDONHFourBoard(void)
{
    
    int16 returnedvalue,returnedresult;
    float returnedresultit,titemp;
    int struuu;
    
    clearDisplay();
    char teststr4[20];
    sprintf(teststr4," Analog DO and NH4  ");
    writeString(0, 0, teststr4);
    while(1)
    {
        struuu = GetAnalogDONHFourVersion(0x01);
        if (struuu == 0xa9)
        {
// this means the device is still plugged in.  Get the real-time temp and RH.
            
        ReadRemoteDevice(0x01); // this selects the Top connector RJ45 device
        moveReceivedData(0x00);
        
     sprintf(teststr4,"WT %f  Raw %Lu  ",sysOutput.wTemp,WTraw);   
    writeString(0, 1, teststr4);
     sprintf(teststr4,"NH4 %Lu   ",NH4Raw);   
    writeString(0, 2, teststr4);
      sprintf(teststr4,"DO %Lu   ",DOraw);   
    writeString(0, 3, teststr4);      
        }
        else
        {
        return(0x02);    // exit the routine when the chip is not installed.
        }
    }   
}

//*****************************************************************************
// Create Fabuary 16, 2017
// This routine is used to test the  Digital DO and NH4 board.
// It clears the display and sends the raw and calculated data to the display in real time.
// when the cable is pulled out, there is an error with the version number and then it releases back
// to the operating system to check for the next connection.
//  Returns no data other than the flag if nothing is connected
//*****************************************************************************
int TestDigitalDONHFourBoard(void)
{
    
    int16 returnedvalue,returnedresult;
    float returnedresultit,titemp;
    int struuu;
    
    clearDisplay();
    char teststr4[20];
 //   sprintf(teststr4,"Digital DO and NH4   ");
 //   writeString(0, 0, teststr4);
    while(1)
    {
        struuu = GetAnalogDONHFourVersion(0x01);
        if ((struuu == 0x39) && (!startupdate))
        {
// this means the device is still plugged in.  Get the real-time temp and RH.
           //DpHredRaw,DpHGreenRaw,DpHBlueRaw,DpHWhiteRaw 
        ReadRemoteDevice(0x01); // this selects the Top connector RJ45 device
        moveReceivedData(0x00);
        
     sprintf(teststr4,"WT %f  Raw %Lu  ",sysOutput.wTemp,WTraw);   
    writeString(0, 0, teststr4);
     sprintf(teststr4,"%Lu %Lu %Lu %Lu  ",NHRedRaw,NHGreenRaw,NHBlueRaw,NHWhiteRaw);   
    writeString(0, 1, teststr4);
      sprintf(teststr4,"DO Raw %Lu    ",DOraw);   
    writeString(0, 2, teststr4); 
    sprintf(teststr4,"%Lu %Lu %Lu %Lu  ",DpHRedRaw,DpHGreenRaw,DpHBlueRaw,DpHWhiteRaw);    
    writeString(0, 3, teststr4);    
    fprintf(BT,"NH4-DO RGBW,%Lu,%Lu,%Lu,%Lu,DO Red,%Lu,WT,%f,Raw,%Lu,Dph-RGBW,%Lu,%Lu,%Lu,%Lu\n\r",NHRedRaw,NHGreenRaw,NHBlueRaw,NHWhiteRaw,DOraw,sysOutput.wTemp,WTraw,DpHRedRaw,DpHGreenRaw,DpHBlueRaw,DpHWhiteRaw);
        }
        else
        {
        return(0x02);    // exit the routine when the chip is not installed.
        }
    }   
}


//*****************************************************************************
// Create Fabuary 20, 2017
// This routine is used to test the CO2 board.
// It clears the display and sends the raw and calculated data to the display in real time.
// when the cable is pulled out, there is an error with the version number and then it releases back
// to the operating system to check for the next connection.
//  Returns no data other than the flag if nothing is connected
//*****************************************************************************
int TestCO2Board(void)
{
    
    int16 returnedvalue,returnedresult;
    float returnedresultit,titemp;
    int struuu;
    
    clearDisplay();
    char teststr4[20];
    sprintf(teststr4,"  CO2/RH/Temp   ");
    writeString(0, 0, teststr4);
    while(1)
    {
        struuu = GetAnalogDONHFourVersion(0x01);   // this same routine is used for finding the ID code for all of the made boards.  The returned number is what makes it different.
        if (struuu == 0xd9)
        {
// this means the device is still plugged in.  Get the real-time temp and RH.
            
        ReadRemoteDevice(0x01); // this selects the Top connector RJ45 device
        moveReceivedData(0x00);
        
     sprintf(teststr4,"AT %f  RH  %f  ",sysOutput.aTemp,sysOutput.rH);   
    writeString(0, 1, teststr4);
      sprintf(teststr4,"CO2 %Lu    ",sysOutput.cO2);   
    writeString(0, 3, teststr4);      
        }
        else
        {
        return(0x02);    // exit the routine when the chip is not installed.
        }
    }   
}

