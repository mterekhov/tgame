#ifndef SPCTGAME_AKEYEVENT_H
#define SPCTGAME_AKEYEVENT_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AKeyEvent
{
public:
    virtual void processKey(const TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYEVENT_H
