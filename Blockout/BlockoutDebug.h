#ifndef __Blockout__BlockoutDebug__
#define __Blockout__BlockoutDebug__

#include <iostream>

#ifdef DEBUG_LOG

#define loger(format, ...)\
printf("%s >> %s %s: ", __FILE__, __func__, __LINE__);\
printf(__VA_ARGS__);\
printf("\n");

#endif

#endif
