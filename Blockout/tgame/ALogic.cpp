#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "aformation.h"
#include "ablockoperations.h"

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

#pragma mark - Public -

//==============================================================================
    
void ALogic::processLogic()
{
}

//==============================================================================

void ALogic::startGame()
{
    _dataStorage.createWellFormation(7, 7, 15);
    generateNewCurrentFormation();
}

//==============================================================================

void ALogic::dropCurrentFormation()
{
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

void ALogic::generateNewCurrentFormation()
{
    AFormation* newStartFormation = _dataStorage.createRandomFormation();
    APoint p(0.0f, _dataStorage.wellDepth() - 1.0f, 0.0f);
    newStartFormation->gridSpacePosition(p);

    _dataStorage.replaceCurrentFormation(newStartFormation);
}

//==============================================================================

}   //  namespace spcTGame
