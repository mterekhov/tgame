#ifndef SPCTGAME_ASTEPSCONTROLLER_H
#define SPCTGAME_ASTEPSCONTROLLER_H

//==============================================================================

#include <vector>

#include "astepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::vector<AStepProtocol*> TGameStepsQueue;
typedef TGameStepsQueue::iterator TGameStepsQueueIter;
typedef TGameStepsQueue::const_iterator TGameStepsQueueConstIter;

//==============================================================================

class AStepsController
{
private:
    TGameStepsQueue _stepsQueue;
    
    void destroyAllSteps();

public:
    AStepsController();
    ~AStepsController();
    void addStepToProcessQueue(AStepProtocol *gameStep);
    TUint processSteps(ADataStorage& dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ASTEPSCONTROLLER_H
