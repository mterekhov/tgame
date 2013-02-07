#ifndef __Blockout__AOpenGLState__
#define __Blockout__AOpenGLState__

//==============================================================================

#include "AColor.h"

//==============================================================================

class AOpenGLState
{
private:
    static AOpenGLState* instance;
    
    AColor _clearColor;
    AColor _drawColor;
    
    void clearColorSetup(const AColor& color);
    void drawColorSetup(const AColor& color);
    
public:
    static AOpenGLState* shared();
    
    AOpenGLState();
    ~AOpenGLState();
    
    AColor clearColor() const;
    void clearColor(const AColor& color);
    
    AColor drawColor() const;
    void drawColor(const AColor& color);
};

//==============================================================================

#endif
