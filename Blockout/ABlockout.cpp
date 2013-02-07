#include "ABlockout.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"

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
    AOpenGLState* oglState = AOpenGLState::shared();
    SPoint originPoint = {0.0f, 0.0f, 0.0f};
    
    oglState->pushMarices();
    
    ADrawBasics::installCamera(AVector(3.0f, 5.0f, 6.0f), AVector(0.0f, 0.0f, 0.0f), AVector(0.0f, 1.0f, 0.0f));
    ADrawBasics::drawOrigin(originPoint);
//    ADrawBasics::drawGrid(50.0f, 50.0f);

    _crafter.craft();
    
    oglState->popMarices();
}
