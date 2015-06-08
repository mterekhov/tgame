#ifndef SPCTGAME_AFRUSTUMBORDER_H
#define SPCTGAME_AFRUSTUMBORDER_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AFrustumBorder
{
public:
    AFrustumBorder();
    AFrustumBorder(const TFloat x, const TFloat y, const TFloat z);
    AFrustumBorder(const AFrustumBorder& border);
    
    TFloat x;
    TFloat y;
    TFloat z;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AFRUSTUMBORDER_H
