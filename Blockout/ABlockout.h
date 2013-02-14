#ifndef __Blockout__ABlockout__
#define __Blockout__ABlockout__

//==============================================================================

#include "ACrafter.h"
#include "AColor.h"

//==============================================================================

class ABlockout
{
private:
    void init();

    ACrafter _crafter;
    GLfloat _wellWidth;
    GLfloat _wellHeight;
    GLfloat _wellDepth;
    
public:
    ABlockout();
    ~ABlockout();
    
    void render();
};

//==============================================================================

#endif /* defined(__Blockout__ABlockout__) */
