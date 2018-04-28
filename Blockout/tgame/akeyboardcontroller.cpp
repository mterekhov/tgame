#include "akeyboardcontroller.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "ablockmovegamestep.h"
#include "ablockrotategamestep.h"
#include "ablockdropgamestep.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

TStringMap stringToKeycode = {{"moveUp", EKEYCODES_UP},
                              {"moveDown", EKEYCODES_DOWN},
                              {"moveLeft", EKEYCODES_LEFT},
                              {"moveRight", EKEYCODES_RIGHT},
                              {"rotateX", EKEYCODES_ROTATE_X},
                              {"rotateY", EKEYCODES_ROTATE_Y},
                              {"rotateZ", EKEYCODES_ROTATE_Z},
                              {"dropBlock", EKEYCODES_DROP_BLOCK}
                              };

//==============================================================================

AKeyboardController::AKeyboardController(AGameStepsController& gameStepsController) : _gameStepsController(gameStepsController)
{
}

//==============================================================================

AKeyboardController::~AKeyboardController()
{
}

//==============================================================================

void AKeyboardController::keyPressed(TUint buttonCode)
{
    switch (buttonCode)
    {
        case EKEYCODES_DOWN:
        case EKEYCODES_UP:
        case EKEYCODES_LEFT:
        case EKEYCODES_RIGHT:
		    _gameStepsController.addStepToProcessQueue(new ABlockMoveGameStep(buttonCode));
        break;
        
        case EKEYCODES_ROTATE_X:
        case EKEYCODES_ROTATE_Y:
        case EKEYCODES_ROTATE_Z:
		    _gameStepsController.addStepToProcessQueue(new ABlockRotateGameStep(buttonCode));
        break;
        
        case EKEYCODES_DROP_BLOCK:
		    _gameStepsController.addStepToProcessQueue(new ABlockDropGameStep());
        break;
    }
}

//==============================================================================

}   //  namespace spcTGame
