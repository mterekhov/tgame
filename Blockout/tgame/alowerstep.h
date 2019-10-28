#ifndef SPCTGAME_ALOWERSTEP_H
#define SPCTGAME_ALOWERSTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ALowerStep : public AGameStepProtocol
{
public:
    ALowerStep();
    virtual ~ALowerStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ALOWERSTEP_H
