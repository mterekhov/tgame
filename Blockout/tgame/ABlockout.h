#ifndef ENGINE_ABLOCKOUT_H
#define ENGINE_ABLOCKOUT_H

//==============================================================================

#include "ACrafter.h"
#include "ALogic.h"
#include "AColor.h"

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
    
#endif
