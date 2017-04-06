
#ifndef TESTER
#include "CommonPassedDataFromMaterToSlave.h"
#endif
//*******************************************************************************
// Create November 2, 2016
// Save this float into eeprom
// returns nothing.
//  give the pointer to the number, the location in eeprom and length
//******************************************************************************
void eeprom_write_blocktest(int8 *ptr, unsigned int8 addr, unsigned char len)
{
  unsigned int8 *data = ptr;
    unsigned int16 bufferin[4];
    unsigned int8 stuff = addr;
   // len=len>>1;    // Since we are using 16 bits, two bytes are used at a time because of defs.
  //  addr=addr<<1;   //mult by two offset to the correct location.

   while (len--) {
        write_eeprom(addr, *data++);
        //addr=addr+2;  // need to skip two bytes since this is a 16 bit CPU 
        addr++;
        // this is commented out since this is on an 8 bit machine.
    } 
 
}




//*******************************************************************
// Created November 22, 2016
// Save the local configures for this machine into internal EEPROM   THIS ROUTINE IS USED ONLY ON 8 BIT CPUS
// Returns a 0 if it worked, it returns a 1 if failed.
// List of data saved for local unit configuration.  There is only 256 bytes on a PIC18F4550  And is saved as 8 bits, I think, not 16 at once
//  Here is the link to the data documintation for the configuration and calibration for remote sensors.  This points to the 16 bit CPUS
//#include "..\OsomobotCarbonDioxideDigitalSensor\OsomobotCarbonDioxideDigitalSensor.X\ITwoSeeGeneralCommunicationSlave.c"     // this is included to connect to the master Osmobot.
//  All saved calibration data is 16 bits.  That means two bytes per data point.  128 words.  
// Which display items  -> int16      Address  120  or 0x78
//*******************************************************************
int SaveConfiguration(void)
{
    int8 lowbyte,highbyte;
    unsigned int16 items;
    
    
    //this is all NH4 stuff
    eeprom_write_blocktest(&sysInput.nh4pt1returnednumber, 0x12, sizeof sysInput.nh4pt1returnednumber);   // this is for nh4pt1returnednumber   This should be four bytes
    fprintf(BT,"*");   
    eeprom_write_blocktest(&sysInput.nh4pt2returnednumber, 0x16, sizeof sysInput.nh4pt2returnednumber);   // this is for nh4pt1returnednumber   This should be four bytes
    fprintf(BT,"*");   
    eeprom_write_blocktest(&sysInput.nh4pt3returnednumber, 0x1a, sizeof sysInput.nh4pt3returnednumber);   // this is for nh4pt1returnednumber   This should be four bytes
    fprintf(BT,"*");   
//  nh4pt1cal1of3
    items = sysInput.nh4pt1cal1of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x00,lowbyte);
    write_eeprom(0x01,highbyte);  
    fprintf(BT,"*");
//***************************************
//  nh4pt1ca2of3
    items = sysInput.nh4pt1cal2of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x02,lowbyte);
    write_eeprom(0x03,highbyte);  
    fprintf(BT,"*");
//***************************************
//  nh4pt1cal3of3
    items = sysInput.nh4pt1cal3of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x04,lowbyte);
    write_eeprom(0x05,highbyte);  
    fprintf(BT,"*");
//***************************************
//  nh4pt2cal1of3
    items = sysInput.nh4pt2cal1of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x06,lowbyte);
    write_eeprom(0x07,highbyte);  
    fprintf(BT,"*");
//***************************************
//  nh4pt2cal2of3
    items = sysInput.nh4pt2cal2of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x08,lowbyte);
    write_eeprom(0x09,highbyte);  
    fprintf(BT,"*");
//***************************************
//  nh4pt2cal3of3
    items = sysInput.nh4pt2cal3of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x0a,lowbyte);
    write_eeprom(0x0b,highbyte);  
    fprintf(BT,"*");
//***************************************   
//  nh4pt3cal1of3
    items = sysInput.nh4pt3cal1of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x0c,lowbyte);
    write_eeprom(0x0d,highbyte);  
    fprintf(BT,"*");
//***************************************
//  nh4pt3cal2of3
    items = sysInput.nh4pt3cal2of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x0e,lowbyte);
    write_eeprom(0x0f,highbyte);  
    fprintf(BT,"*");
//***************************************
//  nh4pt3cal3of3
    items = sysInput.nh4pt3cal3of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x10,lowbyte);
    write_eeprom(0x11,highbyte);  
    fprintf(BT,"*");
//***************************************   
    
//Created Feb 27, 2017
    //this is all DO stuff  
    // it starts after the NH4 stuff.  The first address for these numbers is 0x1E
    
    
    //  DOpt1cal1of3
    items = sysInput.DOpt1cal1of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x1E,lowbyte);
    write_eeprom(0x1F,highbyte);  
    fprintf(BT,"*");
//***************************************
//  DOpt1cal2of3
    items = sysInput.DOpt1cal2of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x20,lowbyte);
    write_eeprom(0x21,highbyte);  
    fprintf(BT,"*");
//***************************************
//  DOpt1cal3of3
    items = sysInput.DOpt1cal3of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x22,lowbyte);
    write_eeprom(0x23,highbyte);  
    fprintf(BT,"*");
//***************************************
//  DOpt2cal1of3
    items = sysInput.DOpt2cal1of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x24,lowbyte);
    write_eeprom(0x25,highbyte);  
    fprintf(BT,"*");
//***************************************
//  DOpt2cal2of3
    items = sysInput.DOpt2cal2of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x26,lowbyte);
    write_eeprom(0x27,highbyte);  
    fprintf(BT,"*");
//***************************************
//  DOpt2cal3of3
    items = sysInput.DOpt2cal3of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x28,lowbyte);
    write_eeprom(0x29,highbyte);  
    fprintf(BT,"*");
//***************************************   
//  DOpt3cal1of3
    items = sysInput.DOpt3cal1of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x2a,lowbyte);
    write_eeprom(0x2b,highbyte);  
    fprintf(BT,"*");
//***************************************
//  DOpt3cal2of3
    items = sysInput.DOpt3cal2of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x2c,lowbyte);
    write_eeprom(0x2d,highbyte);  
    fprintf(BT,"*");
//***************************************
//  DOpt3cal3of3
    items = sysInput.DOpt3cal3of3;
    lowbyte =(int8) items;
    highbyte = (int8) (items>>8);
    write_eeprom(0x2e,lowbyte);
    write_eeprom(0x2F,highbyte);  
    fprintf(BT,"*");
//*************************************** 
    eeprom_write_blocktest(&sysInput.DOpt1returnednumber, 0x30, sizeof sysInput.DOpt1returnednumber);   // this is forDOpt1returnednumber   This should be four bytes
    fprintf(BT,"*");   
    eeprom_write_blocktest(&sysInput.DOpt2returnednumber, 0x34, sizeof sysInput.DOpt2returnednumber);   // this is for DOpt2returnednumber   This should be four bytes
    fprintf(BT,"*");   
    eeprom_write_blocktest(&sysInput.DOpt3returnednumber, 0x38, sizeof sysInput.DOpt3returnednumber);   // this is forDOpt3returnednumber   This should be four bytes
    fprintf(BT,"*"); 
    
    
    
 //Created Feb 27, 2017
    //this is all Theremister stuff   
    
    
}


//**************************************************************
// Created November 24, 2016
// This routine sucks in the data number as a float from the Interenal EEOPROM.  This is for the 8 bit version
//**************************************************************
float READ_FLOAT_EEPROM(int n) { 
   int i; 
   float data;

   for (i = 0; i < 4; i++)    // this needs to read in four bytes
      *((int8*)&data + i) = read_eeprom(i + n);

   return(data); 
}


void LoadConfigurations(void)
{
    int8 lowbyte,highbyte;
    unsigned int16 items;
    
    
    sysInput.nh4pt1returnednumber = READ_FLOAT_EEPROM(0x12);   // this gets the four bytes from EEPROM to make   nh4pt1returnednumber  
    sysInput.nh4pt2returnednumber = READ_FLOAT_EEPROM(0x16);   // this gets the four bytes from EEPROM to make   nh4pt1returnednumber  
    sysInput.nh4pt3returnednumber = READ_FLOAT_EEPROM(0x1a);   // this gets the four bytes from EEPROM to make   nh4pt1returnednumber  
  //  nh4pt1cal1of3  
    lowbyte = read_eeprom(0x00);
    highbyte = read_eeprom(0x01);
    items = (int16) highbyte;
    sysInput.nh4pt1cal1of3 = (items<<8) +  lowbyte;  
//***************************************
//  nh4pt1ca2of3  
    lowbyte = read_eeprom(0x02);
    highbyte = read_eeprom(0x03);
    items = (int16) highbyte;
    sysInput.nh4pt1cal2of3 = (items<<8) +  lowbyte;  
//***************************************
//  nh4pt1ca3of3  
    lowbyte = read_eeprom(0x04);
    highbyte = read_eeprom(0x05);
    items = (int16) highbyte;
    sysInput.nh4pt1cal3of3 = (items<<8) +  lowbyte;  
//***************************************  
//  nh4pt2ca1of3  
    lowbyte = read_eeprom(0x06);
    highbyte = read_eeprom(0x07);
    items = (int16) highbyte;
    sysInput.nh4pt2cal1of3 = (items<<8) +  lowbyte;  
//***************************************    
//  nh4pt2ca2of3  
    lowbyte = read_eeprom(0x08);
    highbyte = read_eeprom(0x09);
    items = (int16) highbyte;
    sysInput.nh4pt2cal2of3 = (items<<8) +  lowbyte;  
//***************************************    
//  nh4pt2ca13of3  
    lowbyte = read_eeprom(0x0a);
    highbyte = read_eeprom(0x0b);
    items = (int16) highbyte;
    sysInput.nh4pt2cal3of3 = (items<<8) +  lowbyte;  
//***************************************    
//  nh4pt3ca1of3  
    lowbyte = read_eeprom(0x0c);
    highbyte = read_eeprom(0x0d);
    items = (int16) highbyte;
    sysInput.nh4pt3cal1of3 = (items<<8) +  lowbyte;  
//***************************************    
//  nh4pt3ca2of3  
    lowbyte = read_eeprom(0x0e);
    highbyte = read_eeprom(0x0f);
    items = (int16) highbyte;
    sysInput.nh4pt3cal2of3 = (items<<8) +  lowbyte;  
//***************************************    
//  nh4pt3ca3of3  
    lowbyte = read_eeprom(0x10);
    highbyte = read_eeprom(0x11);
    items = (int16) highbyte;
    sysInput.nh4pt3cal3of3 = (items<<8) +  lowbyte;  
//***************************************    
   
    
    
    
// load the DO stuff out of EEPROM   Added Feb 27, 2017

    sysInput.DOpt1returnednumber = READ_FLOAT_EEPROM(0x30);   // this gets the four bytes from EEPROM to make   DOpt1returnednumber  
    sysInput.DOpt2returnednumber = READ_FLOAT_EEPROM(0x34);   // this gets the four bytes from EEPROM to make   DOpt2returnednumber  
    sysInput.DOpt3returnednumber = READ_FLOAT_EEPROM(0x38);   // this gets the four bytes from EEPROM to make   DOpt3returnednumber  
  //  DOpt1cal1of3   
    lowbyte = read_eeprom(0x1e);
    highbyte = read_eeprom(0x1f);
    items = (int16) highbyte;
    sysInput.DOpt1cal1of3 = (items<<8) +  lowbyte;  
//***************************************
//  DOpt1cal2of3   
    lowbyte = read_eeprom(0x20);
    highbyte = read_eeprom(0x21);
    items = (int16) highbyte;
    sysInput.DOpt1cal2of3 = (items<<8) +  lowbyte;  
//***************************************
//  DOpt1cal3of3  
    lowbyte = read_eeprom(0x22);
    highbyte = read_eeprom(0x23);
    items = (int16) highbyte;
    sysInput.DOpt1cal3of3 = (items<<8) +  lowbyte;  
//***************************************  
//  DOpt2cal1of3  
    lowbyte = read_eeprom(0x24);
    highbyte = read_eeprom(0x25);
    items = (int16) highbyte;
    sysInput.DOpt2cal1of3 = (items<<8) +  lowbyte;  
//***************************************    
//  DOpt2cal2of3  
    lowbyte = read_eeprom(0x26);
    highbyte = read_eeprom(0x27);
    items = (int16) highbyte;
    sysInput.DOpt2cal2of3 = (items<<8) +  lowbyte;  
//***************************************    
//  DOpt2cal3of3  
    lowbyte = read_eeprom(0x28);
    highbyte = read_eeprom(0x29);
    items = (int16) highbyte;
    sysInput.DOpt2cal3of3 = (items<<8) +  lowbyte;  
//***************************************    
//  DOpt3cal1of3  
    lowbyte = read_eeprom(0x2a);
    highbyte = read_eeprom(0x2b);
    items = (int16) highbyte;
    sysInput.DOpt3cal1of3 = (items<<8) +  lowbyte;  
//***************************************    
//  DOpt3cal2of3  
    lowbyte = read_eeprom(0x2c);
    highbyte = read_eeprom(0x2d);
    items = (int16) highbyte;
    sysInput.DOpt3cal2of3 = (items<<8) +  lowbyte;  
//***************************************    
//  DOpt3cal3of3  
    lowbyte = read_eeprom(0x2e);
    highbyte = read_eeprom(0x2f);
    items = (int16) highbyte;
    sysInput.DOpt3cal3of3 = (items<<8) +  lowbyte;  
//***************************************    
       
}





//********************************************************************
// Created November 22, 2016
// Load the local routines out of the internal EEPROM for the PIC18 series CPUs.  This does not work on the PIC24 or PIC33 CPUS
//  The data is saved different for each CPU for the data type.  
//  Returns nothing.
//********************************************************************
unsigned int16 getlocalconfigurations(void)
{
    int8 lowbyte,highbyte;
    unsigned int16 items;
    
    lowbyte = read_eeprom(0x78);
    highbyte = read_eeprom(0x79);
    items = (int16) highbyte;
   
    items = (items<<8) +  lowbyte;
    return(items);
}

//**********************************************************************
// Created November 22, 2016
// This saves the local configurations to the EEPROM.  The data so far is only 16 bits.
// int16 word saved to address
// Returns if the data is save OK.  A 0 for OK, a 1 for not OK
//**********************************************************************
int savelocalconfigurations(int16 selectitem)
{
    int8 lowbyte,highbyte;
     unsigned int16 items;
     
    lowbyte =(int8) selectitem;
    highbyte = (int8) (selectitem>>8);
    write_eeprom(0x78,lowbyte);
    write_eeprom(0x79,highbyte);
    
    lowbyte = read_eeprom(0x78);
    highbyte = read_eeprom(0x79);
    items = (int16) highbyte;
   
    items = (items<<8) +  lowbyte; 
    
    if (items == selectitem)
    {
        return(0);
    }
    else
    {
        return(1);
    }
}