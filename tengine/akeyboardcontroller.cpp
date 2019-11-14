#include "akeyboardcontroller.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "amoveformationstep.h"
#include "arotateformationstep.h"
#include "adropstep.h"
#include "arandomstep.h"

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

AKeyboardController::AKeyboardController(AStepsController& stepsController) : _stepsController(stepsController)
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
		    _stepsController.addStepToProcessQueue(new AMoveFormationStep(buttonCode));
        break;
        
        case EKEYCODES_ROTATE_X:
        case EKEYCODES_ROTATE_Y:
        case EKEYCODES_ROTATE_Z:
		    _stepsController.addStepToProcessQueue(new ARotateFormationStep(buttonCode));
        break;
        
        case EKEYCODES_DROP_BLOCK:
		    _stepsController.addStepToProcessQueue(new ADropStep());
		    _stepsController.addStepToProcessQueue(new ARandomStep());
        break;
    }
}

//==============================================================================

}   //  namespace spcTGame
