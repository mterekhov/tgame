#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "aformation.h"
#include "apoint.h"
#include "akeyevent.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ALogic : public AKeyEvent
{
public:
    ALogic();
    virtual ~ALogic();
    
    TBool collisions(const AFormation* forCompare, const APoint& pos);
    virtual void processKey(const TUint buttonCode);
    
    void processLogic();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ALOGIC_H
