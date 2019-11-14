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
	createWellFormation(1, 1, 1);
	createCurrentFormation();
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

//AFormation& ADataStorage::createFormation1()
//{
//    AFormation newFormation = AFormationFactory::createFormation1();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation2()
//{
//    AFormation newFormation = AFormationFactory::createFormation2();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation3()
//{
//    AFormation newFormation = AFormationFactory::createFormation3();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation4()
//{
//    AFormation newFormation = AFormationFactory::createFormation4();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation5()
//{
//    AFormation newFormation = AFormationFactory::createFormation5();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation6()
//{
//    AFormation newFormation = AFormationFactory::createFormation6();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation7()
//{
//    AFormation newFormation = AFormationFactory::createFormation7();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation8()
//{
//    AFormation newFormation = AFormationFactory::createFormation8();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation9()
//{
//    AFormation newFormation = AFormationFactory::createFormation9();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================
//
//AFormation& ADataStorage::createFormation10()
//{
//    AFormation newFormation = AFormationFactory::createFormation10();
//
//    return addFormationToList(newFormation);
//}
//
////==============================================================================

AFormation ADataStorage::createRandomFormation()
{
    TUint formationIndex = rand() % FORMATIONS_COUNT;
    switch (formationIndex)
    {
        case FORMATIONS_ONE:
            return AFormationFactory::createFormation1();
        break;
        
        case FORMATIONS_TWO:
            return AFormationFactory::createFormation2();
        break;
        
        case FORMATIONS_THREE:
            return AFormationFactory::createFormation3();
        break;
        
        case FORMATIONS_FOUR:
            return AFormationFactory::createFormation4();
        break;
        
        case FORMATIONS_FIVE:
            return AFormationFactory::createFormation5();
        break;
        
        case FORMATIONS_SIX:
            return AFormationFactory::createFormation6();
        break;
        
        case FORMATIONS_SEVEN:
            return AFormationFactory::createFormation7();
        break;
        
        case FORMATIONS_EIGHT:
            return AFormationFactory::createFormation8();
        break;
    };
    
	return AFormationFactory::createFormation1();
}

//==============================================================================

#pragma mark - Current formation -

//==============================================================================

void ADataStorage::assignCurrentFormation(AFormation& formation)
{
	_formationList[EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX] = formation;
}
	
//==============================================================================

AFormation& ADataStorage::currentFormation()
{
    return _formationList[EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX];
}

//==============================================================================

void ADataStorage::createCurrentFormation()
{
	AFormation newRandomFormation = createRandomFormation();
	if (_formationList.size() < EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX + 1)
	{
		_formationList.push_back(newRandomFormation);
	}
	else
	{
		_formationList[EDATASTORAGEINDEXES_CURRENT_FORMATION_INDEX] = newRandomFormation;
	}
}

//==============================================================================

#pragma mark - Well formation -

//==============================================================================

void ADataStorage::createWellFormation(const TFloat width, const TFloat height, const TFloat depth)
{
	AFormation well = AFormationFactory::createFormation(width, height, depth);
	if (_formationList.size() < EDATASTORAGEINDEXES_WELL_FORMATION_INDEX + 1)
	{
		_formationList.push_back(well);
	}
	else
	{
		_formationList[EDATASTORAGEINDEXES_WELL_FORMATION_INDEX] = well;
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

const TFormationsList& ADataStorage::droppedFormationsList()
{
    return _droppedFormationsList;
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

AFormation& ADataStorage::addFormationToList(AFormation& formation)
{
    _formationList.push_back(formation);

    return _formationList.back();
}

//==============================================================================

void ADataStorage::makeFormationDropped(AFormation& formation)
{
    _droppedFormationsList.push_back(formation);
}

//==============================================================================

}   //  namespace spcTGame
