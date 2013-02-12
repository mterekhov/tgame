#include "ABlock.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"

//==============================================================================

ABlock::ABlock(const AFormation& data) : _data(data)
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
                TData value = _data.item(i, j, l);
                if (value == EDATASTATE_RENDERABLE)
                    ADrawBasics::drawCarcasedCube(i, l, j, 1.0f);
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
