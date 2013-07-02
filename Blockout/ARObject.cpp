#include "ARObject.h"

//==============================================================================

ARObject::ARObject() : _objectType(OBJECTTYPE_SOLID)
{
}

//==============================================================================

ARObject::ARObject(const ARObject& object) : _objectType(object._objectType)
{
}

//==============================================================================

ARObject::~ARObject()
{
}

//==============================================================================

void ARObject::renderObject() const
{
}

//==============================================================================

EObjectType ARObject::objectType() const
{
    return _objectType;
}
