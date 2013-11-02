#ifndef ENGINE_ASOLIDBLOCK_H
#define ENGINE_ASOLIDBLOCK_H

//==============================================================================

#include "AColoredBlock.h"

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

#endif // ENGINE_ASOLIDBLOCK_H
