#ifndef ENGINE_AFORMATIONFACTORY_H
#define ENGINE_AFORMATIONFACTORY_H

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
    static AFormation nullFormation();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif
