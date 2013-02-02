#include "ABlockout.h"
#include "ADrawBasics.h"

#include <stdio.h>
#include <time.h>

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
    SPoint originPoint = {0.0f, 0.0f, 0.0f};
    
    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
//    ADrawBasics::drawOrigin(originPoint);
//    ADrawBasics::drawGrid(50.0f, 50.0f);
    glPopMatrix();
    
    _crafter.craft();
}
