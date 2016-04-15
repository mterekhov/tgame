#ifndef SPCTGAME_ABLOCKMOVEUSEREVENT_H
#define SPCTGAME_ABLOCKMOVEUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "auserevent.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockMoveUserEvent : public AUserEvent
{
private:
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation);

    void moveCurrentBlockDown();
    void moveCurrentBlockUp();
    void moveCurrentBlockLeft();
    void moveCurrentBlockRight();

public:
    ABlockMoveUserEvent(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~ABlockMoveUserEvent();

    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKMOVEUSEREVENT_H
