#ifndef __Blockout__ARObject__
#define __Blockout__ARObject__

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
    virtual ~ARObject();
    virtual void renderObject();
    EObjectType objectType() const;
};

//==============================================================================

#endif
