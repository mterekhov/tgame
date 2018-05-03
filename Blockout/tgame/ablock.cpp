#include "ablock.h"
#include "adrawbasics.h"
#include "aopenglstate.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ABlock::ABlock(const AFormation& formation) : _formation(formation), _size(1.0f)
{
}

//==============================================================================

ABlock::ABlock(const ABlock& block) : ARObject(block), _formation(block.formation()),
                                        _size(block.size())
{
}

//==============================================================================

ABlock::~ABlock()
{
}

//==============================================================================

TFloat ABlock::size() const
{
    return _size;
}

//==============================================================================

const AFormation& ABlock::formation() const
{
    return _formation;
}

//==============================================================================

}   //  namespace spcTGame
