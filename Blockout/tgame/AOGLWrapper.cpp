#include "AOGLWrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

void AOGLWrapper::oglTexCoordPointer(TInt size, TEnum type, TSize stride, const TVoid* pointer)
{
    glTexCoordPointer(size, type, stride, pointer);
}

//==============================================================================
    
void AOGLWrapper::oglVertexPointer(TInt size, TEnum type, TSize stride, const TVoid* pointer)
{
    glVertexPointer(size, type, stride, pointer);
}

//==============================================================================

/// mode - what primitives you would like to draw
/// first - index of the first element
/// count - number of points(not primitives or it's floats)
void AOGLWrapper::oglDrawArrays(TEnum mode, TInt first, TSize count)
{
    glDrawArrays(mode, first, count);
}

//==============================================================================

void AOGLWrapper::oglMultMatrixf(const TFloat* m)
{
    glMultMatrixf(m);
}

//==============================================================================

void AOGLWrapper::oglTranslatef(TFloat x, TFloat y, TFloat z)
{
    glTranslatef(x, y, z);
}

//==============================================================================

void AOGLWrapper::oglEnable(TEnum cap)
{
    glEnable(cap);
}

//==============================================================================

void AOGLWrapper::oglDepthFunc(TEnum func)
{
    glDepthFunc(func);
}

//==============================================================================

void AOGLWrapper::oglClearDepth(TDouble depth)
{
    glClearDepth(depth);
}

//==============================================================================

void AOGLWrapper::oglShadeModel(TEnum mode)
{
    glShadeModel(mode);
}

//==============================================================================

void AOGLWrapper::oglEnableClientState(TEnum array)
{
    glEnableClientState(array);
}

//==============================================================================

void AOGLWrapper::oglColor4f(TFloat red, TFloat green, TFloat blue, TFloat alpha)
{
    glColor4f(red, green, blue, alpha);
}

//==============================================================================

void AOGLWrapper::oglClearColor(TFloat red, TFloat green, TFloat blue, TFloat alpha)
{
    glClearColor(red, green, blue, alpha);
}

//==============================================================================

void AOGLWrapper::oglViewport(TInt x, TInt y, TSize width, TSize height)
{
    glViewport(x, y, width, height);
}

//==============================================================================

void AOGLWrapper::oglMatrixMode(TEnum mode)
{
    glMatrixMode(mode);
}

//==============================================================================

void AOGLWrapper::oglLoadIdentity()
{
    glLoadIdentity();
}

//==============================================================================

void AOGLWrapper::oglFrustum(TDouble left, TDouble right, TDouble bottom, TDouble top, TDouble zNear, TDouble zFar)
{
    glFrustum(left, right, bottom, top, zNear, zFar);
}

//==============================================================================

void AOGLWrapper::oglPushMatrix()
{
    glPushMatrix();
}

//==============================================================================

void AOGLWrapper::oglPopMatrix()
{
    glPopMatrix();
}

//==============================================================================

void AOGLWrapper::oglDisable(TEnum cap)
{
    glDisable(cap);
}

//==============================================================================

void AOGLWrapper::oglDisableClientState(TEnum array)
{
    glDisableClientState(array);
}

//==============================================================================

void AOGLWrapper::oglClear(TBitfield mask)
{
    glClear(mask);
}

//==============================================================================

void AOGLWrapper::oglLineWidth(TFloat width)
{
    glLineWidth(width);
}

//==============================================================================

void AOGLWrapper::oglGenTextures(TSize n, TUint* textures)
{
    glGenTextures(n, textures);
}

//==============================================================================

void AOGLWrapper::oglDeleteTextures(TSize n, const TUint* textures)
{
    glDeleteTextures(n, textures);
}

//==============================================================================

void AOGLWrapper::oglTexImage2D(TEnum target, TInt level, TInt internalformat, TSize width, TSize height, TInt border, TEnum format, TEnum type, const TVoid* pixels)
{
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

//==============================================================================

void AOGLWrapper::oglTexParameterf(TEnum target, TEnum pname, TFloat param)
{
    glTexParameterf(target, pname, param);
}

//==============================================================================

void AOGLWrapper::oglBindTexture(TEnum target, TUint texture)
{
    glBindTexture(target, texture);
}

//==============================================================================

TEnum AOGLWrapper::oglGetError()
{
    return glGetError();
}

//==============================================================================

}   //  namespace spcTGame
