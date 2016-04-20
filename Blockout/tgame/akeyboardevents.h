#ifndef SPCTGAME_AKEYBOARDEVENTS_H
#define SPCTGAME_AKEYBOARDEVENTS_H

//==============================================================================

#include "blockouttypes.h"
#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AKeyboardEvents
{
private:
    AGameStepsController& _gameStepsController;

public:
    AKeyboardEvents(AGameStepsController& gameStepsController);
    ~AKeyboardEvents();
    
    void keyPressed(TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYBOARDEVENTS_H
