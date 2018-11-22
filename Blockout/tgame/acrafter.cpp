#include "acrafter.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"
#include "adrawbasics.h"
#include "abundle.h"
#include "awell.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
#pragma mark - init -

//==============================================================================

ACrafter::ACrafter(ADataStorage& dataStorage): _dataStorage(dataStorage)
{
}

//==============================================================================

ACrafter::~ACrafter()
{
    clearAllLists();
}

//==============================================================================

#pragma mark - Game events -

//==============================================================================

void ACrafter::refreshRenderLists()
{
    renewRenderLists();
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

void ACrafter::renewRenderLists()
{
    clearAllLists();
    
    //  create well and add it to render cycle
    createWell();
    
    //  create current block and add it to render cycle
    createColoredBlock(_dataStorage.currentFormation(), AColor::blueColor());
    
    //  create render list for all dropped blocks
    createDroppedBlocks();
}

//==============================================================================

void ACrafter::createDroppedBlocks()
{
    const TFormationsList& droppedFormations = _dataStorage.droppedFormationsList();
    for (TFormationsListConstIter iter = droppedFormations.begin(); iter != droppedFormations.end(); iter++)
    {
        TString textureFileName = "MARBFAC3.tga";
        textureFileName = ABundle().fullPathToResource(textureFileName);
        createTexturedBlock(*iter, _textureManager.createTextureFromTGA(textureFileName));
    }
}

//==============================================================================

#pragma mark - create well -

//==============================================================================

void ACrafter::createWell()
{
	ARenderInterface *newWell = ARenderObject::createWell(_dataStorage.wellFormation(), _dataStorage.cellSize(), AColor::greenColor());
	ARenderObject wellRenderObject = ARenderObject(newWell);
	_coloredObjectsList.push_back(wellRenderObject);
}

//==============================================================================

void ACrafter::createColoredBlock(const AFormation& formation, const AColor& color)
{
	ARenderInterface *newColoredBlock = ARenderObject::createColoredBlock(formation, _dataStorage.cellSize(), color, ERenderStyle::RENDERSTYLE_CARCAS);
	ARenderObject newRenderObject = ARenderObject(newColoredBlock);
	_coloredObjectsList.push_back(newRenderObject);
}

//==============================================================================

void ACrafter::createTexturedBlock(const AFormation& formation, ATexture& texture)
{
	ARenderInterface *newTexturedBlock = ARenderObject::createTexturedBlock(formation, _dataStorage.cellSize(), texture);
	ARenderObject newRenderObject = ARenderObject(newTexturedBlock);
	_texturedObjectsList.push_back(newRenderObject);
}

//==============================================================================

void ACrafter::generateTexturedRenderList(const TFormationsList& formations, ATexture& texture)
{
    for (TFormationsListConstIter iter = formations.begin(); iter != formations.end(); iter++)
    {
        createTexturedBlock((*iter), texture);
    }
}

//==============================================================================

void ACrafter::clearAllLists()
{
    if (_texturedObjectsList.size() != 0)
    {
	    _texturedObjectsList.clear();
	}
	
    if (_coloredObjectsList.size() != 0)
    {
	    _coloredObjectsList.clear();
	}
}

//==============================================================================

#pragma mark - craft the list -

//==============================================================================

void ACrafter::processRender()
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    oglState->pushMarices();

    TFloat wWidth = _dataStorage.wellWidth();
    TFloat wHeight = _dataStorage.wellHeight();
    TFloat wDepth = _dataStorage.wellDepth();
    ADrawBasics::installCamera(AVector(wHeight / 2.0f, 2.0f * wDepth, wWidth / 2.0f),
                               AVector(wHeight / 2.0f, 0.0f, wWidth / 2.0f),
                               AVector(1.0f, 0.0f, 0.0f));

    renderContent();

    oglState->popMarices();
}

//==============================================================================

void ACrafter::renderContent()
{
    AOpenGLState* oglState = AOpenGLState::shared();

    //  Draw solid list
    AColor previousColor = oglState->drawColor();
    renderColoredObjects();
    oglState->drawColor(previousColor);

    //  Draw textured objects
    previousColor = oglState->drawColor();
    oglState->drawColor(AColor::whiteColor());
    oglState->textureEnable();
    renderTexturedObjects();
    oglState->textureDisable();
    oglState->drawColor(previousColor);
}

//==============================================================================

void ACrafter::renderColoredObjects()
{
    if (_coloredObjectsList.size() == 0)
        return;

    TRenderObjectsListIter iterBegin = _coloredObjectsList.begin();
    TRenderObjectsListIter iterEnd = _coloredObjectsList.end();
    for (TRenderObjectsListIter iter = iterBegin; iter != iterEnd; iter++)
    {
    	const ARenderObject& object = *iter;
        object.render();
	}
}

//==============================================================================
	
void ACrafter::renderTexturedObjects()
{
    if (_coloredObjectsList.size() == 0)
        return;

    TRenderObjectsListIter iterBegin = _texturedObjectsList.begin();
    TRenderObjectsListIter iterEnd = _texturedObjectsList.end();
    for (TRenderObjectsListIter iter = iterBegin; iter != iterEnd; iter++)
    {
        iter->render();
	}
}

//==============================================================================
	
}   //  namespace spcTGame
