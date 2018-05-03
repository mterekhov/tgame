#ifndef SPCTGAME_AFORMATIONOPERATIONS_H
#define SPCTGAME_AFORMATIONOPERATIONS_H

//==============================================================================

#include "aformation.h"
#include "amatrix.h"
#include "afrustumborder.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AFormationOperations
{
private:
    static void defineAxisNewDimension(const TFloat oglCoord, TInt* currentMax, TInt* currentMin);
    static APoint applyMatrixToPoint(const AMatrix& mat, const APoint& in);
    static void frustumFormationPosition(APoint& point, AFormation& f, const AFrustumBorder& frustum);

public:
    static AFormation createRotatedFormation(const AFormation& formationToRotate, const AMatrix& m);
    static AFormation createRotatedFrustumFormation(const AFormation& formationToRotate, const AMatrix& m, const AFrustumBorder& frustum);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AFORMATIONOPERATIONS_H
