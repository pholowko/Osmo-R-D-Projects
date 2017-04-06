#define __USE_MDD_BOOTLOADER__

#include "ex_mdd_common.h"

void main(void)
{
   HW_INIT();
   
   fprintf(STREAM_USER_UART, "\r\n\nAPPLICATION V1.0\r\n");
   
   for(;;)
   {
      delay_ms(500);
      output_toggle(PIN_LED1);
   }
}
