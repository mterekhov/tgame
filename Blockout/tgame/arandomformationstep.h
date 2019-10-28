#ifndef SPCTGAME_ARANDOMFORMATIONSTEP_H
#define SPCTGAME_ARANDOMFORMATIONSTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ARandomFormationStep : public AGameStepProtocol
{
public:
    ARandomFormationStep();
    virtual ~ARandomFormationStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ARANDOMFORMATIONSTEP_H
