#ifndef SPCTGAME_ADRAWBASICS_H
#define SPCTGAME_ADRAWBASICS_H

//==============================================================================

#include "APoint.h"
#include "AVector.h"
#include "ADataLiner.h"
#include "atexture.h"
#include "APoint2D.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ADrawBasics
{
private:
    static TPoints2DList generateUV(const ATexture& tex);
    static TPointsList generateCoords(const APoint& location, const TFloat cubeSize);
    
    static void drawTriangles(const ADataLiner& dataLiner);

public:
    static void installCamera(const AVector& eyePosition3D, const AVector& center3D, const AVector& upVector3D);
    static void drawLine(const APoint& p1, const APoint& p2);

    static void drawTexturedCube(const APoint& pos, const TFloat cubeSize, ATexture& texture);
    static void drawSolidCube(const APoint& pos, const TFloat cubeSize);
    static void drawCarcasedCube(const APoint& pos, const TFloat cubeSize);

    static void drawOrigin(const APoint& location, const TFloat scale);
    static void drawGrid(const TFloat rowsNumber, const TFloat columnsNumber, const TFloat scale);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif
