

//unsigned int8 httprlinecntr=0;




void sendTestPage(void)
{
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\nHello World!\n<br />This Is The Root Page\n<br />\n</html>\r\n");
}

void sendTestPage2(char requestedPage[])
{
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\nYou Requested Page: \n%s\n<br />\n</html>\r\n",requestedPage);
}

void send404Page(requestedPage[])
{
fprintf(WIFI,"HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\nThe Requested Page: OSMOBOTIP:PORT%s Does Not Exist, Sorry.\n<br />\n</html>\r\n",requestedPage);
}



void sendHTTPPage(char pageString[])
{
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n%s\r\n\r\n",pageString);
//delay_ms(1000);
}


void genTestPage(char outString[])
//void genWifiConfigPage(char outString[])
{
//OLD PAGE NO AUTHENTICATION SELECT
/*
sprintf(outString,"\
<html>\
<body>\
<form action=\"router_submit.html\" method=\"get\">\
  Router name: <input type=\"text\" name=\"SSID\"><br>\
  Router Password: <input type=\"text\" name=\"PASS\"><br>\
  Auth: <input type=\"text\" name=\"AUTH\"><br>\
  Enc: <input type=\"text\" name=\"ENCRYPT\"><br>\
  <input type=\"submit\" value=\"Submit\">\
</form>\
</body>\
</html>\
\r\n");
*/
outstring[0]='\0';
//NEW PAGE Basoc
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
fprintf(WIFI,"<html><body><form action=\"router_submit.html\" method=\"get\">Router name: <input type=\"text\" name=\"SSID\"><br>Router Password: <input type=\"text\" name=\"PASS\"><br>");
fprintf(WIFI,"Auth: <select  name=\"AUTH\"><option value=\"OPEN\">OPEN</option><option value=\"SHARED\">SHARED</option><option value=\"WPAPSK\">WPAPSK</option><option value=\"WPA2PSK\" selected=\"selected\">WPA2PSK</option></select>");
fprintf(WIFI,"</br>Enc: <select  name=\"ENCRYPT\"><option value=\"NONE\">NONE</option><option value=\"WEP\">WEP</option><option value=\"TKIP\">TKIP</option><option value=\"AES\" checked=\"checked\"");
fprintf(WIFI,"selected=\"selected\">AES</option></select></br><input type=\"submit\" value=\"Submit\"></form></body></html>\r\n\r\n");
//delay_ms(1000);
}

//void genTestPage(char outString[])
void genWifiConfigPage(char outString[])
{
/* //Original Test Page
sprintf(outString,"<!DOCTYPE HTML>\n<html>\nHello World!\n<br />This Is The Test Page\n<br />\n</html>");
*/
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
fprintf(WIFI,"<!DOCTYPE html><html><script>\n function handleRBClick(){checkval=document.querySelector('input[name = \"SSIDr\"]:checked').value; checksec=document.querySelector('input[name = \"SSIDr\"]:checked').title;");
fprintf(WIFI,"if(checkval==\"~!$Other\"){visVar=\"visible\";} else{visVar=\"hidden\"; document.getElementById(\"SSIDtb\").value=\"\";} document.getElementById(\"SSIDtb\").style.visibility=visVar;");
fprintf(WIFI,"document.getElementById(\"customProperties\").style.visibility=visVar;\nif(checksec.indexOf(\"NONE\")>-1) {document.getElementById(\"pwdiv\").style.visibility=\"hidden\"; document.getElementById('PASStb').value=\"\";}\n");
fprintf(WIFI,"else{document.getElementById(\"pwdiv\").style.visibility=\"visible\";}}function submitForm() {var ssidval = document.querySelector('input[name = \"SSIDr\"]:checked').value;");
fprintf(WIFI,"var encrypStr = document.querySelector('input[name = \"SSIDr\"]:checked').title; if(ssidval==\"~!$Other\"){document.getElementById('SSIDh').value=document.getElementById('SSIDtb').value;");
fprintf(WIFI,"document.getElementById('AUTHh').value=document.getElementById('AUTHDM').value; document.getElementById('ENCRYPTh').value=document.getElementById('ENCRYPTDM').value;}\n");
fprintf(WIFI,"else{document.getElementById('SSIDh').value=ssidval;\nif(encrypStr.indexOf(\"WPA2\")>-1){document.getElementById('AUTHh').value=\"WPA2PSK\";}\n");
fprintf(WIFI,"else if(encrypStr.indexOf(\"SHARED\")>-1){document.getElementById('AUTHh').value=\"SHARED\";}\nelse if(encrypStr.indexOf(\"WPAPSK\")>-1){document.getElementById('AUTHh').value=\"WPAPSK\";}\nelse{document.getElementById('AUTHh').value=\"OPEN\";}\n");  
fprintf(WIFI,"if(encrypStr.indexOf(\"AES\")>-1){document.getElementById('ENCRYPTh').value=\"AES\";}\nelse if(encrypStr.indexOf(\"TPIK\")>-1){document.getElementById('ENCRYPTh').value=\"TPIK\";}\n");   
fprintf(WIFI,"else if(encrypStr.indexOf(\"WEP\")>-1){document.getElementById('ENCRYPTh').value=\"WEP\";}\nelse{document.getElementById('ENCRYPTh').value=\"NONE\";}\n}");
fprintf(WIFI,"document.getElementById('PASSh').value=document.getElementById('PASStb').value; document.getElementById('Rsmt').submit();}</script>");       
fprintf(WIFI,"<body><table WIDTH=\"80%%\"><form name=\"Router List\"><tr bgcolor=\"#e8e8e8\"><TD WIDTH=\"110\" class=\"main\">&nbsp;&nbsp;&nbsp;Select Router:</TD><TD class=\"main\" valign=\"top\">");
fprintf(WIFI,"<div id=\"SSIDrb\" onclick=\"handleRBClick()\">\n\n");
//Router Table Custom Text 
int rctr=0;
int ractr=1;
while(rctr<MAXNUMROUTERS)
{
	if(routerTable[rctr].sigStr>-1)
	{
	if(strstr(routerTable[rctr].SSID,"SSID")==NULL)
		{
		fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb%d\" type=\"radio\" value=\"%s\" title=\"%s\"> %s (%s%%)<br />\n",ractr,routerTable[rctr].SSID,routerTable[rctr].secTYPE,routerTable[rctr].SSID,routerTable[rctr].signalstreangth);
		ractr++;
		}
	}
rctr++;
}
fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb%d\" type=\"radio\" value=\"~!$Other\" title=\"Other\" checked=\"checked\">\n\n",ractr);

/*
fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb1\" type=\"radio\" value=\"NETGEAR31\" title=\"WPA2/AES\"> NETGEAR31<br />\n");
fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb2\" type=\"radio\" value=\"Test1\" title=\"NONE/NONE\"> Test1<br />\n");
fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb3\" type=\"radio\" value=\"Test2\" title=\"NONE/NONE\"> Test2<br />\n");
fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb4\" type=\"radio\" value=\"Test3\" title=\"WPA1PSKWPA2PSK/TKIPAES\"> MyRouter<br />\n");
fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb5\" type=\"radio\" value=\"~!$Other\" title=\"Other\" checked=\"checked\">\n\n");
*/
//Back To Stock Text
fprintf(WIFI,"Other: <input type=\"text\" name=\"SSIDrt\" id=\"SSIDtb\" width=\"250\" value=\"\" /><br /></div></TD></tr><tr bgcolor=\"#e8e8e8\"><td TD WIDTH=\"110\" class=\"main\">\n");
fprintf(WIFI,"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Security:</td><TD><div id=\"pwdiv\">Password: <input type=\"text\" name=\"PASS\" id=\"PASStb\" value=\"\" width=\"250\" /><br /></div><div id=\"customProperties\">\n");
fprintf(WIFI,"Auth: <select id=\"AUTHDM\"><option value=\"OPEN\">OPEN</option><option value=\"SHARED\">SHARED</option><option value=\"WPAPSK\">WPAPSK</option><option value=\"WPA2PSK\" selected=\"selected\">WPA2PSK</option></select>\n"); 

//Potentially a trouble line
fprintf(WIFI,"Enc: <select id=\"ENCRYPTDM\"><option value=\"NONE\">NONE</option><option value=\"WEP\">WEP</option><option value=\"TKIP\">TKIP</option><option value=\"AES\" checked=\"checked\" selected=\"selected\">AES</option></select>");     
//        
fprintf(WIFI,"\n</div></TD></tr></form></table><table></table><form name=\"Router Submit\" id=\"Rsmt\" action=\"router_submit.html\"  method=\"get\" onsubmit=\"return submitForm();\">\n");
fprintf(WIFI,"<input type=\"hidden\" name=\"SSID\" id=\"SSIDh\" value=\"\" ><input type=\"hidden\" name=\"PASS\" id=\"PASSh\" value=\"\"><input type=\"hidden\" name=\"AUTH\" id=\"AUTHh\" value=\"\">\n");
fprintf(WIFI,"<input type=\"hidden\" name=\"ENCRYPT\" id=\"ENCRYPTh\" value=\"\"><input type=\"submit\" value=\"Submit\"></form>\n</body></html>\r\n\r\n");
//delay_ms(1000);

//Test of the big router page

}

void genSubmittedPage(char outString[], char SSID[], char PASSSTR[])
{
sprintf(outString,"<!DOCTYPE HTML>\n<html>\nThank You!\n<br />Router Info Submitted\n<br />SSID:%s\n<br />Password:%s\n</html>",SSID,PASSSTR);
}

//void sendSubmittedPage(char SSID[], char PASSSTR[])
//{
//fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
//fprintf(WIFI,"<!DOCTYPE HTML>\n<html>\nRouter Name, Password and Encryption Configured\n<br />Osmobot is reconfiguring and booting\n<br />SSID:%s\n<br />Password:%s\n</html>",SSID,PASSSTR);
//}


void simpleSubmittedPage()
{
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
//fprintf(WIFI,"<!DOCTYPE HTML>\n<html>\nThank You!\n<br />Router Info Submitted\n</html>\r\n\r\n");   // changed over to a more meaningfull message
fprintf(WIFI,"<!DOCTYPE HTML>\n<html>\nRouter Name, Password and Encryption Configured\n<br />Osmobot is reconfiguring and booting\r\n\r\n</html>");
}

void genHostPage(char outString[])
{

//New Home Page with Internet Link Indicator
outString[0]='\0';
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
fprintf(WIFI,"<!DOCTYPE HTML>\n<html>\n<script>function checkCxn(connected){c=document.getElementById('CXN');\nif(connected){c.innerHTML+='connected to the internet.';}\n");
fprintf(WIFI,"else{c.innerHTML+='not connected to the internet.';}}</script><div id=\"CXN\">Osmobot is </div><br />Links:<br />");
fprintf(WIFI,"<img src='http://osmobot.org/singlepixel.gif' style=\"display:none\" onload=\"checkCxn(1)\" onerror=\"checkCxn(0)\" />");
//fprintf(WIFI,"<a href=\"wifiConfig.html\">Wifi Config</a><br/><a href=\"test.html\">Test Page</a><br/></html>");   //  this is being removed to get rid of test link.  But is still in to check for debugging.
fprintf(WIFI,"<a href=\"wifiConfig.html\">Wifi Config</a><br/></html>");
//delay_ms(1000);
}






//********************************************************************************************************
// Created Augest 19, 2015
// Ths routine takes the values from the submitted webpage and moves them into the router configuration variables.
// It also saves them in the SD Card.  It then sends a signal for the unit to restart the process of configuring the Wifi from the beginning with the new read data from the SD Card.
// The input to the routine is WebPageTxtBuff.  It is used to parse the "GET" command line.  The information for the passed information is between tbe GET and the http/1.1
//********************************************************************************************************
void SaveSubmittedData(void)
	{

    int x,z;  // general variable for the current pointer to the filter   Z is used for the past filter pointer
        //***************************************************************
        // Created April 27, 2016
        //  This code takes the UTF-8 character sequence and makes since 8 bit characters from web browsers.
        //  There are two pointers, one for the current location and the second for the scanning location.  The characters are always less in length than the ASCII version.
        //*************************************************************
        
  //      UTF8Decode(char next, unsigned int32 **dst);  
    
		char *ssidpntr= strstr(WebPageTxtBuff,"SSID=")+5;
		char *doneptr= strchr(WebPageTxtBuff,'&');
	
		strncpy(STA_SSID,ssidpntr,(doneptr-ssidpntr));
        
		strncpy(STA_SSID+(doneptr-ssidpntr),"\0",1);

        
        //****************************************************
        // Created June 17, 2016
        //  This routine is added to remove international % hex strings from the returned information from the web browser
        // It checks each string of data and replaces it with the char code assocated in  hex.
        //****************************************************
        sprintf(Configuration,"%s",STA_SSID);
        DecodeWebPageCode();   // convert the hex browser code into characters
        sprintf(STA_SSID,"%s",Configreturn);

		char *passpntr= strstr(WebPageTxtBuff,"PASS=")+5;
		doneptr= strchr(passpntr,'&');

		strncpy(STA_PW,passpntr,doneptr-passpntr);

		strncpy(STA_PW+(doneptr-passpntr),"\0",1);

        //****************************************************
        // Created June 17, 2016
        //  This routine is added to remove international % hex strings from the returned information from the web browser
        // It checks each string of data and replaces it with the char code assocated in  hex.
        //****************************************************
        sprintf(Configuration,"%s",STA_PW);
        DecodeWebPageCode();    // convert the hex browser code into characters
        sprintf(STA_PW,"%s",Configreturn);
        
		char *authpntr= strstr(WebPageTxtBuff,"AUTH=")+5;

		doneptr= strchr(authpntr,'&');

		strncpy(STA_AUTH,authpntr,doneptr-authpntr);

		strncpy(STA_AUTH+(doneptr-authpntr),"\0",1);
        
        
        //****************************************************
        // Created June 17, 2016
        //  This routine is added to remove international % hex strings from the returned information from the web browser
        // It checks each string of data and replaces it with the char code assocated in  hex.
        //****************************************************
        sprintf(Configuration,"%s",STA_AUTH);
        DecodeWebPageCode();    // convert the hex browser code into characters
        sprintf(STA_AUTH,"%s",Configreturn);
        
		
		char *encpntr= strstr(WebPageTxtBuff,"ENCRYPT=")+8;
//		doneptr= strchr(encpntr,'\0');
		doneptr= strchr(encpntr,' ');
		
		strncpy(STA_ENC,encpntr,encpntr-passpntr);
		strncpy(STA_ENC+(doneptr-encpntr),"\0",1);	

int rctr=0;
while(rctr<MAXNUMROUTERS)
{
	if(routerTable[rctr].sigStr>-1)
	{
	if((!strcmp(routerTable[rctr].SSID,STA_SSID)) && (strlen(routerTable[rctr].SSID) > 0))
		{
		strncpy(STA_ENC, routerTable[rctr].secType, 6);
		strncpy(STA_AUTH, routerTable[rctr].authType, 8);		
		}
	}
rctr++;
}
	

	}




void copyCredentials(char target[], char source[])
{
char c;
int8 charcntr=0;
while((c=source[charcntr])!='&')
	{
	target[charcntr]=c;
	}
target[charcntr]='\0';
}

//**************************************************************
// Created June 3, 2016
//  This routine is a UTF-8 filter that replaces the HTML webpae internatinal character string into ASCII
//  just for the WIFI chip.
// The pointer foe dst is the return string pointer and the pnt pointer is the orignal sting.
//  The dst pointer string ends with a null terminator and can be used for normal operations.
//  If there is "%" codes, it then is translated into ASCII characters.
//*************************************************************



//    char Configuration[256],charout;   /// This is used by the I2C EEPROM for testing.
//    char Configreturn[256];   /// This is used by the I2C EEPROM for testing.
void DecodeWebPageCode(void)
{
    char returnedstring;
    char temparray[2];
    int concat, inputpointer, outputpointer;
    inputpointer=0;
    outputpointer=0;
    while(Configuration[inputpointer] != 0)
    {
    if (Configuration[inputpointer] == 0x25 & isdigit(Configuration[inputpointer + 1]) & isdigit(Configuration[inputpointer +2]))
    {
      temparray[1] = 0;   // null terminator
      temparray[0] = Configuration[inputpointer + 1];
      concat = 16 * atoi(temparray);
      temparray[0] = Configuration[inputpointer + 2];
      concat = concat + atoi(temparray);
      Configreturn[outputpointer] = (char) concat;
      outputpointer++;
      inputpointer++;   //  Kick the input to the next location after the three characters are used for this code.
      inputpointer++;
      inputpointer++;
    }
    else
    {
        Configreturn[outputpointer] = Configuration[inputpointer];  // this is an understood character.  Just pass it through
        inputpointer++;
        outputpointer++;
    }
    }
    //outputpointer++;
    Configreturn[outputpointer] = 0;  //  Add the null terminator and exit the routine filter.
}
