#include "acrafter.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"
#include "adrawbasics.h"

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

#pragma mark - create well -

//==============================================================================

AWell* ACrafter::createWell()
{
    AFormation& wellContent = _dataStorage.createFormation(_dataStorage.wellWidth(), _dataStorage.wellHeight(), _dataStorage.wellDepth());
    AWell* well = new AWell(_dataStorage.cellSize(), wellContent);
    addObjectForRender(well);
    
    wellContent.item(0, 2, 7, EDATASTATE_RENDERABLE);
    ATexture& t = textureManager.createTextureFromTGA("/Users/michael/Development/private/blockout/Blockout/resources/celtic.tga");
    addObjectForRender(createTexturedBlock(wellContent, t));
    
    return well;
}

//==============================================================================

#pragma mark - blocks creation -

//==============================================================================

ASolidBlock* ACrafter::createSolidBlock(AFormation& formation)
{
    ASolidBlock* newBlock = new ASolidBlock(formation);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

AColoredBlock* ACrafter::createColoredBlock(AFormation& formation)
{
    AColoredBlock* newBlock = new AColoredBlock(formation);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

ATexturedBlock* ACrafter::createTexturedBlock(AFormation& formation, const ATexture& texture)
{
    ATexturedBlock* newBlock = new ATexturedBlock(formation, texture);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

#pragma mark - render list management -

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

    TRObjectsListConstIter iterBegin = renderList.begin();
    TRObjectsListConstIter iterEnd = renderList.end();
    for (TRObjectsListConstIter iter = iterBegin; iter != iterEnd; iter++)
        delete (*iter);
    
    renderList.clear();
    
    return true;
}

//==============================================================================

TBool ACrafter::addObjectForRender(ARObject* object)
{
    if (object == 0)
        return false;
    
    switch (object->objectType())
    {
        case OBJECTTYPE_SOLID:
            _solidRenderList.push_back(object);
        break;
            
        case OBJECTTYPE_TEXTURED:
            _texturedRenderList.push_back(object);
        break;
        
        default:
            return false;
    }
    
    return true;
}

//==============================================================================

void ACrafter::processKey(const TUint buttonCode)
{
//    ATexture tex = textureManager.createTextureFromTGA("/Users/michael/Development/private/blockout/Blockout/resources/image.tga");
    createColoredBlock(_dataStorage.currentFormation());
}

//==============================================================================

#pragma mark - craft the list -

//==============================================================================

void ACrafter::processRender()
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    oglState->pushMarices();

//    ADrawBasics::installCamera(AVector(6, 5, 7),
//                               AVector(0, 0, 0),
//                               AVector(0.0f, 1.0f, 0.0f));

    TFloat wWidth = _dataStorage.wellWidth();
    TFloat wHeight = _dataStorage.wellHeight();
    TFloat wDepth = _dataStorage.wellDepth();
    ADrawBasics::installCamera(AVector(wHeight / 2.0f, 2.0f * wDepth, wWidth / 2.0f),
                               AVector(wHeight / 2.0f, 0.0f, wWidth / 2.0f),
                               AVector(1.0f, 0.0f, 0.0f));
    
//    ADrawBasics::drawOrigin(APoint(0,0,0), 1.0f);
//    ADrawBasics::drawGrid(50.0f, 50.0f, 1.0f);

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

void ACrafter::renderList(const TRObjectsList& renderList)
{
    if (renderList.size() == 0)
        return;

    TRObjectsListConstIter iterBegin = renderList.begin();
    TRObjectsListConstIter iterEnd = renderList.end();
    for (TRObjectsListConstIter iter = iterBegin; iter != iterEnd; iter++)
        (*iter)->renderObject();
}

//==============================================================================
    
}   //  namespace spcTGame
