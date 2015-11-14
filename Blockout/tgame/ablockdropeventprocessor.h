#ifndef SPCTGAME_ABLOCKDROPEVENTPROCESSOR_H
#define SPCTGAME_ABLOCKDROPEVENTPROCESSOR_H

//==============================================================================

#include "blockouttypes.h"
#include "agameeventdelegate.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockDropEventProcessor : public AGameEventDelegate
{
private:
    void makeDrop();
    APoint findDropPosition(AFormation* formation);

public:
    ABlockDropEventProcessor(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~ABlockDropEventProcessor();

    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKDROPEVENTPROCESSOR_H
