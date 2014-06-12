#ifndef SPCTGAME_ACRAFTER_H
#define SPCTGAME_ACRAFTER_H

//==============================================================================

#include "ATexturedBlock.h"
#include "ASolidBlock.h"
#include "ABlock.h"
#include "ATextureManager.h"
#include "AWell.h"

#include <list>

//==============================================================================

namespace spcTGame
{
    
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
    
    void clearAllLists();
    void clearTextureList();
    void clearRenderList();
    TBool clearList(TRObjectsList& renderList);
    
    void renderList(const TRObjectsList& renderList);
    TBool addObjectForRender(ARObject* object);
    
public:
    ATextureManager textureManager;

    ACrafter();
    virtual ~ACrafter();
    
    void processRender();
    
    AWell* createWell(const TFloat width, const TFloat height, const TFloat depth);
    ATexturedBlock* createTexturedBlock(const AFormation& formation, const ATexture& texture);
    ASolidBlock* createSolidBlock(const AFormation& formation);
    AColoredBlock* createColoredBlock(const AFormation& formation);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif
