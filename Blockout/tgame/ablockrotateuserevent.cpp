#include "ablockrotateuserevent.h"
#include "ablockoperations.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockRotateUserEvent::ABlockRotateUserEvent(const TUint buttonCode) : _buttonCode(buttonCode) 
{
}

//==============================================================================

ABlockRotateUserEvent::~ABlockRotateUserEvent()
{
}

//==============================================================================

void ABlockRotateUserEvent::processEvent(ACrafter &crafter, ADataStorage &dataStorage)
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

    crafter.blockMovedOrRotated();
}

//==============================================================================

void ABlockRotateUserEvent::rotateY(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationY(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ABlockRotateUserEvent::rotateX(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationX(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ABlockRotateUserEvent::rotateZ(ADataStorage &dataStorage)
{
    AMatrix m = AMatrix::rotationZ(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void ABlockRotateUserEvent::rotate(const AMatrix& m, ADataStorage &dataStorage)
{
    AFormation* rotatedFormation = ABlockOperations::createRotatedFrustumFormation(*dataStorage.currentFormation(),
                                                                                   m,
                                                                                   AFrustumBorder(dataStorage.wellHeight(), dataStorage.wellDepth(), dataStorage.wellWidth()));
    dataStorage.replaceCurrentFormation(rotatedFormation);
}

//==============================================================================

}   //  namespace spcTGame
