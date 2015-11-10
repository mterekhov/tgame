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
    _crafter.blockDropped();
}

//==============================================================================

void ABlockDropEventProcessor::makeDrop(AFormation* formation)
{
    APoint position = formation->gridSpacePosition();
    
    APoint dropPosition = findDropPosition(formation);
    formation->gridSpacePosition(dropPosition);
}

//==============================================================================

APoint ABlockDropEventProcessor::findDropPosition(AFormation* formation)
{
    APoint dropPosition = formation->gridSpacePosition();
    AFormation* wellFormation = _dataStorage.wellFormation();

    for (TInt l = 0; l < formation->levelsCount(); l++)
    {
        for (TInt i = 0; i < formation->height(); i++)
        {
            for (TInt j = 0; j < formation->width(); j++)
            {
                TData value = formation->item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                {
                    
                }
            }
        }
    }
    
    return dropPosition;
}

//==============================================================================

}   //  namespace spcTGame
