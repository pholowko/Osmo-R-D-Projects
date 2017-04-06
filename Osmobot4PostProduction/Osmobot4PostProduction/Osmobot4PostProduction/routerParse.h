#ifndef ROUTERPARSE_H
#define ROUTERPARSE_H

#define MAXNUMROUTERS 10

//#define XMLSIZE 30+MAXNUMROUTERS*125
#define RTRHTMLSIZE 1300


//Router Datastructure declaration

typedef struct Routerstruct {
char SSID[32]; 
char secType[24];
int sigStr;
}Router;

//Router Table initialization
Router routerTable[MAXNUMROUTERS];


//Buffer to hold router information as an XML file


char routerXML[RTRHTMLSIZE];//Preallocate memory for each router entry to be stored in XML


char tempXMLBuff[130];


//Function Declarations
void printRouter(Router router);
int parseRouter(Router router[], char c, int RST);
void clearRouters(Router router[]);


#include "routerParse.c"
#endif