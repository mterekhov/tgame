#ifndef SPCTGAME_ACOLOREDBLOCK_H
#define SPCTGAME_ACOLOREDBLOCK_H

//==============================================================================

#include "arenderinterface.h"
#include "aformation.h"
#include "acolor.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class AColoredBlock : public ARenderInterface
{
private:
    AFormation _formation;
    TFloat _size;
    AColor _color;
    ERenderStyle _renderStyle;

public:
    AColoredBlock(const AFormation& formation, const TFloat size, const AColor& color, const ERenderStyle renderStyle);
    AColoredBlock(const AColoredBlock& block);
    virtual ~AColoredBlock();
    
    virtual void render();
    virtual ARenderInterface *copy();
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_ACOLOREDBLOCK_H