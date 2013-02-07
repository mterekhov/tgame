#include "AWell.h"
#include "ADrawBasics.h"
#import "AOpenGLState.h"

#include <stdio.h>

//==============================================================================

AWell::AWell(const GLfloat width, const GLfloat height, const GLfloat depth) : ARObject(), wellWidth(width), wellHeight(height), wellDepth(depth), wellCellSize(1.0f)
{
}

//==============================================================================

AWell::AWell() : ARObject(), wellWidth(0.0f), wellHeight(0.0f), wellDepth(0.0f), wellCellSize(1.0f)
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
    AOpenGLState* oglInstance = AOpenGLState::shared();
    
    AColor color = oglInstance->drawColor();
    
    oglInstance->drawColor(AColor::redColor());
    for (GLfloat i = 0.0f; i < wellHeight; i += 1.0f)
    {
        SPoint p1 = {0.0f,                     0.0f, i * wellCellSize};
        SPoint p2 = {wellWidth * wellCellSize, 0.0f, i * wellCellSize};
//        printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = 0.0f; i < wellWidth; i += 1.0f)
    {
        SPoint p1 = {i * wellCellSize, 0.0f, 0.0f};
        SPoint p2 = {i * wellCellSize, 0.0f, wellHeight * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }

    oglInstance->drawColor(color);
}

//==============================================================================

void AWell::renderObject()
{
    renderHull();
    renderContent();
}
