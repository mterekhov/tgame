#ifndef SPCTGAME_ADROPDOWNBLOCKGAMESTEP_H
#define SPCTGAME_ADROPDOWNBLOCKGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ADropDwnBlockGameStep : public AGameStepProtocol
{
public:
    virtual void executeStep();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADROPDOWNBLOCKGAMESTEP_H
