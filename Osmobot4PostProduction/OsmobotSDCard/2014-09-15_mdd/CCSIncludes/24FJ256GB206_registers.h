#word WREG0 = 0x000

#word WREG1 = 0x002

#word WREG2 = 0x004

#word WREG3 = 0x006

#word WREG4 = 0x008

#word WREG5 = 0x00A

#word WREG6 = 0x00C

#word WREG7 = 0x00E

#word WREG8 = 0x010

#word WREG9 = 0x012

#word WREG10 = 0x014

#word WREG11 = 0x016

#word WREG12 = 0x018

#word WREG13 = 0x01A

#word WREG14 = 0x01C

#word WREG15 = 0x01E

#word SPLIM = 0x020

#word PC = 0x02E

#word DSRPAG = 0x032

#word DSWPAG = 0x034

#word RCOUNT = 0x036

typedef union 
 {
      struct {
         unsigned int C:1;
         unsigned int Z:1;
         unsigned int OV:1;
         unsigned int N:1;
         unsigned int RA:1;
         unsigned int IPL0:3;
         unsigned int DC:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int IPL:3;
      };
} SRBITS;
SRBITS SRbits;
#word SRbits = 0x042
#word SR = 0x042

typedef struct 
 {
   unsigned int :2;
   unsigned int RES:1;
   unsigned int IPL3:1;
} CORCONBITS;
CORCONBITS CORCONbits;
#word CORCONbits = 0x044
#word CORCON = 0x044

#word DISICNT = 0x052

#word TBLPAG = 0x054

typedef struct 
 {
   unsigned int CN0PDE:1;
   unsigned int CN1PDE:1;
   unsigned int CN2PDE:1;
   unsigned int CN3PDE:1;
   unsigned int CN4PDE:1;
   unsigned int CN5PDE:1;
   unsigned int CN6PDE:1;
   unsigned int CN7PDE:1;
   unsigned int CN8PDE:1;
   unsigned int CN9PDE:1;
   unsigned int CN10PDE:1;
   unsigned int CN11PDE:1;
   unsigned int CN12PDE:1;
   unsigned int CN13PDE:1;
   unsigned int CN14PDE:1;
   unsigned int CN15PDE:1;
} CNPD1BITS;
CNPD1BITS CNPD1bits;
#word CNPD1bits = 0x056
#word CNPD1 = 0x056

typedef struct 
 {
   unsigned int CN16PDE:1;
   unsigned int CN17PDE:1;
   unsigned int CN18PDE:1;
   unsigned int :3;
   unsigned int CN22PDE:1;
   unsigned int CN23PDE:1;
   unsigned int CN24PDE:1;
   unsigned int CN25PDE:1;
   unsigned int CN26PDE:1;
   unsigned int CN27PDE:1;
   unsigned int CN28PDE:1;
   unsigned int CN29PDE:1;
   unsigned int CN30PDE:1;
   unsigned int CN31PDE:1;
} CNPD2BITS;
CNPD2BITS CNPD2bits;
#word CNPD2bits = 0x058
#word CNPD2 = 0x058

typedef struct 
 {
   unsigned int CN32PDE:1;
} CNPD3BITS;
CNPD3BITS CNPD3bits;
#word CNPD3bits = 0x05A
#word CNPD3 = 0x05A

typedef struct 
 {
   unsigned int :1;
   unsigned int CN49PDE:1;
   unsigned int CN50PDE:1;
   unsigned int CN51PDE:1;
   unsigned int CN52PDE:1;
   unsigned int CN53PDE:1;
   unsigned int CN54PDE:1;
   unsigned int CN55PDE:1;
   unsigned int CN56PDE:1;
   unsigned int :1;
   unsigned int CN58PDE:1;
   unsigned int CN59PDE:1;
   unsigned int CN60PDE:1;
   unsigned int CN61PDE:1;
   unsigned int CN62PDE:1;
   unsigned int CN63PDE:1;
} CNPD4BITS;
CNPD4BITS CNPD4bits;
#word CNPD4bits = 0x05C
#word CNPD4 = 0x05C

typedef struct 
 {
   unsigned int CN64PDE:1;
   unsigned int CN65PDE:1;
   unsigned int :2;
   unsigned int CN68PDE:1;
   unsigned int CN69PDE:1;
   unsigned int :1;
   unsigned int CN71PDE:1;
} CNPD5BITS;
CNPD5BITS CNPD5bits;
#word CNPD5bits = 0x05E
#word CNPD5 = 0x05E

typedef struct 
 {
   unsigned int :3;
   unsigned int CN83PDE:1;
   unsigned int CN84PDE:1;
} CNPD6BITS;
CNPD6BITS CNPD6bits;
#word CNPD6bits = 0x060
#word CNPD6 = 0x060

typedef struct 
 {
   unsigned int CN0IE:1;
   unsigned int CN1IE:1;
   unsigned int CN2IE:1;
   unsigned int CN3IE:1;
   unsigned int CN4IE:1;
   unsigned int CN5IE:1;
   unsigned int CN6IE:1;
   unsigned int CN7IE:1;
   unsigned int CN8IE:1;
   unsigned int CN9IE:1;
   unsigned int CN10IE:1;
   unsigned int CN11IE:1;
   unsigned int CN12IE:1;
   unsigned int CN13IE:1;
   unsigned int CN14IE:1;
   unsigned int CN15IE:1;
} CNEN1BITS;
CNEN1BITS CNEN1bits;
#word CNEN1bits = 0x062
#word CNEN1 = 0x062

typedef struct 
 {
   unsigned int CN16IE:1;
   unsigned int CN17IE:1;
   unsigned int CN18IE:1;
   unsigned int :3;
   unsigned int CN22IE:1;
   unsigned int CN23IE:1;
   unsigned int CN24IE:1;
   unsigned int CN25IE:1;
   unsigned int CN26IE:1;
   unsigned int CN27IE:1;
   unsigned int CN28IE:1;
   unsigned int CN29IE:1;
   unsigned int CN30IE:1;
   unsigned int CN31IE:1;
} CNEN2BITS;
CNEN2BITS CNEN2bits;
#word CNEN2bits = 0x064
#word CNEN2 = 0x064

typedef struct 
 {
   unsigned int CN32IE:1;
} CNEN3BITS;
CNEN3BITS CNEN3bits;
#word CNEN3bits = 0x066
#word CNEN3 = 0x066

typedef struct 
 {
   unsigned int :1;
   unsigned int CN49IE:1;
   unsigned int CN50IE:1;
   unsigned int CN51IE:1;
   unsigned int CN52IE:1;
   unsigned int CN53IE:1;
   unsigned int CN54IE:1;
   unsigned int CN55IE:1;
   unsigned int CN56IE:1;
   unsigned int :1;
   unsigned int CN58IE:1;
   unsigned int CN59IE:1;
   unsigned int CN60IE:1;
   unsigned int CN61IE:1;
   unsigned int CN62IE:1;
   unsigned int CN63IE:1;
} CNEN4BITS;
CNEN4BITS CNEN4bits;
#word CNEN4bits = 0x068
#word CNEN4 = 0x068

typedef struct 
 {
   unsigned int CN64IE:1;
   unsigned int CN65IE:1;
   unsigned int :2;
   unsigned int CN68IE:1;
   unsigned int CN69IE:1;
   unsigned int :1;
   unsigned int CN71IE:1;
} CNEN5BITS;
CNEN5BITS CNEN5bits;
#word CNEN5bits = 0x06A
#word CNEN5 = 0x06A

typedef struct 
 {
   unsigned int :3;
   unsigned int CN83IE:1;
   unsigned int CN84IE:1;
} CNEN6BITS;
CNEN6BITS CNEN6bits;
#word CNEN6bits = 0x06C
#word CNEN6 = 0x06C

typedef struct 
 {
   unsigned int CN0PUE:1;
   unsigned int CN1PUE:1;
   unsigned int CN2PUE:1;
   unsigned int CN3PUE:1;
   unsigned int CN4PUE:1;
   unsigned int CN5PUE:1;
   unsigned int CN6PUE:1;
   unsigned int CN7PUE:1;
   unsigned int CN8PUE:1;
   unsigned int CN9PUE:1;
   unsigned int CN10PUE:1;
   unsigned int CN11PUE:1;
   unsigned int CN12PUE:1;
   unsigned int CN13PUE:1;
   unsigned int CN14PUE:1;
   unsigned int CN15PUE:1;
} CNPU1BITS;
CNPU1BITS CNPU1bits;
#word CNPU1bits = 0x06E
#word CNPU1 = 0x06E

typedef struct 
 {
   unsigned int CN16PUE:1;
   unsigned int CN17PUE:1;
   unsigned int CN18PUE:1;
   unsigned int :3;
   unsigned int CN22PUE:1;
   unsigned int CN23PUE:1;
   unsigned int CN24PUE:1;
   unsigned int CN25PUE:1;
   unsigned int CN26PUE:1;
   unsigned int CN27PUE:1;
   unsigned int CN28PUE:1;
   unsigned int CN29PUE:1;
   unsigned int CN30PUE:1;
   unsigned int CN31PUE:1;
} CNPU2BITS;
CNPU2BITS CNPU2bits;
#word CNPU2bits = 0x070
#word CNPU2 = 0x070

typedef struct 
 {
   unsigned int CN32PUE:1;
} CNPU3BITS;
CNPU3BITS CNPU3bits;
#word CNPU3bits = 0x072
#word CNPU3 = 0x072

typedef struct 
 {
   unsigned int :1;
   unsigned int CN49PUE:1;
   unsigned int CN50PUE:1;
   unsigned int CN51PUE:1;
   unsigned int CN52PUE:1;
   unsigned int CN53PUE:1;
   unsigned int CN54PUE:1;
   unsigned int CN55PUE:1;
   unsigned int CN56PUE:1;
   unsigned int :1;
   unsigned int CN58PUE:1;
   unsigned int CN59PUE:1;
   unsigned int CN60PUE:1;
   unsigned int CN61PUE:1;
   unsigned int CN62PUE:1;
   unsigned int CN63PUE:1;
} CNPU4BITS;
CNPU4BITS CNPU4bits;
#word CNPU4bits = 0x074
#word CNPU4 = 0x074

typedef struct 
 {
   unsigned int CN64PUE:1;
   unsigned int CN65PUE:1;
   unsigned int :2;
   unsigned int CN68PUE:1;
   unsigned int CN69PUE:1;
   unsigned int :1;
   unsigned int CN71PUE:1;
} CNPU5BITS;
CNPU5BITS CNPU5bits;
#word CNPU5bits = 0x076
#word CNPU5 = 0x076

typedef struct 
 {
   unsigned int :3;
   unsigned int CN83PUE:1;
   unsigned int CN84PUE:1;
} CNPU6BITS;
CNPU6BITS CNPU6bits;
#word CNPU6bits = 0x078
#word CNPU6 = 0x078

typedef struct 
 {
   unsigned int :1;
   unsigned int OSCFAIL:1;
   unsigned int STKERR:1;
   unsigned int ADDRERR:1;
   unsigned int MATHERR:1;
   unsigned int :10;
   unsigned int NSTDIS:1;
} INTCON1BITS;
INTCON1BITS INTCON1bits;
#word INTCON1bits = 0x080
#word INTCON1 = 0x080

typedef struct 
 {
   unsigned int INT0EP:1;
   unsigned int INT1EP:1;
   unsigned int INT2EP:1;
   unsigned int INT3EP:1;
   unsigned int INT4EP:1;
   unsigned int :9;
   unsigned int DISI:1;
   unsigned int ALTIVT:1;
} INTCON2BITS;
INTCON2BITS INTCON2bits;
#word INTCON2bits = 0x082
#word INTCON2 = 0x082

typedef struct 
 {
   unsigned int INT0IF:1;
   unsigned int IC1IF:1;
   unsigned int OC1IF:1;
   unsigned int T1IF:1;
   unsigned int :1;
   unsigned int IC2IF:1;
   unsigned int OC2IF:1;
   unsigned int T2IF:1;
   unsigned int T3IF:1;
   unsigned int SPF1IF:1;
   unsigned int SPI1IF:1;
   unsigned int U1RXIF:1;
   unsigned int U1TXIF:1;
   unsigned int AD1IF:1;
} IFS0BITS;
IFS0BITS IFS0bits;
#word IFS0bits = 0x084
#word IFS0 = 0x084

typedef struct 
 {
   unsigned int SI2C1IF:1;
   unsigned int MI2C1IF:1;
   unsigned int CMIF:1;
   unsigned int CNIF:1;
   unsigned int INT1IF:1;
   unsigned int :1;
   unsigned int IC7IF:1;
   unsigned int IC8IF:1;
   unsigned int :1;
   unsigned int OC3IF:1;
   unsigned int OC4IF:1;
   unsigned int T4IF:1;
   unsigned int T5IF:1;
   unsigned int INT2IF:1;
   unsigned int U2RXIF:1;
   unsigned int U2TXIF:1;
} IFS1BITS;
IFS1BITS IFS1bits;
#word IFS1bits = 0x086
#word IFS1 = 0x086

typedef struct 
 {
   unsigned int SPF2IF:1;
   unsigned int SPI2IF:1;
   unsigned int :3;
   unsigned int IC3IF:1;
   unsigned int IC4IF:1;
   unsigned int IC5IF:1;
   unsigned int IC6IF:1;
   unsigned int OC5IF:1;
   unsigned int OC6IF:1;
   unsigned int OC7IF:1;
   unsigned int OC8IF:1;
   unsigned int PMPIF:1;
} IFS2BITS;
IFS2BITS IFS2bits;
#word IFS2bits = 0x088
#word IFS2 = 0x088

typedef struct 
 {
   unsigned int :1;
   unsigned int SI2C2IF:1;
   unsigned int MI2C2IF:1;
   unsigned int :2;
   unsigned int INT3IF:1;
   unsigned int INT4IF:1;
   unsigned int :7;
   unsigned int RTCIF:1;
} IFS3BITS;
IFS3BITS IFS3bits;
#word IFS3bits = 0x08A
#word IFS3 = 0x08A

typedef struct 
 {
   unsigned int :1;
   unsigned int U1ERIF:1;
   unsigned int U2ERIF:1;
   unsigned int CRCIF:1;
   unsigned int :4;
   unsigned int LVDIF:1;
   unsigned int :4;
   unsigned int CTMUIF:1;
} IFS4BITS;
IFS4BITS IFS4bits;
#word IFS4bits = 0x08C
#word IFS4 = 0x08C

typedef struct 
 {
   unsigned int :1;
   unsigned int U3ERIF:1;
   unsigned int U3RXIF:1;
   unsigned int U3TXIF:1;
   unsigned int SI2C3IF:1;
   unsigned int MI2C3IF:1;
   unsigned int USB1IF:1;
   unsigned int U4ERIF:1;
   unsigned int U4RXIF:1;
   unsigned int U4TXIF:1;
   unsigned int SPF3IF:1;
   unsigned int SPI3IF:1;
   unsigned int OC9IF:1;
   unsigned int IC9IF:1;
} IFS5BITS;
IFS5BITS IFS5bits;
#word IFS5bits = 0x08E
#word IFS5 = 0x08E

typedef struct 
 {
   unsigned int INT0IE:1;
   unsigned int IC1IE:1;
   unsigned int OC1IE:1;
   unsigned int T1IE:1;
   unsigned int :1;
   unsigned int IC2IE:1;
   unsigned int OC2IE:1;
   unsigned int T2IE:1;
   unsigned int T3IE:1;
   unsigned int SPF1IE:1;
   unsigned int SPI1IE:1;
   unsigned int U1RXIE:1;
   unsigned int U1TXIE:1;
   unsigned int AD1IE:1;
} IEC0BITS;
IEC0BITS IEC0bits;
#word IEC0bits = 0x094
#word IEC0 = 0x094

typedef struct 
 {
   unsigned int SI2C1IE:1;
   unsigned int MI2C1IE:1;
   unsigned int CMIE:1;
   unsigned int CNIE:1;
   unsigned int INT1IE:1;
   unsigned int :1;
   unsigned int IC7IE:1;
   unsigned int IC8IE:1;
   unsigned int :1;
   unsigned int OC3IE:1;
   unsigned int OC4IE:1;
   unsigned int T4IE:1;
   unsigned int T5IE:1;
   unsigned int INT2IE:1;
   unsigned int U2RXIE:1;
   unsigned int U2TXIE:1;
} IEC1BITS;
IEC1BITS IEC1bits;
#word IEC1bits = 0x096
#word IEC1 = 0x096

typedef struct 
 {
   unsigned int SPF2IE:1;
   unsigned int SPI2IE:1;
   unsigned int :3;
   unsigned int IC3IE:1;
   unsigned int IC4IE:1;
   unsigned int IC5IE:1;
   unsigned int IC6IE:1;
   unsigned int OC5IE:1;
   unsigned int OC6IE:1;
   unsigned int OC7IE:1;
   unsigned int OC8IE:1;
   unsigned int PMPIE:1;
} IEC2BITS;
IEC2BITS IEC2bits;
#word IEC2bits = 0x098
#word IEC2 = 0x098

typedef struct 
 {
   unsigned int :1;
   unsigned int SI2C2IE:1;
   unsigned int MI2C2IE:1;
   unsigned int :2;
   unsigned int INT3IE:1;
   unsigned int INT4IE:1;
   unsigned int :7;
   unsigned int RTCIE:1;
} IEC3BITS;
IEC3BITS IEC3bits;
#word IEC3bits = 0x09A
#word IEC3 = 0x09A

typedef struct 
 {
   unsigned int :1;
   unsigned int U1ERIE:1;
   unsigned int U2ERIE:1;
   unsigned int CRCIE:1;
   unsigned int :4;
   unsigned int LVDIE:1;
   unsigned int :4;
   unsigned int CTMUIE:1;
} IEC4BITS;
IEC4BITS IEC4bits;
#word IEC4bits = 0x09C
#word IEC4 = 0x09C

typedef struct 
 {
   unsigned int :1;
   unsigned int U3ERIE:1;
   unsigned int U3RXIE:1;
   unsigned int U3TXIE:1;
   unsigned int SI2C3IE:1;
   unsigned int MI2C3IE:1;
   unsigned int USB1IE:1;
   unsigned int U4ERIE:1;
   unsigned int U4RXIE:1;
   unsigned int U4TXIE:1;
   unsigned int SPF3IE:1;
   unsigned int SPI3IE:1;
   unsigned int OC9IE:1;
   unsigned int IC9IE:1;
} IEC5BITS;
IEC5BITS IEC5bits;
#word IEC5bits = 0x09E
#word IEC5 = 0x09E

typedef union 
 {
      struct {
         unsigned int INT0IP0:3;
         unsigned int :1;
         unsigned int IC1IP0:3;
         unsigned int :1;
         unsigned int OC1IP0:3;
         unsigned int :1;
         unsigned int T1IP0:3;
      };
      struct {
         unsigned int INT0IP:3;
         unsigned int :1;
         unsigned int IC1IP:3;
         unsigned int :1;
         unsigned int OC1IP:3;
         unsigned int :1;
         unsigned int T1IP:3;
      };
} IPC0BITS;
IPC0BITS IPC0bits;
#word IPC0bits = 0x0A4
#word IPC0 = 0x0A4

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int IC2IP0:3;
         unsigned int :1;
         unsigned int OC2IP0:3;
         unsigned int :1;
         unsigned int T2IP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int IC2IP:3;
         unsigned int :1;
         unsigned int OC2IP:3;
         unsigned int :1;
         unsigned int T2IP:3;
      };
} IPC1BITS;
IPC1BITS IPC1bits;
#word IPC1bits = 0x0A6
#word IPC1 = 0x0A6

typedef union 
 {
      struct {
         unsigned int T3IP0:3;
         unsigned int :1;
         unsigned int SPF1IP0:3;
         unsigned int :1;
         unsigned int SPI1IP0:3;
         unsigned int :1;
         unsigned int U1RXIP0:3;
      };
      struct {
         unsigned int T3IP:3;
         unsigned int :1;
         unsigned int SPF1IP:3;
         unsigned int :1;
         unsigned int SPI1IP:3;
         unsigned int :1;
         unsigned int U1RXIP:3;
      };
} IPC2BITS;
IPC2BITS IPC2bits;
#word IPC2bits = 0x0A8
#word IPC2 = 0x0A8

typedef union 
 {
      struct {
         unsigned int U1TXIP0:3;
         unsigned int :1;
         unsigned int AD1IP0:3;
      };
      struct {
         unsigned int U1TXIP:3;
         unsigned int :1;
         unsigned int AD1IP:3;
      };
} IPC3BITS;
IPC3BITS IPC3bits;
#word IPC3bits = 0x0AA
#word IPC3 = 0x0AA

typedef union 
 {
   union {
      struct {
         unsigned int SI2C1IP0:3;
         unsigned int :1;
         unsigned int MI2C1IP0:3;
         unsigned int :1;
         unsigned int CMIP0:3;
         unsigned int :1;
         unsigned int CNIP0:3;
      };
      struct {
         unsigned int SI2C1IP:3;
         unsigned int :1;
         unsigned int MI2C1IP:3;
         unsigned int :1;
         unsigned int CMIP:3;
         unsigned int :1;
         unsigned int CNIP:3;
      };

      struct {
         unsigned int SI2C1P0:3;
         unsigned int :1;
         unsigned int MI2C1P0:3;
      };
   };
      struct {
         unsigned int SI2C1P:3;
         unsigned int :1;
         unsigned int MI2C1P:3;
      };
} IPC4BITS;
IPC4BITS IPC4bits;
#word IPC4bits = 0x0AC
#word IPC4 = 0x0AC

typedef union 
 {
      struct {
         unsigned int INT1IP0:3;
         unsigned int :5;
         unsigned int IC7IP0:3;
         unsigned int :1;
         unsigned int IC8IP0:3;
      };
      struct {
         unsigned int INT1IP:3;
         unsigned int :5;
         unsigned int IC7IP:3;
         unsigned int :1;
         unsigned int IC8IP:3;
      };
} IPC5BITS;
IPC5BITS IPC5bits;
#word IPC5bits = 0x0AE
#word IPC5 = 0x0AE

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int OC3IP0:3;
         unsigned int :1;
         unsigned int OC4IP0:3;
         unsigned int :1;
         unsigned int T4IP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int OC3IP:3;
         unsigned int :1;
         unsigned int OC4IP:3;
         unsigned int :1;
         unsigned int T4IP:3;
      };
} IPC6BITS;
IPC6BITS IPC6bits;
#word IPC6bits = 0x0B0
#word IPC6 = 0x0B0

typedef union 
 {
      struct {
         unsigned int T5IP0:3;
         unsigned int :1;
         unsigned int INT2IP0:3;
         unsigned int :1;
         unsigned int U2RXIP0:3;
         unsigned int :1;
         unsigned int U2TXIP0:3;
      };
      struct {
         unsigned int T5IP:3;
         unsigned int :1;
         unsigned int INT2IP:3;
         unsigned int :1;
         unsigned int U2RXIP:3;
         unsigned int :1;
         unsigned int U2TXIP:3;
      };
} IPC7BITS;
IPC7BITS IPC7bits;
#word IPC7bits = 0x0B2
#word IPC7 = 0x0B2

typedef union 
 {
      struct {
         unsigned int SPF2IP0:3;
         unsigned int :1;
         unsigned int SPI2IP0:3;
      };
      struct {
         unsigned int SPF2IP:3;
         unsigned int :1;
         unsigned int SPI2IP:3;
      };
} IPC8BITS;
IPC8BITS IPC8bits;
#word IPC8bits = 0x0B4
#word IPC8 = 0x0B4

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int IC3IP0:3;
         unsigned int :1;
         unsigned int IC4IP0:3;
         unsigned int :1;
         unsigned int IC5IP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int IC3IP:3;
         unsigned int :1;
         unsigned int IC4IP:3;
         unsigned int :1;
         unsigned int IC5IP:3;
      };
} IPC9BITS;
IPC9BITS IPC9bits;
#word IPC9bits = 0x0B6
#word IPC9 = 0x0B6

typedef union 
 {
      struct {
         unsigned int IC6IP0:3;
         unsigned int :1;
         unsigned int OC5IP0:3;
         unsigned int :1;
         unsigned int OC6IP0:3;
         unsigned int :1;
         unsigned int OC7IP0:3;
      };
      struct {
         unsigned int IC6IP:3;
         unsigned int :1;
         unsigned int OC5IP:3;
         unsigned int :1;
         unsigned int OC6IP:3;
         unsigned int :1;
         unsigned int OC7IP:3;
      };
} IPC10BITS;
IPC10BITS IPC10bits;
#word IPC10bits = 0x0B8
#word IPC10 = 0x0B8

typedef union 
 {
      struct {
         unsigned int OC8IP0:3;
         unsigned int :1;
         unsigned int PMPIP0:3;
      };
      struct {
         unsigned int OC8IP:3;
         unsigned int :1;
         unsigned int PMPIP:3;
      };
} IPC11BITS;
IPC11BITS IPC11bits;
#word IPC11bits = 0x0BA
#word IPC11 = 0x0BA

typedef union 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int SI2C2IP0:3;
         unsigned int :1;
         unsigned int MI2C2IP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int SI2C2IP:3;
         unsigned int :1;
         unsigned int MI2C2IP:3;
      };

      struct {
         unsigned int :4;
         unsigned int SI2C2P0:3;
         unsigned int :1;
         unsigned int MI2C2P0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int SI2C2P:3;
         unsigned int :1;
         unsigned int MI2C2P:3;
      };
} IPC12BITS;
IPC12BITS IPC12bits;
#word IPC12bits = 0x0BC
#word IPC12 = 0x0BC

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int INT3IP0:3;
         unsigned int :1;
         unsigned int INT4IP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int INT3IP:3;
         unsigned int :1;
         unsigned int INT4IP:3;
      };
} IPC13BITS;
IPC13BITS IPC13bits;
#word IPC13bits = 0x0BE
#word IPC13 = 0x0BE

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int RTCIP0:3;
      };
      struct {
         unsigned int :8;
         unsigned int RTCIP:3;
      };
} IPC15BITS;
IPC15BITS IPC15bits;
#word IPC15bits = 0x0C2
#word IPC15 = 0x0C2

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int U1ERIP0:3;
         unsigned int :1;
         unsigned int U2ERIP0:3;
         unsigned int :1;
         unsigned int CRCIP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int U1ERIP:3;
         unsigned int :1;
         unsigned int U2ERIP:3;
         unsigned int :1;
         unsigned int CRCIP:3;
      };
} IPC16BITS;
IPC16BITS IPC16bits;
#word IPC16bits = 0x0C4
#word IPC16 = 0x0C4

#word IPC18 = 0x0C8

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int CTMUIP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int CTMUIP:3;
      };
} IPC19BITS;
IPC19BITS IPC19bits;
#word IPC19bits = 0x0CA
#word IPC19 = 0x0CA

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int U3ERIP0:3;
         unsigned int :1;
         unsigned int U3RXIP0:3;
         unsigned int :1;
         unsigned int U3TXIP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int U3ERIP:3;
         unsigned int :1;
         unsigned int U3RXIP:3;
         unsigned int :1;
         unsigned int U3TXIP:3;
      };
} IPC20BITS;
IPC20BITS IPC20bits;
#word IPC20bits = 0x0CC
#word IPC20 = 0x0CC

typedef union 
 {
   union {
      struct {
         unsigned int SI2C3IP0:3;
         unsigned int :1;
         unsigned int MI2C3IP0:3;
         unsigned int :1;
         unsigned int USB1IP0:3;
         unsigned int :1;
         unsigned int U4ERIP0:3;
      };
      struct {
         unsigned int SI2C3IP:3;
         unsigned int :1;
         unsigned int MI2C3IP:3;
         unsigned int :1;
         unsigned int USB1IP:3;
         unsigned int :1;
         unsigned int U4ERIP:3;
      };

      struct {
         unsigned int SI2C3P0:3;
         unsigned int :1;
         unsigned int MI2C3P0:3;
      };
   };
      struct {
         unsigned int SI2C3P:3;
         unsigned int :1;
         unsigned int MI2C3P:3;
      };
} IPC21BITS;
IPC21BITS IPC21bits;
#word IPC21bits = 0x0CE
#word IPC21 = 0x0CE

typedef union 
 {
      struct {
         unsigned int U4RXIP0:3;
         unsigned int :1;
         unsigned int U4TXIP0:3;
         unsigned int :1;
         unsigned int SPF3IP0:3;
         unsigned int :1;
         unsigned int SPI3IP0:3;
      };
      struct {
         unsigned int U4RXIP:3;
         unsigned int :1;
         unsigned int U4TXIP:3;
         unsigned int :1;
         unsigned int SPF3IP:3;
         unsigned int :1;
         unsigned int SPI3IP:3;
      };
} IPC22BITS;
IPC22BITS IPC22bits;
#word IPC22bits = 0x0D0
#word IPC22 = 0x0D0

typedef union 
 {
      struct {
         unsigned int OC9IP0:3;
         unsigned int :1;
         unsigned int IC9IP0:3;
      };
      struct {
         unsigned int OC9IP:3;
         unsigned int :1;
         unsigned int IC9IP:3;
      };
} IPC23BITS;
IPC23BITS IPC23bits;
#word IPC23bits = 0x0D2
#word IPC23 = 0x0D2

typedef union 
 {
      struct {
         unsigned int VECNUM0:7;
         unsigned int :1;
         unsigned int ILR0:4;
         unsigned int :1;
         unsigned int VHOLD:1;
         unsigned int :1;
         unsigned int CPUIRQ:1;
      };
      struct {
         unsigned int VECNUM:7;
         unsigned int :1;
         unsigned int ILR:4;
      };
} INTTREGBITS;
INTTREGBITS INTTREGbits;
#word INTTREGbits = 0x0E0
#word INTTREG = 0x0E0

#word TMR1 = 0x100

#word PR1 = 0x102

typedef union 
 {
      struct {
         unsigned int :1;
         unsigned int TCS:1;
         unsigned int TSYNC:1;
         unsigned int :1;
         unsigned int TCKPS0:2;
         unsigned int TGATE:1;
         unsigned int :6;
         unsigned int TSIDL:1;
         unsigned int :1;
         unsigned int TON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TCKPS:2;
         unsigned int :1;
         unsigned int :6;
      };
} T1CONBITS;
T1CONBITS T1CONbits;
#word T1CONbits = 0x104
#word T1CON = 0x104

#word TMR2 = 0x106

#word TMR3HLD = 0x108

#word TMR3 = 0x10A

#word PR2 = 0x10C

#word PR3 = 0x10E

typedef union 
 {
      struct {
         unsigned int :1;
         unsigned int TCS:1;
         unsigned int :1;
         unsigned int T32:1;
         unsigned int TCKPS0:2;
         unsigned int TGATE:1;
         unsigned int :6;
         unsigned int TSIDL:1;
         unsigned int :1;
         unsigned int TON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TCKPS:2;
         unsigned int :1;
         unsigned int :6;
      };
} T2CONBITS;
T2CONBITS T2CONbits;
#word T2CONbits = 0x110
#word T2CON = 0x110

typedef union 
 {
      struct {
         unsigned int :1;
         unsigned int TCS:1;
         unsigned int :2;
         unsigned int TCKPS0:2;
         unsigned int TGATE:1;
         unsigned int :6;
         unsigned int TSIDL:1;
         unsigned int :1;
         unsigned int TON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :2;
         unsigned int TCKPS:2;
         unsigned int :1;
         unsigned int :6;
      };
} T3CONBITS;
T3CONBITS T3CONbits;
#word T3CONbits = 0x112
#word T3CON = 0x112

#word TMR4 = 0x114

#word TMR5HLD = 0x116

#word TMR5 = 0x118

#word PR4 = 0x11A

#word PR5 = 0x11C

typedef union 
 {
      struct {
         unsigned int :1;
         unsigned int TCS:1;
         unsigned int :1;
         unsigned int T45:1;
         unsigned int TCKPS0:2;
         unsigned int TGATE:1;
         unsigned int :6;
         unsigned int TSIDL:1;
         unsigned int :1;
         unsigned int TON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TCKPS:2;
         unsigned int :1;
         unsigned int :6;
      };
} T4CONBITS;
T4CONBITS T4CONbits;
#word T4CONbits = 0x11E
#word T4CON = 0x11E

typedef union 
 {
      struct {
         unsigned int :1;
         unsigned int TCS:1;
         unsigned int :2;
         unsigned int TCKPS0:2;
         unsigned int TGATE:1;
         unsigned int :6;
         unsigned int TSIDL:1;
         unsigned int :1;
         unsigned int TON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :2;
         unsigned int TCKPS:2;
         unsigned int :1;
         unsigned int :6;
      };
} T5CONBITS;
T5CONBITS T5CONbits;
#word T5CONbits = 0x120
#word T5CON = 0x120

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC1CON1BITS;
IC1CON1BITS IC1CON1bits;
#word IC1CON1bits = 0x140
#word IC1CON1 = 0x140

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC1CON2BITS;
IC1CON2BITS IC1CON2bits;
#word IC1CON2bits = 0x142
#word IC1CON2 = 0x142

#word IC1BUF = 0x144

#word IC1TMR = 0x146

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC2CON1BITS;
IC2CON1BITS IC2CON1bits;
#word IC2CON1bits = 0x148
#word IC2CON1 = 0x148

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC2CON2BITS;
IC2CON2BITS IC2CON2bits;
#word IC2CON2bits = 0x14A
#word IC2CON2 = 0x14A

#word IC2BUF = 0x14C

#word IC2TMR = 0x14E

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC3CON1BITS;
IC3CON1BITS IC3CON1bits;
#word IC3CON1bits = 0x150
#word IC3CON1 = 0x150

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC3CON2BITS;
IC3CON2BITS IC3CON2bits;
#word IC3CON2bits = 0x152
#word IC3CON2 = 0x152

#word IC3BUF = 0x154

#word IC3TMR = 0x156

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC4CON1BITS;
IC4CON1BITS IC4CON1bits;
#word IC4CON1bits = 0x158
#word IC4CON1 = 0x158

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC4CON2BITS;
IC4CON2BITS IC4CON2bits;
#word IC4CON2bits = 0x15A
#word IC4CON2 = 0x15A

#word IC4BUF = 0x15C

#word IC4TMR = 0x15E

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC5CON1BITS;
IC5CON1BITS IC5CON1bits;
#word IC5CON1bits = 0x160
#word IC5CON1 = 0x160

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC5CON2BITS;
IC5CON2BITS IC5CON2bits;
#word IC5CON2bits = 0x162
#word IC5CON2 = 0x162

#word IC5BUF = 0x164

#word IC5TMR = 0x166

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC6CON1BITS;
IC6CON1BITS IC6CON1bits;
#word IC6CON1bits = 0x168
#word IC6CON1 = 0x168

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC6CON2BITS;
IC6CON2BITS IC6CON2bits;
#word IC6CON2bits = 0x16A
#word IC6CON2 = 0x16A

#word IC6BUF = 0x16C

#word IC6TMR = 0x16E

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC7CON1BITS;
IC7CON1BITS IC7CON1bits;
#word IC7CON1bits = 0x170
#word IC7CON1 = 0x170

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC7CON2BITS;
IC7CON2BITS IC7CON2bits;
#word IC7CON2bits = 0x172
#word IC7CON2 = 0x172

#word IC7BUF = 0x174

#word IC7TMR = 0x176

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC8CON1BITS;
IC8CON1BITS IC8CON1bits;
#word IC8CON1bits = 0x178
#word IC8CON1 = 0x178

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC8CON2BITS;
IC8CON2BITS IC8CON2bits;
#word IC8CON2bits = 0x17A
#word IC8CON2 = 0x17A

#word IC8BUF = 0x17C

#word IC8TMR = 0x17E

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int :3;
         unsigned int ICTSEL0:3;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :3;
         unsigned int ICTSEL:3;
      };
} IC9CON1BITS;
IC9CON1BITS IC9CON1bits;
#word IC9CON1bits = 0x180
#word IC9CON1 = 0x180

typedef union 
 {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int :1;
         unsigned int TRIGSTAT:1;
         unsigned int ICTRIG:1;
         unsigned int IC32:1;
      };
      struct {
         unsigned int SYNCSEL:5;
      };
} IC9CON2BITS;
IC9CON2BITS IC9CON2bits;
#word IC9CON2bits = 0x182
#word IC9CON2 = 0x182

#word IC9BUF = 0x184

#word IC9TMR = 0x186

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC1CON1BITS;
OC1CON1BITS OC1CON1bits;
#word OC1CON1bits = 0x190
#word OC1CON1 = 0x190

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC1CON2BITS;
OC1CON2BITS OC1CON2bits;
#word OC1CON2bits = 0x192
#word OC1CON2 = 0x192

#word OC1RS = 0x194

#word OC1R = 0x196

#word OC1TMR = 0x198

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC2CON1BITS;
OC2CON1BITS OC2CON1bits;
#word OC2CON1bits = 0x19A
#word OC2CON1 = 0x19A

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC2CON2BITS;
OC2CON2BITS OC2CON2bits;
#word OC2CON2bits = 0x19C
#word OC2CON2 = 0x19C

#word OC2RS = 0x19E

#word OC2R = 0x1A0

#word OC2TMR = 0x1A2

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC3CON1BITS;
OC3CON1BITS OC3CON1bits;
#word OC3CON1bits = 0x1A4
#word OC3CON1 = 0x1A4

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC3CON2BITS;
OC3CON2BITS OC3CON2bits;
#word OC3CON2bits = 0x1A6
#word OC3CON2 = 0x1A6

#word OC3RS = 0x1A8

#word OC3R = 0x1AA

#word OC3TMR = 0x1AC

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC4CON1BITS;
OC4CON1BITS OC4CON1bits;
#word OC4CON1bits = 0x1AE
#word OC4CON1 = 0x1AE

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC4CON2BITS;
OC4CON2BITS OC4CON2bits;
#word OC4CON2bits = 0x1B0
#word OC4CON2 = 0x1B0

#word OC4RS = 0x1B2

#word OC4R = 0x1B4

#word OC4TMR = 0x1B6

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC5CON1BITS;
OC5CON1BITS OC5CON1bits;
#word OC5CON1bits = 0x1B8
#word OC5CON1 = 0x1B8

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC5CON2BITS;
OC5CON2BITS OC5CON2bits;
#word OC5CON2bits = 0x1BA
#word OC5CON2 = 0x1BA

#word OC5RS = 0x1BC

#word OC5R = 0x1BE

#word OC5TMR = 0x1C0

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC6CON1BITS;
OC6CON1BITS OC6CON1bits;
#word OC6CON1bits = 0x1C2
#word OC6CON1 = 0x1C2

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC6CON2BITS;
OC6CON2BITS OC6CON2bits;
#word OC6CON2bits = 0x1C4
#word OC6CON2 = 0x1C4

#word OC6RS = 0x1C6

#word OC6R = 0x1C8

#word OC6TMR = 0x1CA

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC7CON1BITS;
OC7CON1BITS OC7CON1bits;
#word OC7CON1bits = 0x1CC
#word OC7CON1 = 0x1CC

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC7CON2BITS;
OC7CON2BITS OC7CON2bits;
#word OC7CON2bits = 0x1CE
#word OC7CON2 = 0x1CE

#word OC7RS = 0x1D0

#word OC7R = 0x1D2

#word OC7TMR = 0x1D4

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC8CON1BITS;
OC8CON1BITS OC8CON1bits;
#word OC8CON1bits = 0x1D6
#word OC8CON1 = 0x1D6

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC8CON2BITS;
OC8CON2BITS OC8CON2bits;
#word OC8CON2bits = 0x1D8
#word OC8CON2 = 0x1D8

#word OC8RS = 0x1DA

#word OC8R = 0x1DC

#word OC8TMR = 0x1DE

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
         unsigned int OCTSEL:3;
      };
} OC9CON1BITS;
OC9CON1BITS OC9CON1bits;
#word OC9CON1bits = 0x1E0
#word OC9CON1 = 0x1E0

typedef union 
 {
   union {
      struct {
         unsigned int SYNCSEL0:5;
         unsigned int OCTRIS:1;
         unsigned int TRIGSTAT:1;
         unsigned int OCTRIG:1;
         unsigned int OC32:1;
         unsigned int DCB0:2;
         unsigned int :1;
         unsigned int OCINV:1;
         unsigned int FLTTRIEN:1;
         unsigned int FLTOUT:1;
         unsigned int FLTMD:1;
      };
      struct {
         unsigned int SYNCSEL:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DCB:2;
      };

      struct {
         unsigned int :15;
         unsigned int FLTMODE:1;
      };
   };
} OC9CON2BITS;
OC9CON2BITS OC9CON2bits;
#word OC9CON2bits = 0x1E2
#word OC9CON2 = 0x1E2

#word OC9RS = 0x1E4

#word OC9R = 0x1E6

#word OC9TMR = 0x1E8

#word I2C1RCV = 0x200

#word I2C1TRN = 0x202

#word I2C1BRG = 0x204

typedef struct 
 {
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int STREN:1;
   unsigned int GCEN:1;
   unsigned int SMEN:1;
   unsigned int DISSLW:1;
   unsigned int A10M:1;
   unsigned int IPMIEN:1;
   unsigned int SCLREL:1;
   unsigned int I2CSIDL:1;
   unsigned int :1;
   unsigned int I2CEN:1;
} I2C1CONBITS;
I2C1CONBITS I2C1CONbits;
#word I2C1CONbits = 0x206
#word I2C1CON = 0x206

typedef struct 
 {
   union {
      struct {
         unsigned int TBF:1;
         unsigned int RBF:1;
         unsigned int R:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D:1;
         unsigned int I2COV:1;
         unsigned int IWCOL:1;
         unsigned int ADD10:1;
         unsigned int GCSTAT:1;
         unsigned int BCL:1;
         unsigned int :3;
         unsigned int TRSTAT:1;
         unsigned int ACKSTAT:1;
      };

      struct {
         unsigned int :2;
         unsigned int R_W:1;
         unsigned int :2;
         unsigned int D_A:1;
      };
   };
} I2C1STATBITS;
I2C1STATBITS I2C1STATbits;
#word I2C1STATbits = 0x208
#word I2C1STAT = 0x208

#word I2C1ADD = 0x20A

#word I2C1MSK = 0x20C

#word I2C2RCV = 0x210

#word I2C2TRN = 0x212

#word I2C2BRG = 0x214

typedef struct 
 {
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int STREN:1;
   unsigned int GCEN:1;
   unsigned int SMEN:1;
   unsigned int DISSLW:1;
   unsigned int A10M:1;
   unsigned int IPMIEN:1;
   unsigned int SCLREL:1;
   unsigned int I2CSIDL:1;
   unsigned int :1;
   unsigned int I2CEN:1;
} I2C2CONBITS;
I2C2CONBITS I2C2CONbits;
#word I2C2CONbits = 0x216
#word I2C2CON = 0x216

typedef struct 
 {
   union {
      struct {
         unsigned int TBF:1;
         unsigned int RBF:1;
         unsigned int R:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D:1;
         unsigned int I2COV:1;
         unsigned int IWCOL:1;
         unsigned int ADD10:1;
         unsigned int GCSTAT:1;
         unsigned int BCL:1;
         unsigned int :3;
         unsigned int TRSTAT:1;
         unsigned int ACKSTAT:1;
      };

      struct {
         unsigned int :2;
         unsigned int R_W:1;
         unsigned int :2;
         unsigned int D_A:1;
      };
   };
} I2C2STATBITS;
I2C2STATBITS I2C2STATbits;
#word I2C2STATbits = 0x218
#word I2C2STAT = 0x218

#word I2C2ADD = 0x21A

#word I2C2MSK = 0x21C

typedef union 
 {
      struct {
         unsigned int STSEL:1;
         unsigned int PDSEL0:2;
         unsigned int BRGH:1;
         unsigned int RXINV:1;
         unsigned int ABAUD:1;
         unsigned int LPBACK:1;
         unsigned int WAKE:1;
         unsigned int UEN0:2;
         unsigned int :1;
         unsigned int RTSMD:1;
         unsigned int IREN:1;
         unsigned int USIDL:1;
         unsigned int :1;
         unsigned int UARTEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int PDSEL:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int UEN:2;
      };
} U1MODEBITS;
U1MODEBITS U1MODEbits;
#word U1MODEbits = 0x220
#word U1MODE = 0x220

typedef union 
 {
      struct {
         unsigned int URXDA:1;
         unsigned int OERR:1;
         unsigned int FERR:1;
         unsigned int PERR:1;
         unsigned int RIDLE:1;
         unsigned int ADDEN:1;
         unsigned int URXISEL0:2;
         unsigned int TRMT:1;
         unsigned int UTXBF:1;
         unsigned int UTXEN:1;
         unsigned int UTXBRK:1;
         unsigned int :1;
         unsigned int UTXISEL0:1;
         unsigned int UTXINV:1;
         unsigned int UTXISEL1:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int URXISEL:2;
      };
} U1STABITS;
U1STABITS U1STAbits;
#word U1STAbits = 0x222
#word U1STA = 0x222

#word U1TXREG = 0x224

typedef union 
 {
      struct {
         unsigned int UTXREG0:9;
      };
      struct {
         unsigned int UTXREG:9;
      };
} U1TXREGBITS;
U1TXREGBITS U1TXREGbits;
#word U1TXREGbits = 0x224
#word U1TXREG = 0x224

#word U1RXREG = 0x226

typedef union 
 {
      struct {
         unsigned int URXREG0:9;
      };
      struct {
         unsigned int URXREG:9;
      };
} U1RXREGBITS;
U1RXREGBITS U1RXREGbits;
#word U1RXREGbits = 0x226
#word U1RXREG = 0x226

#word U1BRG = 0x228

typedef union 
 {
      struct {
         unsigned int STSEL:1;
         unsigned int PDSEL0:2;
         unsigned int BRGH:1;
         unsigned int RXINV:1;
         unsigned int ABAUD:1;
         unsigned int LPBACK:1;
         unsigned int WAKE:1;
         unsigned int UEN0:2;
         unsigned int :1;
         unsigned int RTSMD:1;
         unsigned int IREN:1;
         unsigned int USIDL:1;
         unsigned int :1;
         unsigned int UARTEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int PDSEL:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int UEN:2;
      };
} U2MODEBITS;
U2MODEBITS U2MODEbits;
#word U2MODEbits = 0x230
#word U2MODE = 0x230

typedef union 
 {
      struct {
         unsigned int URXDA:1;
         unsigned int OERR:1;
         unsigned int FERR:1;
         unsigned int PERR:1;
         unsigned int RIDLE:1;
         unsigned int ADDEN:1;
         unsigned int URXISEL0:2;
         unsigned int TRMT:1;
         unsigned int UTXBF:1;
         unsigned int UTXEN:1;
         unsigned int UTXBRK:1;
         unsigned int :1;
         unsigned int UTXISEL0:1;
         unsigned int UTXINV:1;
         unsigned int UTXISEL1:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int URXISEL:2;
      };
} U2STABITS;
U2STABITS U2STAbits;
#word U2STAbits = 0x232
#word U2STA = 0x232

#word U2TXREG = 0x234

typedef union 
 {
      struct {
         unsigned int UTXREG0:9;
      };
      struct {
         unsigned int UTXREG:9;
      };
} U2TXREGBITS;
U2TXREGBITS U2TXREGbits;
#word U2TXREGbits = 0x234
#word U2TXREG = 0x234

#word U2RXREG = 0x236

typedef union 
 {
      struct {
         unsigned int URXREG0:9;
      };
      struct {
         unsigned int URXREG:9;
      };
} U2RXREGBITS;
U2RXREGBITS U2RXREGbits;
#word U2RXREGbits = 0x236
#word U2RXREG = 0x236

#word U2BRG = 0x238

typedef union 
 {
      struct {
         unsigned int SPIRBF:1;
         unsigned int SPITBF:1;
         unsigned int SISEL0:3;
         unsigned int SRXMPT:1;
         unsigned int SPIROV:1;
         unsigned int SRMPT:1;
         unsigned int SPIBEC0:3;
         unsigned int :2;
         unsigned int SPISIDL:1;
         unsigned int :1;
         unsigned int SPIEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SISEL:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SPIBEC:3;
         unsigned int :2;
      };
} SPI1STATBITS;
SPI1STATBITS SPI1STATbits;
#word SPI1STATbits = 0x240
#word SPI1STAT = 0x240

typedef union 
 {
      struct {
         unsigned int PPRE0:2;
         unsigned int SPRE0:3;
         unsigned int MSTEN:1;
         unsigned int CKP:1;
         unsigned int SSEN:1;
         unsigned int CKE:1;
         unsigned int SMP:1;
         unsigned int MODE16:1;
         unsigned int DISSDO:1;
         unsigned int DISSCK:1;
      };
      struct {
         unsigned int PPRE:2;
         unsigned int SPRE:3;
      };
} SPI1CON1BITS;
SPI1CON1BITS SPI1CON1bits;
#word SPI1CON1bits = 0x242
#word SPI1CON1 = 0x242

typedef struct 
 {
   unsigned int SPIBEN:1;
   unsigned int SPIFE:1;
   unsigned int :11;
   unsigned int SPIFPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI1CON2BITS;
SPI1CON2BITS SPI1CON2bits;
#word SPI1CON2bits = 0x244
#word SPI1CON2 = 0x244

#word SPI1BUF = 0x248

typedef union 
 {
      struct {
         unsigned int STSEL:1;
         unsigned int PDSEL0:2;
         unsigned int BRGH:1;
         unsigned int RXINV:1;
         unsigned int ABAUD:1;
         unsigned int LPBACK:1;
         unsigned int WAKE:1;
         unsigned int UEN0:2;
         unsigned int :1;
         unsigned int RTSMD:1;
         unsigned int IREN:1;
         unsigned int USIDL:1;
         unsigned int :1;
         unsigned int UARTEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int PDSEL:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int UEN:2;
      };
} U3MODEBITS;
U3MODEBITS U3MODEbits;
#word U3MODEbits = 0x250
#word U3MODE = 0x250

typedef union 
 {
      struct {
         unsigned int URXDA:1;
         unsigned int OERR:1;
         unsigned int FERR:1;
         unsigned int PERR:1;
         unsigned int RIDLE:1;
         unsigned int ADDEN:1;
         unsigned int URXISEL0:2;
         unsigned int TRMT:1;
         unsigned int UTXBF:1;
         unsigned int UTXEN:1;
         unsigned int UTXBRK:1;
         unsigned int :1;
         unsigned int UTXISEL0:1;
         unsigned int UTXINV:1;
         unsigned int UTXISEL1:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int URXISEL:2;
      };
} U3STABITS;
U3STABITS U3STAbits;
#word U3STAbits = 0x252
#word U3STA = 0x252

typedef union 
 {
      struct {
         unsigned int UTXREG0:9;
      };
      struct {
         unsigned int UTXREG:9;
      };
} U3TXREGBITS;
U3TXREGBITS U3TXREGbits;
#word U3TXREGbits = 0x254
#word U3TXREG = 0x254

typedef union 
 {
      struct {
         unsigned int URXREG0:9;
      };
      struct {
         unsigned int URXREG:9;
      };
} U3RXREGBITS;
U3RXREGBITS U3RXREGbits;
#word U3RXREGbits = 0x256
#word U3RXREG = 0x256

#word U3BRG = 0x258

typedef union 
 {
      struct {
         unsigned int SPIRBF:1;
         unsigned int SPITBF:1;
         unsigned int SISEL0:3;
         unsigned int SRXMPT:1;
         unsigned int SPIROV:1;
         unsigned int SRMPT:1;
         unsigned int SPIBEC0:3;
         unsigned int :2;
         unsigned int SPISIDL:1;
         unsigned int :1;
         unsigned int SPIEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SISEL:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SPIBEC:3;
         unsigned int :2;
      };
} SPI2STATBITS;
SPI2STATBITS SPI2STATbits;
#word SPI2STATbits = 0x260
#word SPI2STAT = 0x260

typedef union 
 {
      struct {
         unsigned int PPRE0:2;
         unsigned int SPRE0:3;
         unsigned int MSTEN:1;
         unsigned int CKP:1;
         unsigned int SSEN:1;
         unsigned int CKE:1;
         unsigned int SMP:1;
         unsigned int MODE16:1;
         unsigned int DISSDO:1;
         unsigned int DISSCK:1;
      };
      struct {
         unsigned int PPRE:2;
         unsigned int SPRE:3;
      };
} SPI2CON1BITS;
SPI2CON1BITS SPI2CON1bits;
#word SPI2CON1bits = 0x262
#word SPI2CON1 = 0x262

typedef struct 
 {
   unsigned int SPIBEN:1;
   unsigned int SPIFE:1;
   unsigned int :11;
   unsigned int SPIFPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI2CON2BITS;
SPI2CON2BITS SPI2CON2bits;
#word SPI2CON2bits = 0x264
#word SPI2CON2 = 0x264

#word SPI2BUF = 0x268

#word I2C3RCV = 0x270

#word I2C3TRN = 0x272

#word I2C3BRG = 0x274

typedef struct 
 {
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int STREN:1;
   unsigned int GCEN:1;
   unsigned int SMEN:1;
   unsigned int DISSLW:1;
   unsigned int A10M:1;
   unsigned int IPMIEN:1;
   unsigned int SCLREL:1;
   unsigned int I2CSIDL:1;
   unsigned int :1;
   unsigned int I2CEN:1;
} I2C3CONBITS;
I2C3CONBITS I2C3CONbits;
#word I2C3CONbits = 0x276
#word I2C3CON = 0x276

typedef struct 
 {
   union {
      struct {
         unsigned int TBF:1;
         unsigned int RBF:1;
         unsigned int R:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D:1;
         unsigned int I2COV:1;
         unsigned int IWCOL:1;
         unsigned int ADD10:1;
         unsigned int GCSTAT:1;
         unsigned int BCL:1;
         unsigned int :3;
         unsigned int TRSTAT:1;
         unsigned int ACKSTAT:1;
      };

      struct {
         unsigned int :2;
         unsigned int R_W:1;
         unsigned int :2;
         unsigned int D_A:1;
      };
   };
} I2C3STATBITS;
I2C3STATBITS I2C3STATbits;
#word I2C3STATbits = 0x278
#word I2C3STAT = 0x278

#word I2C3ADD = 0x27A

#word I2C3MSK = 0x27C

typedef union 
 {
      struct {
         unsigned int SPIRBF:1;
         unsigned int SPITBF:1;
         unsigned int SISEL0:3;
         unsigned int SRXMPT:1;
         unsigned int SPIROV:1;
         unsigned int SRMPT:1;
         unsigned int SPIBEC0:3;
         unsigned int :2;
         unsigned int SPISIDL:1;
         unsigned int :1;
         unsigned int SPIEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SISEL:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SPIBEC:3;
         unsigned int :2;
      };
} SPI3STATBITS;
SPI3STATBITS SPI3STATbits;
#word SPI3STATbits = 0x280
#word SPI3STAT = 0x280

typedef union 
 {
      struct {
         unsigned int PPRE0:2;
         unsigned int SPRE0:3;
         unsigned int MSTEN:1;
         unsigned int CKP:1;
         unsigned int SSEN:1;
         unsigned int CKE:1;
         unsigned int SMP:1;
         unsigned int MODE16:1;
         unsigned int DISSDO:1;
         unsigned int DISSCK:1;
      };
      struct {
         unsigned int PPRE:2;
         unsigned int SPRE:3;
      };
} SPI3CON1BITS;
SPI3CON1BITS SPI3CON1bits;
#word SPI3CON1bits = 0x282
#word SPI3CON1 = 0x282

typedef struct 
 {
   unsigned int SPIBEN:1;
   unsigned int SPIFE:1;
   unsigned int :11;
   unsigned int SPIFPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI3CON2BITS;
SPI3CON2BITS SPI3CON2bits;
#word SPI3CON2bits = 0x284
#word SPI3CON2 = 0x284

#word SPI3BUF = 0x288

typedef union 
 {
      struct {
         unsigned int STSEL:1;
         unsigned int PDSEL0:2;
         unsigned int BRGH:1;
         unsigned int RXINV:1;
         unsigned int ABAUD:1;
         unsigned int LPBACK:1;
         unsigned int WAKE:1;
         unsigned int UEN0:2;
         unsigned int :1;
         unsigned int RTSMD:1;
         unsigned int IREN:1;
         unsigned int USIDL:1;
         unsigned int :1;
         unsigned int UARTEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int PDSEL:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int UEN:2;
      };
} U4MODEBITS;
U4MODEBITS U4MODEbits;
#word U4MODEbits = 0x2B0
#word U4MODE = 0x2B0

typedef union 
 {
      struct {
         unsigned int URXDA:1;
         unsigned int OERR:1;
         unsigned int FERR:1;
         unsigned int PERR:1;
         unsigned int RIDLE:1;
         unsigned int ADDEN:1;
         unsigned int URXISEL0:2;
         unsigned int TRMT:1;
         unsigned int UTXBF:1;
         unsigned int UTXEN:1;
         unsigned int UTXBRK:1;
         unsigned int :1;
         unsigned int UTXISEL0:1;
         unsigned int UTXINV:1;
         unsigned int UTXISEL1:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int URXISEL:2;
      };
} U4STABITS;
U4STABITS U4STAbits;
#word U4STAbits = 0x2B2
#word U4STA = 0x2B2

typedef union 
 {
      struct {
         unsigned int UTXREG0:9;
      };
      struct {
         unsigned int UTXREG:9;
      };
} U4TXREGBITS;
U4TXREGBITS U4TXREGbits;
#word U4TXREGbits = 0x2B4
#word U4TXREG = 0x2B4

typedef union 
 {
      struct {
         unsigned int URXREG0:9;
      };
      struct {
         unsigned int URXREG:9;
      };
} U4RXREGBITS;
U4RXREGBITS U4RXREGbits;
#word U4RXREGbits = 0x2B6
#word U4RXREG = 0x2B6

#word U4BRG = 0x2B8

typedef struct 
 {
   unsigned int TRISB0:1;
   unsigned int TRISB1:1;
   unsigned int TRISB2:1;
   unsigned int TRISB3:1;
   unsigned int TRISB4:1;
   unsigned int TRISB5:1;
   unsigned int TRISB6:1;
   unsigned int TRISB7:1;
   unsigned int TRISB8:1;
   unsigned int TRISB9:1;
   unsigned int TRISB10:1;
   unsigned int TRISB11:1;
   unsigned int TRISB12:1;
   unsigned int TRISB13:1;
   unsigned int TRISB14:1;
   unsigned int TRISB15:1;
} TRISBBITS;
TRISBBITS TRISBbits;
#word TRISBbits = 0x2C8
#word TRISB = 0x2C8

typedef struct 
 {
   unsigned int RB0:1;
   unsigned int RB1:1;
   unsigned int RB2:1;
   unsigned int RB3:1;
   unsigned int RB4:1;
   unsigned int RB5:1;
   unsigned int RB6:1;
   unsigned int RB7:1;
   unsigned int RB8:1;
   unsigned int RB9:1;
   unsigned int RB10:1;
   unsigned int RB11:1;
   unsigned int RB12:1;
   unsigned int RB13:1;
   unsigned int RB14:1;
   unsigned int RB15:1;
} PORTBBITS;
PORTBBITS PORTBbits;
#word PORTBbits = 0x2CA
#word PORTB = 0x2CA

typedef struct 
 {
   unsigned int LATB0:1;
   unsigned int LATB1:1;
   unsigned int LATB2:1;
   unsigned int LATB3:1;
   unsigned int LATB4:1;
   unsigned int LATB5:1;
   unsigned int LATB6:1;
   unsigned int LATB7:1;
   unsigned int LATB8:1;
   unsigned int LATB9:1;
   unsigned int LATB10:1;
   unsigned int LATB11:1;
   unsigned int LATB12:1;
   unsigned int LATB13:1;
   unsigned int LATB14:1;
   unsigned int LATB15:1;
} LATBBITS;
LATBBITS LATBbits;
#word LATBbits = 0x2CC
#word LATB = 0x2CC

typedef union 
 {
      struct {
         unsigned int ODB0:16;
      };
      struct {
         unsigned int ODB:16;
      };
} ODCBBITS;
ODCBBITS ODCBbits;
#word ODCBbits = 0x2CE
#word ODCB = 0x2CE

typedef struct 
 {
   unsigned int TRISC0:1;
   unsigned int TRISC1:1;
   unsigned int TRISC2:1;
   unsigned int TRISC3:1;
   unsigned int TRISC4:1;
   unsigned int TRISC5:1;
   unsigned int TRISC6:1;
   unsigned int TRISC7:1;
   unsigned int TRISC8:1;
   unsigned int TRISC9:1;
   unsigned int TRISC10:1;
   unsigned int TRISC11:1;
   unsigned int TRISC12:1;
   unsigned int TRISC13:1;
   unsigned int TRISC14:1;
   unsigned int TRISC15:1;
} TRISCBITS;
TRISCBITS TRISCbits;
#word TRISCbits = 0x2D0
#word TRISC = 0x2D0

typedef struct 
 {
   unsigned int RC0:1;
   unsigned int RC1:1;
   unsigned int RC2:1;
   unsigned int RC3:1;
   unsigned int RC4:1;
   unsigned int RC5:1;
   unsigned int RC6:1;
   unsigned int RC7:1;
   unsigned int RC8:1;
   unsigned int RC9:1;
   unsigned int RC10:1;
   unsigned int RC11:1;
   unsigned int RC12:1;
   unsigned int RC13:1;
   unsigned int RC14:1;
   unsigned int RC15:1;
} PORTCBITS;
PORTCBITS PORTCbits;
#word PORTCbits = 0x2D2
#word PORTC = 0x2D2

typedef struct 
 {
   unsigned int LATC0:1;
   unsigned int LATC1:1;
   unsigned int LATC2:1;
   unsigned int LATC3:1;
   unsigned int LATC4:1;
   unsigned int LATC5:1;
   unsigned int LATC6:1;
   unsigned int LATC7:1;
   unsigned int LATC8:1;
   unsigned int LATC9:1;
   unsigned int LATC10:1;
   unsigned int LATC11:1;
   unsigned int LATC12:1;
   unsigned int LATC13:1;
   unsigned int LATC14:1;
   unsigned int LATC15:1;
} LATCBITS;
LATCBITS LATCbits;
#word LATCbits = 0x2D4
#word LATC = 0x2D4

typedef struct 
 {
   unsigned int :12;
   unsigned int ODC12:4;
} ODCCBITS;
ODCCBITS ODCCbits;
#word ODCCbits = 0x2D6
#word ODCC = 0x2D6

typedef struct 
 {
   unsigned int TRISD0:1;
   unsigned int TRISD1:1;
   unsigned int TRISD2:1;
   unsigned int TRISD3:1;
   unsigned int TRISD4:1;
   unsigned int TRISD5:1;
   unsigned int TRISD6:1;
   unsigned int TRISD7:1;
   unsigned int TRISD8:1;
   unsigned int TRISD9:1;
   unsigned int TRISD10:1;
   unsigned int TRISD11:1;
   unsigned int TRISD12:1;
   unsigned int TRISD13:1;
   unsigned int TRISD14:1;
   unsigned int TRISD15:1;
} TRISDBITS;
TRISDBITS TRISDbits;
#word TRISDbits = 0x2D8
#word TRISD = 0x2D8

typedef struct 
 {
   unsigned int RD0:1;
   unsigned int RD1:1;
   unsigned int RD2:1;
   unsigned int RD3:1;
   unsigned int RD4:1;
   unsigned int RD5:1;
   unsigned int RD6:1;
   unsigned int RD7:1;
   unsigned int RD8:1;
   unsigned int RD9:1;
   unsigned int RD10:1;
   unsigned int RD11:1;
   unsigned int RD12:1;
   unsigned int RD13:1;
   unsigned int RD14:1;
   unsigned int RD15:1;
} PORTDBITS;
PORTDBITS PORTDbits;
#word PORTDbits = 0x2DA
#word PORTD = 0x2DA

typedef struct 
 {
   unsigned int LATD0:1;
   unsigned int LATD1:1;
   unsigned int LATD2:1;
   unsigned int LATD3:1;
   unsigned int LATD4:1;
   unsigned int LATD5:1;
   unsigned int LATD6:1;
   unsigned int LATD7:1;
   unsigned int LATD8:1;
   unsigned int LATD9:1;
   unsigned int LATD10:1;
   unsigned int LATD11:1;
   unsigned int LATD12:1;
   unsigned int LATD13:1;
   unsigned int LATD14:1;
   unsigned int LATD15:1;
} LATDBITS;
LATDBITS LATDbits;
#word LATDbits = 0x2DC
#word LATD = 0x2DC

typedef union 
 {
      struct {
         unsigned int ODD0:12;
      };
      struct {
         unsigned int ODD:12;
      };
} ODCDBITS;
ODCDBITS ODCDbits;
#word ODCDbits = 0x2DE
#word ODCD = 0x2DE

typedef struct 
 {
   unsigned int TRISE0:1;
   unsigned int TRISE1:1;
   unsigned int TRISE2:1;
   unsigned int TRISE3:1;
   unsigned int TRISE4:1;
   unsigned int TRISE5:1;
   unsigned int TRISE6:1;
   unsigned int TRISE7:1;
   unsigned int TRISE8:1;
   unsigned int TRISE9:1;
   unsigned int TRISE10:1;
   unsigned int TRISE11:1;
   unsigned int TRISE12:1;
   unsigned int TRISE13:1;
   unsigned int TRISE14:1;
   unsigned int TRISE15:1;
} TRISEBITS;
TRISEBITS TRISEbits;
#word TRISEbits = 0x2E0
#word TRISE = 0x2E0

typedef struct 
 {
   unsigned int RE0:1;
   unsigned int RE1:1;
   unsigned int RE2:1;
   unsigned int RE3:1;
   unsigned int RE4:1;
   unsigned int RE5:1;
   unsigned int RE6:1;
   unsigned int RE7:1;
   unsigned int RE8:1;
   unsigned int RE9:1;
   unsigned int RE10:1;
   unsigned int RE11:1;
   unsigned int RE12:1;
   unsigned int RE13:1;
   unsigned int RE14:1;
   unsigned int RE15:1;
} PORTEBITS;
PORTEBITS PORTEbits;
#word PORTEbits = 0x2E2
#word PORTE = 0x2E2

typedef struct 
 {
   unsigned int LATE0:1;
   unsigned int LATE1:1;
   unsigned int LATE2:1;
   unsigned int LATE3:1;
   unsigned int LATE4:1;
   unsigned int LATE5:1;
   unsigned int LATE6:1;
   unsigned int LATE7:1;
   unsigned int LATE8:1;
   unsigned int LATE9:1;
   unsigned int LATE10:1;
   unsigned int LATE11:1;
   unsigned int LATE12:1;
   unsigned int LATE13:1;
   unsigned int LATE14:1;
   unsigned int LATE15:1;
} LATEBITS;
LATEBITS LATEbits;
#word LATEbits = 0x2E4
#word LATE = 0x2E4

typedef union 
 {
      struct {
         unsigned int ODE0:8;
      };
      struct {
         unsigned int ODE:8;
      };
} ODCEBITS;
ODCEBITS ODCEbits;
#word ODCEbits = 0x2E6
#word ODCE = 0x2E6

typedef struct 
 {
   unsigned int TRISF0:1;
   unsigned int TRISF1:1;
   unsigned int TRISF2:1;
   unsigned int TRISF3:1;
   unsigned int TRISF4:1;
   unsigned int TRISF5:1;
   unsigned int TRISF6:1;
   unsigned int TRISF7:1;
   unsigned int TRISF8:1;
   unsigned int TRISF9:1;
   unsigned int TRISF10:1;
   unsigned int TRISF11:1;
   unsigned int TRISF12:1;
   unsigned int TRISF13:1;
   unsigned int TRISF14:1;
   unsigned int TRISF15:1;
} TRISFBITS;
TRISFBITS TRISFbits;
#word TRISFbits = 0x2E8
#word TRISF = 0x2E8

typedef struct 
 {
   unsigned int RF0:1;
   unsigned int RF1:1;
   unsigned int RF2:1;
   unsigned int RF3:1;
   unsigned int RF4:1;
   unsigned int RF5:1;
   unsigned int RF6:1;
   unsigned int RF7:1;
   unsigned int RF8:1;
   unsigned int RF9:1;
   unsigned int RF10:1;
   unsigned int RF11:1;
   unsigned int RF12:1;
   unsigned int RF13:1;
   unsigned int RF14:1;
   unsigned int RF15:1;
} PORTFBITS;
PORTFBITS PORTFbits;
#word PORTFbits = 0x2EA
#word PORTF = 0x2EA

typedef struct 
 {
   unsigned int LATF0:1;
   unsigned int LATF1:1;
   unsigned int LATF2:1;
   unsigned int LATF3:1;
   unsigned int LATF4:1;
   unsigned int LATF5:1;
   unsigned int LATF6:1;
   unsigned int LATF7:1;
   unsigned int LATF8:1;
   unsigned int LATF9:1;
   unsigned int LATF10:1;
   unsigned int LATF11:1;
   unsigned int LATF12:1;
   unsigned int LATF13:1;
   unsigned int LATF14:1;
   unsigned int LATF15:1;
} LATFBITS;
LATFBITS LATFbits;
#word LATFbits = 0x2EC
#word LATF = 0x2EC

typedef union 
 {
      struct {
         unsigned int ODF0:2;
         unsigned int :1;
         unsigned int ODF3:3;
         unsigned int :1;
         unsigned int ODF7:1;
      };
      struct {
         unsigned int ODF00:2;
         unsigned int :1;
         unsigned int ODF03:3;
      };
} ODCFBITS;
ODCFBITS ODCFbits;
#word ODCFbits = 0x2EE
#word ODCF = 0x2EE

typedef struct 
 {
   unsigned int TRISG0:1;
   unsigned int TRISG1:1;
   unsigned int TRISG2:1;
   unsigned int TRISG3:1;
   unsigned int TRISG4:1;
   unsigned int TRISG5:1;
   unsigned int TRISG6:1;
   unsigned int TRISG7:1;
   unsigned int TRISG8:1;
   unsigned int TRISG9:1;
   unsigned int TRISG10:1;
   unsigned int TRISG11:1;
   unsigned int TRISG12:1;
   unsigned int TRISG13:1;
   unsigned int TRISG14:1;
   unsigned int TRISG15:1;
} TRISGBITS;
TRISGBITS TRISGbits;
#word TRISGbits = 0x2F0
#word TRISG = 0x2F0

typedef struct 
 {
   unsigned int RG0:1;
   unsigned int RG1:1;
   unsigned int RG2:1;
   unsigned int RG3:1;
   unsigned int RG4:1;
   unsigned int RG5:1;
   unsigned int RG6:1;
   unsigned int RG7:1;
   unsigned int RG8:1;
   unsigned int RG9:1;
   unsigned int RG10:1;
   unsigned int RG11:1;
   unsigned int RG12:1;
   unsigned int RG13:1;
   unsigned int RG14:1;
   unsigned int RG15:1;
} PORTGBITS;
PORTGBITS PORTGbits;
#word PORTGbits = 0x2F2
#word PORTG = 0x2F2

typedef struct 
 {
   unsigned int LATG0:1;
   unsigned int LATG1:1;
   unsigned int LATG2:1;
   unsigned int LATG3:1;
   unsigned int LATG4:1;
   unsigned int LATG5:1;
   unsigned int LATG6:1;
   unsigned int LATG7:1;
   unsigned int LATG8:1;
   unsigned int LATG9:1;
   unsigned int LATG10:1;
   unsigned int LATG11:1;
   unsigned int LATG12:1;
   unsigned int LATG13:1;
   unsigned int LATG14:1;
   unsigned int LATG15:1;
} LATGBITS;
LATGBITS LATGbits;
#word LATGbits = 0x2F4
#word LATG = 0x2F4

typedef struct 
 {
   unsigned int :2;
   unsigned int ODG2:2;
   unsigned int :2;
   unsigned int ODG6:4;
} ODCGBITS;
ODCGBITS ODCGbits;
#word ODCGbits = 0x2F6
#word ODCG = 0x2F6

typedef struct 
 {
   union {
      struct {
         unsigned int PMPTTL:1;
         unsigned int RTSECSEL:1;
      };

      struct {
         unsigned int :1;
         unsigned int RTSECSEL0:1;
      };
   };
} PADCFG1BITS;
PADCFG1BITS PADCFG1bits;
#word PADCFG1bits = 0x2FC
#word PADCFG1 = 0x2FC

#word ADC1BUF0 = 0x300

#word ADC1BUF1 = 0x302

#word ADC1BUF2 = 0x304

#word ADC1BUF3 = 0x306

#word ADC1BUF4 = 0x308

#word ADC1BUF5 = 0x30A

#word ADC1BUF6 = 0x30C

#word ADC1BUF7 = 0x30E

#word ADC1BUF8 = 0x310

#word ADC1BUF9 = 0x312

#word ADC1BUFA = 0x314

#word ADC1BUFB = 0x316

#word ADC1BUFC = 0x318

#word ADC1BUFD = 0x31A

#word ADC1BUFE = 0x31C

#word ADC1BUFF = 0x31E

typedef union 
 {
      struct {
         unsigned int DONE:1;
         unsigned int SAMP:1;
         unsigned int ASAM:1;
         unsigned int :2;
         unsigned int SSRC0:3;
         unsigned int FORM0:2;
         unsigned int :3;
         unsigned int ADSIDL:1;
         unsigned int :1;
         unsigned int ADON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :2;
         unsigned int SSRC:3;
         unsigned int FORM:2;
         unsigned int :3;
      };
} AD1CON1BITS;
AD1CON1BITS AD1CON1bits;
#word AD1CON1bits = 0x320
#word AD1CON1 = 0x320

typedef union 
 {
      struct {
         unsigned int ALTS:1;
         unsigned int BUFM:1;
         unsigned int SMPI0:5;
         unsigned int BUFS:1;
         unsigned int :2;
         unsigned int CSCNA:1;
         unsigned int :2;
         unsigned int VCFG0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SMPI:5;
         unsigned int :1;
         unsigned int :2;
         unsigned int :1;
         unsigned int :2;
         unsigned int VCFG:3;
      };
} AD1CON2BITS;
AD1CON2BITS AD1CON2bits;
#word AD1CON2bits = 0x322
#word AD1CON2 = 0x322

typedef union 
 {
      struct {
         unsigned int ADCS0:8;
         unsigned int SAMC0:5;
         unsigned int :2;
         unsigned int ADRC:1;
      };
      struct {
         unsigned int ADCS:8;
         unsigned int SAMC:5;
         unsigned int :2;
      };
} AD1CON3BITS;
AD1CON3BITS AD1CON3bits;
#word AD1CON3bits = 0x324
#word AD1CON3 = 0x324

typedef union 
 {
      struct {
         unsigned int CH0SA0:5;
         unsigned int :2;
         unsigned int CH0NA:1;
         unsigned int CH0SB0:5;
         unsigned int :2;
         unsigned int CH0NB:1;
      };
      struct {
         unsigned int CH0SA:5;
         unsigned int :2;
         unsigned int :1;
         unsigned int CH0SB:5;
         unsigned int :2;
      };
} AD1CHSBITS;
AD1CHSBITS AD1CHSbits;
#word AD1CHSbits = 0x328
#word AD1CHS = 0x328

typedef struct 
 {
   unsigned int :8;
   unsigned int CSSL24:4;
} AD1CSSHBITS;
AD1CSSHBITS AD1CSSHbits;
#word AD1CSSHbits = 0x32E
#word AD1CSSH = 0x32E

typedef union 
 {
      struct {
         unsigned int CSSL0:16;
      };
      struct {
         unsigned int CSSL:16;
      };
} AD1CSSLBITS;
AD1CSSLBITS AD1CSSLbits;
#word AD1CSSLbits = 0x330
#word AD1CSSL = 0x330

typedef union 
 {
      struct {
         unsigned int EDG1STAT:1;
         unsigned int EDG2STAT:1;
         unsigned int EDG1SEL0:2;
         unsigned int EDG1POL:1;
         unsigned int EDG2SEL0:2;
         unsigned int EDG2POL:1;
         unsigned int CTTRIG:1;
         unsigned int IDISSEN:1;
         unsigned int EDGSEQEN:1;
         unsigned int EDGEN:1;
         unsigned int TGEN:1;
         unsigned int CTMUSIDL:1;
         unsigned int :1;
         unsigned int CTMUEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int EDG1SEL:2;
         unsigned int :1;
         unsigned int EDG2SEL:2;
      };
} CTMUCONBITS;
CTMUCONBITS CTMUCONbits;
#word CTMUCONbits = 0x33C
#word CTMUCON = 0x33C

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int IRNG0:2;
         unsigned int ITRIM0:6;
      };
      struct {
         unsigned int :8;
         unsigned int IRNG:2;
         unsigned int ITRIM:6;
      };
} CTMUICONBITS;
CTMUICONBITS CTMUICONbits;
#word CTMUICONbits = 0x33E
#word CTMUICON = 0x33E

#word ADC1BUF10 = 0x340

#word ADC1BUF11 = 0x342

#word ADC1BUF12 = 0x344

#word ADC1BUF13 = 0x346

#word ADC1BUF14 = 0x348

#word ADC1BUF15 = 0x34A

#word ADC1BUF16 = 0x34C

#word ADC1BUF17 = 0x34E

#word ADC1BUF18 = 0x350

#word ADC1BUF19 = 0x352

#word ADC1BUF1A = 0x354

#word ADC1BUF1B = 0x356

#word ADC1BUF1C = 0x358

#word ADC1BUF1D = 0x35A

#word ADC1BUF1E = 0x35C

#word ADC1BUF1F = 0x35E

typedef struct 
 {
   unsigned int VBUSVDIF:1;
   unsigned int :1;
   unsigned int SESENDIF:1;
   unsigned int SESVDIF:1;
   unsigned int ACTVIF:1;
   unsigned int LSTATEIF:1;
   unsigned int T1MSECIF:1;
   unsigned int IDIF:1;
} U1OTGIRBITS;
U1OTGIRBITS U1OTGIRbits;
#word U1OTGIRbits = 0x480
#word U1OTGIR = 0x480

typedef struct 
 {
   unsigned int VBUSVDIE:1;
   unsigned int :1;
   unsigned int SESENDIE:1;
   unsigned int SESVDIE:1;
   unsigned int ACTVIE:1;
   unsigned int LSTATEIE:1;
   unsigned int T1MSECIE:1;
   unsigned int IDIE:1;
} U1OTGIEBITS;
U1OTGIEBITS U1OTGIEbits;
#word U1OTGIEbits = 0x482
#word U1OTGIE = 0x482

typedef struct 
 {
   unsigned int VBUSVD:1;
   unsigned int :1;
   unsigned int SESEND:1;
   unsigned int SESVD:1;
   unsigned int :1;
   unsigned int LSTATE:1;
   unsigned int :1;
   unsigned int ID:1;
} U1OTGSTATBITS;
U1OTGSTATBITS U1OTGSTATbits;
#word U1OTGSTATbits = 0x484
#word U1OTGSTAT = 0x484

typedef struct 
 {
   unsigned int VBUSDIS:1;
   unsigned int VBUSCHG:1;
   unsigned int OTGEN:1;
   unsigned int VBUSON:1;
   unsigned int DMPULDWN:1;
   unsigned int DPPULDWN:1;
   unsigned int DMPULUP:1;
   unsigned int DPPULUP:1;
} U1OTGCONBITS;
U1OTGCONBITS U1OTGCONbits;
#word U1OTGCONbits = 0x486
#word U1OTGCON = 0x486

typedef struct 
 {
   union {
      struct {
         unsigned int USBPWR:1;
         unsigned int USUSPND:1;
         unsigned int :2;
         unsigned int USLPGRD:1;
         unsigned int :2;
         unsigned int UACTPND:1;
      };

      struct {
         unsigned int :1;
         unsigned int USUSPEND:1;
      };
   };
} U1PWRCBITS;
U1PWRCBITS U1PWRCbits;
#word U1PWRCbits = 0x488
#word U1PWRC = 0x488

typedef struct 
 {
   union {
      struct {
         unsigned int URSTIF:1;
         unsigned int UERRIF:1;
         unsigned int SOFIF:1;
         unsigned int TRNIF:1;
         unsigned int IDLEIF:1;
         unsigned int RESUMEIF:1;
         unsigned int ATTACHIF:1;
         unsigned int STALLIF:1;
      };

      struct {
         unsigned int DETACHIF:1;
      };
   };
} U1IRBITS;
U1IRBITS U1IRbits;
#word U1IRbits = 0x48A
#word U1IR = 0x48A

typedef struct 
 {
   union {
      struct {
         unsigned int URSTIE:1;
         unsigned int UERRIE:1;
         unsigned int SOFIE:1;
         unsigned int TRNIE:1;
         unsigned int IDLEIE:1;
         unsigned int RESUMEIE:1;
         unsigned int ATTACHIE:1;
         unsigned int STALLIE:1;
      };

      struct {
         unsigned int DETACHIE:1;
      };
   };
} U1IEBITS;
U1IEBITS U1IEbits;
#word U1IEbits = 0x48C
#word U1IE = 0x48C

typedef struct 
 {
   union {
      struct {
         unsigned int PIDEF:1;
         unsigned int CRC5EF:1;
         unsigned int CRC16EF:1;
         unsigned int DFN8EF:1;
         unsigned int BTOEF:1;
         unsigned int DMAEF:1;
         unsigned int :1;
         unsigned int BTSEF:1;
      };

      struct {
         unsigned int :1;
         unsigned int EOFEF:1;
      };
   };
} U1EIRBITS;
U1EIRBITS U1EIRbits;
#word U1EIRbits = 0x48E
#word U1EIR = 0x48E

typedef struct 
 {
   union {
      struct {
         unsigned int PIDEE:1;
         unsigned int CRC5EE:1;
         unsigned int CRC16EE:1;
         unsigned int DFN8EE:1;
         unsigned int BTOEE:1;
         unsigned int DMAEE:1;
         unsigned int :1;
         unsigned int BTSEE:1;
      };

      struct {
         unsigned int :1;
         unsigned int EOFEE:1;
      };
   };
} U1EIEBITS;
U1EIEBITS U1EIEbits;
#word U1EIEbits = 0x490
#word U1EIE = 0x490

typedef union 
 {
      struct {
         unsigned int :2;
         unsigned int PPBI:1;
         unsigned int DIR:1;
         unsigned int ENDPT0:4;
      };
      struct {
         unsigned int :2;
         unsigned int :1;
         unsigned int :1;
         unsigned int ENDPT:4;
      };
} U1STATBITS;
U1STATBITS U1STATbits;
#word U1STATbits = 0x492
#word U1STAT = 0x492

typedef struct 
 {
   union {
      struct {
         unsigned int USBEN:1;
         unsigned int PPBRST:1;
         unsigned int RESUME:1;
         unsigned int HOSTEN:1;
         unsigned int USBRST:1;
         unsigned int PKTDIS:1;
         unsigned int SE0:1;
         unsigned int JSTATE:1;
      };

      struct {
         unsigned int SOFEN:1;
         unsigned int :3;
         unsigned int RESET:1;
         unsigned int TOKBUSY:1;
      };
   };
} U1CONBITS;
U1CONBITS U1CONbits;
#word U1CONbits = 0x494
#word U1CON = 0x494

typedef union 
 {
   union {
      struct {
         unsigned int DEVADDR0:7;
         unsigned int LOWSPDEN:1;
      };
      struct {
         unsigned int DEVADDR:7;
      };

      struct {
         unsigned int :7;
         unsigned int LSPDEN:1;
      };
   };
} U1ADDRBITS;
U1ADDRBITS U1ADDRbits;
#word U1ADDRbits = 0x496
#word U1ADDR = 0x496

typedef union 
 {
      struct {
         unsigned int :1;
         unsigned int BDTPTRL0:7;
      };
      struct {
         unsigned int :1;
         unsigned int BDTPTRL:7;
      };
} U1BDTP1BITS;
U1BDTP1BITS U1BDTP1bits;
#word U1BDTP1bits = 0x498
#word U1BDTP1 = 0x498

typedef union 
 {
      struct {
         unsigned int FRM0:8;
      };
      struct {
         unsigned int FRM:8;
      };
} U1FRMLBITS;
U1FRMLBITS U1FRMLbits;
#word U1FRMLbits = 0x49A
#word U1FRML = 0x49A

typedef struct 
 {
   unsigned int FRM8:3;
} U1FRMHBITS;
U1FRMHBITS U1FRMHbits;
#word U1FRMHbits = 0x49C
#word U1FRMH = 0x49C

typedef union 
 {
      struct {
         unsigned int EP0:4;
         unsigned int PID0:4;
      };
      struct {
         unsigned int EP:4;
         unsigned int PID:4;
      };
} U1TOKBITS;
U1TOKBITS U1TOKbits;
#word U1TOKbits = 0x49E
#word U1TOK = 0x49E

#word U1SOF = 0x4A0

typedef union 
 {
      struct {
         unsigned int CNT0:8;
      };
      struct {
         unsigned int CNT:8;
      };
} U1SOFBITS;
U1SOFBITS U1SOFbits;
#word U1SOFbits = 0x4A0
#word U1SOF = 0x4A0

typedef union 
 {
      struct {
         unsigned int PPB0:2;
         unsigned int :2;
         unsigned int USBSIDL:1;
         unsigned int :1;
         unsigned int UOEMON:1;
         unsigned int UTEYE:1;
      };
      struct {
         unsigned int PPB:2;
         unsigned int :2;
      };
} U1CNFG1BITS;
U1CNFG1BITS U1CNFG1bits;
#word U1CNFG1bits = 0x4A6
#word U1CNFG1 = 0x4A6

typedef struct 
 {
   unsigned int UTRDIS:1;
   unsigned int UVCMPDIS:1;
   unsigned int UVBUSDIS:1;
   unsigned int EXTI2CEN:1;
   unsigned int PUVBUS:1;
   unsigned int UVCMPSEL:1;
} U1CNFG2BITS;
U1CNFG2BITS U1CNFG2bits;
#word U1CNFG2bits = 0x4A8
#word U1CNFG2 = 0x4A8

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
         unsigned int :1;
         unsigned int RETRYDIS:1;
         unsigned int LSPD:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
         unsigned int :3;
         unsigned int LOWSPD:1;
      };
   };
} U1EP0BITS;
U1EP0BITS U1EP0bits;
#word U1EP0bits = 0x4AA
#word U1EP0 = 0x4AA

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP1BITS;
U1EP1BITS U1EP1bits;
#word U1EP1bits = 0x4AC
#word U1EP1 = 0x4AC

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP2BITS;
U1EP2BITS U1EP2bits;
#word U1EP2bits = 0x4AE
#word U1EP2 = 0x4AE

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP3BITS;
U1EP3BITS U1EP3bits;
#word U1EP3bits = 0x4B0
#word U1EP3 = 0x4B0

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP4BITS;
U1EP4BITS U1EP4bits;
#word U1EP4bits = 0x4B2
#word U1EP4 = 0x4B2

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP5BITS;
U1EP5BITS U1EP5bits;
#word U1EP5bits = 0x4B4
#word U1EP5 = 0x4B4

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP6BITS;
U1EP6BITS U1EP6bits;
#word U1EP6bits = 0x4B6
#word U1EP6 = 0x4B6

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP7BITS;
U1EP7BITS U1EP7bits;
#word U1EP7bits = 0x4B8
#word U1EP7 = 0x4B8

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP8BITS;
U1EP8BITS U1EP8bits;
#word U1EP8bits = 0x4BA
#word U1EP8 = 0x4BA

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP9BITS;
U1EP9BITS U1EP9bits;
#word U1EP9bits = 0x4BC
#word U1EP9 = 0x4BC

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP10BITS;
U1EP10BITS U1EP10bits;
#word U1EP10bits = 0x4BE
#word U1EP10 = 0x4BE

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP11BITS;
U1EP11BITS U1EP11bits;
#word U1EP11bits = 0x4C0
#word U1EP11 = 0x4C0

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP12BITS;
U1EP12BITS U1EP12bits;
#word U1EP12bits = 0x4C2
#word U1EP12 = 0x4C2

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP13BITS;
U1EP13BITS U1EP13bits;
#word U1EP13bits = 0x4C4
#word U1EP13 = 0x4C4

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP14BITS;
U1EP14BITS U1EP14bits;
#word U1EP14bits = 0x4C6
#word U1EP14 = 0x4C6

typedef struct 
 {
   union {
      struct {
         unsigned int EPHSHK:1;
         unsigned int EPSTALL:1;
         unsigned int EPTXEN:1;
         unsigned int EPRXEN:1;
         unsigned int EPCONDIS:1;
      };

      struct {
         unsigned int :2;
         unsigned int EPINEN:1;
         unsigned int EPOUTEN:1;
      };
   };
} U1EP15BITS;
U1EP15BITS U1EP15bits;
#word U1EP15bits = 0x4C8
#word U1EP15 = 0x4C8

typedef union 
 {
   union {
      struct {
         unsigned int PER0:8;
         unsigned int DC0:8;
      };
      struct {
         unsigned int PER:8;
         unsigned int DC:8;
      };

      struct {
         unsigned int USBRS0:8;
         unsigned int USBR0:8;
      };
   };
      struct {
         unsigned int USBRS:8;
         unsigned int USBR:8;
      };
} U1PWMRRSBITS;
U1PWMRRSBITS U1PWMRRSbits;
#word U1PWMRRSbits = 0x4CC
#word U1PWMRRS = 0x4CC

typedef struct 
 {
   unsigned int :8;
   unsigned int CNTEN:1;
   unsigned int PWMPOL:1;
   unsigned int :5;
   unsigned int PWMEN:1;
} U1PWMCONBITS;
U1PWMCONBITS U1PWMCONbits;
#word U1PWMCONbits = 0x4CE
#word U1PWMCON = 0x4CE

typedef struct 
 {
   unsigned int VBGEN:1;
   unsigned int VBG2EN:1;
   unsigned int VBG6EN:1;
} ANCFGBITS;
ANCFGBITS ANCFGbits;
#word ANCFGbits = 0x4DE
#word ANCFG = 0x4DE

typedef union 
 {
      struct {
         unsigned int ANSB0:16;
      };
      struct {
         unsigned int ANSB:16;
      };
} ANSBBITS;
ANSBBITS ANSBbits;
#word ANSBbits = 0x4E2
#word ANSB = 0x4E2

typedef struct 
 {
   unsigned int :13;
   unsigned int ANSC13:2;
} ANSCBITS;
ANSCBITS ANSCbits;
#word ANSCbits = 0x4E4
#word ANSC = 0x4E4

typedef struct 
 {
   unsigned int :6;
   unsigned int ANSD6:2;
} ANSDBITS;
ANSDBITS ANSDbits;
#word ANSDbits = 0x4E6
#word ANSD = 0x4E6

typedef struct 
 {
   unsigned int ANSF0:1;
} ANSFBITS;
ANSFBITS ANSFbits;
#word ANSFbits = 0x4EA
#word ANSF = 0x4EA

typedef struct 
 {
   unsigned int :6;
   unsigned int ANSG6:4;
} ANSGBITS;
ANSGBITS ANSGbits;
#word ANSGbits = 0x4EC
#word ANSG = 0x4EC

typedef union 
 {
      struct {
         unsigned int IRQM0:2;
         unsigned int BUSKEEP:1;
         unsigned int :1;
         unsigned int ALMODE:1;
         unsigned int ALP:1;
         unsigned int CSF0:2;
         unsigned int MODE0:2;
         unsigned int :1;
         unsigned int ADRMUX0:2;
         unsigned int PSIDL:1;
         unsigned int :1;
         unsigned int PMPEN:1;
      };
      struct {
         unsigned int IRQM:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int CSF:2;
         unsigned int MODE:2;
         unsigned int :1;
         unsigned int ADRMUX:2;
      };
} PMCON1BITS;
PMCON1BITS PMCON1bits;
#word PMCON1bits = 0x600
#word PMCON1 = 0x600

typedef union 
 {
   union {
      struct {
         unsigned int RADDR0:8;
         unsigned int :4;
         unsigned int TIMEOUT:1;
         unsigned int ERROR:1;
         unsigned int :1;
         unsigned int BUSY:1;
      };
      struct {
         unsigned int RADDR:8;
         unsigned int :4;
      };

      struct {
         unsigned int RADDR16:4;
         unsigned int RADDR20:4;
      };
   };
} PMCON2BITS;
PMCON2BITS PMCON2bits;
#word PMCON2bits = 0x602
#word PMCON2 = 0x602

typedef union 
 {
      struct {
         unsigned int RES0:7;
         unsigned int :1;
         unsigned int AWAITE:1;
         unsigned int AWAITM0:2;
         unsigned int :1;
         unsigned int PTBE0EN:1;
         unsigned int PTBE1EN:1;
         unsigned int PTRDEN:1;
         unsigned int PTWREN:1;
      };
      struct {
         unsigned int RES:7;
         unsigned int :1;
         unsigned int :1;
         unsigned int AWAITM:2;
      };
} PMCON3BITS;
PMCON3BITS PMCON3bits;
#word PMCON3bits = 0x604
#word PMCON3 = 0x604

typedef union 
 {
      struct {
         unsigned int PTEN0:16;
      };
      struct {
         unsigned int PTEN:16;
      };
} PMCON4BITS;
PMCON4BITS PMCON4bits;
#word PMCON4bits = 0x606
#word PMCON4 = 0x606

typedef union 
 {
      struct {
         unsigned int :5;
         unsigned int PTSZ0:2;
         unsigned int ACKP:1;
         unsigned int SM:1;
         unsigned int RDSP:1;
         unsigned int WRSP:1;
         unsigned int :1;
         unsigned int BEP:1;
         unsigned int CSPTEN:1;
         unsigned int CSP:1;
         unsigned int CSDIS:1;
      };
      struct {
         unsigned int :5;
         unsigned int PTSZ:2;
      };
} PMCS1CFBITS;
PMCS1CFBITS PMCS1CFbits;
#word PMCS1CFbits = 0x608
#word PMCS1CF = 0x608

typedef struct 
 {
   unsigned int :3;
   unsigned int BASE11:1;
   unsigned int :3;
   unsigned int BASE15:5;
   unsigned int BASE20:4;
} PMCS1BSBITS;
PMCS1BSBITS PMCS1BSbits;
#word PMCS1BSbits = 0x60A
#word PMCS1BS = 0x60A

typedef union 
 {
      struct {
         unsigned int DWAITE0:2;
         unsigned int DWAITM0:4;
         unsigned int DWAITB0:2;
         unsigned int :6;
         unsigned int ACKM0:2;
      };
      struct {
         unsigned int DWAITE:2;
         unsigned int DWAITM:4;
         unsigned int DWAITB:2;
         unsigned int :6;
         unsigned int ACKM:2;
      };
} PMCS1MDBITS;
PMCS1MDBITS PMCS1MDbits;
#word PMCS1MDbits = 0x60C
#word PMCS1MD = 0x60C

typedef union 
 {
      struct {
         unsigned int :5;
         unsigned int PTSZ0:2;
         unsigned int ACKP:1;
         unsigned int SM:1;
         unsigned int RDSP:1;
         unsigned int WRSP:1;
         unsigned int :1;
         unsigned int BEP:1;
         unsigned int CSPTEN:1;
         unsigned int CSP:1;
         unsigned int CSDIS:1;
      };
      struct {
         unsigned int :5;
         unsigned int PTSZ:2;
      };
} PMCS2CFBITS;
PMCS2CFBITS PMCS2CFbits;
#word PMCS2CFbits = 0x60E
#word PMCS2CF = 0x60E

typedef struct 
 {
   unsigned int :3;
   unsigned int BASE11:1;
   unsigned int :3;
   unsigned int BASE15:5;
   unsigned int BASE20:4;
} PMCS2BSBITS;
PMCS2BSBITS PMCS2BSbits;
#word PMCS2BSbits = 0x610
#word PMCS2BS = 0x610

typedef union 
 {
      struct {
         unsigned int DWAITE0:2;
         unsigned int DWAITM0:4;
         unsigned int DWAITB0:2;
         unsigned int :6;
         unsigned int ACKM0:2;
      };
      struct {
         unsigned int DWAITE:2;
         unsigned int DWAITM:4;
         unsigned int DWAITB:2;
         unsigned int :6;
         unsigned int ACKM:2;
      };
} PMCS2MDBITS;
PMCS2MDBITS PMCS2MDbits;
#word PMCS2MDbits = 0x612
#word PMCS2MD = 0x612

#word PMDOUT1 = 0x614

#word PMDOUT2 = 0x616

#word PMDIN1 = 0x618

#word PMDIN2 = 0x61A

typedef struct 
 {
   unsigned int OB0E:1;
   unsigned int OB1E:1;
   unsigned int OB2E:1;
   unsigned int OB3E:1;
   unsigned int :2;
   unsigned int OBUF:1;
   unsigned int OBE:1;
   unsigned int IB0F:1;
   unsigned int IB1F:1;
   unsigned int IB2F:1;
   unsigned int IB3F:1;
   unsigned int :2;
   unsigned int IBOV:1;
   unsigned int IBF:1;
} PMSTATBITS;
PMSTATBITS PMSTATbits;
#word PMSTATbits = 0x61C
#word PMSTAT = 0x61C

#word ALRMVAL = 0x620

typedef union 
 {
      struct {
         unsigned int ARPT0:8;
         unsigned int ALRMPTR0:2;
         unsigned int AMASK0:4;
         unsigned int CHIME:1;
         unsigned int ALRMEN:1;
      };
      struct {
         unsigned int ARPT:8;
         unsigned int ALRMPTR:2;
         unsigned int AMASK:4;
      };
} ALCFGRPTBITS;
ALCFGRPTBITS ALCFGRPTbits;
#word ALCFGRPTbits = 0x622
#word ALCFGRPT = 0x622

#word RTCVAL = 0x624

typedef union 
 {
      struct {
         unsigned int CAL0:1;
         unsigned int CAL1:1;
         unsigned int CAL2:1;
         unsigned int CAL3:1;
         unsigned int CAL4:1;
         unsigned int CAL5:1;
         unsigned int CAL6:1;
         unsigned int CAL7:1;
         unsigned int RTCPTR0:1;
         unsigned int RTCPTR1:1;
         unsigned int RTCOE:1;
         unsigned int HALFSEC:1;
         unsigned int RTCSYNC:1;
         unsigned int RTCWREN:1;
         unsigned int :1;
         unsigned int RTCEN:1;
      };
      struct {
         unsigned int CAL:8;
         unsigned int RTCPTR:2;
      };
} RCFGCALBITS;
RCFGCALBITS RCFGCALbits;
#word RCFGCALbits = 0x626
#word RCFGCAL = 0x626

typedef struct 
 {
   unsigned int C1OUT:1;
   unsigned int C2OUT:1;
   unsigned int C3OUT:1;
   unsigned int :5;
   unsigned int C1EVT:1;
   unsigned int C2EVT:1;
   unsigned int C3EVT:1;
   unsigned int :4;
   unsigned int CMIDL:1;
} CMSTATBITS;
CMSTATBITS CMSTATbits;
#word CMSTATbits = 0x630
#word CMSTAT = 0x630

typedef union 
 {
      struct {
         unsigned int CVR0:4;
         unsigned int CVRSS:1;
         unsigned int CVRR:1;
         unsigned int CVROE:1;
         unsigned int CVREN:1;
         unsigned int CVREFM0:2;
         unsigned int CVREFP:1;
      };
      struct {
         unsigned int CVR:4;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int CVREFM:2;
      };
} CVRCONBITS;
CVRCONBITS CVRCONbits;
#word CVRCONbits = 0x632
#word CVRCON = 0x632

typedef union 
 {
   union {
      struct {
         unsigned int CCH0:2;
         unsigned int :2;
         unsigned int CREF:1;
         unsigned int :1;
         unsigned int EVPOL0:2;
         unsigned int COUT:1;
         unsigned int CEVT:1;
         unsigned int :3;
         unsigned int CPOL:1;
         unsigned int COE:1;
         unsigned int CON:1;
      };
      struct {
         unsigned int CCH:2;
         unsigned int :2;
         unsigned int :1;
         unsigned int :1;
         unsigned int EVPOL:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :3;
      };

      struct {
         unsigned int :15;
         unsigned int CEN:1;
      };
   };
} CM1CONBITS;
CM1CONBITS CM1CONbits;
#word CM1CONbits = 0x634
#word CM1CON = 0x634

typedef union 
 {
   union {
      struct {
         unsigned int CCH0:2;
         unsigned int :2;
         unsigned int CREF:1;
         unsigned int :1;
         unsigned int EVPOL0:2;
         unsigned int COUT:1;
         unsigned int CEVT:1;
         unsigned int :3;
         unsigned int CPOL:1;
         unsigned int COE:1;
         unsigned int CON:1;
      };
      struct {
         unsigned int CCH:2;
         unsigned int :2;
         unsigned int :1;
         unsigned int :1;
         unsigned int EVPOL:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :3;
      };

      struct {
         unsigned int :15;
         unsigned int CEN:1;
      };
   };
} CM2CONBITS;
CM2CONBITS CM2CONbits;
#word CM2CONbits = 0x636
#word CM2CON = 0x636

typedef union 
 {
   union {
      struct {
         unsigned int CCH0:2;
         unsigned int :2;
         unsigned int CREF:1;
         unsigned int :1;
         unsigned int EVPOL0:2;
         unsigned int COUT:1;
         unsigned int CEVT:1;
         unsigned int :3;
         unsigned int CPOL:1;
         unsigned int COE:1;
         unsigned int CON:1;
      };
      struct {
         unsigned int CCH:2;
         unsigned int :2;
         unsigned int :1;
         unsigned int :1;
         unsigned int EVPOL:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :3;
      };

      struct {
         unsigned int :15;
         unsigned int CEN:1;
      };
   };
} CM3CONBITS;
CM3CONBITS CM3CONbits;
#word CM3CONbits = 0x638
#word CM3CON = 0x638

typedef union 
 {
      struct {
         unsigned int :3;
         unsigned int LENDIAN:1;
         unsigned int CRCGO:1;
         unsigned int CRCISEL:1;
         unsigned int CRCMPT:1;
         unsigned int CRCFUL:1;
         unsigned int VWORD0:5;
         unsigned int CSIDL:1;
         unsigned int :1;
         unsigned int CRCEN:1;
      };
      struct {
         unsigned int :3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int VWORD:5;
      };
} CRCCON1BITS;
CRCCON1BITS CRCCON1bits;
#word CRCCON1bits = 0x640
#word CRCCON1 = 0x640

typedef union 
 {
      struct {
         unsigned int PLEN0:5;
         unsigned int :3;
         unsigned int DWIDTH0:5;
      };
      struct {
         unsigned int PLEN:5;
         unsigned int :3;
         unsigned int DWIDTH:5;
      };
} CRCCON2BITS;
CRCCON2BITS CRCCON2bits;
#word CRCCON2bits = 0x642
#word CRCCON2 = 0x642

typedef struct 
 {
   unsigned int :1;
   unsigned int X1:15;
} CRCXORLBITS;
CRCXORLBITS CRCXORLbits;
#word CRCXORLbits = 0x644
#word CRCXORL = 0x644

typedef struct 
 {
   unsigned int X16:4;
   unsigned int X20:10;
   unsigned int X30:2;
} CRCXORHBITS;
CRCXORHBITS CRCXORHbits;
#word CRCXORHbits = 0x646
#word CRCXORH = 0x646

#word CRCDAT = 0x648

#word CRCWDAT = 0x64C

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int INT1R0:6;
      };
      struct {
         unsigned int :8;
         unsigned int INT1R:6;
      };
} RPINR0BITS;
RPINR0BITS RPINR0bits;
#word RPINR0bits = 0x680
#word RPINR0 = 0x680

typedef union 
 {
      struct {
         unsigned int INT2R0:6;
         unsigned int :2;
         unsigned int INT3R0:6;
      };
      struct {
         unsigned int INT2R:6;
         unsigned int :2;
         unsigned int INT3R:6;
      };
} RPINR1BITS;
RPINR1BITS RPINR1bits;
#word RPINR1bits = 0x682
#word RPINR1 = 0x682

#word RPINR2 = 0x684

typedef union 
 {
      struct {
         unsigned int T2CKR0:6;
         unsigned int :2;
         unsigned int T3CKR0:6;
      };
      struct {
         unsigned int T2CKR:6;
         unsigned int :2;
         unsigned int T3CKR:6;
      };
} RPINR3BITS;
RPINR3BITS RPINR3bits;
#word RPINR3bits = 0x686
#word RPINR3 = 0x686

typedef union 
 {
      struct {
         unsigned int T4CKR0:6;
         unsigned int :2;
         unsigned int T5CKR0:6;
      };
      struct {
         unsigned int T4CKR:6;
         unsigned int :2;
         unsigned int T5CKR:6;
      };
} RPINR4BITS;
RPINR4BITS RPINR4bits;
#word RPINR4bits = 0x688
#word RPINR4 = 0x688

typedef union 
 {
      struct {
         unsigned int IC1R0:6;
         unsigned int :2;
         unsigned int IC2R0:6;
      };
      struct {
         unsigned int IC1R:6;
         unsigned int :2;
         unsigned int IC2R:6;
      };
} RPINR7BITS;
RPINR7BITS RPINR7bits;
#word RPINR7bits = 0x68E
#word RPINR7 = 0x68E

typedef union 
 {
      struct {
         unsigned int IC3R0:6;
         unsigned int :2;
         unsigned int IC4R0:6;
      };
      struct {
         unsigned int IC3R:6;
         unsigned int :2;
         unsigned int IC4R:6;
      };
} RPINR8BITS;
RPINR8BITS RPINR8bits;
#word RPINR8bits = 0x690
#word RPINR8 = 0x690

typedef union 
 {
      struct {
         unsigned int IC5R0:6;
         unsigned int :2;
         unsigned int IC6R0:6;
      };
      struct {
         unsigned int IC5R:6;
         unsigned int :2;
         unsigned int IC6R:6;
      };
} RPINR9BITS;
RPINR9BITS RPINR9bits;
#word RPINR9bits = 0x692
#word RPINR9 = 0x692

typedef union 
 {
      struct {
         unsigned int IC7R0:6;
         unsigned int :2;
         unsigned int IC8R0:6;
      };
      struct {
         unsigned int IC7R:6;
         unsigned int :2;
         unsigned int IC8R:6;
      };
} RPINR10BITS;
RPINR10BITS RPINR10bits;
#word RPINR10bits = 0x694
#word RPINR10 = 0x694

typedef union 
 {
      struct {
         unsigned int OCFAR0:6;
         unsigned int :2;
         unsigned int OCFBR0:6;
      };
      struct {
         unsigned int OCFAR:6;
         unsigned int :2;
         unsigned int OCFBR:6;
      };
} RPINR11BITS;
RPINR11BITS RPINR11bits;
#word RPINR11bits = 0x696
#word RPINR11 = 0x696

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int IC9R0:6;
      };
      struct {
         unsigned int :8;
         unsigned int IC9R:6;
      };
} RPINR15BITS;
RPINR15BITS RPINR15bits;
#word RPINR15bits = 0x69E
#word RPINR15 = 0x69E

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int U3RXR0:6;
      };
      struct {
         unsigned int :8;
         unsigned int U3RXR:6;
      };
} RPINR17BITS;
RPINR17BITS RPINR17bits;
#word RPINR17bits = 0x6A2
#word RPINR17 = 0x6A2

typedef union 
 {
      struct {
         unsigned int U1RXR0:6;
         unsigned int :2;
         unsigned int U1CTSR0:6;
      };
      struct {
         unsigned int U1RXR:6;
         unsigned int :2;
         unsigned int U1CTSR:6;
      };
} RPINR18BITS;
RPINR18BITS RPINR18bits;
#word RPINR18bits = 0x6A4
#word RPINR18 = 0x6A4

typedef union 
 {
      struct {
         unsigned int U2RXR0:6;
         unsigned int :2;
         unsigned int U2CTSR0:6;
      };
      struct {
         unsigned int U2RXR:6;
         unsigned int :2;
         unsigned int U2CTSR:6;
      };
} RPINR19BITS;
RPINR19BITS RPINR19bits;
#word RPINR19bits = 0x6A6
#word RPINR19 = 0x6A6

typedef union 
 {
      struct {
         unsigned int SDI1R0:6;
         unsigned int :2;
         unsigned int SCK1R0:6;
      };
      struct {
         unsigned int SDI1R:6;
         unsigned int :2;
         unsigned int SCK1R:6;
      };
} RPINR20BITS;
RPINR20BITS RPINR20bits;
#word RPINR20bits = 0x6A8
#word RPINR20 = 0x6A8

typedef union 
 {
      struct {
         unsigned int SS1R0:6;
         unsigned int :2;
         unsigned int U3CTSR0:6;
      };
      struct {
         unsigned int SS1R:6;
         unsigned int :2;
         unsigned int U3CTSR:6;
      };
} RPINR21BITS;
RPINR21BITS RPINR21bits;
#word RPINR21bits = 0x6AA
#word RPINR21 = 0x6AA

typedef union 
 {
      struct {
         unsigned int SDI2R0:6;
         unsigned int :2;
         unsigned int SCK2R0:6;
      };
      struct {
         unsigned int SDI2R:6;
         unsigned int :2;
         unsigned int SCK2R:6;
      };
} RPINR22BITS;
RPINR22BITS RPINR22bits;
#word RPINR22bits = 0x6AC
#word RPINR22 = 0x6AC

#word RPINR23 = 0x6AE

typedef union 
 {
      struct {
         unsigned int U4RXR0:6;
         unsigned int :2;
         unsigned int U4CTSR0:6;
      };
      struct {
         unsigned int U4RXR:6;
         unsigned int :2;
         unsigned int U4CTSR:6;
      };
} RPINR27BITS;
RPINR27BITS RPINR27bits;
#word RPINR27bits = 0x6B6
#word RPINR27 = 0x6B6

typedef union 
 {
      struct {
         unsigned int SDI3R0:6;
         unsigned int :2;
         unsigned int SCK3R0:6;
      };
      struct {
         unsigned int SDI3R:6;
         unsigned int :2;
         unsigned int SCK3R:6;
      };
} RPINR28BITS;
RPINR28BITS RPINR28bits;
#word RPINR28bits = 0x6B8
#word RPINR28 = 0x6B8

#word RPINR29 = 0x6BA

typedef union 
 {
      struct {
         unsigned int RP0R0:6;
         unsigned int :2;
         unsigned int RP1R0:6;
      };
      struct {
         unsigned int RP0R:6;
         unsigned int :2;
         unsigned int RP1R:6;
      };
} RPOR0BITS;
RPOR0BITS RPOR0bits;
#word RPOR0bits = 0x6C0
#word RPOR0 = 0x6C0

typedef union 
 {
      struct {
         unsigned int RP2R0:6;
         unsigned int :2;
         unsigned int RP3R0:6;
      };
      struct {
         unsigned int RP2R:6;
         unsigned int :2;
         unsigned int RP3R:6;
      };
} RPOR1BITS;
RPOR1BITS RPOR1bits;
#word RPOR1bits = 0x6C2
#word RPOR1 = 0x6C2

#word RPOR2 = 0x6C4

typedef union 
 {
      struct {
         unsigned int RP6R0:6;
         unsigned int :2;
         unsigned int RP7R0:6;
      };
      struct {
         unsigned int RP6R:6;
         unsigned int :2;
         unsigned int RP7R:6;
      };
} RPOR3BITS;
RPOR3BITS RPOR3bits;
#word RPOR3bits = 0x6C6
#word RPOR3 = 0x6C6

typedef union 
 {
      struct {
         unsigned int RP8R0:6;
         unsigned int :2;
         unsigned int RP9R0:6;
      };
      struct {
         unsigned int RP8R:6;
         unsigned int :2;
         unsigned int RP9R:6;
      };
} RPOR4BITS;
RPOR4BITS RPOR4bits;
#word RPOR4bits = 0x6C8
#word RPOR4 = 0x6C8

typedef union 
 {
      struct {
         unsigned int RP10R0:6;
         unsigned int :2;
         unsigned int RP11R0:6;
      };
      struct {
         unsigned int RP10R:6;
         unsigned int :2;
         unsigned int RP11R:6;
      };
} RPOR5BITS;
RPOR5BITS RPOR5bits;
#word RPOR5bits = 0x6CA
#word RPOR5 = 0x6CA

typedef union 
 {
      struct {
         unsigned int RP12R0:6;
         unsigned int :2;
         unsigned int RP13R0:6;
      };
      struct {
         unsigned int RP12R:6;
         unsigned int :2;
         unsigned int RP13R:6;
      };
} RPOR6BITS;
RPOR6BITS RPOR6bits;
#word RPOR6bits = 0x6CC
#word RPOR6 = 0x6CC

#word RPOR7 = 0x6CE

typedef union 
 {
      struct {
         unsigned int RP16R0:6;
         unsigned int :2;
         unsigned int RP17R0:6;
      };
      struct {
         unsigned int RP16R:6;
         unsigned int :2;
         unsigned int RP17R:6;
      };
} RPOR8BITS;
RPOR8BITS RPOR8bits;
#word RPOR8bits = 0x6D0
#word RPOR8 = 0x6D0

typedef union 
 {
      struct {
         unsigned int RP18R0:6;
         unsigned int :2;
         unsigned int RP19R0:6;
      };
      struct {
         unsigned int RP18R:6;
         unsigned int :2;
         unsigned int RP19R:6;
      };
} RPOR9BITS;
RPOR9BITS RPOR9bits;
#word RPOR9bits = 0x6D2
#word RPOR9 = 0x6D2

typedef union 
 {
      struct {
         unsigned int RP20R0:6;
         unsigned int :2;
         unsigned int RP21R0:6;
      };
      struct {
         unsigned int RP20R:6;
         unsigned int :2;
         unsigned int RP21R:6;
      };
} RPOR10BITS;
RPOR10BITS RPOR10bits;
#word RPOR10bits = 0x6D4
#word RPOR10 = 0x6D4

typedef union 
 {
      struct {
         unsigned int RP22R0:6;
         unsigned int :2;
         unsigned int RP23R0:6;
      };
      struct {
         unsigned int RP22R:6;
         unsigned int :2;
         unsigned int RP23R:6;
      };
} RPOR11BITS;
RPOR11BITS RPOR11bits;
#word RPOR11bits = 0x6D6
#word RPOR11 = 0x6D6

typedef union 
 {
      struct {
         unsigned int RP24R0:6;
         unsigned int :2;
         unsigned int RP25R0:6;
      };
      struct {
         unsigned int RP24R:6;
         unsigned int :2;
         unsigned int RP25R:6;
      };
} RPOR12BITS;
RPOR12BITS RPOR12bits;
#word RPOR12bits = 0x6D8
#word RPOR12 = 0x6D8

typedef union 
 {
      struct {
         unsigned int RP26R0:6;
         unsigned int :2;
         unsigned int RP27R0:6;
      };
      struct {
         unsigned int RP26R:6;
         unsigned int :2;
         unsigned int RP27R:6;
      };
} RPOR13BITS;
RPOR13BITS RPOR13bits;
#word RPOR13bits = 0x6DA
#word RPOR13 = 0x6DA

typedef union 
 {
      struct {
         unsigned int RP28R0:6;
         unsigned int :2;
         unsigned int RP29R0:6;
      };
      struct {
         unsigned int RP28R:6;
         unsigned int :2;
         unsigned int RP29R:6;
      };
} RPOR14BITS;
RPOR14BITS RPOR14bits;
#word RPOR14bits = 0x6DC
#word RPOR14 = 0x6DC

typedef struct 
 {
   union {
      struct {
         unsigned int POR:1;
         unsigned int BOR:1;
         unsigned int IDLE:1;
         unsigned int SLEEP:1;
         unsigned int WDTO:1;
         unsigned int SWDTEN:1;
         unsigned int SWR:1;
         unsigned int EXTR:1;
         unsigned int VREGS:1;
         unsigned int CM:1;
         unsigned int :4;
         unsigned int IOPUWR:1;
         unsigned int TRAPR:1;
      };

      struct {
         unsigned int :8;
         unsigned int PMSLP:1;
      };
   };
} RCONBITS;
RCONBITS RCONbits;
#word RCONbits = 0x740
#word RCON = 0x740

typedef union 
 {
   union {
      struct {
         unsigned int OSWEN:1;
         unsigned int SOSCEN:1;
         unsigned int POSCEN:1;
         unsigned int CF:1;
         unsigned int :1;
         unsigned int LOCK:1;
         unsigned int IOLOCK:1;
         unsigned int CLKLOCK:1;
         unsigned int NOSC0:3;
         unsigned int :1;
         unsigned int COSC0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int NOSC:3;
         unsigned int :1;
         unsigned int COSC:3;
      };

      struct {
         unsigned int :1;
         unsigned int LPOSCEN:1;
      };
   };
} OSCCONBITS;
OSCCONBITS OSCCONbits;
#word OSCCONbits = 0x742
#word OSCCON = 0x742

typedef union 
 {
      struct {
         unsigned int :5;
         unsigned int PLLEN:1;
         unsigned int CPDIV0:2;
         unsigned int RCDIV0:3;
         unsigned int DOZEN:1;
         unsigned int DOZE0:3;
         unsigned int ROI:1;
      };
      struct {
         unsigned int :5;
         unsigned int :1;
         unsigned int CPDIV:2;
         unsigned int RCDIV:3;
         unsigned int :1;
         unsigned int DOZE:3;
      };
} CLKDIVBITS;
CLKDIVBITS CLKDIVbits;
#word CLKDIVbits = 0x744
#word CLKDIV = 0x744

#word OSCTUN = 0x748

typedef union 
 {
   union {
      struct {
         unsigned int :8;
         unsigned int RODIV0:4;
         unsigned int ROSEL:1;
         unsigned int ROSSLP:1;
         unsigned int :1;
         unsigned int ROEN:1;
      };
      struct {
         unsigned int :8;
         unsigned int RODIV:4;
      };

      struct {
         unsigned int :15;
         unsigned int ROON:1;
      };
   };
} REFOCONBITS;
REFOCONBITS REFOCONbits;
#word REFOCONbits = 0x74E
#word REFOCON = 0x74E

typedef union 
 {
      struct {
         unsigned int NVMOP0:4;
         unsigned int :2;
         unsigned int ERASE:1;
         unsigned int :6;
         unsigned int WRERR:1;
         unsigned int WREN:1;
         unsigned int WR:1;
      };
      struct {
         unsigned int NVMOP:4;
         unsigned int :2;
         unsigned int :1;
         unsigned int :6;
      };
} NVMCONBITS;
NVMCONBITS NVMCONbits;
#word NVMCONbits = 0x760
#word NVMCON = 0x760

#word NVMKEY = 0x766

typedef struct 
 {
   unsigned int ADC1MD:1;
   unsigned int :2;
   unsigned int SPI1MD:1;
   unsigned int SPI2MD:1;
   unsigned int U1MD:1;
   unsigned int U2MD:1;
   unsigned int I2C1MD:1;
   unsigned int :3;
   unsigned int T1MD:1;
   unsigned int T2MD:1;
   unsigned int T3MD:1;
   unsigned int T4MD:1;
   unsigned int T5MD:1;
} PMD1BITS;
PMD1BITS PMD1bits;
#word PMD1bits = 0x770
#word PMD1 = 0x770

typedef struct 
 {
   unsigned int OC1MD:1;
   unsigned int OC2MD:1;
   unsigned int OC3MD:1;
   unsigned int OC4MD:1;
   unsigned int OC5MD:1;
   unsigned int OC6MD:1;
   unsigned int OC7MD:1;
   unsigned int OC8MD:1;
   unsigned int IC1MD:1;
   unsigned int IC2MD:1;
   unsigned int IC3MD:1;
   unsigned int IC4MD:1;
   unsigned int IC5MD:1;
   unsigned int IC6MD:1;
   unsigned int IC7MD:1;
   unsigned int IC8MD:1;
} PMD2BITS;
PMD2BITS PMD2bits;
#word PMD2bits = 0x772
#word PMD2 = 0x772

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int I2C2MD:1;
         unsigned int I2C3MD:1;
         unsigned int U3MD:1;
         unsigned int :3;
         unsigned int CRCMD:1;
         unsigned int PMPMD:1;
         unsigned int RTCCMD:1;
         unsigned int CMPMD:1;
      };

      struct {
         unsigned int :7;
         unsigned int CRCPMD:1;
      };
   };
} PMD3BITS;
PMD3BITS PMD3bits;
#word PMD3bits = 0x774
#word PMD3 = 0x774

typedef struct 
 {
   unsigned int USB1MD:1;
   unsigned int LVDMD:1;
   unsigned int CTMUMD:1;
   unsigned int REFOMD:1;
   unsigned int :1;
   unsigned int U4MD:1;
   unsigned int UPWMMD:1;
} PMD4BITS;
PMD4BITS PMD4bits;
#word PMD4bits = 0x776
#word PMD4 = 0x776

typedef struct 
 {
   unsigned int OC9MD:1;
   unsigned int :7;
   unsigned int IC9MD:1;
} PMD5BITS;
PMD5BITS PMD5bits;
#word PMD5bits = 0x778
#word PMD5 = 0x778

typedef struct 
 {
   unsigned int SPI3MD:1;
} PMD6BITS;
PMD6BITS PMD6bits;
#word PMD6bits = 0x77A
#word PMD6 = 0x77A

