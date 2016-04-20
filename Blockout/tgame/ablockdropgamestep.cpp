#include "ablockdropgamestep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ABlockDropGameStep::ABlockDropGameStep()
{
}

//==============================================================================

ABlockDropGameStep::~ABlockDropGameStep()
{
}

//==============================================================================

void ABlockDropGameStep::executeStep(ADataStorage &dataStorage)
{
    //  assign drop position to current formation
    AFormation *formationToDrop = dataStorage.currentFormation();
    APoint dropPosition = findDropPosition(formationToDrop);
    formationToDrop->gridSpacePosition(dropPosition);

    //  mark current formation as dropped
    //  and generate new current formation
    dataStorage.dropCurrentFormation();
    
    //  correct new current formation position
    AFormation* newCurrentFormation = dataStorage.currentFormation();
    APoint p(0.0f, dataStorage.wellDepth() - 1.0f, 0.0f);
    newCurrentFormation->gridSpacePosition(p);
}

//==============================================================================

APoint ABlockDropGameStep::findDropPosition(AFormation* formation)
{
    APoint dropPosition = formation->gridSpacePosition();
    dropPosition.y = 0;
//    AFormation* wellFormation = _dataStorage.wellFormation();
//
//    for (TInt l = 0; l < formation->levelsCount(); l++)
//    {
//        for (TInt i = 0; i < formation->height(); i++)
//        {
//            for (TInt j = 0; j < formation->width(); j++)
//            {
//                TData value = formation->item(j, i, l);
//                if (value == EDATASTATE_RENDERABLE)
//                {
//                    
//                }
//            }
//        }
//    }
    
    return dropPosition;
}

//==============================================================================

}   //  namespace spcTGame
