/////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2012 Custom Computer Services         ////
//// This source code may only be used by licensed users of the CCS  ////
//// C compiler.  This source code may only be distributed to other  ////
//// licensed users of the CCS C compiler.  No other use,            ////
//// reproduction or distribution is permitted without written       ////
//// permission.  Derivative programs created using this software    ////
//// in object code form are not restricted in any way.              ////
/////////////////////////////////////////////////////////////////////////

#byte TOSU = 0xFFF

#byte TOSH = 0xFFE

#byte TOSL = 0xFFD

typedef union 
 {
   union {
      struct {
         unsigned int SP0:5;
      };
      struct {
         unsigned int SP:5;
      };

   union {
      struct {
         unsigned int :7;
         unsigned int STKOVF:1;
      };
   };

      struct {
         unsigned int STKPTR0:5;
         unsigned int :1;
         unsigned int STKUNF:1;
         unsigned int STKFUL:1;
      };
   };
      struct {
         unsigned int STKPTR:5;
      };
} STKPTRBITS;
STKPTRBITS STKPTRbits;
#byte STKPTRbits = 0xFFC
#byte STKPTR = 0xFFC

#byte PCLATU = 0xFFB

#byte PCLATH = 0xFFA

#byte PCL = 0xFF9

typedef union 
 {
      struct {
         unsigned int TBLPTRU0:5;
         unsigned int ACSS:1;
      };
      struct {
         unsigned int TBLPTRU:5;
      };
} TBLPTRUBITS;
TBLPTRUBITS TBLPTRUbits;
#byte TBLPTRUbits = 0xFF8
#byte TBLPTRU = 0xFF8

#byte TBLPTRH = 0xFF7

#byte TBLPTRL = 0xFF6

#byte TABLAT = 0xFF5

#byte PRODH = 0xFF4

#byte PRODL = 0xFF3

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int INT0F:1;
         unsigned int T0IF:1;
         unsigned int :1;
         unsigned int INT0E:1;
         unsigned int T0IE:1;
         unsigned int GIEL:1;
         unsigned int GIEH:1;
      };

   union {
      struct {
         unsigned int :6;
         unsigned int PEIE:1;
         unsigned int GIE:1;
      };
   };

      struct {
         unsigned int RBIF:1;
         unsigned int INT0IF:1;
         unsigned int TMR0IF:1;
         unsigned int RBIE:1;
         unsigned int INT0IE:1;
         unsigned int TMR0IE:1;
         unsigned int PEIE_GIEL:1;
         unsigned int GIE_GIEH:1;
      };
   };
} INTCONBITS;
INTCONBITS INTCONbits;
#byte INTCONbits = 0xFF2
#byte INTCON = 0xFF2

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int INT3P:1;
         unsigned int T0IP:1;
      };

      struct {
         unsigned int RBIP:1;
         unsigned int INT3IP:1;
         unsigned int TMR0IP:1;
         unsigned int INTEDG3:1;
         unsigned int INTEDG2:1;
         unsigned int INTEDG1:1;
         unsigned int INTEDG0:1;
         unsigned int RBPU:1;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int INTEDG:4;
      };
} INTCON2BITS;
INTCON2BITS INTCON2bits;
#byte INTCON2bits = 0xFF1
#byte INTCON2 = 0xFF1

typedef struct 
 {
   union {
      struct {
         unsigned int INT1IF:1;
         unsigned int INT2IF:1;
         unsigned int INT3IF:1;
         unsigned int INT1IE:1;
         unsigned int INT2IE:1;
         unsigned int INT3IE:1;
         unsigned int INT1IP:1;
         unsigned int INT2IP:1;
      };

      struct {
         unsigned int INT1F:1;
         unsigned int INT2F:1;
         unsigned int INT3F:1;
         unsigned int INT1E:1;
         unsigned int INT2E:1;
         unsigned int INT3E:1;
         unsigned int INT1P:1;
         unsigned int INT2P:1;
      };
   };
} INTCON3BITS;
INTCON3BITS INTCON3bits;
#byte INTCON3bits = 0xFF0
#byte INTCON3 = 0xFF0

#byte INDF0 = 0xFEF

#byte POSTINC0 = 0xFEE

#byte POSTDEC0 = 0xFED

#byte PREINC0 = 0xFEC

#byte PLUSW0 = 0xFEB

#byte FSR0H = 0xFEA

#byte FSR0L = 0xFE9

#byte WREG = 0xFE8

#byte INDF1 = 0xFE7

#byte POSTINC1 = 0xFE6

#byte POSTDEC1 = 0xFE5

#byte PREINC1 = 0xFE4

#byte PLUSW1 = 0xFE3

#byte FSR1H = 0xFE2

#byte FSR1L = 0xFE1

#byte BSR = 0xFE0

#byte INDF2 = 0xFDF

#byte POSTINC2 = 0xFDE

#byte POSTDEC2 = 0xFDD

#byte PREINC2 = 0xFDC

#byte PLUSW2 = 0xFDB

#byte FSR2H = 0xFDA

#byte FSR2L = 0xFD9

typedef struct 
 {
   unsigned int C:1;
   unsigned int DC:1;
   unsigned int Z:1;
   unsigned int OV:1;
   unsigned int N:1;
} STATUSBITS;
STATUSBITS STATUSbits;
#byte STATUSbits = 0xFD8
#byte STATUS = 0xFD8

#byte TMR0H = 0xFD7

#byte TMR0L = 0xFD6

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int T0PS3:1;
      };

      struct {
         unsigned int T0PS0:3;
         unsigned int PSA:1;
         unsigned int T0SE:1;
         unsigned int T0CS:1;
         unsigned int T08BIT:1;
         unsigned int TMR0ON:1;
      };
   };
      struct {
         unsigned int T0PS:3;
      };
} T0CONBITS;
T0CONBITS T0CONbits;
#byte T0CONbits = 0xFD5
#byte T0CON = 0xFD5

typedef union 
 {
   union {
      struct {
         unsigned int RODIV0:4;
         unsigned int ROSEL:1;
         unsigned int ROSSLP:1;
         unsigned int :1;
         unsigned int ROON:1;
      };
      struct {
         unsigned int RODIV:4;
      };

      struct {
         unsigned int SCS0:2;
         unsigned int :1;
         unsigned int OSTS:1;
         unsigned int IRCF0:3;
         unsigned int IDLEN:1;
      };
   };
      struct {
         unsigned int SCS:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int IRCF:3;
      };
} OSCCONBITS;
OSCCONBITS OSCCONbits;
#byte OSCCONbits = 0xFD3
#byte OSCCON = 0xFD3

typedef union 
 {
   union {
      struct {
         unsigned int C1CH0:2;
      };
      struct {
         unsigned int C1CH:2;
      };

      struct {
         unsigned int CCH0:2;
         unsigned int CREF:1;
         unsigned int EVPOL0:2;
         unsigned int CPOL:1;
         unsigned int COE:1;
         unsigned int CON:1;
      };
   };
      struct {
         unsigned int CCH:2;
         unsigned int :1;
         unsigned int EVPOL:2;
      };
} CM1CON1BITS;
CM1CON1BITS CM1CON1bits;
#byte CM1CON1bits = 0xFD2
#byte CM1CON1 = 0xFD2

typedef union 
 {
   union {
      struct {
         unsigned int CCH0:2;
         unsigned int CREF:1;
         unsigned int EVPOL0:2;
         unsigned int CPOL:1;
         unsigned int COE:1;
         unsigned int CON:1;
      };
      struct {
         unsigned int CCH:2;
         unsigned int :1;
         unsigned int EVPOL:2;
      };

      struct {
         unsigned int C1CH0:2;
      };
   };
      struct {
         unsigned int C1CH:2;
      };
} CM2CON1BITS;
CM2CON1BITS CM2CON1bits;
#byte CM2CON1bits = 0xFD1
#byte CM2CON1 = 0xFD1

typedef struct 
 {
   unsigned int BOR:1;
   unsigned int POR:1;
   unsigned int PD:1;
   unsigned int TO:1;
   unsigned int RI:1;
   unsigned int CM:1;
   unsigned int :1;
   unsigned int IPEN:1;
} RCONBITS;
RCONBITS RCONbits;
#byte RCONbits = 0xFD0
#byte RCON = 0xFD0

typedef struct 
 {
   unsigned int ECCP1OD:1;
   unsigned int ECCP2OD:1;
   unsigned int ECCP3OD:1;
   unsigned int CCP4OD:1;
   unsigned int CCP5OD:1;
} ODCON1BITS;
ODCON1BITS ODCON1bits;
#byte ODCON1bits = 0xFCF
#byte ODCON1 = 0xFCF

typedef struct 
 {
   union {
      struct {
         unsigned int U1OD:1;
         unsigned int U2OD:1;
      };

      struct {
         unsigned int USART1OD:1;
         unsigned int USART2OD:1;
      };
   };
} ODCON2BITS;
ODCON2BITS ODCON2bits;
#byte ODCON2bits = 0xFCE
#byte ODCON2 = 0xFCE

typedef struct 
 {
   union {
      struct {
         unsigned int :2;
         unsigned int T1INSYNC:1;
      };

   union {
      struct {
         unsigned int TMR1ON:1;
         unsigned int TMR1CS:1;
         unsigned int T1SYNC:1;
         unsigned int T1OSCEN:1;
         unsigned int T1CKPS0:2;
         unsigned int T1RUN:1;
         unsigned int RD16:1;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int T1CKPS:2;
      };

      struct {
         unsigned int SPI1OD:1;
         unsigned int SPI2OD:1;
      };
   };
} ODCON3BITS;
ODCON3BITS ODCON3bits;
#byte ODCON3bits = 0xFCD
#byte ODCON3 = 0xFCD

typedef struct 
 {
   union {
      struct {
         unsigned int PMPTTL:1;
      };

      struct {
         unsigned int PMPTL:1;
      };
   };
} PADCFG1BITS;
PADCFG1BITS PADCFG1bits;
#byte PADCFG1bits = 0xFCC
#byte PADCFG1 = 0xFCC

typedef union 
 {
   union {
      struct {
         unsigned int WM0:2;
         unsigned int :2;
         unsigned int WAIT0:2;
         unsigned int :1;
         unsigned int EBDIS:1;
      };
      struct {
         unsigned int WM:2;
         unsigned int :2;
         unsigned int WAIT:2;
      };

      struct {
         unsigned int :7;
         unsigned int EDBIS:1;
      };
   };
} MEMCONBITS;
MEMCONBITS MEMCONbits;
#byte MEMCONbits = 0xFCB
#byte MEMCON = 0xFCB

typedef union 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int T2OUTPS0:4;
      };
      struct {
         unsigned int :3;
         unsigned int T2OUTPS:4;
      };

      struct {
         unsigned int T2CKPS0:2;
         unsigned int TMR2ON:1;
         unsigned int TOUTPS0:4;
      };
   };
      struct {
         unsigned int T2CKPS:2;
         unsigned int :1;
         unsigned int TOUTPS:4;
      };
} T2CONBITS;
T2CONBITS T2CONbits;
#byte T2CONbits = 0xFCA
#byte T2CON = 0xFCA

#byte SSPBUF = 0xFC9
#byte SSP1BUF = 0xFC9

typedef union 
 {
   union {
      struct {
         unsigned int MSK0:8;
      };
      struct {
         unsigned int MSK:8;
      };


   union {
      struct {
         unsigned int :2;
         unsigned int WRITE:1;
         unsigned int :2;
         unsigned int ADDRESS:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int READ_WRITE:1;
         unsigned int :2;
         unsigned int DATA_ADDRESS:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int W:1;
         unsigned int :2;
         unsigned int A:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int I2C_READ:1;
         unsigned int I2C_START:1;
         unsigned int I2C_STOP:1;
         unsigned int I2C_DAT:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int R_W:1;
         unsigned int :2;
         unsigned int D_A:1;
      };
   };

      struct {
         unsigned int BF:1;
         unsigned int UA:1;
         unsigned int R:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D:1;
         unsigned int CKE:1;
         unsigned int SMP:1;
      };
   };
} SSP1STATBITS;
SSP1STATBITS SSP1STATbits;
#byte SSP1STATbits = 0xFC7
#byte SSP1STAT = 0xFC7

typedef union 
 {
      struct {
         unsigned int SSPM0:4;
         unsigned int CKP:1;
         unsigned int SSPEN:1;
         unsigned int SSPOV:1;
         unsigned int WCOL:1;
      };
      struct {
         unsigned int SSPM:4;
      };
} SSP1CON1BITS;
SSP1CON1BITS SSP1CON1bits;
#byte SSP1CON1bits = 0xFC6
#byte SSP1CON1 = 0xFC6

SSP1CON1BITS SSPCON1bits;
#byte SSPCON1bits = 0xFC6
#byte SSPCON1 = 0xFC6

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int ADMSK1:5;
      };

      struct {
         unsigned int SEN:1;
         unsigned int RSEN:1;
         unsigned int PEN:1;
         unsigned int RCEN:1;
         unsigned int ACKEN:1;
         unsigned int ACKDT:1;
         unsigned int ACKSTAT:1;
         unsigned int GCEN:1;
      };
   };
} SSP1CON2BITS;
SSP1CON2BITS SSP1CON2bits;
#byte SSP1CON2bits = 0xFC5
#byte SSP1CON2 = 0xFC5

#byte ADRESH = 0xFC4

#byte ADRESL = 0xFC3

typedef union 
 {
   union {
      struct {
         unsigned int ADON:1;
         unsigned int GO:1;
         unsigned int CHS0:4;
         unsigned int VCFG0:2;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CHS:4;
         unsigned int VCFG:2;
      };

   union {
      struct {
         unsigned int :1;
         unsigned int DONE:1;
      };
   };

   union {
      struct {
         unsigned int PCFG8:2;
         unsigned int PCFG10:6;
      };
   };

   union {
      struct {
         unsigned int :1;
         unsigned int NOT_DONE:1;
      };
   };

      struct {
         unsigned int :1;
         unsigned int GO_DONE:1;
      };
   };
} ADCON0BITS;
ADCON0BITS ADCON0bits;
#byte ADCON0bits = 0xFC2
#byte ADCON0 = 0xFC2

#byte ANCON1 = 0xFC2

typedef union 
 {
   union {
      struct {
         unsigned int ADCS0:3;
         unsigned int ACQT0:2;
         unsigned int :1;
         unsigned int ADCAL:1;
         unsigned int ADFM:1;
      };
      struct {
         unsigned int ADCS:3;
         unsigned int ACQT:2;
      };

      struct {
         unsigned int PCFG0:5;
         unsigned int ACQT2:1;
         unsigned int PCFG6:2;
      };
   };
   /*
      struct {
         unsigned int PCFG:5;
         unsigned int :1;
         unsigned int PCFG:2;
      };*/
} ANCON0BITS;
ANCON0BITS ANCON0bits;
#byte ANCON0bits = 0xFC1
#byte ANCON0 = 0xFC1



typedef struct 
 {
   union {
      struct {
         unsigned int SWDTE:1;
         unsigned int :3;
         unsigned int DEVCFG:1;
      };

      struct {
         unsigned int SWDTEN:1;
         unsigned int :3;
         unsigned int ADSHR:1;
         unsigned int :1;
         unsigned int LVDSTAT:1;
         unsigned int REGSLP:1;
      };
   };
} WDTCONBITS;
WDTCONBITS WDTCONbits;
#byte WDTCONbits = 0xFC0
#byte WDTCON = 0xFC0

typedef union 
 {
   union {
      struct {
         unsigned int PSSBD0:2;
         unsigned int PSSAC0:2;
         unsigned int ECCPAS0:3;
         unsigned int ECCPASE:1;
      };
      struct {
         unsigned int PSSBD:2;
         unsigned int PSSAC:2;
         unsigned int ECCPAS:3;
      };

      struct {
         unsigned int PSS1BD0:2;
         unsigned int PSS1AC0:2;
         unsigned int ECCP1AS0:3;
         unsigned int ECCP1ASE:1;
      };
   };
      struct {
         unsigned int PSS1BD:2;
         unsigned int PSS1AC:2;
         unsigned int ECCP1AS:3;
      };
} ECCP1ASBITS;
ECCP1ASBITS ECCP1ASbits;
#byte ECCP1ASbits = 0xFBF
#byte ECCP1AS = 0xFBF

typedef union 
 {
   union {
      struct {
         unsigned int P1DC0:7;
         unsigned int P1RSEN:1;
      };
      struct {
         unsigned int P1DC:7;
      };

      struct {
         unsigned int PDC0:7;
         unsigned int PRSEN:1;
      };
   };
      struct {
         unsigned int PDC:7;
      };
} ECCP1DELBITS;
ECCP1DELBITS ECCP1DELbits;
#byte ECCP1DELbits = 0xFBE
#byte ECCP1DEL = 0xFBE

#byte CCPR1H = 0xFBD

#byte CCPR1L = 0xFBC

typedef struct 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int CCP1Y:1;
         unsigned int CCP1X:1;
      };

      struct {
         unsigned int CCP1M0:4;
         unsigned int DC1B0:2;
         unsigned int P1M0:2;
      };
   };
      struct {
         unsigned int CCP1M:4;
         unsigned int DC1B:2;
         unsigned int P1M:2;
      };
} ECCP1CONBITS;
ECCP1CONBITS ECCP1CONbits;
#byte ECCP1CONbits = 0xFBB
#byte ECCP1CON = 0xFBB

typedef union 
 {
   union {
      struct {
         unsigned int PSS2BD0:2;
         unsigned int PSS2AC0:2;
         unsigned int ECCP2AS0:3;
         unsigned int ECCP2ASE:1;
      };
      struct {
         unsigned int PSS2BD:2;
         unsigned int PSS2AC:2;
         unsigned int ECCP2AS:3;
      };

      struct {
         unsigned int PSSBD0:2;
         unsigned int PSSAC0:2;
         unsigned int ECCPAS0:3;
         unsigned int ECCPASE:1;
      };
   };
      struct {
         unsigned int PSSBD:2;
         unsigned int PSSAC:2;
         unsigned int ECCPAS:3;
      };
} ECCP2ASBITS;
ECCP2ASBITS ECCP2ASbits;
#byte ECCP2ASbits = 0xFBA
#byte ECCP2AS = 0xFBA

typedef union 
 {
   union {
      struct {
         unsigned int PDC0:7;
         unsigned int PRSEN:1;
      };
      struct {
         unsigned int PDC:7;
      };

      struct {
         unsigned int P2DC0:7;
         unsigned int P2RSEN:1;
      };
   };
      struct {
         unsigned int P2DC:7;
      };
} ECCP2DELBITS;
ECCP2DELBITS ECCP2DELbits;
#byte ECCP2DELbits = 0xFB9
#byte ECCP2DEL = 0xFB9

#byte CCPR2H = 0xFB8

#byte CCPR2L = 0xFB7

typedef struct 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int CCP2Y:1;
         unsigned int CCP2X:1;
      };

      struct {
         unsigned int CCP2M0:4;
         unsigned int DC2B0:2;
         unsigned int P2M0:2;
      };
   };
      struct {
         unsigned int CCP2M:4;
         unsigned int DC2B:2;
         unsigned int P2M:2;
      };
} ECCP2CONBITS;
ECCP2CONBITS ECCP2CONbits;
#byte ECCP2CONbits = 0xFB6
#byte ECCP2CON = 0xFB6

typedef union 
 {
   union {
      struct {
         unsigned int PSS3BD0:2;
         unsigned int PSS3AC0:2;
         unsigned int ECCP3AS0:3;
         unsigned int ECCP3ASE:1;
      };
      struct {
         unsigned int PSS3BD:2;
         unsigned int PSS3AC:2;
         unsigned int ECCP3AS:3;
      };

      struct {
         unsigned int PSSBD0:2;
         unsigned int PSSAC0:2;
         unsigned int ECCPAS0:3;
         unsigned int ECCPASE:1;
      };
   };
      struct {
         unsigned int PSSBD:2;
         unsigned int PSSAC:2;
         unsigned int ECCPAS:3;
      };
} ECCP3ASBITS;
ECCP3ASBITS ECCP3ASbits;
#byte ECCP3ASbits = 0xFB5
#byte ECCP3AS = 0xFB5

typedef union 
 {
   union {
      struct {
         unsigned int PDC0:7;
         unsigned int PRSEN:1;
      };
      struct {
         unsigned int PDC:7;
      };

      struct {
         unsigned int P3DC0:7;
         unsigned int P3RSEN:1;
      };
   };
      struct {
         unsigned int P3DC:7;
      };
} ECCP3DELBITS;
ECCP3DELBITS ECCP3DELbits;
#byte ECCP3DELbits = 0xFB4
#byte ECCP3DEL = 0xFB4

#byte CCPR3H = 0xFB3

#byte CCPR3L = 0xFB2

typedef union 
 {
   union {
      struct {
         unsigned int CCP3M0:4;
         unsigned int DC3B0:2;
         unsigned int P3M0:2;
      };
      struct {
         unsigned int CCP3M:4;
         unsigned int DC3B:2;
         unsigned int P3M:2;
      };

      struct {
         unsigned int :4;
         unsigned int CCP3Y:1;
         unsigned int CCP3X:1;
      };
   };
} ECCP3CONBITS;
ECCP3CONBITS ECCP3CONbits;
#byte ECCP3CONbits = 0xFB1
#byte ECCP3CON = 0xFB1

#byte SPBRG = 0xFB0
#byte SPBRG1 = 0xFB0

#byte RCREG = 0xFAF
#byte RCREG1 = 0xFAF

#byte TXREG = 0xFAE
#byte TXREG1 = 0xFAE

typedef struct 
 {
   union {
      struct {
         unsigned int TX9D1:1;
         unsigned int TRMT1:1;
         unsigned int BRGH1:1;
         unsigned int SENDB1:1;
         unsigned int SYNC1:1;
         unsigned int TXEN1:1;
         unsigned int TX8:1;
         unsigned int CSRC1:1;
      };

   union {
      struct {
         unsigned int TXD8:1;
         unsigned int :5;
         unsigned int TX8_9:1;
      };
   };

      struct {
         unsigned int TX9D:1;
         unsigned int TRMT:1;
         unsigned int BRGH:1;
         unsigned int SENDB:1;
         unsigned int SYNC:1;
         unsigned int TXEN:1;
         unsigned int TX9:1;
         unsigned int CSRC:1;
      };
   };
} TXSTA1BITS;
TXSTA1BITS TXSTA1bits;
#byte TXSTA1bits = 0xFAD
#byte TXSTA1 = 0xFAD
TXSTA1BITS TXSTAbits;
#byte TXSTAbits = 0xFAD
#byte TXSTA = 0xFAD

typedef struct 
 {
   union {
      struct {
         unsigned int RX9D:1;
         unsigned int OERR:1;
         unsigned int FERR:1;
         unsigned int ADDEN:1;
         unsigned int CREN:1;
         unsigned int SREN:1;
         unsigned int RX9:1;
         unsigned int SPEN:1;
      };

   union {
      struct {
         unsigned int RCD8:1;
         unsigned int :5;
         unsigned int RC9:1;
      };
   };

   union {
      struct {
         unsigned int :6;
         unsigned int RC8:1;
      };
   };

      struct {
         unsigned int RX9D1:1;
         unsigned int OERR1:1;
         unsigned int FERR1:1;
         unsigned int ADDEN1:1;
         unsigned int CREN1:1;
         unsigned int SREN1:1;
         unsigned int RC8_9:1;
         unsigned int SPEN1:1;
      };
   };
} RCSTA1BITS;
RCSTA1BITS RCSTA1bits;
#byte RCSTA1bits = 0xFAC
#byte RCSTA1 = 0xFAC

RCSTA1BITS RCSTAbits;
#byte RCSTAbits = 0xFAC
#byte RCSTA = 0xFAC

#byte SPBRG2 = 0xFAB

#byte RCREG2 = 0xFAA

#byte TXREG2 = 0xFA9

typedef struct 
 {
   union {
      struct {
         unsigned int TX9D:1;
         unsigned int TRMT:1;
         unsigned int BRGH:1;
         unsigned int SENDB:1;
         unsigned int SYNC:1;
         unsigned int TXEN:1;
         unsigned int TX9:1;
         unsigned int CSRC:1;
      };

   union {
      struct {
         unsigned int TXD8:1;
         unsigned int :5;
         unsigned int TX8_9:1;
      };
   };

   union {
      struct {
         unsigned int TX9D2:1;
         unsigned int TRMT2:1;
         unsigned int BRGH2:1;
         unsigned int SENDB2:1;
         unsigned int SYNC2:1;
         unsigned int TXEN2:1;
         unsigned int TX8:1;
         unsigned int CSRC2:1;
      };
   };

      struct {
         unsigned int :6;
         unsigned int TX92:1;
      };
   };
} TXSTA2BITS;
TXSTA2BITS TXSTA2bits;
#byte TXSTA2bits = 0xFA8
#byte TXSTA2 = 0xFA8

#byte EECON2 = 0xFA7

typedef struct 
 {
   unsigned int :1;
   unsigned int WR:1;
   unsigned int WREN:1;
   unsigned int WRERR:1;
   unsigned int FREE:1;
   unsigned int WPROG:1;
} EECON1BITS;
EECON1BITS EECON1bits;
#byte EECON1bits = 0xFA6
#byte EECON1 = 0xFA6

typedef struct 
 {
   unsigned int CCP3IP:1;
   unsigned int CCP4IP:1;
   unsigned int CCP5IP:1;
   unsigned int TMR4IP:1;
   unsigned int TX2IP:1;
   unsigned int RC2IP:1;
   unsigned int BCL2IP:1;
   unsigned int SSP2IP:1;
} IPR3BITS;
IPR3BITS IPR3bits;
#byte IPR3bits = 0xFA5
#byte IPR3 = 0xFA5

typedef struct 
 {
   unsigned int CCP3IF:1;
   unsigned int CCP4IF:1;
   unsigned int CCP5IF:1;
   unsigned int TMR4IF:1;
   unsigned int TX2IF:1;
   unsigned int RC2IF:1;
   unsigned int BCL2IF:1;
   unsigned int SSP2IF:1;
} PIR3BITS;
PIR3BITS PIR3bits;
#byte PIR3bits = 0xFA4
#byte PIR3 = 0xFA4

typedef struct 
 {
   unsigned int CCP3IE:1;
   unsigned int CCP4IE:1;
   unsigned int CCP5IE:1;
   unsigned int TMR4IE:1;
   unsigned int TX2IE:1;
   unsigned int RC2IE:1;
   unsigned int BCL2IE:1;
   unsigned int SSP2IE:1;
} PIE3BITS;
PIE3BITS PIE3bits;
#byte PIE3bits = 0xFA3
#byte PIE3 = 0xFA3

typedef struct 
 {
   union {
      struct {
         unsigned int CCP2IP:1;
         unsigned int TMR3IP:1;
         unsigned int LVDIP:1;
         unsigned int BCL1IP:1;
         unsigned int :1;
         unsigned int CM1IP:1;
         unsigned int CM2IP:1;
         unsigned int OSCFIP:1;
      };

      struct {
         unsigned int :3;
         unsigned int BCLIP:1;
      };
   };
} IPR2BITS;
IPR2BITS IPR2bits;
#byte IPR2bits = 0xFA2
#byte IPR2 = 0xFA2

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int BCLIF:1;
      };

      struct {
         unsigned int CCP2IF:1;
         unsigned int TMR3IF:1;
         unsigned int LVDIF:1;
         unsigned int BCL1IF:1;
         unsigned int :1;
         unsigned int CM1IF:1;
         unsigned int CM2IF:1;
         unsigned int OSCFIF:1;
      };
   };
} PIR2BITS;
PIR2BITS PIR2bits;
#byte PIR2bits = 0xFA1
#byte PIR2 = 0xFA1

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int BCLIE:1;
      };

      struct {
         unsigned int CCP2IE:1;
         unsigned int TMR3IE:1;
         unsigned int LVDIE:1;
         unsigned int BCL1IE:1;
         unsigned int :1;
         unsigned int CM1IE:1;
         unsigned int CM2IE:1;
         unsigned int OSCFIE:1;
      };
   };
} PIE2BITS;
PIE2BITS PIE2bits;
#byte PIE2bits = 0xFA0
#byte PIE2 = 0xFA0

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int SSPIP:1;
         unsigned int TXIP:1;
         unsigned int RCIP:1;
      };

      struct {
         unsigned int TMR1IP:1;
         unsigned int TMR2IP:1;
         unsigned int CCP1IP:1;
         unsigned int SSP1IP:1;
         unsigned int TX1IP:1;
         unsigned int RC1IP:1;
         unsigned int ADIP:1;
         unsigned int PMPIP:1;
      };
   };
} IPR1BITS;
IPR1BITS IPR1bits;
#byte IPR1bits = 0xF9F
#byte IPR1 = 0xF9F

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int SSPIF:1;
         unsigned int TXIF:1;
         unsigned int RCIF:1;
      };

      struct {
         unsigned int TMR1IF:1;
         unsigned int TMR2IF:1;
         unsigned int CCP1IF:1;
         unsigned int SSP1IF:1;
         unsigned int TX1IF:1;
         unsigned int RC1IF:1;
         unsigned int ADIF:1;
         unsigned int PMPIF:1;
      };
   };
} PIR1BITS;
PIR1BITS PIR1bits;
#byte PIR1bits = 0xF9E
#byte PIR1 = 0xF9E

typedef struct 
 {
   union {
      struct {
         unsigned int TMR1IE:1;
         unsigned int TMR2IE:1;
         unsigned int CCP1IE:1;
         unsigned int SSP1IE:1;
         unsigned int TX1IE:1;
         unsigned int RC1IE:1;
         unsigned int ADIE:1;
         unsigned int PMPIE:1;
      };

      struct {
         unsigned int :3;
         unsigned int SSPIE:1;
         unsigned int TXIE:1;
         unsigned int RCIE:1;
      };
   };
} PIE1BITS;
PIE1BITS PIE1bits;
#byte PIE1bits = 0xF9D
#byte PIE1 = 0xF9D

typedef struct 
 {
   union {
      struct {
         unsigned int :6;
         unsigned int RX92:1;
      };

   union {
      struct {
         unsigned int RX9D2:1;
         unsigned int OERR2:1;
         unsigned int FERR2:1;
         unsigned int ADDEN2:1;
         unsigned int CREN2:1;
         unsigned int SREN2:1;
         unsigned int RC8_9:1;
         unsigned int SPEN2:1;
      };
   };

   union {
      struct {
         unsigned int :6;
         unsigned int RC8:1;
      };
   };

   union {
      struct {
         unsigned int RX9D:1;
         unsigned int OERR:1;
         unsigned int FERR:1;
         unsigned int ADDEN:1;
         unsigned int CREN:1;
         unsigned int SREN:1;
         unsigned int RX9:1;
         unsigned int SPEN:1;
      };
   };

      struct {
         unsigned int RCD8:1;
         unsigned int :5;
         unsigned int RC9:1;
      };
   };
} RCSTA2BITS;
RCSTA2BITS RCSTA2bits;
#byte RCSTA2bits = 0xF9C
#byte RCSTA2 = 0xF9C

typedef union 
 {
      struct {
         unsigned int TUN0:6;
         unsigned int PLLEN:1;
         unsigned int INTSRC:1;
      };
      struct {
         unsigned int TUN:6;
      };
} OSCTUNEBITS;
OSCTUNEBITS OSCTUNEbits;
#byte OSCTUNEbits = 0xF9B
#byte OSCTUNE = 0xF9B

typedef union 
 {
   union {
      struct {
         unsigned int RJ0:1;
         unsigned int RJ1:1;
         unsigned int RJ2:1;
         unsigned int RJ3:1;
         unsigned int RJ4:1;
         unsigned int RJ5:1;
         unsigned int RJ6:1;
         unsigned int RJ7:1;
      };
      struct {
         unsigned int RJ:8;
      };

      struct {
         unsigned int TRISJ0:1;
         unsigned int TRISJ1:1;
         unsigned int TRISJ2:1;
         unsigned int TRISJ3:1;
         unsigned int TRISJ4:1;
         unsigned int TRISJ5:1;
         unsigned int TRISJ6:1;
         unsigned int TRISJ7:1;
      };
   };
      struct {
         unsigned int TRISJ:8;
      };
} TRISJBITS;
TRISJBITS TRISJbits;
#byte TRISJbits = 0xF9A
#byte TRISJ = 0xF9A

typedef union 
 {
   union {
      struct {
         unsigned int RH0:1;
         unsigned int RH1:1;
         unsigned int RH2:1;
         unsigned int RH3:1;
         unsigned int RH4:1;
         unsigned int RH5:1;
         unsigned int RH6:1;
         unsigned int RH7:1;
      };
      struct {
         unsigned int RH:8;
      };

      struct {
         unsigned int TRISH0:1;
         unsigned int TRISH1:1;
         unsigned int TRISH2:1;
         unsigned int TRISH3:1;
         unsigned int TRISH4:1;
         unsigned int TRISH5:1;
         unsigned int TRISH6:1;
         unsigned int TRISH7:1;
      };
   };
      struct {
         unsigned int TRISH:8;
      };
} TRISHBITS;
TRISHBITS TRISHbits;
#byte TRISHbits = 0xF99
#byte TRISH = 0xF99

typedef union 
 {
   union {
      struct {
         unsigned int RG0:1;
         unsigned int RG1:1;
         unsigned int RG2:1;
         unsigned int RG3:1;
         unsigned int RG4:1;
      };
      struct {
         unsigned int RG:5;
      };

      struct {
         unsigned int TRISG0:1;
         unsigned int TRISG1:1;
         unsigned int TRISG2:1;
         unsigned int TRISG3:1;
         unsigned int TRISG4:1;
      };
   };
      struct {
         unsigned int TRISG:5;
      };
} TRISGBITS;
TRISGBITS TRISGbits;
#byte TRISGbits = 0xF98
#byte TRISG = 0xF98

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int RF0:1;
         unsigned int RF1:1;
         unsigned int RF2:1;
         unsigned int RF3:1;
         unsigned int RF4:1;
         unsigned int RF5:1;
         unsigned int RF6:1;
         unsigned int RF7:1;
      };

      struct {
         unsigned int :1;
         unsigned int TRISF0:1;
         unsigned int TRISF1:1;
         unsigned int TRISF2:1;
         unsigned int TRISF3:1;
         unsigned int TRISF4:1;
         unsigned int TRISF5:1;
         unsigned int TRISF6:1;
         unsigned int TRISF7:1;
      };
   };
} TRISFBITS;
TRISFBITS TRISFbits;
#byte TRISFbits = 0xF97
#byte TRISF = 0xF97

typedef union 
 {
   union {
      struct {
         unsigned int RE0:1;
         unsigned int RE1:1;
         unsigned int RE2:1;
         unsigned int RE3:1;
         unsigned int RE4:1;
         unsigned int RE5:1;
         unsigned int RE6:1;
         unsigned int RE7:1;
      };
      struct {
         unsigned int RE:8;
      };

      struct {
         unsigned int TRISE0:1;
         unsigned int TRISE1:1;
         unsigned int TRISE2:1;
         unsigned int TRISE3:1;
         unsigned int TRISE4:1;
         unsigned int TRISE5:1;
         unsigned int TRISE6:1;
         unsigned int TRISE7:1;
      };
   };
      struct {
         unsigned int TRISE:8;
      };
} TRISEBITS;
TRISEBITS TRISEbits;
#byte TRISEbits = 0xF96
#byte TRISE = 0xF96

typedef union 
 {
   union {
      struct {
         unsigned int RD0:1;
         unsigned int RD1:1;
         unsigned int RD2:1;
         unsigned int RD3:1;
         unsigned int RD4:1;
         unsigned int RD5:1;
         unsigned int RD6:1;
         unsigned int RD7:1;
      };
      struct {
         unsigned int RD:8;
      };

      struct {
         unsigned int TRISD0:1;
         unsigned int TRISD1:1;
         unsigned int TRISD2:1;
         unsigned int TRISD3:1;
         unsigned int TRISD4:1;
         unsigned int TRISD5:1;
         unsigned int TRISD6:1;
         unsigned int TRISD7:1;
      };
   };
      struct {
         unsigned int TRISD:8;
      };
} TRISDBITS;
TRISDBITS TRISDbits;
#byte TRISDbits = 0xF95
#byte TRISD = 0xF95

typedef union 
 {
   union {
      struct {
         unsigned int RC0:1;
         unsigned int RC1:1;
         unsigned int RC2:1;
         unsigned int RC3:1;
         unsigned int RC4:1;
         unsigned int RC5:1;
         unsigned int RC6:1;
         unsigned int RC7:1;
      };
      struct {
         unsigned int RC:8;
      };

      struct {
         unsigned int TRISC0:1;
         unsigned int TRISC1:1;
         unsigned int TRISC2:1;
         unsigned int TRISC3:1;
         unsigned int TRISC4:1;
         unsigned int TRISC5:1;
         unsigned int TRISC6:1;
         unsigned int TRISC7:1;
      };
   };
      struct {
         unsigned int TRISC:8;
      };
} TRISCBITS;
TRISCBITS TRISCbits;
#byte TRISCbits = 0xF94
#byte TRISC = 0xF94

typedef union 
 {
   union {
      struct {
         unsigned int RB0:1;
         unsigned int RB1:1;
         unsigned int RB2:1;
         unsigned int RB3:1;
         unsigned int RB4:1;
         unsigned int RB5:1;
         unsigned int RB6:1;
         unsigned int RB7:1;
      };
      struct {
         unsigned int RB:8;
      };

      struct {
         unsigned int TRISB0:1;
         unsigned int TRISB1:1;
         unsigned int TRISB2:1;
         unsigned int TRISB3:1;
         unsigned int TRISB4:1;
         unsigned int TRISB5:1;
         unsigned int TRISB6:1;
         unsigned int TRISB7:1;
      };
   };
      struct {
         unsigned int TRISB:8;
      };
} TRISBBITS;
TRISBBITS TRISBbits;
#byte TRISBbits = 0xF93
#byte TRISB = 0xF93

typedef union 
 {
   union {
      struct {
         unsigned int RA0:1;
         unsigned int RA1:1;
         unsigned int RA2:1;
         unsigned int RA3:1;
         unsigned int RA4:1;
         unsigned int RA5:1;
         unsigned int RA6:1;
         unsigned int RA7:1;
      };
      struct {
         unsigned int RA:8;
      };

      struct {
         unsigned int TRISA0:1;
         unsigned int TRISA1:1;
         unsigned int TRISA2:1;
         unsigned int TRISA3:1;
         unsigned int TRISA4:1;
         unsigned int TRISA5:1;
         unsigned int TRISA6:1;
         unsigned int TRISA7:1;
      };
   };
      struct {
         unsigned int TRISA:8;
      };
} TRISABITS;
TRISABITS TRISAbits;
#byte TRISAbits = 0xF92
#byte TRISA = 0xF92

typedef union 
 {
      struct {
         unsigned int LATJ0:1;
         unsigned int LATJ1:1;
         unsigned int LATJ2:1;
         unsigned int LATJ3:1;
         unsigned int LATJ4:1;
         unsigned int LATJ5:1;
         unsigned int LATJ6:1;
         unsigned int LATJ7:1;
      };
      struct {
         unsigned int LATJ:8;
      };
} LATJBITS;
LATJBITS LATJbits;
#byte LATJbits = 0xF91
#byte LATJ = 0xF91

typedef union 
 {
      struct {
         unsigned int LATH0:1;
         unsigned int LATH1:1;
         unsigned int LATH2:1;
         unsigned int LATH3:1;
         unsigned int LATH4:1;
         unsigned int LATH5:1;
         unsigned int LATH6:1;
         unsigned int LATH7:1;
      };
      struct {
         unsigned int LATH:8;
      };
} LATHBITS;
LATHBITS LATHbits;
#byte LATHbits = 0xF90
#byte LATH = 0xF90

typedef union 
 {
      struct {
         unsigned int LATG0:1;
         unsigned int LATG1:1;
         unsigned int LATG2:1;
         unsigned int LATG3:1;
         unsigned int LATG4:1;
      };
      struct {
         unsigned int LATG:5;
      };
} LATGBITS;
LATGBITS LATGbits;
#byte LATGbits = 0xF8F
#byte LATG = 0xF8F

typedef struct 
 {
   unsigned int :1;
   unsigned int LATF0:1;
   unsigned int LATF1:1;
   unsigned int LATF2:1;
   unsigned int LATF3:1;
   unsigned int LATF4:1;
   unsigned int LATF5:1;
   unsigned int LATF6:1;
   unsigned int LATF7:1;
} LATFBITS;
LATFBITS LATFbits;
#byte LATFbits = 0xF8E
#byte LATF = 0xF8E

typedef union 
 {
      struct {
         unsigned int LATE0:1;
         unsigned int LATE1:1;
         unsigned int LATE2:1;
         unsigned int LATE3:1;
         unsigned int LATE4:1;
         unsigned int LATE5:1;
         unsigned int LATE6:1;
         unsigned int LATE7:1;
      };
      struct {
         unsigned int LATE:8;
      };
} LATEBITS;
LATEBITS LATEbits;
#byte LATEbits = 0xF8D
#byte LATE = 0xF8D

typedef union 
 {
      struct {
         unsigned int LATD0:1;
         unsigned int LATD1:1;
         unsigned int LATD2:1;
         unsigned int LATD3:1;
         unsigned int LATD4:1;
         unsigned int LATD5:1;
         unsigned int LATD6:1;
         unsigned int LATD7:1;
      };
      struct {
         unsigned int LATD:8;
      };
} LATDBITS;
LATDBITS LATDbits;
#byte LATDbits = 0xF8C
#byte LATD = 0xF8C

typedef union 
 {
      struct {
         unsigned int LATC0:1;
         unsigned int LATC1:1;
         unsigned int LATC2:1;
         unsigned int LATC3:1;
         unsigned int LATC4:1;
         unsigned int LATC5:1;
         unsigned int LATC6:1;
         unsigned int LATC7:1;
      };
      struct {
         unsigned int LATC:8;
      };
} LATCBITS;
LATCBITS LATCbits;
#byte LATCbits = 0xF8B
#byte LATC = 0xF8B

typedef union 
 {
      struct {
         unsigned int LATB0:1;
         unsigned int LATB1:1;
         unsigned int LATB2:1;
         unsigned int LATB3:1;
         unsigned int LATB4:1;
         unsigned int LATB5:1;
         unsigned int LATB6:1;
         unsigned int LATB7:1;
      };
      struct {
         unsigned int LATB:8;
      };
} LATBBITS;
LATBBITS LATBbits;
#byte LATBbits = 0xF8A
#byte LATB = 0xF8A

typedef union 
 {
      struct {
         unsigned int LATA0:1;
         unsigned int LATA1:1;
         unsigned int LATA2:1;
         unsigned int LATA3:1;
         unsigned int LATA4:1;
         unsigned int LATA5:1;
         unsigned int LATA6:1;
         unsigned int LATA7:1;
      };
      struct {
         unsigned int LATA:8;
      };
} LATABITS;
LATABITS LATAbits;
#byte LATAbits = 0xF89
#byte LATA = 0xF89

typedef struct 
 {
   union {
      struct {
         unsigned int ALE:1;
         unsigned int OE:1;
         unsigned int WRL:1;
         unsigned int WRH:1;
         unsigned int BA:1;
         unsigned int CE:1;
         unsigned int LB:1;
         unsigned int UB:1;
      };

      struct {
         unsigned int RJ0:1;
         unsigned int RJ1:1;
         unsigned int RJ2:1;
         unsigned int RJ3:1;
         unsigned int RJ4:1;
         unsigned int RJ5:1;
         unsigned int RJ6:1;
         unsigned int RJ7:1;
      };
   };
      struct {
         unsigned int RJ:8;
      };
} PORTJBITS;
PORTJBITS PORTJbits;
#byte PORTJbits = 0xF88
#byte PORTJ = 0xF88

typedef struct 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int C2INC:1;
         unsigned int C2IND:1;
         unsigned int C1INC:1;
      };

   union {
      struct {
         unsigned int :2;
         unsigned int PMD0:1;
         unsigned int PMD1:1;
         unsigned int PMD2:1;
         unsigned int PMBE:1;
         unsigned int PMRD:1;
         unsigned int PMWR:1;
      };
   };

   union {
      struct {
         unsigned int A1:4;
         unsigned int AN1:4;
      };
   };

      struct {
         unsigned int RH0:1;
         unsigned int RH1:1;
         unsigned int RH2:1;
         unsigned int RH3:1;
         unsigned int RH4:1;
         unsigned int RH5:1;
         unsigned int RH6:1;
         unsigned int RH7:1;
      };
   };
      struct {
         unsigned int RH:8;
      };
} PORTHBITS;
PORTHBITS PORTHbits;
#byte PORTHbits = 0xF87
#byte PORTH = 0xF87

typedef struct 
 {
   union {
      struct {
         unsigned int PMA0:1;
         unsigned int PMA1:1;
         unsigned int PMA2:1;
         unsigned int PMCS3:1;
         unsigned int PMCS2:1;
      };

   union {
      struct {
         unsigned int :1;
         unsigned int CK:1;
         unsigned int DT2:1;
      };
   };

   union {
      struct {
         unsigned int CCP0:1;
         unsigned int TX:1;
         unsigned int RX:1;
         unsigned int CCP3:1;
         unsigned int CCP5:1;
      };
   };

      struct {
         unsigned int RG0:1;
         unsigned int RG1:1;
         unsigned int RG2:1;
         unsigned int RG3:1;
         unsigned int RG4:1;
         unsigned int RJPU:1;
         unsigned int REPU:1;
         unsigned int RDPU:1;
      };
   };
      struct {
         unsigned int RG:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
      };
} PORTGBITS;
PORTGBITS PORTGbits;
#byte PORTGbits = 0xF86
#byte PORTG = 0xF86

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int RF0:1;
         unsigned int RF1:1;
         unsigned int RF2:1;
         unsigned int RF3:1;
         unsigned int RF4:1;
         unsigned int RF5:1;
         unsigned int RF6:1;
         unsigned int RF7:1;
      };

   union {
      struct {
         unsigned int :1;
         unsigned int C2OUT:1;
         unsigned int C1OUT:1;
         unsigned int C2INB:1;
         unsigned int C2INA:1;
         unsigned int C1INB:1;
         unsigned int C1INA:1;
      };
   };

   union {
      struct {
         unsigned int :5;
         unsigned int CVREF:1;
      };
   };
   /*
   union {
      struct {
         unsigned int :1;
         unsigned int AN0:1;
         unsigned int AN1:1;
         unsigned int AN2:1;
         unsigned int AN3:1;
         unsigned int AN1:2;
         unsigned int SS:1;
      };
   };

      struct {
         unsigned int :2;
         unsigned int PMA5:1;
         unsigned int :2;
         unsigned int PMD0:1;
         unsigned int PMD1:1;
         unsigned int PMD0:1;
      };
      */
   };
} PORTFBITS;
PORTFBITS PORTFbits;
#byte PORTFbits = 0xF85
#byte PORTF = 0xF85

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int REFO:1;
         unsigned int :3;
         unsigned int CCP2:1;
      };

   /*
   union {
      struct {
         unsigned int PMRD:1;
         unsigned int PMWR:1;
         unsigned int PMBE:1;
         unsigned int PMA1:1;
         unsigned int PMA1:1;
         unsigned int PMA1:1;
         unsigned int PMA1:1;
         unsigned int PMA9:1;
      };
   };

   union {
      struct {
         unsigned int AD0:1;
         unsigned int AD1:1;
         unsigned int AD1:6;
      };
   };
   */

      struct {
         unsigned int RE0:1;
         unsigned int RE1:1;
         unsigned int RE2:1;
         unsigned int RE3:1;
         unsigned int RE4:1;
         unsigned int RE5:1;
         unsigned int RE6:1;
         unsigned int RE7:1;
      };
   };
      struct {
         unsigned int RE:8;
      };
} PORTEBITS;
PORTEBITS PORTEbits;
#byte PORTEbits = 0xF84
#byte PORTE = 0xF84

typedef union 
 {
   union {
      struct {
         unsigned int RD0:1;
         unsigned int RD1:1;
         unsigned int RD2:1;
         unsigned int RD3:1;
         unsigned int RD4:1;
         unsigned int RD5:1;
         unsigned int RD6:1;
         unsigned int RD7:1;
      };
      struct {
         unsigned int RD:8;
      };

   union {
      struct {
         unsigned int :4;
         unsigned int SDO:1;
         unsigned int SDA:1;
         unsigned int SCL:1;
         unsigned int SS2:1;
      };
   };

   union {
      struct {
         unsigned int AD0:1;
         unsigned int AD1:1;
         unsigned int AD2:1;
         unsigned int AD3:1;
         unsigned int AD4:1;
         unsigned int AD5:1;
         unsigned int AD6:1;
         unsigned int AD7:1;
      };
   };
      struct {
         unsigned int AD:8;
      };

   union {
      struct {
         unsigned int PMD0:1;
         unsigned int PMD1:1;
         unsigned int PMD2:1;
         unsigned int PMD3:1;
         unsigned int PMD4:1;
         unsigned int PMD5:1;
         unsigned int PMD6:1;
         unsigned int PMD7:1;
      };
   };
      struct {
         unsigned int PMD:8;
      };

      struct {
         unsigned int :5;
         unsigned int SDI:1;
         unsigned int SCK2:1;
      };
   };
} PORTDBITS;
PORTDBITS PORTDbits;
#byte PORTDbits = 0xF83
#byte PORTD = 0xF83

typedef struct 
 {
   union {
      struct {
         unsigned int T13CKI:1;
         unsigned int CCP2:1;
         unsigned int :1;
         unsigned int SCL:1;
         unsigned int SDA:1;
         unsigned int :1;
         unsigned int CK:1;
         unsigned int DT:1;
      };

   union {
      struct {
         unsigned int T1OSO:1;
         unsigned int T1OSI:1;
         unsigned int CCP:1;
         unsigned int SCK:1;
         unsigned int SDI:1;
         unsigned int SDO:1;
         unsigned int TX:1;
         unsigned int RX:1;
      };
   };

      struct {
         unsigned int RC0:1;
         unsigned int RC1:1;
         unsigned int RC2:1;
         unsigned int RC3:1;
         unsigned int RC4:1;
         unsigned int RC5:1;
         unsigned int RC6:1;
         unsigned int RC7:1;
      };
   };
      struct {
         unsigned int RC:8;
      };
} PORTCBITS;
PORTCBITS PORTCbits;
#byte PORTCbits = 0xF82
#byte PORTC = 0xF82

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int CCP2:1;
      };

   /*
   union {
      struct {
         unsigned int FLT:1;
         unsigned int PMA0:1;
         unsigned int PMA1:1;
         unsigned int PMA2:1;
         unsigned int PMA3:1;
         unsigned int PMA0:1;
         unsigned int PGC:1;
         unsigned int PGD:1;
      };
   };
   */
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int PMA:1;
         unsigned int :1;
         unsigned int :1;
      };

   union {
      struct {
         unsigned int INT0:1;
         unsigned int INT1:1;
         unsigned int INT2:1;
         unsigned int INT3:1;
         unsigned int KBI0:1;
         unsigned int KBI1:1;
         unsigned int KBI2:1;
         unsigned int KBI3:1;
      };
   };
      struct {
         unsigned int INT:4;
         unsigned int KBI:4;
      };

      struct {
         unsigned int RB0:1;
         unsigned int RB1:1;
         unsigned int RB2:1;
         unsigned int RB3:1;
         unsigned int RB4:1;
         unsigned int RB5:1;
         unsigned int RB6:1;
         unsigned int RB7:1;
      };
   };
      struct {
         unsigned int RB:8;
      };
} PORTBBITS;
PORTBBITS PORTBbits;
#byte PORTBbits = 0xF81
#byte PORTB = 0xF81

typedef struct 
 {
   union {
      struct {
         unsigned int :2;
         unsigned int VREFM:1;
         unsigned int VREFP:1;
         unsigned int PMD0:1;
         unsigned int PMD1:1;
         unsigned int CLKO:1;
      };

   union {
      struct {
         unsigned int AN0:1;
         unsigned int AN1:1;
         unsigned int AN2:1;
         unsigned int AN3:1;
         unsigned int T0CKI:1;
         unsigned int AN5:1;
         unsigned int OSC2:1;
      };
   };
      struct {
         unsigned int AN:4;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
      };

      struct {
         unsigned int RA0:1;
         unsigned int RA1:1;
         unsigned int RA2:1;
         unsigned int RA3:1;
         unsigned int RA4:1;
         unsigned int RA5:1;
         unsigned int RA6:1;
         unsigned int RA7:1;
      };
   };
      struct {
         unsigned int RA:8;
      };
} PORTABITS;
PORTABITS PORTAbits;
#byte PORTAbits = 0xF80
#byte PORTA = 0xF80

#byte SPBRGH1 = 0xF7F

typedef struct 
 {
   union {
      struct {
         unsigned int ABDEN:1;
         unsigned int WUE:1;
         unsigned int :1;
         unsigned int BRG16:1;
         unsigned int TXCKP:1;
         unsigned int RXDTP:1;
         unsigned int RCIDL:1;
         unsigned int ABDOVF:1;
      };

      struct {
         unsigned int :4;
         unsigned int SCKP:1;
         unsigned int DTRXP:1;
         unsigned int RCMT:1;
      };
   };
} BAUDCON1BITS;
BAUDCON1BITS BAUDCON1bits;
#byte BAUDCON1bits = 0xF7E
#byte BAUDCON1 = 0xF7E

#byte SPBRGH2 = 0xF7D

typedef struct 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int SCKP:1;
         unsigned int DTRXP:1;
         unsigned int RCMT:1;
      };

      struct {
         unsigned int ABDEN:1;
         unsigned int WUE:1;
         unsigned int :1;
         unsigned int BRG16:1;
         unsigned int TXCKP:1;
         unsigned int RXDTP:1;
         unsigned int RCIDL:1;
         unsigned int ABDOVF:1;
      };
   };
} BAUDCON2BITS;
BAUDCON2BITS BAUDCON2bits;
#byte BAUDCON2bits = 0xF7C
#byte BAUDCON2 = 0xF7C

#byte TMR3H = 0xF7B

#byte TMR3L = 0xF7A

typedef struct 
 {
   union {
      struct {
         unsigned int :2;
         unsigned int T3INSYNC:1;
      };

      struct {
         unsigned int TMR3ON:1;
         unsigned int TMR3CS:1;
         unsigned int T3SYNC:1;
         unsigned int T3CCP1:1;
         unsigned int T3CKPS0:2;
         unsigned int T3CCP2:1;
         unsigned int RD16:1;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int T3CKPS:2;
      };
} T3CONBITS;
T3CONBITS T3CONbits;
#byte T3CONbits = 0xF79
#byte T3CON = 0xF79

#byte TMR4 = 0xF78

typedef union 
 {
      struct {
         unsigned int CVR0:4;
         unsigned int CVRSS:1;
         unsigned int CVRR:1;
         unsigned int CVROE:1;
         unsigned int CVREN:1;
      };
      struct {
         unsigned int CVR:4;
      };
} CVRCONBITS;
CVRCONBITS CVRCONbits;
#byte CVRCONbits = 0xF77
#byte CVRCON = 0xF77

typedef union 
 {
      struct {
         unsigned int T4CKPS0:2;
         unsigned int TMR4ON:1;
         unsigned int T4OUTPS0:4;
      };
      struct {
         unsigned int T4CKPS:2;
         unsigned int :1;
         unsigned int T4OUTPS:4;
      };
} T4CONBITS;
T4CONBITS T4CONbits;
#byte T4CONbits = 0xF76
#byte T4CON = 0xF76

#byte CCPR4H = 0xF75

#byte CCPR4L = 0xF74

typedef struct 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int DCCP4Y:1;
         unsigned int DCCP4X:1;
      };

      struct {
         unsigned int CCP4M0:4;
         unsigned int DC4B0:2;
      };
   };
      struct {
         unsigned int CCP4M:4;
         unsigned int DC4B:2;
      };
} CCP4CONBITS;
CCP4CONBITS CCP4CONbits;
#byte CCP4CONbits = 0xF73
#byte CCP4CON = 0xF73

#byte CCPR5H = 0xF72

#byte CCPR5L = 0xF71

typedef struct 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int DCCP5Y:1;
         unsigned int DCCP5X:1;
      };

      struct {
         unsigned int CCP5M0:4;
         unsigned int DC5B0:2;
      };
   };
      struct {
         unsigned int CCP5M:4;
         unsigned int DC5B:2;
      };
} CCP5CONBITS;
CCP5CONBITS CCP5CONbits;
#byte CCP5CONbits = 0xF70
#byte CCP5CON = 0xF70

#byte SSP2BUF = 0xF6F

typedef union 
 {
   union {
      struct {
         unsigned int MSK0:8;
      };
      struct {
         unsigned int MSK:8;
      };


   union {
      struct {
         unsigned int :2;
         unsigned int WRITE:1;
         unsigned int :2;
         unsigned int ADDRESS:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int READ_WRITE:1;
         unsigned int :2;
         unsigned int DATA_ADDRESS:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int W:1;
         unsigned int :2;
         unsigned int A:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int I2C_READ:1;
         unsigned int I2C_START:1;
         unsigned int I2C_STOP:1;
         unsigned int I2C_DAT:1;
      };
   };

   union {
      struct {
         unsigned int BF:1;
         unsigned int UA:1;
         unsigned int R:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D:1;
         unsigned int CKE:1;
         unsigned int SMP:1;
      };
   };

      struct {
         unsigned int :2;
         unsigned int R_W:1;
         unsigned int :2;
         unsigned int D_A:1;
      };
   };
} SSP2STATBITS;
SSP2STATBITS SSP2STATbits;
#byte SSP2STATbits = 0xF6D
#byte SSP2STAT = 0xF6D

typedef union 
 {
      struct {
         unsigned int SSPM0:4;
         unsigned int CKP:1;
         unsigned int SSPEN:1;
         unsigned int SSPOV:1;
         unsigned int WCOL:1;
      };
      struct {
         unsigned int SSPM:4;
      };
} SSP2CON1BITS;
SSP2CON1BITS SSP2CON1bits;
#byte SSP2CON1bits = 0xF6C
#byte SSP2CON1 = 0xF6C

typedef struct 
 {
   union {
      struct {
         unsigned int SEN:1;
         unsigned int RSEN:1;
         unsigned int PEN:1;
         unsigned int RCEN:1;
         unsigned int ACKEN:1;
         unsigned int ACKDT:1;
         unsigned int ACKSTAT:1;
         unsigned int GCEN:1;
      };

      struct {
         unsigned int :1;
         unsigned int ADMSK1:5;
      };
   };
} SSP2CON2BITS;
SSP2CON2BITS SSP2CON2bits;
#byte SSP2CON2bits = 0xF6B
#byte SSP2CON2 = 0xF6B

typedef struct 
 {
   unsigned int COUT1:2;
} CMSTATBITS;
CMSTATBITS CMSTATbits;
#byte CMSTATbits = 0xF6A
#byte CMSTAT = 0xF6A

typedef union 
 {
      struct {
         unsigned int ADDRH0:6;
         unsigned int CS1:2;
      };
      struct {
         unsigned int ADDRH:6;
         unsigned int CS:2;
      };
} PMADDRHBITS;
PMADDRHBITS PMADDRHbits;
#byte PMADDRHbits = 0xF69
#byte PMADDRH = 0xF69

#byte PMADDRL = 0xF68

#byte PMDIN1H = 0xF67

#byte PMDIN1L = 0xF66

typedef union 
 {
      struct {
         unsigned int PTRDEN:1;
         unsigned int PTWREN:1;
         unsigned int PTBEEN:1;
         unsigned int ADRMUX0:2;
         unsigned int PSIDL:1;
         unsigned int :1;
         unsigned int PMPEN:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int ADRMUX:2;
      };
} PMCONHBITS;
PMCONHBITS PMCONHbits;
#byte PMCONHbits = 0xF65
#byte PMCONH = 0xF65

typedef union 
 {
      struct {
         unsigned int RDSP:1;
         unsigned int WRSP:1;
         unsigned int BEP:1;
         unsigned int CS1P:1;
         unsigned int CS2P:1;
         unsigned int ALP:1;
         unsigned int CSF0:2;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int CSF:2;
      };
} PMCONLBITS;
PMCONLBITS PMCONLbits;
#byte PMCONLbits = 0xF64
#byte PMCONL = 0xF64

typedef union 
 {
      struct {
         unsigned int MODE0:2;
         unsigned int MODE16:1;
         unsigned int INCM0:2;
         unsigned int IRQM0:2;
         unsigned int BUSY:1;
      };
      struct {
         unsigned int MODE:2;
         unsigned int :1;
         unsigned int INCM:2;
         unsigned int IRQM:2;
      };
} PMMODEHBITS;
PMMODEHBITS PMMODEHbits;
#byte PMMODEHbits = 0xF63
#byte PMMODEH = 0xF63

typedef union 
 {
      struct {
         unsigned int WAITE0:2;
         unsigned int WAITM0:4;
         unsigned int WAITB0:2;
      };
      struct {
         unsigned int WAITE:2;
         unsigned int WAITM:4;
         unsigned int WAITB:2;
      };
} PMMODELBITS;
PMMODELBITS PMMODELbits;
#byte PMMODELbits = 0xF62
#byte PMMODEL = 0xF62

#byte PMDOUT2H = 0xF61

#byte PMDOUT2L = 0xF60

#byte PMDIN2H = 0xF5F

#byte PMDIN2L = 0xF5E

typedef struct 
 {
   unsigned int PTEN8:2;
   unsigned int PTEN10:6;
} PMEHBITS;
PMEHBITS PMEHbits;
#byte PMEHbits = 0xF5D
#byte PMEH = 0xF5D

typedef union 
 {
      struct {
         unsigned int PTEN0:8;
      };
      struct {
         unsigned int PTEN:8;
      };
} PMELBITS;
PMELBITS PMELbits;
#byte PMELbits = 0xF5C
#byte PMEL = 0xF5C

typedef struct 
 {
   unsigned int IB0F:1;
   unsigned int IB1F:1;
   unsigned int IB2F:1;
   unsigned int IB3F:1;
   unsigned int :2;
   unsigned int IBOV:1;
   unsigned int IBF:1;
} PMSTATHBITS;
PMSTATHBITS PMSTATHbits;
#byte PMSTATHbits = 0xF5B
#byte PMSTATH = 0xF5B

typedef struct 
 {
   unsigned int OB0E:1;
   unsigned int OB1E:1;
   unsigned int OB2E:1;
   unsigned int OB3E:1;
   unsigned int :2;
   unsigned int OBUF:1;
   unsigned int OBE:1;
} PMSTATLBITS;
PMSTATLBITS PMSTATLbits;
#byte PMSTATLbits = 0xF5A
#byte PMSTATL = 0xF5A

