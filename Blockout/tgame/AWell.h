#ifndef SPCTGAME_AWELL_H
#define SPCTGAME_AWELL_H

//==============================================================================

#include "arobject.h"
#include "acolor.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AWell : public ARObject
{
private:
    void renderHull() const;
    void renderContent() const;

public:
    TFloat wellWidth;   //  maps to z axis
    TFloat wellHeight;  //  maps to x axis
    TFloat wellDepth;   //  maps to y axis
    TFloat wellCellSize;
    
    AColor color;

    AWell();
    AWell(const TFloat width, const TFloat height, const TFloat depth, const TFloat cellSize);
    virtual ~AWell();

    virtual void renderObject();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AWELL_H
