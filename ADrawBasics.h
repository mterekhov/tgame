#ifndef __Blockout__ADrawBasics__
#define __Blockout__ADrawBasics__

//==============================================================================

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#include "DrawTypes.h"

//==============================================================================

class ADrawBasics
{
public:
    static const GLfloat scale;
    
    static ADrawBasics& instance();
    ADrawBasics();
    ~ADrawBasics();
    
    static void drawCube(const GLfloat x, const GLfloat y, const GLfloat z);
    static void drawOrigin(const SPoint& location);
    static void drawGrid(const GLfloat rowsNumber, const GLfloat columnsNumber);

private:
    static ADrawBasics* _basics;

    static void drawLine(const SPoint& p1, const SPoint& p2);
};

//==============================================================================

#endif
