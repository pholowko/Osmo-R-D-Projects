//////////////////////////////////////////
//Data Storer
//////////////////////////////////////////



//sysOutput.,sysInput.



void storeRecievedData(char strBuff[], unsigned int8 index, unsigned int8 dataSet)
{
char *garbage;	//Just to please the string function gods...
fprintf(BT,"->this is the returned string <- %s\r\n",strBuff);
switch(dataSet)
	{	
	case 0:	//Checksum Value
	sysInput.chksum=strtoul(strBuff,&garbage,10);

	break;

	case 1:	//Time
	
		switch(index){
			case 0://year
			sysInput.year=strtoul(strBuff,&garbage,10);
			break;

			case 1://month
			sysInput.month=strtoul(strBuff,&garbage,10);
			break;

			case 2://day
			sysInput.day=strtoul(strBuff,&garbage,10);
			break;

			case 3://hour
			sysInput.hour=strtoul(strBuff,&garbage,10);
			break;

			case 4://minute
			sysInput.minute=strtoul(strBuff,&garbage,10);
     
			break;

			case 5://second
			sysInput.second=strtoul(strBuff,&garbage,10);
			break;

		}
	break;

	case 2:	//General Control
//	TCPHold=0;

switch(index){
			case 0://Serial Number
			//nothing for now add SN check later
			break;

			case 1://SSR Control BITS
			//////////Recieved:###
			///////Bit Mapping:123
			int ctrlNum=strtoul(strBuff,&garbage,10);
			sysInput.io3=(ctrlNum%10);
			ctrlNum-=sysInput.io3;	//Get rid of that pesky 1's place
			sysInput.io2=(ctrlNum%100)/10;
			ctrlNum-=(sysInput.io2)*10;	//Get rid of that pesky 10's place
			sysInput.io1=(ctrlNum/100);

			
			break;

			case 2://month
			//Stuff?
			break;

			case 3://month
			//Stuff?
			break;

			case 4://month
			//Stuff?
			break;

			case 5://month
			//Stuff?
			break;

			}			
	break;

	default:
	//nothing
	break;

	}
} 




/////////////////////////////////////
//End Stored Recieved Data
////////////////////////////////////




#define HTTPDEBUG 0



/////////////////////////////////////////////
//Text Parser
/////////////////////////////////////////////
 int1 startText=0;
 unsigned int8 i = 0;
 unsigned int8 valNum =0;
 unsigned int8 dataSet=0;



void parseHTTP(char c, char tempBuff[])
{
 
//if(testcntr>2500000)
if(1)
{

fprintf(BT,"Testing Values -> c %c,valNum -> %i,dataSet -> %i",c,valNum,dataSet);
	
		if(c=='~')
		{
			#if HTTPDEBUG 
				Display_XYString(10,1,"1");
			#endif
		startText=1;
		valNum =0;
		dataSet=0;
		}
	if(startText)	//once you're in the meat of the code
	{

		switch(c){
		case'~':
		//Nothing
		break;

		case']':
		startText=0;
			#if HTTPDEBUG 
				Display_XYString(10,1,"0");
			#endif
		break;

		case',':	//next number
		tempBuff[i]='\0';	//Ensures that buffer wont be overwritten in a way that causes data corruption
		storeRecievedData(tempBuff,valNum,dataSet);
		i=0;
		valNum++;

		
			//Display_XYString(7,2,tempBuff);
            fprintf(BT,"returned Cal String  %s\n\r", tempBuff);
		

		break;

		case'\n':	//Next Dataset
		tempBuff[i]='\0';	//Ensures that buffer wont be overwritten in a way that causes data corruption
		storeRecievedData(tempBuff,valNum,dataSet);
		i=0;
		valNum=0;
		
			fprintf(BT,"returned Cal String  %s\n\r", tempBuff);
		
		dataSet++;
		break;
	
		default:	//Regular ol' number
		tempBuff[i]=c;	//add the character to the buffer
		i++;	//increment
		break;
		}

	}
	
	}	
}
///////////////////////////////////////////////////////
//End Text Parser
///////////////////////////////////////////////////////









