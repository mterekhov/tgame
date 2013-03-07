#ifndef __Blockout__ACrafter__
#define __Blockout__ACrafter__

//==============================================================================

#include "ARObject.h"

#include <list>

//==============================================================================

typedef std::list<ARObject*> TRObjectsList;
typedef TRObjectsList::iterator TRObjectsListIter;
typedef TRObjectsList::const_iterator TRObjectsListConstIter;

//==============================================================================

class ACrafter
{
private:
    TRObjectsList _renderList;
    
    void clearRenderList();
    
public:
    ACrafter();
    virtual ~ACrafter();
    
    void addObjectForRender(ARObject* object);

    void processRender();
};

//==============================================================================

#endif
