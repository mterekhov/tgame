#include "ASolidBlock.h"
#include "AOpenGLState.h"
#include "ADrawBasics.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASolidBlock::ASolidBlock(const AFormation& data) : AColoredBlock(data)
{
}

//==============================================================================

ASolidBlock::ASolidBlock(const ASolidBlock& block) : AColoredBlock(block)
{
}

//==============================================================================

ASolidBlock::~ASolidBlock()
{
}

//==============================================================================

void ASolidBlock::renderObject()
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
                    ADrawBasics::drawSolidCube(APoint(i, l, j), _size);
            }
        }
    }
    oglInstance->drawColor(color);
}

//==============================================================================
    
}   //  namespace spcTGame
