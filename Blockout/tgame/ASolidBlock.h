#ifndef ENGINE_ASOLIDBLOCK_H
#define ENGINE_ASOLIDBLOCK_H

//==============================================================================

#include "AColoredBlock.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ASolidBlock : public AColoredBlock
{
public:
    ASolidBlock(const AFormation& data);
    ASolidBlock(const ASolidBlock& block);
    virtual ~ASolidBlock();
    
    virtual void renderObject();
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif // ENGINE_ASOLIDBLOCK_H
