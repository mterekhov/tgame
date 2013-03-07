#ifndef __Blockout__ALogic__
#define __Blockout__ALogic__

//==============================================================================

#include "AFormation.h"
#include "APoint.h"

//==============================================================================

class ALogic
{
public:
    ALogic();
    ~ALogic();
    
    bool collisions(const AFormation* forCompare, const APoint& pos);
    
    void processLogic();
};

//==============================================================================

#endif
