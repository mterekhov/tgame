#ifndef ENGINE_ADATALINER_H
#define ENGINE_ADATALINER_H

#include "APoint.h"
#include "APoint2D.h"
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
    
    TUlong numberOfFloatValues() const;
    TUint arrayStride() const;
    TUint pointsCount() const;

    EIntegrity checkIntegrity() const;
    bool generateArray(TFloat* resultArray) const;
};

//==============================================================================

#endif
