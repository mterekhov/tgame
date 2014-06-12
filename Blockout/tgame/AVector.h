#ifndef ENGINE_AVECTOR_H
#define ENGINE_AVECTOR_H

//==============================================================================

#include "BlockoutTypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AVector
{
public:
    AVector();
    AVector(const TFloat x, const TFloat y, const TFloat z);
    AVector(const AVector& vector);
    ~AVector();
    
    void normalize();

    TFloat x;
    TFloat y;
    TFloat z;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif
