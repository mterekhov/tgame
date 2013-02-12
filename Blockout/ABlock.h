#ifndef __Blockout__ABlock__
#define __Blockout__ABlock__

//==============================================================================

#include "ARObject.h"
#include "AData.h"

//==============================================================================

class ABlock : public ARObject
{
private:
    AData _data;
    
public:
    ABlock(const AData& data);
    ~ABlock();
    
    void renderObject();
};

//==============================================================================

#endif
