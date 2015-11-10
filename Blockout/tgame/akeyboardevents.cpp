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

AKeyboardEvents::AKeyboardEvents(ACrafter &crafter, ADataStorage &dataStorage) : _dropEventProcessor(crafter, dataStorage),
                                                                                 _moveEventProcessor(crafter, dataStorage),
                                                                                 _rotateEventProcessor(crafter, dataStorage)
{
}

//==============================================================================

AKeyboardEvents::~AKeyboardEvents()
{
}

//==============================================================================

void AKeyboardEvents::keyPressed(TUint buttonCode)
{
    switch (buttonCode)
    {
        case EKEYCODES_DOWN:
        case EKEYCODES_UP:
        case EKEYCODES_LEFT:
        case EKEYCODES_RIGHT:
            _moveEventProcessor.processEvent(&buttonCode);
        break;
        
        case EKEYCODES_ROTATE_X:
        case EKEYCODES_ROTATE_Y:
        case EKEYCODES_ROTATE_Z:
            _rotateEventProcessor.processEvent(&buttonCode);
        break;
        
        case EKEYCODES_DROP_BLOCK:
            _dropEventProcessor.processEvent(0);
        break;
    }
}

//==============================================================================

}   //  namespace spcTGame
