#include "AWell.h"
#include "ADrawBasics.h"

//==============================================================================

AWell::AWell(const GLfloat width, const GLfloat height, const GLfloat depth) : ARObject(), wellWidth(width), wellHeight(height), wellDepth(depth), wellCellSize(0.0f)
{
}

//==============================================================================

AWell::AWell() : ARObject(), wellWidth(0.0f), wellHeight(0.0f), wellDepth(0.0f), wellCellSize(0.0f)
{
}

//==============================================================================

AWell::~AWell()
{
    ARObject::~ARObject();
}

//==============================================================================

void AWell::renderContent()
{
}

//==============================================================================

void AWell::renderHull()
{
    for (GLfloat i = 0.0f; i < wellHeight; i += 1.0f)
    {
        SPoint p1 = {0.0f,                     0.0f, i * wellCellSize};
        SPoint p2 = {wellWidth * wellCellSize, 0.0f, i * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = 0.0f; i < wellWidth; i += 1.0f)
    {
        SPoint p1 = {i * wellCellSize, 0.0f, 0.0f};
        SPoint p2 = {i * wellCellSize, 0.0f, wellHeight * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }
}

//==============================================================================

void AWell::renderObject()
{
    renderHull();
    renderContent();
}
