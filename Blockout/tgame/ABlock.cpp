#include "ablock.h"
#include "adrawbasics.h"
#include "aopenglstate.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ABlock::ABlock(AFormation* data) : _data(data), _size(1.0f)
{
}

//==============================================================================

ABlock::ABlock(const ABlock& block) : ARObject(block), _data(block.data()),
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

//void ABlock::size(const TFloat size)
//{
//    _size = size;
//}

//==============================================================================

AFormation* ABlock::data() const
{
    return _data;
}

//==============================================================================

}   //  namespace spcTGame
