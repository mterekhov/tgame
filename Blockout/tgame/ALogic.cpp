#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "aformation.h"
#include <math.h>

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
    APoint p(0.0f, _dataStorage.wellDepth() - 1, 0.0f);
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
    if ((position.x + formation->height()) >_dataStorage.wellHeight() ||
         position.x < 0)
        return true;
        
    if ((position.z + formation->width()) >_dataStorage.wellWidth() ||
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
    APoint gridPoint = _dataStorage.currentFormation()->gridSpacePosition();

    SRotationMetaData rotationMeta;
    AFormation* f = createRotatedFormation(m, rotationMeta);

    for (TRPIter iter = rotationMeta.rotatedPoints.begin(); iter != rotationMeta.rotatedPoints.end(); iter++)
    {
        APoint p = *iter;
        p.x += rotationMeta.negativeShifts[0];
        p.y += rotationMeta.negativeShifts[1];
        p.z += rotationMeta.negativeShifts[2];
        TInt column = static_cast<TUint>(round(p.z));
        TInt row = static_cast<TUint>(round(p.x));
        TInt level = static_cast<TUint>(round(p.y));
        
        TBool r = f->item(column, row, level, EDATASTATE_RENDERABLE);
        if (r == false)
        {
            loger("can not rotate");
        }
    }
    
    correctBlockPosition(gridPoint, f);
    f->gridSpacePosition(gridPoint);
}

//==============================================================================

AFormation* ALogic::createRotatedFormation(const AMatrix& m, SRotationMetaData& rotationMeta)
{
    TInt maxWidth = 0;
    TInt maxHeight = 0;
    TInt maxLevels = 0;
    TInt minWidth = 0;
    TInt minHeight = 0;
    TInt minLevels = 0;
    
    AFormation* currentBlock = _dataStorage.currentFormation();
    
    for (TInt l = 0; l < currentBlock->levelsCount(); l++)
    {
        for (TInt i = 0; i < currentBlock->height(); i++)
        {
            for (TInt j = 0; j < currentBlock->width(); j++)
            {
                TData value = currentBlock->item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                {
                    APoint pointToRotate(i, l, j);
                    APoint rotated = applyMatrixToPoint(m, pointToRotate);
                    rotationMeta.rotatedPoints.push_back(rotated);
                    
                    defineAxisNewDimension(rotated.z, &maxWidth, &minWidth);
                    defineAxisNewDimension(rotated.x, &maxHeight, &minHeight);
                    defineAxisNewDimension(rotated.y, &maxLevels, &minLevels);
                }
            }
        }
    }

    rotationMeta.newDimmension[0] = maxWidth - minWidth + 1;
    rotationMeta.newDimmension[1] = maxHeight - minHeight + 1;
    rotationMeta.newDimmension[2] = maxLevels - minLevels + 1;
    rotationMeta.negativeShifts[2] = fabs(minWidth);
    rotationMeta.negativeShifts[0] = fabs(minHeight);
    rotationMeta.negativeShifts[1] = fabs(minLevels);

    return AFormationFactory::createFormation(rotationMeta.newDimmension[0], rotationMeta.newDimmension[1], rotationMeta.newDimmension[2]);
}

//==============================================================================

void ALogic::correctBlockPosition(APoint& point, const AFormation* f)
{
    TFloat shift = static_cast<TFloat>(f->height()) + point.x;
    if (shift > _dataStorage.wellHeight())
        point.x += _dataStorage.wellHeight() - shift;
    
    shift = static_cast<TFloat>(f->width()) + point.z;
    if (shift > _dataStorage.wellWidth())
        point.z += _dataStorage.wellWidth() - shift;
    
    shift = static_cast<TFloat>(f->levelsCount()) + point.y;
    if (shift > _dataStorage.wellDepth())
        point.y += _dataStorage.wellDepth() - shift;
}

//==============================================================================

void ALogic::defineAxisNewDimension(const TFloat oglCoord, TInt* currentMax, TInt* currentMin)
{
    TFloat min = static_cast<TFloat>(*currentMin);
    TFloat max = static_cast<TFloat>(*currentMax);
    if (oglCoord < min)
    {
        min = oglCoord;
    }
    
    if (oglCoord > max)
    {
        max = oglCoord;
    }

    *currentMin = static_cast<TInt>(roundf(min));
    *currentMax = static_cast<TInt>(roundf(max));
}

//==============================================================================

APoint ALogic::applyMatrixToPoint(const AMatrix& mat, const APoint& in)
{
    APoint res;
    res.x = mat.m[0][0] * in.x + mat.m[1][0] * in.y + mat.m[2][0] * in.z + mat.m[3][0];
    res.y = mat.m[0][1] * in.x + mat.m[1][1] * in.y + mat.m[2][1] * in.z + mat.m[3][1];
    res.z = mat.m[0][2] * in.x + mat.m[1][2] * in.y + mat.m[2][2] * in.z + mat.m[3][2];
    TFloat out3 = mat.m[0][3] * in.x + mat.m[1][3] * in.y + mat.m[2][3] * in.z + mat.m[3][3];
    
    res.x /= out3;
    res.y /= out3;
    res.z /= out3;
    
    return res;
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
