#ifndef ASolidBlock_H
#define ASolidBlock_H

//==============================================================================

#include "ABlock.h"
#include "atexture.h"

//==============================================================================

class ATexturedBlock : public ABlock
{
private:
    ATexture texture;
    
public:
    ATexturedBlock(const AFormation& data);
    ~ATexturedBlock();
    virtual void renderObject();
};

//==============================================================================

#endif // ASolidBlock_H
