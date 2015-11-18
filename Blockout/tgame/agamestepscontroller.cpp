#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

void AGameStepsController::addStepToProcessQueue(AGameStepProtocol *gameStep)
{
    if (gameStep == 0)
        return;
    
    _stepsQueue.push_back(gameStep);
}

//==============================================================================

void AGameStepsController::processSteps()
{
    for (TGameStepsQueueIter iter = _stepsQueue.begin(); iter != _stepsQueue.end(); iter++)
    {
        AGameStepProtocol *step = *iter;
        step->executeStep();
    }
    
    _stepsQueue.clear();
}

//==============================================================================

void AGameStepsController::destroyAllSteps()
{
    for (TGameStepsQueueIter iter = _stepsQueue.begin(); iter != _stepsQueue.end(); iter++)
        delete *iter;
    
    _stepsQueue.clear();
}

//==============================================================================

}   //  namespace spcTGame
