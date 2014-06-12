#include "AWell.h"
#include "ADrawBasics.h"
#import "AOpenGLState.h"

#include <stdio.h>

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AWell::AWell(const TFloat width, const TFloat height, const TFloat depth) : ARObject(), wellWidth(width), wellHeight(height), wellDepth(depth), wellCellSize(1.0f)
{
}

//==============================================================================

AWell::AWell() : ARObject(), wellWidth(0.0f), wellHeight(0.0f), wellDepth(0.0f), wellCellSize(1.0f)
{
}

//==============================================================================

AWell::~AWell()
{
}

//==============================================================================

void AWell::renderContent() const
{
}

//==============================================================================

void AWell::renderHull() const
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    
    AColor color = oglInstance->drawColor();
    
    oglInstance->drawColor(AColor::greenColor());
    for (TFloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, 0.0f, i * wellCellSize), APoint(wellWidth * wellCellSize, 0.0f, i * wellCellSize));

    for (TFloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * wellCellSize, 0.0f, 0.0f), APoint(i * wellCellSize, 0.0f, wellHeight * wellCellSize));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * wellCellSize, 0.0f), APoint(wellWidth * wellCellSize, i * wellCellSize, 0.0f));

    for (TFloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * wellCellSize, 0.0f, 0.0f), APoint(i * wellCellSize, wellDepth * wellCellSize, 0.0f));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * wellCellSize, wellHeight * wellCellSize), APoint(wellWidth * wellCellSize, i * wellCellSize, wellHeight * wellCellSize));

    for (TFloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * wellCellSize, 0.0f, wellHeight * wellCellSize), APoint(i * wellCellSize, wellDepth * wellCellSize, wellHeight * wellCellSize));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * wellCellSize, 0.0f), APoint(0.0f, i * wellCellSize, wellHeight * wellCellSize));

    for (TFloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, 0.0f, i * wellCellSize), APoint(0.0f, wellDepth * wellCellSize, i * wellCellSize));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(wellWidth * wellCellSize, i * wellCellSize, 0.0f), APoint(wellWidth * wellCellSize, i * wellCellSize, wellHeight * wellCellSize));

    for (TFloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(wellWidth * wellCellSize, 0.0f, i * wellCellSize), APoint(wellWidth * wellCellSize, wellDepth * wellCellSize, i * wellCellSize));

    oglInstance->drawColor(color);
}

//==============================================================================

void AWell::renderObject()
{
    renderHull();
    renderContent();
}

//==============================================================================
    
}   //  namespace spcTGame
