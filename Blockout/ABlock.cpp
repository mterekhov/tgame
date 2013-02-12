#include "ABlock.h"
#include "ADrawBasics.h"

//==============================================================================

ABlock::ABlock(const AData& data) : _data(data)
{
}

//==============================================================================

ABlock::~ABlock()
{
}

//==============================================================================

void ABlock::renderObject()
{
    for (int l = 0; l < _data.levelsCount(); l++)
    {
        for (int i = 0; i < _data.height(); i++)
        {
            for (int j = 0; j < _data.width(); j++)
            {
                TData value = _data.item(i, j, l);
                if (value)
                    ADrawBasics::drawCarcasedCube(i, l, j, 1.0f);
            }
        }
    }
}
