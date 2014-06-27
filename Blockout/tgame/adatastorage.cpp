#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ADataStorage::ADataStorage() : _currentFormation(AFormationFactory::nullFormation()), _wellWidth(5.0f), _wellHeight(5.0f), _wellDepth(9.0f)
{
}

//==============================================================================

ADataStorage::~ADataStorage()
{
}

//==============================================================================

AFormation& ADataStorage::createFormation(const TFloat width, const TFloat height, const TFloat levelsCount)
{
    AFormation newFormation(width, height, levelsCount);
    _formationList.push_back(newFormation);
    
    return _formationList.back();
}

//==============================================================================

AFormation& ADataStorage::createFormation1()
{
    AFormation newFormation = AFormationFactory::createFormation1();
    _formationList.push_back(newFormation);
    
    return _formationList.back();
}

//==============================================================================

void ADataStorage::currentFormation(AFormation& formation)
{
    _currentFormation = formation;
}

//==============================================================================

AFormation& ADataStorage::currentFormation()
{
    return _currentFormation;
}

//==============================================================================

TFloat ADataStorage::wellWidth()
{
    return _wellWidth;
}

//==============================================================================

TFloat ADataStorage::wellHeight()
{
    return _wellHeight;
}

//==============================================================================

TFloat ADataStorage::wellDepth()
{
    return _wellDepth;
}

//==============================================================================

void ADataStorage::wellWidth(const TFloat width)
{
    _wellWidth = width;
}

//==============================================================================

void ADataStorage::wellHeight(const TFloat height)
{
    _wellHeight = height;
}

//==============================================================================

void ADataStorage::wellDepth(const TFloat depth)
{
    _wellDepth = depth;
}

//==============================================================================

TFloat ADataStorage::cellSize()
{
    return 1.0f;
}

//==============================================================================

}   //  namespace spcTGame
