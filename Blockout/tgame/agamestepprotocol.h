#ifndef SPCTGAME_AGAMESTEPPROTOCOL_H
#define SPCTGAME_AGAMESTEPPROTOCOL_H

//==============================================================================
//
//  This class provides common functionality for any event which could happen in game
//
//==============================================================================

namespace spcTGame
{

//==============================================================================

class AGameStepProtocol
{
public:
    virtual void executeStep() = 0;
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AGAMESTEPPROTOCOL_H
