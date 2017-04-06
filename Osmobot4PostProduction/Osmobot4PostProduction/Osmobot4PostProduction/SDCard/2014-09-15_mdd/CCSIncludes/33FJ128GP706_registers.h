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

#word ACCA = 0x022

typedef union 
 {
      struct {
         unsigned int ACCAU0:8;
         unsigned int SIGNEXT0:8;
      };
      struct {
         unsigned int ACCAU:8;
         unsigned int SIGNEXT:8;
      };
} ACCAUBITS;
ACCAUBITS ACCAUbits;
#word ACCAUbits = 0x026
#word ACCAU = 0x026

#word ACCB = 0x028

typedef union 
 {
      struct {
         unsigned int ACCBU0:8;
         unsigned int SIGNEXT0:8;
      };
      struct {
         unsigned int ACCBU:8;
         unsigned int SIGNEXT:8;
      };
} ACCBUBITS;
ACCBUBITS ACCBUbits;
#word ACCBUbits = 0x02C
#word ACCBU = 0x02C

#word PC = 0x02E

#word TBLPAG = 0x032

#word PSVPAG = 0x034

#word RCOUNT = 0x036

#word DCOUNT = 0x038

#word DOSTART = 0x03A

#word DOEND = 0x03E

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
         unsigned int DA:1;
         unsigned int SAB:1;
         unsigned int OAB:1;
         unsigned int SB:1;
         unsigned int SA:1;
         unsigned int OB:1;
         unsigned int OA:1;
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

typedef union 
 {
      struct {
         unsigned int IF:1;
         unsigned int RND:1;
         unsigned int PSV:1;
         unsigned int IPL3:1;
         unsigned int ACCSAT:1;
         unsigned int SATDW:1;
         unsigned int SATB:1;
         unsigned int SATA:1;
         unsigned int DL0:3;
         unsigned int EDT:1;
         unsigned int US:1;
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
         unsigned int DL:3;
      };
} CORCONBITS;
CORCONBITS CORCONbits;
#word CORCONbits = 0x044
#word CORCON = 0x044

typedef union 
 {
      struct {
         unsigned int XWM0:4;
         unsigned int YWM0:4;
         unsigned int BWM0:4;
         unsigned int :2;
         unsigned int YMODEN:1;
         unsigned int XMODEN:1;
      };
      struct {
         unsigned int XWM:4;
         unsigned int YWM:4;
         unsigned int BWM:4;
         unsigned int :2;
      };
} MODCONBITS;
MODCONBITS MODCONbits;
#word MODCONbits = 0x046
#word MODCON = 0x046

#word XMODSRT = 0x048

#word XMODEND = 0x04A

#word YMODSRT = 0x04C

#word YMODEND = 0x04E

typedef union 
 {
      struct {
         unsigned int XB0:15;
         unsigned int BREN:1;
      };
      struct {
         unsigned int XB:15;
      };
} XBREVBITS;
XBREVBITS XBREVbits;
#word XBREVbits = 0x050
#word XBREV = 0x050

#word DISICNT = 0x052

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
#word CNEN1bits = 0x060
#word CNEN1 = 0x060

typedef struct 
 {
   unsigned int CN16IE:1;
   unsigned int CN17IE:1;
   unsigned int CN18IE:1;
} CNEN2BITS;
CNEN2BITS CNEN2bits;
#word CNEN2bits = 0x062
#word CNEN2 = 0x062

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
#word CNPU1bits = 0x068
#word CNPU1 = 0x068

typedef struct 
 {
   unsigned int CN16PUE:1;
   unsigned int CN17PUE:1;
   unsigned int CN18PUE:1;
} CNPU2BITS;
CNPU2BITS CNPU2bits;
#word CNPU2bits = 0x06A
#word CNPU2 = 0x06A

typedef struct 
 {
   unsigned int :1;
   unsigned int OSCFAIL:1;
   unsigned int STKERR:1;
   unsigned int ADDRERR:1;
   unsigned int MATHERR:1;
   unsigned int DMACERR:1;
   unsigned int DIV0ERR:1;
   unsigned int SFTACERR:1;
   unsigned int COVTE:1;
   unsigned int OVBTE:1;
   unsigned int OVATE:1;
   unsigned int COVBERR:1;
   unsigned int COVAERR:1;
   unsigned int OVBERR:1;
   unsigned int OVAERR:1;
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
   unsigned int DMA0IF:1;
   unsigned int IC2IF:1;
   unsigned int OC2IF:1;
   unsigned int T2IF:1;
   unsigned int T3IF:1;
   unsigned int SPI1EIF:1;
   unsigned int SPI1IF:1;
   unsigned int U1RXIF:1;
   unsigned int U1TXIF:1;
   unsigned int AD1IF:1;
   unsigned int DMA1IF:1;
} IFS0BITS;
IFS0BITS IFS0bits;
#word IFS0bits = 0x084
#word IFS0 = 0x084

typedef struct 
 {
   union {
      struct {
         unsigned int SI2C1IF:1;
         unsigned int MI2C1IF:1;
         unsigned int :1;
         unsigned int CNIF:1;
         unsigned int INT1IF:1;
         unsigned int AD2IF:1;
         unsigned int IC7IF:1;
         unsigned int IC8IF:1;
         unsigned int DMA2IF:1;
         unsigned int OC3IF:1;
         unsigned int OC4IF:1;
         unsigned int T4IF:1;
         unsigned int T5IF:1;
         unsigned int INT2IF:1;
         unsigned int U2RXIF:1;
         unsigned int U2TXIF:1;
      };

      struct {
         unsigned int SI2CIF:1;
      };
   };
} IFS1BITS;
IFS1BITS IFS1bits;
#word IFS1bits = 0x086
#word IFS1 = 0x086

typedef struct 
 {
   unsigned int SPI2EIF:1;
   unsigned int SPI2IF:1;
   unsigned int C1RXIF:1;
   unsigned int C1IF:1;
   unsigned int DMA3IF:1;
   unsigned int IC3IF:1;
   unsigned int IC4IF:1;
   unsigned int IC5IF:1;
   unsigned int IC6IF:1;
   unsigned int OC5IF:1;
   unsigned int OC6IF:1;
   unsigned int OC7IF:1;
   unsigned int OC8IF:1;
   unsigned int :1;
   unsigned int DMA4IF:1;
   unsigned int T6IF:1;
} IFS2BITS;
IFS2BITS IFS2bits;
#word IFS2bits = 0x088
#word IFS2 = 0x088

typedef struct 
 {
   unsigned int T7IF:1;
   unsigned int SI2C2IF:1;
   unsigned int MI2C2IF:1;
   unsigned int T8IF:1;
   unsigned int T9IF:1;
   unsigned int INT3IF:1;
   unsigned int INT4IF:1;
   unsigned int C2RXIF:1;
   unsigned int C2IF:1;
   unsigned int :2;
   unsigned int DCIEIF:1;
   unsigned int DCIIF:1;
   unsigned int DMA5IF:1;
} IFS3BITS;
IFS3BITS IFS3bits;
#word IFS3bits = 0x08A
#word IFS3 = 0x08A

typedef struct 
 {
   unsigned int :1;
   unsigned int U1EIF:1;
   unsigned int U2EIF:1;
   unsigned int :1;
   unsigned int DMA6IF:1;
   unsigned int DMA7IF:1;
   unsigned int C1TXIF:1;
   unsigned int C2TXIF:1;
} IFS4BITS;
IFS4BITS IFS4bits;
#word IFS4bits = 0x08C
#word IFS4 = 0x08C

typedef struct 
 {
   unsigned int INT0IE:1;
   unsigned int IC1IE:1;
   unsigned int OC1IE:1;
   unsigned int T1IE:1;
   unsigned int DMA0IE:1;
   unsigned int IC2IE:1;
   unsigned int OC2IE:1;
   unsigned int T2IE:1;
   unsigned int T3IE:1;
   unsigned int SPI1EIE:1;
   unsigned int SPI1IE:1;
   unsigned int U1RXIE:1;
   unsigned int U1TXIE:1;
   unsigned int AD1IE:1;
   unsigned int DMA1IE:1;
} IEC0BITS;
IEC0BITS IEC0bits;
#word IEC0bits = 0x094
#word IEC0 = 0x094

typedef struct 
 {
   union {
      struct {
         unsigned int SI2C1IE:1;
         unsigned int MI2C1IE:1;
         unsigned int :1;
         unsigned int CNIE:1;
         unsigned int INT1IE:1;
         unsigned int AD2IE:1;
         unsigned int IC7IE:1;
         unsigned int IC8IE:1;
         unsigned int DMA2IE:1;
         unsigned int OC3IE:1;
         unsigned int OC4IE:1;
         unsigned int T4IE:1;
         unsigned int T5IE:1;
         unsigned int INT2IE:1;
         unsigned int U2RXIE:1;
         unsigned int U2TXIE:1;
      };

      struct {
         unsigned int SI2CIE:1;
      };
   };
} IEC1BITS;
IEC1BITS IEC1bits;
#word IEC1bits = 0x096
#word IEC1 = 0x096

typedef struct 
 {
   unsigned int SPI2EIE:1;
   unsigned int SPI2IE:1;
   unsigned int C1RXIE:1;
   unsigned int C1IE:1;
   unsigned int DMA3IE:1;
   unsigned int IC3IE:1;
   unsigned int IC4IE:1;
   unsigned int IC5IE:1;
   unsigned int IC6IE:1;
   unsigned int OC5IE:1;
   unsigned int OC6IE:1;
   unsigned int OC7IE:1;
   unsigned int OC8IE:1;
   unsigned int :1;
   unsigned int DMA4IE:1;
   unsigned int T6IE:1;
} IEC2BITS;
IEC2BITS IEC2bits;
#word IEC2bits = 0x098
#word IEC2 = 0x098

typedef struct 
 {
   unsigned int T7IE:1;
   unsigned int SI2C2IE:1;
   unsigned int MI2C2IE:1;
   unsigned int T8IE:1;
   unsigned int T9IE:1;
   unsigned int INT3IE:1;
   unsigned int INT4IE:1;
   unsigned int C2RXIE:1;
   unsigned int C2IE:1;
   unsigned int :2;
   unsigned int DCIEIE:1;
   unsigned int DCIIE:1;
   unsigned int DMA5IE:1;
} IEC3BITS;
IEC3BITS IEC3bits;
#word IEC3bits = 0x09A
#word IEC3 = 0x09A

typedef struct 
 {
   unsigned int :1;
   unsigned int U1EIE:1;
   unsigned int U2EIE:1;
   unsigned int :1;
   unsigned int DMA6IE:1;
   unsigned int DMA7IE:1;
   unsigned int C1TXIE:1;
   unsigned int C2TXIE:1;
} IEC4BITS;
IEC4BITS IEC4bits;
#word IEC4bits = 0x09C
#word IEC4 = 0x09C

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
         unsigned int DMA0IP0:3;
         unsigned int :1;
         unsigned int IC2IP0:3;
         unsigned int :1;
         unsigned int OC2IP0:3;
         unsigned int :1;
         unsigned int T2IP0:3;
      };
      struct {
         unsigned int DMA0IP:3;
         unsigned int :1;
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
         unsigned int SPI1EIP0:3;
         unsigned int :1;
         unsigned int SPI1IP0:3;
         unsigned int :1;
         unsigned int U1RXIP0:3;
      };
      struct {
         unsigned int T3IP:3;
         unsigned int :1;
         unsigned int SPI1EIP:3;
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
         unsigned int :1;
         unsigned int DMA1IP0:3;
      };
      struct {
         unsigned int U1TXIP:3;
         unsigned int :1;
         unsigned int AD1IP:3;
         unsigned int :1;
         unsigned int DMA1IP:3;
      };
} IPC3BITS;
IPC3BITS IPC3bits;
#word IPC3bits = 0x0AA
#word IPC3 = 0x0AA

typedef union 
 {
      struct {
         unsigned int SI2C1IP0:3;
         unsigned int :1;
         unsigned int MI2C1IP0:3;
         unsigned int :5;
         unsigned int CNIP0:3;
      };
      struct {
         unsigned int SI2C1IP:3;
         unsigned int :1;
         unsigned int MI2C1IP:3;
         unsigned int :5;
         unsigned int CNIP:3;
      };
} IPC4BITS;
IPC4BITS IPC4bits;
#word IPC4bits = 0x0AC
#word IPC4 = 0x0AC

typedef union 
 {
      struct {
         unsigned int INT1IP0:3;
         unsigned int :1;
         unsigned int AD2IP0:3;
         unsigned int :1;
         unsigned int IC7IP0:3;
         unsigned int :1;
         unsigned int IC8IP0:3;
      };
      struct {
         unsigned int INT1IP:3;
         unsigned int :1;
         unsigned int AD2IP:3;
         unsigned int :1;
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
         unsigned int DMA2IP0:3;
         unsigned int :1;
         unsigned int OC3IP0:3;
         unsigned int :1;
         unsigned int OC4IP0:3;
         unsigned int :1;
         unsigned int T4IP0:3;
      };
      struct {
         unsigned int DMA2IP:3;
         unsigned int :1;
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
         unsigned int SPI2EIP0:3;
         unsigned int :1;
         unsigned int SPI2IP0:3;
         unsigned int :1;
         unsigned int C1RXIP0:3;
         unsigned int :1;
         unsigned int C1IP0:3;
      };
      struct {
         unsigned int SPI2EIP:3;
         unsigned int :1;
         unsigned int SPI2IP:3;
         unsigned int :1;
         unsigned int C1RXIP:3;
         unsigned int :1;
         unsigned int C1IP:3;
      };
} IPC8BITS;
IPC8BITS IPC8bits;
#word IPC8bits = 0x0B4
#word IPC8 = 0x0B4

typedef union 
 {
      struct {
         unsigned int DMA3IP0:3;
         unsigned int :1;
         unsigned int IC3IP0:3;
         unsigned int :1;
         unsigned int IC4IP0:3;
         unsigned int :1;
         unsigned int IC5IP0:3;
      };
      struct {
         unsigned int DMA3IP:3;
         unsigned int :1;
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
         unsigned int :5;
         unsigned int DMA4IP0:3;
         unsigned int :1;
         unsigned int T6IP0:3;
      };
      struct {
         unsigned int OC8IP:3;
         unsigned int :5;
         unsigned int DMA4IP:3;
         unsigned int :1;
         unsigned int T6IP:3;
      };
} IPC11BITS;
IPC11BITS IPC11bits;
#word IPC11bits = 0x0BA
#word IPC11 = 0x0BA

typedef union 
 {
      struct {
         unsigned int T7IP0:3;
         unsigned int :1;
         unsigned int SI2C2IP0:3;
         unsigned int :1;
         unsigned int MI2C2IP0:3;
         unsigned int :1;
         unsigned int T8IP0:3;
      };
      struct {
         unsigned int T7IP:3;
         unsigned int :1;
         unsigned int SI2C2IP:3;
         unsigned int :1;
         unsigned int MI2C2IP:3;
         unsigned int :1;
         unsigned int T8IP:3;
      };
} IPC12BITS;
IPC12BITS IPC12bits;
#word IPC12bits = 0x0BC
#word IPC12 = 0x0BC

typedef union 
 {
      struct {
         unsigned int T9IP0:3;
         unsigned int :1;
         unsigned int INT3IP0:3;
         unsigned int :1;
         unsigned int INT4IP0:3;
         unsigned int :1;
         unsigned int C2RXIP0:3;
      };
      struct {
         unsigned int T9IP:3;
         unsigned int :1;
         unsigned int INT3IP:3;
         unsigned int :1;
         unsigned int INT4IP:3;
         unsigned int :1;
         unsigned int C2RXIP:3;
      };
} IPC13BITS;
IPC13BITS IPC13bits;
#word IPC13bits = 0x0BE
#word IPC13 = 0x0BE

typedef union 
 {
      struct {
         unsigned int C2IP0:3;
         unsigned int :9;
         unsigned int DCIEIP0:3;
      };
      struct {
         unsigned int C2IP:3;
         unsigned int :9;
         unsigned int DCIEIP:3;
      };
} IPC14BITS;
IPC14BITS IPC14bits;
#word IPC14bits = 0x0C0
#word IPC14 = 0x0C0

typedef union 
 {
      struct {
         unsigned int DCIIP0:3;
         unsigned int :1;
         unsigned int DMA5IP0:3;
      };
      struct {
         unsigned int DCIIP:3;
         unsigned int :1;
         unsigned int DMA5IP:3;
      };
} IPC15BITS;
IPC15BITS IPC15bits;
#word IPC15bits = 0x0C2
#word IPC15 = 0x0C2

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int U1EIP0:3;
         unsigned int :1;
         unsigned int U2EIP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int U1EIP:3;
         unsigned int :1;
         unsigned int U2EIP:3;
      };
} IPC16BITS;
IPC16BITS IPC16bits;
#word IPC16bits = 0x0C4
#word IPC16 = 0x0C4

typedef union 
 {
      struct {
         unsigned int DMA6IP0:3;
         unsigned int :1;
         unsigned int DMA7IP0:3;
         unsigned int :1;
         unsigned int C1TXIP0:3;
         unsigned int :1;
         unsigned int C2TXIP0:3;
      };
      struct {
         unsigned int DMA6IP:3;
         unsigned int :1;
         unsigned int DMA7IP:3;
         unsigned int :1;
         unsigned int C1TXIP:3;
         unsigned int :1;
         unsigned int C2TXIP:3;
      };
} IPC17BITS;
IPC17BITS IPC17bits;
#word IPC17bits = 0x0C6
#word IPC17 = 0x0C6

typedef union 
 {
      struct {
         unsigned int VECNUM0:7;
         unsigned int :1;
         unsigned int ILR0:4;
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

#word TMR6 = 0x122

#word TMR7HLD = 0x124

#word TMR7 = 0x126

#word PR6 = 0x128

#word PR7 = 0x12A

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
} T6CONBITS;
T6CONBITS T6CONbits;
#word T6CONbits = 0x12C
#word T6CON = 0x12C

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
} T7CONBITS;
T7CONBITS T7CONbits;
#word T7CONbits = 0x12E
#word T7CON = 0x12E

#word TMR8 = 0x130

#word TMR9HLD = 0x132

#word TMR9 = 0x134

#word PR8 = 0x136

#word PR9 = 0x138

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
} T8CONBITS;
T8CONBITS T8CONbits;
#word T8CONbits = 0x13A
#word T8CON = 0x13A

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
} T9CONBITS;
T9CONBITS T9CONbits;
#word T9CONbits = 0x13C
#word T9CON = 0x13C

#word IC1BUF = 0x140

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC1CONBITS;
IC1CONBITS IC1CONbits;
#word IC1CONbits = 0x142
#word IC1CON = 0x142

#word IC2BUF = 0x144

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC2CONBITS;
IC2CONBITS IC2CONbits;
#word IC2CONbits = 0x146
#word IC2CON = 0x146

#word IC3BUF = 0x148

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC3CONBITS;
IC3CONBITS IC3CONbits;
#word IC3CONbits = 0x14A
#word IC3CON = 0x14A

#word IC4BUF = 0x14C

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC4CONBITS;
IC4CONBITS IC4CONbits;
#word IC4CONbits = 0x14E
#word IC4CON = 0x14E

#word IC5BUF = 0x150

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC5CONBITS;
IC5CONBITS IC5CONbits;
#word IC5CONbits = 0x152
#word IC5CON = 0x152

#word IC6BUF = 0x154

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC6CONBITS;
IC6CONBITS IC6CONbits;
#word IC6CONbits = 0x156
#word IC6CON = 0x156

#word IC7BUF = 0x158

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC7CONBITS;
IC7CONBITS IC7CONbits;
#word IC7CONbits = 0x15A
#word IC7CON = 0x15A

#word IC8BUF = 0x15C

typedef union 
 {
      struct {
         unsigned int ICM0:3;
         unsigned int ICBNE:1;
         unsigned int ICOV:1;
         unsigned int ICI0:2;
         unsigned int ICTMR:1;
         unsigned int :5;
         unsigned int ICSIDL:1;
      };
      struct {
         unsigned int ICM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int ICI:2;
         unsigned int :1;
         unsigned int :5;
      };
} IC8CONBITS;
IC8CONBITS IC8CONbits;
#word IC8CONbits = 0x15E
#word IC8CON = 0x15E

#word OC1RS = 0x180

#word OC1R = 0x182

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC1CONBITS;
OC1CONBITS OC1CONbits;
#word OC1CONbits = 0x184
#word OC1CON = 0x184

#word OC2RS = 0x186

#word OC2R = 0x188

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC2CONBITS;
OC2CONBITS OC2CONbits;
#word OC2CONbits = 0x18A
#word OC2CON = 0x18A

#word OC3RS = 0x18C

#word OC3R = 0x18E

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC3CONBITS;
OC3CONBITS OC3CONbits;
#word OC3CONbits = 0x190
#word OC3CON = 0x190

#word OC4RS = 0x192

#word OC4R = 0x194

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC4CONBITS;
OC4CONBITS OC4CONbits;
#word OC4CONbits = 0x196
#word OC4CON = 0x196

#word OC5RS = 0x198

#word OC5R = 0x19A

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC5CONBITS;
OC5CONBITS OC5CONbits;
#word OC5CONbits = 0x19C
#word OC5CON = 0x19C

#word OC6RS = 0x19E

#word OC6R = 0x1A0

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC6CONBITS;
OC6CONBITS OC6CONbits;
#word OC6CONbits = 0x1A2
#word OC6CON = 0x1A2

#word OC7RS = 0x1A4

#word OC7R = 0x1A6

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC7CONBITS;
OC7CONBITS OC7CONbits;
#word OC7CONbits = 0x1A8
#word OC7CON = 0x1A8

#word OC8RS = 0x1AA

#word OC8R = 0x1AC

typedef union 
 {
      struct {
         unsigned int OCM0:3;
         unsigned int OCTSEL:1;
         unsigned int OCFLT:1;
         unsigned int :8;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :8;
      };
} OC8CONBITS;
OC8CONBITS OC8CONbits;
#word OC8CONbits = 0x1AE
#word OC8CON = 0x1AE

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
         unsigned int R_W:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D_A:1;
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
         unsigned int R:1;
         unsigned int :2;
         unsigned int D:1;
         unsigned int I2CCOV:1;
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
         unsigned int R_W:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D_A:1;
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
         unsigned int R:1;
         unsigned int :2;
         unsigned int D:1;
         unsigned int I2CCOV:1;
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
         unsigned int URXINV:1;
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
         unsigned int URXINV:1;
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

typedef struct 
 {
   unsigned int SPIRBF:1;
   unsigned int SPITBF:1;
   unsigned int :4;
   unsigned int SPIROV:1;
   unsigned int :6;
   unsigned int SPISIDL:1;
   unsigned int :1;
   unsigned int SPIEN:1;
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
   unsigned int :1;
   unsigned int FRMDLY:1;
   unsigned int :11;
   unsigned int FRMPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI1CON2BITS;
SPI1CON2BITS SPI1CON2bits;
#word SPI1CON2bits = 0x244
#word SPI1CON2 = 0x244

#word SPI1BUF = 0x248

typedef struct 
 {
   unsigned int SPIRBF:1;
   unsigned int SPITBF:1;
   unsigned int :4;
   unsigned int SPIROV:1;
   unsigned int :6;
   unsigned int SPISIDL:1;
   unsigned int :1;
   unsigned int SPIEN:1;
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
   unsigned int :1;
   unsigned int FRMDLY:1;
   unsigned int :11;
   unsigned int FRMPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI2CON2BITS;
SPI2CON2BITS SPI2CON2bits;
#word SPI2CON2bits = 0x264
#word SPI2CON2 = 0x264

#word SPI2BUF = 0x268

typedef union 
 {
      struct {
         unsigned int COFSM0:2;
         unsigned int :3;
         unsigned int DJST:1;
         unsigned int CSDOM:1;
         unsigned int UNFM:1;
         unsigned int COFSD:1;
         unsigned int CSCKE:1;
         unsigned int CSCKD:1;
         unsigned int DLOOP:1;
         unsigned int :1;
         unsigned int DCISIDL:1;
         unsigned int :1;
         unsigned int DCIEN:1;
      };
      struct {
         unsigned int COFSM:2;
         unsigned int :3;
      };
} DCICON1BITS;
DCICON1BITS DCICON1bits;
#word DCICON1bits = 0x280
#word DCICON1 = 0x280

typedef union 
 {
      struct {
         unsigned int WS0:4;
         unsigned int :1;
         unsigned int COFSG0:4;
         unsigned int :1;
         unsigned int BLEN0:2;
      };
      struct {
         unsigned int WS:4;
         unsigned int :1;
         unsigned int COFSG:4;
         unsigned int :1;
         unsigned int BLEN:2;
      };
} DCICON2BITS;
DCICON2BITS DCICON2bits;
#word DCICON2bits = 0x282
#word DCICON2 = 0x282

#word DCICON3 = 0x284

typedef union 
 {
      struct {
         unsigned int TMPTY:1;
         unsigned int TUNF:1;
         unsigned int RFUL:1;
         unsigned int ROV:1;
         unsigned int :4;
         unsigned int SLOT0:4;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :4;
         unsigned int SLOT:4;
      };
} DCISTATBITS;
DCISTATBITS DCISTATbits;
#word DCISTATbits = 0x286
#word DCISTAT = 0x286

typedef union 
 {
      struct {
         unsigned int TSE0:16;
      };
      struct {
         unsigned int TSE:16;
      };
} TSCONBITS;
TSCONBITS TSCONbits;
#word TSCONbits = 0x288
#word TSCON = 0x288

typedef union 
 {
      struct {
         unsigned int RSE0:16;
      };
      struct {
         unsigned int RSE:16;
      };
} RSCONBITS;
RSCONBITS RSCONbits;
#word RSCONbits = 0x28C
#word RSCON = 0x28C

#word RXBUF0 = 0x290

#word RXBUF1 = 0x292

#word RXBUF2 = 0x294

#word RXBUF3 = 0x296

#word TXBUF0 = 0x298

#word TXBUF1 = 0x29A

#word TXBUF2 = 0x29C

#word TXBUF3 = 0x29E

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
#word TRISBbits = 0x2C6
#word TRISB = 0x2C6

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
#word PORTBbits = 0x2C8
#word PORTB = 0x2C8

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
#word LATBbits = 0x2CA
#word LATB = 0x2CA

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
#word TRISCbits = 0x2CC
#word TRISC = 0x2CC

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
#word PORTCbits = 0x2CE
#word PORTC = 0x2CE

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
#word LATCbits = 0x2D0
#word LATC = 0x2D0

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
#word TRISDbits = 0x2D2
#word TRISD = 0x2D2

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
#word PORTDbits = 0x2D4
#word PORTD = 0x2D4

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
#word LATDbits = 0x2D6
#word LATD = 0x2D6

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
#word TRISFbits = 0x2DE
#word TRISF = 0x2DE

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
#word PORTFbits = 0x2E0
#word PORTF = 0x2E0

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
#word LATFbits = 0x2E2
#word LATF = 0x2E2

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
#word TRISGbits = 0x2E4
#word TRISG = 0x2E4

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
#word PORTGbits = 0x2E6
#word PORTG = 0x2E6

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
#word LATGbits = 0x2E8
#word LATG = 0x2E8

#word ADC1BUF0 = 0x300

typedef union 
 {
      struct {
         unsigned int DONE:1;
         unsigned int SAMP:1;
         unsigned int ASAM:1;
         unsigned int SIMSAM:1;
         unsigned int :1;
         unsigned int SSRC0:3;
         unsigned int FORM0:2;
         unsigned int AD12B:1;
         unsigned int :1;
         unsigned int ADDMABM:1;
         unsigned int ADSIDL:1;
         unsigned int :1;
         unsigned int ADON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SSRC:3;
         unsigned int FORM:2;
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
         unsigned int SMPI0:4;
         unsigned int :1;
         unsigned int BUFS:1;
         unsigned int CHPS0:2;
         unsigned int CSCNA:1;
         unsigned int :2;
         unsigned int VCFG0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SMPI:4;
         unsigned int :1;
         unsigned int :1;
         unsigned int CHPS:2;
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
         unsigned int CH123SA:1;
         unsigned int CH123NA0:2;
         unsigned int :5;
         unsigned int CH123SB:1;
         unsigned int CH123NB0:2;
      };
      struct {
         unsigned int :1;
         unsigned int CH123NA:2;
         unsigned int :5;
         unsigned int :1;
         unsigned int CH123NB:2;
      };
} AD1CHS123BITS;
AD1CHS123BITS AD1CHS123bits;
#word AD1CHS123bits = 0x326
#word AD1CHS123 = 0x326

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
} AD1CHS0BITS;
AD1CHS0BITS AD1CHS0bits;
#word AD1CHS0bits = 0x328
#word AD1CHS0 = 0x328

typedef struct 
 {
   unsigned int PCFG16:2;
} AD1PCFGHBITS;
AD1PCFGHBITS AD1PCFGHbits;
#word AD1PCFGHbits = 0x32A
#word AD1PCFGH = 0x32A

typedef union 
 {
      struct {
         unsigned int PCFG0:16;
      };
      struct {
         unsigned int PCFG:16;
      };
} AD1PCFGLBITS;
AD1PCFGLBITS AD1PCFGLbits;
#word AD1PCFGLbits = 0x32C
#word AD1PCFGL = 0x32C

typedef struct 
 {
   unsigned int CSS16:2;
} AD1CSSHBITS;
AD1CSSHBITS AD1CSSHbits;
#word AD1CSSHbits = 0x32E
#word AD1CSSH = 0x32E

typedef union 
 {
      struct {
         unsigned int CSS0:16;
      };
      struct {
         unsigned int CSS:16;
      };
} AD1CSSLBITS;
AD1CSSLBITS AD1CSSLbits;
#word AD1CSSLbits = 0x330
#word AD1CSSL = 0x330

#word AD1CON4 = 0x332

#word ADC2BUF0 = 0x340

typedef union 
 {
      struct {
         unsigned int DONE:1;
         unsigned int SAMP:1;
         unsigned int ASAM:1;
         unsigned int SIMSAM:1;
         unsigned int :1;
         unsigned int SSRC0:3;
         unsigned int FORM0:2;
         unsigned int AD12B:1;
         unsigned int :1;
         unsigned int ADDMABM:1;
         unsigned int ADSIDL:1;
         unsigned int :1;
         unsigned int ADON:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SSRC:3;
         unsigned int FORM:2;
      };
} AD2CON1BITS;
AD2CON1BITS AD2CON1bits;
#word AD2CON1bits = 0x360
#word AD2CON1 = 0x360

typedef union 
 {
      struct {
         unsigned int ALTS:1;
         unsigned int BUFM:1;
         unsigned int SMPI0:4;
         unsigned int :1;
         unsigned int BUFS:1;
         unsigned int CHPS0:2;
         unsigned int CSCNA:1;
         unsigned int :2;
         unsigned int VCFG0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SMPI:4;
         unsigned int :1;
         unsigned int :1;
         unsigned int CHPS:2;
         unsigned int :1;
         unsigned int :2;
         unsigned int VCFG:3;
      };
} AD2CON2BITS;
AD2CON2BITS AD2CON2bits;
#word AD2CON2bits = 0x362
#word AD2CON2 = 0x362

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
} AD2CON3BITS;
AD2CON3BITS AD2CON3bits;
#word AD2CON3bits = 0x364
#word AD2CON3 = 0x364

typedef union 
 {
      struct {
         unsigned int CH123SA:1;
         unsigned int CH123NA0:2;
         unsigned int :5;
         unsigned int CH123SB:1;
         unsigned int CH123NB0:2;
      };
      struct {
         unsigned int :1;
         unsigned int CH123NA:2;
         unsigned int :5;
         unsigned int :1;
         unsigned int CH123NB:2;
      };
} AD2CHS123BITS;
AD2CHS123BITS AD2CHS123bits;
#word AD2CHS123bits = 0x366
#word AD2CHS123 = 0x366

typedef union 
 {
      struct {
         unsigned int CH0SA0:4;
         unsigned int :3;
         unsigned int CH0NA:1;
         unsigned int CH0SB0:4;
         unsigned int :3;
         unsigned int CH0NB:1;
      };
      struct {
         unsigned int CH0SA:4;
         unsigned int :3;
         unsigned int :1;
         unsigned int CH0SB:4;
         unsigned int :3;
      };
} AD2CHS0BITS;
AD2CHS0BITS AD2CHS0bits;
#word AD2CHS0bits = 0x368
#word AD2CHS0 = 0x368

typedef union 
 {
      struct {
         unsigned int PCFG0:16;
      };
      struct {
         unsigned int PCFG:16;
      };
} AD2PCFGLBITS;
AD2PCFGLBITS AD2PCFGLbits;
#word AD2PCFGLbits = 0x36C
#word AD2PCFGL = 0x36C

typedef union 
 {
      struct {
         unsigned int CSS0:16;
      };
      struct {
         unsigned int CSS:16;
      };
} AD2CSSLBITS;
AD2CSSLBITS AD2CSSLbits;
#word AD2CSSLbits = 0x370
#word AD2CSSL = 0x370

#word AD2CON4 = 0x372

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA0CONBITS;
DMA0CONBITS DMA0CONbits;
#word DMA0CONbits = 0x380
#word DMA0CON = 0x380

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA0REQBITS;
DMA0REQBITS DMA0REQbits;
#word DMA0REQbits = 0x382
#word DMA0REQ = 0x382

#word DMA0STA = 0x384

#word DMA0STB = 0x386

#word DMA0PAD = 0x388

#word DMA0CNT = 0x38A

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA1CONBITS;
DMA1CONBITS DMA1CONbits;
#word DMA1CONbits = 0x38C
#word DMA1CON = 0x38C

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA1REQBITS;
DMA1REQBITS DMA1REQbits;
#word DMA1REQbits = 0x38E
#word DMA1REQ = 0x38E

#word DMA1STA = 0x390

#word DMA1STB = 0x392

#word DMA1PAD = 0x394

#word DMA1CNT = 0x396

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA2CONBITS;
DMA2CONBITS DMA2CONbits;
#word DMA2CONbits = 0x398
#word DMA2CON = 0x398

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA2REQBITS;
DMA2REQBITS DMA2REQbits;
#word DMA2REQbits = 0x39A
#word DMA2REQ = 0x39A

#word DMA2STA = 0x39C

#word DMA2STB = 0x39E

#word DMA2PAD = 0x3A0

#word DMA2CNT = 0x3A2

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA3CONBITS;
DMA3CONBITS DMA3CONbits;
#word DMA3CONbits = 0x3A4
#word DMA3CON = 0x3A4

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA3REQBITS;
DMA3REQBITS DMA3REQbits;
#word DMA3REQbits = 0x3A6
#word DMA3REQ = 0x3A6

#word DMA3STA = 0x3A8

#word DMA3STB = 0x3AA

#word DMA3PAD = 0x3AC

#word DMA3CNT = 0x3AE

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA4CONBITS;
DMA4CONBITS DMA4CONbits;
#word DMA4CONbits = 0x3B0
#word DMA4CON = 0x3B0

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA4REQBITS;
DMA4REQBITS DMA4REQbits;
#word DMA4REQbits = 0x3B2
#word DMA4REQ = 0x3B2

#word DMA4STA = 0x3B4

#word DMA4STB = 0x3B6

#word DMA4PAD = 0x3B8

#word DMA4CNT = 0x3BA

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA5CONBITS;
DMA5CONBITS DMA5CONbits;
#word DMA5CONbits = 0x3BC
#word DMA5CON = 0x3BC

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA5REQBITS;
DMA5REQBITS DMA5REQbits;
#word DMA5REQbits = 0x3BE
#word DMA5REQ = 0x3BE

#word DMA5STA = 0x3C0

#word DMA5STB = 0x3C2

#word DMA5PAD = 0x3C4

#word DMA5CNT = 0x3C6

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA6CONBITS;
DMA6CONBITS DMA6CONbits;
#word DMA6CONbits = 0x3C8
#word DMA6CON = 0x3C8

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA6REQBITS;
DMA6REQBITS DMA6REQbits;
#word DMA6REQbits = 0x3CA
#word DMA6REQ = 0x3CA

#word DMA6STA = 0x3CC

#word DMA6STB = 0x3CE

#word DMA6PAD = 0x3D0

#word DMA6CNT = 0x3D2

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int :2;
         unsigned int AMODE0:2;
         unsigned int :5;
         unsigned int NULLW:1;
         unsigned int HALF:1;
         unsigned int DIR:1;
         unsigned int SIZE:1;
         unsigned int CHEN:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :2;
         unsigned int AMODE:2;
         unsigned int :5;
      };
} DMA7CONBITS;
DMA7CONBITS DMA7CONbits;
#word DMA7CONbits = 0x3D4
#word DMA7CON = 0x3D4

typedef union 
 {
      struct {
         unsigned int IRQSEL0:7;
         unsigned int :8;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:7;
         unsigned int :8;
      };
} DMA7REQBITS;
DMA7REQBITS DMA7REQbits;
#word DMA7REQbits = 0x3D6
#word DMA7REQ = 0x3D6

#word DMA7STA = 0x3D8

#word DMA7STB = 0x3DA

#word DMA7PAD = 0x3DC

#word DMA7CNT = 0x3DE

typedef union 
 {
      struct {
         unsigned int XWCOL0:8;
         unsigned int PWCOL0:8;
      };
      struct {
         unsigned int XWCOL:8;
         unsigned int PWCOL:8;
      };
} DMACS0BITS;
DMACS0BITS DMACS0bits;
#word DMACS0bits = 0x3E0
#word DMACS0 = 0x3E0

typedef union 
 {
      struct {
         unsigned int PPST0:8;
         unsigned int LSTCH0:4;
      };
      struct {
         unsigned int PPST:8;
         unsigned int LSTCH:4;
      };
} DMACS1BITS;
DMACS1BITS DMACS1bits;
#word DMACS1bits = 0x3E2
#word DMACS1 = 0x3E2

#word DSADR = 0x3E4

typedef union 
 {
      struct {
         unsigned int WIN:1;
         unsigned int :2;
         unsigned int CANCAP:1;
         unsigned int :1;
         unsigned int OPMODE0:3;
         unsigned int REQOP0:3;
         unsigned int CANCKS:1;
         unsigned int ABAT:1;
         unsigned int CSIDL:1;
      };
      struct {
         unsigned int :1;
         unsigned int :2;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
         unsigned int REQOP:3;
      };
} C1CTRL1BITS;
C1CTRL1BITS C1CTRL1bits;
#word C1CTRL1bits = 0x400
#word C1CTRL1 = 0x400

#word C1CTRL2 = 0x402

typedef union 
 {
      struct {
         unsigned int ICODE0:7;
         unsigned int :1;
         unsigned int FILHIT0:5;
      };
      struct {
         unsigned int ICODE:7;
         unsigned int :1;
         unsigned int FILHIT:5;
      };
} C1VECBITS;
C1VECBITS C1VECbits;
#word C1VECbits = 0x404
#word C1VEC = 0x404

typedef union 
 {
      struct {
         unsigned int FSA0:5;
         unsigned int :8;
         unsigned int DMABS0:3;
      };
      struct {
         unsigned int FSA:5;
         unsigned int :8;
         unsigned int DMABS:3;
      };
} C1FCTRLBITS;
C1FCTRLBITS C1FCTRLbits;
#word C1FCTRLbits = 0x406
#word C1FCTRL = 0x406

typedef union 
 {
      struct {
         unsigned int FNRB0:6;
         unsigned int :2;
         unsigned int FBP0:6;
      };
      struct {
         unsigned int FNRB:6;
         unsigned int :2;
         unsigned int FBP:6;
      };
} C1FIFOBITS;
C1FIFOBITS C1FIFObits;
#word C1FIFObits = 0x408
#word C1FIFO = 0x408

typedef struct 
 {
   unsigned int TBIF:1;
   unsigned int RBIF:1;
   unsigned int RBOVIF:1;
   unsigned int FIFOIF:1;
   unsigned int :1;
   unsigned int ERRIF:1;
   unsigned int WAKIF:1;
   unsigned int IVRIF:1;
   unsigned int EWARN:1;
   unsigned int RXWAR:1;
   unsigned int TXWAR:1;
   unsigned int RXBP:1;
   unsigned int TXBP:1;
   unsigned int TXBO:1;
} C1INTFBITS;
C1INTFBITS C1INTFbits;
#word C1INTFbits = 0x40A
#word C1INTF = 0x40A

typedef struct 
 {
   unsigned int TBIE:1;
   unsigned int RBIE:1;
   unsigned int RBOVIE:1;
   unsigned int FIFOIE:1;
   unsigned int :1;
   unsigned int ERRIE:1;
   unsigned int WAKIE:1;
   unsigned int IVRIE:1;
} C1INTEBITS;
C1INTEBITS C1INTEbits;
#word C1INTEbits = 0x40C
#word C1INTE = 0x40C

typedef union 
 {
      struct {
         unsigned int RERRCNT0:8;
         unsigned int TERRCNT0:8;
      };
      struct {
         unsigned int RERRCNT:8;
         unsigned int TERRCNT:8;
      };
} C1ECBITS;
C1ECBITS C1ECbits;
#word C1ECbits = 0x40E
#word C1EC = 0x40E

typedef union 
 {
      struct {
         unsigned int BRP0:6;
         unsigned int SJW0:2;
      };
      struct {
         unsigned int BRP:6;
         unsigned int SJW:2;
      };
} C1CFG1BITS;
C1CFG1BITS C1CFG1bits;
#word C1CFG1bits = 0x410
#word C1CFG1 = 0x410

typedef union 
 {
      struct {
         unsigned int PRSEG0:3;
         unsigned int SEG1PH0:3;
         unsigned int SAM:1;
         unsigned int SEG2PHTS:1;
         unsigned int SEG2PH0:3;
         unsigned int :3;
         unsigned int WAKFIL:1;
      };
      struct {
         unsigned int PRSEG:3;
         unsigned int SEG1PH:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int SEG2PH:3;
         unsigned int :3;
      };
} C1CFG2BITS;
C1CFG2BITS C1CFG2bits;
#word C1CFG2bits = 0x412
#word C1CFG2 = 0x412

typedef union 
 {
      struct {
         unsigned int FLTEN0:16;
      };
      struct {
         unsigned int FLTEN:16;
      };
} C1FEN1BITS;
C1FEN1BITS C1FEN1bits;
#word C1FEN1bits = 0x414
#word C1FEN1 = 0x414

typedef union 
 {
      struct {
         unsigned int F0MSK0:2;
         unsigned int F1MSK0:2;
         unsigned int F2MSK0:2;
         unsigned int F3MSK0:2;
         unsigned int F4MSK0:2;
         unsigned int F5MSK0:2;
         unsigned int F6MSK0:2;
         unsigned int F7MSK0:2;
      };
      struct {
         unsigned int F0MSK:2;
         unsigned int F1MSK:2;
         unsigned int F2MSK:2;
         unsigned int F3MSK:2;
         unsigned int F4MSK:2;
         unsigned int F5MSK:2;
         unsigned int F6MSK:2;
         unsigned int F7MSK:2;
      };
} C1FMSKSEL1BITS;
C1FMSKSEL1BITS C1FMSKSEL1bits;
#word C1FMSKSEL1bits = 0x418
#word C1FMSKSEL1 = 0x418

typedef union 
 {
      struct {
         unsigned int F8MSK0:2;
         unsigned int F9MSK0:2;
         unsigned int F10MSK0:2;
         unsigned int F11MSK0:2;
         unsigned int F12MSK0:2;
         unsigned int F13MSK0:2;
         unsigned int F14MSK0:2;
         unsigned int F15MSK0:2;
      };
      struct {
         unsigned int F8MSK:2;
         unsigned int F9MSK:2;
         unsigned int F10MSK:2;
         unsigned int F11MSK:2;
         unsigned int F12MSK:2;
         unsigned int F13MSK:2;
         unsigned int F14MSK:2;
         unsigned int F15MSK:2;
      };
} C1FMSKSEL2BITS;
C1FMSKSEL2BITS C1FMSKSEL2bits;
#word C1FMSKSEL2bits = 0x41A
#word C1FMSKSEL2 = 0x41A

typedef union 
 {
      struct {
         unsigned int RXFUL0:16;
      };
      struct {
         unsigned int RXFUL:16;
      };
} C1RXFUL1BITS;
C1RXFUL1BITS C1RXFUL1bits;
#word C1RXFUL1bits = 0x420
#word C1RXFUL1 = 0x420

typedef union 
 {
      struct {
         unsigned int F0BP0:4;
         unsigned int F1BP0:4;
         unsigned int F2BP0:4;
         unsigned int F3BP0:4;
      };
      struct {
         unsigned int F0BP:4;
         unsigned int F1BP:4;
         unsigned int F2BP:4;
         unsigned int F3BP:4;
      };
} C1BUFPNT1BITS;
C1BUFPNT1BITS C1BUFPNT1bits;
#word C1BUFPNT1bits = 0x420
#word C1BUFPNT1 = 0x420

typedef struct 
 {
   unsigned int RXFUL16:4;
   unsigned int RXFUL20:10;
   unsigned int RXFUL30:2;
} C1RXFUL2BITS;
C1RXFUL2BITS C1RXFUL2bits;
#word C1RXFUL2bits = 0x422
#word C1RXFUL2 = 0x422

typedef union 
 {
      struct {
         unsigned int F4BP0:4;
         unsigned int F5BP0:4;
         unsigned int F6BP0:4;
         unsigned int F7BP0:4;
      };
      struct {
         unsigned int F4BP:4;
         unsigned int F5BP:4;
         unsigned int F6BP:4;
         unsigned int F7BP:4;
      };
} C1BUFPNT2BITS;
C1BUFPNT2BITS C1BUFPNT2bits;
#word C1BUFPNT2bits = 0x422
#word C1BUFPNT2 = 0x422

typedef union 
 {
      struct {
         unsigned int F8BP0:4;
         unsigned int F9BP0:4;
         unsigned int F10BP0:4;
         unsigned int F11BP0:4;
      };
      struct {
         unsigned int F8BP:4;
         unsigned int F9BP:4;
         unsigned int F10BP:4;
         unsigned int F11BP:4;
      };
} C1BUFPNT3BITS;
C1BUFPNT3BITS C1BUFPNT3bits;
#word C1BUFPNT3bits = 0x424
#word C1BUFPNT3 = 0x424

typedef union 
 {
      struct {
         unsigned int F12BP0:4;
         unsigned int F13BP0:4;
         unsigned int F14BP0:4;
         unsigned int F15BP0:4;
      };
      struct {
         unsigned int F12BP:4;
         unsigned int F13BP:4;
         unsigned int F14BP:4;
         unsigned int F15BP:4;
      };
} C1BUFPNT4BITS;
C1BUFPNT4BITS C1BUFPNT4bits;
#word C1BUFPNT4bits = 0x426
#word C1BUFPNT4 = 0x426

typedef union 
 {
      struct {
         unsigned int RXOVF0:16;
      };
      struct {
         unsigned int RXOVF:16;
      };
} C1RXOVF1BITS;
C1RXOVF1BITS C1RXOVF1bits;
#word C1RXOVF1bits = 0x428
#word C1RXOVF1 = 0x428

typedef struct 
 {
   unsigned int RXOVF16:4;
   unsigned int RXOVF20:10;
   unsigned int RXOVF30:2;
} C1RXOVF2BITS;
C1RXOVF2BITS C1RXOVF2bits;
#word C1RXOVF2bits = 0x42A
#word C1RXOVF2 = 0x42A

typedef union 
 {
      struct {
         unsigned int TX0PRI0:2;
         unsigned int RTREN0:1;
         unsigned int TXREQ0:1;
         unsigned int TXERR0:1;
         unsigned int TXLARB0:1;
         unsigned int TXABT0:1;
         unsigned int TXEN0:1;
         unsigned int TX1PRI0:2;
         unsigned int RTREN1:1;
         unsigned int TXREQ1:1;
         unsigned int TXERR1:1;
         unsigned int TXLARB1:1;
         unsigned int TXABT1:1;
         unsigned int TXEN1:1;
      };
      struct {
         unsigned int TX0PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX1PRI:2;
      };
} C1TR01CONBITS;
C1TR01CONBITS C1TR01CONbits;
#word C1TR01CONbits = 0x430
#word C1TR01CON = 0x430

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXM0SIDBITS;
C1RXM0SIDBITS C1RXM0SIDbits;
#word C1RXM0SIDbits = 0x430
#word C1RXM0SID = 0x430

typedef union 
 {
      struct {
         unsigned int TX2PRI0:2;
         unsigned int RTREN2:1;
         unsigned int TXREQ2:1;
         unsigned int TXERR2:1;
         unsigned int TXLARB2:1;
         unsigned int TXABT2:1;
         unsigned int TXEN2:1;
         unsigned int TX3PRI0:2;
         unsigned int RTREN3:1;
         unsigned int TXREQ3:1;
         unsigned int TXERR3:1;
         unsigned int TXLARB3:1;
         unsigned int TXABT3:1;
         unsigned int TXEN3:1;
      };
      struct {
         unsigned int TX2PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX3PRI:2;
      };
} C1TR23CONBITS;
C1TR23CONBITS C1TR23CONbits;
#word C1TR23CONbits = 0x432
#word C1TR23CON = 0x432

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXM0EIDBITS;
C1RXM0EIDBITS C1RXM0EIDbits;
#word C1RXM0EIDbits = 0x432
#word C1RXM0EID = 0x432

typedef union 
 {
      struct {
         unsigned int TX4PRI0:2;
         unsigned int RTREN4:1;
         unsigned int TXREQ4:1;
         unsigned int TXERR4:1;
         unsigned int TXLARB4:1;
         unsigned int TXABT4:1;
         unsigned int TXEN4:1;
         unsigned int TX5PRI0:2;
         unsigned int RTREN5:1;
         unsigned int TXREQ5:1;
         unsigned int TXERR5:1;
         unsigned int TXLARB5:1;
         unsigned int TXABT5:1;
         unsigned int TXEN5:1;
      };
      struct {
         unsigned int TX4PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX5PRI:2;
      };
} C1TR45CONBITS;
C1TR45CONBITS C1TR45CONbits;
#word C1TR45CONbits = 0x434
#word C1TR45CON = 0x434

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXM1SIDBITS;
C1RXM1SIDBITS C1RXM1SIDbits;
#word C1RXM1SIDbits = 0x434
#word C1RXM1SID = 0x434

typedef union 
 {
      struct {
         unsigned int TX6PRI0:2;
         unsigned int RTREN6:1;
         unsigned int TXREQ6:1;
         unsigned int TXERR6:1;
         unsigned int TXLARB6:1;
         unsigned int TXABT6:1;
         unsigned int TXEN6:1;
         unsigned int TX7PRI0:2;
         unsigned int RTREN7:1;
         unsigned int TXREQ7:1;
         unsigned int TXERR7:1;
         unsigned int TXLARB7:1;
         unsigned int TXABT7:1;
         unsigned int TXEN7:1;
      };
      struct {
         unsigned int TX6PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX7PRI:2;
      };
} C1TR67CONBITS;
C1TR67CONBITS C1TR67CONbits;
#word C1TR67CONbits = 0x436
#word C1TR67CON = 0x436

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXM1EIDBITS;
C1RXM1EIDBITS C1RXM1EIDbits;
#word C1RXM1EIDbits = 0x436
#word C1RXM1EID = 0x436

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXM2SIDBITS;
C1RXM2SIDBITS C1RXM2SIDbits;
#word C1RXM2SIDbits = 0x438
#word C1RXM2SID = 0x438

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXM2EIDBITS;
C1RXM2EIDBITS C1RXM2EIDbits;
#word C1RXM2EIDbits = 0x43A
#word C1RXM2EID = 0x43A

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF0SIDBITS;
C1RXF0SIDBITS C1RXF0SIDbits;
#word C1RXF0SIDbits = 0x440
#word C1RXF0SID = 0x440

#word C1RXD = 0x440

#word C1TXD = 0x442

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF0EIDBITS;
C1RXF0EIDBITS C1RXF0EIDbits;
#word C1RXF0EIDbits = 0x442
#word C1RXF0EID = 0x442

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF1SIDBITS;
C1RXF1SIDBITS C1RXF1SIDbits;
#word C1RXF1SIDbits = 0x444
#word C1RXF1SID = 0x444

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF1EIDBITS;
C1RXF1EIDBITS C1RXF1EIDbits;
#word C1RXF1EIDbits = 0x446
#word C1RXF1EID = 0x446

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF2SIDBITS;
C1RXF2SIDBITS C1RXF2SIDbits;
#word C1RXF2SIDbits = 0x448
#word C1RXF2SID = 0x448

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF2EIDBITS;
C1RXF2EIDBITS C1RXF2EIDbits;
#word C1RXF2EIDbits = 0x44A
#word C1RXF2EID = 0x44A

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF3SIDBITS;
C1RXF3SIDBITS C1RXF3SIDbits;
#word C1RXF3SIDbits = 0x44C
#word C1RXF3SID = 0x44C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF3EIDBITS;
C1RXF3EIDBITS C1RXF3EIDbits;
#word C1RXF3EIDbits = 0x44E
#word C1RXF3EID = 0x44E

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF4SIDBITS;
C1RXF4SIDBITS C1RXF4SIDbits;
#word C1RXF4SIDbits = 0x450
#word C1RXF4SID = 0x450

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF4EIDBITS;
C1RXF4EIDBITS C1RXF4EIDbits;
#word C1RXF4EIDbits = 0x452
#word C1RXF4EID = 0x452

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF5SIDBITS;
C1RXF5SIDBITS C1RXF5SIDbits;
#word C1RXF5SIDbits = 0x454
#word C1RXF5SID = 0x454

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF5EIDBITS;
C1RXF5EIDBITS C1RXF5EIDbits;
#word C1RXF5EIDbits = 0x456
#word C1RXF5EID = 0x456

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF6SIDBITS;
C1RXF6SIDBITS C1RXF6SIDbits;
#word C1RXF6SIDbits = 0x458
#word C1RXF6SID = 0x458

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF6EIDBITS;
C1RXF6EIDBITS C1RXF6EIDbits;
#word C1RXF6EIDbits = 0x45A
#word C1RXF6EID = 0x45A

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF7SIDBITS;
C1RXF7SIDBITS C1RXF7SIDbits;
#word C1RXF7SIDbits = 0x45C
#word C1RXF7SID = 0x45C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF7EIDBITS;
C1RXF7EIDBITS C1RXF7EIDbits;
#word C1RXF7EIDbits = 0x45E
#word C1RXF7EID = 0x45E

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF8SIDBITS;
C1RXF8SIDBITS C1RXF8SIDbits;
#word C1RXF8SIDbits = 0x460
#word C1RXF8SID = 0x460

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF8EIDBITS;
C1RXF8EIDBITS C1RXF8EIDbits;
#word C1RXF8EIDbits = 0x462
#word C1RXF8EID = 0x462

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF9SIDBITS;
C1RXF9SIDBITS C1RXF9SIDbits;
#word C1RXF9SIDbits = 0x464
#word C1RXF9SID = 0x464

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF9EIDBITS;
C1RXF9EIDBITS C1RXF9EIDbits;
#word C1RXF9EIDbits = 0x466
#word C1RXF9EID = 0x466

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF10SIDBITS;
C1RXF10SIDBITS C1RXF10SIDbits;
#word C1RXF10SIDbits = 0x468
#word C1RXF10SID = 0x468

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF10EIDBITS;
C1RXF10EIDBITS C1RXF10EIDbits;
#word C1RXF10EIDbits = 0x46A
#word C1RXF10EID = 0x46A

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF11SIDBITS;
C1RXF11SIDBITS C1RXF11SIDbits;
#word C1RXF11SIDbits = 0x46C
#word C1RXF11SID = 0x46C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF11EIDBITS;
C1RXF11EIDBITS C1RXF11EIDbits;
#word C1RXF11EIDbits = 0x46E
#word C1RXF11EID = 0x46E

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF12SIDBITS;
C1RXF12SIDBITS C1RXF12SIDbits;
#word C1RXF12SIDbits = 0x470
#word C1RXF12SID = 0x470

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF12EIDBITS;
C1RXF12EIDBITS C1RXF12EIDbits;
#word C1RXF12EIDbits = 0x472
#word C1RXF12EID = 0x472

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF13SIDBITS;
C1RXF13SIDBITS C1RXF13SIDbits;
#word C1RXF13SIDbits = 0x474
#word C1RXF13SID = 0x474

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF13EIDBITS;
C1RXF13EIDBITS C1RXF13EIDbits;
#word C1RXF13EIDbits = 0x476
#word C1RXF13EID = 0x476

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF14SIDBITS;
C1RXF14SIDBITS C1RXF14SIDbits;
#word C1RXF14SIDbits = 0x478
#word C1RXF14SID = 0x478

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF14EIDBITS;
C1RXF14EIDBITS C1RXF14EIDbits;
#word C1RXF14EIDbits = 0x47A
#word C1RXF14EID = 0x47A

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C1RXF15SIDBITS;
C1RXF15SIDBITS C1RXF15SIDbits;
#word C1RXF15SIDbits = 0x47C
#word C1RXF15SID = 0x47C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C1RXF15EIDBITS;
C1RXF15EIDBITS C1RXF15EIDbits;
#word C1RXF15EIDbits = 0x47E
#word C1RXF15EID = 0x47E

typedef union 
 {
   union {
      struct {
         unsigned int WIN:1;
         unsigned int :2;
         unsigned int CANCAP:1;
         unsigned int :1;
         unsigned int OPMODE0:3;
         unsigned int REQOP0:3;
         unsigned int CANCKS:1;
         unsigned int ABAT:1;
         unsigned int CSIDL:1;
      };
      struct {
         unsigned int :1;
         unsigned int :2;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
         unsigned int REQOP:3;
      };

      struct {
         unsigned int :13;
         unsigned int CANSIDL:1;
      };
   };
} C2CTRL1BITS;
C2CTRL1BITS C2CTRL1bits;
#word C2CTRL1bits = 0x500
#word C2CTRL1 = 0x500

#word C2CTRL2 = 0x502

typedef union 
 {
      struct {
         unsigned int ICODE0:7;
         unsigned int :1;
         unsigned int FILHIT0:5;
      };
      struct {
         unsigned int ICODE:7;
         unsigned int :1;
         unsigned int FILHIT:5;
      };
} C2VECBITS;
C2VECBITS C2VECbits;
#word C2VECbits = 0x504
#word C2VEC = 0x504

typedef union 
 {
      struct {
         unsigned int FSA0:5;
         unsigned int :8;
         unsigned int DMABS0:3;
      };
      struct {
         unsigned int FSA:5;
         unsigned int :8;
         unsigned int DMABS:3;
      };
} C2FCTRLBITS;
C2FCTRLBITS C2FCTRLbits;
#word C2FCTRLbits = 0x506
#word C2FCTRL = 0x506

typedef union 
 {
      struct {
         unsigned int FNRB0:6;
         unsigned int :2;
         unsigned int FBP0:6;
      };
      struct {
         unsigned int FNRB:6;
         unsigned int :2;
         unsigned int FBP:6;
      };
} C2FIFOBITS;
C2FIFOBITS C2FIFObits;
#word C2FIFObits = 0x508
#word C2FIFO = 0x508

typedef struct 
 {
   unsigned int TBIF:1;
   unsigned int RBIF:1;
   unsigned int RBOVIF:1;
   unsigned int FIFOIF:1;
   unsigned int :1;
   unsigned int ERRIF:1;
   unsigned int WAKIF:1;
   unsigned int IVRIF:1;
   unsigned int EWARN:1;
   unsigned int RXWARN:1;
   unsigned int TXWARN:1;
   unsigned int RXBP:1;
   unsigned int TXBP:1;
   unsigned int TXBO:1;
} C2INTFBITS;
C2INTFBITS C2INTFbits;
#word C2INTFbits = 0x50A
#word C2INTF = 0x50A

typedef struct 
 {
   unsigned int TBIE:1;
   unsigned int RBIE:1;
   unsigned int RBOVIE:1;
   unsigned int FIFOIE:1;
   unsigned int :1;
   unsigned int ERRIE:1;
   unsigned int WAKIE:1;
   unsigned int IVRIE:1;
} C2INTEBITS;
C2INTEBITS C2INTEbits;
#word C2INTEbits = 0x50C
#word C2INTE = 0x50C

typedef union 
 {
      struct {
         unsigned int RERRCNT0:8;
         unsigned int TERRCNT0:8;
      };
      struct {
         unsigned int RERRCNT:8;
         unsigned int TERRCNT:8;
      };
} C2ECBITS;
C2ECBITS C2ECbits;
#word C2ECbits = 0x50E
#word C2EC = 0x50E

typedef union 
 {
      struct {
         unsigned int BRP0:6;
         unsigned int SJW0:2;
      };
      struct {
         unsigned int BRP:6;
         unsigned int SJW:2;
      };
} C2CFG1BITS;
C2CFG1BITS C2CFG1bits;
#word C2CFG1bits = 0x510
#word C2CFG1 = 0x510

typedef union 
 {
      struct {
         unsigned int PRSEG0:3;
         unsigned int SEG1PH0:3;
         unsigned int SAM:1;
         unsigned int SEG2PHTS:1;
         unsigned int SEG2PH0:3;
         unsigned int :3;
         unsigned int WAKFIL:1;
      };
      struct {
         unsigned int PRSEG:3;
         unsigned int SEG1PH:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int SEG2PH:3;
         unsigned int :3;
      };
} C2CFG2BITS;
C2CFG2BITS C2CFG2bits;
#word C2CFG2bits = 0x512
#word C2CFG2 = 0x512

typedef union 
 {
      struct {
         unsigned int FLTEN0:16;
      };
      struct {
         unsigned int FLTEN:16;
      };
} C2FEN1BITS;
C2FEN1BITS C2FEN1bits;
#word C2FEN1bits = 0x514
#word C2FEN1 = 0x514

typedef union 
 {
      struct {
         unsigned int F0MSK0:2;
         unsigned int F1MSK0:2;
         unsigned int F2MSK0:2;
         unsigned int F3MSK0:2;
         unsigned int F4MSK0:2;
         unsigned int F5MSK0:2;
         unsigned int F6MSK0:2;
         unsigned int F7MSK0:2;
      };
      struct {
         unsigned int F0MSK:2;
         unsigned int F1MSK:2;
         unsigned int F2MSK:2;
         unsigned int F3MSK:2;
         unsigned int F4MSK:2;
         unsigned int F5MSK:2;
         unsigned int F6MSK:2;
         unsigned int F7MSK:2;
      };
} C2FMSKSEL1BITS;
C2FMSKSEL1BITS C2FMSKSEL1bits;
#word C2FMSKSEL1bits = 0x518
#word C2FMSKSEL1 = 0x518

typedef union 
 {
      struct {
         unsigned int F8MSK0:2;
         unsigned int F9MSK0:2;
         unsigned int F10MSK0:2;
         unsigned int F11MSK0:2;
         unsigned int F12MSK0:2;
         unsigned int F13MSK0:2;
         unsigned int F14MSK0:2;
         unsigned int F15MSK0:2;
      };
      struct {
         unsigned int F8MSK:2;
         unsigned int F9MSK:2;
         unsigned int F10MSK:2;
         unsigned int F11MSK:2;
         unsigned int F12MSK:2;
         unsigned int F13MSK:2;
         unsigned int F14MSK:2;
         unsigned int F15MSK:2;
      };
} C2FMSKSEL2BITS;
C2FMSKSEL2BITS C2FMSKSEL2bits;
#word C2FMSKSEL2bits = 0x51A
#word C2FMSKSEL2 = 0x51A

typedef union 
 {
      struct {
         unsigned int RXFUL0:16;
      };
      struct {
         unsigned int RXFUL:16;
      };
} C2RXFUL1BITS;
C2RXFUL1BITS C2RXFUL1bits;
#word C2RXFUL1bits = 0x520
#word C2RXFUL1 = 0x520

typedef union 
 {
      struct {
         unsigned int F0BP0:4;
         unsigned int F1BP0:4;
         unsigned int F2BP0:4;
         unsigned int F3BP0:4;
      };
      struct {
         unsigned int F0BP:4;
         unsigned int F1BP:4;
         unsigned int F2BP:4;
         unsigned int F3BP:4;
      };
} C2BUFPNT1BITS;
C2BUFPNT1BITS C2BUFPNT1bits;
#word C2BUFPNT1bits = 0x520
#word C2BUFPNT1 = 0x520

typedef struct 
 {
   unsigned int RXFUL16:4;
   unsigned int RXFUL20:10;
   unsigned int RXFUL30:2;
} C2RXFUL2BITS;
C2RXFUL2BITS C2RXFUL2bits;
#word C2RXFUL2bits = 0x522
#word C2RXFUL2 = 0x522

typedef union 
 {
      struct {
         unsigned int F4BP0:4;
         unsigned int F5BP0:4;
         unsigned int F6BP0:4;
         unsigned int F7BP0:4;
      };
      struct {
         unsigned int F4BP:4;
         unsigned int F5BP:4;
         unsigned int F6BP:4;
         unsigned int F7BP:4;
      };
} C2BUFPNT2BITS;
C2BUFPNT2BITS C2BUFPNT2bits;
#word C2BUFPNT2bits = 0x522
#word C2BUFPNT2 = 0x522

typedef union 
 {
      struct {
         unsigned int F8BP0:4;
         unsigned int F9BP0:4;
         unsigned int F10BP0:4;
         unsigned int F11BP0:4;
      };
      struct {
         unsigned int F8BP:4;
         unsigned int F9BP:4;
         unsigned int F10BP:4;
         unsigned int F11BP:4;
      };
} C2BUFPNT3BITS;
C2BUFPNT3BITS C2BUFPNT3bits;
#word C2BUFPNT3bits = 0x524
#word C2BUFPNT3 = 0x524

typedef union 
 {
      struct {
         unsigned int F12BP0:4;
         unsigned int F13BP0:4;
         unsigned int F14BP0:4;
         unsigned int F15BP0:4;
      };
      struct {
         unsigned int F12BP:4;
         unsigned int F13BP:4;
         unsigned int F14BP:4;
         unsigned int F15BP:4;
      };
} C2BUFPNT4BITS;
C2BUFPNT4BITS C2BUFPNT4bits;
#word C2BUFPNT4bits = 0x526
#word C2BUFPNT4 = 0x526

typedef union 
 {
      struct {
         unsigned int RXOVF0:16;
      };
      struct {
         unsigned int RXOVF:16;
      };
} C2RXOVF1BITS;
C2RXOVF1BITS C2RXOVF1bits;
#word C2RXOVF1bits = 0x528
#word C2RXOVF1 = 0x528

typedef struct 
 {
   unsigned int RXOVF16:4;
   unsigned int RXOVF20:10;
   unsigned int RXOVF30:2;
} C2RXOVF2BITS;
C2RXOVF2BITS C2RXOVF2bits;
#word C2RXOVF2bits = 0x52A
#word C2RXOVF2 = 0x52A

typedef union 
 {
      struct {
         unsigned int TX0PRI0:2;
         unsigned int RTREN0:1;
         unsigned int TXREQ0:1;
         unsigned int TXERR0:1;
         unsigned int TXLARB0:1;
         unsigned int TXABT0:1;
         unsigned int TXEN0:1;
         unsigned int TX1PRI0:2;
         unsigned int RTREN1:1;
         unsigned int TXREQ1:1;
         unsigned int TXERR1:1;
         unsigned int TXLARB1:1;
         unsigned int TXABT1:1;
         unsigned int TXEN1:1;
      };
      struct {
         unsigned int TX0PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX1PRI:2;
      };
} C2TR01CONBITS;
C2TR01CONBITS C2TR01CONbits;
#word C2TR01CONbits = 0x530
#word C2TR01CON = 0x530

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C2RXM0SIDBITS;
C2RXM0SIDBITS C2RXM0SIDbits;
#word C2RXM0SIDbits = 0x530
#word C2RXM0SID = 0x530

typedef union 
 {
      struct {
         unsigned int TX2PRI0:2;
         unsigned int RTREN2:1;
         unsigned int TXREQ2:1;
         unsigned int TXERR2:1;
         unsigned int TXLARB2:1;
         unsigned int TXABT2:1;
         unsigned int TXEN2:1;
         unsigned int TX3PRI0:2;
         unsigned int RTREN3:1;
         unsigned int TXREQ3:1;
         unsigned int TXERR3:1;
         unsigned int TXLARB3:1;
         unsigned int TXABT3:1;
         unsigned int TXEN3:1;
      };
      struct {
         unsigned int TX2PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX3PRI:2;
      };
} C2TR23CONBITS;
C2TR23CONBITS C2TR23CONbits;
#word C2TR23CONbits = 0x532
#word C2TR23CON = 0x532

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXM0EIDBITS;
C2RXM0EIDBITS C2RXM0EIDbits;
#word C2RXM0EIDbits = 0x532
#word C2RXM0EID = 0x532

typedef union 
 {
      struct {
         unsigned int TX4PRI0:2;
         unsigned int RTREN4:1;
         unsigned int TXREQ4:1;
         unsigned int TXERR4:1;
         unsigned int TXLARB4:1;
         unsigned int TXABT4:1;
         unsigned int TXEN4:1;
         unsigned int TX5PRI0:2;
         unsigned int RTREN5:1;
         unsigned int TXREQ5:1;
         unsigned int TXERR5:1;
         unsigned int TXLARB5:1;
         unsigned int TXABT5:1;
         unsigned int TXEN5:1;
      };
      struct {
         unsigned int TX4PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX5PRI:2;
      };
} C2TR45CONBITS;
C2TR45CONBITS C2TR45CONbits;
#word C2TR45CONbits = 0x534
#word C2TR45CON = 0x534

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C2RXM1SIDBITS;
C2RXM1SIDBITS C2RXM1SIDbits;
#word C2RXM1SIDbits = 0x534
#word C2RXM1SID = 0x534

typedef union 
 {
      struct {
         unsigned int TX6PRI0:2;
         unsigned int RTREN6:1;
         unsigned int TXREQ6:1;
         unsigned int TXERR6:1;
         unsigned int TXLARB6:1;
         unsigned int TXABT6:1;
         unsigned int TXEN6:1;
         unsigned int TX7PRI0:2;
         unsigned int RTREN7:1;
         unsigned int TXREQ7:1;
         unsigned int TXERR7:1;
         unsigned int TXLARB7:1;
         unsigned int TXABT7:1;
         unsigned int TXEN7:1;
      };
      struct {
         unsigned int TX6PRI:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int TX7PRI:2;
      };
} C2TR67CONBITS;
C2TR67CONBITS C2TR67CONbits;
#word C2TR67CONbits = 0x536
#word C2TR67CON = 0x536

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXM1EIDBITS;
C2RXM1EIDBITS C2RXM1EIDbits;
#word C2RXM1EIDbits = 0x536
#word C2RXM1EID = 0x536

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };

      struct {
         unsigned int EID0:2;
      };
   };
      struct {
         unsigned int EID:2;
      };
} C2RXM2SIDBITS;
C2RXM2SIDBITS C2RXM2SIDbits;
#word C2RXM2SIDbits = 0x538
#word C2RXM2SID = 0x538

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXM2EIDBITS;
C2RXM2EIDBITS C2RXM2EIDbits;
#word C2RXM2EIDbits = 0x53A
#word C2RXM2EID = 0x53A

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF0SIDBITS;
C2RXF0SIDBITS C2RXF0SIDbits;
#word C2RXF0SIDbits = 0x540
#word C2RXF0SID = 0x540

#word C2RXD = 0x540

#word C2TXD = 0x542

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF0EIDBITS;
C2RXF0EIDBITS C2RXF0EIDbits;
#word C2RXF0EIDbits = 0x542
#word C2RXF0EID = 0x542

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF1SIDBITS;
C2RXF1SIDBITS C2RXF1SIDbits;
#word C2RXF1SIDbits = 0x544
#word C2RXF1SID = 0x544

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF1EIDBITS;
C2RXF1EIDBITS C2RXF1EIDbits;
#word C2RXF1EIDbits = 0x546
#word C2RXF1EID = 0x546

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF2SIDBITS;
C2RXF2SIDBITS C2RXF2SIDbits;
#word C2RXF2SIDbits = 0x548
#word C2RXF2SID = 0x548

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF2EIDBITS;
C2RXF2EIDBITS C2RXF2EIDbits;
#word C2RXF2EIDbits = 0x54A
#word C2RXF2EID = 0x54A

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF3SIDBITS;
C2RXF3SIDBITS C2RXF3SIDbits;
#word C2RXF3SIDbits = 0x54C
#word C2RXF3SID = 0x54C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF3EIDBITS;
C2RXF3EIDBITS C2RXF3EIDbits;
#word C2RXF3EIDbits = 0x54E
#word C2RXF3EID = 0x54E

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF4SIDBITS;
C2RXF4SIDBITS C2RXF4SIDbits;
#word C2RXF4SIDbits = 0x550
#word C2RXF4SID = 0x550

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF4EIDBITS;
C2RXF4EIDBITS C2RXF4EIDbits;
#word C2RXF4EIDbits = 0x552
#word C2RXF4EID = 0x552

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF5SIDBITS;
C2RXF5SIDBITS C2RXF5SIDbits;
#word C2RXF5SIDbits = 0x554
#word C2RXF5SID = 0x554

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF5EIDBITS;
C2RXF5EIDBITS C2RXF5EIDbits;
#word C2RXF5EIDbits = 0x556
#word C2RXF5EID = 0x556

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF6SIDBITS;
C2RXF6SIDBITS C2RXF6SIDbits;
#word C2RXF6SIDbits = 0x558
#word C2RXF6SID = 0x558

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF6EIDBITS;
C2RXF6EIDBITS C2RXF6EIDbits;
#word C2RXF6EIDbits = 0x55A
#word C2RXF6EID = 0x55A

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF7SIDBITS;
C2RXF7SIDBITS C2RXF7SIDbits;
#word C2RXF7SIDbits = 0x55C
#word C2RXF7SID = 0x55C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF7EIDBITS;
C2RXF7EIDBITS C2RXF7EIDbits;
#word C2RXF7EIDbits = 0x55E
#word C2RXF7EID = 0x55E

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF8SIDBITS;
C2RXF8SIDBITS C2RXF8SIDbits;
#word C2RXF8SIDbits = 0x560
#word C2RXF8SID = 0x560

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF8EIDBITS;
C2RXF8EIDBITS C2RXF8EIDbits;
#word C2RXF8EIDbits = 0x562
#word C2RXF8EID = 0x562

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF9SIDBITS;
C2RXF9SIDBITS C2RXF9SIDbits;
#word C2RXF9SIDbits = 0x564
#word C2RXF9SID = 0x564

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF9EIDBITS;
C2RXF9EIDBITS C2RXF9EIDbits;
#word C2RXF9EIDbits = 0x566
#word C2RXF9EID = 0x566

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF10SIDBITS;
C2RXF10SIDBITS C2RXF10SIDbits;
#word C2RXF10SIDbits = 0x568
#word C2RXF10SID = 0x568

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF10EIDBITS;
C2RXF10EIDBITS C2RXF10EIDbits;
#word C2RXF10EIDbits = 0x56A
#word C2RXF10EID = 0x56A

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF11SIDBITS;
C2RXF11SIDBITS C2RXF11SIDbits;
#word C2RXF11SIDbits = 0x56C
#word C2RXF11SID = 0x56C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF11EIDBITS;
C2RXF11EIDBITS C2RXF11EIDbits;
#word C2RXF11EIDbits = 0x56E
#word C2RXF11EID = 0x56E

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF12SIDBITS;
C2RXF12SIDBITS C2RXF12SIDbits;
#word C2RXF12SIDbits = 0x570
#word C2RXF12SID = 0x570

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF12EIDBITS;
C2RXF12EIDBITS C2RXF12EIDbits;
#word C2RXF12EIDbits = 0x572
#word C2RXF12EID = 0x572

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF13SIDBITS;
C2RXF13SIDBITS C2RXF13SIDbits;
#word C2RXF13SIDbits = 0x574
#word C2RXF13SID = 0x574

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF13EIDBITS;
C2RXF13EIDBITS C2RXF13EIDbits;
#word C2RXF13EIDbits = 0x576
#word C2RXF13EID = 0x576

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF14SIDBITS;
C2RXF14SIDBITS C2RXF14SIDbits;
#word C2RXF14SIDbits = 0x578
#word C2RXF14SID = 0x578

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF14EIDBITS;
C2RXF14EIDBITS C2RXF14EIDbits;
#word C2RXF14EIDbits = 0x57A
#word C2RXF14EID = 0x57A

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
      };
} C2RXF15SIDBITS;
C2RXF15SIDBITS C2RXF15SIDbits;
#word C2RXF15SIDbits = 0x57C
#word C2RXF15SID = 0x57C

typedef union 
 {
      struct {
         unsigned int EID0:16;
      };
      struct {
         unsigned int EID:16;
      };
} C2RXF15EIDBITS;
C2RXF15EIDBITS C2RXF15EIDbits;
#word C2RXF15EIDbits = 0x57E
#word C2RXF15EID = 0x57E

typedef union 
 {
      struct {
         unsigned int ODCD0:12;
      };
      struct {
         unsigned int ODCD:12;
      };
} ODCDBITS;
ODCDBITS ODCDbits;
#word ODCDbits = 0x6D2
#word ODCD = 0x6D2

#word ODCF = 0x6DE

typedef union 
 {
      struct {
         unsigned int ODCG0:4;
         unsigned int :2;
         unsigned int ODCG6:4;
         unsigned int :2;
         unsigned int ODCG12:4;
      };
      struct {
         unsigned int ODCG:4;
         unsigned int :2;
         unsigned int ODCG:4;
         unsigned int :2;
         unsigned int ODCG:4;
      };
} ODCGBITS;
ODCGBITS ODCGbits;
#word ODCGbits = 0x6E4
#word ODCG = 0x6E4

typedef struct 
 {
   unsigned int POR:1;
   unsigned int BOR:1;
   unsigned int IDLE:1;
   unsigned int SLEEP:1;
   unsigned int WDTO:1;
   unsigned int SWDTEN:1;
   unsigned int SWR:1;
   unsigned int EXTR:1;
   unsigned int VREGS:1;
   unsigned int :5;
   unsigned int IOPUWR:1;
   unsigned int TRAPR:1;
} RCONBITS;
RCONBITS RCONbits;
#word RCONbits = 0x740
#word RCON = 0x740

typedef union 
 {
      struct {
         unsigned int OSWEN:1;
         unsigned int LPOSCEN:1;
         unsigned int :1;
         unsigned int CF:1;
         unsigned int :1;
         unsigned int LOCK:1;
         unsigned int :1;
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
} OSCCONBITS;
OSCCONBITS OSCCONbits;
#word OSCCONbits = 0x742
#word OSCCON = 0x742

typedef union 
 {
      struct {
         unsigned int PLLPRE0:5;
         unsigned int :1;
         unsigned int PLLPOST0:2;
         unsigned int FRCDIV0:3;
         unsigned int DOZEN:1;
         unsigned int DOZE0:3;
         unsigned int ROI:1;
      };
      struct {
         unsigned int PLLPRE:5;
         unsigned int :1;
         unsigned int PLLPOST:2;
         unsigned int FRCDIV:3;
         unsigned int :1;
         unsigned int DOZE:3;
      };
} CLKDIVBITS;
CLKDIVBITS CLKDIVbits;
#word CLKDIVbits = 0x744
#word CLKDIV = 0x744

typedef union 
 {
      struct {
         unsigned int PLLDIV0:9;
      };
      struct {
         unsigned int PLLDIV:9;
      };
} PLLFBDBITS;
PLLFBDBITS PLLFBDbits;
#word PLLFBDbits = 0x746
#word PLLFBD = 0x746

#word OSCTUN = 0x748

typedef struct 
 {
   unsigned int RL_BSR:1;
   unsigned int IR_BSR:1;
   unsigned int IW_BSR:1;
} BSRAMBITS;
BSRAMBITS BSRAMbits;
#word BSRAMbits = 0x750
#word BSRAM = 0x750

typedef struct 
 {
   unsigned int RL_SSR:1;
   unsigned int IR_SSR:1;
   unsigned int IW_SSR:1;
} SSRAMBITS;
SSRAMBITS SSRAMbits;
#word SSRAMbits = 0x752
#word SSRAM = 0x752

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
   unsigned int AD1MD:1;
   unsigned int C1MD:1;
   unsigned int C2MD:1;
   unsigned int SPI1MD:1;
   unsigned int SPI2MD:1;
   unsigned int U1MD:1;
   unsigned int U2MD:1;
   unsigned int I2C1MD:1;
   unsigned int DCIMD:1;
   unsigned int :2;
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
   unsigned int AD2MD:1;
   unsigned int I2C2MD:1;
   unsigned int :10;
   unsigned int T6MD:1;
   unsigned int T7MD:1;
   unsigned int T8MD:1;
   unsigned int T9MD:1;
} PMD3BITS;
PMD3BITS PMD3bits;
#word PMD3bits = 0x774
#word PMD3 = 0x774

