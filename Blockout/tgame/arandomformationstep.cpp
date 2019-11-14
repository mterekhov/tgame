#include "arandomformationstep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ARandomFormationStep::ARandomFormationStep()
{
}

//==============================================================================

ARandomFormationStep::~ARandomFormationStep()
{
}

//==============================================================================

void ARandomFormationStep::executeStep(ADataStorage &dataStorage)
{
	dataStorage.createCurrentFormation();
    AFormation& newStartFormation = dataStorage.currentFormation();
    APoint p(0.0f, dataStorage.wellDepth() - 1.0f, 0.0f);
    newStartFormation.gridSpacePosition(p);

    dataStorage.assignCurrentFormation(newStartFormation);
}

//==============================================================================

}   //  namespace spcTGame
