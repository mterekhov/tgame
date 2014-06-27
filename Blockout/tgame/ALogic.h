#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "aformation.h"
#include "apoint.h"
#include "akeyevent.h"
#include "adatastorage.h"
#include "amatrix.h"

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
    void dropCurrentBlock();
    void rotateX();
    void rotateY();
    void rotateZ();
    void rotate(const AMatrix& m);
    
    void generateStartFormation();
    AFormation& generateFormation();
    bool isBreakingWellBound(const APoint& position, const AFormation& formation);

    APoint applyMatrixToPoint(const AMatrix& mat, const APoint& in);
    void defineAxisNewDimension(const TFloat oglCoord, TInt* currentMax, TInt* currentMin);
    AFormation& defineDimmension(const AMatrix& m, std::list<TInt>& shifts, std::list<APoint>& points);

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
