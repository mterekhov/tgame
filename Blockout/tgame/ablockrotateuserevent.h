#ifndef SPCTGAME_ABLOCKROTATEUSEREVENT_H
#define SPCTGAME_ABLOCKROTATEUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "auserevent.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockRotateUserEvent : public AUserEvent
{
private:
    TUint _buttonCode;
    
public:
    ABlockRotateUserEvent(const TUint buttonCode);
    virtual ~ABlockRotateUserEvent();

    virtual void processEvent(AGameStepsController& gameStepsController);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKROTATEUSEREVENT_H
