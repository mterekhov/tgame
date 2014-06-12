#ifndef ENGINE_ABLOCKOUTDEBUG_H
#define ENGINE_ABLOCKOUTDEBUG_H

//==============================================================================

#include <iostream>

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
#ifdef DEBUG_LOG
#define loger(...)\
    printf("%s line %d: ", __PRETTY_FUNCTION__, __LINE__);\
    printf(__VA_ARGS__);\
    printf("\n");
#else
    #define loger(...)
#endif

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif
