#ifndef __Blockout__APoint2D__
#define __Blockout__APoint2D__

//==============================================================================

#include <vector>
#include "DrawTypes.h"

//==============================================================================

class APoint2D
{
public:
    APoint2D();
    APoint2D(const GLfloat x, const GLfloat y);
    APoint2D(const APoint2D& point);
    ~APoint2D();

    GLfloat x;
    GLfloat y;
};

//==============================================================================

typedef std::vector<APoint2D> TPointsList;

//==============================================================================

#endif
