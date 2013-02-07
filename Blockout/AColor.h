#ifndef __Blockout__AColor__
#define __Blockout__AColor__

//==============================================================================

#include <OpenGL/gl.h>

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
