#include "AOpenGLState.h"
#include "BlockoutDebug.h"
#include "ATextureManager.h"

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

AOpenGLState::AOpenGLState() : _lineWidth(1.0f), _textureEnabled(false), _currentTexture(ATextureManager::zeroTexture)
{
    drawColorSetup(_drawColor);
    clearColorSetup(_clearColor);

    glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);
	glDepthFunc(GL_LESS);

//	glEnable(GL_CULL_FACE);
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

void AOpenGLState::frustumSetup(const TFloat screenWidth, const TFloat screenHeight)
{
    glViewport(0.0f, 0.0f, screenWidth, screenHeight);
    
    TFloat aspect = screenWidth / screenHeight;
    TFloat near = 0.1f;
    TFloat far = 10000.0f;
    TFloat fieldOfView = 45.0f;
    TFloat size = near * tanf(DEG_TO_RAD(fieldOfView) / 2.0f);
    TFloat width = size;
    TFloat height = size / aspect;
    
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

void AOpenGLState::textureEnable()
{
    if (_textureEnabled)
    {
        loger("textures already enabled");
        return;
    }
    
    _textureEnabled = true;
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

//==============================================================================

void AOpenGLState::textureDisable()
{
    if (!_textureEnabled)
    {
        loger("textures already disabled");
        return;
    }
    
    _textureEnabled = false;
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//==============================================================================

bool AOpenGLState::textureEnabled() const
{
    return _textureEnabled;
}

//==============================================================================

bool AOpenGLState::currentTexture(ATexture& texture)
{
    if (_textureEnabled == false)
        return false;

    _currentTexture = texture;
    texture.atBind();

    return true;
}

//==============================================================================

const ATexture& AOpenGLState::currentTexture() const
{
    return _currentTexture;
}

//==============================================================================

void AOpenGLState::clearCurrentTexture()
{
    _currentTexture.atUnBind();
    _currentTexture = ATextureManager::zeroTexture;
}

//==============================================================================

void AOpenGLState::clear(GLbitfield mask)
{
    glClear(mask);
}

//==============================================================================

TFloat AOpenGLState::lineWidth() const
{
    return _lineWidth;
}

//==============================================================================

void AOpenGLState::lineWidth(const TFloat width)
{
    _lineWidth = width;
    glLineWidth(width);
}

//==============================================================================

std::string AOpenGLState::lastError()
{
    std::string error = "unknown error";
    
    GLenum errorCode = glGetError();
    switch (errorCode) {
        case GL_NO_ERROR:
            error = "ok";
            break;
        case GL_INVALID_ENUM:
            error = "An unacceptable value is specified for an enumerated argument. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_INVALID_VALUE:
            error = "A numeric argument is out of range. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_INVALID_OPERATION:
            error = "The specified operation is not allowed in the current state. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_STACK_OVERFLOW:
            error = "This command would cause a stack overflow. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_STACK_UNDERFLOW:
            error = "This command would cause a stack underflow. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_OUT_OF_MEMORY:
            error = "There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded.";
            break;
    }
    
    return error;
}
