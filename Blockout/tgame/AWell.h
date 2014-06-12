#ifndef ENGINE_AWELL_H
#define ENGINE_AWELL_H

//==============================================================================

#include "ARObject.h"
#include "AColor.h"

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
    TFloat wellWidth;
    TFloat wellHeight;
    TFloat wellDepth;
    TFloat wellCellSize;
    
    AColor color;

    AWell();
    AWell(const TFloat width, const TFloat height, const TFloat depth);
    virtual ~AWell();

    virtual void renderObject();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif
