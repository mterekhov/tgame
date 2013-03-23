#include "ABlockout.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"
#include "AWell.h"
#include "ATexturedBlock.h"
#include "AFormationFactory.h"
#include "atga.h"

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
    ATexture tex("/Users/admin/Documents/blockout/Blockout/resources/celtic.tga");
    ATexturedBlock block(AFormationFactory::createFormation1(), tex);
    _crafter.addObjectForRender(block);
    
    AWell well(_wellWidth, _wellHeight, _wellDepth);
    _crafter.addObjectForRender(well);
}

//==============================================================================

void ABlockout::render()
{
    AOpenGLState* oglState = AOpenGLState::shared();

    oglState->pushMarices();

    ADrawBasics::installCamera(AVector(4, 3, 7),
                               AVector(0, 0, 0),
                               AVector(0.0f, 1.0f, 0.0f));
    
//    ADrawBasics::installCamera(AVector(_wellWidth / 2.0f, 2.0f * _wellDepth, _wellHeight / 2.0f),
//                               AVector(_wellWidth / 2.0f, 0.0f, _wellHeight / 2.0f),
//                               AVector(1.0f, 0.0f, 0.0f));
//    ADrawBasics::drawOrigin(APoint(0,0,0), 1.0f);
//    ADrawBasics::drawGrid(50.0f, 50.0f, 1.0f);

//    _crafter.processRender();

    oglState->textureEnable();
    ATexture tex;
    tex.atInit("/Users/admin/Documents/blockout/Blockout/resources/celtic.tga");
    oglState->currentTexture(tex);
//    tex.atInit("/Volumes/development/source/blockout/blockout/Blockout/resources/celtic.tga");
    ADrawBasics::drawTexturedCube(APoint(0.0f, 0.0f, 0.0f), 1.0f, tex);
    oglState->textureDisable();

//    oglState->drawColor(AColor::redColor());
//    ADrawBasics::drawCarcasedCube(APoint(0, 0, 0), 1);
    
    oglState->popMarices();
}

//==============================================================================

void ABlockout::processGameCycle()
{
    _logic.processLogic();
    render();
}
