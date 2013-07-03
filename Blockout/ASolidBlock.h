#ifndef ENGINE_ASOLIDBLOCK_H
#define ENGINE_ASOLIDBLOCK_H

//==============================================================================

#include "ABlock.h"

//==============================================================================

class ASolidBlock : public ABlock
{
public:
    ASolidBlock(const AFormation& data);
    virtual ~ASolidBlock();
    
    virtual void renderObject();
};

//==============================================================================

#endif // ENGINE_ASOLIDBLOCK_H
