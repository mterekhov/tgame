#include "ADrawBasics.h"
#include "AOpenGLState.h"
#include "BlockoutDebug.h"

//==============================================================================

#pragma mark - beta -

//==============================================================================

void ADrawBasics::drawTexturedCube(const APoint& pos, const GLfloat cubeSize, ATexture& texture)
{
    TPointsList coordspoints = ADrawBasics::generateCoords(pos, cubeSize);
    TPoints2DList uvpoints = ADrawBasics::generateUV(texture);
    ADataLiner dataLiner;
    dataLiner.pushCoordPointList(coordspoints);
    dataLiner.pushUVPointList(uvpoints);
    TUint sizer = dataLiner.numberOfFloatValues();
    GLfloat* line = new GLfloat[sizer];
    memset(line, 0, sizer * sizeof(GLfloat));
    if (dataLiner.generateArray(line) == false)
    {
        loger("failed to generate array of vertexes");
        return;
    }

    //    for (int i = 0; i < dataLiner.pointsCount(); i++)
//    {
//        loger("xyz = %.3f\t%.3f\t%.3f\nuv = %.3f\t%.3f", line[dataLiner.arrayStride() * i],
//               line[dataLiner.arrayStride() * i + 1],
//               line[dataLiner.arrayStride() * i + 2],
//               line[dataLiner.arrayStride() * i + 3],
//               line[dataLiner.arrayStride() * i + 4]);
//    }
    
    AOpenGLState* instance = AOpenGLState::shared();
    instance->currentTexture(texture);
    
    glTexCoordPointer(2, GL_FLOAT, 3, &line[3]);
    ADrawBasics::drawTriangles(dataLiner);
    
    instance->clearCurrentTexture();
}

//==============================================================================

TPoints2DList ADrawBasics::generateUV(const ATexture& tex)
{
    TPoints2DList points;
    
    GLfloat xaspect = static_cast<GLfloat>(tex.atImageWidth()) / static_cast<GLfloat>(tex.atWidth());
    GLfloat yaspect = static_cast<GLfloat>(tex.atImageHeight()) / static_cast<GLfloat>(tex.atHeight());

    APoint2D p1 = APoint2D(0.0f, 0.0f);
    APoint2D p2 = APoint2D(0.0f, yaspect);
    APoint2D p3 = APoint2D(xaspect, yaspect);
    APoint2D p4 = APoint2D(xaspect, 0.0f);

    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p1);

    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p1);
    
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p1);

    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p1);

    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p1);

    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p1);

    return points;
}

//==============================================================================

void ADrawBasics::drawSolidCube(const APoint& location, const GLfloat cubeSize)
{
    TPointsList pointsList = ADrawBasics::generateCoords(location, cubeSize);
    ADataLiner dataLiner;
    dataLiner.pushCoordPointList(pointsList);
    
    ADrawBasics::drawTriangles(dataLiner);
}

//==============================================================================

void ADrawBasics::drawTriangles(const ADataLiner& dataLiner)
{
    TUint sizer = dataLiner.numberOfFloatValues();
    GLfloat* line = new GLfloat[sizer];
    memset(line, 0, sizer * sizeof(GLfloat));

    if (dataLiner.generateArray(line) == false)
    {
        loger("failed to generate array of vertexes");
        return;
    }

    loger("==================================");
    for (int i = 0; i < sizer; i+=3)
    {
        loger("%i. %.3f\t%.3f\t%.3f", i / 3 + 1, line[i], line[i + 1], line[i + 2]);
    }
    
    glVertexPointer(3, GL_FLOAT, 0, line);
//    glVertexPointer(3, GL_FLOAT, dataLiner.arrayStride(), line);
    glDrawArrays(GL_TRIANGLES, 5, dataLiner.pointsCount());
    
    delete [] line;
}

//==============================================================================

TPointsList ADrawBasics::generateCoords(const APoint& location, const GLfloat cubeSize)
{
    APoint p1 = location;
    APoint p2 = APoint(location.x + cubeSize, location.y, location.z);
    APoint p3 = APoint(location.x + cubeSize, location.y, location.z + cubeSize);
    APoint p4 = APoint(location.x,            location.y, location.z + cubeSize);

    APoint p5 = APoint(location.x,            location.y + cubeSize, location.z);
    APoint p6 = APoint(location.x + cubeSize, location.y + cubeSize, location.z);
    APoint p7 = APoint(location.x + cubeSize, location.y + cubeSize, location.z + cubeSize);
    APoint p8 = APoint(location.x,            location.y + cubeSize, location.z + cubeSize);

    TPointsList points;
    
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p4);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p8);
    points.push_back(p6);
    points.push_back(p7);
    points.push_back(p8);
    
    points.push_back(p5);
    points.push_back(p8);
    points.push_back(p1);
    points.push_back(p8);
    points.push_back(p4);
    points.push_back(p1);

    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p1);
    points.push_back(p6);
    points.push_back(p2);
    points.push_back(p1);

    points.push_back(p6);
    points.push_back(p7);
    points.push_back(p2);
    points.push_back(p7);
    points.push_back(p3);
    points.push_back(p2);

    points.push_back(p8);
    points.push_back(p7);
    points.push_back(p4);
    points.push_back(p7);
    points.push_back(p3);
    points.push_back(p4);

    return points;
}

//==============================================================================

#pragma mark - render basics -

//==============================================================================

void ADrawBasics::drawCarcasedCube(const APoint& location, const GLfloat cubeSize)
{
    APoint p1 = location;
    APoint p2 = APoint(location.x + cubeSize, location.y, location.z);
    APoint p3 = APoint(location.x + cubeSize, location.y, location.z + cubeSize);
    APoint p4 = APoint(location.x,            location.y, location.z + cubeSize);

    ADrawBasics::drawLine(p1, p2);
    ADrawBasics::drawLine(p2, p3);
    ADrawBasics::drawLine(p3, p4);
    ADrawBasics::drawLine(p4, p1);

    APoint p5 = APoint(location.x,            location.y + cubeSize, location.z);
    APoint p6 = APoint(location.x + cubeSize, location.y + cubeSize, location.z);
    APoint p7 = APoint(location.x + cubeSize, location.y + cubeSize, location.z + cubeSize);
    APoint p8 = APoint(location.x,            location.y + cubeSize, location.z + cubeSize);

    ADrawBasics::drawLine(p5, p6);
    ADrawBasics::drawLine(p6, p7);
    ADrawBasics::drawLine(p7, p8);
    ADrawBasics::drawLine(p8, p5);

    ADrawBasics::drawLine(p5, p1);
    ADrawBasics::drawLine(p6, p2);
    ADrawBasics::drawLine(p7, p3);
    ADrawBasics::drawLine(p8, p4);
}

//==============================================================================

void ADrawBasics::drawLine(const APoint& p1, const APoint& p2)
{
    GLfloat line[6] = {0};
    line[0] = p1.x;
    line[1] = p1.y;
    line[2] = p1.z;

    line[3] = p2.x;
    line[4] = p2.y;
    line[5] = p2.z;

    glVertexPointer(3, GL_FLOAT, 0, line);
    glDrawArrays(GL_LINES, 0, 2);
}

//==============================================================================

#pragma mark - render some usefull stuff -

//==============================================================================

void ADrawBasics::drawOrigin(const APoint& location, const GLfloat scale)
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    AColor color = oglInstance->drawColor();
    
    oglInstance->drawColor(AColor::redColor());
    APoint tmpPoint = APoint(location.x + scale, location.y, location.z);
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(AColor::greenColor());
    tmpPoint.x = location.x;
    tmpPoint.y = location.y + scale;
    tmpPoint.z = location.z;
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(AColor::blueColor());
    tmpPoint.x = location.x;
    tmpPoint.y = location.y;
    tmpPoint.z = location.z + scale;
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(color);
}

//==============================================================================

void ADrawBasics::drawGrid(const GLfloat rowsNumber, const GLfloat columnsNumber, const GLfloat scale)
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    AColor color = oglInstance->drawColor();

    oglInstance->drawColor(AColor::whiteColor());
    for (GLfloat i = -50.0f; i < 50.0f; i+= 1.0f)
        drawLine(APoint(-50.0f * scale, 0.0f, i * scale), APoint(50.0f * scale, 0.0f, i * scale));

    for (GLfloat i = -50.0f; i < 50.0f; i+= 1.0f)
        drawLine(APoint(i * scale, 0.0f, -50.0f * scale), APoint(i * scale, 0.0f, 50.0f * scale));

    oglInstance->drawColor(color);
}

//==============================================================================

void ADrawBasics::installCamera(const AVector& eyePosition3D, const AVector& center3D, const AVector& upVector3D)
{
    GLfloat m[16] = {0.0f};
    GLfloat x[3] = {0.0f};
    GLfloat y[3] = {0.0f};
    GLfloat z[3] = {0.0f};
    GLfloat mag = 0.0f;

    /* Make rotation matrix */

    /* Z vector */
    z[0] = eyePosition3D.x - center3D.x;
    z[1] = eyePosition3D.y - center3D.y;
    z[2] = eyePosition3D.z - center3D.z;
    mag = sqrtf(z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);
    if (mag) {          /* mpichler, 19950515 */
        z[0] /= mag;
        z[1] /= mag;
        z[2] /= mag;
    }

    /* Y vector */
    y[0] = upVector3D.x;
    y[1] = upVector3D.y;
    y[2] = upVector3D.z;

    /* X vector = Y cross Z */
    x[0] = y[1] * z[2] - y[2] * z[1];
    x[1] = -y[0] * z[2] + y[2] * z[0];
    x[2] = y[0] * z[1] - y[1] * z[0];

    /* Recompute Y = Z cross X */
    y[0] = z[1] * x[2] - z[2] * x[1];
    y[1] = -z[0] * x[2] + z[2] * x[0];
    y[2] = z[0] * x[1] - z[1] * x[0];

    /* mpichler, 19950515 */
    /* cross product gives area of parallelogram, which is < 1.0 for
     * non-perpendicular unit-length vectors; so normalize x, y here
     */

    mag = sqrtf(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
    if (mag) {
        x[0] /= mag;
        x[1] /= mag;
        x[2] /= mag;
    }

    mag = sqrt(y[0] * y[0] + y[1] * y[1] + y[2] * y[2]);
    if (mag) {
        y[0] /= mag;
        y[1] /= mag;
        y[2] /= mag;
    }

    #define M(row,col)  m[col * 4 + row]
    M(0, 0) = x[0];
    M(0, 1) = x[1];
    M(0, 2) = x[2];
    M(0, 3) = 0.0f;
    M(1, 0) = y[0];
    M(1, 1) = y[1];
    M(1, 2) = y[2];
    M(1, 3) = 0.0f;
    M(2, 0) = z[0];
    M(2, 1) = z[1];
    M(2, 2) = z[2];
    M(2, 3) = 0.0f;
    M(3, 0) = 0.0f;
    M(3, 1) = 0.0f;
    M(3, 2) = 0.0f;
    M(3, 3) = 1.0f;
    #undef M
    glMultMatrixf(m);

    /* Translate Eye to Origin */
    glTranslatef(-eyePosition3D.x, -eyePosition3D.y, -eyePosition3D.z);
}
