#ifndef SPCTGAME_ABLOCKMOVEUSEREVENT_H
#define SPCTGAME_ABLOCKMOVEUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "auserevent.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockMoveUserEvent : public AUserEvent
{
private:
    TUint _buttonCode;

public:
    ABlockMoveUserEvent(const TUint buttonCode);
    virtual ~ABlockMoveUserEvent();

    virtual void processEvent(AGameStepsController& gameStepsController);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKMOVEUSEREVENT_H
