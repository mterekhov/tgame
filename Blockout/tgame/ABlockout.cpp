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

    _crafter.createWell();
    
    _keyboardEvents.addDelegate(_logic);
    _keyboardEvents.addDelegate(_crafter);
}

//==============================================================================

void ABlockout::startGame()
{
    _logic.startGame();

    ATexture tex = _crafter.textureManager.createTextureFromTGA("/Users/michael/Development/private/blockout/Blockout/resources/image.tga");
    _crafter.createTexturedBlock(_dataStorage.currentFormation(), tex);
}

//==============================================================================

void ABlockout::processGameCycle()
{
    _logic.processLogic();
    _crafter.processRender();
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
