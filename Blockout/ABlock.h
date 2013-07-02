#ifndef ENGINE_ABLOCK_H
#define ENGINE_ABLOCK_H

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
    ABlock(const ABlock& block);
    virtual  ~ABlock();
    
    virtual void renderObject();
    
    AColor color() const;
    void color(const AColor& color);
    
    AFormation data() const;
    
    GLfloat size() const;
    void size(const GLfloat sizer);
};

//==============================================================================

#endif
