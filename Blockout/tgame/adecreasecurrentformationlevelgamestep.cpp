#include "adecreasecurrentformationlevelgamestep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ALowerStep::ALowerStep()
{
}

//==============================================================================

ALowerStep::~ALowerStep()
{
}

//==============================================================================

void ALowerStep::executeStep(ADataStorage &dataStorage)
{
    AFormation& currentFormation = dataStorage.currentFormation();
    APoint currentFormationPosition = currentFormation.gridSpacePosition();
    currentFormationPosition.y -= 1.0f;
    currentFormation.gridSpacePosition(currentFormationPosition);
}

//==============================================================================

}   //  namespace spcTGame
