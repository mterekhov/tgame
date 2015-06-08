#include <math.h>

#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "aformation.h"
#include "ablockoperations.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

enum EFormation
{
    FORMATIONS_ONE,
    FORMATIONS_TWO,
    FORMATIONS_THREE,
    FORMATIONS_FOUR,
    FORMATIONS_FIVE,
    FORMATIONS_SIX,
    FORMATIONS_SEVEN,
    FORMATIONS_EIGHT,
    FORMATIONS_COUNT
};

//==============================================================================

#define PRECISION_EPSILON 0.000001

//==============================================================================
    
ALogic::ALogic(ADataStorage& dataStorage) : _dataStorage(dataStorage)
{
    srand(static_cast<TUint>(time(0)));
}

//==============================================================================

ALogic::~ALogic()
{
}

//==============================================================================

void ALogic::processLogic()
{
}

//==============================================================================

#pragma mark - start the game -

//==============================================================================
    
void ALogic::startGame()
{
    generateNewFormation();
}

//==============================================================================

void ALogic::generateNewFormation()
{
    AFormation* newStartFormation = generateRandomFormation();
    APoint p(0.0f, _dataStorage.wellDepth() - 1.0f, 0.0f);
    newStartFormation->gridSpacePosition(p);
}

//==============================================================================

AFormation* ALogic::generateRandomFormation()
{
    TUint formationIndex = rand() % FORMATIONS_COUNT;
    AFormation* newFormation = 0;

    switch (formationIndex)
    {
        case FORMATIONS_ONE:
            newFormation = _dataStorage.createFormation1();
        break;
        
        case FORMATIONS_TWO:
            newFormation = _dataStorage.createFormation2();
        break;
        
        case FORMATIONS_THREE:
            newFormation = _dataStorage.createFormation3();
        break;
        
        case FORMATIONS_FOUR:
            newFormation = _dataStorage.createFormation4();
        break;
        
        case FORMATIONS_FIVE:
            newFormation = _dataStorage.createFormation5();
        break;
        
        case FORMATIONS_SIX:
            newFormation = _dataStorage.createFormation6();
        break;
        
        case FORMATIONS_SEVEN:
            newFormation = _dataStorage.createFormation7();
        break;
        
        case FORMATIONS_EIGHT:
            newFormation = _dataStorage.createFormation8();
        break;
    };
    
    return newFormation;
}

//==============================================================================

TBool ALogic::collisions(const AFormation* forCompare, const APoint& pos)
{
    return false;
}

//==============================================================================

void ALogic::processKey(const TUint buttonCode)
{
    switch (buttonCode)
    {
        case EKEYCODES_DOWN:
            moveCurrentBlockLeft();
        break;
        
        case EKEYCODES_UP:
            moveCurrentBlockRight();
        break;
        
        case EKEYCODES_LEFT:
            moveCurrentBlockUp();
        break;
        
        case EKEYCODES_RIGHT:
            moveCurrentBlockDown();
        break;
        
        case EKEYCODES_ROTATE_X:
            rotateX();
        break;
        
        case EKEYCODES_ROTATE_Y:
            rotateY();
        break;
        
        case EKEYCODES_ROTATE_Z:
            rotateZ();
        break;
        
        case EKEYCODES_DROP_BLOCK:
            dropCurrentBlock();
        break;
    }
}

//==============================================================================

#pragma mark - Move blocks -

//==============================================================================

void ALogic::moveCurrentBlockDown()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ALogic::moveCurrentBlockUp()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.z -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ALogic::moveCurrentBlockLeft()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ALogic::moveCurrentBlockRight()
{
    AFormation* currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock->gridSpacePosition();
    position.x += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock->gridSpacePosition(position);
}

//==============================================================================

void ALogic::dropCurrentBlock()
{
    makeDrop(_dataStorage.currentFormation());
    generateNewFormation();
}

//==============================================================================

bool ALogic::isBreakingWellBound(const APoint& position, const AFormation* formation)
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

#pragma mark - Rotation -

//==============================================================================

void ALogic::rotateY()
{
    AMatrix m = AMatrix::rotationY(M_PI_2);
    rotate(m);
}

//==============================================================================

void ALogic::rotateX()
{
    AMatrix m = AMatrix::rotationX(M_PI_2);
    rotate(m);
}

//==============================================================================

void ALogic::rotateZ()
{
    AMatrix m = AMatrix::rotationZ(M_PI_2);
    rotate(m);
}

//==============================================================================

void ALogic::rotate(const AMatrix& m)
{
    AFormation* well = _dataStorage.wellFormation();
    AFormation* rotatedFormation = ABlockOperations::createRotatedFrustumFormation(*_dataStorage.currentFormation(),
                                                                                   m,
                                                                                   AFrustumBorder(well->height(), well->levelsCount(), well->width()));
    _dataStorage.currentFormation(rotatedFormation);
}

//==============================================================================

#pragma mark - make drop -

//==============================================================================

void ALogic::makeDrop(AFormation* formation)
{
    APoint position = formation->gridSpacePosition();
    
    APoint dropPosition = findDropPosition(formation);
    formation->gridSpacePosition(dropPosition);
}

//==============================================================================

APoint ALogic::findDropPosition(AFormation* formation)
{
    APoint dropPosition = formation->gridSpacePosition();
    AFormation* wellFormation = _dataStorage.wellFormation();

    for (TInt l = 0; l < formation->levelsCount(); l++)
    {
        for (TInt i = 0; i < formation->height(); i++)
        {
            for (TInt j = 0; j < formation->width(); j++)
            {
                TData value = formation->item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                {
                    
                }
            }
        }
    }
    
    return dropPosition;
}

//==============================================================================

}   //  namespace spcTGame
