#ifndef ENGINE_APOINT_H
#define ENGINE_APOINT_H

//==============================================================================

#include <vector>
#include "DrawTypes.h"

//==============================================================================

class APoint
{
public:
    APoint();
    APoint(const GLfloat x, const GLfloat y, const GLfloat z);
    APoint(const APoint& point);
    ~APoint();

    GLfloat x;
    GLfloat y;
    GLfloat z;
};

//==============================================================================

typedef std::vector<APoint> TPointsList;

//==============================================================================

#endif
