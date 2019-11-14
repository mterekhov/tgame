#ifndef SPCTGAME_ADROPSTEP_H
#define SPCTGAME_ADROPSTEP_H

//==============================================================================

#include "astepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ADropStep : public AStepProtocol
{
private:
    APoint findDropPosition(const AFormation& formation);
    
public:
    ADropStep();
    virtual ~ADropStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADROPSTEP_H
