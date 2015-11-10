#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ADataStorage::ADataStorage() : _currentFormation(0), _wellFormation(0)
{
}

//==============================================================================

ADataStorage::~ADataStorage()
{
    destroyAllFormations();
}

//==============================================================================

void ADataStorage::destroyAllFormations()
{
    for (TFormationListIter iter = _formationList.begin(); iter != _formationList.end(); iter++)
    {
        AFormation *formation = *iter;
        _formationList.remove(formation);
        delete formation;
    }
}

//==============================================================================

AFormation* ADataStorage::createWellFormation(const TFloat width, const TFloat height, const TFloat depth)
{
    deleteFormation(_wellFormation);
    AFormation* newFormation = AFormationFactory::createFormation(width, height, depth);
    _wellFormation = pushFormation(newFormation);
    
    return _wellFormation;
}

//==============================================================================

AFormation* ADataStorage::pushFormation(AFormation* pushFormation)
{
    _formationList.push_back(pushFormation);

    return _formationList.back();
}

//==============================================================================

AFormation* ADataStorage::createFormation1()
{
    AFormation* newFormation = AFormationFactory::createFormation1();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation2()
{
    AFormation* newFormation = AFormationFactory::createFormation2();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation3()
{
    AFormation* newFormation = AFormationFactory::createFormation3();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation4()
{
    AFormation* newFormation = AFormationFactory::createFormation4();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation5()
{
    AFormation* newFormation = AFormationFactory::createFormation5();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation6()
{
    AFormation* newFormation = AFormationFactory::createFormation6();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation7()
{
    AFormation* newFormation = AFormationFactory::createFormation7();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation8()
{
    AFormation* newFormation = AFormationFactory::createFormation8();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation9()
{
    AFormation* newFormation = AFormationFactory::createFormation9();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation10()
{
    AFormation* newFormation = AFormationFactory::createFormation10();
    currentFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

void ADataStorage::currentFormation(AFormation* formation)
{
    _formationList.remove(_currentFormation);
    _currentFormation = pushFormation(formation);
}

//==============================================================================

AFormation* ADataStorage::currentFormation()
{
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::wellFormation()
{
    return _wellFormation;
}

//==============================================================================

TFloat ADataStorage::wellWidth()
{
    return _wellFormation->width();
}

//==============================================================================

TFloat ADataStorage::wellHeight()
{
    return _wellFormation->height();
}

//==============================================================================

TFloat ADataStorage::wellDepth()
{
    return _wellFormation->levelsCount();
}

//==============================================================================

TFloat ADataStorage::cellSize()
{
    return 1.0f;
}

//==============================================================================

void ADataStorage::deleteFormation(AFormation* formation)
{
    if (formation == 0)
        return;
    
    _formationList.remove(formation);
    delete formation;
}

//==============================================================================

}   //  namespace spcTGame
