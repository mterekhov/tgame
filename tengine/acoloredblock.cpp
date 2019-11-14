#include "acoloredblock.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "arenderobject.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AColoredBlock::AColoredBlock(const AFormation& formation, const TFloat size, const AColor& color, const ERenderStyle renderStyle) : _formation(formation), _size(size), _color(color), _renderStyle(renderStyle)
{
}

//==============================================================================

AColoredBlock::AColoredBlock(const AColoredBlock& block) : _formation(block._formation), _size(block._size), _color(block._color), _renderStyle(block._renderStyle)
{
}

//==============================================================================

AColoredBlock::~AColoredBlock()
{
}

//==============================================================================

ARenderInterface *AColoredBlock::copy()
{
	return ARenderObject::createColoredBlock(_formation, _size, _color, _renderStyle);
}

//==============================================================================

void AColoredBlock::render()
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
                    switch (_renderStyle)
                    {
						case RENDERSTYLE_SOLID:
							ADrawBasics::drawSolidCube(point, _size);
						break;
							
						case RENDERSTYLE_CARCAS:
							ADrawBasics::drawCarcasedCube(point, _size);
						break;
					}
                }
            }
        }
    }
    oglInstance->drawColor(color);
}

//==============================================================================

}   //  namespace spcTGame
