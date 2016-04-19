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
public:
    AUserEvent();
    virtual ~AUserEvent();
    
    virtual void processEvent(ACrafter &crafter, ADataStorage &dataStorage);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AUSEREVENT_H
