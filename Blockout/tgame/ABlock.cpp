#include "ABlock.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ABlock::ABlock(const AFormation& data) : _data(data), _size(1.0f)
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

AFormation ABlock::data() const
{
    return _data;
}

//==============================================================================
    
}   //  namespace spcTGame
