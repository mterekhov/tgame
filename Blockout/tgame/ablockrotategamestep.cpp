#include "ablockrotategamestep.h"
#include "keymaps.h"
#include "ablockoperations.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ABlockRotateGameStep::ABlockRotateGameStep(const TUint buttonCode) : _buttonCode(buttonCode)
{
}

//==============================================================================

ABlockRotateGameStep::~ABlockRotateGameStep()
{
}

//==============================================================================

void ABlockRotateGameStep::executeStep(ADataStorage &dataStorage)
{
    switch (_buttonCode)
    {
        case EKEYCODES_ROTATE_X:
            rotateX(dataStorage);
        break;
        
        case EKEYCODES_ROTATE_Y:
            rotateY(dataStorage);
        break;
        
        case EKEYCODES_ROTATE_Z:
            rotateZ(dataStorage);
        break;
            
        default:
        break;
    }
}

//==============================================================================

void ABlockRotateGameStep::rotateX(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationX(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ABlockRotateGameStep::rotateY(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationY(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ABlockRotateGameStep::rotateZ(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationZ(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ABlockRotateGameStep::rotate(const AMatrix& m, ADataStorage &dataStorage)
{
    AFormation* rotatedFormation = ABlockOperations::createRotatedFrustumFormation(*dataStorage.currentFormation(),
                                                                                   m,
                                                                                   AFrustumBorder(dataStorage.wellHeight(), dataStorage.wellDepth(), dataStorage.wellWidth()));
    dataStorage.replaceCurrentFormation(rotatedFormation);
}

//==============================================================================

}   //  namespace spcTGame
