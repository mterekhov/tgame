#include "ABlock.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"

//==============================================================================

ABlock::ABlock(const AFormation& data) : _data(data), _color(AColor::redColor()), _size(1.0f)
{
}

//==============================================================================

ABlock::~ABlock()
{
}

//==============================================================================

void ABlock::renderObject()
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    AColor color = oglInstance->drawColor();
    oglInstance->drawColor(_color);

    for (int l = 0; l < _data.levelsCount(); l++)
    {
        for (int i = 0; i < _data.height(); i++)
        {
            for (int j = 0; j < _data.width(); j++)
            {
                TData value = _data.item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                    ADrawBasics::drawCarcasedCube(APoint(i, l, j), _size);
            }
        }
    }
    oglInstance->drawColor(color);
}

//==============================================================================

AColor ABlock::color() const
{
    return _color;
}

//==============================================================================

void ABlock::color(const AColor& color)
{
    _color = color;
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
