#include "ablockrotateuserevent.h"
#include "ablockoperations.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockRotateUserEvent::ABlockRotateUserEvent(ACrafter &crafter, ADataStorage &dataStorage) : AUserEvent(crafter, dataStorage)
{
}

//==============================================================================

ABlockRotateUserEvent::~ABlockRotateUserEvent()
{
}

//==============================================================================

void ABlockRotateUserEvent::processEvent(void *context)
{
    EKeyCodes rotateAxis = *static_cast<EKeyCodes *>(context);
    switch (rotateAxis)
    {
        case EKEYCODES_ROTATE_X:
            rotateX();
        break;
        
        case EKEYCODES_ROTATE_Y:
            rotateY();
        break;
        
        case EKEYCODES_ROTATE_Z:
            rotateZ();
        break;
            
        default:
        break;
    }

    _crafter.blockMovedOrRotated();
}

//==============================================================================

void ABlockRotateUserEvent::rotateY()
{
    AMatrix m = AMatrix::rotationY(M_PI_2);
    rotate(m);
}

//==============================================================================

void ABlockRotateUserEvent::rotateX()
{
    AMatrix m = AMatrix::rotationX(M_PI_2);
    rotate(m);
}

//==============================================================================

void ABlockRotateUserEvent::rotateZ()
{
    AMatrix m = AMatrix::rotationZ(M_PI_2);
    rotate(m);
}

//==============================================================================

void ABlockRotateUserEvent::rotate(const AMatrix& m)
{
    AFormation* rotatedFormation = ABlockOperations::createRotatedFrustumFormation(*_dataStorage.currentFormation(),
                                                                                   m,
                                                                                   AFrustumBorder(_dataStorage.wellHeight(), _dataStorage.wellDepth(), _dataStorage.wellWidth()));
    _dataStorage.replaceCurrentFormation(rotatedFormation);
}

//==============================================================================

}   //  namespace spcTGame
