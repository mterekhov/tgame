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
    clearList(_solidRenderList);
    clearList(_texturedRenderList);
}

//==============================================================================

void ACrafter::clearList(TRObjectsList& renderList)
{
    if (renderList.size() == 0)
    {
        loger("failed to clear empty list");
        return;
    }
    
    TRObjectsListConstIter iterBegin = renderList.begin();
    TRObjectsListConstIter iterEnd = renderList.end();
    for (TRObjectsListConstIter iter = iterBegin; iter != iterEnd; iter++)
        delete (*iter);
    
    renderList.clear();
}

//==============================================================================

void ACrafter::addObjectForRender(ARObject* object)
{
    if (object == 0)
    {
        loger("failed to add render object because it is empty");
        return;
    }
    
    loger("testing %s log out", "<with in>");
    
    switch (object->objectType())
    {
        case OBJECTTYPE_SOLID:
            _solidRenderList.push_back(object);
        break;
            
        case OBJECTTYPE_TEXTURED:
            _texturedRenderList.push_back(object);
        break;
    }
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
    {
        loger("render list is empty");
        return;
    }
    
    TRObjectsListConstIter iterBegin = renderList.begin();
    TRObjectsListConstIter iterEnd = renderList.end();
    for (TRObjectsListConstIter iter = iterBegin; iter != iterEnd; iter++)
        (*iter)->renderObject();
}
