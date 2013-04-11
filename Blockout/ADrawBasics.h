#ifndef ENGINE_ADRAWBASICS_H
#define ENGINE_ADRAWBASICS_H

//==============================================================================

#include "APoint.h"
#include "AVector.h"
#include "ADataLiner.h"
#include "atexture.h"
#include "APoint2D.h"

//==============================================================================

class ADrawBasics
{
private:
    static TPoints2DList generateUV(const ATexture& tex);
    static TPointsList generateCoords(const APoint& location, const GLfloat cubeSize);
    
    static void drawTriangles(const ADataLiner& dataLiner);

public:
    static void installCamera(const AVector& eyePosition3D, const AVector& center3D, const AVector& upVector3D);
    static void drawLine(const APoint& p1, const APoint& p2);

    static void drawTexturedCube(const APoint& pos, const GLfloat cubeSize, const ATexture& texture);
    static void drawSolidCube(const APoint& pos, const GLfloat cubeSize);
    static void drawCarcasedCube(const APoint& pos, const GLfloat cubeSize);

    static void drawOrigin(const APoint& location, const GLfloat scale);
    static void drawGrid(const GLfloat rowsNumber, const GLfloat columnsNumber, const GLfloat scale);
};

//==============================================================================

#endif
