#include "ADrawBasics.h"

//==============================================================================

ADrawBasics* ADrawBasics::_basics;

//==============================================================================

ADrawBasics& ADrawBasics::instance()
{
    if (_basics == 0)
    {
        _basics = new ADrawBasics();
    }
    
    return *_basics;
}

//==============================================================================

ADrawBasics::ADrawBasics()
{
}

//==============================================================================

ADrawBasics::~ADrawBasics()
{
}
