#include "atexturedblock.h"
#include "aopenglstate.h"
#include "adrawbasics.h"
#include "arenderobject.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ATexturedBlock::ATexturedBlock(const AFormation& formation, const TFloat size, const ATexture& texture) : _formation(formation), _size(size), _texture(texture)
{
}

//==============================================================================

ATexturedBlock::ATexturedBlock(const ATexturedBlock& block) : _formation(block._formation), _size(block._size), _texture(block._texture)
{
}

//==============================================================================

ATexturedBlock::~ATexturedBlock()
{
}

//==============================================================================

ARenderInterface *ATexturedBlock::copy()
{
	return ARenderObject::createTexturedBlock(_formation, _size, _texture);
}

void ATexturedBlock::render()
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
