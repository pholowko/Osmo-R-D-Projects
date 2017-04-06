#include <18F67J60.h>


#USE I2C(MASTER,I2C1, sda=PIN_C4, scl=PIN_C3,FAST=10000,  NOINIT)
//#use delay(clock=41666667)
#use delay(clock=25mhz)
#fuses NOWDT, NODEBUG, HS
   
//#use rs232(baud=9600, uart1, stream=STREAM_UI, errors)
//char testString[] = "Hello World!\nTest123!!!";

/*
void i2c_writeString(int8 addr, char dat[])
{
int i=0;
//i2c_start();
i2c_write(addr);

	while(dat[i]!='\0')
{
		i2c_write(dat[i]);
		i++;
	}	
}	

*/
//char strTest[]={'T','E','S','T','\n','1','2'};
char strTest[15];
char strTest2[15];
void main()
{

//i2c_init(100000);
//i2c_init(20000);
i2c_init(1000);

output_bit(PIN_C5,1);
output_bit(PIN_C0,0);

//output_bit(PIN_C5,1);
//output_bit(PIN_C0,1);

sprintf(strTest,"TEST12345!\n");
sprintf(strTest2,"TEST?!\n");
while(1)
    {
	//i2c_writeString(0xa0,testString);
//	i2c_start();
//	i2c_write(0xa0);
//	i2c_write('u');
//	i2c_write('e');
int i=0;
while(strTest[i]!='\0'){
	i2c_start();
	i2c_write(0xa0);
i2c_write(strTest[i]);
	i2c_stop();
i++;
}
//	i2c_stop();
	
delay_ms(2000);

i=0;
while(strTest2[i]!='\0'){
	i2c_start();
	i2c_write(0xa0);
i2c_write(strTest2[i]);
	i2c_stop();
i++;
}
delay_ms(2000);


}
}






