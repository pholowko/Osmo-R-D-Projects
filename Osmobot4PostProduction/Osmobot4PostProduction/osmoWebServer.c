/*
static int danweb_readline_client (char *buf, int length)
{
	if (!client.available())
		return -1;

	int8 count = 0;
	char c;
	while ((c = client.read()) > 0) {
		if (c == '\r')
			continue;
		if (c == '\n')
			break;
		if (count >= length)
			break;
		buf[count++] = c;
	}
	buf[count] = 0;
	return count;
}
*/


#define SERVERLCD 0


unsigned int8 httprlinecntr=0;

//Parse a Line of HTTP Request, returns 1 if end of line returns 0 otherwise
int1 getRequestLine(char c, char buff[])
{
//Reached The End of a Line
buff[httprlinecntr]=c;
int1 returnval =0;
if(c=='\n')
	{

	buff[httprlinecntr+1]='\0';
	httprlinecntr=0;
	returnval=1;
	}
//Any Other Character
else
	{
	httprlinecntr++;
	//return 0;
	}	
return returnval;
}


int1 lineIsGetRequest(char buff[])
{
	// Looks for GET in the line
//	if (strstr(buff, "GET ") != 0)
if (buff[0]=='G')
		{
		return 1;
		}
	else
		{
		return 0;
		}
}



//Returns 1 if the request has a page text, 0 if blank host request
int1 parseGetRequest(char lineBuff[], char pageRequestBuff[])
{
//No Page Requested
if(lineBuff[5]==' ')
	{
	pageRequestBuff[0]='\0';	//Blank it just in case
	#if SERVERLCD
	VacDisplayClear();
	Display_XYString(0,1,"ROOT PAGE");
	#endif
	return 0;
	}
//There is a type of page
else
{
int16 pageParseCntr=0;
char c;
//Copy The Request Text
while((c=lineBuff[4+pageParseCntr])!=' ')//Get Character until space
{
pageRequestBuff[pageParseCntr]=c;
pageParseCntr++;
}
//Null Terminate The String After parsing
pageRequestBuff[pageParseCntr]='\0';
	#if SERVERLCD
	VacDisplayClear();
	Display_XYString(0,1,pageRequestBuff);
	#endif
}

}

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
delay_ms(1000);
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
delay_ms(1000);
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
fprintf(WIFI,"else if(encrypStr.indexOf(\"SHARED\")>-1){document.getElementById('AUTHh').value=\"SHARED\";}\nelse{document.getElementById('AUTHh').value=\"OPEN\";}\n");  
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
		fprintf(WIFI,"<input name=\"SSIDr\" id=\"SSIDrb%d\" type=\"radio\" value=\"%s\" title=\"%s\"> %s (%d%%)<br />\n",ractr,routerTable[rctr].SSID,routerTable[rctr].secTYPE,routerTable[rctr].SSID,routerTable[rctr].sigStr);
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
fprintf(WIFI,"Auth: <select id=\"AUTHDM\"><option value=\"OPEN\">OPEN</option><option value=\"SHARED\">SHARED</option><option value=\"WPA2PSK\" selected=\"selected\">WPA2PSK</option></select>\n"); 

//Potentially a trouble line
fprintf(WIFI,"Enc: <select id=\"ENCRYPTDM\"><option value=\"NONE\">NONE</option><option value=\"WEP\">WEP</option><option value=\"TKIP\">TKIP</option><option value=\"AES\" checked=\"checked\" selected=\"selected\">AES</option></select>");     
//        
fprintf(WIFI,"\n</div></TD></tr></form></table><table></table><form name=\"Router Submit\" id=\"Rsmt\" action=\"router_submit.html\"  method=\"get\" onsubmit=\"return submitForm();\">\n");
fprintf(WIFI,"<input type=\"hidden\" name=\"SSID\" id=\"SSIDh\" value=\"\" ><input type=\"hidden\" name=\"PASS\" id=\"PASSh\" value=\"\"><input type=\"hidden\" name=\"AUTH\" id=\"AUTHh\" value=\"\">\n");
fprintf(WIFI,"<input type=\"hidden\" name=\"ENCRYPT\" id=\"ENCRYPTh\" value=\"\"><input type=\"submit\" value=\"Submit\"></form>\n</body></html>\r\n\r\n");
delay_ms(1000);

//Test of the big router page

}

void genSubmittedPage(char outString[], char SSID[], char PASSSTR[])
{
sprintf(outString,"<!DOCTYPE HTML>\n<html>\nThank You!\n<br />Router Info Submitted\n<br />SSID:%s\n<br />Password:%s\n</html>",SSID,PASSSTR);
}

void sendSubmittedPage(char SSID[], char PASSSTR[])
{
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
fprintf(WIFI,"<!DOCTYPE HTML>\n<html>\nThank You!\n<br />Router Info Submitted\n<br />SSID:%s\n<br />Password:%s\n</html>",SSID,PASSSTR);
}


void simpleSubmittedPage()
{
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
fprintf(WIFI,"<!DOCTYPE HTML>\n<html>\nThank You!\n<br />Router Info Submitted\n</html>\r\n\r\n");
}

void genHostPage(char outString[])
{
/*	//Old Home Page
sprintf(outString,"<!DOCTYPE HTML>\n\
<html>\
<br />\
Osmobot is:<img src='http://www.example.com/singlepixel.gif' alt=\"Not Connected To The Internet\" />\
<br />\
<a href=\"wifiConfig.html\">Wifi Config</a>\
<br />
<a href=\"test.html\">Test Page</a>\
<br />\n\
</html>");

*/

//New Home Page with Internet Link Indicator
outString[0]='\0';
fprintf(WIFI,"HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n");
fprintf(WIFI,"<!DOCTYPE HTML>\n<html>\n<script>function checkCxn(connected){c=document.getElementById('CXN');\nif(connected){c.innerHTML+='connected to the internet.';}\n");
fprintf(WIFI,"else{c.innerHTML+='not connected to the internet.';}}</script><div id=\"CXN\">Osmobot is </div><br />Links:<br />");
fprintf(WIFI,"<img src='http://osmobot.org/singlepixel.gif' style=\"display:none\" onload=\"checkCxn(1)\" onerror=\"checkCxn(0)\" />");
fprintf(WIFI,"<a href=\"wifiConfig.html\">Wifi Config</a><br/><a href=\"test.html\">Test Page</a><br/></html>");
delay_ms(1000);
}










////PUT THIS AFTER ALL THE WEBPAGE FUCTIONS

//Takes Variable string out of URL
void stripArgs(char url[], char argStr[])
{

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

//Serves The Webpage
void osmobotServePage(char url[])
{
//Add conditionals as webpages are added
if (strncmp(url,"/wifiConfig.html",16)==0)
	{
	genWifiConfigPage(WebPageTxtBuff);
	//sendHTTPPage(WebPageTxtBuff);
	}

else if (strncmp(url,"/test.html",10)==0)
	{
	genTestPage(WebPageTxtBuff);
	//sendHTTPPage(WebPageTxtBuff);
	}
else if (strncmp(url,"/router_submit.html",19)==0)
	{
	simpleSubmittedPage();
	delay_ms(1000);
	char *varStart=strchr(url,'?');
	char fakeSSID[32];
	char fakePASS[64];
	#if SERVERLCD
		VacDisplayClear();
	#endif
	if(varStart!=null)	//Look For those Variables
		{
		//simpleSubmittedPage();
		//STA_SSID
		//"SSID="\
		char *ssidpntr= strstr(varStart,"SSID=")+5;
		char *doneptr= strchr(varStart,'&');
		
		//fakeSSID[doneptr-ssidpntr]='\0';


		#if SERVERLCD
		Display_XYString(0,1,"SSID");
		#endif
		strncpy(STA_SSID,ssidpntr,(doneptr-ssidpntr));
		strncpy(STA_SSID+(doneptr-ssidpntr),"\0",1);

		//copyCredentials(STA_SSID,fakeSSID,);
		//STA_PW
		//"PASS="
		#if SERVERLCD
		Display_XYString(1,2,"PASS ");
		#endif
		char *passpntr= strstr(varStart,"PASS=")+5;
		#if SERVERLCD
			VacWriteChar('1');
			VacWriteChar(*passpntr);
		#endif
		doneptr= strchr(passpntr,'&');
		#if SERVERLCD
			VacWriteChar('2');
			VacWriteChar(*doneptr);
		#endif
		strncpy(STA_PW,passpntr,doneptr-passpntr);
		#if SERVERLCD		
			VacWriteChar('3');
		#endif
		strncpy(STA_PW+(doneptr-passpntr),"\0",1);
		#if SERVERLCD
			VacWriteChar('4');

			Display_XYString(2,3,"AUTH");
		#endif
		char *authpntr= strstr(varStart,"AUTH=")+5;
		#if SERVERLCD
			VacWriteChar('1');
			VacWriteChar(*authpntr);
		#endif
		doneptr= strchr(authpntr,'&');
		#if SERVERLCD
			VacWriteChar('2');
			VacWriteChar(*doneptr);
		#endif
		strncpy(STA_AUTH,authpntr,doneptr-authpntr);
		#if SERVERLCD
		VacWriteChar('3');
		#endif
		strncpy(STA_AUTH+(doneptr-authpntr),"\0",1);
		#if SERVERLCD
		VacWriteChar('4');
		#endif
		

		char *encpntr= strstr(varStart,"ENCRYPT=")+8;
		doneptr= strchr(encpntr,'\0');

		
		strncpy(STA_ENC,encpntr,encpntr-passpntr);
		strncpy(STA_ENC+(doneptr-encpntr),"\0",1);
		
		//sendSubmittedPage(STA_SSID,STA_PW);
		WFIsConfig=0;
		}
	//genSubmittedPage(WebPageTxtBuff,STA_SSID,STA_PW);
	//genSubmittedPage(WebPageTxtBuff,fakeSSID,fakePASS);
	//sendHTTPPage(WebPageTxtBuff);
	//WIFI_CONFIG_ROUTER_SETTINGS();
	xRST();
	VacDisplayClear();
	resetParsing=1;
	delay_ms(10000);
	WIFI_enter_setup();
	WFIsConfig=0;
	USEAT=1;
	WIFI_STA_CCONFIG(1);
	}



//IF There isnt a Page 404 It
else
	{
	send404Page(url);
	}

}