#include "agameeventdelegate.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

AGameEventDelegate::AGameEventDelegate(ACrafter &crafter, ADataStorage &dataStorage) : _crafter(crafter), _dataStorage(dataStorage)
{
}

//==============================================================================

AGameEventDelegate::~AGameEventDelegate()
{
}

//==============================================================================

void AGameEventDelegate::processEvent(void *context)
{
}

//==============================================================================

}   //  namespace spcTGame
