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
         unsigned int ACCA390:8;
      };
      struct {
         unsigned int ACCAU:8;
         unsigned int ACCA39:8;
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
         unsigned int ACCB390:8;
      };
      struct {
         unsigned int ACCBU:8;
         unsigned int ACCB39:8;
      };
} ACCBUBITS;
ACCBUBITS ACCBUbits;
#word ACCBUbits = 0x02C
#word ACCBU = 0x02C

#word PC = 0x02E

#word DSRPAG = 0x032

#word DSWPAG = 0x034

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
         unsigned int SFA:1;
         unsigned int IPL3:1;
         unsigned int ACCSAT:1;
         unsigned int SATDW:1;
         unsigned int SATB:1;
         unsigned int SATA:1;
         unsigned int DL0:3;
         unsigned int EDT:1;
         unsigned int US0:2;
         unsigned int :1;
         unsigned int VAR:1;
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
         unsigned int :1;
         unsigned int US:2;
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

#word TBLPAG = 0x054

#word MSTRPR = 0x058

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
} IC10CON1BITS;
IC10CON1BITS IC10CON1bits;
#word IC10CON1bits = 0x188
#word IC10CON1 = 0x188

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
} IC10CON2BITS;
IC10CON2BITS IC10CON2bits;
#word IC10CON2bits = 0x18A
#word IC10CON2 = 0x18A

#word IC10BUF = 0x18C

#word IC10TMR = 0x18E

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
} IC11CON1BITS;
IC11CON1BITS IC11CON1bits;
#word IC11CON1bits = 0x190
#word IC11CON1 = 0x190

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
} IC11CON2BITS;
IC11CON2BITS IC11CON2bits;
#word IC11CON2bits = 0x192
#word IC11CON2 = 0x192

#word IC11BUF = 0x194

#word IC11TMR = 0x196

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
} IC12CON1BITS;
IC12CON1BITS IC12CON1bits;
#word IC12CON1bits = 0x198
#word IC12CON1 = 0x198

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
} IC12CON2BITS;
IC12CON2BITS IC12CON2bits;
#word IC12CON2bits = 0x19A
#word IC12CON2 = 0x19A

#word IC12BUF = 0x19C

#word IC12TMR = 0x19E

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
} IC13CON1BITS;
IC13CON1BITS IC13CON1bits;
#word IC13CON1bits = 0x1A0
#word IC13CON1 = 0x1A0

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
} IC13CON2BITS;
IC13CON2BITS IC13CON2bits;
#word IC13CON2bits = 0x1A2
#word IC13CON2 = 0x1A2

#word IC13BUF = 0x1A4

#word IC13TMR = 0x1A6

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
} IC14CON1BITS;
IC14CON1BITS IC14CON1bits;
#word IC14CON1bits = 0x1A8
#word IC14CON1 = 0x1A8

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
} IC14CON2BITS;
IC14CON2BITS IC14CON2bits;
#word IC14CON2bits = 0x1AA
#word IC14CON2 = 0x1AA

#word IC14BUF = 0x1AC

#word IC14TMR = 0x1AE

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
} IC15CON1BITS;
IC15CON1BITS IC15CON1bits;
#word IC15CON1bits = 0x1B0
#word IC15CON1 = 0x1B0

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
} IC15CON2BITS;
IC15CON2BITS IC15CON2bits;
#word IC15CON2bits = 0x1B2
#word IC15CON2 = 0x1B2

#word IC15BUF = 0x1B4

#word IC15TMR = 0x1B6

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
} IC16CON1BITS;
IC16CON1BITS IC16CON1bits;
#word IC16CON1bits = 0x1B8
#word IC16CON1 = 0x1B8

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
} IC16CON2BITS;
IC16CON2BITS IC16CON2bits;
#word IC16CON2bits = 0x1BA
#word IC16CON2 = 0x1BA

#word IC16BUF = 0x1BC

#word IC16TMR = 0x1BE

typedef union 
 {
      struct {
         unsigned int CCM0:2;
         unsigned int GATEN:1;
         unsigned int CNTPOL:1;
         unsigned int INTDIV0:3;
         unsigned int :1;
         unsigned int IMV0:2;
         unsigned int PIMOD0:3;
         unsigned int QEISIDL:1;
         unsigned int :1;
         unsigned int QEIEN:1;
      };
      struct {
         unsigned int CCM:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int INTDIV:3;
         unsigned int :1;
         unsigned int IMV:2;
         unsigned int PIMOD:3;
      };
} QEI1CONBITS;
QEI1CONBITS QEI1CONbits;
#word QEI1CONbits = 0x1C0
#word QEI1CON = 0x1C0

typedef union 
 {
      struct {
         unsigned int QEA:1;
         unsigned int QEB:1;
         unsigned int INDEX:1;
         unsigned int HOME:1;
         unsigned int QEAPOL:1;
         unsigned int QEBPOL:1;
         unsigned int IDXPOL:1;
         unsigned int HOMPOL:1;
         unsigned int SWPAB:1;
         unsigned int OUTFNC0:2;
         unsigned int QFDIV0:3;
         unsigned int FLTREN:1;
         unsigned int QCAPEN:1;
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
         unsigned int :1;
         unsigned int OUTFNC:2;
         unsigned int QFDIV:3;
      };
} QEI1IOCBITS;
QEI1IOCBITS QEI1IOCbits;
#word QEI1IOCbits = 0x1C2
#word QEI1IOC = 0x1C2

typedef struct 
 {
   unsigned int IDXIEN:1;
   unsigned int IDXIRQ:1;
   unsigned int HOMIEN:1;
   unsigned int HOMIRQ:1;
   unsigned int VELOVIEN:1;
   unsigned int VELOVIRQ:1;
   unsigned int PCIIEN:1;
   unsigned int PCIIRQ:1;
   unsigned int POSOVIEN:1;
   unsigned int POSOVIRQ:1;
   unsigned int PCLEQIEN:1;
   unsigned int PCLEQIRQ:1;
   unsigned int PCHEQIEN:1;
   unsigned int PCHEQIRQ:1;
} QEI1STATBITS;
QEI1STATBITS QEI1STATbits;
#word QEI1STATbits = 0x1C4
#word QEI1STAT = 0x1C4

#word POS1CNT = 0x1C6

#word POS1HLD = 0x1CA

#word VEL1CNT = 0x1CC

#word INT1TMR = 0x1CE

#word INT1HLD = 0x1D2

#word INDX1CNT = 0x1D6

#word INDX1HLD = 0x1DA

#word QEI1GEC = 0x1DC

#word QEI1LEC = 0x1E0

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
} I2C2STATBITS;
I2C2STATBITS I2C2STATbits;
#word I2C2STATbits = 0x218
#word I2C2STAT = 0x218

#word I2C2ADD = 0x21A

#word I2C2MSK = 0x21C

typedef union 
 {
   union {
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

      struct {
         unsigned int :4;
         unsigned int RXINV:1;
      };
   };
} U1MODEBITS;
U1MODEBITS U1MODEbits;
#word U1MODEbits = 0x220
#word U1MODE = 0x220

typedef union 
 {
   union {
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

      struct {
         unsigned int :14;
         unsigned int TXINV:1;
      };
   };
} U1STABITS;
U1STABITS U1STAbits;
#word U1STAbits = 0x222
#word U1STA = 0x222

#word U1TXREG = 0x224

#word U1RXREG = 0x226

#word U1BRG = 0x228

typedef union 
 {
   union {
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

      struct {
         unsigned int :4;
         unsigned int RXINV:1;
      };
   };
} U2MODEBITS;
U2MODEBITS U2MODEbits;
#word U2MODEbits = 0x230
#word U2MODE = 0x230

typedef union 
 {
   union {
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

      struct {
         unsigned int :14;
         unsigned int TXINV:1;
      };
   };
} U2STABITS;
U2STABITS U2STAbits;
#word U2STAbits = 0x232
#word U2STA = 0x232

#word U2TXREG = 0x234

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

typedef union 
 {
   union {
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

      struct {
         unsigned int :4;
         unsigned int RXINV:1;
      };
   };
} U3MODEBITS;
U3MODEBITS U3MODEbits;
#word U3MODEbits = 0x250
#word U3MODE = 0x250

typedef union 
 {
   union {
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

      struct {
         unsigned int :14;
         unsigned int TXINV:1;
      };
   };
} U3STABITS;
U3STABITS U3STAbits;
#word U3STAbits = 0x252
#word U3STA = 0x252

#word U3TXREG = 0x254

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
         unsigned int BCG0:12;
      };
      struct {
         unsigned int BCG:12;
      };
} DCICON3BITS;
DCICON3BITS DCICON3bits;
#word DCICON3bits = 0x284
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
#word SPI3STATbits = 0x2A0
#word SPI3STAT = 0x2A0

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
#word SPI3CON1bits = 0x2A2
#word SPI3CON1 = 0x2A2

typedef struct 
 {
   unsigned int SPIBEN:1;
   unsigned int FRMDLY:1;
   unsigned int :11;
   unsigned int FRMPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI3CON2BITS;
SPI3CON2BITS SPI3CON2bits;
#word SPI3CON2bits = 0x2A4
#word SPI3CON2 = 0x2A4

#word SPI3BUF = 0x2A8

typedef union 
 {
   union {
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

      struct {
         unsigned int :4;
         unsigned int RXINV:1;
      };
   };
} U4MODEBITS;
U4MODEBITS U4MODEbits;
#word U4MODEbits = 0x2B0
#word U4MODE = 0x2B0

typedef union 
 {
   union {
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

      struct {
         unsigned int :14;
         unsigned int TXINV:1;
      };
   };
} U4STABITS;
U4STABITS U4STAbits;
#word U4STAbits = 0x2B2
#word U4STA = 0x2B2

#word U4TXREG = 0x2B4

#word U4RXREG = 0x2B6

#word U4BRG = 0x2B8

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
} SPI4STATBITS;
SPI4STATBITS SPI4STATbits;
#word SPI4STATbits = 0x2C0
#word SPI4STAT = 0x2C0

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
} SPI4CON1BITS;
SPI4CON1BITS SPI4CON1bits;
#word SPI4CON1bits = 0x2C2
#word SPI4CON1 = 0x2C2

typedef struct 
 {
   unsigned int SPIBEN:1;
   unsigned int FRMDLY:1;
   unsigned int :11;
   unsigned int FRMPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI4CON2BITS;
SPI4CON2BITS SPI4CON2bits;
#word SPI4CON2bits = 0x2C4
#word SPI4CON2 = 0x2C4

#word SPI4BUF = 0x2C8

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
         unsigned int SIMSAM:1;
         unsigned int SSRCG:1;
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
         unsigned int SMPI0:5;
         unsigned int BUFS:1;
         unsigned int CHPS0:2;
         unsigned int CSCNA:1;
         unsigned int :2;
         unsigned int VCFG0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SMPI:5;
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
   unsigned int CSS16:4;
   unsigned int CSS20:10;
   unsigned int CSS30:2;
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

typedef union 
 {
      struct {
         unsigned int DMABL0:3;
         unsigned int :5;
         unsigned int ADDMAEN:1;
      };
      struct {
         unsigned int DMABL:3;
         unsigned int :5;
      };
} AD1CON4BITS;
AD1CON4BITS AD1CON4bits;
#word AD1CON4bits = 0x332
#word AD1CON4 = 0x332

#word ADC2BUF0 = 0x340

#word ADC2BUF1 = 0x342

#word ADC2BUF2 = 0x344

#word ADC2BUF3 = 0x346

#word ADC2BUF4 = 0x348

#word ADC2BUF5 = 0x34A

#word ADC2BUF6 = 0x34C

#word ADC2BUF7 = 0x34E

#word ADC2BUF8 = 0x350

#word ADC2BUF9 = 0x352

#word ADC2BUFA = 0x354

#word ADC2BUFB = 0x356

#word ADC2BUFC = 0x358

#word ADC2BUFD = 0x35A

#word ADC2BUFE = 0x35C

#word ADC2BUFF = 0x35E

typedef union 
 {
      struct {
         unsigned int DONE:1;
         unsigned int SAMP:1;
         unsigned int ASAM:1;
         unsigned int SIMSAM:1;
         unsigned int SSRCG:1;
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
         unsigned int SMPI0:5;
         unsigned int BUFS:1;
         unsigned int CHPS0:2;
         unsigned int CSCNA:1;
         unsigned int :2;
         unsigned int VCFG0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int SMPI:5;
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
} AD2CHS0BITS;
AD2CHS0BITS AD2CHS0bits;
#word AD2CHS0bits = 0x368
#word AD2CHS0 = 0x368

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

typedef union 
 {
      struct {
         unsigned int DMABL0:3;
         unsigned int :5;
         unsigned int ADDMAEN:1;
      };
      struct {
         unsigned int DMABL:3;
         unsigned int :5;
      };
} AD2CON4BITS;
AD2CON4BITS AD2CON4bits;
#word AD2CON4bits = 0x372
#word AD2CON4 = 0x372

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
         unsigned int EID0:2;
      };
      struct {
         unsigned int EID:2;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
   };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
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
         unsigned int EID0:2;
      };
      struct {
         unsigned int EID:2;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
   };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
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
#word U1OTGIRbits = 0x488
#word U1OTGIR = 0x488

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
#word U1OTGIEbits = 0x48A
#word U1OTGIE = 0x48A

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
#word U1OTGSTATbits = 0x48C
#word U1OTGSTAT = 0x48C

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
#word U1OTGCONbits = 0x48E
#word U1OTGCON = 0x48E

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
#word U1PWRCbits = 0x490
#word U1PWRC = 0x490

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
#word U1IRbits = 0x4C0
#word U1IR = 0x4C0

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
#word U1IEbits = 0x4C2
#word U1IE = 0x4C2

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
         unsigned int BUSACCEF:1;
         unsigned int BTSEF:1;
      };

      struct {
         unsigned int :1;
         unsigned int EOFEF:1;
      };
   };
} U1EIRBITS;
U1EIRBITS U1EIRbits;
#word U1EIRbits = 0x4C4
#word U1EIR = 0x4C4

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
         unsigned int BUSACCEE:1;
         unsigned int BTSEE:1;
      };

      struct {
         unsigned int :1;
         unsigned int EOFEE:1;
      };
   };
} U1EIEBITS;
U1EIEBITS U1EIEbits;
#word U1EIEbits = 0x4C6
#word U1EIE = 0x4C6

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
#word U1STATbits = 0x4C8
#word U1STAT = 0x4C8

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
#word U1CONbits = 0x4CA
#word U1CON = 0x4CA

typedef union 
 {
   union {
      struct {
         unsigned int DEVADDR0:7;
         unsigned int LSPDEN:1;
      };
      struct {
         unsigned int DEVADDR:7;
      };

      struct {
         unsigned int :7;
         unsigned int LOWSPDEN:1;
      };
   };
} U1ADDRBITS;
U1ADDRBITS U1ADDRbits;
#word U1ADDRbits = 0x4CC
#word U1ADDR = 0x4CC

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
#word U1BDTP1bits = 0x4CE
#word U1BDTP1 = 0x4CE

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
#word U1FRMLbits = 0x4D0
#word U1FRML = 0x4D0

typedef struct 
 {
   unsigned int FRM8:3;
} U1FRMHBITS;
U1FRMHBITS U1FRMHbits;
#word U1FRMHbits = 0x4D2
#word U1FRMH = 0x4D2

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
#word U1TOKbits = 0x4D4
#word U1TOK = 0x4D4

#word U1SOF = 0x4D6

#word U1BDTP2 = 0x4D8

#word U1BDTP3 = 0x4DA

typedef struct 
 {
   unsigned int :4;
   unsigned int USBSIDL:1;
   unsigned int :1;
   unsigned int UOEMON:1;
   unsigned int UTEYE:1;
} U1CNFG1BITS;
U1CNFG1BITS U1CNFG1bits;
#word U1CNFG1bits = 0x4DC
#word U1CNFG1 = 0x4DC

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
#word U1CNFG2bits = 0x4DE
#word U1CNFG2 = 0x4DE

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
#word U1EP0bits = 0x4E0
#word U1EP0 = 0x4E0

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
#word U1EP1bits = 0x4E2
#word U1EP1 = 0x4E2

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
#word U1EP2bits = 0x4E4
#word U1EP2 = 0x4E4

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
#word U1EP3bits = 0x4E6
#word U1EP3 = 0x4E6

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
#word U1EP4bits = 0x4E8
#word U1EP4 = 0x4E8

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
#word U1EP5bits = 0x4EA
#word U1EP5 = 0x4EA

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
#word U1EP6bits = 0x4EC
#word U1EP6 = 0x4EC

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
#word U1EP7bits = 0x4EE
#word U1EP7 = 0x4EE

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
#word U1EP8bits = 0x4F0
#word U1EP8 = 0x4F0

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
#word U1EP9bits = 0x4F2
#word U1EP9 = 0x4F2

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
#word U1EP10bits = 0x4F4
#word U1EP10 = 0x4F4

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
#word U1EP11bits = 0x4F6
#word U1EP11 = 0x4F6

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
#word U1EP12bits = 0x4F8
#word U1EP12 = 0x4F8

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
#word U1EP13bits = 0x4FA
#word U1EP13 = 0x4FA

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
#word U1EP14bits = 0x4FC
#word U1EP14 = 0x4FC

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
#word U1EP15bits = 0x4FE
#word U1EP15 = 0x4FE

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
   unsigned int RXWAR:1;
   unsigned int TXWAR:1;
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
         unsigned int EID0:2;
      };
      struct {
         unsigned int EID:2;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
   };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
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
         unsigned int EID0:2;
      };
      struct {
         unsigned int EID:2;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int MIDE:1;
         unsigned int :1;
         unsigned int SID0:11;
      };
   };
      struct {
         unsigned int EID:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:11;
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
         unsigned int PER0:8;
         unsigned int DC0:8;
      };
      struct {
         unsigned int PER:8;
         unsigned int DC:8;
      };
} U1PWMRRSBITS;
U1PWMRRSBITS U1PWMRRSbits;
#word U1PWMRRSbits = 0x580
#word U1PWMRRS = 0x580

typedef struct 
 {
   unsigned int :8;
   unsigned int CNTEN:1;
   unsigned int PWMPOL:1;
   unsigned int :5;
   unsigned int PWMEN:1;
} U1PWMCONBITS;
U1PWMCONBITS U1PWMCONbits;
#word U1PWMCONbits = 0x582
#word U1PWMCON = 0x582

typedef union 
 {
      struct {
         unsigned int CCM0:2;
         unsigned int GATEN:1;
         unsigned int CNTPOL:1;
         unsigned int INTDIV0:3;
         unsigned int :1;
         unsigned int IMV0:2;
         unsigned int PIMOD0:3;
         unsigned int QEISIDL:1;
         unsigned int :1;
         unsigned int QEIEN:1;
      };
      struct {
         unsigned int CCM:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int INTDIV:3;
         unsigned int :1;
         unsigned int IMV:2;
         unsigned int PIMOD:3;
      };
} QEI2CONBITS;
QEI2CONBITS QEI2CONbits;
#word QEI2CONbits = 0x5C0
#word QEI2CON = 0x5C0

typedef union 
 {
      struct {
         unsigned int QEA:1;
         unsigned int QEB:1;
         unsigned int INDEX:1;
         unsigned int HOME:1;
         unsigned int QEAPOL:1;
         unsigned int QEBPOL:1;
         unsigned int IDXPOL:1;
         unsigned int HOMPOL:1;
         unsigned int SWPAB:1;
         unsigned int OUTFNC0:2;
         unsigned int QFDIV0:3;
         unsigned int FLTREN:1;
         unsigned int QCAPEN:1;
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
         unsigned int :1;
         unsigned int OUTFNC:2;
         unsigned int QFDIV:3;
      };
} QEI2IOCBITS;
QEI2IOCBITS QEI2IOCbits;
#word QEI2IOCbits = 0x5C2
#word QEI2IOC = 0x5C2

typedef struct 
 {
   unsigned int IDXIEN:1;
   unsigned int IDXIRQ:1;
   unsigned int HOMIEN:1;
   unsigned int HOMIRQ:1;
   unsigned int VELOVIEN:1;
   unsigned int VELOVIRQ:1;
   unsigned int PCIIEN:1;
   unsigned int PCIIRQ:1;
   unsigned int POSOVIEN:1;
   unsigned int POSOVIRQ:1;
   unsigned int PCLEQIEN:1;
   unsigned int PCLEQIRQ:1;
   unsigned int PCHEQIEN:1;
   unsigned int PCHEQIRQ:1;
} QEI2STATBITS;
QEI2STATBITS QEI2STATbits;
#word QEI2STATbits = 0x5C4
#word QEI2STAT = 0x5C4

#word POS2CNT = 0x5C6

#word POS2HLD = 0x5CA

#word VEL2CNT = 0x5CC

#word INT2TMR = 0x5CE

#word INT2HLD = 0x5D2

#word INDX2CNT = 0x5D6

#word INDX2HLD = 0x5DA

#word QEI2GEC = 0x5DC

#word QEI2LEC = 0x5E0

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
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int CSF:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int ADRMUX:2;
      };
} PMCONBITS;
PMCONBITS PMCONbits;
#word PMCONbits = 0x600
#word PMCON = 0x600

typedef union 
 {
      struct {
         unsigned int WAITE0:2;
         unsigned int WAITM0:4;
         unsigned int WAITB0:2;
         unsigned int MODE0:2;
         unsigned int MODE16:1;
         unsigned int INCM0:2;
         unsigned int IRQM0:2;
         unsigned int BUSY:1;
      };
      struct {
         unsigned int WAITE:2;
         unsigned int WAITM:4;
         unsigned int WAITB:2;
         unsigned int MODE:2;
         unsigned int :1;
         unsigned int INCM:2;
         unsigned int IRQM:2;
      };
} PMMODEBITS;
PMMODEBITS PMMODEbits;
#word PMMODEbits = 0x602
#word PMMODE = 0x602

typedef union 
 {
      struct {
         unsigned int ADDR0:14;
         unsigned int CS1:2;
      };
      struct {
         unsigned int ADDR:14;
         unsigned int CS:2;
      };
} PMADDRBITS;
PMADDRBITS PMADDRbits;
#word PMADDRbits = 0x604
#word PMADDR = 0x604

#word PMDOUT2 = 0x606

#word PMDIN1 = 0x608

#word PMDIN2 = 0x60A

typedef union 
 {
      struct {
         unsigned int PTEN0:16;
      };
      struct {
         unsigned int PTEN:16;
      };
} PMAENBITS;
PMAENBITS PMAENbits;
#word PMAENbits = 0x60C
#word PMAEN = 0x60C

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
#word PMSTATbits = 0x60E
#word PMSTAT = 0x60E

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
         unsigned int CAL0:8;
         //unsigned int RTCPTR0:2;  //PCD_QUIRKS
         unsigned int RTCPTR0:1;  //PCD_QUIRKS
         unsigned int RTCPTR1:1;  //PCD_QUIRKS
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
         unsigned int RP64R0:6;
         unsigned int :2;
         unsigned int RP65R0:6;
      };
      struct {
         unsigned int RP64R:6;
         unsigned int :2;
         unsigned int RP65R:6;
      };
} RPOR0BITS;
RPOR0BITS RPOR0bits;
#word RPOR0bits = 0x680
#word RPOR0 = 0x680

typedef union 
 {
      struct {
         unsigned int RP66R0:6;
         unsigned int :2;
         unsigned int RP67R0:6;
      };
      struct {
         unsigned int RP66R:6;
         unsigned int :2;
         unsigned int RP67R:6;
      };
} RPOR1BITS;
RPOR1BITS RPOR1bits;
#word RPOR1bits = 0x682
#word RPOR1 = 0x682

typedef union 
 {
      struct {
         unsigned int RP68R0:6;
         unsigned int :2;
         unsigned int RP69R0:6;
      };
      struct {
         unsigned int RP68R:6;
         unsigned int :2;
         unsigned int RP69R:6;
      };
} RPOR2BITS;
RPOR2BITS RPOR2bits;
#word RPOR2bits = 0x684
#word RPOR2 = 0x684

typedef union 
 {
      struct {
         unsigned int RP70R0:6;
         unsigned int :2;
         unsigned int RP71R0:6;
      };
      struct {
         unsigned int RP70R:6;
         unsigned int :2;
         unsigned int RP71R:6;
      };
} RPOR3BITS;
RPOR3BITS RPOR3bits;
#word RPOR3bits = 0x686
#word RPOR3 = 0x686

typedef union 
 {
      struct {
         unsigned int RP79R0:6;
         unsigned int :2;
         unsigned int RP80R0:6;
      };
      struct {
         unsigned int RP79R:6;
         unsigned int :2;
         unsigned int RP80R:6;
      };
} RPOR4BITS;
RPOR4BITS RPOR4bits;
#word RPOR4bits = 0x688
#word RPOR4 = 0x688

typedef union 
 {
      struct {
         unsigned int RP82R0:6;
         unsigned int :2;
         unsigned int RP84R0:6;
      };
      struct {
         unsigned int RP82R:6;
         unsigned int :2;
         unsigned int RP84R:6;
      };
} RPOR5BITS;
RPOR5BITS RPOR5bits;
#word RPOR5bits = 0x68A
#word RPOR5 = 0x68A

typedef union 
 {
      struct {
         unsigned int RP85R0:6;
         unsigned int :2;
         unsigned int RP87R0:6;
      };
      struct {
         unsigned int RP85R:6;
         unsigned int :2;
         unsigned int RP87R:6;
      };
} RPOR6BITS;
RPOR6BITS RPOR6bits;
#word RPOR6bits = 0x68C
#word RPOR6 = 0x68C

typedef union 
 {
      struct {
         unsigned int RP96R0:6;
         unsigned int :2;
         unsigned int RP97R0:6;
      };
      struct {
         unsigned int RP96R:6;
         unsigned int :2;
         unsigned int RP97R:6;
      };
} RPOR7BITS;
RPOR7BITS RPOR7bits;
#word RPOR7bits = 0x68E
#word RPOR7 = 0x68E

typedef union 
 {
      struct {
         unsigned int RP98R0:6;
         unsigned int :2;
         unsigned int RP99R0:6;
      };
      struct {
         unsigned int RP98R:6;
         unsigned int :2;
         unsigned int RP99R:6;
      };
} RPOR8BITS;
RPOR8BITS RPOR8bits;
#word RPOR8bits = 0x690
#word RPOR8 = 0x690

typedef union 
 {
      struct {
         unsigned int RP100R0:6;
         unsigned int :2;
         unsigned int RP101R0:6;
      };
      struct {
         unsigned int RP100R:6;
         unsigned int :2;
         unsigned int RP101R:6;
      };
} RPOR9BITS;
RPOR9BITS RPOR9bits;
#word RPOR9bits = 0x692
#word RPOR9 = 0x692

typedef union 
 {
      struct {
         unsigned int RP113R0:6;
         unsigned int :2;
         unsigned int RP118R0:6;
      };
      struct {
         unsigned int RP113R:6;
         unsigned int :2;
         unsigned int RP118R:6;
      };
} RPOR13BITS;
RPOR13BITS RPOR13bits;
#word RPOR13bits = 0x69A
#word RPOR13 = 0x69A

typedef union 
 {
      struct {
         unsigned int RP120R0:6;
         unsigned int :2;
         unsigned int RP125R0:6;
      };
      struct {
         unsigned int RP120R:6;
         unsigned int :2;
         unsigned int RP125R:6;
      };
} RPOR14BITS;
RPOR14BITS RPOR14bits;
#word RPOR14bits = 0x69C
#word RPOR14 = 0x69C

typedef union 
 {
      struct {
         unsigned int RSVR0:7;
         unsigned int :1;
         unsigned int INT1R0:7;
      };
      struct {
         unsigned int RSVR:7;
         unsigned int :1;
         unsigned int INT1R:7;
      };
} RPINR0BITS;
RPINR0BITS RPINR0bits;
#word RPINR0bits = 0x6A0
#word RPINR0 = 0x6A0

typedef union 
 {
      struct {
         unsigned int INT2R0:7;
         unsigned int :1;
         unsigned int INT3R0:7;
      };
      struct {
         unsigned int INT2R:7;
         unsigned int :1;
         unsigned int INT3R:7;
      };
} RPINR1BITS;
RPINR1BITS RPINR1bits;
#word RPINR1bits = 0x6A2
#word RPINR1 = 0x6A2

typedef union 
 {
      struct {
         unsigned int INT4R0:7;
         unsigned int :1;
         unsigned int RSVR0:7;
      };
      struct {
         unsigned int INT4R:7;
         unsigned int :1;
         unsigned int RSVR:7;
      };
} RPINR2BITS;
RPINR2BITS RPINR2bits;
#word RPINR2bits = 0x6A4
#word RPINR2 = 0x6A4

typedef union 
 {
      struct {
         unsigned int T2CKR0:7;
         unsigned int :1;
         unsigned int T3CKR0:7;
      };
      struct {
         unsigned int T2CKR:7;
         unsigned int :1;
         unsigned int T3CKR:7;
      };
} RPINR3BITS;
RPINR3BITS RPINR3bits;
#word RPINR3bits = 0x6A6
#word RPINR3 = 0x6A6

typedef union 
 {
      struct {
         unsigned int T4CKR0:7;
         unsigned int :1;
         unsigned int T5CKR0:7;
      };
      struct {
         unsigned int T4CKR:7;
         unsigned int :1;
         unsigned int T5CKR:7;
      };
} RPINR4BITS;
RPINR4BITS RPINR4bits;
#word RPINR4bits = 0x6A8
#word RPINR4 = 0x6A8

typedef union 
 {
      struct {
         unsigned int T6CKR0:7;
         unsigned int :1;
         unsigned int T7CKR0:7;
      };
      struct {
         unsigned int T6CKR:7;
         unsigned int :1;
         unsigned int T7CKR:7;
      };
} RPINR5BITS;
RPINR5BITS RPINR5bits;
#word RPINR5bits = 0x6AA
#word RPINR5 = 0x6AA

typedef union 
 {
      struct {
         unsigned int T8CKR0:7;
         unsigned int :1;
         unsigned int T9CKR0:7;
      };
      struct {
         unsigned int T8CKR:7;
         unsigned int :1;
         unsigned int T9CKR:7;
      };
} RPINR6BITS;
RPINR6BITS RPINR6bits;
#word RPINR6bits = 0x6AC
#word RPINR6 = 0x6AC

typedef union 
 {
      struct {
         unsigned int IC1R0:7;
         unsigned int :1;
         unsigned int IC2R0:7;
      };
      struct {
         unsigned int IC1R:7;
         unsigned int :1;
         unsigned int IC2R:7;
      };
} RPINR7BITS;
RPINR7BITS RPINR7bits;
#word RPINR7bits = 0x6AE
#word RPINR7 = 0x6AE

typedef union 
 {
      struct {
         unsigned int IC3R0:7;
         unsigned int :1;
         unsigned int IC4R0:7;
      };
      struct {
         unsigned int IC3R:7;
         unsigned int :1;
         unsigned int IC4R:7;
      };
} RPINR8BITS;
RPINR8BITS RPINR8bits;
#word RPINR8bits = 0x6B0
#word RPINR8 = 0x6B0

typedef union 
 {
      struct {
         unsigned int IC5R0:7;
         unsigned int :1;
         unsigned int IC6R0:7;
      };
      struct {
         unsigned int IC5R:7;
         unsigned int :1;
         unsigned int IC6R:7;
      };
} RPINR9BITS;
RPINR9BITS RPINR9bits;
#word RPINR9bits = 0x6B2
#word RPINR9 = 0x6B2

typedef union 
 {
      struct {
         unsigned int IC7R0:7;
         unsigned int :1;
         unsigned int IC8R0:7;
      };
      struct {
         unsigned int IC7R:7;
         unsigned int :1;
         unsigned int IC8R:7;
      };
} RPINR10BITS;
RPINR10BITS RPINR10bits;
#word RPINR10bits = 0x6B4
#word RPINR10 = 0x6B4

typedef union 
 {
      struct {
         unsigned int OCFAR0:7;
         unsigned int :1;
         unsigned int OCFBR0:7;
      };
      struct {
         unsigned int OCFAR:7;
         unsigned int :1;
         unsigned int OCFBR:7;
      };
} RPINR11BITS;
RPINR11BITS RPINR11bits;
#word RPINR11bits = 0x6B6
#word RPINR11 = 0x6B6

typedef union 
 {
      struct {
         unsigned int FLT1R0:7;
         unsigned int :1;
         unsigned int FLT2R0:7;
      };
      struct {
         unsigned int FLT1R:7;
         unsigned int :1;
         unsigned int FLT2R:7;
      };
} RPINR12BITS;
RPINR12BITS RPINR12bits;
#word RPINR12bits = 0x6B8
#word RPINR12 = 0x6B8

typedef union 
 {
      struct {
         unsigned int FLT3R0:7;
         unsigned int :1;
         unsigned int FLT4R0:7;
      };
      struct {
         unsigned int FLT3R:7;
         unsigned int :1;
         unsigned int FLT4R:7;
      };
} RPINR13BITS;
RPINR13BITS RPINR13bits;
#word RPINR13bits = 0x6BA
#word RPINR13 = 0x6BA

typedef union 
 {
      struct {
         unsigned int QEA1R0:7;
         unsigned int :1;
         unsigned int QEB1R0:7;
      };
      struct {
         unsigned int QEA1R:7;
         unsigned int :1;
         unsigned int QEB1R:7;
      };
} RPINR14BITS;
RPINR14BITS RPINR14bits;
#word RPINR14bits = 0x6BC
#word RPINR14 = 0x6BC

typedef union 
 {
      struct {
         unsigned int INDX1R0:7;
         unsigned int :1;
         unsigned int HOME1R0:7;
      };
      struct {
         unsigned int INDX1R:7;
         unsigned int :1;
         unsigned int HOME1R:7;
      };
} RPINR15BITS;
RPINR15BITS RPINR15bits;
#word RPINR15bits = 0x6BE
#word RPINR15 = 0x6BE

typedef union 
 {
      struct {
         unsigned int QEA2R0:7;
         unsigned int :1;
         unsigned int QEB2R0:7;
      };
      struct {
         unsigned int QEA2R:7;
         unsigned int :1;
         unsigned int QEB2R:7;
      };
} RPINR16BITS;
RPINR16BITS RPINR16bits;
#word RPINR16bits = 0x6C0
#word RPINR16 = 0x6C0

typedef union 
 {
      struct {
         unsigned int INDX2R0:7;
         unsigned int :1;
         unsigned int HOME2R0:7;
      };
      struct {
         unsigned int INDX2R:7;
         unsigned int :1;
         unsigned int HOME2R:7;
      };
} RPINR17BITS;
RPINR17BITS RPINR17bits;
#word RPINR17bits = 0x6C2
#word RPINR17 = 0x6C2

typedef union 
 {
      struct {
         unsigned int U1RXR0:7;
         unsigned int :1;
         unsigned int U1CTSR0:7;
      };
      struct {
         unsigned int U1RXR:7;
         unsigned int :1;
         unsigned int U1CTSR:7;
      };
} RPINR18BITS;
RPINR18BITS RPINR18bits;
#word RPINR18bits = 0x6C4
#word RPINR18 = 0x6C4

typedef union 
 {
      struct {
         unsigned int U2RXR0:7;
         unsigned int :1;
         unsigned int U2CTSR0:7;
      };
      struct {
         unsigned int U2RXR:7;
         unsigned int :1;
         unsigned int U2CTSR:7;
      };
} RPINR19BITS;
RPINR19BITS RPINR19bits;
#word RPINR19bits = 0x6C6
#word RPINR19 = 0x6C6

typedef union 
 {
      struct {
         unsigned int SDI1R0:7;
         unsigned int :1;
         unsigned int SCK1R0:7;
      };
      struct {
         unsigned int SDI1R:7;
         unsigned int :1;
         unsigned int SCK1R:7;
      };
} RPINR20BITS;
RPINR20BITS RPINR20bits;
#word RPINR20bits = 0x6C8
#word RPINR20 = 0x6C8

typedef union 
 {
      struct {
         unsigned int SS1R0:7;
         unsigned int :1;
         unsigned int RSVR0:7;
      };
      struct {
         unsigned int SS1R:7;
         unsigned int :1;
         unsigned int RSVR:7;
      };
} RPINR21BITS;
RPINR21BITS RPINR21bits;
#word RPINR21bits = 0x6CA
#word RPINR21 = 0x6CA

typedef union 
 {
      struct {
         unsigned int SS2R0:7;
         unsigned int :1;
         unsigned int RSVR0:7;
      };
      struct {
         unsigned int SS2R:7;
         unsigned int :1;
         unsigned int RSVR:7;
      };
} RPINR23BITS;
RPINR23BITS RPINR23bits;
#word RPINR23bits = 0x6CE
#word RPINR23 = 0x6CE

typedef union 
 {
      struct {
         unsigned int CSDIR0:7;
         unsigned int :1;
         unsigned int CSCKR0:7;
      };
      struct {
         unsigned int CSDIR:7;
         unsigned int :1;
         unsigned int CSCKR:7;
      };
} RPINR24BITS;
RPINR24BITS RPINR24bits;
#word RPINR24bits = 0x6D0
#word RPINR24 = 0x6D0

typedef union 
 {
      struct {
         unsigned int COFSR0:7;
         unsigned int :1;
         unsigned int RSVR0:7;
      };
      struct {
         unsigned int COFSR:7;
         unsigned int :1;
         unsigned int RSVR:7;
      };
} RPINR25BITS;
RPINR25BITS RPINR25bits;
#word RPINR25bits = 0x6D2
#word RPINR25 = 0x6D2

typedef union 
 {
      struct {
         unsigned int C1RXR0:7;
         unsigned int :1;
         unsigned int C2RXR0:7;
      };
      struct {
         unsigned int C1RXR:7;
         unsigned int :1;
         unsigned int C2RXR:7;
      };
} RPINR26BITS;
RPINR26BITS RPINR26bits;
#word RPINR26bits = 0x6D4
#word RPINR26 = 0x6D4

typedef union 
 {
      struct {
         unsigned int U3RXR0:7;
         unsigned int :1;
         unsigned int U3CTSR0:7;
      };
      struct {
         unsigned int U3RXR:7;
         unsigned int :1;
         unsigned int U3CTSR:7;
      };
} RPINR27BITS;
RPINR27BITS RPINR27bits;
#word RPINR27bits = 0x6D6
#word RPINR27 = 0x6D6

typedef union 
 {
      struct {
         unsigned int U4RXR0:7;
         unsigned int :1;
         unsigned int U4CTSR0:7;
      };
      struct {
         unsigned int U4RXR:7;
         unsigned int :1;
         unsigned int U4CTSR:7;
      };
} RPINR28BITS;
RPINR28BITS RPINR28bits;
#word RPINR28bits = 0x6D8
#word RPINR28 = 0x6D8

typedef union 
 {
      struct {
         unsigned int SDI3R0:7;
         unsigned int :1;
         unsigned int SCK3R0:7;
      };
      struct {
         unsigned int SDI3R:7;
         unsigned int :1;
         unsigned int SCK3R:7;
      };
} RPINR29BITS;
RPINR29BITS RPINR29bits;
#word RPINR29bits = 0x6DA
#word RPINR29 = 0x6DA

typedef union 
 {
      struct {
         unsigned int SS3R0:7;
         unsigned int :1;
         unsigned int RSVR0:7;
      };
      struct {
         unsigned int SS3R:7;
         unsigned int :1;
         unsigned int RSVR:7;
      };
} RPINR30BITS;
RPINR30BITS RPINR30bits;
#word RPINR30bits = 0x6DC
#word RPINR30 = 0x6DC

typedef union 
 {
      struct {
         unsigned int SDI4R0:7;
         unsigned int :1;
         unsigned int SCK4R0:7;
      };
      struct {
         unsigned int SDI4R:7;
         unsigned int :1;
         unsigned int SCK4R:7;
      };
} RPINR31BITS;
RPINR31BITS RPINR31bits;
#word RPINR31bits = 0x6DE
#word RPINR31 = 0x6DE

typedef union 
 {
      struct {
         unsigned int SS4R0:7;
         unsigned int :1;
         unsigned int RSVR0:7;
      };
      struct {
         unsigned int SS4R:7;
         unsigned int :1;
         unsigned int RSVR:7;
      };
} RPINR32BITS;
RPINR32BITS RPINR32bits;
#word RPINR32bits = 0x6E0
#word RPINR32 = 0x6E0

typedef union 
 {
      struct {
         unsigned int IC9R0:7;
         unsigned int :1;
         unsigned int IC10R0:7;
      };
      struct {
         unsigned int IC9R:7;
         unsigned int :1;
         unsigned int IC10R:7;
      };
} RPINR33BITS;
RPINR33BITS RPINR33bits;
#word RPINR33bits = 0x6E2
#word RPINR33 = 0x6E2

typedef union 
 {
      struct {
         unsigned int IC11R0:7;
         unsigned int :1;
         unsigned int IC12R0:7;
      };
      struct {
         unsigned int IC11R:7;
         unsigned int :1;
         unsigned int IC12R:7;
      };
} RPINR34BITS;
RPINR34BITS RPINR34bits;
#word RPINR34bits = 0x6E4
#word RPINR34 = 0x6E4

typedef union 
 {
      struct {
         unsigned int IC13R0:7;
         unsigned int :1;
         unsigned int IC14R0:7;
      };
      struct {
         unsigned int IC13R:7;
         unsigned int :1;
         unsigned int IC14R:7;
      };
} RPINR35BITS;
RPINR35BITS RPINR35bits;
#word RPINR35bits = 0x6E6
#word RPINR35 = 0x6E6

typedef union 
 {
      struct {
         unsigned int IC15R0:7;
         unsigned int :1;
         unsigned int IC16R0:7;
      };
      struct {
         unsigned int IC15R:7;
         unsigned int :1;
         unsigned int IC16R:7;
      };
} RPINR36BITS;
RPINR36BITS RPINR36bits;
#word RPINR36bits = 0x6E8
#word RPINR36 = 0x6E8

typedef union 
 {
      struct {
         unsigned int OCFCR0:7;
         unsigned int :1;
         unsigned int SYNCI1R0:7;
      };
      struct {
         unsigned int OCFCR:7;
         unsigned int :1;
         unsigned int SYNCI1R:7;
      };
} RPINR37BITS;
RPINR37BITS RPINR37bits;
#word RPINR37bits = 0x6EA
#word RPINR37 = 0x6EA

typedef union 
 {
      struct {
         unsigned int SYNCI2R0:7;
         unsigned int :1;
         unsigned int DTCMP1R0:7;
      };
      struct {
         unsigned int SYNCI2R:7;
         unsigned int :1;
         unsigned int DTCMP1R:7;
      };
} RPINR38BITS;
RPINR38BITS RPINR38bits;
#word RPINR38bits = 0x6EC
#word RPINR38 = 0x6EC

typedef union 
 {
      struct {
         unsigned int DTCMP2R0:7;
         unsigned int :1;
         unsigned int DTCMP3R0:7;
      };
      struct {
         unsigned int DTCMP2R:7;
         unsigned int :1;
         unsigned int DTCMP3R:7;
      };
} RPINR39BITS;
RPINR39BITS RPINR39bits;
#word RPINR39bits = 0x6EE
#word RPINR39 = 0x6EE

typedef union 
 {
      struct {
         unsigned int DTCMP4R0:7;
         unsigned int :1;
         unsigned int DTCMP5R0:7;
      };
      struct {
         unsigned int DTCMP4R:7;
         unsigned int :1;
         unsigned int DTCMP5R:7;
      };
} RPINR40BITS;
RPINR40BITS RPINR40bits;
#word RPINR40bits = 0x6F0
#word RPINR40 = 0x6F0

typedef union 
 {
      struct {
         unsigned int FLT5R0:7;
         unsigned int :1;
         unsigned int FLT6R0:7;
      };
      struct {
         unsigned int FLT5R:7;
         unsigned int :1;
         unsigned int FLT6R:7;
      };
} RPINR42BITS;
RPINR42BITS RPINR42bits;
#word RPINR42bits = 0x6F4
#word RPINR42 = 0x6F4

typedef union 
 {
      struct {
         unsigned int FLT7R0:7;
         unsigned int :1;
         unsigned int RSVR0:7;
      };
      struct {
         unsigned int FLT7R:7;
         unsigned int :1;
         unsigned int RSVR:7;
      };
} RPINR43BITS;
RPINR43BITS RPINR43bits;
#word RPINR43bits = 0x6F6
#word RPINR43 = 0x6F6

typedef union 
 {
      struct {
         unsigned int NVMOP0:4;
         unsigned int :8;
         unsigned int NVMSIDL:1;
         unsigned int WRERR:1;
         unsigned int WREN:1;
         unsigned int WR:1;
      };
      struct {
         unsigned int NVMOP:4;
         unsigned int :8;
      };
} NVMCONBITS;
NVMCONBITS NVMCONbits;
#word NVMCONbits = 0x728
#word NVMCON = 0x728

#word NVMADR = 0x72A

#word NVMADRU = 0x72C

#word NVMKEY = 0x72E

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
   unsigned int CM:1;
   unsigned int DPSLP:1;
   unsigned int VREGSF:1;
   unsigned int :1;
   unsigned int SBOREN:1;
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

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int RODIV0:4;
         unsigned int ROSEL:1;
         unsigned int ROSSLP:1;
         unsigned int :1;
         unsigned int ROON:1;
      };
      struct {
         unsigned int :8;
         unsigned int RODIV:4;
      };
} REFOCONBITS;
REFOCONBITS REFOCONbits;
#word REFOCONbits = 0x74E
#word REFOCON = 0x74E

typedef union 
 {
   union {
      struct {
         unsigned int APLLPRE0:3;
         unsigned int :2;
         unsigned int APLLPOST0:3;
         unsigned int :1;
         unsigned int FRCSEL:1;
         unsigned int ASRCSEL:1;
         unsigned int AOSCMD0:2;
         unsigned int SELACLK:1;
         unsigned int APLLCK:1;
         unsigned int ENAPLL:1;
      };
      struct {
         unsigned int APLLPRE:3;
         unsigned int :2;
         unsigned int APLLPOST:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int AOSCMD:2;
      };

      struct {
         unsigned int APPLPRE0:3;
      };
   };
      struct {
         unsigned int APPLPRE:3;
      };
} ACLKCON3BITS;
ACLKCON3BITS ACLKCON3bits;
#word ACLKCON3bits = 0x758
#word ACLKCON3 = 0x758

#word ACLKDIV3 = 0x75A

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
   unsigned int PWMMD:1;
   unsigned int QEI1MD:1;
   unsigned int T1MD:1;
   unsigned int T2MD:1;
   unsigned int T3MD:1;
   unsigned int T4MD:1;
   unsigned int T5MD:1;
} PMD1BITS;
PMD1BITS PMD1bits;
#word PMD1bits = 0x760
#word PMD1 = 0x760

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
#word PMD2bits = 0x762
#word PMD2 = 0x762

typedef struct 
 {
   unsigned int AD2MD:1;
   unsigned int I2C2MD:1;
   unsigned int I2C3MD:1;
   unsigned int U3MD:1;
   unsigned int :1;
   unsigned int QEI2MD:1;
   unsigned int DAC1MD:1;
   unsigned int CRCMD:1;
   unsigned int PMPMD:1;
   unsigned int RTCCMD:1;
   unsigned int CMPMD:1;
   unsigned int :1;
   unsigned int T6MD:1;
   unsigned int T7MD:1;
   unsigned int T8MD:1;
   unsigned int T9MD:1;
} PMD3BITS;
PMD3BITS PMD3bits;
#word PMD3bits = 0x764
#word PMD3 = 0x764

typedef struct 
 {
   unsigned int USB1MD:1;
   unsigned int LVDMD:1;
   unsigned int CTMUMD:1;
   unsigned int REFOMD:1;
   unsigned int EEMD:1;
   unsigned int U4MD:1;
} PMD4BITS;
PMD4BITS PMD4bits;
#word PMD4bits = 0x766
#word PMD4 = 0x766

typedef struct 
 {
   unsigned int OC9MD:1;
   unsigned int OC10MD:1;
   unsigned int OC11MD:1;
   unsigned int OC12MD:1;
   unsigned int OC13MD:1;
   unsigned int OC14MD:1;
   unsigned int OC15MD:1;
   unsigned int OC16MD:1;
   unsigned int IC9MD:1;
   unsigned int IC10MD:1;
   unsigned int IC11MD:1;
   unsigned int IC12MD:1;
   unsigned int IC13MD:1;
   unsigned int IC14MD:1;
   unsigned int IC15MD:1;
   unsigned int IC16MD:1;
} PMD5BITS;
PMD5BITS PMD5bits;
#word PMD5bits = 0x768
#word PMD5 = 0x768

typedef struct 
 {
   unsigned int SPI3MD:1;
   unsigned int SPI4MD:1;
   unsigned int :6;
   unsigned int PWM1MD:1;
   unsigned int PWM2MD:1;
   unsigned int PWM3MD:1;
   unsigned int PWM4MD:1;
   unsigned int PWM5MD:1;
   unsigned int PWM6MD:1;
   unsigned int PWM7MD:1;
   unsigned int PWM8MD:1;
} PMD6BITS;
PMD6BITS PMD6bits;
#word PMD6bits = 0x76A
#word PMD6 = 0x76A

typedef struct 
 {
   union {
      struct {
         unsigned int PWM9MD:1;
         unsigned int :3;
         unsigned int DMA0MD:1;
         unsigned int DMA4MD:1;
         unsigned int DMA8MD:1;
         unsigned int DMA12MD:1;
      };

   union {
      struct {
         unsigned int :4;
         unsigned int DMA1MD:1;
         unsigned int DMA5MD:1;
         unsigned int DMA9MD:1;
         unsigned int DMA13MD:1;
      };
   };

   union {
      struct {
         unsigned int :4;
         unsigned int DMA2MD:1;
         unsigned int DMA6MD:1;
         unsigned int DMA10MD:1;
         unsigned int DMA14MD:1;
      };
   };

      struct {
         unsigned int :4;
         unsigned int DMA3MD:1;
         unsigned int DMA7MD:1;
         unsigned int DMA11MD:1;
      };
   };
} PMD7BITS;
PMD7BITS PMD7bits;
#word PMD7bits = 0x76C
#word PMD7 = 0x76C

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
   unsigned int NVMIF:1;
} IFS0BITS;
IFS0BITS IFS0bits;
#word IFS0bits = 0x800
#word IFS0 = 0x800

typedef struct 
 {
   unsigned int SI2C1IF:1;
   unsigned int MI2C1IF:1;
   unsigned int CMIF:1;
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
} IFS1BITS;
IFS1BITS IFS1bits;
#word IFS1bits = 0x802
#word IFS1 = 0x802

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
   unsigned int PMPIF:1;
   unsigned int DMA4IF:1;
   unsigned int T6IF:1;
} IFS2BITS;
IFS2BITS IFS2bits;
#word IFS2bits = 0x804
#word IFS2 = 0x804

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
   unsigned int PSEMIF:1;
   unsigned int QEI1IF:1;
   unsigned int DCIEIF:1;
   unsigned int DCIIF:1;
   unsigned int DMA5IF:1;
   unsigned int RTCIF:1;
} IFS3BITS;
IFS3BITS IFS3bits;
#word IFS3bits = 0x806
#word IFS3 = 0x806

typedef struct 
 {
   unsigned int :1;
   unsigned int U1EIF:1;
   unsigned int U2EIF:1;
   unsigned int CRCIF:1;
   unsigned int DMA6IF:1;
   unsigned int DMA7IF:1;
   unsigned int C1TXIF:1;
   unsigned int C2TXIF:1;
   unsigned int :1;
   unsigned int PSESMIF:1;
   unsigned int :1;
   unsigned int QEI2IF:1;
} IFS4BITS;
IFS4BITS IFS4bits;
#word IFS4bits = 0x808
#word IFS4 = 0x808

typedef struct 
 {
   unsigned int :1;
   unsigned int U3EIF:1;
   unsigned int U3RXIF:1;
   unsigned int U3TXIF:1;
   unsigned int :2;
   unsigned int USB1IF:1;
   unsigned int U4EIF:1;
   unsigned int U4RXIF:1;
   unsigned int U4TXIF:1;
   unsigned int SPI3EIF:1;
   unsigned int SPI3IF:1;
   unsigned int OC9IF:1;
   unsigned int IC9IF:1;
   unsigned int PWM1IF:1;
   unsigned int PWM2IF:1;
} IFS5BITS;
IFS5BITS IFS5bits;
#word IFS5bits = 0x80A
#word IFS5 = 0x80A

typedef struct 
 {
   unsigned int PWM3IF:1;
   unsigned int PWM4IF:1;
   unsigned int PWM5IF:1;
   unsigned int PWM6IF:1;
   unsigned int PWM7IF:1;
} IFS6BITS;
IFS6BITS IFS6bits;
#word IFS6bits = 0x80C
#word IFS6 = 0x80C

typedef struct 
 {
   unsigned int :6;
   unsigned int DMA8IF:1;
   unsigned int DMA9IF:1;
   unsigned int DMA10IF:1;
   unsigned int DMA11IF:1;
   unsigned int SPI4EIF:1;
   unsigned int SPI4IF:1;
   unsigned int OC10IF:1;
   unsigned int IC10IF:1;
   unsigned int OC11IF:1;
   unsigned int IC11IF:1;
} IFS7BITS;
IFS7BITS IFS7bits;
#word IFS7bits = 0x80E
#word IFS7 = 0x80E

typedef struct 
 {
   unsigned int OC12IF:1;
   unsigned int IC12IF:1;
   unsigned int DMA12IF:1;
   unsigned int DMA13IF:1;
   unsigned int DMA14IF:1;
   unsigned int :1;
   unsigned int OC13IF:1;
   unsigned int IC13IF:1;
   unsigned int OC14IF:1;
   unsigned int IC14IF:1;
   unsigned int OC15IF:1;
   unsigned int IC15IF:1;
   unsigned int OC16IF:1;
   unsigned int IC16IF:1;
   unsigned int ICDIF:1;
} IFS8BITS;
IFS8BITS IFS8bits;
#word IFS8bits = 0x810
#word IFS8 = 0x810

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
   unsigned int NVMIE:1;
} IEC0BITS;
IEC0BITS IEC0bits;
#word IEC0bits = 0x820
#word IEC0 = 0x820

typedef struct 
 {
   unsigned int SI2C1IE:1;
   unsigned int MI2C1IE:1;
   unsigned int CMIE:1;
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
} IEC1BITS;
IEC1BITS IEC1bits;
#word IEC1bits = 0x822
#word IEC1 = 0x822

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
   unsigned int PMPIE:1;
   unsigned int DMA4IE:1;
   unsigned int T6IE:1;
} IEC2BITS;
IEC2BITS IEC2bits;
#word IEC2bits = 0x824
#word IEC2 = 0x824

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
   unsigned int PSEMIE:1;
   unsigned int QEI1IE:1;
   unsigned int DCIEIE:1;
   unsigned int DCIIE:1;
   unsigned int DMA5IE:1;
   unsigned int RTCIE:1;
} IEC3BITS;
IEC3BITS IEC3bits;
#word IEC3bits = 0x826
#word IEC3 = 0x826

typedef struct 
 {
   unsigned int :1;
   unsigned int U1EIE:1;
   unsigned int U2EIE:1;
   unsigned int CRCIE:1;
   unsigned int DMA6IE:1;
   unsigned int DMA7IE:1;
   unsigned int C1TXIE:1;
   unsigned int C2TXIE:1;
   unsigned int :1;
   unsigned int PSESMIE:1;
   unsigned int :1;
   unsigned int QEI2IE:1;
} IEC4BITS;
IEC4BITS IEC4bits;
#word IEC4bits = 0x828
#word IEC4 = 0x828

typedef struct 
 {
   unsigned int :1;
   unsigned int U3EIE:1;
   unsigned int U3RXIE:1;
   unsigned int U3TXIE:1;
   unsigned int :2;
   unsigned int USB1IE:1;
   unsigned int U4EIE:1;
   unsigned int U4RXIE:1;
   unsigned int U4TXIE:1;
   unsigned int SPI3EIE:1;
   unsigned int SPI3IE:1;
   unsigned int OC9IE:1;
   unsigned int IC9IE:1;
   unsigned int PWM1IE:1;
   unsigned int PWM2IE:1;
} IEC5BITS;
IEC5BITS IEC5bits;
#word IEC5bits = 0x82A
#word IEC5 = 0x82A

typedef struct 
 {
   unsigned int PWM3IE:1;
   unsigned int PWM4IE:1;
   unsigned int PWM5IE:1;
   unsigned int PWM6IE:1;
   unsigned int PWM7IE:1;
} IEC6BITS;
IEC6BITS IEC6bits;
#word IEC6bits = 0x82C
#word IEC6 = 0x82C

typedef struct 
 {
   unsigned int :6;
   unsigned int DMA8IE:1;
   unsigned int DMA9IE:1;
   unsigned int DMA10IE:1;
   unsigned int DMA11IE:1;
   unsigned int SPI4EIE:1;
   unsigned int SPI4IE:1;
   unsigned int OC10IE:1;
   unsigned int IC10IE:1;
   unsigned int OC11IE:1;
   unsigned int IC11IE:1;
} IEC7BITS;
IEC7BITS IEC7bits;
#word IEC7bits = 0x82E
#word IEC7 = 0x82E

typedef struct 
 {
   unsigned int OC12IE:1;
   unsigned int IC12IE:1;
   unsigned int DMA12IE:1;
   unsigned int DMA13IE:1;
   unsigned int DMA14IE:1;
   unsigned int :1;
   unsigned int OC13IE:1;
   unsigned int IC13IE:1;
   unsigned int OC14IE:1;
   unsigned int IC14IE:1;
   unsigned int OC15IE:1;
   unsigned int IC15IE:1;
   unsigned int OC16IE:1;
   unsigned int IC16IE:1;
   unsigned int ICDIF:1;
} IEC8BITS;
IEC8BITS IEC8bits;
#word IEC8bits = 0x830
#word IEC8 = 0x830

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
#word IPC0bits = 0x840
#word IPC0 = 0x840

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
#word IPC1bits = 0x842
#word IPC1 = 0x842

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
#word IPC2bits = 0x844
#word IPC2 = 0x844

typedef union 
 {
      struct {
         unsigned int U1TXIP0:3;
         unsigned int :1;
         unsigned int AD1IP0:3;
         unsigned int :1;
         unsigned int DMA1IP0:3;
         unsigned int :1;
         unsigned int NVMIP0:3;
      };
      struct {
         unsigned int U1TXIP:3;
         unsigned int :1;
         unsigned int AD1IP:3;
         unsigned int :1;
         unsigned int DMA1IP:3;
         unsigned int :1;
         unsigned int NVMIP:3;
      };
} IPC3BITS;
IPC3BITS IPC3bits;
#word IPC3bits = 0x846
#word IPC3 = 0x846

typedef union 
 {
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
} IPC4BITS;
IPC4BITS IPC4bits;
#word IPC4bits = 0x848
#word IPC4 = 0x848

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
#word IPC5bits = 0x84A
#word IPC5 = 0x84A

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
#word IPC6bits = 0x84C
#word IPC6 = 0x84C

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
#word IPC7bits = 0x84E
#word IPC7 = 0x84E

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
#word IPC8bits = 0x850
#word IPC8 = 0x850

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
#word IPC9bits = 0x852
#word IPC9 = 0x852

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
#word IPC10bits = 0x854
#word IPC10 = 0x854

typedef union 
 {
      struct {
         unsigned int OC8IP0:3;
         unsigned int :1;
         unsigned int PMPIP0:3;
         unsigned int :1;
         unsigned int DMA4IP0:3;
         unsigned int :1;
         unsigned int T6IP0:3;
      };
      struct {
         unsigned int OC8IP:3;
         unsigned int :1;
         unsigned int PMPIP:3;
         unsigned int :1;
         unsigned int DMA4IP:3;
         unsigned int :1;
         unsigned int T6IP:3;
      };
} IPC11BITS;
IPC11BITS IPC11bits;
#word IPC11bits = 0x856
#word IPC11 = 0x856

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
#word IPC12bits = 0x858
#word IPC12 = 0x858

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
#word IPC13bits = 0x85A
#word IPC13 = 0x85A

typedef union 
 {
      struct {
         unsigned int C2IP0:3;
         unsigned int :1;
         unsigned int PSEMIP0:3;
         unsigned int :1;
         unsigned int QEI1IP0:3;
         unsigned int :1;
         unsigned int DCIEIP0:3;
      };
      struct {
         unsigned int C2IP:3;
         unsigned int :1;
         unsigned int PSEMIP:3;
         unsigned int :1;
         unsigned int QEI1IP:3;
         unsigned int :1;
         unsigned int DCIEIP:3;
      };
} IPC14BITS;
IPC14BITS IPC14bits;
#word IPC14bits = 0x85C
#word IPC14 = 0x85C

typedef union 
 {
      struct {
         unsigned int DCIIP0:3;
         unsigned int :1;
         unsigned int DMA5IP0:3;
         unsigned int :1;
         unsigned int RTCIP0:3;
      };
      struct {
         unsigned int DCIIP:3;
         unsigned int :1;
         unsigned int DMA5IP:3;
         unsigned int :1;
         unsigned int RTCIP:3;
      };
} IPC15BITS;
IPC15BITS IPC15bits;
#word IPC15bits = 0x85E
#word IPC15 = 0x85E

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int U1EIP0:3;
         unsigned int :1;
         unsigned int U2EIP0:3;
         unsigned int :1;
         unsigned int CRCIP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int U1EIP:3;
         unsigned int :1;
         unsigned int U2EIP:3;
         unsigned int :1;
         unsigned int CRCIP:3;
      };
} IPC16BITS;
IPC16BITS IPC16bits;
#word IPC16bits = 0x860
#word IPC16 = 0x860

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
#word IPC17bits = 0x862
#word IPC17 = 0x862

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int PSESMIP0:3;
         unsigned int :5;
         unsigned int QEI2IP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int PSESMIP:3;
         unsigned int :5;
         unsigned int QEI2IP:3;
      };
} IPC18BITS;
IPC18BITS IPC18bits;
#word IPC18bits = 0x864
#word IPC18 = 0x864

typedef union 
 {
      struct {
         unsigned int :4;
         unsigned int U3EIP0:3;
         unsigned int :1;
         unsigned int U3RXIP0:3;
         unsigned int :1;
         unsigned int U3TXIP0:3;
      };
      struct {
         unsigned int :4;
         unsigned int U3EIP:3;
         unsigned int :1;
         unsigned int U3RXIP:3;
         unsigned int :1;
         unsigned int U3TXIP:3;
      };
} IPC20BITS;
IPC20BITS IPC20bits;
#word IPC20bits = 0x868
#word IPC20 = 0x868

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int USB1IP0:3;
         unsigned int :1;
         unsigned int U4EIP0:3;
      };
      struct {
         unsigned int :8;
         unsigned int USB1IP:3;
         unsigned int :1;
         unsigned int U4EIP:3;
      };
} IPC21BITS;
IPC21BITS IPC21bits;
#word IPC21bits = 0x86A
#word IPC21 = 0x86A

typedef union 
 {
      struct {
         unsigned int U4RXIP0:3;
         unsigned int :1;
         unsigned int U4TXIP0:3;
         unsigned int :1;
         unsigned int SPI3EIP0:3;
         unsigned int :1;
         unsigned int SPI3IP0:3;
      };
      struct {
         unsigned int U4RXIP:3;
         unsigned int :1;
         unsigned int U4TXIP:3;
         unsigned int :1;
         unsigned int SPI3EIP:3;
         unsigned int :1;
         unsigned int SPI3IP:3;
      };
} IPC22BITS;
IPC22BITS IPC22bits;
#word IPC22bits = 0x86C
#word IPC22 = 0x86C

typedef union 
 {
      struct {
         unsigned int OC9IP0:3;
         unsigned int :1;
         unsigned int IC9IP0:3;
         unsigned int :1;
         unsigned int PWM1IP0:3;
         unsigned int :1;
         unsigned int PWM2IP0:3;
      };
      struct {
         unsigned int OC9IP:3;
         unsigned int :1;
         unsigned int IC9IP:3;
         unsigned int :1;
         unsigned int PWM1IP:3;
         unsigned int :1;
         unsigned int PWM2IP:3;
      };
} IPC23BITS;
IPC23BITS IPC23bits;
#word IPC23bits = 0x86E
#word IPC23 = 0x86E

typedef union 
 {
      struct {
         unsigned int PWM3IP0:3;
         unsigned int :1;
         unsigned int PWM4IP0:3;
         unsigned int :1;
         unsigned int PWM5IP0:3;
         unsigned int :1;
         unsigned int PWM6IP0:3;
      };
      struct {
         unsigned int PWM3IP:3;
         unsigned int :1;
         unsigned int PWM4IP:3;
         unsigned int :1;
         unsigned int PWM5IP:3;
         unsigned int :1;
         unsigned int PWM6IP:3;
      };
} IPC24BITS;
IPC24BITS IPC24bits;
#word IPC24bits = 0x870
#word IPC24 = 0x870

typedef union 
 {
      struct {
         unsigned int :8;
         unsigned int DMA8IP0:3;
         unsigned int :1;
         unsigned int DMA9IP0:3;
      };
      struct {
         unsigned int :8;
         unsigned int DMA8IP:3;
         unsigned int :1;
         unsigned int DMA9IP:3;
      };
} IPC29BITS;
IPC29BITS IPC29bits;
#word IPC29bits = 0x87A
#word IPC29 = 0x87A

typedef union 
 {
      struct {
         unsigned int DMA10IP0:3;
         unsigned int :1;
         unsigned int DMA11IP0:3;
         unsigned int :1;
         unsigned int SPI4EIP0:3;
         unsigned int :1;
         unsigned int SPI4IP0:3;
      };
      struct {
         unsigned int DMA10IP:3;
         unsigned int :1;
         unsigned int DMA11IP:3;
         unsigned int :1;
         unsigned int SPI4EIP:3;
         unsigned int :1;
         unsigned int SPI4IP:3;
      };
} IPC30BITS;
IPC30BITS IPC30bits;
#word IPC30bits = 0x87C
#word IPC30 = 0x87C

typedef union 
 {
      struct {
         unsigned int OC10IP0:3;
         unsigned int :1;
         unsigned int IC10IP0:3;
         unsigned int :1;
         unsigned int OC11IP0:3;
         unsigned int :1;
         unsigned int IC11IP0:3;
      };
      struct {
         unsigned int OC10IP:3;
         unsigned int :1;
         unsigned int IC10IP:3;
         unsigned int :1;
         unsigned int OC11IP:3;
         unsigned int :1;
         unsigned int IC11IP:3;
      };
} IPC31BITS;
IPC31BITS IPC31bits;
#word IPC31bits = 0x87E
#word IPC31 = 0x87E

typedef union 
 {
      struct {
         unsigned int OC12IP0:3;
         unsigned int :1;
         unsigned int IC12IP0:3;
         unsigned int :1;
         unsigned int DMA12IP0:3;
         unsigned int :1;
         unsigned int DMA13IP0:3;
      };
      struct {
         unsigned int OC12IP:3;
         unsigned int :1;
         unsigned int IC12IP:3;
         unsigned int :1;
         unsigned int DMA12IP:3;
         unsigned int :1;
         unsigned int DMA13IP:3;
      };
} IPC32BITS;
IPC32BITS IPC32bits;
#word IPC32bits = 0x880
#word IPC32 = 0x880

typedef union 
 {
      struct {
         unsigned int DMA14IP0:3;
         unsigned int :5;
         unsigned int OC13IP0:3;
         unsigned int :1;
         unsigned int IC13IP0:3;
      };
      struct {
         unsigned int DMA14IP:3;
         unsigned int :5;
         unsigned int OC13IP:3;
         unsigned int :1;
         unsigned int IC13IP:3;
      };
} IPC33BITS;
IPC33BITS IPC33bits;
#word IPC33bits = 0x882
#word IPC33 = 0x882

typedef union 
 {
      struct {
         unsigned int OC14IP0:3;
         unsigned int :1;
         unsigned int IC14IP0:3;
         unsigned int :1;
         unsigned int OC15IP0:3;
         unsigned int :1;
         unsigned int IC15IP0:3;
      };
      struct {
         unsigned int OC14IP:3;
         unsigned int :1;
         unsigned int IC14IP:3;
         unsigned int :1;
         unsigned int OC15IP:3;
         unsigned int :1;
         unsigned int IC15IP:3;
      };
} IPC34BITS;
IPC34BITS IPC34bits;
#word IPC34bits = 0x884
#word IPC34 = 0x884

typedef union 
 {
      struct {
         unsigned int OC16IP0:3;
         unsigned int :1;
         unsigned int IC16IP0:3;
         unsigned int :1;
         unsigned int ICDIP0:3;
      };
      struct {
         unsigned int OC16IP:3;
         unsigned int :1;
         unsigned int IC16IP:3;
         unsigned int :1;
         unsigned int ICDIP:3;
      };
} IPC35BITS;
IPC35BITS IPC35bits;
#word IPC35bits = 0x886
#word IPC35 = 0x886

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
#word INTCON1bits = 0x8C0
#word INTCON1 = 0x8C0

typedef struct 
 {
   unsigned int INT0EP:1;
   unsigned int INT1EP:1;
   unsigned int INT2EP:1;
   unsigned int INT3EP:1;
   unsigned int INT4EP:1;
   unsigned int :8;
   unsigned int SWTRAP:1;
   unsigned int DISI:1;
   unsigned int GIE:1;
} INTCON2BITS;
INTCON2BITS INTCON2bits;
#word INTCON2bits = 0x8C2
#word INTCON2 = 0x8C2

typedef struct 
 {
   unsigned int :4;
   unsigned int DOOVR:1;
   unsigned int DAE:1;
   unsigned int UAE:1;
} INTCON3BITS;
INTCON3BITS INTCON3bits;
#word INTCON3bits = 0x8C4
#word INTCON3 = 0x8C4

typedef struct 
 {
   unsigned int SGHT:1;
} INTCON4BITS;
INTCON4BITS INTCON4bits;
#word INTCON4bits = 0x8C6
#word INTCON4 = 0x8C6

typedef union 
 {
      struct {
         unsigned int VECNUM0:8;
         unsigned int ILR0:4;
      };
      struct {
         unsigned int VECNUM:8;
         unsigned int ILR:4;
      };
} INTTREGBITS;
INTTREGBITS INTTREGbits;
#word INTTREGbits = 0x8C8
#word INTTREG = 0x8C8

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC1CON1BITS;
OC1CON1BITS OC1CON1bits;
#word OC1CON1bits = 0x900
#word OC1CON1 = 0x900

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC1CON2BITS;
OC1CON2BITS OC1CON2bits;
#word OC1CON2bits = 0x902
#word OC1CON2 = 0x902

#word OC1RS = 0x904

#word OC1R = 0x906

#word OC1TMR = 0x908

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC2CON1BITS;
OC2CON1BITS OC2CON1bits;
#word OC2CON1bits = 0x90A
#word OC2CON1 = 0x90A

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC2CON2BITS;
OC2CON2BITS OC2CON2bits;
#word OC2CON2bits = 0x90C
#word OC2CON2 = 0x90C

#word OC2RS = 0x90E

#word OC2R = 0x910

#word OC2TMR = 0x912

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC3CON1BITS;
OC3CON1BITS OC3CON1bits;
#word OC3CON1bits = 0x914
#word OC3CON1 = 0x914

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC3CON2BITS;
OC3CON2BITS OC3CON2bits;
#word OC3CON2bits = 0x916
#word OC3CON2 = 0x916

#word OC3RS = 0x918

#word OC3R = 0x91A

#word OC3TMR = 0x91C

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC4CON1BITS;
OC4CON1BITS OC4CON1bits;
#word OC4CON1bits = 0x91E
#word OC4CON1 = 0x91E

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC4CON2BITS;
OC4CON2BITS OC4CON2bits;
#word OC4CON2bits = 0x920
#word OC4CON2 = 0x920

#word OC4RS = 0x922

#word OC4R = 0x924

#word OC4TMR = 0x926

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC5CON1BITS;
OC5CON1BITS OC5CON1bits;
#word OC5CON1bits = 0x928
#word OC5CON1 = 0x928

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC5CON2BITS;
OC5CON2BITS OC5CON2bits;
#word OC5CON2bits = 0x92A
#word OC5CON2 = 0x92A

#word OC5RS = 0x92C

#word OC5R = 0x92E

#word OC5TMR = 0x930

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC6CON1BITS;
OC6CON1BITS OC6CON1bits;
#word OC6CON1bits = 0x932
#word OC6CON1 = 0x932

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC6CON2BITS;
OC6CON2BITS OC6CON2bits;
#word OC6CON2bits = 0x934
#word OC6CON2 = 0x934

#word OC6RS = 0x936

#word OC6R = 0x938

#word OC6TMR = 0x93A

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC7CON1BITS;
OC7CON1BITS OC7CON1bits;
#word OC7CON1bits = 0x93C
#word OC7CON1 = 0x93C

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC7CON2BITS;
OC7CON2BITS OC7CON2bits;
#word OC7CON2bits = 0x93E
#word OC7CON2 = 0x93E

#word OC7RS = 0x940

#word OC7R = 0x942

#word OC7TMR = 0x944

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC8CON1BITS;
OC8CON1BITS OC8CON1bits;
#word OC8CON1bits = 0x946
#word OC8CON1 = 0x946

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC8CON2BITS;
OC8CON2BITS OC8CON2bits;
#word OC8CON2bits = 0x948
#word OC8CON2 = 0x948

#word OC8RS = 0x94A

#word OC8R = 0x94C

#word OC8TMR = 0x94E

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC9CON1BITS;
OC9CON1BITS OC9CON1bits;
#word OC9CON1bits = 0x950
#word OC9CON1 = 0x950

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC9CON2BITS;
OC9CON2BITS OC9CON2bits;
#word OC9CON2bits = 0x952
#word OC9CON2 = 0x952

#word OC9RS = 0x954

#word OC9R = 0x956

#word OC9TMR = 0x958

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC10CON1BITS;
OC10CON1BITS OC10CON1bits;
#word OC10CON1bits = 0x95A
#word OC10CON1 = 0x95A

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC10CON2BITS;
OC10CON2BITS OC10CON2bits;
#word OC10CON2bits = 0x95C
#word OC10CON2 = 0x95C

#word OC10RS = 0x95E

#word OC10R = 0x960

#word OC10TMR = 0x962

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC11CON1BITS;
OC11CON1BITS OC11CON1bits;
#word OC11CON1bits = 0x964
#word OC11CON1 = 0x964

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC11CON2BITS;
OC11CON2BITS OC11CON2bits;
#word OC11CON2bits = 0x966
#word OC11CON2 = 0x966

#word OC11RS = 0x968

#word OC11R = 0x96A

#word OC11TMR = 0x96C

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC12CON1BITS;
OC12CON1BITS OC12CON1bits;
#word OC12CON1bits = 0x96E
#word OC12CON1 = 0x96E

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC12CON2BITS;
OC12CON2BITS OC12CON2bits;
#word OC12CON2bits = 0x970
#word OC12CON2 = 0x970

#word OC12RS = 0x972

#word OC12R = 0x974

#word OC12TMR = 0x976

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC13CON1BITS;
OC13CON1BITS OC13CON1bits;
#word OC13CON1bits = 0x978
#word OC13CON1 = 0x978

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC13CON2BITS;
OC13CON2BITS OC13CON2bits;
#word OC13CON2bits = 0x97A
#word OC13CON2 = 0x97A

#word OC13RS = 0x97C

#word OC13R = 0x97E

#word OC13TMR = 0x980

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC14CON1BITS;
OC14CON1BITS OC14CON1bits;
#word OC14CON1bits = 0x982
#word OC14CON1 = 0x982

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC14CON2BITS;
OC14CON2BITS OC14CON2bits;
#word OC14CON2bits = 0x984
#word OC14CON2 = 0x984

#word OC14RS = 0x986

#word OC14R = 0x988

#word OC14TMR = 0x98A

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC15CON1BITS;
OC15CON1BITS OC15CON1bits;
#word OC15CON1bits = 0x98C
#word OC15CON1 = 0x98C

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC15CON2BITS;
OC15CON2BITS OC15CON2bits;
#word OC15CON2bits = 0x98E
#word OC15CON2 = 0x98E

#word OC15RS = 0x990

#word OC15R = 0x992

#word OC15TMR = 0x994

typedef union 
 {
   union {
      struct {
         unsigned int OCM0:3;
         unsigned int TRIGMODE:1;
         unsigned int OCFLTA:1;
         unsigned int OCFLTB:1;
         unsigned int OCFLTC:1;
         unsigned int ENFLTA:1;
         unsigned int ENFLTB:1;
         unsigned int ENFLTC:1;
         unsigned int OCTSEL0:3;
         unsigned int OCSIDL:1;
      };
      struct {
         unsigned int OCM:3;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OCTSEL:3;
      };

      struct {
         unsigned int :4;
         unsigned int OCFLT0:3;
         unsigned int ENFLT0:3;
      };
   };
      struct {
         unsigned int :4;
         unsigned int OCFLT:3;
         unsigned int ENFLT:3;
      };
} OC16CON1BITS;
OC16CON1BITS OC16CON1bits;
#word OC16CON1bits = 0x996
#word OC16CON1 = 0x996

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
         unsigned int :14;
         unsigned int FLTMODE:1;
      };
   };
} OC16CON2BITS;
OC16CON2BITS OC16CON2bits;
#word OC16CON2bits = 0x998
#word OC16CON2 = 0x998

#word OC16RS = 0x99A

#word OC16R = 0x99C

#word OC16TMR = 0x99E

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
   unsigned int CMSIDL:1;
} CMSTATBITS;
CMSTATBITS CMSTATbits;
#word CMSTATbits = 0xA80
#word CMSTAT = 0xA80

typedef union 
 {
      struct {
         unsigned int CVR0:4;
         unsigned int CVRSS:1;
         unsigned int CVRR:1;
         unsigned int CVROE:1;
         unsigned int CVREN:1;
         unsigned int BGSEL0:2;
         unsigned int VREFSEL:1;
      };
      struct {
         unsigned int CVR:4;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int BGSEL:2;
      };
} CVRCONBITS;
CVRCONBITS CVRCONbits;
#word CVRCONbits = 0xA82
#word CVRCON = 0xA82

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
         unsigned int :2;
         unsigned int CLPWR:1;
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
         unsigned int :2;
      };

      struct {
         unsigned int :15;
         unsigned int CEN:1;
      };
   };
} CM1CONBITS;
CM1CONBITS CM1CONbits;
#word CM1CONbits = 0xA84
#word CM1CON = 0xA84

typedef union 
 {
      struct {
         unsigned int SELSRCA0:4;
         unsigned int SELSRCB0:4;
         unsigned int SELSRCC0:4;
      };
      struct {
         unsigned int SELSRCA:4;
         unsigned int SELSRCB:4;
         unsigned int SELSRCC:4;
      };
} CM1MSKSRCBITS;
CM1MSKSRCBITS CM1MSKSRCbits;
#word CM1MSKSRCbits = 0xA86
#word CM1MSKSRC = 0xA86

typedef struct 
 {
   unsigned int AANEN:1;
   unsigned int AAEN:1;
   unsigned int ABNEN:1;
   unsigned int ABEN:1;
   unsigned int ACNEN:1;
   unsigned int ACEN:1;
   unsigned int PAGS:1;
   unsigned int NAGS:1;
   unsigned int OANEN:1;
   unsigned int OAEN:1;
   unsigned int OBNEN:1;
   unsigned int OBEN:1;
   unsigned int OCNEN:1;
   unsigned int OCEN:1;
   unsigned int :1;
   unsigned int HLMS:1;
} CM1MSKCONBITS;
CM1MSKCONBITS CM1MSKCONbits;
#word CM1MSKCONbits = 0xA88
#word CM1MSKCON = 0xA88

typedef union 
 {
      struct {
         unsigned int CFDIV0:3;
         unsigned int CFLTREN:1;
         unsigned int CFSEL0:3;
      };
      struct {
         unsigned int CFDIV:3;
         unsigned int :1;
         unsigned int CFSEL:3;
      };
} CM1FLTRBITS;
CM1FLTRBITS CM1FLTRbits;
#word CM1FLTRbits = 0xA8A
#word CM1FLTR = 0xA8A

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
         unsigned int :2;
         unsigned int CLPWR:1;
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
         unsigned int :2;
      };

      struct {
         unsigned int :15;
         unsigned int CEN:1;
      };
   };
} CM2CONBITS;
CM2CONBITS CM2CONbits;
#word CM2CONbits = 0xA8C
#word CM2CON = 0xA8C

typedef union 
 {
      struct {
         unsigned int SELSRCA0:4;
         unsigned int SELSRCB0:4;
         unsigned int SELSRCC0:4;
      };
      struct {
         unsigned int SELSRCA:4;
         unsigned int SELSRCB:4;
         unsigned int SELSRCC:4;
      };
} CM2MSKSRCBITS;
CM2MSKSRCBITS CM2MSKSRCbits;
#word CM2MSKSRCbits = 0xA8E
#word CM2MSKSRC = 0xA8E

typedef struct 
 {
   unsigned int AANEN:1;
   unsigned int AAEN:1;
   unsigned int ABNEN:1;
   unsigned int ABEN:1;
   unsigned int ACNEN:1;
   unsigned int ACEN:1;
   unsigned int PAGS:1;
   unsigned int NAGS:1;
   unsigned int OANEN:1;
   unsigned int OAEN:1;
   unsigned int OBNEN:1;
   unsigned int OBEN:1;
   unsigned int OCNEN:1;
   unsigned int OCEN:1;
   unsigned int :1;
   unsigned int HLMS:1;
} CM2MSKCONBITS;
CM2MSKCONBITS CM2MSKCONbits;
#word CM2MSKCONbits = 0xA90
#word CM2MSKCON = 0xA90

typedef union 
 {
      struct {
         unsigned int CFDIV0:3;
         unsigned int CFLTREN:1;
         unsigned int CFSEL0:3;
      };
      struct {
         unsigned int CFDIV:3;
         unsigned int :1;
         unsigned int CFSEL:3;
      };
} CM2FLTRBITS;
CM2FLTRBITS CM2FLTRbits;
#word CM2FLTRbits = 0xA92
#word CM2FLTR = 0xA92

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
         unsigned int :2;
         unsigned int CLPWR:1;
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
         unsigned int :2;
      };

      struct {
         unsigned int :15;
         unsigned int CEN:1;
      };
   };
} CM3CONBITS;
CM3CONBITS CM3CONbits;
#word CM3CONbits = 0xA94
#word CM3CON = 0xA94

typedef union 
 {
      struct {
         unsigned int SELSRCA0:4;
         unsigned int SELSRCB0:4;
         unsigned int SELSRCC0:4;
      };
      struct {
         unsigned int SELSRCA:4;
         unsigned int SELSRCB:4;
         unsigned int SELSRCC:4;
      };
} CM3MSKSRCBITS;
CM3MSKSRCBITS CM3MSKSRCbits;
#word CM3MSKSRCbits = 0xA96
#word CM3MSKSRC = 0xA96

typedef struct 
 {
   unsigned int AANEN:1;
   unsigned int AAEN:1;
   unsigned int ABNEN:1;
   unsigned int ABEN:1;
   unsigned int ACNEN:1;
   unsigned int ACEN:1;
   unsigned int PAGS:1;
   unsigned int NAGS:1;
   unsigned int OANEN:1;
   unsigned int OAEN:1;
   unsigned int OBNEN:1;
   unsigned int OBEN:1;
   unsigned int OCNEN:1;
   unsigned int OCEN:1;
   unsigned int :1;
   unsigned int HLMS:1;
} CM3MSKCONBITS;
CM3MSKCONBITS CM3MSKCONbits;
#word CM3MSKCONbits = 0xA98
#word CM3MSKCON = 0xA98

typedef union 
 {
      struct {
         unsigned int CFDIV0:3;
         unsigned int CFLTREN:1;
         unsigned int CFSEL0:3;
      };
      struct {
         unsigned int CFDIV:3;
         unsigned int :1;
         unsigned int CFSEL:3;
      };
} CM3FLTRBITS;
CM3FLTRBITS CM3FLTRbits;
#word CM3FLTRbits = 0xA9A
#word CM3FLTR = 0xA9A

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
#word DMA0CONbits = 0xB00
#word DMA0CON = 0xB00

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA0REQBITS;
DMA0REQBITS DMA0REQbits;
#word DMA0REQbits = 0xB02
#word DMA0REQ = 0xB02

#word DMA0STA = 0xB04

#word DMA0STB = 0xB08

#word DMA0PAD = 0xB0C

#word DMA0CNT = 0xB0E

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
#word DMA1CONbits = 0xB10
#word DMA1CON = 0xB10

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA1REQBITS;
DMA1REQBITS DMA1REQbits;
#word DMA1REQbits = 0xB12
#word DMA1REQ = 0xB12

#word DMA1STA = 0xB14

#word DMA1STB = 0xB18

#word DMA1PAD = 0xB1C

#word DMA1CNT = 0xB1E

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
#word DMA2CONbits = 0xB20
#word DMA2CON = 0xB20

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA2REQBITS;
DMA2REQBITS DMA2REQbits;
#word DMA2REQbits = 0xB22
#word DMA2REQ = 0xB22

#word DMA2STA = 0xB24

#word DMA2STB = 0xB28

#word DMA2PAD = 0xB2C

#word DMA2CNT = 0xB2E

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
#word DMA3CONbits = 0xB30
#word DMA3CON = 0xB30

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA3REQBITS;
DMA3REQBITS DMA3REQbits;
#word DMA3REQbits = 0xB32
#word DMA3REQ = 0xB32

#word DMA3STA = 0xB34

#word DMA3STB = 0xB38

#word DMA3PAD = 0xB3C

#word DMA3CNT = 0xB3E

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
#word DMA4CONbits = 0xB40
#word DMA4CON = 0xB40

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA4REQBITS;
DMA4REQBITS DMA4REQbits;
#word DMA4REQbits = 0xB42
#word DMA4REQ = 0xB42

#word DMA4STA = 0xB44

#word DMA4STB = 0xB48

#word DMA4PAD = 0xB4C

#word DMA4CNT = 0xB4E

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
#word DMA5CONbits = 0xB50
#word DMA5CON = 0xB50

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA5REQBITS;
DMA5REQBITS DMA5REQbits;
#word DMA5REQbits = 0xB52
#word DMA5REQ = 0xB52

#word DMA5STA = 0xB54

#word DMA5STB = 0xB58

#word DMA5PAD = 0xB5C

#word DMA5CNT = 0xB5E

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
#word DMA6CONbits = 0xB60
#word DMA6CON = 0xB60

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA6REQBITS;
DMA6REQBITS DMA6REQbits;
#word DMA6REQbits = 0xB62
#word DMA6REQ = 0xB62

#word DMA6STA = 0xB64

#word DMA6STB = 0xB68

#word DMA6PAD = 0xB6C

#word DMA6CNT = 0xB6E

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
#word DMA7CONbits = 0xB70
#word DMA7CON = 0xB70

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA7REQBITS;
DMA7REQBITS DMA7REQbits;
#word DMA7REQbits = 0xB72
#word DMA7REQ = 0xB72

#word DMA7STA = 0xB74

#word DMA7STB = 0xB78

#word DMA7PAD = 0xB7C

#word DMA7CNT = 0xB7E

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
} DMA8CONBITS;
DMA8CONBITS DMA8CONbits;
#word DMA8CONbits = 0xB80
#word DMA8CON = 0xB80

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA8REQBITS;
DMA8REQBITS DMA8REQbits;
#word DMA8REQbits = 0xB82
#word DMA8REQ = 0xB82

#word DMA8STA = 0xB84

#word DMA8STB = 0xB88

#word DMA8PAD = 0xB8C

#word DMA8CNT = 0xB8E

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
} DMA9CONBITS;
DMA9CONBITS DMA9CONbits;
#word DMA9CONbits = 0xB90
#word DMA9CON = 0xB90

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA9REQBITS;
DMA9REQBITS DMA9REQbits;
#word DMA9REQbits = 0xB92
#word DMA9REQ = 0xB92

#word DMA9STA = 0xB94

#word DMA9STB = 0xB98

#word DMA9PAD = 0xB9C

#word DMA9CNT = 0xB9E

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
} DMA10CONBITS;
DMA10CONBITS DMA10CONbits;
#word DMA10CONbits = 0xBA0
#word DMA10CON = 0xBA0

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA10REQBITS;
DMA10REQBITS DMA10REQbits;
#word DMA10REQbits = 0xBA2
#word DMA10REQ = 0xBA2

#word DMA10STA = 0xBA4

#word DMA10STB = 0xBA8

#word DMA10PAD = 0xBAC

#word DMA10CNT = 0xBAE

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
} DMA11CONBITS;
DMA11CONBITS DMA11CONbits;
#word DMA11CONbits = 0xBB0
#word DMA11CON = 0xBB0

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA11REQBITS;
DMA11REQBITS DMA11REQbits;
#word DMA11REQbits = 0xBB2
#word DMA11REQ = 0xBB2

#word DMA11STA = 0xBB4

#word DMA11STB = 0xBB8

#word DMA11PAD = 0xBBC

#word DMA11CNT = 0xBBE

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
} DMA12CONBITS;
DMA12CONBITS DMA12CONbits;
#word DMA12CONbits = 0xBC0
#word DMA12CON = 0xBC0

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA12REQBITS;
DMA12REQBITS DMA12REQbits;
#word DMA12REQbits = 0xBC2
#word DMA12REQ = 0xBC2

#word DMA12STA = 0xBC4

#word DMA12STB = 0xBC8

#word DMA12PAD = 0xBCC

#word DMA12CNT = 0xBCE

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
} DMA13CONBITS;
DMA13CONBITS DMA13CONbits;
#word DMA13CONbits = 0xBD0
#word DMA13CON = 0xBD0

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA13REQBITS;
DMA13REQBITS DMA13REQbits;
#word DMA13REQbits = 0xBD2
#word DMA13REQ = 0xBD2

#word DMA13STA = 0xBD4

#word DMA13STB = 0xBD8

#word DMA13PAD = 0xBDC

#word DMA13CNT = 0xBDE

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
} DMA14CONBITS;
DMA14CONBITS DMA14CONbits;
#word DMA14CONbits = 0xBE0
#word DMA14CON = 0xBE0

typedef union 
 {
      struct {
         unsigned int IRQSEL0:8;
         unsigned int :7;
         unsigned int FORCE:1;
      };
      struct {
         unsigned int IRQSEL:8;
         unsigned int :7;
      };
} DMA14REQBITS;
DMA14REQBITS DMA14REQbits;
#word DMA14REQbits = 0xBE2
#word DMA14REQ = 0xBE2

#word DMA14STA = 0xBE4

#word DMA14STB = 0xBE8

#word DMA14PAD = 0xBEC

#word DMA14CNT = 0xBEE

typedef union 
 {
      struct {
         unsigned int PWCOL0:15;
      };
      struct {
         unsigned int PWCOL:15;
      };
} DMAPWCBITS;
DMAPWCBITS DMAPWCbits;
#word DMAPWCbits = 0xBF0
#word DMAPWC = 0xBF0

typedef union 
 {
      struct {
         unsigned int RQCOL0:15;
      };
      struct {
         unsigned int RQCOL:15;
      };
} DMARQCBITS;
DMARQCBITS DMARQCbits;
#word DMARQCbits = 0xBF2
#word DMARQC = 0xBF2

typedef union 
 {
      struct {
         unsigned int PPST0:15;
      };
      struct {
         unsigned int PPST:15;
      };
} DMAPPSBITS;
DMAPPSBITS DMAPPSbits;
#word DMAPPSbits = 0xBF4
#word DMAPPS = 0xBF4

#word DMALCA = 0xBF6

#word DSADR = 0xBF8

typedef union 
 {
      struct {
         unsigned int SEVTPS0:4;
         unsigned int SYNCSRC0:3;
         unsigned int SYNCEN:1;
         unsigned int SYNCOEN:1;
         unsigned int SYNCPOL:1;
         unsigned int EIPU:1;
         unsigned int SEIEN:1;
         unsigned int SESTAT:1;
         unsigned int PTSIDL:1;
         unsigned int :1;
         unsigned int PTEN:1;
      };
      struct {
         unsigned int SEVTPS:4;
         unsigned int SYNCSRC:3;
      };
} PTCONBITS;
PTCONBITS PTCONbits;
#word PTCONbits = 0xC00
#word PTCON = 0xC00

#word PTCON2 = 0xC02

#word PTPER = 0xC04

#word SEVTCMP = 0xC06

#word MDC = 0xC0A

typedef union 
 {
      struct {
         unsigned int SEVTPS0:4;
         unsigned int SYNCSRC0:3;
         unsigned int SYNCEN:1;
         unsigned int SYNCOEN:1;
         unsigned int SYNCPOL:1;
         unsigned int EIPU:1;
         unsigned int SEIEN:1;
         unsigned int SESTAT:1;
      };
      struct {
         unsigned int SEVTPS:4;
         unsigned int SYNCSRC:3;
      };
} STCONBITS;
STCONBITS STCONbits;
#word STCONbits = 0xC0E
#word STCON = 0xC0E

#word STCON2 = 0xC10

#word STPER = 0xC12

#word SSEVTCMP = 0xC14

typedef union 
 {
      struct {
         unsigned int CHOPCLK0:10;
         unsigned int :5;
         unsigned int CHPCLKEN:1;
      };
      struct {
         unsigned int CHOPCLK:10;
         unsigned int :5;
      };
} CHOPBITS;
CHOPBITS CHOPbits;
#word CHOPbits = 0xC1A
#word CHOP = 0xC1A

typedef union 
 {
      struct {
         unsigned int IUE:1;
         unsigned int XPRES:1;
         unsigned int CAM:1;
         unsigned int MTBS:1;
         unsigned int :1;
         unsigned int DTCP:1;
         unsigned int DTC0:2;
         unsigned int MDCS:1;
         unsigned int ITB:1;
         unsigned int TRGIEN:1;
         unsigned int CLIEN:1;
         unsigned int FLTIEN:1;
         unsigned int TRGSTAT:1;
         unsigned int CLSTAT:1;
         unsigned int FLTSTAT:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DTC:2;
      };
} PWMCON1BITS;
PWMCON1BITS PWMCON1bits;
#word PWMCON1bits = 0xC20
#word PWMCON1 = 0xC20

typedef union 
 {
      struct {
         unsigned int OSYNC:1;
         unsigned int SWAP:1;
         unsigned int CLDAT0:2;
         unsigned int FLTDAT0:2;
         unsigned int OVRDAT0:2;
         unsigned int OVRENL:1;
         unsigned int OVRENH:1;
         unsigned int PMOD0:2;
         unsigned int POLL:1;
         unsigned int POLH:1;
         unsigned int PENL:1;
         unsigned int PENH:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CLDAT:2;
         unsigned int FLTDAT:2;
         unsigned int OVRDAT:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int PMOD:2;
      };
} IOCON1BITS;
IOCON1BITS IOCON1bits;
#word IOCON1bits = 0xC22
#word IOCON1 = 0xC22

typedef union 
 {
      struct {
         unsigned int FLTMOD0:2;
         unsigned int FLTPOL:1;
         unsigned int FLTSRC0:5;
         unsigned int CLMOD:1;
         unsigned int CLPOL:1;
         unsigned int CLSRC0:5;
         unsigned int IFLTMOD:1;
      };
      struct {
         unsigned int FLTMOD:2;
         unsigned int :1;
         unsigned int FLTSRC:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int CLSRC:5;
      };
} FCLCON1BITS;
FCLCON1BITS FCLCON1bits;
#word FCLCON1bits = 0xC24
#word FCLCON1 = 0xC24

#word PDC1 = 0xC26

#word PHASE1 = 0xC28

#word DTR1 = 0xC2A

#word ALTDTR1 = 0xC2C

#word SDC1 = 0xC2E

#word SPHASE1 = 0xC30

typedef union 
 {
      struct {
         unsigned int TRGCMP0:16;
      };
      struct {
         unsigned int TRGCMP:16;
      };
} TRIG1BITS;
TRIG1BITS TRIG1bits;
#word TRIG1bits = 0xC32
#word TRIG1 = 0xC32

typedef union 
 {
      struct {
         unsigned int TRGSTRT0:6;
         unsigned int :1;
         unsigned int DTM:1;
         unsigned int :4;
         unsigned int TRGDIV0:4;
      };
      struct {
         unsigned int TRGSTRT:6;
         unsigned int :1;
         unsigned int :1;
         unsigned int :4;
         unsigned int TRGDIV:4;
      };
} TRGCON1BITS;
TRGCON1BITS TRGCON1bits;
#word TRGCON1bits = 0xC34
#word TRGCON1 = 0xC34

typedef union 
 {
      struct {
         unsigned int :3;
         unsigned int PWMCAP10:10;
         unsigned int PWMCAP110:3;
      };
      struct {
         unsigned int :3;
         unsigned int PWMCAP:10;
         unsigned int PWMCAP1:3;
      };
} PWMCAP1BITS;
PWMCAP1BITS PWMCAP1bits;
#word PWMCAP1bits = 0xC38
#word PWMCAP1 = 0xC38

typedef struct 
 {
   unsigned int BPLL:1;
   unsigned int BPLH:1;
   unsigned int BPHL:1;
   unsigned int BPHH:1;
   unsigned int BCL:1;
   unsigned int BCH:1;
   unsigned int :4;
   unsigned int CLLEBEN:1;
   unsigned int FLTLEBEN:1;
   unsigned int PLF:1;
   unsigned int PLR:1;
   unsigned int PHF:1;
   unsigned int PHR:1;
} LEBCON1BITS;
LEBCON1BITS LEBCON1bits;
#word LEBCON1bits = 0xC3A
#word LEBCON1 = 0xC3A

typedef union 
 {
      struct {
         unsigned int LEB0:12;
      };
      struct {
         unsigned int LEB:12;
      };
} LEBDLY1BITS;
LEBDLY1BITS LEBDLY1bits;
#word LEBDLY1bits = 0xC3C
#word LEBDLY1 = 0xC3C

typedef union 
 {
      struct {
         unsigned int CHOPLEN:1;
         unsigned int CHOPHEN:1;
         unsigned int CHOPSEL0:4;
         unsigned int :2;
         unsigned int BLANKSEL0:4;
         unsigned int :2;
         unsigned int HRDDIS:1;
         unsigned int HRPDIS:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CHOPSEL:4;
         unsigned int :2;
         unsigned int BLANKSEL:4;
         unsigned int :2;
      };
} AUXCON1BITS;
AUXCON1BITS AUXCON1bits;
#word AUXCON1bits = 0xC3E
#word AUXCON1 = 0xC3E

typedef union 
 {
      struct {
         unsigned int IUE:1;
         unsigned int XPRES:1;
         unsigned int CAM:1;
         unsigned int MTBS:1;
         unsigned int :1;
         unsigned int DTCP:1;
         unsigned int DTC0:2;
         unsigned int MDCS:1;
         unsigned int ITB:1;
         unsigned int TRGIEN:1;
         unsigned int CLIEN:1;
         unsigned int FLTIEN:1;
         unsigned int TRGSTAT:1;
         unsigned int CLSTAT:1;
         unsigned int FLTSTAT:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DTC:2;
      };
} PWMCON2BITS;
PWMCON2BITS PWMCON2bits;
#word PWMCON2bits = 0xC40
#word PWMCON2 = 0xC40

typedef union 
 {
      struct {
         unsigned int OSYNC:1;
         unsigned int SWAP:1;
         unsigned int CLDAT0:2;
         unsigned int FLTDAT0:2;
         unsigned int OVRDAT0:2;
         unsigned int OVRENL:1;
         unsigned int OVRENH:1;
         unsigned int PMOD0:2;
         unsigned int POLL:1;
         unsigned int POLH:1;
         unsigned int PENL:1;
         unsigned int PENH:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CLDAT:2;
         unsigned int FLTDAT:2;
         unsigned int OVRDAT:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int PMOD:2;
      };
} IOCON2BITS;
IOCON2BITS IOCON2bits;
#word IOCON2bits = 0xC42
#word IOCON2 = 0xC42

typedef union 
 {
      struct {
         unsigned int FLTMOD0:2;
         unsigned int FLTPOL:1;
         unsigned int FLTSRC0:5;
         unsigned int CLMOD:1;
         unsigned int CLPOL:1;
         unsigned int CLSRC0:5;
         unsigned int IFLTMOD:1;
      };
      struct {
         unsigned int FLTMOD:2;
         unsigned int :1;
         unsigned int FLTSRC:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int CLSRC:5;
      };
} FCLCON2BITS;
FCLCON2BITS FCLCON2bits;
#word FCLCON2bits = 0xC44
#word FCLCON2 = 0xC44

#word PDC2 = 0xC46

#word PHASE2 = 0xC48

#word DTR2 = 0xC4A

#word ALTDTR2 = 0xC4C

#word SDC2 = 0xC4E

#word SPHASE2 = 0xC50

typedef union 
 {
      struct {
         unsigned int TRGCMP0:16;
      };
      struct {
         unsigned int TRGCMP:16;
      };
} TRIG2BITS;
TRIG2BITS TRIG2bits;
#word TRIG2bits = 0xC52
#word TRIG2 = 0xC52

typedef union 
 {
      struct {
         unsigned int TRGSTRT0:6;
         unsigned int :1;
         unsigned int DTM:1;
         unsigned int :4;
         unsigned int TRGDIV0:4;
      };
      struct {
         unsigned int TRGSTRT:6;
         unsigned int :1;
         unsigned int :1;
         unsigned int :4;
         unsigned int TRGDIV:4;
      };
} TRGCON2BITS;
TRGCON2BITS TRGCON2bits;
#word TRGCON2bits = 0xC54
#word TRGCON2 = 0xC54

typedef union 
 {
      struct {
         unsigned int :3;
         unsigned int PWMCAP10:10;
         unsigned int PWMCAP110:3;
      };
      struct {
         unsigned int :3;
         unsigned int PWMCAP:10;
         unsigned int PWMCAP1:3;
      };
} PWMCAP2BITS;
PWMCAP2BITS PWMCAP2bits;
#word PWMCAP2bits = 0xC58
#word PWMCAP2 = 0xC58

typedef struct 
 {
   unsigned int BPLL:1;
   unsigned int BPLH:1;
   unsigned int BPHL:1;
   unsigned int BPHH:1;
   unsigned int BCL:1;
   unsigned int BCH:1;
   unsigned int :4;
   unsigned int CLLEBEN:1;
   unsigned int FLTLEBEN:1;
   unsigned int PLF:1;
   unsigned int PLR:1;
   unsigned int PHF:1;
   unsigned int PHR:1;
} LEBCON2BITS;
LEBCON2BITS LEBCON2bits;
#word LEBCON2bits = 0xC5A
#word LEBCON2 = 0xC5A

typedef union 
 {
      struct {
         unsigned int LEB0:12;
      };
      struct {
         unsigned int LEB:12;
      };
} LEBDLY2BITS;
LEBDLY2BITS LEBDLY2bits;
#word LEBDLY2bits = 0xC5C
#word LEBDLY2 = 0xC5C

typedef union 
 {
      struct {
         unsigned int CHOPLEN:1;
         unsigned int CHOPHEN:1;
         unsigned int CHOPSEL0:4;
         unsigned int :2;
         unsigned int BLANKSEL0:4;
         unsigned int :2;
         unsigned int HRDDIS:1;
         unsigned int HRPDIS:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CHOPSEL:4;
         unsigned int :2;
         unsigned int BLANKSEL:4;
         unsigned int :2;
      };
} AUXCON2BITS;
AUXCON2BITS AUXCON2bits;
#word AUXCON2bits = 0xC5E
#word AUXCON2 = 0xC5E

typedef union 
 {
      struct {
         unsigned int IUE:1;
         unsigned int XPRES:1;
         unsigned int CAM:1;
         unsigned int MTBS:1;
         unsigned int :1;
         unsigned int DTCP:1;
         unsigned int DTC0:2;
         unsigned int MDCS:1;
         unsigned int ITB:1;
         unsigned int TRGIEN:1;
         unsigned int CLIEN:1;
         unsigned int FLTIEN:1;
         unsigned int TRGSTAT:1;
         unsigned int CLSTAT:1;
         unsigned int FLTSTAT:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DTC:2;
      };
} PWMCON3BITS;
PWMCON3BITS PWMCON3bits;
#word PWMCON3bits = 0xC60
#word PWMCON3 = 0xC60

typedef union 
 {
      struct {
         unsigned int OSYNC:1;
         unsigned int SWAP:1;
         unsigned int CLDAT0:2;
         unsigned int FLTDAT0:2;
         unsigned int OVRDAT0:2;
         unsigned int OVRENL:1;
         unsigned int OVRENH:1;
         unsigned int PMOD0:2;
         unsigned int POLL:1;
         unsigned int POLH:1;
         unsigned int PENL:1;
         unsigned int PENH:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CLDAT:2;
         unsigned int FLTDAT:2;
         unsigned int OVRDAT:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int PMOD:2;
      };
} IOCON3BITS;
IOCON3BITS IOCON3bits;
#word IOCON3bits = 0xC62
#word IOCON3 = 0xC62

typedef union 
 {
      struct {
         unsigned int FLTMOD0:2;
         unsigned int FLTPOL:1;
         unsigned int FLTSRC0:5;
         unsigned int CLMOD:1;
         unsigned int CLPOL:1;
         unsigned int CLSRC0:5;
         unsigned int IFLTMOD:1;
      };
      struct {
         unsigned int FLTMOD:2;
         unsigned int :1;
         unsigned int FLTSRC:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int CLSRC:5;
      };
} FCLCON3BITS;
FCLCON3BITS FCLCON3bits;
#word FCLCON3bits = 0xC64
#word FCLCON3 = 0xC64

#word PDC3 = 0xC66

#word PHASE3 = 0xC68

#word DTR3 = 0xC6A

#word ALTDTR3 = 0xC6C

#word SDC3 = 0xC6E

#word SPHASE3 = 0xC70

typedef union 
 {
      struct {
         unsigned int TRGCMP0:16;
      };
      struct {
         unsigned int TRGCMP:16;
      };
} TRIG3BITS;
TRIG3BITS TRIG3bits;
#word TRIG3bits = 0xC72
#word TRIG3 = 0xC72

typedef union 
 {
      struct {
         unsigned int TRGSTRT0:6;
         unsigned int :1;
         unsigned int DTM:1;
         unsigned int :4;
         unsigned int TRGDIV0:4;
      };
      struct {
         unsigned int TRGSTRT:6;
         unsigned int :1;
         unsigned int :1;
         unsigned int :4;
         unsigned int TRGDIV:4;
      };
} TRGCON3BITS;
TRGCON3BITS TRGCON3bits;
#word TRGCON3bits = 0xC74
#word TRGCON3 = 0xC74

typedef union 
 {
      struct {
         unsigned int :3;
         unsigned int PWMCAP10:10;
         unsigned int PWMCAP110:3;
      };
      struct {
         unsigned int :3;
         unsigned int PWMCAP:10;
         unsigned int PWMCAP1:3;
      };
} PWMCAP3BITS;
PWMCAP3BITS PWMCAP3bits;
#word PWMCAP3bits = 0xC78
#word PWMCAP3 = 0xC78

typedef struct 
 {
   unsigned int BPLL:1;
   unsigned int BPLH:1;
   unsigned int BPHL:1;
   unsigned int BPHH:1;
   unsigned int BCL:1;
   unsigned int BCH:1;
   unsigned int :4;
   unsigned int CLLEBEN:1;
   unsigned int FLTLEBEN:1;
   unsigned int PLF:1;
   unsigned int PLR:1;
   unsigned int PHF:1;
   unsigned int PHR:1;
} LEBCON3BITS;
LEBCON3BITS LEBCON3bits;
#word LEBCON3bits = 0xC7A
#word LEBCON3 = 0xC7A

typedef union 
 {
      struct {
         unsigned int LEB0:12;
      };
      struct {
         unsigned int LEB:12;
      };
} LEBDLY3BITS;
LEBDLY3BITS LEBDLY3bits;
#word LEBDLY3bits = 0xC7C
#word LEBDLY3 = 0xC7C

typedef union 
 {
      struct {
         unsigned int CHOPLEN:1;
         unsigned int CHOPHEN:1;
         unsigned int CHOPSEL0:4;
         unsigned int :2;
         unsigned int BLANKSEL0:4;
         unsigned int :2;
         unsigned int HRDDIS:1;
         unsigned int HRPDIS:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CHOPSEL:4;
         unsigned int :2;
         unsigned int BLANKSEL:4;
         unsigned int :2;
      };
} AUXCON3BITS;
AUXCON3BITS AUXCON3bits;
#word AUXCON3bits = 0xC7E
#word AUXCON3 = 0xC7E

typedef union 
 {
      struct {
         unsigned int IUE:1;
         unsigned int XPRES:1;
         unsigned int CAM:1;
         unsigned int MTBS:1;
         unsigned int :1;
         unsigned int DTCP:1;
         unsigned int DTC0:2;
         unsigned int MDCS:1;
         unsigned int ITB:1;
         unsigned int TRGIEN:1;
         unsigned int CLIEN:1;
         unsigned int FLTIEN:1;
         unsigned int TRGSTAT:1;
         unsigned int CLSTAT:1;
         unsigned int FLTSTAT:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int DTC:2;
      };
} PWMCON4BITS;
PWMCON4BITS PWMCON4bits;
#word PWMCON4bits = 0xC80
#word PWMCON4 = 0xC80

typedef union 
 {
      struct {
         unsigned int OSYNC:1;
         unsigned int SWAP:1;
         unsigned int CLDAT0:2;
         unsigned int FLTDAT0:2;
         unsigned int OVRDAT0:2;
         unsigned int OVRENL:1;
         unsigned int OVRENH:1;
         unsigned int PMOD0:2;
         unsigned int POLL:1;
         unsigned int POLH:1;
         unsigned int PENL:1;
         unsigned int PENH:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CLDAT:2;
         unsigned int FLTDAT:2;
         unsigned int OVRDAT:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int PMOD:2;
      };
} IOCON4BITS;
IOCON4BITS IOCON4bits;
#word IOCON4bits = 0xC82
#word IOCON4 = 0xC82

typedef union 
 {
      struct {
         unsigned int FLTMOD0:2;
         unsigned int FLTPOL:1;
         unsigned int FLTSRC0:5;
         unsigned int CLMOD:1;
         unsigned int CLPOL:1;
         unsigned int CLSRC0:5;
         unsigned int IFLTMOD:1;
      };
      struct {
         unsigned int FLTMOD:2;
         unsigned int :1;
         unsigned int FLTSRC:5;
         unsigned int :1;
         unsigned int :1;
         unsigned int CLSRC:5;
      };
} FCLCON4BITS;
FCLCON4BITS FCLCON4bits;
#word FCLCON4bits = 0xC84
#word FCLCON4 = 0xC84

#word PDC4 = 0xC86

#word PHASE4 = 0xC88

#word DTR4 = 0xC8A

#word ALTDTR4 = 0xC8C

#word SDC4 = 0xC8E

#word SPHASE4 = 0xC90

typedef union 
 {
      struct {
         unsigned int TRGCMP0:16;
      };
      struct {
         unsigned int TRGCMP:16;
      };
} TRIG4BITS;
TRIG4BITS TRIG4bits;
#word TRIG4bits = 0xC92
#word TRIG4 = 0xC92

typedef union 
 {
      struct {
         unsigned int TRGSTRT0:6;
         unsigned int :1;
         unsigned int DTM:1;
         unsigned int :4;
         unsigned int TRGDIV0:4;
      };
      struct {
         unsigned int TRGSTRT:6;
         unsigned int :1;
         unsigned int :1;
         unsigned int :4;
         unsigned int TRGDIV:4;
      };
} TRGCON4BITS;
TRGCON4BITS TRGCON4bits;
#word TRGCON4bits = 0xC94
#word TRGCON4 = 0xC94

typedef union 
 {
      struct {
         unsigned int :3;
         unsigned int PWMCAP10:10;
         unsigned int PWMCAP110:3;
      };
      struct {
         unsigned int :3;
         unsigned int PWMCAP:10;
         unsigned int PWMCAP1:3;
      };
} PWMCAP4BITS;
PWMCAP4BITS PWMCAP4bits;
#word PWMCAP4bits = 0xC98
#word PWMCAP4 = 0xC98

typedef struct 
 {
   unsigned int BPLL:1;
   unsigned int BPLH:1;
   unsigned int BPHL:1;
   unsigned int BPHH:1;
   unsigned int BCL:1;
   unsigned int BCH:1;
   unsigned int :4;
   unsigned int CLLEBEN:1;
   unsigned int FLTLEBEN:1;
   unsigned int PLF:1;
   unsigned int PLR:1;
   unsigned int PHF:1;
   unsigned int PHR:1;
} LEBCON4BITS;
LEBCON4BITS LEBCON4bits;
#word LEBCON4bits = 0xC9A
#word LEBCON4 = 0xC9A

typedef union 
 {
      struct {
         unsigned int LEB0:12;
      };
      struct {
         unsigned int LEB:12;
      };
} LEBDLY4BITS;
LEBDLY4BITS LEBDLY4bits;
#word LEBDLY4bits = 0xC9C
#word LEBDLY4 = 0xC9C

typedef union 
 {
      struct {
         unsigned int CHOPLEN:1;
         unsigned int CHOPHEN:1;
         unsigned int CHOPSEL0:4;
         unsigned int :2;
         unsigned int BLANKSEL0:4;
         unsigned int :2;
         unsigned int HRDDIS:1;
         unsigned int HRPDIS:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CHOPSEL:4;
         unsigned int :2;
         unsigned int BLANKSEL:4;
         unsigned int :2;
      };
} AUXCON4BITS;
AUXCON4BITS AUXCON4bits;
#word AUXCON4bits = 0xC9E
#word AUXCON4 = 0xC9E

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
#word TRISBbits = 0xE10
#word TRISB = 0xE10

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
#word PORTBbits = 0xE12
#word PORTB = 0xE12

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
#word LATBbits = 0xE14
#word LATB = 0xE14

typedef union 
 {
      struct {
         unsigned int CNIEB0:16;
      };
      struct {
         unsigned int CNIEB:16;
      };
} CNENBBITS;
CNENBBITS CNENBbits;
#word CNENBbits = 0xE18
#word CNENB = 0xE18

typedef union 
 {
      struct {
         unsigned int CNPUB0:16;
      };
      struct {
         unsigned int CNPUB:16;
      };
} CNPUBBITS;
CNPUBBITS CNPUBbits;
#word CNPUBbits = 0xE1A
#word CNPUB = 0xE1A

typedef union 
 {
      struct {
         unsigned int CNPDB0:16;
      };
      struct {
         unsigned int CNPDB:16;
      };
} CNPDBBITS;
CNPDBBITS CNPDBbits;
#word CNPDBbits = 0xE1C
#word CNPDB = 0xE1C

typedef union 
 {
      struct {
         unsigned int ANSB0:16;
      };
      struct {
         unsigned int ANSB:16;
      };
} ANSELBBITS;
ANSELBBITS ANSELBbits;
#word ANSELBbits = 0xE1E
#word ANSELB = 0xE1E

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
#word TRISCbits = 0xE20
#word TRISC = 0xE20

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
#word PORTCbits = 0xE22
#word PORTC = 0xE22

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
#word LATCbits = 0xE24
#word LATC = 0xE24

typedef union 
 {
      struct {
         unsigned int CNIEC0:16;
      };
      struct {
         unsigned int CNIEC:16;
      };
} CNENCBITS;
CNENCBITS CNENCbits;
#word CNENCbits = 0xE28
#word CNENC = 0xE28

typedef union 
 {
      struct {
         unsigned int CNPUC0:16;
      };
      struct {
         unsigned int CNPUC:16;
      };
} CNPUCBITS;
CNPUCBITS CNPUCbits;
#word CNPUCbits = 0xE2A
#word CNPUC = 0xE2A

typedef union 
 {
      struct {
         unsigned int CNPDC0:16;
      };
      struct {
         unsigned int CNPDC:16;
      };
} CNPDCBITS;
CNPDCBITS CNPDCbits;
#word CNPDCbits = 0xE2C
#word CNPDC = 0xE2C

typedef union 
 {
      struct {
         unsigned int ANSC0:16;
      };
      struct {
         unsigned int ANSC:16;
      };
} ANSELCBITS;
ANSELCBITS ANSELCbits;
#word ANSELCbits = 0xE2E
#word ANSELC = 0xE2E

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
#word TRISDbits = 0xE30
#word TRISD = 0xE30

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
#word PORTDbits = 0xE32
#word PORTD = 0xE32

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
#word LATDbits = 0xE34
#word LATD = 0xE34

typedef union 
 {
      struct {
         unsigned int ODCD0:16;
      };
      struct {
         unsigned int ODCD:16;
      };
} ODCDBITS;
ODCDBITS ODCDbits;
#word ODCDbits = 0xE36
#word ODCD = 0xE36

typedef union 
 {
      struct {
         unsigned int CNIED0:16;
      };
      struct {
         unsigned int CNIED:16;
      };
} CNENDBITS;
CNENDBITS CNENDbits;
#word CNENDbits = 0xE38
#word CNEND = 0xE38

typedef union 
 {
      struct {
         unsigned int CNPUD0:16;
      };
      struct {
         unsigned int CNPUD:16;
      };
} CNPUDBITS;
CNPUDBITS CNPUDbits;
#word CNPUDbits = 0xE3A
#word CNPUD = 0xE3A

typedef union 
 {
      struct {
         unsigned int CNPDD0:16;
      };
      struct {
         unsigned int CNPDD:16;
      };
} CNPDDBITS;
CNPDDBITS CNPDDbits;
#word CNPDDbits = 0xE3C
#word CNPDD = 0xE3C

typedef union 
 {
      struct {
         unsigned int ANSD0:16;
      };
      struct {
         unsigned int ANSD:16;
      };
} ANSELDBITS;
ANSELDBITS ANSELDbits;
#word ANSELDbits = 0xE3E
#word ANSELD = 0xE3E

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
#word TRISEbits = 0xE40
#word TRISE = 0xE40

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
#word PORTEbits = 0xE42
#word PORTE = 0xE42

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
#word LATEbits = 0xE44
#word LATE = 0xE44

typedef union 
 {
      struct {
         unsigned int CNIEE0:16;
      };
      struct {
         unsigned int CNIEE:16;
      };
} CNENEBITS;
CNENEBITS CNENEbits;
#word CNENEbits = 0xE48
#word CNENE = 0xE48

typedef union 
 {
      struct {
         unsigned int CNPUE0:16;
      };
      struct {
         unsigned int CNPUE:16;
      };
} CNPUEBITS;
CNPUEBITS CNPUEbits;
#word CNPUEbits = 0xE4A
#word CNPUE = 0xE4A

typedef union 
 {
      struct {
         unsigned int CNPDE0:16;
      };
      struct {
         unsigned int CNPDE:16;
      };
} CNPDEBITS;
CNPDEBITS CNPDEbits;
#word CNPDEbits = 0xE4C
#word CNPDE = 0xE4C

typedef union 
 {
      struct {
         unsigned int ANSE0:1;
         unsigned int ANSE1:1;
         unsigned int ANSE2:1;
         unsigned int ANSE3:1;
         unsigned int ANSE4:1;
         unsigned int ANSE5:1;
         unsigned int ANSE6:1;
         unsigned int ANSE7:1;
         unsigned int ANSE8:1;
         unsigned int ANSE9:1;
         unsigned int ANSE10:1;
         unsigned int ANSE11:1;
         unsigned int ANSE12:1;
         unsigned int ANSE13:1;
         unsigned int ANSE14:1;
         unsigned int ANSE15:1;
      };
      struct {
         unsigned int ANSE:16;
      };
} ANSELEBITS;
ANSELEBITS ANSELEbits;
#word ANSELEbits = 0xE4E
#word ANSELE = 0xE4E

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
#word TRISFbits = 0xE50
#word TRISF = 0xE50

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
#word PORTFbits = 0xE52
#word PORTF = 0xE52

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
#word LATFbits = 0xE54
#word LATF = 0xE54

typedef union 
 {
      struct {
         unsigned int ODCF0:16;
      };
      struct {
         unsigned int ODCF:16;
      };
} ODCFBITS;
ODCFBITS ODCFbits;
#word ODCFbits = 0xE56
#word ODCF = 0xE56

typedef union 
 {
      struct {
         unsigned int CNIEF0:16;
      };
      struct {
         unsigned int CNIEF:16;
      };
} CNENFBITS;
CNENFBITS CNENFbits;
#word CNENFbits = 0xE58
#word CNENF = 0xE58

typedef union 
 {
      struct {
         unsigned int CNPUF0:16;
      };
      struct {
         unsigned int CNPUF:16;
      };
} CNPUFBITS;
CNPUFBITS CNPUFbits;
#word CNPUFbits = 0xE5A
#word CNPUF = 0xE5A

typedef union 
 {
      struct {
         unsigned int CNPDF0:16;
      };
      struct {
         unsigned int CNPDF:16;
      };
} CNPDFBITS;
CNPDFBITS CNPDFbits;
#word CNPDFbits = 0xE5C
#word CNPDF = 0xE5C

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
#word TRISGbits = 0xE60
#word TRISG = 0xE60

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
#word PORTGbits = 0xE62
#word PORTG = 0xE62

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
#word LATGbits = 0xE64
#word LATG = 0xE64

typedef union 
 {
      struct {
         unsigned int ODCG0:16;
      };
      struct {
         unsigned int ODCG:16;
      };
} ODCGBITS;
ODCGBITS ODCGbits;
#word ODCGbits = 0xE66
#word ODCG = 0xE66

typedef union 
 {
      struct {
         unsigned int CNIEG0:16;
      };
      struct {
         unsigned int CNIEG:16;
      };
} CNENGBITS;
CNENGBITS CNENGbits;
#word CNENGbits = 0xE68
#word CNENG = 0xE68

typedef union 
 {
      struct {
         unsigned int CNPUG0:16;
      };
      struct {
         unsigned int CNPUG:16;
      };
} CNPUGBITS;
CNPUGBITS CNPUGbits;
#word CNPUGbits = 0xE6A
#word CNPUG = 0xE6A

typedef union 
 {
      struct {
         unsigned int CNPDG0:16;
      };
      struct {
         unsigned int CNPDG:16;
      };
} CNPDGBITS;
CNPDGBITS CNPDGbits;
#word CNPDGbits = 0xE6C
#word CNPDG = 0xE6C

typedef union 
 {
      struct {
         unsigned int ANSG0:1;
         unsigned int ANSG1:1;
         unsigned int ANSG2:1;
         unsigned int ANSG3:1;
         unsigned int ANSG4:1;
         unsigned int ANSG5:1;
         unsigned int ANSG6:1;
         unsigned int ANSG7:1;
         unsigned int ANSG8:1;
         unsigned int ANSG9:1;
         unsigned int ANSG10:1;
         unsigned int ANSG11:1;
         unsigned int ANSG12:1;
         unsigned int ANSG13:1;
         unsigned int ANSG14:1;
         unsigned int ANSG15:1;
      };
      struct {
         unsigned int ANSG:16;
      };
} ANSELGBITS;
ANSELGBITS ANSELGbits;
#word ANSELGbits = 0xE6E
#word ANSELG = 0xE6E

typedef struct 
 {
   unsigned int PMPTTL:1;
   unsigned int RTSECSEL:1;
} PADCFG1BITS;
PADCFG1BITS PADCFG1bits;
#word PADCFG1bits = 0xEFE
#word PADCFG1 = 0xEFE

#word FEXL = 0xF80

#word FEXU = 0xF82

#word VISI = 0xF88

#word DPCL = 0xF8A

#word DPCU = 0xF8C

#word DFTADD = 0xFC6

#word DFTDATA = 0xFC8

#word DFTDATA_INC = 0xFCA

