#ifndef SPCTGAME_ATEXTUREDBLOCK_H
#define SPCTGAME_ATEXTUREDBLOCK_H

//==============================================================================

#include "arenderinterface.h"
#include "aformation.h"
#include "atexture.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ATexturedBlock : public ARenderInterface
{
private:
    AFormation _formation;
    TFloat _size;
    ATexture _texture;

public:
    ATexturedBlock(const AFormation& formation, const TFloat size, const ATexture& texture);
    ATexturedBlock(const ATexturedBlock& block);
    virtual ~ATexturedBlock();
    
    virtual void render();
	virtual ARenderInterface *copy();
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif // SPCTGAME_ATEXTUREDBLOCK_H
