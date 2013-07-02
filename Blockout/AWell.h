#ifndef ENGINE_AWELL_H
#define ENGINE_AWELL_H

//==============================================================================

#include "DrawTypes.h"
#include "ARObject.h"
#include "AColor.h"

//==============================================================================

class AWell : public ARObject
{
private:
    void renderHull() const;
    void renderContent() const;

public:
    GLfloat wellWidth;
    GLfloat wellHeight;
    GLfloat wellDepth;
    GLfloat wellCellSize;
    
    AColor color;

    AWell();
    AWell(const GLfloat width, const GLfloat height, const GLfloat depth);
    virtual ~AWell();

    virtual void renderObject();
};

//==============================================================================

#endif
