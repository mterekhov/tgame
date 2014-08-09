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
}

//==============================================================================

AFormation* ADataStorage::createWellFormation(const TFloat width, const TFloat height, const TFloat levelsCount)
{
    AFormation* newFormation = AFormationFactory::createFormation(width, height, levelsCount);
//    AFormation* newFormation = new AFormation(width, height, levelsCount);
    _wellFormation = pushFormation(newFormation);
    
    return _wellFormation;
}

//==============================================================================

//AFormation* ADataStorage::createFormation(const TFloat width, const TFloat height, const TFloat levelsCount)
//{
//    AFormation* newFormation = new AFormation(width, height, levelsCount);
//    return pushFormation(newFormation);
//}

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
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation2()
{
    AFormation* newFormation = AFormationFactory::createFormation2();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation3()
{
    AFormation* newFormation = AFormationFactory::createFormation3();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation4()
{
    AFormation* newFormation = AFormationFactory::createFormation4();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation5()
{
    AFormation* newFormation = AFormationFactory::createFormation5();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation6()
{
    AFormation* newFormation = AFormationFactory::createFormation6();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation7()
{
    AFormation* newFormation = AFormationFactory::createFormation7();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation8()
{
    AFormation* newFormation = AFormationFactory::createFormation8();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation9()
{
    AFormation* newFormation = AFormationFactory::createFormation9();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
}

//==============================================================================

AFormation* ADataStorage::createFormation10()
{
    AFormation* newFormation = AFormationFactory::createFormation10();
    _currentFormation = pushFormation(newFormation);
    return _currentFormation;
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

}   //  namespace spcTGame
