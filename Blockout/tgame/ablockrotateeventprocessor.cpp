#include "ablockrotateeventprocessor.h"
#include "ablockoperations.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockRotateEventProcessor::ABlockRotateEventProcessor(ACrafter &crafter, ADataStorage &dataStorage) : AGameEventDelegate(crafter, dataStorage)
{
}

//==============================================================================

ABlockRotateEventProcessor::~ABlockRotateEventProcessor()
{
}

//==============================================================================

void ABlockRotateEventProcessor::processEvent(void *context)
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
    }

    _crafter.blockMovedOrRotated();
}

//==============================================================================

void ABlockRotateEventProcessor::rotateY()
{
    AMatrix m = AMatrix::rotationY(M_PI_2);
    rotate(m);
}

//==============================================================================

void ABlockRotateEventProcessor::rotateX()
{
    AMatrix m = AMatrix::rotationX(M_PI_2);
    rotate(m);
}

//==============================================================================

void ABlockRotateEventProcessor::rotateZ()
{
    AMatrix m = AMatrix::rotationZ(M_PI_2);
    rotate(m);
}

//==============================================================================

void ABlockRotateEventProcessor::rotate(const AMatrix& m)
{
    AFormation* rotatedFormation = ABlockOperations::createRotatedFrustumFormation(*_dataStorage.currentFormation(),
                                                                                   m,
                                                                                   AFrustumBorder(_dataStorage.wellHeight(), _dataStorage.wellDepth(), _dataStorage.wellWidth()));
    _dataStorage.currentFormation(rotatedFormation);
}

//==============================================================================

}   //  namespace spcTGame