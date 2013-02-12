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
    GLfloat _lineWidth;
    
    void clearColorSetup(const AColor& color);
    void drawColorSetup(const AColor& color);
    
public:
    static AOpenGLState* shared();
    
    AOpenGLState();
    ~AOpenGLState();
    
    GLfloat lineWidth() const;
    void lineWidth(const GLfloat width);
    
    AColor clearColor() const;
    void clearColor(const AColor& color);
    
    AColor drawColor() const;
    void drawColor(const AColor& color);

    void frustumSetup(const GLfloat screenWidth, const GLfloat screenHeight);
    
    void pushMarices();
    void popMarices();
    
    void clear(GLbitfield mask);
};

//==============================================================================

#endif
