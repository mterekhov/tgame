#include "ABlock.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"

//==============================================================================

ABlock::ABlock(const AFormation& data) : _data(data), _size(1.0f)
{
}

//==============================================================================

ABlock::ABlock(const ABlock& block) : ARObject(block), _data(block._data),
                                        _size(block._size)
{
}

//==============================================================================

ABlock::~ABlock()
{
}

//==============================================================================

GLfloat ABlock::size() const
{
    return _size;
}

//==============================================================================

void ABlock::size(const GLfloat sizer)
{
    _size = sizer;
}

//==============================================================================

AFormation ABlock::data() const
{
    return _data;
}
