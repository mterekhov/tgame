#ifndef ENGINE_ACOLOREDBLOCK_H
#define ENGINE_ACOLOREDBLOCK_H

//==============================================================================

#include "ABlock.h"
#include "AFormation.h"
#include "AColor.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AColoredBlock : public ABlock
{
protected:
    AColor _color;

public:
    AColoredBlock(const AFormation& data);
    AColoredBlock(const AColoredBlock& block);
    virtual ~AColoredBlock();
    
    virtual void renderObject();
    
    AColor color() const;
    void color(const AColor& color);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  ENGINE_ACOLOREDBLOCK_H
