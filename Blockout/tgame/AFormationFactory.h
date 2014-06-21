#ifndef SPCTGAME_AFORMATIONFACTORY_H
#define SPCTGAME_AFORMATIONFACTORY_H

//==============================================================================

#include "AFormation.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AFormationFactory
{
public:
    static AFormation createFormation1();
    static AFormation createFormation2();
    static AFormation nullFormation();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONFACTORY_H
