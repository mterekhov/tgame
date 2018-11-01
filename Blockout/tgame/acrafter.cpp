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
    createColoredBlock(_dataStorage.currentFormation());
    
    //  create render list for all dropped blocks
    createDroppedBlocks();
}

//==============================================================================

void ACrafter::createDroppedBlocks()
{
    const TFormationList& droppedFormations = _dataStorage.droppedFormationsList();
    for (TFormationListConstIter iter = droppedFormations.begin(); iter != droppedFormations.end(); iter++)
    {
        TString textureFileName = "celtic.tga";
        textureFileName = ABundle().fullPathToResource(textureFileName);
        createTexturedBlock(*iter, _textureManager.createTextureFromTGA(textureFileName));
    }
}

//==============================================================================

#pragma mark - create well -

//==============================================================================

AWell& ACrafter::createWell()
{
    AWell well(_dataStorage.wellFormation());
    return static_cast<AWell&>(addObjectForRender(well));
}

//==============================================================================

#pragma mark - blocks creation -

//==============================================================================

ASolidBlock& ACrafter::createSolidBlock(const AFormation& formation)
{
    ASolidBlock newBlock(formation);
    return static_cast<ASolidBlock&>(addObjectForRender(newBlock));
}

//==============================================================================

AColoredBlock& ACrafter::createColoredBlock(const AFormation& formation)
{
    AColoredBlock newBlock(formation);
    return static_cast<AColoredBlock&>(addObjectForRender(newBlock));
}

//==============================================================================

ATexturedBlock& ACrafter::createTexturedBlock(const AFormation& formation, ATexture& texture)
{
    ATexturedBlock newBlock(formation, texture);
    return static_cast<ATexturedBlock&>(addObjectForRender(newBlock));
}

//==============================================================================

#pragma mark - render list management -

//==============================================================================

void ACrafter::generateTexturedRenderList(const TFormationList& formations, ATexture& texture)
{
    for (TFormationListConstIter iter = formations.begin(); iter != formations.end(); iter++)
    {
        createTexturedBlock((*iter), texture);
    }
}

//==============================================================================

void ACrafter::clearAllLists()
{
    clearRenderList();
    clearTextureList();
}

//==============================================================================

void ACrafter::clearRenderList()
{
    if (!clearList(_solidRenderList))
    {
        loger("failed to clear solid objects list");
    }
}

//==============================================================================

void ACrafter::clearTextureList()
{
    if (!clearList(_texturedRenderList))
    {
        loger("failed to clear textured objects list");
    }
}

//==============================================================================

TBool ACrafter::clearList(TRObjectsList& renderList)
{
    if (renderList.size() == 0)
        return false;

    renderList.clear();
    
    return true;
}

//==============================================================================

ARObject& ACrafter::addObjectForRender(const ARObject& object)
{
    switch (object.objectType())
    {
        case OBJECTTYPE_SOLID:
            _solidRenderList.push_back(object);
			return _solidRenderList.back();
        break;
            
        case OBJECTTYPE_TEXTURED:
            _texturedRenderList.push_back(object);
			return _texturedRenderList.back();
        break;
        
        default:
			return _solidRenderList.back();
    }
    
	return _solidRenderList.back();
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
    TRObjectsList listToRender = _solidRenderList;
    renderList(listToRender);
    oglState->drawColor(previousColor);

    //  Draw textured objects
    previousColor = oglState->drawColor();
    oglState->drawColor(AColor::whiteColor());
    oglState->textureEnable();
    listToRender = _texturedRenderList;
    renderList(listToRender);
    oglState->textureDisable();
    oglState->drawColor(previousColor);
}

//==============================================================================

void ACrafter::renderList(TRObjectsList& renderList)
{
    if (renderList.size() == 0)
        return;

    TRObjectsListIter iterBegin = renderList.begin();
    TRObjectsListIter iterEnd = renderList.end();
    for (TRObjectsListIter iter = iterBegin; iter != iterEnd; iter++)
        (*iter).renderObject();
}

//==============================================================================
    
}   //  namespace spcTGame
