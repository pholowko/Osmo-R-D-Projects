#ifndef __EX_MDD_BOOT_H__
#define __EX_MDD_BOOT_H__

//set to 1 to allow writing/erase of config words by loader.
//set to 0 to go back one erase page, preventing loader from writing 
// config words.
//don't set this to 0 if your pic doesn't have config words in the last few
// bytes of program memory.
#ifndef LOADER_CAN_CHANGE_CONFIG
#define LOADER_CAN_CHANGE_CONFIG 1
#endif

////////// end config ///////////////////////////////////////////////////////

#define LOADER_SIZE  0x8000

#if LOADER_CAN_CHANGE_CONFIG
   #define APPLICATION_END getenv("PROGRAM_MEMORY")
#else
   #define APPLICATION_END (getenv("PROGRAM_MEMORY") - getenv("FLASH_ERASE_SIZE"))
#endif

#define APPLICATION_START  LOADER_SIZE
#define ISR_START          APPLICATION_START+8

#if defined(__MDD_BOOT_IS_LOADER__)
   #if getenv("PROGRAM_MEMORY") > 0x10000
      #org APPLICATION_START+0x80, 0xFFFF
      #org 0x10000, getenv("PROGRAM_MEMORY")-1 {}
   #else
      #org APPLICATION_START+0x80, getenv("PROGRAM_MEMORY")-1 {}
   #endif
   
   #int_global
   void isr_global(void)
   {
      jump_to_isr(ISR_START);
   }
   
   //create shell program so you can load bootloader hex into PIC
   #org APPLICATION_START, APPLICATION_START+7
   void ShellReset(void)
   {
      #asm
         GOTO APPLICATION_START
      #endasm
   }
   
   #org APPLICATION_START+8, APPLICATION_START+15
   void ShellIsrHigh(void)
   {
      #asm
         RETFIE 0
      #endasm
   }

   #org APPLICATION_START+16, APPLICATION_START+0x7F
   void ShellIsrLow(void)
   {
      #asm
         RETFIE 0
      #endasm
   }
#else
   #build(reset=APPLICATION_START, interrupt=ISR_START)
   #org 0, APPLICATION_START-1 {}
   
  #if !LOADER_CAN_CHANGE_CONFIG
   //prevent code from going in the last page, which is going to be soft protected
   #org getenv("PROGRAM_MEMORY")-getenv("FLASH_ERASE_SIZE"), getenv("PROGRAM_MEMORY")
  #endif
#endif

#endif //__EX_MDD_BOOT_H__
