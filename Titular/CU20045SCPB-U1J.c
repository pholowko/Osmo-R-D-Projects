/////////////Configuration////////////////////
#define RSPIN PIN_E2
#define WRPIN PIN_E1
#define RDPIN PIN_E0
#define WRITEPORT PORT_D

//////////////////////////////////////////////


/////////////Definitions//////////////////////
#ifndef BYTE
#define BYTE int8
#endif
#ifndef BOOL
#define BOOL int1
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif





//////////////////////////////////////////////

void initDispIO(void)
{
output_bit(WRPIN,HIGH);
output_bit(RDPIN,HIGH);
output_bit(RSPIN,LOW);
output_d(0x00);
}


void output_d_flipped(BYTE val){
output_bit(PIN_D0,(val&(1<<7)));
output_bit(PIN_D1,(val&(1<<6)));
output_bit(PIN_D2,(val&(1<<5)));
output_bit(PIN_D3,(val&(1<<4)));
output_bit(PIN_D4,(val&(1<<3)));
output_bit(PIN_D5,(val&(1<<2)));
output_bit(PIN_D6,(val&(1<<1)));
output_bit(PIN_D7,(val&(1<<0)));
}


BYTE readByte(BOOL RSval)
{
output_bit(RDPIN,HIGH);
delay_cycles(1);
output_bit(RSPIN,RSval);
delay_cycles(1);
output_bit(RDPIN,LOW);
delay_cycles(1);
BYTE dataVal=input_d();
delay_cycles(1);
output_bit(RDPIN,HIGH);
delay_cycles(1);

return dataVal;
}



BOOL writeByte(BOOL RSval, BYTE val){
//RSval=RSval&0x01;
//BYTE startByte = (0x00|(RSval));	//Sets startByte depending on RSval
//BYTE stopByte = (0x02|(RSval));	//Sets stopByte depending on RSval

/*
if((readByte(0)&0x80)==1){

delay_cycles(255);

}
else
{

}
*/
output_d_flipped(val);
output_bit(WRPIN,HIGH);
////RS is LOW when writing and HIGH otherwise
//output_d(val);

//output_d(0xff);


if(RSval!=0)
{
output_bit(RSPIN,HIGH);
}
else{
output_bit(RSPIN,LOW);
}
output_bit(WRPIN,HIGH);
//delay_cycles(1);
output_bit(WRPIN,LOW);
//output_E(0x00);	//Write RS	"START"
//delay_cycles(1);



//delay_cycles(1);
//output_E(0x02);	//Write RS ... & RW HIGH "STOP"
output_bit(WRPIN,HIGH);
//delay_cycles(1);
return HIGH;
}




BOOL writeChar(BYTE val){
writeByte(1,val);
return HIGH;
}





BOOL writeCharPos(BYTE xPos, BYTE yPos, BYTE strPtr)
{


BYTE WAMpos=0x80+xPos+(0x20*yPos);
writeByte(0,WAMpos);	//Set WAM Address

int i=0;


writeChar(strPtr);
return HIGH;
}


void clearLine(int8 xPos, int8 yPos){

BYTE linePos=((0x20*yPos)+0x80);
writeByte(0,linePos);
for(int ct=0; ct<20; ct++)
{
writeChar(' ');
}
BYTE WAMpos=0x80+xPos+(0x20*yPos);
writeByte(0,WAMpos);	//Set WAM Address
}




BOOL writeString(BYTE xPos, BYTE yPos, BYTE strPtr[])
{

BYTE linePos=((0x20*yPos)+0x80);
writeByte(0,linePos);
//for(int ct=0; ct<20; ct++)
//{
//writeChar(' ');
//}

BYTE WAMpos=0x80+xPos+(0x20*yPos);
writeByte(0,WAMpos);	//Set WAM Address

int i=0;

while(strPtr[i]!='\0')
{
writeChar(strPtr[i]);
i++;
if(i>=20)
{
break;
}

}
return HIGH;
}


void clearDisplay(){
writeByte(0,0x01);	//Clear Display
delay_ms(5);

}







void initDisplay(void){
writeByte(0,0x3F);	//Set 8 bit mode
delay_cycles(127);
writeByte(0,0x01);	//Clear Display
delay_ms(5);
//writeByte(0,0x02);	//Cursor Home
writeByte(0,0x06);	//Entry Mode Set
writeByte(0,0x0F);	//Display On Cursor On
writeByte(0,0x10);	//Cursor Shift
writeByte(0,0x80);	//Set WAM Address
}



