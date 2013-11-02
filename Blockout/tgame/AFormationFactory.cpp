#include "AFormationFactory.h"

//==============================================================================

AFormation AFormationFactory::createFormation1()
{
    AFormation formation(3, 2, 1);
    formation.item(0, 0, 0, EDATASTATE_RENDERABLE);
    formation.item(1, 0, 0, EDATASTATE_RENDERABLE);
    formation.item(1, 1, 0, EDATASTATE_RENDERABLE);
    formation.item(2, 1, 0, EDATASTATE_RENDERABLE);

    return formation;
}
