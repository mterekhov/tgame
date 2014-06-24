#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "aformation.h"
#include "apoint.h"
#include "akeyevent.h"
#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ALogic : public AKeyEvent
{
private:
    ADataStorage& _dataStorage;
    
    void moveCurrentBlockDown();
    void moveCurrentBlockUp();
    void moveCurrentBlockLeft();
    void moveCurrentBlockRight();
    
   AFormation& generateFormation();

public:
    ALogic(ADataStorage& dataStorage);
    virtual ~ALogic();
    
    TBool collisions(const AFormation* forCompare, const APoint& pos);
    void startGame();

    virtual void processKey(const TUint buttonCode);
    void processLogic();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ALOGIC_H
