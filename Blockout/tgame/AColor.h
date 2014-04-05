#ifndef ENGINE_ACOLOR_H
#define ENGINE_ACOLOR_H

//==============================================================================

#include "BlockoutTypes.h"

//==============================================================================

class AColor
{
public:
    static AColor whiteColor();
    static AColor blackColor();
    static AColor redColor();
    static AColor greenColor();
    static AColor blueColor();

    AColor();
    AColor(const TFloat _red, const TFloat _green, const TFloat _blue, const TFloat _alpha);
    AColor(const AColor& color);
    ~AColor();
    
    void normalize();

    TFloat red;
    TFloat green;
    TFloat blue;
    TFloat alpha;
};

//==============================================================================

#endif