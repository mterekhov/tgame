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

}   //  namespace spcTGame
