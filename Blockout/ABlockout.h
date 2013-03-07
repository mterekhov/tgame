#ifndef __Blockout__ABlockout__
#define __Blockout__ABlockout__

//==============================================================================

#include "ACrafter.h"
#include "ALogic.h"
#include "AColor.h"

//==============================================================================

class ABlockout
{
private:
    void init();
    void render();

    ACrafter _crafter;
    ALogic _logic;
    GLfloat _wellWidth;
    GLfloat _wellHeight;
    GLfloat _wellDepth;
    
public:
    ABlockout();
    ~ABlockout();
    
    void processGameCycle();
};

//==============================================================================

#endif /* defined(__Blockout__ABlockout__) */
