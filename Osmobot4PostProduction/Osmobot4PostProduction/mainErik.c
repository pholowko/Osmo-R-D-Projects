#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bgetc(void);

char dataSplitter();

char teststring[]="+ok=on\n\nGET\nSome\nStuff\n\nHTTP\n<html>\n\ndata\nCrab\nBarnacle\nEmu\nArdvark\n\n\n\n\n\n\n</html>+ok=\nCH:ID:ECT\n01:11:LOL\n02:22:KEK\n03:33:DRP\n\nrandomzzzzzz\nHTTP / 1.1 Stuff\nI Completely forgot\nWhat goes here\nbut thats ok for now\n\n";
int nextOut=0;
int nextIn;
#define bkbhit2 (nextIn!=nextOut)

#include <Stringsplitter.h>

int main(int argc, char **argv)
{
nextIn=strlen(teststring);	


//printf("Hello World!\n");
dataSplitter();

	
	
	return 0;
}






char bgetc(void)
{
char c=teststring[nextOut];
nextOut++;
return c;	
}





//Function That takes Data Input 
#define SPLITTERDEBUG 1
#ifndef int1
#define int1 int
#endif
#define bkbhit (nextIn!=nextOut)
char dataSplitter()
{
char stateType=0;
int1 isSet=0;	//Lazy way of checking if one of the modes is on
int1 nsaWATCHLIST=0;	//used to identify when one of a series of escape characters is seen


/*
int8 HTTPCTR=0;
int8 WWWCTR=0;
int8 ATCTR=0;
int8 ENGRCTR=0;
*/
//fprintf(WIFI,"%i\r\n",bkbhit);
//char daBuff[24];
while(bkbhit)
	{
	char c=bgetc();
	
	
	
//fprintf(WIFI,"%c\r\n",c);
////////////////////////////////////////////////////////////	
	if(isSet==0)
		{
		nsaWATCHLIST=0;
		//Try to figure out what the hell is going on
		switch(c)
			{
			case 'H':	//HTTP/1.1 ...
			stateType='w';
			isSet=1;
			break;
			case 'G':	//GET ...
			stateType='r';
			isSet=1;
			break;
			case '+':	//+ok= ...
			stateType='a';
			isSet=1;
			break;
			case 'E':	//TBD
			stateType='e';
			isSet=1;
			break;
			default:		//None of the above keep going
			stateType=0;
			isSet=0;
			break;
			}

		#if SPLITTERDEBUG
		printf("\nState:%c\n",stateType);
		//fprintf(WIFI,"HI\n");
		//fprintf(WIFI,"%c\n",stateType);
		#endif
		}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
	else	//if you know what you're doing
		{
		switch(stateType)
			{
			//OSMOBOT.ORG gangster stuff
			case 'w':

			if(nsaWATCHLIST==1)
			{
			if(c=='h')		//Identity verified
				{
				//go back to not knowing what you're doing
				isSet=0;	
				stateType=0;	
				nsaWATCHLIST=0;
				}
			else
				{
				nsaWATCHLIST=0;				
				}
			}
			

			
			
			if(c=='/')	//</html>
			{
			nsaWATCHLIST=1;	//Youre on a list
			}
			


			//parseHTTP(c,daBuff);	//Parse the character

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
				nsaWATCHLIST=0;
				}
			else
			{
			nsaWATCHLIST=0;				
			}	
				
			}
			if(c=='\n')	//</html>
			{
			nsaWATCHLIST=1;	//Youre on a list
			}


			//Parse your web request somewhere here



			break;


			//AT commands...
			case 'a':
	//Have to do this first because 2 consecutive characters are the same
			if(nsaWATCHLIST==1)
			{
			if(c=='\n')		//Identity verified
				{
				//go back to not knowing what you're doing
				isSet=0;	
				stateType=0;	
				nsaWATCHLIST=0;
				}
			else
				{
				nsaWATCHLIST=0;				
				}	
			}
			
			if(c=='\n')	//</html>
			{
			nsaWATCHLIST=1;	//Youre on a list
			}


			//Parse your AT Commands somewhere here



			break;


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
		
						

			
///////////////////////////////////////////////
		}

	}
	
	printf("%c",c);
	
	if(nsaWATCHLIST){
		
	//printf("-ON A NSA WATCH LIST	");
	}
	
	}
#if SPLITTERDEBUG
//fprintf(WIFI,"%c\n",stateType);
//fprintf(WIFI,"%c\n",'m');
//fputc(stateType,WIFI);
//fputc('\n',WIFI);

#endif
return stateType;
}

