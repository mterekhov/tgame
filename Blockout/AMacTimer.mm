#include "AMacTimer.h"

//==============================================================================

AMacTimer::AMacTimer(const float interval, AFireObject* target, void* usersData, const bool repeats) : _fireInterval(interval), _fireObject(target), _usersData(usersData), _isRepeats(repeats)
{    
}

//==============================================================================

AMacTimer::~AMacTimer()
{
}

//==============================================================================


void AMacTimer::invalidate()
{
    _isValid = false;
}

//==============================================================================

bool AMacTimer::fire()
{
    if (isValid() == true)
        return false;

    
    
    return true;
}

//==============================================================================


const bool AMacTimer::isValid() const
{
    if (_isValid == true)
        return true;
    
    return false;
}

//==============================================================================

const bool AMacTimer::isRepeats() const
{
    return _isRepeats;
}

//==============================================================================

void* AMacTimer::userData()
{
    return _usersData;
}
