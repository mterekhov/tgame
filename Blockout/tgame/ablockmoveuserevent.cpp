#include "ablockmoveuserevent.h"
#include "ablockmovegamestep.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockMoveUserEvent::ABlockMoveUserEvent(const TUint buttonCode) : _buttonCode(buttonCode)
{
}

//==============================================================================

ABlockMoveUserEvent::~ABlockMoveUserEvent()
{
}

//==============================================================================

void ABlockMoveUserEvent::processEvent(AGameStepsController& gameStepsController)
{    
    gameStepsController.addStepToProcessQueue(new ABlockMoveGameStep(_buttonCode));
}

//==============================================================================

}   //  namespace spcTGame
