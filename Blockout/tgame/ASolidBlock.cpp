#include "asolidblock.h"
#include "aopenglstate.h"
#include "adrawbasics.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASolidBlock::ASolidBlock(AFormation& data) : AColoredBlock(data)
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

    for (TInt l = 0; l < _data.levelsCount(); l++)
    {
        for (TInt i = 0; i < _data.height(); i++)
        {
            for (TInt j = 0; j < _data.width(); j++)
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
