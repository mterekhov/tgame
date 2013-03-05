#include "AMacTimer.h"

//==============================================================================

ATimer* ATimer::createTimer(const float interval, AFireObject* target, void* usersData, const bool repeats)
{
    AMacTimer* newTimer = new AMacTimer(interval, target, usersData, repeats);
    return newTimer;
}
