//see about.txt in filesystem/ for information

#ifndef __FILESYSTEM_C__
#define __FILESYSTEM_C__

#include "FSConfig.h"

#if defined(USE_SST25_INTERFACE)
#include "sst25vf_mdd.c"
#endif

#if defined(FS_DYNAMIC_MEM)
 #if defined(__PCH__)
  #include "salloc.c"
 #else
  #include <stdlibm.h>
 #endif
#endif

#include "fsio.c"

#if defined(USE_SD_INTERFACE_WITH_SPI)
#include "sd-spi.c"
#endif

#endif
