#ifndef ENGINE_ABLOCK_H
#define ENGINE_ABLOCK_H

//==============================================================================

#include "ARObject.h"
#include "AFormation.h"
#include "AColor.h"

//==============================================================================

namespace spcTGame
{
    
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
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif
