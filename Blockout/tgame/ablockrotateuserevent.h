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
    TUint _buttonCode;
    
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage);

    void rotateX(ADataStorage &dataStorage);
    void rotateY(ADataStorage &dataStorage);
    void rotateZ(ADataStorage &dataStorage);
    void rotate(const AMatrix& m, ADataStorage &dataStorage);

public:
    ABlockRotateUserEvent(const TUint buttonCode);
    virtual ~ABlockRotateUserEvent();

    virtual void processEvent(ACrafter &crafter, ADataStorage &dataStorage);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABLOCKROTATEUSEREVENT_H
