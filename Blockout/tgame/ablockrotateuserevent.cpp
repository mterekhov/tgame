#include "ablockrotateuserevent.h"
#include "ablockrotategamestep.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockRotateUserEvent::ABlockRotateUserEvent(const TUint buttonCode) : _buttonCode(buttonCode) 
{
}

//==============================================================================

ABlockRotateUserEvent::~ABlockRotateUserEvent()
{
}

//==============================================================================

void ABlockRotateUserEvent::processEvent(AGameStepsController& gameStepsController)
{
    gameStepsController.addStepToProcessQueue(new ABlockRotateGameStep(_buttonCode));
}

//==============================================================================

}   //  namespace spcTGame
