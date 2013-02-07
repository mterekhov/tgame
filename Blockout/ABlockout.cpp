#include "ABlockout.h"
#include "ADrawBasics.h"
#include "AOpenGLState.h"
#include "AWell.h"

#include <stdio.h>
#include <time.h>

//==============================================================================

ABlockout::ABlockout() : _wellWidth(3.0f), _wellHeight(3.0f), _wellDepth(9.0f)
{
    AWell* well = new AWell(_wellWidth, _wellHeight, _wellDepth);
    _crafter.addObjectForRender(well);
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

    ADrawBasics::installCamera(AVector(_wellWidth / 2.0f, 2.0f * _wellDepth, _wellHeight / 2.0f),
                               AVector(_wellWidth / 2.0f, 0.0f, _wellHeight / 2.0f),
                               AVector(1.0f, 0.0f, 0.0f));
    ADrawBasics::drawOrigin(originPoint);
//    ADrawBasics::drawGrid(50.0f, 50.0f);

    _crafter.craft();
    
    oglState->popMarices();
}
