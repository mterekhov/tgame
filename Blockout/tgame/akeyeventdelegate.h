#ifndef SPCTGAME_AKEYEVENTDELEGATE_H
#define SPCTGAME_AKEYEVENTDELEGATE_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AKeyEventDelegate
{
public:
    virtual void processKey(const TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYEVENTDELEGATE_H
