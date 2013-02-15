#ifndef __Blockout__ADrawBasics__
#define __Blockout__ADrawBasics__

//==============================================================================

#include "APoint.h"
#include "AVector.h"

//==============================================================================

class ADrawBasics
{
public:
    static void installCamera(const AVector& eyePosition3D, const AVector& center3D, const AVector& upVector3D);
    static void drawLine(const APoint& p1, const APoint& p2);
    static void drawTriangles(const APoint& p1, const APoint& p2, const APoint& p3);

    static void drawSolidCube(const APoint& pos, const GLfloat cubeSize);
    static void drawCarcasedCube(const APoint& pos, const GLfloat cubeSize);

    static void drawOrigin(const APoint& location, const GLfloat scale);
    static void drawGrid(const GLfloat rowsNumber, const GLfloat columnsNumber, const GLfloat scale);
};

//==============================================================================

#endif
