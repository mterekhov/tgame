#ifndef ENGINE_ACRAFTER_H
#define ENGINE_ACRAFTER_H

//==============================================================================

#include "ATexturedBlock.h"
#include "ASolidBlock.h"
#include "ABlock.h"
#include "ATextureManager.h"

#include <list>

//==============================================================================

typedef std::list<ARObject*> TRObjectsList;
typedef TRObjectsList::iterator TRObjectsListIter;
typedef TRObjectsList::const_iterator TRObjectsListConstIter;

//==============================================================================

class ACrafter
{
private:
    TRObjectsList _texturedRenderList;
    TRObjectsList _solidRenderList;
    
    bool clearList(TRObjectsList& renderList);
    void clearRenderLists();
    void renderList(const TRObjectsList& renderList);
    bool addObjectForRender(ARObject* object);
    
public:
    ATextureManager textureManager;

    ACrafter();
    virtual ~ACrafter();
    
    void processRender();
    
    ATexturedBlock* acCreateTexturedBlock(const AFormation& formation, const ATexture& texture);
    ASolidBlock* acCreateSolidBlock(const AFormation& formation);
    AColoredBlock* acCreateColoredBlock(const AFormation& formation);
};

//==============================================================================

#endif
