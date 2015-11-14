#include "ablockdropeventprocessor.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockDropEventProcessor::ABlockDropEventProcessor(ACrafter &crafter, ADataStorage &dataStorage) : AGameEventDelegate(crafter, dataStorage)
{
}

//==============================================================================

ABlockDropEventProcessor::~ABlockDropEventProcessor()
{
}

//==============================================================================

void ABlockDropEventProcessor::processEvent(void *context)
{
    makeDrop();
}

//==============================================================================

void ABlockDropEventProcessor::makeDrop()
{
    AFormation *formationToDrop = _dataStorage.currentFormation();
    APoint dropPosition = findDropPosition(formationToDrop);
    dropPosition.y = 0;
    formationToDrop->gridSpacePosition(dropPosition);

    _dataStorage.dropCurrentFormation();
    AFormation* newCurrentFormation = _dataStorage.currentFormation();
    APoint p(0.0f, _dataStorage.wellDepth() - 1.0f, 0.0f);
    newCurrentFormation->gridSpacePosition(p);

    _crafter.blockDropped();
}

//==============================================================================

APoint ABlockDropEventProcessor::findDropPosition(AFormation* formation)
{
    APoint dropPosition = formation->gridSpacePosition();
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
