

//Function That takes Data Input 
#define SPLITTERDEBUG 1
#define LAZYDEBUG 1
#ifndef int1
#define int1 int
#endif



//************************************************************************************
//  Created Augest 12, 2015
// This routine marshalls where webpages go from the server or from the handhaeld device used to configure the unit.
// This is the first attepmt, I guessing there are a lot of conditrions coming back from the hand held device telling different pages that needs to be sorted.
//  Also how are pages sent back to the handheld device?  And not to the webserver?
// Once the data comes completed from the remote location, it can be parsed for what it needs to do.  
// How do you tell the end of a transmitted line?
// This routine returns a flag where it says there is a string ready for parsing.
//***********************************************************************************
int webmarshaller(void)
	{
	char teststring[40];
// for now print out anything that comes from the Wifi to the blue tooth.
	while(next_in != next_out)
		{
		char yy;  //This is a dummy varaible for getting a character from the buffer.
		yy = Paulbgetc();
		if (yy != 0xFFFE)	
			{
			WebPageTxtBuff[webmarshallerpointer] = yy;
			webmarshallerpointer++;
			WebPageTxtBuff[webmarshallerpointer] = 0x00;
			}
		}
	//  Once this go around is completed, the end of the string is checked.
	// if the  end of the string is found, the pointer -> webmarshallerpointer is set to zero and the flag is set to parse the data.
		
//		sprintf(teststring, "</html> ");
		sprintf(teststring, "GoodMessage");
			if (strstr(&WebPageTxtBuff, &teststring)!=0)
				{
			//	webmarshallerpointer = 0;
				SDCardResults = 0;  // This changes the comuncations flag to allow sensor reading.  If anything comes back, it's connected.
         		return(1);
				}
		sprintf(teststring, "HTTP/1.1\r\n");	
				if (strstr(&WebPageTxtBuff, &teststring)!=0)
				{
				//webmarshallerpointer = 0;
				SDCardResults = 0;  // This changes the comuncations flag to allow sensor reading.  If anything comes back, it's connected.
         		return(2);
				}
		sprintf(teststring, "400 Bad Request");
			if (strstr(&WebPageTxtBuff, &teststring)!=0)
				{
			//	webmarshallerpointer = 0;
				SDCardResults = 3;  // This changes the comuncations flag to allow sensor reading.  If anything comes back, it's connected.
         		return(4);
				}
        sprintf(teststring, "NewSerialnumber");  //this tells the returned message is from the server and is a new serial number.
			if (strstr(&WebPageTxtBuff, &teststring)!=0)
				{
				SDCardResults = 0;  // This changes the comuncations flag to allow sensor reading.  If anything comes back, it's connected.
         		return(5);   // returned data is new serial number
				}
        sprintf(teststring, "NewFW");  //this tells the returned message is from the server and is a section of the FW.
			if (strstr(&WebPageTxtBuff, &teststring)!=0)
				{
				SDCardResults = 0;  // This changes the comuncations flag to allow sensor reading.  If anything comes back, it's connected.
         		return(6);   // returns the FW update
				}
return(0);
	}






//*********************************************************************************************************
// Created Augest 12, 2015
// This routine finds out what to do with all of the strings from the handheld devices.
//  The basic premise is to see if there is a GET statement and ignore error and the like.
// It also sends out the right pages to hand held device.
// / Nothing is returned for this funtion.
//*********************************************************************************************************
void webhandle(void)
	{
	
	char teststring[30];
	sprintf(teststring, "GET / ");	
		if (strstr(&WebPageTxtBuff, &teststring)!=0)
			{
 			genHostPage(" ");
			webmarshallerpointer = 0;
			savetrigger = 0;
			}
	sprintf(teststring, "GET /wifiConfig.html ");	
		if (strstr(&WebPageTxtBuff, &teststring)!=0)
			{
 			genWifiConfigPage(" ");
			webmarshallerpointer = 0;
			savetrigger = 0;
			}
	sprintf(teststring, "GET /router_submit.html");	
		if (strstr(&WebPageTxtBuff, &teststring)!=0)
			{
 			simpleSubmittedPage();   // Send out the benidition webpage.
			SaveSubmittedData();   // Save the submitted data into the SD card or what other funtions needed.
			webmarshallerpointer = 0;
			savetrigger = 1;   // This triggers the latest configuration to be saved on the SD CArd.  Added Augest 19, 2015
			}
	}







//**********************************************************************
// Created Augest 12, 2014
// This cleans the array called WebPageTxtBuff to all zeros.
// This needs to be called each a line has been parsed and the data is not needed anymore.
//**********************************************************************
void cleanWebPageTxtBuff(void)
	{
	int16 x;   //this is a dummy varaible used for pointing to the next location in the array for clearing it up.
	for (x = 0; x < WEBTEXTLENGTH; x++)
		WebPageTxtBuff[x] = 0x00;
	}
