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

}   //  namespace spcTGame
