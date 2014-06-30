#ifndef SPCTGAME_AWELL_H
#define SPCTGAME_AWELL_H

//==============================================================================

#include "arobject.h"
#include "acolor.h"
#include "aformation.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AWell : public ARObject
{
private:
    AFormation& _content;

    void renderHull() const;

public:
    TFloat wellWidth;   //  maps to z axis
    TFloat wellHeight;  //  maps to x axis
    TFloat wellDepth;   //  maps to y axis
    TFloat wellCellSize;
    
    AColor color;

    AWell();
    AWell(const TFloat cellSize, AFormation& content);
    virtual ~AWell();

    virtual void renderObject();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AWELL_H
