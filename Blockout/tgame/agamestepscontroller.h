#ifndef SPCTGAME_AGAMESTEPSCONTROLLER_H
#define SPCTGAME_AGAMESTEPSCONTROLLER_H

//==============================================================================

#include <vector>

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::vector<AGameStepProtocol*> TGameStepsQueue;
typedef TGameStepsQueue::iterator TGameStepsQueueIter;
typedef TGameStepsQueue::const_iterator TGameStepsQueueConstIter;

//==============================================================================

class AGameStepsController
{
private:
    ADataStorage& _dataStorage;
    TGameStepsQueue _stepsQueue;
    
    void destroyAllSteps();

public:
    AGameStepsController(ADataStorage &dataStorage);
    ~AGameStepsController();
    void addStepToProcessQueue(AGameStepProtocol *gameStep);
    void processSteps();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AGAMESTEPSCONTROLLER_H
