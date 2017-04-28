#ifndef SPCTGAME_ABLOCKOUT_H
#define SPCTGAME_ABLOCKOUT_H

//==============================================================================

#include "acrafter.h"
#include "alogic.h"
#include "acolor.h"
#include "akeyboardevents.h"
#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ABlockout
{
private:
    void init();
    void render();

    ADataStorage _dataStorage;
    ACrafter _crafter;
    ALogic _logic;
    AKeyboardEvents _keyboardEvents;
        
public:
    ABlockout();
    ~ABlockout();
    
    void updateScreenSize(const TDouble screenWidth, const TDouble screenHeight);
    
    void startGame();
    void processKeyboardEvent(const TUint buttonCode);
    void processGameCycle();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKOUT_H
