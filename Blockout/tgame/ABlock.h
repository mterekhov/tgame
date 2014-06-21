#ifndef SPCTGAME_ABLOCK_H
#define SPCTGAME_ABLOCK_H

//==============================================================================

#include "arobject.h"
#include "aformation.h"
#include "acolor.h"

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
    
    void size(const TFloat size);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_ABLOCK_H
