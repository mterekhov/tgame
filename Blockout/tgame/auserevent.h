#ifndef SPCTGAME_AUSEREVENT_H
#define SPCTGAME_AUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "acrafter.h"
#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AUserEvent
{
protected:
    ACrafter &_crafter;
    ADataStorage &_dataStorage;

public:
    AUserEvent(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~AUserEvent();
    
    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AUSEREVENT_H
