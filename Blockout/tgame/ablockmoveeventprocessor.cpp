#include "ablockmoveeventprocessor.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ABlockMoveEventProcessor::ABlockMoveEventProcessor(ACrafter &crafter, ADataStorage &dataStorage) : AGameEventDelegate(crafter, dataStorage)
{
}

//==============================================================================

ABlockMoveEventProcessor::~ABlockMoveEventProcessor()
{
}

//==============================================================================

void ABlockMoveEventProcessor::processEvent(void *context)
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
    }
    
    _crafter.blockMovedOrRotated();
}

//==============================================================================

void ABlockMoveEventProcessor::moveCurrentBlockRight()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveEventProcessor::moveCurrentBlockLeft()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveEventProcessor::moveCurrentBlockDown()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveEventProcessor::moveCurrentBlockUp()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

TBool ABlockMoveEventProcessor::isBreakingWellBound(const APoint& position, const AFormation* formation)
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
