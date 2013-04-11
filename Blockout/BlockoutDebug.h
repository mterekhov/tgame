#ifndef __Blockout__BlockoutDebug__
#define __Blockout__BlockoutDebug__

#include <iostream>

#ifdef DEBUG_LOG
#define loger(...)\
    printf("%s line %d: ", __PRETTY_FUNCTION__, __LINE__);\
    printf(__VA_ARGS__);\
    printf("\n");
#else
    #define loger(...)
#endif

#endif
