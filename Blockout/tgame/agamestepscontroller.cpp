#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AGameStepsController::AGameStepsController(ADataStorage &dataStorage) : _dataStorage(dataStorage)
{
}

//==============================================================================

AGameStepsController::~AGameStepsController()
{
}

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
    printf("start %i steps execution ... ", _stepsQueue.size());
    for (TGameStepsQueueIter iter = _stepsQueue.begin(); iter != _stepsQueue.end(); iter++)
    {
        AGameStepProtocol *step = *iter;
        step->executeStep(_dataStorage);
        delete step;
    }
    
    _stepsQueue.clear();
    printf("finished\n");
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
