#include "arotateformationstep.h"
#include "keymaps.h"
#include "aformationoperations.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ARotateFormationStep::ARotateFormationStep(const TUint buttonCode) : _buttonCode(buttonCode)
{
}

//==============================================================================

ARotateFormationStep::~ARotateFormationStep()
{
}

//==============================================================================

void ARotateFormationStep::executeStep(ADataStorage &dataStorage)
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

void ARotateFormationStep::rotateX(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationX(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ARotateFormationStep::rotateY(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationY(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ARotateFormationStep::rotateZ(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationZ(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ARotateFormationStep::rotate(const AMatrix& m, ADataStorage &dataStorage)
{
    AFormation rotatedFormation = AFormationOperations::createRotatedFrustumFormation(dataStorage.currentFormation(),
                                                                                   m,
                                                                                   AFrustumBorder(dataStorage.wellHeight(), dataStorage.wellDepth(), dataStorage.wellWidth()));
    dataStorage.assignCurrentFormation(rotatedFormation);
}

//==============================================================================

}   //  namespace spcTGame
