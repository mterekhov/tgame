#include "BlockoutDebug.h"

//==============================================================================
#define log(char* format, ...)\
#ifdef DEBUG_LOG\
    printf("%s >> %s %s: ", __FILE__, __func__, __LINE__);\
    va_list args;\
    va_start(args, format);\
    vprintf(format, args);\
    va_end(args);\
    printf("\n");\
#endif\
