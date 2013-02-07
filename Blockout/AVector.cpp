#include "AVector.h"
#include "DrawTypes.h"

//==============================================================================

AVector::AVector() : x(0.0f), y(0.0f), z(0.0f)
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
    if (len < FLOAT_PRECISION)
    {
        x /= sqrtf(len);
        y /= sqrtf(len);
        z /= sqrtf(len);
    }
}
