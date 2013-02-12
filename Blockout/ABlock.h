#ifndef __Blockout__ABlock__
#define __Blockout__ABlock__

//==============================================================================

#include "ARObject.h"
#include "AFormation.h"
#include "AColor.h"

//==============================================================================

class ABlock : public ARObject
{
private:
    AFormation _data;
    AColor _color;
public:
    ABlock(const AFormation& data);
    ~ABlock();
    
    void renderObject();
    
    AColor color() const;
    void color(const AColor& color);
};

//==============================================================================

#endif
