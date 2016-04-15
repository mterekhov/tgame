#ifndef SPCTGAME_ABLOCKDROPUSEREVENT_H
#define SPCTGAME_ABLOCKDROPUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "auserevent.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockDropUserEvent : public AUserEvent
{
private:
    void makeDrop();
    APoint findDropPosition(AFormation* formation);

public:
    ABlockDropUserEvent(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~ABlockDropUserEvent();

    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKDROPUSEREVENT_H
