#ifndef ASolidBlock_H
#define ASolidBlock_H

//==============================================================================

#include "ABlock.h"

//==============================================================================

class ASolidBlock : public ABlock
{
public:
    ASolidBlock(const AFormation& data);
    virtual ~ASolidBlock();
    
    virtual void renderObject() const;
};

//==============================================================================

#endif // ASolidBlock_H
