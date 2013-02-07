#ifndef __Blockout__AWell__
#define __Blockout__AWell__

//==============================================================================

#include "DrawTypes.h"
#include "ARObject.h"

//==============================================================================

class AWell : public ARObject
{
private:
    void renderHull();
    void renderContent();

public:
    GLfloat wellWidth;
    GLfloat wellHeight;
    GLfloat wellDepth;
    GLfloat wellCellSize;


    AWell();
    AWell(const GLfloat width, const GLfloat height, const GLfloat depth);
    ~AWell();

    void renderObject();
};

//==============================================================================

#endif
