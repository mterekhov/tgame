#ifndef SPCTGAME_ABLOCKDROPUSEREVENT_H
#define SPCTGAME_ABLOCKDROPUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "auserevent.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockDropUserEvent : public AUserEvent
{
public:
    ABlockDropUserEvent();
    virtual ~ABlockDropUserEvent();

    virtual void processEvent(AGameStepsController& gameStepsController);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKDROPUSEREVENT_H
