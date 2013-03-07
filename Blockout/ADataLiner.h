#ifndef __Blockout__ADataLiner__
#define __Blockout__ADataLiner__

#include "APoint.h"
#include "APoint2D.h"
#include "DrawTypes.h"
#include "BlockoutTypes.h"

//==============================================================================

enum EIntegrity
{
    EINTEGRITY_OK,
    EINTEGRITY_INCONSISTENT
};

//==============================================================================

class ADataLiner
{
private:
    TPointsList _coordsList;
    TPoints2DList _uvList;
    TPointsList _normalsList;

public:
    ADataLiner();
    ~ADataLiner();
    
    void pushPoint(const APoint& coords);
    void pushUVPoint(const APoint2D& point);
    void pushNormalPoint(const APoint& point);

    void pushCoordPointList(const TPointsList& pointsList);
    void pushUVPointList(const TPoints2DList& pointsList);
    void pushNormalPointList(const TPointsList& pointsList);
    
    TUlong arrayElementsNumber();
    TUint arrayStride();

    EIntegrity checkIntegrity();
    bool generateArray(GLfloat* resultArray);
};

//==============================================================================

#endif
