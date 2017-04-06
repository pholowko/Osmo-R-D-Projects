#ifndef ROUTERPARSE_H
#define ROUTERPARSE_H

#define MAXNUMROUTERS 15

//#define XMLSIZE 30+MAXNUMROUTERS*125
#define RTRHTMLSIZE 1300


//Router Datastructure declaration

typedef struct Routerstruct {
char SSID[32]; 
char signalstreangth[5];
char secType[15];
char authType[15];
char macaddr[25];
int sigStr;
}Router;

//Router Table initialization
Router routerTable[MAXNUMROUTERS];


//Buffer to hold router information as an XML file


//char routerXML[RTRHTMLSIZE];//Preallocate memory for each router entry to be stored in XML


//char tempXMLBuff[130];


//Function Declarations
void reloadTime(void);
void printRouter(Router router);
int parseRouter(Router router[], char c, int RST);
void clearRouters(Router router[]);
int SendBTCommand(char* sendingstring, char receivingstring[]);
int changeconnection(int commandnumber);
unsigned int8 sensorRead(void);
void intimultiplex(void);
void selectsensor(int sensornumber);
float WaterTemperature(void);
#include "routerParse.c"
#endif