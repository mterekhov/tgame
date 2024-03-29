#include "ACrafter.h"
#include "AWell.h"

//==============================================================================

#pragma mark - init -

//==============================================================================

ACrafter::ACrafter()
{
    createWell();
}

//==============================================================================

ACrafter::~ACrafter()
{
    clearRenderList();
}

//==============================================================================

void ACrafter::createWell()
{
    AWell* well = new AWell(10.0f, 10.0f, 25.0f);
    addObjectForRender(well);
}

//==============================================================================

#pragma mark - render list management -

//==============================================================================

void ACrafter::clearRenderList()
{
    if (!_renderList.size())
        return;
    
    TRObjectsListIter iterBegin = _renderList.begin();
    TRObjectsListIter iterEnd = _renderList.end();
    for (TRObjectsListIter iter = iterBegin; iter != iterEnd; iter++)
        delete (*iter);
}

//==============================================================================

void ACrafter::addObjectForRender(ARObject* object)
{
    if (!object)
        return;
    
    _renderList.push_back(object);
}

//==============================================================================

#pragma mark - craft the list -

//==============================================================================

void ACrafter::craft()
{
    TRObjectsListIter iterBegin = _renderList.begin();
    TRObjectsListIter iterEnd = _renderList.end();
    for (TRObjectsListIter iter = iterBegin; iter != iterEnd; iter++)
        (*iter)->renderObject();
}
