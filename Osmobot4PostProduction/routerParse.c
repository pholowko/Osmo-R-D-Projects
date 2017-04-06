


//Test Function to ensure prober router data copy
void printRouter(Router router)
{ 
	//PC Version
   //printf("%s-%s-%d\n",router.SSID,router.secType,router.sigStr);  
}




//*****************************************************************************************************
// Create Augest 12, 2015
// This is a routiner parsing routine where it takes apart the routines and their securities and places them into router.structure.
// The needed data is as follows:  router.SSID,router.secType,router.sigSt
// An int is returned to inidicate the error status
// Assume the routertable table is global
// 0  no error
// 1 nothing as a result
//*****************************************************************************************************
int seperateRouter(char * inputstring)
	{

	char *r;
	int routernumber = 0;
	int itemnumber,limit;  // this is moved to the next item in the record set.
    int recordpointer=0;  // This is used for a pointer in each string array for each item in the routerrecord.

	limit = 55;  // set the starting position of limit counter
	for (r = inputstring + 55; *r !='\0'; *r++)   // The offset is for the text that is producted for the colmumn headers.
		{
		if (*r == '\n' || *r == '\r')  // set the parsing for the next line.  In the case of the first one, it is set to zero.
			{	
			itemnumber = 0;  // Always reset the item number when seeing a CR or LF.
			recordpointer = 0;
			}
		if (*r == ',')
			{
			itemnumber++;   // Kick to the next item in the record.
			recordpointer =  0;
			if (itemnumber > 5)
				{
				routerTable[routernumber].sigStr = 1;
				routernumber++;   // kick the router pointer if all done with this record.
                if (routernumber > 14)
					{
					return(0);   // Return to the calling routine to limit the number of routers to show.  If there are more than 15, routers, it runs out of mememorty.  This puts a limit on the length.
					}
				}
			}
        limit++;  // kick the limit counter
		if (limit > 900)
			return(0); // exit routine because there are twoo many routers taking too many characters.
        //fprintf(BT,"%i\r\n",limit);
		if (isalpha(*r) || isdigit(*r) || *r == ':' || *r == '-' ||  *r == '_' ||  *r == ' ' ||  *r == ''' ||  *r == '&' ||  *r == '^' ||  *r == '*' ||  *r == '$' ||  *r == '#' ||  *r == '@' ||  *r == '!' ||  *r == ';' ||  *r == '"' ||  *r == '|' ||  *r == '?' ||  *r == '.'  ||  *r == '~')
			{
			switch(itemnumber)
				{
				case 0:
					routerTable[routernumber].signalstreangth[recordpointer] = *r;
					recordpointer++;
					routerTable[routernumber].signalstreangth[recordpointer] = 0x00;
					break;
				case 1:
					routerTable[routernumber].SSID[recordpointer] = *r;
					recordpointer++;
					routerTable[routernumber].SSID[recordpointer] = 0x00;
					break;
				case 2:
					routerTable[routernumber].macaddr[recordpointer] = *r;
					recordpointer++;
					routerTable[routernumber].macaddr[recordpointer] = 0x00;
					break;
				case 3:
					// do nothing.  some number appears here.

				case 4:
					routerTable[routernumber].secType[recordpointer] = *r;
					recordpointer++;
					routerTable[routernumber].secType[recordpointer] = 0x00;
					break;
				case 5:
					routerTable[routernumber].authType[recordpointer] = *r;
					recordpointer++;
					routerTable[routernumber].authType[recordpointer] = 0x00;
					break;
			default:
					break;
				}
			}
		}
	fprintf(BT,"Limit number for Router Parsing  %i\r\n",limit);
	return(0);   // no error so far.
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

