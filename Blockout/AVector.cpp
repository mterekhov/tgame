#include "AVector.h"

//==============================================================================

AVector::AVector() : x(0.0f), y(0.0f), z(0.0f)
{
}

//==============================================================================

AVector::AVector(const TFloat x, const TFloat y, const TFloat z) : x(x), y(y), z(z)
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
    TFloat len = x * x + y * y + z * z;
    if (len < FLOAT_PRECISION)
    {
        x /= sqrtf(len);
        y /= sqrtf(len);
        z /= sqrtf(len);
    }
}
