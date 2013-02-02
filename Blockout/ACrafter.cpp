#include "ACrafter.h"
#include "ADrawBasics.h"

//==============================================================================

ACrafter::ACrafter()
{
}

//==============================================================================

ACrafter::~ACrafter()
{
}

//==============================================================================

void drawWell()
{
    GLfloat width = 10.0f;
    GLfloat height = 10.0f;
    GLfloat depth = 30.0f;
    GLfloat cellSize = 1.0f;
    
    for (GLfloat j = 0.0f; j < height; j += 1.0f)
    {
        SPoint p1 = {0.0f,             -depth, j * cellSize};
        SPoint p2 = {width * cellSize, -depth, j * cellSize};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat j = 0.0f; j < width; j += 1.0f)
    {
        SPoint p1 = {j * cellSize, -depth, 0.0f};
        SPoint p2 = {j * cellSize, -depth, width * cellSize};
        ADrawBasics::drawLine(p1, p2);
    }
}

//==============================================================================

void ACrafter::craft()
{
    drawWell();
}
