#ifndef SPCTGAME_ABLOCKMOVEEVENTPROCESSOR_H
#define SPCTGAME_ABLOCKMOVEEVENTPROCESSOR_H

//==============================================================================

#include "blockouttypes.h"
#include "agameeventdelegate.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

enum EMoveDirection
{
    EMOVE_DIRECTION_LEFT,
    EMOVE_DIRECTION_UP,
    EMOVE_DIRECTION_DOWN,
    EMOVE_DIRECTION_RIGHT
};

//==============================================================================

class ABlockMoveEventProcessor : public AGameEventDelegate
{
private:
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation);

    void moveCurrentBlockDown();
    void moveCurrentBlockUp();
    void moveCurrentBlockLeft();
    void moveCurrentBlockRight();

public:
    ABlockMoveEventProcessor(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~ABlockMoveEventProcessor();

    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKMOVEEVENTPROCESSOR_H
