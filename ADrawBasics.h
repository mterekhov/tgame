#ifndef __Blockout__ADrawBasics__
#define __Blockout__ADrawBasics__

//==============================================================================

#include <OpenGL/OpenGL.h>

//==============================================================================

class ADrawBasics
{
public:
    static ADrawBasics& instance();
    ADrawBasics();
    ~ADrawBasics();
    
    static void drawCube(const GLfloat x, const GLfloat y, const GLfloat z);

private:
    static ADrawBasics* _basics;
};

//==============================================================================

#endif
