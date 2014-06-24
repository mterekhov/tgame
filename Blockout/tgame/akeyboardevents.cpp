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

void AKeyboardEvents::addDelegate(AKeyEvent& newDelegate)
{
    _delegates.push_back(&newDelegate);
}

//==============================================================================

void AKeyboardEvents::keyPressed(const TUint buttonCode)
{
    for (TKeyDelegateListIter iter = _delegates.begin(); iter != _delegates.end(); iter++)
    {
        (*iter)->processKey(buttonCode);
    }
}

//==============================================================================

}   //  namespace spcTGame
