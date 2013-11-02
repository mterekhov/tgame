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
    TFloat _lineWidth;
    bool _textureEnabled;
    
    void clearColorSetup(const AColor& color);
    void drawColorSetup(const AColor& color);
    
public:
    static AOpenGLState* shared();
    
    AOpenGLState();
    ~AOpenGLState();
    
    TFloat lineWidth() const;
    void lineWidth(const TFloat width);
    
    AColor clearColor() const;
    void clearColor(const AColor& color);
    
    AColor drawColor() const;
    void drawColor(const AColor& color);

    void frustumSetup(const TFloat screenWidth, const TFloat screenHeight);
    
    void pushMarices();
    void popMarices();
    
    void textureEnable();
    void textureDisable();
    bool textureEnabled() const;
    
    void clear(GLbitfield mask);
    
    bool currentTexture(ATexture& texture);
    const ATexture& currentTexture() const;
    void clearCurrentTexture();
    
    std::string lastError();
};

//==============================================================================

#endif
