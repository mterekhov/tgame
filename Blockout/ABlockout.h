#ifndef __Blockout__ABlockout__
#define __Blockout__ABlockout__

//==============================================================================

#include "ACrafter.h"

//==============================================================================

class ABlockout
{
private:
    ACrafter _crafter;

public:
    ABlockout();
    ~ABlockout();
    
    void render();
};

//==============================================================================

#endif /* defined(__Blockout__ABlockout__) */
