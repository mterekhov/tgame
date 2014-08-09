#ifndef SPCTGAME_ACRAFTER_H
#define SPCTGAME_ACRAFTER_H

//==============================================================================
//
//  The main purpose of this class is to render everything we need and keep it in memory
//
//==============================================================================

#include <list>

#include "atexturedblock.h"
#include "asolidblock.h"
#include "ablock.h"
#include "atexturemanager.h"
#include "awell.h"
#include "adatastorage.h"
#include "akeyevent.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

typedef std::list<ARObject*> TRObjectsList;
typedef TRObjectsList::iterator TRObjectsListIter;
typedef TRObjectsList::const_iterator TRObjectsListConstIter;

//==============================================================================

class ACrafter : public AKeyEvent
{
private:
    ADataStorage& _dataStorage;

    TRObjectsList _texturedRenderList;
    TRObjectsList _solidRenderList;
    
    void clearAllLists();
    void clearTextureList();
    void clearRenderList();
    TBool clearList(TRObjectsList& renderList);
    
    void renderContent();
    void renderList(const TRObjectsList& renderList);
    TBool addObjectForRender(ARObject* object);
    
public:
    ATextureManager textureManager;

    ACrafter(ADataStorage& dataStorage);
    virtual ~ACrafter();

    virtual void processKey(const TUint buttonCode);

    void processRender();
    
    AWell* createWell();
    ATexturedBlock* createTexturedBlock(AFormation* formation, const ATexture& texture);
    ASolidBlock* createSolidBlock(AFormation* formation);
    AColoredBlock* createColoredBlock(AFormation* formation);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ACRAFTER_H
