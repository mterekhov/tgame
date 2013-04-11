#ifndef ENGINE_AOPENGLSTATE_H
#define ENGINE_AOPENGLSTATE_H

//==============================================================================

#include "AColor.h"
#include "atexture.h"

//==============================================================================

class AOpenGLState
{
private:
    static AOpenGLState* instance;
    
    ATexture _currentTexture;
    AColor _clearColor;
    AColor _drawColor;
    GLfloat _lineWidth;
    bool _textureEnabled;
    
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
    
    void textureEnable();
    void textureDisable();
    bool textureEnabled() const;
    
    void clear(GLbitfield mask);
    
    bool currentTexture(const ATexture& texture);
    ATexture currentTexture() const;
    void clearCurrentTexture();
    
    std::string lastError();
};

//==============================================================================

#endif
