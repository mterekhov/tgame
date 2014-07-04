#include "aformationfactory.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AFormation AFormationFactory::_nullFormation;

//==============================================================================
    
AFormation AFormationFactory::createFormation1()
{
    AFormation formation(1, 1, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation2()
{
    AFormation formation(1, 2, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation3()
{
    AFormation formation(1, 3, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(0, 2, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation4()
{
    AFormation formation(2, 2, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(1, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation5()
{
    AFormation formation(2, 2, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(1, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(1, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation6()
{
    AFormation formation(2, 3, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(0, 2, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    if (formation.item(1, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation7()
{
    AFormation formation(3, 2, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();
    
    if (formation.item(1, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();
    
    if (formation.item(1, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();
    
    if (formation.item(2, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation8()
{
    AFormation formation(2, 3, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();
    
    if (formation.item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();
    
    if (formation.item(0, 2, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();
    
    if (formation.item(1, 2, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::createFormation9()
{
    return AFormation();
}

//==============================================================================

AFormation AFormationFactory::createFormation10()
{
    return AFormation();
}

//==============================================================================

AFormation& AFormationFactory::nullFormation()
{
    _nullFormation = AFormation();
    return _nullFormation;
}

//==============================================================================
    
}   //  namespace spcTGame
