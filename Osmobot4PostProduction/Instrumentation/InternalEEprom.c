voidcheckROMStats(void){
	#word eraseFSize=getenv("FLASH_ERASE_SIZE");
	#word writeFSize=getenv("FLASH_WRITE_SIZE");
	#word prgMem=getenv("FLASH_ERASE_SIZE");


	int16 dispESize=eraseFSize;
	int16 dispWSize=writeFSize;
	int16 dispTheMem=prgMem; 
}