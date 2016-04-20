#ifndef SPCTGAME_ABLOCKDROPGAMESTEP_H
#define SPCTGAME_ABLOCKDROPGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockDropGameStep : public AGameStepProtocol
{
private:
    APoint findDropPosition(AFormation* formation);
    
public:
    ABlockDropGameStep();
    virtual ~ABlockDropGameStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKDROPGAMESTEP_H
