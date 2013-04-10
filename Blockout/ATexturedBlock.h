#ifndef ATexturedBlock_H
#define ATexturedBlock_H

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
    virtual ~ATexturedBlock();
    
    virtual void renderObject() const;
};

//==============================================================================

#endif // ATexturedBlock_H
