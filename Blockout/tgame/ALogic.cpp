#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "aformation.h"
#include <math.h>

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

#define PRECISION_EPSILON 0.000001

//==============================================================================
    
ALogic::ALogic(ADataStorage& dataStorage) : _dataStorage(dataStorage)
{
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
    generateStartFormation();
}

//==============================================================================

void ALogic::generateStartFormation()
{
    AFormation& newStartFormation = generateFormation();
    APoint p(0.0f, _dataStorage.wellDepth() - 1, 0.0f);
    newStartFormation.gridSpacePosition(p);
    _dataStorage.currentFormation(newStartFormation);
}

//==============================================================================

AFormation& ALogic::generateFormation()
{
    AFormation& newFormation = _dataStorage.createFormation1();
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
            loger("moving down");
        break;
        
        case EKEYCODES_UP:
            moveCurrentBlockRight();
            loger("moving up");
        break;
        
        case EKEYCODES_LEFT:
            moveCurrentBlockUp();
            loger("moving left");
        break;
        
        case EKEYCODES_RIGHT:
            moveCurrentBlockDown();
            loger("moving right");
        break;
        
        case EKEYCODES_ROTATE_X:
            loger("rotate x");
        break;
        
        case EKEYCODES_ROTATE_Y:
            rotateY();
        break;
        
        case EKEYCODES_ROTATE_Z:
            loger("rotate z");
        break;
        
        case EKEYCODES_DROP_BLOCK:
            dropCurrentBlock();
            loger("drop block");
        break;
    }
}

//==============================================================================

#pragma mark - Move blocks -

//==============================================================================

void ALogic::moveCurrentBlockDown()
{
    AFormation& currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock.gridSpacePosition();
    position.z += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock.gridSpacePosition(position);
}

//==============================================================================

void ALogic::moveCurrentBlockUp()
{
    AFormation& currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock.gridSpacePosition();
    position.z -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock.gridSpacePosition(position);
}

//==============================================================================

void ALogic::moveCurrentBlockLeft()
{
    AFormation& currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock.gridSpacePosition();
    position.x -= _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock.gridSpacePosition(position);
}

//==============================================================================

void ALogic::moveCurrentBlockRight()
{
    AFormation& currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock.gridSpacePosition();
    position.x += _dataStorage.cellSize();

    if (isBreakingWellBound(position, currentBlock) == false)
        currentBlock.gridSpacePosition(position);
}

//==============================================================================

void ALogic::dropCurrentBlock()
{
    AFormation& currentBlock = _dataStorage.currentFormation();
    APoint position = currentBlock.gridSpacePosition();
    position.y = 0;
    
    currentBlock.gridSpacePosition(position);
    generateStartFormation();
}

//==============================================================================

bool ALogic::isBreakingWellBound(const APoint& position, const AFormation& formation)
{
    //  check top border
    if ((position.x + formation.height()) >_dataStorage.wellHeight() ||
         position.x < 0)
        return true;
        
    if ((position.z + formation.width()) >_dataStorage.wellWidth() ||
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
    
    std::list<APoint> points;
    std::list<TInt> shifts;
    AFormation& f = defineDimmension(m, shifts, points);
    std::list<TInt>::iterator shiftIter = shifts.begin();
    TInt shiftZ = *shiftIter;
    shiftIter++;
    TInt shiftX = *shiftIter;
    shiftIter++;
    TInt shiftY = *shiftIter;
    
    for (std::list<APoint>::iterator iter = points.begin(); iter != points.end(); iter++)
    {
        APoint p = *iter;
//        printf("old point %.3f\t%.3f\t%.3f\n", p.x, p.y, p.z);
        p.x += static_cast<TFloat>(shiftX);
        p.y += static_cast<TFloat>(shiftY);
        p.z += static_cast<TFloat>(shiftZ);
        printf("new point %.3f\t%.3f\t%.3f\n", p.x, p.y, p.z);
        TInt column = static_cast<TUint>(round(p.z));
        TInt row = static_cast<TUint>(round(p.x));
        TInt level = static_cast<TUint>(round(p.y));
        
        TBool r = f.item(column, row, level, EDATASTATE_RENDERABLE);
        if (r == false)
        {
            loger("FUCKUP");
        }
    }
    
    f.gridSpacePosition(_dataStorage.currentFormation().gridSpacePosition());
    _dataStorage.currentFormation(f);
    
}

//==============================================================================

AFormation& ALogic::defineDimmension(const AMatrix& m, std::list<TInt>& shifts, std::list<APoint>& points)
{
    TInt maxWidth = 0;
    TInt maxHeight = 0;
    TInt maxLevels = 0;
    TInt minWidth = 0;
    TInt minHeight = 0;
    TInt minLevels = 0;
    
    AFormation& currentBlock = _dataStorage.currentFormation();
    
    TUint sizer = currentBlock.levelsCount() * currentBlock.width() * currentBlock.height();
    TData* newData = new TData[sizer];
    memset(newData, EDATASTATE_EMPTY, sizer * sizeof(TData));
    
    for (TInt l = 0; l < currentBlock.levelsCount(); l++)
    {
        for (TInt i = 0; i < currentBlock.height(); i++)
        {
            for (TInt j = 0; j < currentBlock.width(); j++)
            {
                TData value = currentBlock.item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                {
                    APoint pointToRotate(i, l, j);
//                    printf("rotating\n%i\t%i\t%i\n", i, l, j);
                    
                    APoint rotated = applyMatrixToPoint(m, pointToRotate);
                    points.push_back(rotated);
//                    printf("after rotation\n%.3f\t%.3f\t%.3f\n", rotated.x, rotated.y, rotated.z);
                    
                    defineAxisNewDimension(rotated.z, &maxWidth, &minWidth);
                    defineAxisNewDimension(rotated.x, &maxHeight, &minHeight);
                    defineAxisNewDimension(rotated.y, &maxLevels, &minLevels);
                }
            }
        }
    }
    
//    printf("\n\nmax %i\t%i\t%i\n", maxWidth, maxHeight, maxLevels);
//    printf("min %i\t%i\t%i\n", minWidth, minHeight, minLevels);
//    printf("new dimmension %i\t%i\t%i\n", maxWidth - minWidth + 1, maxHeight - minHeight + 1, maxLevels - minLevels + 1);

    shifts.push_back(fabs(minWidth));
    shifts.push_back(fabs(minHeight));
    shifts.push_back(fabs(minLevels));

    return _dataStorage.createFormation(maxWidth - minWidth + 1, maxHeight - minHeight + 1, maxLevels - minLevels + 1);
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

}   //  namespace spcTGame
