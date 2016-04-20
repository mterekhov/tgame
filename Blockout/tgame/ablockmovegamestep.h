#ifndef SPCTGAME_ABLOCKMOVEGAMESTEP_H
#define SPCTGAME_ABLOCKMOVEGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockMoveGameStep : public AGameStepProtocol
{
private:
    TUint _buttonCode;
        
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage);

    void moveCurrentBlockDown(ADataStorage &dataStorage);
    void moveCurrentBlockUp(ADataStorage &dataStorage);
    void moveCurrentBlockLeft(ADataStorage &dataStorage);
    void moveCurrentBlockRight(ADataStorage &dataStorage);
    
public:
    ABlockMoveGameStep(const TUint buttonCode);
    virtual ~ABlockMoveGameStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKMOVEGAMESTEP_H
