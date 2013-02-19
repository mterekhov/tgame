#ifndef ASolidBlock_H
#define ASolidBlock_H

//==============================================================================

#include "ABlock.h"

//==============================================================================

class ASolidBlock : public ABlock
{
public:
    ASolidBlock(const AFormation& data);
    ~ASolidBlock();
    virtual void renderObject();
};

//==============================================================================

#endif // ASolidBlock_H
