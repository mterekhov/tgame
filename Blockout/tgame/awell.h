#ifndef SPCTGAME_AWELL_H
#define SPCTGAME_AWELL_H

//==============================================================================

#include "ablock.h"
#include "acolor.h"
#include "aformation.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AWell : public ABlock
{
private:
    void renderHull() const;

public:
    AColor color;

    AWell(const AFormation& formation);
    virtual ~AWell();

    virtual void renderObject();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AWELL_H
