#include "ACrafter.h"
#include "AOpenGLState.h"
#include "BlockoutDebug.h"

//==============================================================================

#pragma mark - init -

//==============================================================================

ACrafter::ACrafter()
{
}

//==============================================================================

ACrafter::~ACrafter()
{
    clearRenderLists();
}

//==============================================================================

#pragma mark - render list management -

//==============================================================================

void ACrafter::clearRenderLists()
{
    if (!clearList(_solidRenderList))
        loger("failed to clear solid objects list");

    if (!clearList(_texturedRenderList))
        loger("failed to clear textured objects list");
}

//==============================================================================

bool ACrafter::clearList(TRObjectsList& renderList)
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

bool ACrafter::addObjectForRender(ARObject* object)
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
    }
    
    return true;
}

//==============================================================================

#pragma mark - craft the list -

//==============================================================================

void ACrafter::processRender()
{
    AOpenGLState* oglState = AOpenGLState::shared();

    //  Draw solid list
    AColor previousColor = oglState->drawColor();
    TRObjectsList listToRender = _solidRenderList;
    renderList(listToRender);
    oglState->drawColor(previousColor);

    //  Draw textured objects
    oglState->textureEnable();
    listToRender = _texturedRenderList;
    renderList(listToRender);
    oglState->textureDisable();
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
