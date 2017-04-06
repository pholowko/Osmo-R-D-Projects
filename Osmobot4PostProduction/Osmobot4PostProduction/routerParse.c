
//#include <stdio.h>

//#define MAXNUMROUTERS 10


//Test String for the parser
/*
char testStr[]="+ok=\r\n\
Ch,SSID,BSSID,Security,Signal(5)W-Mode,ExtCH,NT,WPS,DPID\r\n\
1,NETGEAR31,04:a1:51:1a:1d:73,WPA2PSK/AES,60,11b/g/n,NONE,IN,NO,\r\n\
4,2WIRE796,64:0f:28:6a:dd:59,WPA1PSKWPA2PSK/TKIPAES,0,11b/g/n,NONE,In,NO,\r\n\
\r\n";
*/



//Test program to validate functionality
/*
int main()
{
    int mainCntr=0;
    char cC;
    do
    {
    cC=testStr[mainCntr];
     
    parseRouter(routerTable,cC,0); 
     
    mainCntr++;    
    } while(cC != '\0');
    
    
    
    
    //Generate Test Router
    sprintf(routerTable[6].SSID,"Netgear31");
    sprintf(routerTable[6].secType,"WPA2PSK/AES");
    routerTable[6].sigStr=65;
    
    
    printRouter(routerTable[0]);
    printRouter(routerTable[1]);
    //printf("%s\n",testStr);

    return 0;
}
*/


//Test Function to ensure prober router data copy
void printRouter(Router router)
{ 
	//PC Version
   //printf("%s-%s-%d\n",router.SSID,router.secType,router.sigStr);  
}



int parseRouter(Router router[], char c, int RST)
{
int doneParsing=0;
//Variables    
static int rtrCntr=0;
static int charCntr=0;
static int itemCntr=-1;
static char tempBuff[42];
static int rctr=0;
static char lastChar=0;
static int timeoutCtr=0;

//Semaphores
static int newLine=0;   //Semaphore can be int1
static int logData=0;   //Semaphore can be int1

if(c==lastChar)
{
timeoutCtr++;
}


if(timeoutCtr>1500)
{
lastChar=0;
timeoutCtr=0;
rtrCntr=0;
charCntr=0;
itemCntr=0;
doneParsing=1;
rctr=0;;
}
switch(c)   //Switch what to do based on character
    {
    case ',':   //Next Item in the list
    tempBuff[charCntr]='\0';
    charCntr=0;
    itemCntr++;
    logData=1;
	newLine=0;

    break;
    
    case'\n':   //Next Line
    tempBuff[charCntr]='\0';
    newLine=1;
    //logData=1;
    charCntr=0;
    itemCntr=-1;
    

    break;
    
    case'\r':    //Check for end of response(\r\n\r\n)
    if(newLine==1)
        {
		rctr++;
		if(rctr>1)
			{
        	//printf("-----Done!-----\n");
        	rtrCntr=0;
        	charCntr=0;
        	itemCntr=0;
			doneParsing=1;
			rctr=0;;
  			}      
		}
    else
        {
        logData=1;    
        }
    break;
    
    default:    //Any other character
    tempBuff[charCntr]=c;
    charCntr++;
	newLine=0;
	rctr=0;
    break;
    }
//Resets newline if character isnt \n    
if(c!='\n')
{
newLine=0;   
}    

//printf("%d,%d,%d: %c\n",rtrCntr,itemCntr,charCntr,c);
//Do more useful stuff later, for now just print string...


if(logData==1)
    {
    //printf("%d,%d,%d: %s\n",rtrCntr,itemCntr,charCntr,tempBuff+1-1);   
    if(rtrCntr>=0)  //If actually a router, offsets compensate for extra data
        {
        switch(itemCntr)
            {
            case 1: //SSID    
            sprintf(routerTable[rtrCntr].SSID,tempBuff);
			Display_XYString(2,1,tempBuff);
			//if(strncmp(tempBuff,"SSID",3))
				//{
				routerTable[rtrCntr].sigStr=-2;//blacklist it
			//	}
            break;
            
            case 3: //Security Mode
            sprintf(routerTable[rtrCntr].secType,tempBuff);
			Display_XYString(3,1,tempBuff);
            break;
            
            case 4: //Signal Strength
		//	if(routerTable[rtrCntr].sigStr!=-2)
				//{
            	routerTable[rtrCntr].sigStr=atoi(tempBuff);
    			//}        	
			break;
                
            default:    //I Dont Care about it
            
            break;
            }
        }
    }


if(newLine==1)
    {
        //printf("-----Next Router-----\n");
        rtrCntr++;
    }

logData=0;  //Reset logData everytime 

return doneParsing; 
}





//Function sets all of the router channels equal to -1 which indicates they should not be used
void clearRouters(Router router[])
{
int cntr=0;
while(cntr<MAXNUMROUTERS)
	{
	routerTable[cntr].sigStr=-1;
	cntr++;
	}	
}


void testRouter()
{
	routerTable[0].sigStr=71;
    sprintf(routerTable[0].SSID,"NETGEAR31");
    sprintf(routerTable[0].secType,"WPA2/AES");

	routerTable[1].sigStr=15;
    sprintf(routerTable[1].SSID,"Test1");
    sprintf(routerTable[1].secType,"NONE/NONE");

	routerTable[2].sigStr=17;
    sprintf(routerTable[2].SSID,"Test2");
    sprintf(routerTable[2].secType,"WPA1PSKWPA2PSK/TKIPAES");

    sprintf(routerTable[6].SSID,"Test3");
    sprintf(routerTable[6].secType,"WPA2PSK/AES");
    routerTable[6].sigStr=65;
}



