#ifndef Blockout_DrawTypes_h
#define Blockout_DrawTypes_h

//==============================================================================

#include <OpenGL/gl.h>

//==============================================================================

#define PI_NUMBER 3.141592653589793f

/// Invariant pi
#define  PI_INV 0.318309886183791f

/// Radian
#define PI_INV180 0.01745329251994f

/// Invariant radian
#define PI_180INV 57.295779513082322f

/// 2 pi number
#define PI2 6.283185307179586f

/// Precision for float operations
#define PRECISION_EPSILON 0.0001f

#define DEG_TO_RAD(deg)	((deg) * PI_INV180)
#define RAD_TO_DEG(rad) ((rad) * PI_180INV)

//==============================================================================

struct SPoint
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

//==============================================================================

#endif
