#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "anewwellstep.h"
#include "arandomstep.h"
#include "alowerstep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ALogic::ALogic(AStepsController& gameStepsController) : _stepsController(gameStepsController)
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
		_stepsController.addStepToProcessQueue(new ALowerStep());
        _previousCycleTimeStamp = timeStamp;
    }
}

//==============================================================================

void ALogic::startGame()
{
	_stepsController.addStepToProcessQueue(new ANewWellStep());
	_stepsController.addStepToProcessQueue(new ARandomStep());
}

//==============================================================================

}   //  namespace spcTGame
