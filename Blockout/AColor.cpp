#include "AColor.h"

//==============================================================================

AColor AColor::blueColor()
{
    return AColor(0.0f, 0.0f, 1.0f, 1.0f);
}

//==============================================================================

AColor AColor::greenColor()
{
    return AColor(0.0f, 1.0f, 0.0f, 1.0f);
}

//==============================================================================

AColor AColor::redColor()
{
    return AColor(1.0f, 0.0f, 0.0f, 1.0f);
}

//==============================================================================

AColor AColor::whiteColor()
{
    return AColor(1.0f, 1.0f, 1.0f, 1.0f);
}

//==============================================================================

AColor AColor::blackColor()
{
    return AColor();
}

//==============================================================================

AColor::AColor() : red(0.0f), green(0.0f), blue(0.0f), alpha(1.0f)
{
}

//==============================================================================

AColor::AColor(const GLfloat _red, const GLfloat _green, const GLfloat _blue, const GLfloat _alpha) : red(_red), green(_green), blue(_blue), alpha(_alpha)
{
}

//==============================================================================

AColor::AColor(const AColor& color)
{
    red = color.red;
    green = color.green;
    blue = color.blue;
    alpha = color.alpha;
}

//==============================================================================

AColor::~AColor()
{
}
