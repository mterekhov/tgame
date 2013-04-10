#ifndef __Blockout__ABlock__
#define __Blockout__ABlock__

//==============================================================================

#include "ARObject.h"
#include "AFormation.h"
#include "AColor.h"

//==============================================================================

class ABlock : public ARObject
{
protected:
    AFormation _data;
    AColor _color;
    GLfloat _size;
    
public:
    ABlock(const AFormation& data);
    virtual  ~ABlock();
    
    virtual void renderObject() const;
    
    AColor color() const;
    void color(const AColor& color);
    
    AFormation data() const;
    
    GLfloat size() const;
    void size(const GLfloat sizer);
};

//==============================================================================

#endif
