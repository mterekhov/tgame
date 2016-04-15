#include "auserevent.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

AUserEvent::AUserEvent(ACrafter &crafter, ADataStorage &dataStorage) : _crafter(crafter), _dataStorage(dataStorage)
{
}

//==============================================================================

AUserEvent::~AUserEvent()
{
}

//==============================================================================

void AUserEvent::processEvent(void *context)
{
}

//==============================================================================

}   //  namespace spcTGame
