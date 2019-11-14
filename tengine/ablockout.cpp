#include "ablockout.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "awell.h"
#include "atexturedblock.h"
#include "aformationfactory.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ABlockout::ABlockout() : _crafter(_dataStorage), _logic(_stepsController), _keyboardController(_stepsController)
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
}

//==============================================================================

void ABlockout::startGame()
{
    //  creates all the formations we need
    _logic.startGame();
}

//==============================================================================

void ABlockout::processGameCycle()
{
	_logic.processLogic();
	_stepsController.processSteps(_dataStorage);
	_crafter.refreshRenderLists();
	_crafter.processRender();
}

//==============================================================================
    
void ABlockout::processKeyboardEvent(const TUint buttonCode)
{
    _keyboardController.keyPressed(buttonCode);
}

//==============================================================================

void ABlockout::updateScreenSize(const TDouble screenWidth, const TDouble screenHeight)
{
    AOpenGLState* oglState = spcTGame::AOpenGLState::shared();
    oglState->frustumSetup(screenWidth, screenHeight);
}

//==============================================================================
    
}   //  namespace spcTGame
