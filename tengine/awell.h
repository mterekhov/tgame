#ifndef SPCTGAME_AWELL_H
#define SPCTGAME_AWELL_H

//==============================================================================

#include "arenderinterface.h"
#include "aformation.h"
#include "acolor.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AWell : public ARenderInterface
{
private:
    AFormation _formation;
    TFloat _size;
    AColor _color;

public:
    AWell(const AFormation& formation, const TFloat size, const AColor& color);
    AWell(const AWell& well);
    virtual ~AWell();

    virtual ARenderInterface *copy();
    virtual void render();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AWELL_H
