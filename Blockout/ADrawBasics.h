#ifndef __Blockout__ADrawBasics__
#define __Blockout__ADrawBasics__

//==============================================================================

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#include "DrawTypes.h"
#include "AVector.h"

//==============================================================================

class ADrawBasics
{
public:
    static const GLfloat scale;
    
    static void installCamera(const AVector& eyePosition3D, const AVector& center3D, const AVector& upVector3D);
    static void drawLine(const SPoint& p1, const SPoint& p2);
    static void drawCube(const GLfloat x, const GLfloat y, const GLfloat z);
    static void drawOrigin(const SPoint& location);
    static void drawGrid(const GLfloat rowsNumber, const GLfloat columnsNumber);
};

//==============================================================================

#endif
