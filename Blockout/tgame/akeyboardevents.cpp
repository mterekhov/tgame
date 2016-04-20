#include "akeyboardevents.h"
#include "blockoutdebug.h"
#include "keymaps.h"

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

AKeyboardEvents::AKeyboardEvents(AGameStepsController& gameStepsController) : _gameStepsController(gameStepsController)
{
}

//==============================================================================

AKeyboardEvents::~AKeyboardEvents()
{
}

//==============================================================================

void AKeyboardEvents::keyPressed(TUint buttonCode)
{
    AUserEvent *userEvent;
    
    switch (buttonCode)
    {
        case EKEYCODES_DOWN:
        case EKEYCODES_UP:
        case EKEYCODES_LEFT:
        case EKEYCODES_RIGHT:
            userEvent = new ABlockMoveUserEvent(buttonCode);
        break;
        
        case EKEYCODES_ROTATE_X:
        case EKEYCODES_ROTATE_Y:
        case EKEYCODES_ROTATE_Z:
            userEvent = new ABlockRotateUserEvent(buttonCode);
        break;
        
        case EKEYCODES_DROP_BLOCK:
            userEvent = new ABlockDropUserEvent();
        break;
    }
    
    if (userEvent)
        userEvent->processEvent(_gameStepsController);
}

//==============================================================================

}   //  namespace spcTGame
