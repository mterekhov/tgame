#ifndef SPCTGAME_ABLOCKOUT_H
#define SPCTGAME_ABLOCKOUT_H

//==============================================================================

#include "acrafter.h"
#include "alogic.h"
#include "acolor.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ABlockout
{
private:
    void init();
    void render();

    ACrafter _crafter;
    ALogic _logic;
    TFloat _wellWidth;
    TFloat _wellHeight;
    TFloat _wellDepth;
    
public:
    ABlockout();
    ~ABlockout();
    
    void processGameCycle();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKOUT_H
