#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"
#include "aformation.h"
#include "ablockoperations.h"

//==============================================================================

namespace spcTGame
{
    
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
    time_t timeStamp = time(NULL);
    if (_previousCycleTimeStamp == 0)
        _previousCycleTimeStamp = timeStamp;
    time_t diff = timeStamp - _previousCycleTimeStamp;
    
    if (diff > LEVEL_DEC_PERIOD)
    {
        decreaseCurrentBlockLevel();
        _previousCycleTimeStamp = timeStamp;
    }
}

//==============================================================================

void ALogic::startGame()
{
    _dataStorage.createWellFormation(7, 7, 15);
    generateNewCurrentFormation();
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

void ALogic::decreaseCurrentBlockLevel()
{
    AFormation *currentFormation = _dataStorage.currentFormation();
    APoint currentFormationPosition = currentFormation->gridSpacePosition();
    currentFormationPosition.y -= 1.0f;
    currentFormation->gridSpacePosition(currentFormationPosition);
}

//==============================================================================

}   //  namespace spcTGame
