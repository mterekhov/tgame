#ifndef SPCTGAME_ABLOCKROTATEUSEREVENT_H
#define SPCTGAME_ABLOCKROTATEUSEREVENT_H

//==============================================================================

#include "blockouttypes.h"
#include "auserevent.h"
#include "amatrix.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockRotateUserEvent : public AUserEvent
{
private:
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation);

    void rotateX();
    void rotateY();
    void rotateZ();
    void rotate(const AMatrix& m);

public:
    ABlockRotateUserEvent(ACrafter &crafter, ADataStorage &dataStorage);
    virtual ~ABlockRotateUserEvent();

    virtual void processEvent(void *context);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKROTATEUSEREVENT_H
