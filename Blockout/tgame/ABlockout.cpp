#include <stdio.h>
#include <time.h>

#include "ablockout.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "awell.h"
#include "atexturedblock.h"
#include "asolidblock.h"
#include "aformationfactory.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ABlockout::ABlockout() : _crafter(_dataStorage), _logic(_dataStorage)
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
    //  call shared to create instance and init some OpenGL pars;
    spcTGame::AOpenGLState::create();

    ATexture tex = _crafter.textureManager.createTextureFromTGA("/Users/michael/Development/private/blockout/Blockout/resources/image.tga");
    _crafter.createTexturedBlock(_dataStorage.currentFormation(), tex);
    _crafter.createWell();
    
    _keyboardEvents.addDelegate(_logic);
}

//==============================================================================

void ABlockout::render()
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    oglState->pushMarices();

    ADrawBasics::installCamera(AVector(4, 5, 7),
                               AVector(0, 0, 0),
                               AVector(0.0f, 1.0f, 0.0f));
    
//    ADrawBasics::installCamera(AVector(_wellWidth / 2.0f, 2.0f * _wellDepth, _wellHeight / 2.0f),
//                               AVector(_wellWidth / 2.0f, 0.0f, _wellHeight / 2.0f),
//                               AVector(1.0f, 0.0f, 0.0f));
//    ADrawBasics::drawOrigin(APoint(0,0,0), 1.0f);
//    ADrawBasics::drawGrid(50.0f, 50.0f, 1.0f);

    _crafter.processRender();

    oglState->popMarices();
}

//==============================================================================

void ABlockout::processGameCycle()
{
    _logic.processLogic();
    render();
}

//==============================================================================
    
void ABlockout::processKeyboardEvent(const TUint buttonCode)
{
    _keyboardEvents.keyPressed(buttonCode);
}

//==============================================================================

void ABlockout::updateScreenSize(const TDouble screenWidth, const TDouble screenHeight)
{
    AOpenGLState* oglState = spcTGame::AOpenGLState::shared();
    oglState->frustumSetup(screenWidth, screenHeight);
}

//==============================================================================
    
}   //  namespace spcTGame
