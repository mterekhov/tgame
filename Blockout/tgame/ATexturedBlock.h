#ifndef SPCTGAME_ATEXTUREDBLOCK_H
#define SPCTGAME_ATEXTUREDBLOCK_H

//==============================================================================

#include "ABlock.h"
#include "atexture.h"

//==============================================================================

namespace spcTGame
{
    
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

}   //  namespace spcTGame
    
//==============================================================================
    
#endif // SPCTGAME_ATEXTUREDBLOCK_H
