#include "AColoredBlock.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"

//==============================================================================

AColoredBlock::AColoredBlock(const AFormation& data) : ABlock(data), _color(AColor::redColor())
{
}

//==============================================================================

AColoredBlock::AColoredBlock(const AColoredBlock& block) : ABlock(block), _color(block._color)
{
}

//==============================================================================

AColoredBlock::~AColoredBlock()
{
}

//==============================================================================

void AColoredBlock::renderObject()
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

AColor AColoredBlock::color() const
{
    return _color;
}

//==============================================================================

void AColoredBlock::color(const AColor& color)
{
    _color = color;
}
