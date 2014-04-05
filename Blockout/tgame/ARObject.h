#ifndef ENGINE_AROBJECT_H
#define ENGINE_AROBJECT_H

//==============================================================================

enum EObjectType
{
    OBJECTTYPE_SOLID,
    OBJECTTYPE_TEXTURED
};

//==============================================================================

class ARObject
{
protected:
    EObjectType _objectType;
    
public:
    ARObject();
    ARObject(const ARObject& object);
    virtual ~ARObject();
    
    virtual void renderObject();
    EObjectType objectType() const;
};

//==============================================================================

#endif
