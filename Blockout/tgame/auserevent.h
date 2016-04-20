#ifndef SPCTGAME_AUSEREVENT_H
#define SPCTGAME_AUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AUserEvent
{
public:
    AUserEvent();
    virtual ~AUserEvent();
    
    virtual void processEvent(AGameStepsController& gameStepsController);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AUSEREVENT_H
