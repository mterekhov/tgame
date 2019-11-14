#include "astepscontroller.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AStepsController::AStepsController()
{
}

//==============================================================================

AStepsController::~AStepsController()
{
}

//==============================================================================

void AStepsController::addStepToProcessQueue(AStepProtocol *gameStep)
{
    if (gameStep == 0)
        return;
    
    _stepsQueue.push_back(gameStep);
}

//==============================================================================

TUint AStepsController::processSteps(ADataStorage& dataStorage)
{
    printf("start %i steps execution ... ", _stepsQueue.size());
    
    TUint stepsProcessed = 0;
    for (TGameStepsQueueIter iter = _stepsQueue.begin(); iter != _stepsQueue.end(); iter++)
    {
        AStepProtocol *step = *iter;
        step->executeStep(dataStorage);
        delete step;
        stepsProcessed++;
    }

    _stepsQueue.clear();
    printf("finished\n");
    
    return stepsProcessed;
}

//==============================================================================

void AStepsController::destroyAllSteps()
{
    for (TGameStepsQueueIter iter = _stepsQueue.begin(); iter != _stepsQueue.end(); iter++)
        delete *iter;
    
    _stepsQueue.clear();
}

//==============================================================================

}   //  namespace spcTGame
