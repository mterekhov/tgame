#ifndef SPCTGAME_AMOVEFORMATIONSTEP_H
#define SPCTGAME_AMOVEFORMATIONSTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AMoveFormationStep : public AGameStepProtocol
{
private:
    TUint _buttonCode;
        
    TBool isBreakingWellBound(const APoint& position, const AFormation& formation, ADataStorage &dataStorage);

    void moveCurrentFormationDown(ADataStorage &dataStorage);
    void moveCurrentFormationUp(ADataStorage &dataStorage);
    void moveCurrentFormationLeft(ADataStorage &dataStorage);
    void moveCurrentFormationRight(ADataStorage &dataStorage);
    
public:
    AMoveFormationStep(const TUint buttonCode);
    virtual ~AMoveFormationStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AMOVEFORMATIONSTEP_H
