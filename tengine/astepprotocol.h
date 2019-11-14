#ifndef SPCTGAME_ASTEPPROTOCOL_H
#define SPCTGAME_ASTEPPROTOCOL_H

//==============================================================================
//
//  This class provides common functionality for any event which could happen in game
//
//==============================================================================

#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AStepProtocol
{
public:
    virtual void executeStep(ADataStorage &dataStorage) = 0;
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ASTEPPROTOCOL_H
