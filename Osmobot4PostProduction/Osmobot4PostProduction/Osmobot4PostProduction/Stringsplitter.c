

//Function That takes Data Input 
#define SPLITTERDEBUG 0
#define LAZYDEBUG 0
#ifndef int1
#define int1 int
#endif



//char dataSplitter(int bkbhit)
char dataSplitter()
{
static char stateType=0;
static int1 isSet=0;	//Lazy way of checking if one of the modes is on
static int1 nsaWATCHLIST=0;	//used to identify when one of a series of escape characters is seen
//static int1 resetbuff=0;

if(resetParsing)
{
stateType=0;
isSet=0;
resetParsing=0;
ISWWWPARSE=0;
}

//int8 HTTPCTR=0;
//int8 WWWCTR=0;
//int8 ATCTR=0;
//int8 ENGRCTR=0;

//fprintf(WIFI,"%i\r\n",bkbhit);
//static char daBuff[24];
char daBuff[24];
char requestBuff[255];

while(bkbhit)
	{
	char c=bgetc();
	#if LAZYDEBUG
	char atstbuf[6];
	sprintf(atstbuf,"%c,%d",c,USEAT);
	Display_XYString(0,4,atstbuf);
	#endif
	
//fprintf(WIFI,"%c\r\n",c);
////////////////////////////////////////////////////////////	
	if(isSet==0)
		{
		//if(c=='\n'){
	//	VacWriteChar('n');
	//	}
	//	else
	//	{

	//	}
		nsaWATCHLIST=0;
		//Try to figure out what the hell is going on
		char dispBuff[20];
		switch(c)
			{
			case 'H':	//HTTP/1.1 ...
			stateType='w';
			isSet=1;
			//VacWriteChar('[');
			break;
			case 'G':	//GET ...
			stateType='r';
			isSet=1;
			//VacWriteChar('[');
			break;
			case '+':	//+ok= ...
			if(WFIsConfig==0)
			{
			stateType='a';
			isSet=1;
			}

			if(ROUTERSCANING==1)
			{
			stateType='s';
			isSet=1;
			}

			//VacWriteChar('[');
			break;
			case 'E':	//TBD
			stateType='e';
			isSet=1;
			//VacWriteChar('[');
			break;
			default:		//None of the above keep going
			stateType=0;
			isSet=0;
			
			break;
			}


		#if SPLITTERDEBUG
		//printf("\nState:%c\n",stateType);
		//fprintf(WIFI,"HI\n");
		//fprintf(WIFI,"%c\n",stateType);
		//VacWriteChar(stateType);
		//VacWriteChar(':');
		VacWriteChar(c);
		#endif
		}
		
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
	else	//if you know what you're doing
		{
				#if SPLITTERDEBUG
				VacWriteChar(c);
				#endif
		switch(stateType)
			{
			//OSMOBOT.ORG gangster stuff
			case 'w':
			ISWWWPARSE=1;
			if(nsaWATCHLIST==1)
			{
			if(c=='h')		//Identity verified
				{
				//go back to not knowing what you're doing
				isSet=0;	
				stateType=0;
				setServer();
				ISWWWPARSE=0;
				#if SPLITTERDEBUG
				VacWriteChar(']');
				#endif	
				}
			else
				{
				nsaWATCHLIST=0;				
				}
			}

			if(c=='/')	//</html>
			{
			nsaWATCHLIST=1;	//Youre on a list
			#if SPLITTERDEBUG
			VacWriteChar('|');
			#endif
			}


			parseHTTP(c,daBuff);	//Parse the character
			break;



			//Someone wants a webpage
			case 'r':
			//Have to do this first because 2 consecutive characters are the same
			if(nsaWATCHLIST==1)
			{
			if(c=='\n')		//Identity verified
				{
				//go back to not knowing what you're doing
				isSet=0;	
				stateType=0;
				#if SPLITTERDEBUG
				VacWriteChar(']');	
				#endif
				}
			else
				{
				nsaWATCHLIST=0;
				}
			}
			if(c=='\n')	//</html>
			{
			//VacWriteChar('|');
			nsaWATCHLIST=1;	//Youre on a list
			}


			//Parse your web request somewhere here
			//VacWriteChar(c);
#if USEWEBSERVER
			if(getRequestLine(c,requestBuff))
				{
				
				if(lineIsGetRequest(requestBuff))
					{
				//	VacDisplayClear();
				//	Display_XYString(0,1,requestBuff);
					if(parseGetRequest(requestBuff,requestURLBuff))
					{
					//sendTestPage();
					//sendTestPage2(requestURLBuff);
					//send404Page(requestURLBuff);
					osmobotServePage(requestURLBuff);
					}
					else
					{
					//sendTestPage();
					genHostPage(WebPageTxtBuff);
					//sendHTTPPage(WebPageTxtBuff);
					//genWifiConfigPage(WebPageTxtBuff);
					//genTestPage(WebPageTxtBuff);
					//sendHTTPPage(WebPageTxtBuff);
					}
				}
			}
#endif
			break;


			//AT commands...
			case 'a':

			if(USEAT==0)
			{
				isSet=0;	
				stateType=0;
			}
	//Have to do this first because 2 consecutive characters are the same
			if(nsaWATCHLIST==1)
			{
			//VacWriteChar('b');
			if(c=='\n')		//Identity verified
				{
				//go back to not knowing what you're doing
				isSet=0;	
				stateType=0;
				#if SPLITTERDEBUG
				VacWriteChar(']');
				#endif	
				}
			else
				{
				nsaWATCHLIST=0;
				//VacWriteChar('x');
				}
			}
			VacWriteChar(c);
			if(c=='+')
				{
				checkATOK=1;
				}
			else if(c=='o')
				{
				ATisOK=checkATOK;
				checkATOK=0;
				}
			else
				{
				}
			
			break;



			if(c=='\r')	//</html>
			{
			//VacWriteChar('?');
			nsaWATCHLIST=1;	//Youre on a list
			}


			//Parse your AT Commands somewhere here
			

				

			//Engineering config stuff
			case 'e':
				//Just to make sure we dont get stuck for now
				isSet=0;	
				stateType=0;
			break;

			//WHAT?
			default:
			//DO NOT PASS GO DO NOT COLLECT $200

			stateType=0;
			isSet=0;
			break;
			

			//scan for routers
			case 's':
			VacWriteChar(c);

			if(c=='+')
			{
				checkScanError=1;
			}
			else if(c=='E')	//Check For Error
			{
			if(checkScanError)
			{
			SCANERROR=checkScanError;
			VacWriteChar('!');
			delay_ms(500);
				}
			}
			else
			{
			checkScanError=0;
			}


							
			if(parseRouter(routerTable,c,0))	//Runs the parser and checks if its done
			{
				isSet=0;	
				stateType=0;
				ROUTERSCANING=0;
				resetParsing=1;
			}
			break;
///////////////////////////////////////////////
		}

	}
	
	//printf("%c",c);
	
	}
#if SPLITTERDEBUG
//fprintf(WIFI,"%c\n",stateType);
//fprintf(WIFI,"%c\n",'m');
//fputc(stateType,WIFI);
//fputc('\n',WIFI);

#endif
return stateType;
}

