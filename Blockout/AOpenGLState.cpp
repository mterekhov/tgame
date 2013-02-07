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

    glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);
	glDepthFunc(GL_LESS);
    
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH); // Type of shading for the polygons
    glEnableClientState(GL_VERTEX_ARRAY);
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

//==============================================================================

void AOpenGLState::frustumSetup(const GLfloat screenWidth, const GLfloat screenHeight)
{
    glViewport(0.0f, 0.0f, screenWidth, screenHeight);
    
    GLfloat aspect = screenWidth / screenHeight;
    GLfloat near = 0.1f;
    GLfloat far = 10000.0f;
    GLfloat fieldOfView = 45.0f;
    GLfloat size = near * tanf(DEG_TO_RAD(fieldOfView) / 2.0f);
    GLfloat width = size;
    GLfloat height = size / aspect;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-width, width, -height, height, near, far);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//==============================================================================

void AOpenGLState::pushMarices()
{
    glPushMatrix();
}

//==============================================================================

void AOpenGLState::popMarices()
{
    glPopMatrix();
}

//==============================================================================

void AOpenGLState::clear(GLbitfield mask)
{
    glClear(mask);
}
