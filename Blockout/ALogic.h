#ifndef __Blockout__ALogic__
#define __Blockout__ALogic__

//==============================================================================

#include "AFormation.h"
#include "APoint.h"

//==============================================================================

class ALogic
{
private:
    AFormation _data;
    
public:
    ALogic(const AFormation& initFormation);
    ~ALogic();
    
    bool collisions(const AFormation* forCompare, const APoint& pos);
    
    void processLogic();
};

//==============================================================================

#endif
