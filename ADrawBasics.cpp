#include "ADrawBasics.h"

//==============================================================================

const GLfloat ADrawBasics::scale = 1.0f;

//==============================================================================

ADrawBasics* ADrawBasics::_basics;

//==============================================================================

ADrawBasics& ADrawBasics::instance()
{
    if (_basics == 0)
    {
        _basics = new ADrawBasics();
    }
    
    return *_basics;
}

//==============================================================================

ADrawBasics::ADrawBasics()
{
}

//==============================================================================

ADrawBasics::~ADrawBasics()
{
}

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
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, line);
    glDrawArrays(GL_LINES, 0, 6);
}

//==============================================================================

void ADrawBasics::drawOrigin(const SPoint& location)
{
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    SPoint tmpPoint = {location.x + scale, location.y, location.z};
    drawLine(location, tmpPoint);
    
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    tmpPoint.x = location.x;
    tmpPoint.y = location.y + scale;
    tmpPoint.z = location.z;
    drawLine(location, tmpPoint);
    
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    tmpPoint.x = location.x;
    tmpPoint.y = location.y;
    tmpPoint.z = location.z + scale;
    drawLine(location, tmpPoint);
    
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
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
