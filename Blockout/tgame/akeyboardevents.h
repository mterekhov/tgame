#ifndef SPCTGAME_AKEYBOARDEVENTS_H
#define SPCTGAME_AKEYBOARDEVENTS_H

//==============================================================================

#include "blockouttypes.h"
#include "keymaps.h"
#include "acrafter.h"
#include "adatastorage.h"
#include "ablockdropeventprocessor.h"
#include "ablockmoveeventprocessor.h"
#include "ablockrotateeventprocessor.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AKeyboardEvents
{
private:
    ABlockDropEventProcessor _dropEventProcessor;
    ABlockMoveEventProcessor _moveEventProcessor;
    ABlockRotateEventProcessor _rotateEventProcessor;

public:
    AKeyboardEvents(ACrafter &crafter, ADataStorage &dataStorage);
    ~AKeyboardEvents();
    
    void keyPressed(TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYBOARDEVENTS_H
