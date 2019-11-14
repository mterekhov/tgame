#ifndef SPCTGAME_ACRAFTER_H
#define SPCTGAME_ACRAFTER_H

//==============================================================================
//
//  The main purpose of this class is to render everything we need and keep it in memory
//
//==============================================================================

#include <list>

#include "atexturedblock.h"
#include "atexturemanager.h"
#include "awell.h"
#include "adatastorage.h"
#include "arenderobject.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

typedef std::list<ARenderObject> TRenderObjectsList;
typedef TRenderObjectsList::iterator TRenderObjectsListIter;
typedef TRenderObjectsList::const_iterator TRenderObjectsListConstIter;

class AWell;

//==============================================================================

class ACrafter
{
private:
    ATextureManager _textureManager;
    ADataStorage& _dataStorage;
    TRenderObjectsList _texturedObjectsList;
    TRenderObjectsList _coloredObjectsList;

    void generateTexturedRenderList(const TFormationsList& formations, ATexture& texture);
    
    void renewRenderLists();
    void clearAllLists();
    void createWell();

    void renderContent();
    void renderColoredObjects();
    void renderTexturedObjects();


	void createColoredBlock(const AFormation& formation, const AColor& color);
	void createTexturedBlock(const AFormation& formation, ATexture& texture);
    void createDroppedBlocks();
    
public:
    ACrafter(ADataStorage& dataStorage);
    virtual ~ACrafter();

    void refreshRenderLists();
    void processRender();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ACRAFTER_H
