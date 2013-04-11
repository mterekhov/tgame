#ifndef ENGINE_AVECTOR_H
#define ENGINE_AVECTOR_H

//==============================================================================

#include "DrawTypes.h"

//==============================================================================

class AVector
{
public:
    AVector();
    AVector(const GLfloat x, const GLfloat y, const GLfloat z);
    AVector(const AVector& vector);
    ~AVector();
    
    void normalize();

    GLfloat x;
    GLfloat y;
    GLfloat z;
};

//==============================================================================

#endif
