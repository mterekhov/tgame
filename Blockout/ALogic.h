#ifndef ENGINE_ALOGIC_H
#define ENGINE_ALOGIC_H

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
