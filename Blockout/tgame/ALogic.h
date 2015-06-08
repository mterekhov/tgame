#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "aformation.h"
#include "apoint.h"
#include "akeyeventdelegate.h"
#include "adatastorage.h"
#include "amatrix.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================
    
class ALogic : public AKeyEventDelegate
{
private:
    ADataStorage& _dataStorage;
    
    void moveCurrentBlockDown();
    void moveCurrentBlockUp();
    void moveCurrentBlockLeft();
    void moveCurrentBlockRight();
    void dropCurrentBlock();
    void rotateX();
    void rotateY();
    void rotateZ();
    void rotate(const AMatrix& m);
    
    void generateNewFormation();
    AFormation* generateRandomFormation();
    bool isBreakingWellBound(const APoint& position, const AFormation* formation);

    void makeDrop(AFormation* formation);
    APoint findDropPosition(AFormation* formation);

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
