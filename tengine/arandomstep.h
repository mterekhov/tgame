#ifndef SPCTGAME_ARANDOMSTEP_H
#define SPCTGAME_ARANDOMSTEP_H

//==============================================================================

#include "astepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ARandomStep : public AStepProtocol
{
public:
    ARandomStep();
    virtual ~ARandomStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ARANDOMSTEP_H
