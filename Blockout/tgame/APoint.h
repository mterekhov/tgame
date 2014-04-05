#ifndef ENGINE_APOINT_H
#define ENGINE_APOINT_H

//==============================================================================

#include <vector>
#include "BlockoutTypes.h"

//==============================================================================

class APoint
{
public:
    APoint();
    APoint(const TFloat x, const TFloat y, const TFloat z);
    APoint(const APoint& point);
    ~APoint();

    TFloat x;
    TFloat y;
    TFloat z;
};

//==============================================================================

typedef std::vector<APoint> TPointsList;

//==============================================================================

#endif