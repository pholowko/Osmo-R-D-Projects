Port of Microchip's MDD 1.4.2 library.  Only SD card code is provided.  FAT12 is disabled because of reentrancy.  LFN is disabled and never tested.

See ex_fat.c, which is an example of usage.  Be sure to add the "CCSIncludes" folder to your compiler include path.