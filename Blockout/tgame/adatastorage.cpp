//#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "adatastorage.h"

enum EDataStorageIndexes
{
    EDATASTORAGEINDEXES_WELL_FORMATION_INDEX,
    EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX,
    EDATASTORAGEINDEXES_COUNT
};

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ADataStorage::ADataStorage()
{
    srand(static_cast<TUint>(time(0)));
	_formationList.push_back(AFormationFactory::createFormation(1, 1, 1));
	_formationList.push_back(createRandomFormation());
}

//==============================================================================

ADataStorage::~ADataStorage()
{
}

//==============================================================================

TFloat ADataStorage::cellSize()
{
    return 1.0f;
}

//==============================================================================

#pragma mark - Formation list management -

//==============================================================================

AFormation& ADataStorage::createFormation1()
{
    AFormation newFormation = AFormationFactory::createFormation1();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation2()
{
    AFormation newFormation = AFormationFactory::createFormation2();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation3()
{
    AFormation newFormation = AFormationFactory::createFormation3();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation4()
{
    AFormation newFormation = AFormationFactory::createFormation4();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation5()
{
    AFormation newFormation = AFormationFactory::createFormation5();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation6()
{
    AFormation newFormation = AFormationFactory::createFormation6();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation7()
{
    AFormation newFormation = AFormationFactory::createFormation7();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation8()
{
    AFormation newFormation = AFormationFactory::createFormation8();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation9()
{
    AFormation newFormation = AFormationFactory::createFormation9();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createFormation10()
{
    AFormation newFormation = AFormationFactory::createFormation10();

    return createFormation(newFormation);
}

//==============================================================================

AFormation& ADataStorage::createRandomFormation()
{
    TUint formationIndex = rand() % FORMATIONS_COUNT;
    switch (formationIndex)
    {
        case FORMATIONS_ONE:
            return createFormation1();
        break;
        
        case FORMATIONS_TWO:
            return createFormation2();
        break;
        
        case FORMATIONS_THREE:
            return createFormation3();
        break;
        
        case FORMATIONS_FOUR:
            return createFormation4();
        break;
        
        case FORMATIONS_FIVE:
            return createFormation5();
        break;
        
        case FORMATIONS_SIX:
            return createFormation6();
        break;
        
        case FORMATIONS_SEVEN:
            return createFormation7();
        break;
        
        case FORMATIONS_EIGHT:
            return createFormation8();
        break;
    };
    
	return createFormation1();
}

//==============================================================================

#pragma mark - Current formation -

//==============================================================================

void ADataStorage::assignCurrentFormation(const AFormation& formation)
{
//	if (!_formationList.size())
// 	{
//		_formationList.push_back(formation);
//	}
//	else
	{
		_formationList[EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX] = formation;
	}
}

//==============================================================================

AFormation& ADataStorage::currentFormation()
{
    return _formationList[EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX];
}

//==============================================================================

#pragma mark - Well formation -

//==============================================================================

void ADataStorage::createWellFormation(const TFloat width, const TFloat height, const TFloat depth)
{
//	if (!_formationList.size())
//	{
//		_formationList.push_back(AFormationFactory::createFormation(width, height, depth));
//	}
//	else
	{
		_formationList[EDATASTORAGEINDEXES_WELL_FORMATION_INDEX] = AFormationFactory::createFormation(width, height, depth);
	}
}

//==============================================================================

const AFormation& ADataStorage::wellFormation() const
{
    return _formationList[EDATASTORAGEINDEXES_WELL_FORMATION_INDEX];
}

//==============================================================================

TFloat ADataStorage::wellWidth()
{
    return _formationList[EDATASTORAGEINDEXES_WELL_FORMATION_INDEX].width();
}

//==============================================================================

TFloat ADataStorage::wellHeight()
{
    return _formationList[EDATASTORAGEINDEXES_WELL_FORMATION_INDEX].height();
}

//==============================================================================

TFloat ADataStorage::wellDepth()
{
    return _formationList[EDATASTORAGEINDEXES_WELL_FORMATION_INDEX].levelsCount();
}

//==============================================================================

#pragma mark - Drop logic -

//==============================================================================

void ADataStorage::dropCurrentFormation()
{
    makeFormationDropped(_formationList[EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX]);
}

//==============================================================================

const TFormationList& ADataStorage::droppedFormationsList()
{
    return _droppedFormationsList;
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

AFormation& ADataStorage::createFormation(AFormation& formation)
{
    return pushFormation(formation);
}

//==============================================================================

AFormation& ADataStorage::pushFormation(AFormation& pushFormation)
{
    _formationList.push_back(pushFormation);

    return _formationList.back();
}

//==============================================================================

void ADataStorage::makeFormationDropped(AFormation& formation)
{
    _droppedFormationsList.push_back(formation);
}

//==============================================================================

}   //  namespace spcTGame
