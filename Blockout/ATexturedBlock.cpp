#include "ATexturedBlock.h"
#include "AOpenGLState.h"
#include "ADrawBasics.h"

//==============================================================================

ATexturedBlock::ATexturedBlock(const AFormation& data, const ATexture& tex) : ABlock(data), _texture(tex)
{
    _objectType = OBJECTTYPE_TEXTURED;
}

//==============================================================================

ATexturedBlock::~ATexturedBlock()
{
}

//==============================================================================

void ATexturedBlock::renderObject() const
{
    for (int l = 0; l < _data.levelsCount(); l++)
    {
        for (int i = 0; i < _data.height(); i++)
        {
            for (int j = 0; j < _data.width(); j++)
            {
                TData value = _data.item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                    ADrawBasics::drawSolidCube(APoint(i, l, j), _size);
//                ADrawBasics::drawTexturedCube(APoint(i, l, j), _size, _texture);
            }
        }
    }
}
