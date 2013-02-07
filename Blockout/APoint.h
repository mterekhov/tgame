#ifndef __Blockout__APoint__
#define __Blockout__APoint__

//==============================================================================

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

#endif
