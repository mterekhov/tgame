#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "AFormation.h"
#include "APoint.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ALogic
{
public:
    ALogic();
    ~ALogic();
    
    TBool collisions(const AFormation* forCompare, const APoint& pos);
    
    void processLogic();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif
