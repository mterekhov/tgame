#ifndef ENGINE_ATEXTUREDBLOCK_H
#define ENGINE_ATEXTUREDBLOCK_H

//==============================================================================

#include "ABlock.h"
#include "atexture.h"

//==============================================================================

class ATexturedBlock : public ABlock
{
private:
    ATexture _texture;

public:
    ATexturedBlock(const AFormation& data, const ATexture& tex);
    ATexturedBlock(const ATexturedBlock& block);
    virtual ~ATexturedBlock();
    
    virtual void renderObject();
};

//==============================================================================

#endif // ENGINE_ATEXTUREDBLOCK_H
