#include "asolidblock.h"
#include "aopenglstate.h"
#include "adrawbasics.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASolidBlock::ASolidBlock(const AFormation& formation) : AColoredBlock(formation)
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

    for (TInt l = 0; l < _formation.levelsCount(); l++)
    {
        for (TInt i = 0; i < _formation.height(); i++)
        {
            for (TInt j = 0; j < _formation.width(); j++)
            {
                TData value = _formation.item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                {
                    APoint point = _formation.gridSpaceLocation(i, l, j);
                    ADrawBasics::drawSolidCube(point, _size);
                }
            }
        }
    }
    oglInstance->drawColor(color);
}

//==============================================================================
    
}   //  namespace spcTGame
