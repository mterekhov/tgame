#ifndef SPCTGAME_AFORMATIONFACTORY_H
#define SPCTGAME_AFORMATIONFACTORY_H

//==============================================================================
//
//  This class is just creating formations and not storing it
//
//==============================================================================

#include "aformation.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AFormationFactory
{
private:
    static AFormation _nullFormation;
    
public:
    static AFormation createFormation1();
    static AFormation createFormation2();
    static AFormation& nullFormation();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONFACTORY_H
