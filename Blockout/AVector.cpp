#include <math.h>

#include "AVector.h"

//==============================================================================

AVector::AVector() : x(0), y(0), z(0)
{
}

//==============================================================================

AVector::AVector(const GLfloat x, const GLfloat y, const GLfloat z) : x(x), y(y), z(z)
{
}

//==============================================================================

AVector::AVector(const AVector& vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
}

//==============================================================================

AVector::~AVector()
{
}

//==============================================================================

void AVector::normalize()
{
    GLfloat len = x * x + y * y + z * z;
    if (len != 0)
    {
        x /= sqrtf(len);
        y /= sqrtf(len);
        z /= sqrtf(len);
    }
}
