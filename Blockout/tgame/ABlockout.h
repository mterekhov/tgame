#ifndef SPCTGAME_ABLOCKOUT_H
#define SPCTGAME_ABLOCKOUT_H

//==============================================================================

#include "acrafter.h"
#include "alogic.h"
#include "acolor.h"
#include "akeyboardevents.h"

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
    AKeyboardEvents _keyboardEvents;
    
    TFloat _wellWidth;
    TFloat _wellHeight;
    TFloat _wellDepth;
    
public:
    ABlockout();
    ~ABlockout();
    
    void updateScreenSize(const TDouble screenWidth, const TDouble screenHeight);
    
    void processKeyboardEvent(const TUint buttonCode);
    void processGameCycle();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKOUT_H
