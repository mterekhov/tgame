#include <stdio.h>

#include "awell.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "adatastorage.h"
#include "blockoutdebug.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AWell::AWell(const TFloat cellSize, AFormation& content) : ARObject(), wellWidth(content.width()), wellHeight(content.height()), wellDepth(content.levelsCount()), wellCellSize(cellSize), _content(content)
{
}

//==============================================================================

AWell::AWell() : ARObject(), wellWidth(0.0f), wellHeight(0.0f), wellDepth(0.0f), wellCellSize(1.0f), _content(AFormationFactory::nullFormation())
{
}

//==============================================================================

AWell::~AWell()
{
}

//==============================================================================

void AWell::renderHull() const
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    
    AColor color = oglInstance->drawColor();
    
    oglInstance->drawColor(AColor::greenColor());
    for (TFloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, 0.0f, i * wellCellSize), APoint(wellHeight * wellCellSize, 0.0f, i * wellCellSize));

    for (TFloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * wellCellSize, 0.0f, 0.0f), APoint(i * wellCellSize, 0.0f, wellWidth * wellCellSize));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * wellCellSize, 0.0f), APoint(wellHeight * wellCellSize, i * wellCellSize, 0.0f));

    for (TFloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * wellCellSize, 0.0f, 0.0f), APoint(i * wellCellSize, wellDepth * wellCellSize, 0.0f));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * wellCellSize, wellWidth * wellCellSize), APoint(wellHeight * wellCellSize, i * wellCellSize, wellWidth * wellCellSize));

    for (TFloat i = 0.0f; i < wellHeight + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * wellCellSize, 0.0f, wellWidth * wellCellSize), APoint(i * wellCellSize, wellDepth * wellCellSize, wellWidth * wellCellSize));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * wellCellSize, 0.0f), APoint(0.0f, i * wellCellSize, wellWidth * wellCellSize));

    for (TFloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, 0.0f, i * wellCellSize), APoint(0.0f, wellDepth * wellCellSize, i * wellCellSize));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < wellDepth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(wellHeight * wellCellSize, i * wellCellSize, 0.0f), APoint(wellHeight * wellCellSize, i * wellCellSize, wellWidth * wellCellSize));

    for (TFloat i = 0.0f; i < wellWidth + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(wellHeight * wellCellSize, 0.0f, i * wellCellSize), APoint(wellHeight * wellCellSize, wellDepth * wellCellSize, i * wellCellSize));

    oglInstance->drawColor(color);
}

//==============================================================================

void AWell::renderObject()
{
    renderHull();
}

//==============================================================================
    
}   //  namespace spcTGame
