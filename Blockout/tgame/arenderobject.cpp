#include "arenderobject.h"
#include "atexturedblock.h"
#include "acoloredblock.h"
#include "awell.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ARenderObject::ARenderObject() : _object(0)
{

}

//==============================================================================

ARenderObject::ARenderObject(const ARenderObject& renderObject)
{
	_object = renderObject._object->copy();
}

//==============================================================================

ARenderObject::ARenderObject(ARenderInterface *object) : _object(object->copy())
{
}

//==============================================================================

ARenderObject::~ARenderObject()
{
	if (_object)
	{
		delete _object;
		_object = 0;
	}
}

//==============================================================================

ARenderInterface *ARenderObject::createTexturedBlock(const AFormation &formation, const TFloat size, const ATexture &texture)
{
	ATexturedBlock *newBlock = new ATexturedBlock(formation, size, texture);
	return newBlock;
}
	
//==============================================================================

ARenderInterface *ARenderObject::createColoredBlock(const AFormation& formation, const TFloat size, const AColor& color)
{
	AColoredBlock *newBlock = new AColoredBlock(formation, size, color);
	return newBlock;
}
	
//==============================================================================

ARenderInterface *ARenderObject::createWell(const AFormation& formation, const TFloat size, const AColor& color)
{
	AWell *newWell = new AWell(formation, size, color);
	return newWell;
}
	
//==============================================================================

void ARenderObject::render()
{
	if (_object == 0)
	{
		return;
	}
	
	_object->render();
}

//==============================================================================
    
}   //  namespace spcTGame

