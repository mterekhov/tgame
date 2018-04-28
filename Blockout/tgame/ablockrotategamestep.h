#ifndef SPCTGAME_ABLOCKROTATEGAMESTEP_H
#define SPCTGAME_ABLOCKROTATEGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"
#include "amatrix.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABlockRotateGameStep : public AGameStepProtocol
{
private:
    TUint _buttonCode;
    
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage);

    void rotateX(ADataStorage &dataStorage);
    void rotateY(ADataStorage &dataStorage);
    void rotateZ(ADataStorage &dataStorage);
    void rotate(const AMatrix& m, ADataStorage &dataStorage);

public:
    ABlockRotateGameStep(const TUint buttonCode);
    virtual ~ABlockRotateGameStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKROTATEGAMESTEP_H
