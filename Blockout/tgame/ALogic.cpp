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
    _dataStorage.createWellFormation(7, 7, 15);
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

}   //  namespace spcTGame
