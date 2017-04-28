#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "aformation.h"
#include "apoint.h"
#include "adatastorage.h"
#include "amatrix.h"

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
    
    ADataStorage& _dataStorage;
    
    void generateNewCurrentFormation();
    void decreaseCurrentBlockLevel();

public:
    ALogic(ADataStorage& dataStorage);
    virtual ~ALogic();

    void startGame();
    void processLogic();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ALOGIC_H
