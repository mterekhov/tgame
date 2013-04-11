#ifndef ENGINE_APOINT2D_H
#define ENGINE_APOINT2D_H

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

typedef std::vector<APoint2D> TPoints2DList;

//==============================================================================

#endif
