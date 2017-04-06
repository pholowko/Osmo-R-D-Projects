void checkROMStats(void){
	#word eraseFSize=getenv("FLASH_ERASE_SIZE");
	#word writeFSize=getenv("FLASH_WRITE_SIZE");
	#word prgMem=getenv("FLASH_ERASE_SIZE");


	int16 beginVal1 = read_program_eeprom(0x0140);
	int16 beginVal2 = read_program_eeprom(0x0080);
	int16 beginVal3 = read_program_eeprom(0x0280);
	int16 beginVal = read_program_eeprom(0x0280);
	int16 endVal1 = read_program_eeprom(0x1D00);
	int16 endVal2 = read_program_eeprom(0x1D01);
	int16 endVal = read_program_eeprom(0x1D10);
	int16 midVal = read_program_eeprom(0x1000);
	int16 dispESize=eraseFSize;
	int16 dispWSize=writeFSize;
	int16 dispTheMem=prgMem;
}

int16 testFlashRead(int16 addr){
#word prgMem=getenv("FLASH_ERASE_SIZE");
int16 test1=read_program_eeprom(addr);
int16 dispTheMem=prgMem;
return test1;
}

void testFlashWrite(int16 addr, int16 val){
#word prgMem=getenv("FLASH_ERASE_SIZE");

int16 tester=read_program_eeprom(addr);
if(tester!=val){
write_program_eeprom(addr,val);
}
int16 test1=read_program_eeprom(addr);
int16 test2=read_program_eeprom(0x0141);
int16 dispTheMem=prgMem;
}