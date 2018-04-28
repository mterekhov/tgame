#include "ablockmovegamestep.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ABlockMoveGameStep::ABlockMoveGameStep(const TUint buttonCode) : _buttonCode(buttonCode)
{
}

//==============================================================================

ABlockMoveGameStep::~ABlockMoveGameStep()
{
}

//==============================================================================

void ABlockMoveGameStep::executeStep(ADataStorage &dataStorage)
{
    switch (_buttonCode)
    {
        case EKEYCODES_DOWN:
            moveCurrentBlockDown(dataStorage);
        break;
        
        case EKEYCODES_UP:
            moveCurrentBlockUp(dataStorage);
        break;
        
        case EKEYCODES_LEFT:
            moveCurrentBlockLeft(dataStorage);
        break;
        
        case EKEYCODES_RIGHT:
            moveCurrentBlockRight(dataStorage);
        break;
            
        default:
            return;
        break;
    }
}

//==============================================================================

void ABlockMoveGameStep::moveCurrentBlockRight(ADataStorage &dataStorage)
{
    AFormation* currentBlock = dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z += dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock, dataStorage) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveGameStep::moveCurrentBlockLeft(ADataStorage &dataStorage)
{
    AFormation* currentBlock = dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z -= dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock, dataStorage) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveGameStep::moveCurrentBlockDown(ADataStorage &dataStorage)
{
    AFormation* currentBlock = dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x -= dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock, dataStorage) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ABlockMoveGameStep::moveCurrentBlockUp(ADataStorage &dataStorage)
{
    AFormation* currentBlock = dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x += dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock, dataStorage) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

TBool ABlockMoveGameStep::isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage)
{
    //  check top border
    if ((position.x + formation->height()) > dataStorage.wellHeight() ||
         position.x < 0)
        return true;
        
    if ((position.z + formation->width()) > dataStorage.wellWidth() ||
         position.z < 0)
        return true;
        
    return false;
}

//==============================================================================

}   //  namespace spcTGame
