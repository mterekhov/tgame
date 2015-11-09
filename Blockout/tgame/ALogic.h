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
    
class ALogic

{
private:
    ADataStorage& _dataStorage;
    
    void generateNewFormation();
    AFormation* generateRandomFormation();

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
