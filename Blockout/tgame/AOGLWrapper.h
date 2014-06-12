#ifndef SPCTGAME_AOGLWRAPPER_H
#define SPCTGAME_AOGLWRAPPER_H

//==============================================================================

#include "BlockoutTypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class AOGLWrapper
{
public:
    static void oglTexCoordPointer(TInt size, TEnum type, TSize stride, const TVoid* pointer);
    static void oglVertexPointer(TInt size, TEnum type, TSize stride, const TVoid* pointer);
    static void oglDrawArrays(TEnum mode, TInt first, TSize count);
    static void oglMultMatrixf(const TFloat* m);
    static void oglTranslatef(TFloat x, TFloat y, TFloat z);
    static void oglEnable(TEnum cap);
    static void oglEnableClientState(TEnum array);
    static void oglColor4f(TFloat red, TFloat green, TFloat blue, TFloat alpha);
    static void oglClearColor(TFloat red, TFloat green, TFloat blue, TFloat alpha);
    static void oglViewport(TInt x, TInt y, TSize width, TSize height);
    static void oglMatrixMode(TEnum mode);
    static void oglLoadIdentity();
    static void oglFrustum(TDouble left, TDouble right, TDouble bottom, TDouble top, TDouble zNear, TDouble zFar);
    static void oglPushMatrix();
    static void oglPopMatrix();
    static void oglDisable(TEnum cap);
    static void oglDisableClientState(TEnum array);
    static void oglClear(TBitfield mask);
    static void oglLineWidth(TFloat width);
    static void oglGenTextures(TSize n, TUint* textures);
    static void oglDeleteTextures(TSize n, const TUint* textures);
//extern void glDeleteTextures (GLsizei n, const GLuint *textures);
//extern void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
//extern void glTexParameterf (GLenum target, GLenum pname, GLfloat param);
//extern void glBindTexture (GLenum target, GLuint texture);
//extern GLenum glGetError (void);
};

//extern void glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
//extern void glVertexPointer   (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
//extern void glDrawArrays (GLenum mode, GLint first, GLsizei count);
//extern void glMultMatrixf (const GLfloat *m);
//extern void glTranslatef (GLfloat x, GLfloat y, GLfloat z);
//extern void glEnable (GLenum cap);
//extern void glEnableClientState (GLenum array);
//extern void glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
//extern void glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
//extern void glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
//extern void glMatrixMode (GLenum mode);
//extern void glLoadIdentity (void);
//extern void glFrustum (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
//extern void glPushMatrix (void);
//extern void glPopMatrix (void);
//extern void glDisable (GLenum cap);
//extern void glDisableClientState (GLenum array);
//extern void glClear (GLbitfield mask);
//extern void glLineWidth (GLfloat width);
//extern void glGenTextures (GLsizei n, GLuint *textures);
//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AOGLWRAPPER_H
