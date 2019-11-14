#ifndef SPCTGAME_AROTATEFORMATIONSTEP_H
#define SPCTGAME_AROTATEFORMATIONSTEP_H

//==============================================================================

#include "astepprotocol.h"
#include "amatrix.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ARotateFormationStep : public AStepProtocol
{
private:
    TUint _buttonCode;
    
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage);

    void rotateX(ADataStorage &dataStorage);
    void rotateY(ADataStorage &dataStorage);
    void rotateZ(ADataStorage &dataStorage);
    void rotate(const AMatrix& m, ADataStorage &dataStorage);

public:
    ARotateFormationStep(const TUint buttonCode);
    virtual ~ARotateFormationStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AROTATEFORMATIONSTEP_H
