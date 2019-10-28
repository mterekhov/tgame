#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "acreatewellgamestep.h"
#include "arandomformationstep.h"
#include "alowerstep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ALogic::ALogic(AGameStepsController& gameStepsController) : _gameStepsController(gameStepsController)
{
}

//==============================================================================

ALogic::~ALogic()
{
}

//==============================================================================

#pragma mark - Public -

//==============================================================================
    
void ALogic::processLogic()
{
    time_t timeStamp = time(NULL);
    if (_previousCycleTimeStamp == 0)
        _previousCycleTimeStamp = timeStamp;
    time_t diff = timeStamp - _previousCycleTimeStamp;
    
    if (diff > LEVEL_DEC_PERIOD)
    {
		_gameStepsController.addStepToProcessQueue(new ALowerStep());
        _previousCycleTimeStamp = timeStamp;
    }
}

//==============================================================================

void ALogic::startGame()
{
	_gameStepsController.addStepToProcessQueue(new ACreateWellGameStep());
	_gameStepsController.addStepToProcessQueue(new ARandomFormationStep());
}

//==============================================================================

}   //  namespace spcTGame
