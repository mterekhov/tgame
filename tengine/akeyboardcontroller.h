#ifndef SPCTGAME_AKEYBOARDCONTROLLER_H
#define SPCTGAME_AKEYBOARDCONTROLLER_H

//==============================================================================

#include "blockouttypes.h"
#include "astepscontroller.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AKeyboardController
{
private:
    AStepsController& _stepsController;

public:
    AKeyboardController(AStepsController& stepsController);
    ~AKeyboardController();
    
    void keyPressed(TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYBOARDCONTROLLER_H
