#include "anewwellstep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ANewWellStep::ANewWellStep()
{
}

//==============================================================================

ANewWellStep::~ANewWellStep()
{
}

//==============================================================================

void ANewWellStep::executeStep(ADataStorage &dataStorage)
{
    dataStorage.createWellFormation(7, 7, 15);
}

//==============================================================================

}   //  namespace spcTGame