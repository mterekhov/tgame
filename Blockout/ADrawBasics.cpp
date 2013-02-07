#include "ADrawBasics.h"
#include "AOpenGLState.h"

//==============================================================================

const GLfloat ADrawBasics::scale = 1.0f;

//==============================================================================

void ADrawBasics::drawCube(const GLfloat x, const GLfloat y, const GLfloat z)
{
}

//==============================================================================

void ADrawBasics::drawLine(const SPoint& p1, const SPoint& p2)
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

void ADrawBasics::drawOrigin(const SPoint& location)
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    AColor color = oglInstance->drawColor();
    
    oglInstance->drawColor(AColor::redColor());
    SPoint tmpPoint = {location.x + scale, location.y, location.z};
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(AColor::greenColor());
    tmpPoint.x = location.x;
    tmpPoint.y = location.y + scale;
    tmpPoint.z = location.z;
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(AColor::blackColor());
    tmpPoint.x = location.x;
    tmpPoint.y = location.y;
    tmpPoint.z = location.z + scale;
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(color);
}

//==============================================================================

void ADrawBasics::drawGrid(const GLfloat rowsNumber, const GLfloat columnsNumber)
{
    for (GLfloat i = -50.0f; i < 50.0f; i+= 1.0f)
    {
        SPoint p1 = {-50.0f * scale, 0.0f, i * scale};
        SPoint p2 = {50.0f * scale, 0.0f, i * scale};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = -50.0f; i < 50.0f; i+= 1.0f)
    {
        SPoint p1 = {i * scale, 0.0f, -50.0f * scale};
        SPoint p2 = {i * scale, 0.0f, 50.0f * scale};
        ADrawBasics::drawLine(p1, p2);
    }
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

    #define M(row,col)  m[col*4+row]
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
