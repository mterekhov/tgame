#ifndef __Blockout__ALogic__
#define __Blockout__ALogic__

//==============================================================================

#include "AData.h"
#include "APoint.h"

//==============================================================================

class ALogic
{
private:
    AData* _data;
    
public:
    ALogic(const unsigned int width, const unsigned int height, const unsigned int levelIndex);
    ~ALogic();
    
    bool collisions(const AData* forCompare, const APoint& pos);
};

//==============================================================================

#endif
