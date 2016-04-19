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
    TUint _buttonCode;
    
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage);

    void moveCurrentBlockDown(ADataStorage &dataStorage);
    void moveCurrentBlockUp(ADataStorage &dataStorage);
    void moveCurrentBlockLeft(ADataStorage &dataStorage);
    void moveCurrentBlockRight(ADataStorage &dataStorage);

public:
    ABlockMoveUserEvent(const TUint buttonCode);
    virtual ~ABlockMoveUserEvent();

    virtual void processEvent(ACrafter &crafter, ADataStorage &dataStorage);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKMOVEUSEREVENT_H
