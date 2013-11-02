#ifndef ENGINE_ABLOCK_H
#define ENGINE_ABLOCK_H

//==============================================================================

#include "ARObject.h"
#include "AFormation.h"
#include "AColor.h"

//==============================================================================

class ABlock : public ARObject
{
protected:
    AFormation _data;
    TFloat _size;
    
public:
    ABlock(const AFormation& data);
    ABlock(const ABlock& block);
    virtual ~ABlock();
    
    AFormation data() const;
    
    TFloat size() const;
    void size(const TFloat sizer);
};

//==============================================================================

#endif
