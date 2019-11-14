#ifndef SPCTGAME_ALOWERSTEP_H
#define SPCTGAME_ALOWERSTEP_H

//==============================================================================

#include "astepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ALowerStep : public AStepProtocol
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
