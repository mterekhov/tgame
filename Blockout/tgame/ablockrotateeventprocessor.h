#ifndef SPCTGAME_ABLOCKROTATEEVENTPROCESSOR_H
#define SPCTGAME_ABLOCKROTATEEVENTPROCESSOR_H

//==============================================================================

#include "blockouttypes.h"
#include "agameeventdelegate.h"
#include "amatrix.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockRotateEventProcessor : public AGameEventDelegate
{
private:
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation);

    void rotateX();
    void rotateY();
    void rotateZ();
    void rotate(const AMatrix& m);

public:
    ABlockRotateEventProcessor(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~ABlockRotateEventProcessor();

    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKROTATEEVENTPROCESSOR_H