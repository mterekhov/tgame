#include "AFormationFactory.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AFormation AFormationFactory::createFormation1()
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

AFormation AFormationFactory::createFormation2()
{
    AFormation formation(1, 1, 1);
    if (formation.item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return AFormationFactory::nullFormation();

    return formation;
}

//==============================================================================

AFormation AFormationFactory::nullFormation()
{
    return AFormation();
}

//==============================================================================
    
}   //  namespace spcTGame
