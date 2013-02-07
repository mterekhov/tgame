#include "AOpenGLState.h"

//==============================================================================

AOpenGLState* AOpenGLState::instance = 0;

//==============================================================================

#pragma mark - Init -

//==============================================================================

AOpenGLState* AOpenGLState::shared()
{
    if (instance)
        return instance;
    
    instance = new AOpenGLState();
    return instance;
}

//==============================================================================

AOpenGLState::AOpenGLState()
{
    drawColorSetup(_drawColor);
    clearColorSetup(_clearColor);
}

//==============================================================================


AOpenGLState::~AOpenGLState()
{
}

//==============================================================================

#pragma mark - Colors -

//==============================================================================

AColor AOpenGLState::clearColor() const
{
    return _clearColor;
}

//==============================================================================

void AOpenGLState::clearColor(const AColor& color)
{
    _clearColor = color;
    clearColorSetup(color);
}

//==============================================================================

AColor AOpenGLState::drawColor() const
{
    return _drawColor;
}

//==============================================================================

void AOpenGLState::drawColor(const AColor& color)
{
    _drawColor = color;
    drawColorSetup(color);
}

//==============================================================================

#pragma mark - OpenGL calls -

//==============================================================================

void AOpenGLState::drawColorSetup(const AColor& color)
{
    glColor4f(color.red, color.green, color.blue, color.alpha);
}

//==============================================================================

void AOpenGLState::clearColorSetup(const AColor& color)
{
    glClearColor(color.red, color.green, color.blue, color.alpha);
}
