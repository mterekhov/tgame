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
    
}   //  namespace spcTGame
