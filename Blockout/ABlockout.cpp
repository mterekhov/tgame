#include "ABlockout.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"
#include "AWell.h"
#include "ABlockFactory.h"

#include <stdio.h>
#include <time.h>

//==============================================================================

ABlockout::ABlockout() : _wellWidth(3.0f), _wellHeight(3.0f), _wellDepth(9.0f)
{
    init();
}

//==============================================================================

ABlockout::~ABlockout()
{
}

//==============================================================================

void ABlockout::init()
{
    ABlock* block = ABlockFactory::createFormation1();
    _crafter.addObjectForRender(block);
    
    AWell* well = new AWell(_wellWidth, _wellHeight, _wellDepth);
    _crafter.addObjectForRender(well);
}

//==============================================================================

void ABlockout::render()
{
    AOpenGLState* oglState = AOpenGLState::shared();

    oglState->pushMarices();

    ADrawBasics::installCamera(AVector(4, -3, 7),
                               AVector(0,0,0),
                               AVector(0.0f, 1.0f, 0.0f));
//    ADrawBasics::installCamera(AVector(_wellWidth / 2.0f, 2.0f * _wellDepth, _wellHeight / 2.0f),
//                               AVector(_wellWidth / 2.0f, 0.0f, _wellHeight / 2.0f),
//                               AVector(1.0f, 0.0f, 0.0f));
//    ADrawBasics::drawOrigin(originPoint, 1.0f);
//    ADrawBasics::drawGrid(50.0f, 50.0f, 1.0f);

//    _crafter.craft();
    glColor4f(1, 0, 0, 1);
    ADrawBasics::drawSolidCube(APoint(0.0f, 0.0f, 0.0f), 1.0f);
    
    oglState->popMarices();
}
