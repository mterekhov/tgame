#include "amoveformationstep.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AMoveFormationStep::AMoveFormationStep(const TUint buttonCode) : _buttonCode(buttonCode)
{
}

//==============================================================================

AMoveFormationStep::~AMoveFormationStep()
{
}

//==============================================================================

void AMoveFormationStep::executeStep(ADataStorage &dataStorage)
{
    switch (_buttonCode)
    {
        case EKEYCODES_DOWN:
            moveCurrentFormationDown(dataStorage);
        break;
        
        case EKEYCODES_UP:
            moveCurrentFormationUp(dataStorage);
        break;
        
        case EKEYCODES_LEFT:
            moveCurrentFormationLeft(dataStorage);
        break;
        
        case EKEYCODES_RIGHT:
            moveCurrentFormationRight(dataStorage);
        break;
            
        default:
            return;
        break;
    }
}

//==============================================================================

void AMoveFormationStep::moveCurrentFormationRight(ADataStorage &dataStorage)
{
    AFormation& currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation.gridSpacePosition();
    position.z += dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation.gridSpacePosition(position);
}

//==============================================================================

void AMoveFormationStep::moveCurrentFormationLeft(ADataStorage &dataStorage)
{
    AFormation& currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation.gridSpacePosition();
    position.z -= dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation.gridSpacePosition(position);
}

//==============================================================================

void AMoveFormationStep::moveCurrentFormationDown(ADataStorage &dataStorage)
{
    AFormation& currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation.gridSpacePosition();
    position.x -= dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation.gridSpacePosition(position);
}

//==============================================================================

void AMoveFormationStep::moveCurrentFormationUp(ADataStorage &dataStorage)
{
    AFormation& currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation.gridSpacePosition();
    position.x += dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation.gridSpacePosition(position);
}

//==============================================================================

TBool AMoveFormationStep::isBreakingWellBound(const APoint& position, const AFormation& formation, ADataStorage &dataStorage)
{
    //  check top border
    if ((position.x + formation.height()) > dataStorage.wellHeight() ||
         position.x < 0)
        return true;
        
    if ((position.z + formation.width()) > dataStorage.wellWidth() ||
         position.z < 0)
        return true;
        
    return false;
}

//==============================================================================

}   //  namespace spcTGame