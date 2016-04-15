#include "ablockmoveuserevent.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockMoveUserEvent::ABlockMoveUserEvent(ACrafter &crafter, ADataStorage &dataStorage) : AUserEvent(crafter, dataStorage)
{
}

//==============================================================================

ABlockMoveUserEvent::~ABlockMoveUserEvent()
{
}

//==============================================================================

void ABlockMoveUserEvent::processEvent(void *context)
{
    EKeyCodes direction = *static_cast<EKeyCodes *>(context);
    switch (direction)
    {
        case EKEYCODES_DOWN:
            moveCurrentBlockDown();
        break;
        
        case EKEYCODES_UP:
            moveCurrentBlockUp();
        break;
        
        case EKEYCODES_LEFT:
            moveCurrentBlockLeft();
        break;
        
        case EKEYCODES_RIGHT:
            moveCurrentBlockRight();
        break;
            
        default:
        break;
    }
    
    _crafter.blockMovedOrRotated();
}

//==============================================================================

void ABlockMoveUserEvent::moveCurrentBlockRight()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveUserEvent::moveCurrentBlockLeft()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveUserEvent::moveCurrentBlockDown()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveUserEvent::moveCurrentBlockUp()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

TBool ABlockMoveUserEvent::isBreakingWellBound(const APoint& position, const AFormation* formation)
{
    //  check top border
    if ((position.x + formation->height()) > _dataStorage.wellHeight() ||
         position.x < 0)
        return true;
        
    if ((position.z + formation->width()) > _dataStorage.wellWidth() ||
         position.z < 0)
        return true;
        
    return false;
}

//==============================================================================

}   //  namespace spcTGame
