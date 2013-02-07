#ifndef Blockout_DrawTypes_h
#define Blockout_DrawTypes_h

//==============================================================================

#include <OpenGL/gl.h>

//==============================================================================

#define FLOAT_PRECISION 0.000001f
#define DEG_TO_RAD(deg)	((deg) * M_PI / 180.0f)
#define RAD_TO_DEG(rad) ((rad) * 180.0f / M_PI)

//==============================================================================

struct SPoint
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

//==============================================================================

#endif
