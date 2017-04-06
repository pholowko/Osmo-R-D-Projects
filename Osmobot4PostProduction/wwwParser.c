//////////////////////////////////////////
//Data Storer
//////////////////////////////////////////

int ServerUp(void);


//**************************************************************************
// Created Augest 13, 2015
// The routine below takes the ACKs from the server and updates the data in the sysInput.  
// The input data is for the time and date.  There is also inputs for the SSR and all of the other Serial Number.
// This is assuming the data is from  the server.
//**************************************************************************
void StoreACKdatafromserver(void)
	{
	char term[7];     //  Array to put the first token
	strcpy(term,"~");   //This is the first token from the returned string.
	int cc,rr,terming;
//	ACKFROMSERVER = 1;   //This means there is an ACK from the server and it time to remove the last file in the buffer.

//fprintf(BT,"->this is the returned string <- %s\r\n",WebPageTxtBuff);
// We will have to do this the hard ways.

// Find the location for the "~"
	for (cc=0; cc < WEBTEXTLENGTH; cc++)
		{
		if (WebPageTxtBuff[cc] == '~')
			{
			cc++;   // Kick to the next numrical location.
			break;
			}
		}

//  Get the first number in the series.
	terming=0;
	for (rr=cc; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ',') && (WebPageTxtBuff[rr] != ' '))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.chksum	= atoi(term);
	if (sysInput.chksum != 0)
		{
		ACKFROMSERVER = 1;   //This means there is an ACK from the server and it time to remove the last file in the buffer.
		}
		else
		{
		ACKFROMSERVER = 0;   //This means there is only tickle from the server and there is only date and time.
		}
	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.year	= atoi(term);

	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.month	= atoi(term);

	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.day	= atoi(term);

	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.hour	= atoi(term);

	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.minute	= atoi(term);

	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.second	= atoi(term);

    if (ACKFROMSERVER == 1)
    {
	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	int ctrlNum	= atoi(term);
//   fprintf(BT,"This is the SSR from the server -> %i",ctrlNum);
//	int ctrlNum=strtoul(WebPageTxtBuff,&ptr,10);
			ctrlNum-=sysInput.io3;	//Get rid of that pesky 1's place
			sysInput.io2=(ctrlNum%100)/10;
			ctrlNum-=(sysInput.io2)*10;	//Get rid of that pesky 10's place
			sysInput.io1=(ctrlNum/100);
            
//*************************************************************
// Created Aug 11, 2016
// This addition is the unittype.  This works with the EEPROM and is called when the data in the EEPROM is changed.
//  It is only changed when there is new data because it would ware out the section of EEPROM if it's updated each time.
//  ***********************************************************            
            
            
     //  This saves the unittype     
	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isalpha(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
            sysInput.unittype[terming]=WebPageTxtBuff[rr];
			terming++;   // kick to next location
			term[terming] = 0x00;   // This is the terming string
		   sysInput.unittype[terming]=0x00;	
            }		
			else
			{
			rr++;
			break;
			}
		}
    
    
//*************************************************************
// Created Aug 23, 2016
// This is the low ADC value for the calibration for the bulb at a fixed ph of 4.
//  It is only changed when there is new data because it would ware out the section of EEPROM if it's updated each time.
//  ***********************************************************                  
     //  This saves the lowphADC value     
    	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.phcallow	= atof(term);
    
       
//*************************************************************
// Created Aug 23, 2016
// This is the high ADC value for the calibration for the bulb for the varaible upper limit.
//  It is only changed when there is new data because it would ware out the section of EEPROM if it's updated each time.
//  ***********************************************************                  
     //  This saves the lowphADC value     
    	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.phcalhigh	= atof(term);
    
    
       
//*************************************************************
// Created Aug 23, 2016
// This is the high pH value for the calibration for the bulb .  The default is 10
//  It is only changed when there is new data because it would ware out the section of EEPROM if it's updated each time.
//  ***********************************************************                  
     //  This saves the upper pH number assosiated with e ADC     
    	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.phnumberupper	= atof(term);
    
    
    //**************************************************************************
    // Created Aug 23, 2016
    // The following code is used to take in the calibration numbers for EC.
    //**************************************************************************
    // This one saves eccal1x
       	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.eccal1x	= atof(term); 
    
   // This one saves eccal1y
       	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.eccal1y	= atof(term); 
    
      // This one saves eccal2x
       	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.eccal2x	= atof(term); 
    
      // This one saves eccal2y
       	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.eccal2y	= atof(term); 
    
      // This one saves eccal3x
       	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.eccal3x	= atof(term); 
    
      // This one saves eccal3y
       	terming=0;
	for (; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ','))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
	sysInput.eccal3y	= atof(term); 
    
    
    
    
    
    // once the data is received, it needs to be compared with the existing unit type.
  //  fprintf(BT,"This is the unit type from the server -> %s\r\n",sysInput.unittype);
    
    }
webmarshallerpointer = 0;
	}

//**************************************************************************
// Created January 16, 2017
// The routine below takes the ACKs from the server and updates the ;latest serial number for production 
// The routine returns a 0 of all is well.
// A 1 is returned if there is a format error.
// This is assuming the data is from  the server.
//**************************************************************************
int ParseNewSerialNumberfromserver(void)
	{
	char term[16];     //  Array to put the first token
	strcpy(term,"~");   //This is the first token from the returned string.
	int cc,rr,xx;
    int32 terming;
//	ACKFROMSERVER = 1;   //This means there is an ACK from the server and it time to remove the last file in the buffer.

//fprintf(BT,"->this is the returned string <- %s\r\n",WebPageTxtBuff);
// We will have to do this the hard ways.

// Find the location for the "~"
	for (cc=0; cc < WEBTEXTLENGTH; cc++)
		{
		if (WebPageTxtBuff[cc] == '~')
			{
			cc++;   // Kick to the next numerical location.
			break;
			}
		}

//  Get the first number in the series.
	terming=0;
	for (rr=cc; rr < WEBTEXTLENGTH; rr++)
		{
		if (isdigit(WebPageTxtBuff[rr]) && (WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ',') && (WebPageTxtBuff[rr] != ' '))
			{
			term[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			term[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
    // move the new serial number into the outputsystem
    terming = atoL(term);
    fprintf(BT,"Returned Serial Number from the Server -> %s\r\n",terming);
    if ((terming > 1000000) && (terming < 3000000))
    {
    for (xx=0; xx < 16; xx++)
        sysOutput.deviceID[xx] = term[xx];
        return(0);
	}
    else
    {
        return(1);
    }
}
    

//**************************************************************************
// Created January 16, 2017
// The routine below takes the ACKs from the server and updates the ;latest serial number for production 
// The routine returns a 0 of all is well.
// A 1 is returned if there is a format error.
// This is assuming the data is from  the server.
//**************************************************************************
int ParseNewFirmWarefromserver(void)
	{
	char term[16];     //  Array to put the first token
	strcpy(term,"~");   //This is the first token from the returned string.
	int cc,rr,xx;
    int32 terming;
//	ACKFROMSERVER = 1;   //This means there is an ACK from the server and it time to remove the last file in the buffer.

//fprintf(BT,"->this is the returned string <- %s\r\n",WebPageTxtBuff);
// We will have to do this the hard ways.

// Find the location for the "~"
	for (cc=0; cc < WEBTEXTLENGTH; cc++)
		{
		if (WebPageTxtBuff[cc] == '~')
			{
			cc++;   // Kick to the next numerical location.
			break;
			}
		}

//  Get the first number in the series.
	terming=0;
	for (rr=cc; rr < WEBTEXTLENGTH; rr++)
		{
		if ((WebPageTxtBuff[rr] != '\n')  && (WebPageTxtBuff[rr] != '\r') && (WebPageTxtBuff[rr] != ',') && (WebPageTxtBuff[rr] != ' '))
			{
			uffit[terming] = WebPageTxtBuff[rr];   // move the character over
			terming++;   // kick to next location
			uffit[terming] = 0x00;
			}		
			else
			{
			rr++;
			break;
			}
		}
    // move the new serial number into the outputsystem
 
    fprintf(BT,"Returned FirmWare Line from Server -> %s\r\n",uffit);
    return(0);

}
    
