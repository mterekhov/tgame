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
    void makeDrop(ACrafter &crafter, ADataStorage &dataStorage);
    APoint findDropPosition(AFormation* formation);

public:
    ABlockDropUserEvent();
    virtual ~ABlockDropUserEvent();

    virtual void processEvent(ACrafter &crafter, ADataStorage &dataStorage);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKDROPUSEREVENT_H
