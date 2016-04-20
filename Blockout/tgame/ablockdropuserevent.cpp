#include "ablockdropuserevent.h"
#include "ablockdropgamestep.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockDropUserEvent::ABlockDropUserEvent()
{
}

//==============================================================================

ABlockDropUserEvent::~ABlockDropUserEvent()
{
}

//==============================================================================

void ABlockDropUserEvent::processEvent(AGameStepsController& gameStepsController)
{
    gameStepsController.addStepToProcessQueue(new ABlockDropGameStep());
}

//==============================================================================

}   //  namespace spcTGame
