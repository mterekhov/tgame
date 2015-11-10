#ifndef SPCTGAME_AGAMEEVENTDELEGATE_H
#define SPCTGAME_AGAMEEVENTDELEGATE_H

//==============================================================================

#include "blockouttypes.h"
#include "acrafter.h"
#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AGameEventDelegate
{
protected:
    ACrafter &_crafter;
    ADataStorage &_dataStorage;

public:
    AGameEventDelegate(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~AGameEventDelegate();
    
    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AGAMEEVENTDELEGATE_H
