#ifndef ENGINE_ACOLOR_H
#define ENGINE_ACOLOR_H

//==============================================================================

#include "DrawTypes.h"

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
    AColor(const GLfloat _red, const GLfloat _green, const GLfloat _blue, const GLfloat _alpha);
    AColor(const AColor& color);
    ~AColor();
    
    void normalize();

    GLfloat red;
    GLfloat green;
    GLfloat blue;
    GLfloat alpha;
};

//==============================================================================

#endif
