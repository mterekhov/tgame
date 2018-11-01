#include "atexturedblock.h"
#include "aopenglstate.h"
#include "adrawbasics.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ATexturedBlock::ATexturedBlock(const AFormation& formation, ATexture& tex) : ABlock(formation), _texture(tex)
{
    _objectType = OBJECTTYPE_TEXTURED;
}

//==============================================================================

ATexturedBlock::ATexturedBlock(const ATexturedBlock& block) : ABlock(block), _texture(block._texture)
{
}

//==============================================================================

ATexturedBlock::~ATexturedBlock()
{
}

//==============================================================================

void ATexturedBlock::renderObject()
{
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
                    ADrawBasics::drawTexturedCube(point, _size, _texture);
                }
            }
        }
    }
}

//==============================================================================
    
}   //  namespace spcTGame
