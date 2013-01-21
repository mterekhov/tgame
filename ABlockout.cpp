#include "ABlockout.h"
#include "ADrawBasics.h"

//==============================================================================

ABlockout::ABlockout()
{
}

//==============================================================================

ABlockout::~ABlockout()
{
}

//==============================================================================

void ABlockout::render()
{
    //  draw without textures
    SPoint originPoint = {0};
        
    ADrawBasics::drawOrigin(originPoint);
    ADrawBasics::drawGrid(50.0f, 50.0f);

    //  draw with textures
}
