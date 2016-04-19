#ifndef SPCTGAME_AKEYBOARDEVENTS_H
#define SPCTGAME_AKEYBOARDEVENTS_H

//==============================================================================

#include "blockouttypes.h"
#include "keymaps.h"
#include "acrafter.h"
#include "adatastorage.h"
#include "ablockdropuserevent.h"
#include "ablockmoveuserevent.h"
#include "ablockrotateuserevent.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AKeyboardEvents
{
private:
    ACrafter& _crafter;
    ADataStorage& _dataStorage;

public:
    AKeyboardEvents(ACrafter &crafter, ADataStorage &dataStorage);
    ~AKeyboardEvents();
    
    void keyPressed(TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYBOARDEVENTS_H
