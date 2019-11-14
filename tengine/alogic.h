#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "astepscontroller.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

#define LEVEL_DEC_PERIOD 1

//==============================================================================
    
class ALogic
{
private:
    time_t _previousCycleTimeStamp;
	AStepsController &_stepsController;
	
public:
    ALogic(AStepsController& gameStepsController);
    virtual ~ALogic();

    void startGame();
    void processLogic();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ALOGIC_H
