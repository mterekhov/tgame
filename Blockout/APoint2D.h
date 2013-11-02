#ifndef ENGINE_APOINT2D_H
#define ENGINE_APOINT2D_H

//==============================================================================

#include <vector>
#include "BlockoutTypes.h"

//==============================================================================

class APoint2D
{
public:
    APoint2D();
    APoint2D(const TFloat x, const TFloat y);
    APoint2D(const APoint2D& point);
    ~APoint2D();

    TFloat x;
    TFloat y;
};

//==============================================================================

typedef std::vector<APoint2D> TPoints2DList;

//==============================================================================

#endif
