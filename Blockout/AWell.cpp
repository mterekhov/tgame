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
    
    oglInstance->drawColor(AColor::greenColor());
    for (GLfloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
    {
        SPoint p1 = {0.0f,                     0.0f, i * wellCellSize};
        SPoint p2 = {wellWidth * wellCellSize, 0.0f, i * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
    {
        SPoint p1 = {i * wellCellSize, 0.0f, 0.0f};
        SPoint p2 = {i * wellCellSize, 0.0f, wellHeight * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }
    
////////////////////////////////////////////////////////////////////////////////

    for (GLfloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
    {
        SPoint p1 = {0.0f,                     i * wellCellSize, 0.0f};
        SPoint p2 = {wellWidth * wellCellSize, i * wellCellSize, 0.0f};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
    {
        SPoint p1 = {i * wellCellSize, 0.0f,                     0.0f};
        SPoint p2 = {i * wellCellSize, wellDepth * wellCellSize, 0.0f};
        ADrawBasics::drawLine(p1, p2);
    }

////////////////////////////////////////////////////////////////////////////////

    for (GLfloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
    {
        SPoint p1 = {0.0f,                     i * wellCellSize, wellHeight * wellCellSize};
        SPoint p2 = {wellWidth * wellCellSize, i * wellCellSize, wellHeight * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
    {
        SPoint p1 = {i * wellCellSize, 0.0f,                     wellHeight * wellCellSize};
        SPoint p2 = {i * wellCellSize, wellDepth * wellCellSize, wellHeight * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }

////////////////////////////////////////////////////////////////////////////////

    for (GLfloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
    {
        SPoint p1 = {0.0f, i * wellCellSize,                     0.0f};
        SPoint p2 = {0.0f, i * wellCellSize, wellHeight * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
    {
        SPoint p1 = {0.0f, 0.0f,                     i * wellCellSize};
        SPoint p2 = {0.0f, wellDepth * wellCellSize, i * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }

////////////////////////////////////////////////////////////////////////////////

    for (GLfloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
    {
        SPoint p1 = {wellWidth * wellCellSize, i * wellCellSize, 0.0f};
        SPoint p2 = {wellWidth * wellCellSize, i * wellCellSize, wellHeight * wellCellSize};
        ADrawBasics::drawLine(p1, p2);
    }
    
    for (GLfloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
    {
        SPoint p1 = {wellWidth * wellCellSize, 0.0f,                     i * wellCellSize};
        SPoint p2 = {wellWidth * wellCellSize, wellDepth * wellCellSize, i * wellCellSize};
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
