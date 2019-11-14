#ifndef SPCTGAME_ANEWWELLSTEP_H
#define SPCTGAME_ANEWWELLSTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ANewWellStep : public AGameStepProtocol
{
private:
    APoint findDropPosition(AFormation* formation);
    
public:
    ANewWellStep();
    virtual ~ANewWellStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ANEWWELLSTEP_H
