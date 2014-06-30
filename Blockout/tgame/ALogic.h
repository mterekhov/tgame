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

typedef std::list<APoint> TRotatedPoints;
typedef TRotatedPoints::iterator TRPIter;
//typedef std::list<TInt> TPositionShift;
//typedef TPositionShift::iterator TPSIter;

#define SHIFT_DIMMENSION 3

struct SRotationMetaData
{
    TInt negativeShifts[SHIFT_DIMMENSION];
    TInt positionShift[SHIFT_DIMMENSION];
    TInt newDimmension[SHIFT_DIMMENSION];
    
    TRotatedPoints rotatedPoints;
};

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
    AFormation& generateRandomFormation();
    bool isBreakingWellBound(const APoint& position, const AFormation& formation);

    APoint applyMatrixToPoint(const AMatrix& mat, const APoint& in);
    void defineAxisNewDimension(const TFloat oglCoord, TInt* currentMax, TInt* currentMin);
    AFormation& createRotatedFormation(const AMatrix& m, SRotationMetaData& rotationMeta);

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
