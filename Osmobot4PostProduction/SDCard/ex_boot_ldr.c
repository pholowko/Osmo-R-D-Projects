#define __USE_MDD_BOOTLOADER__
#define __MDD_BOOT_IS_LOADER__

#include "ex_mdd_common.h"

#if defined(__PCD__)
   #error Not tested or supported with 16bit PICs
#endif

#if 0
   #define debug_boot   printf
   void debug_putc(char c) {fputc(c, STREAM_USER_UART);}
#else
   // disable booting debugs
   #define debug_boot(a,b,c,d,e,f,g,h,i,j,k)
   #define debug_putc(c)
#endif

unsigned int8 atoi_b16(char *s) {  // Convert two hex characters to a int8
   unsigned int8 result = 0;
   int i;

   for (i=0; i<2; i++,s++)  {
      if (*s >= 'A')
         result = 16*result + (*s) - 'A' + 10;
      else
         result = 16*result + (*s) - '0';
   }

   return(result);
}

#define ROM_BLOCK_INVALID -1

int32 rom_block_start = ROM_BLOCK_INVALID;

#define EEPROM_ERASE_SIZE  getenv("FLASH_ERASE_SIZE")
int8 rom_block[EEPROM_ERASE_SIZE];

void rom_w_init(void)
{
   rom_block_start = ROM_BLOCK_INVALID;
}

// see rom_w() documentation.  performs the flushing
void rom_w_flush(void)
{
   if (rom_block_start != ROM_BLOCK_INVALID)
   {
      erase_program_eeprom(rom_block_start);     //erase entire block
   
      write_program_memory(rom_block_start, rom_block, sizeof(rom_block));    //write modified block
      
      rom_block_start = ROM_BLOCK_INVALID;
   }
}

// see rom_w() documentation.  performs the writing
void rom_w_block(int32 location, char *src, int16 size)
{
   int32 block_start;
   int16 i,num;

   block_start = location & (~((int32)EEPROM_ERASE_SIZE-1));
      
   i = location - block_start;

   while (size) 
   {
      if (block_start != rom_block_start)
      {
         rom_w_flush();
         
         rom_block_start = block_start;
         
         read_program_memory(block_start, rom_block, sizeof(rom_block));  //read entire block to ram buffer
      }
      

      if (size>(EEPROM_ERASE_SIZE-i)) {num=EEPROM_ERASE_SIZE-i;} else {num=size;}

      memcpy(&rom_block[i], src, num);    //modify ram buffer

      src += num;
      block_start += EEPROM_ERASE_SIZE;
      i = 0;
      size -= num;
   }
}

// Write to Flash ROM.
//
// location - flash program memory address
// src - pointer to data to write
// size - number of bytes to write to flash
//
// Here is the sequence of events:
//   1.) Goes to the beginning of the first erase block for this address
//   2.) Reads n records to ram, where n is the PIC's flash erase size
//   3.) Erases block in flash
//   4.) Modifies block in RAM
//   5.) Writes changed block back to FLASH.  Writes in chunks defined by PIC's flash write size
//   6.) Goes back to step1 if there is still more data to be written
void rom_w(int32 location, char *src, int16 size)
{
   rom_w_block(location, src, size);
   rom_w_flush();
}

void real_load_program(FSFILE *f)
{
   char c;
   int1  done=FALSE;
   unsigned int8  checksum, line_type;
   unsigned int16 l_addr,h_addr=0;
   unsigned int32 addr;
   /*
   #if getenv("FLASH_ERASE_SIZE")>2
      int32 next_addr;
   #endif
   */
   unsigned int8  dataidx, i, count;
   unsigned int8  data[32];
   int  buffidx;
   #define BUFFER_LEN_LOD  80
   char buffer[BUFFER_LEN_LOD];
   
   unsigned int8 resetVectorInfiniteLoop[4];
   unsigned int8 resetVectorSize = 0;
   unsigned int8 resetVectorData[32];
   
   // set reset vector to infinite loop until full HEX file is read.
  #if defined(__PCH__)
   resetVectorInfiniteLoop[0] = (APPLICATION_START/2);
   resetVectorInfiniteLoop[1] = 0xEF;
   resetVectorInfiniteLoop[2] = (APPLICATION_START/2) >> 8;
   resetVectorInfiniteLoop[3] = (((APPLICATION_START/2) >> 16) & 0xF) | 0xF0;
  #else
   #error add support for your PIC architecture here
  #endif
   rom_w(APPLICATION_START, resetVectorInfiniteLoop, sizeof(resetVectorInfiniteLoop));
   
   while (!done)  // Loop until the entire program is downloaded
   {
      buffidx = 0;
      do
      {
         i = FSfread(&c, sizeof(char), 1, f);
         if (i)
         {
            if (c == 0x0A)
               buffidx = 0;
            else
               buffer[buffidx++] = c;
         }
      } while ((i != 0) && (c != 0x0D) && (buffidx < BUFFER_LEN_LOD));

      //debug_boot(debug_putc, "\r\ni=%U idx=%U c=%X b[0]=%c ", i, buffidx, c, buffer[0]);

      if (i == 0)
         break;   //EOF or error, done

      // Only process data blocks that start with ':'
      if (buffidx && (buffer[0] == ':'))
      {
         buffer[buffidx-1] = 0;
         debug_boot(debug_putc, "\r\n%s", buffer);
         
         count = atoi_b16 (&buffer[1]);  // Get the number of bytes from the buffer

         // Get the lower 16 bits of address
         l_addr = make16(atoi_b16(&buffer[3]),atoi_b16(&buffer[5]));

         line_type = atoi_b16 (&buffer[7]);

         addr = make32(h_addr,l_addr);
         
         debug_boot(debug_putc, " TYPE=%U LEN=%U ADD=%LX", line_type, count, addr);

         #if defined(__PCM__)  // PIC16 uses word addresses
            addr /= 2;
         #endif

         checksum = 0;  // Sum the bytes to find the check sum value
         for (i=1; i<(buffidx-3); i+=2)
            checksum += atoi_b16 (&buffer[i]);
         checksum = 0xFF - checksum + 1;

         //debug_boot(debug_putc, " CS=%X.%X", checksum, atoi_b16(&buffer[buffidx-3]));

         // If the line type is 1, then data is done being sent
         if (checksum == atoi_b16 (&buffer[buffidx-3]))
         {
            if (line_type == 1) 
            {
               done = TRUE;
               debug_boot(debug_putc, " DONE");
            }
            else if (line_type == 4)
            {
               h_addr = make16(atoi_b16(&buffer[9]), atoi_b16(&buffer[11]));
               debug_boot(debug_putc, " ADDR");
            }
            else if 
            (
               (line_type == 0) &&
               (addr >= APPLICATION_START) && 
               (addr < APPLICATION_END)
            )
            {
               // Loops through all of the data and stores it in data
               // The last 2 bytes are the check sum, hence buffidx-3
               for (i = 9,dataidx=0; i < buffidx-3; i += 2)
                  data[dataidx++]=atoi_b16(&buffer[i]);

               if (addr == APPLICATION_START)
               {
                  debug_boot(debug_putc, " SAVING");

                  memcpy(resetVectorData, data, count);

                  resetVectorSize = count;
               }
               else
               {
                  debug_boot(debug_putc, " WRITING");
   
                  rom_w_block(addr, data, count);
               }
            }
         }
      }
   }

   rom_w_flush();

   // done and success, write final reset vector to PIC
   if (resetVectorSize && done)
   {
      debug_boot(debug_putc, "\r\nWRITING CACHED RESET VECTOR ");
      rom_w(APPLICATION_START, resetVectorData, resetVectorSize);
   }
}

void main(void)
{
   FSFILE *f;
   char fileName[] = "boot.hex";
   
   HW_INIT();
   
   delay_ms(72);
   
   debug_boot(debug_putc, "\r\n\nRESET ");
   
   MDD_InitIO();
   
   if (MDD_MediaDetect())
   {
      debug_boot(debug_putc, "\r\nMEDIA DETECTED... ");
      
      if (FSInit())
      {
         debug_boot(debug_putc, "\r\nFS LOADED... ");
         
         f = FSfopen(fileName, "r");
         
         if (f != NULL)
         {
            debug_boot(debug_putc, "\r\nFILE LOADED... ");
            
            real_load_program(f);
            
            FSfclose(f);
         }
      }
   }
   
   debug_boot(debug_putc, "\r\nGOING TO APPLICATION\r\n");
  
  #asm
   GOTO APPLICATION_START
  #endasm
}
