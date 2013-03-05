#include "AMacTimer.h"
#include "AMacTimerWrapper.h"

//==============================================================================

void timerFired(NSTimer* timer)
{
    if (timer == nil)
        return;
    
    AMacTimerWrapper* timerWrapper = (AMacTimerWrapper*)timer.userInfo;
    if (timerWrapper == nil)
        return;
    
    AMacTimer* cppTimer = timerWrapper->timer;
    if (!cppTimer)
        return;
    
    cppTimer->fireObject();
}

//==============================================================================

AMacTimer::AMacTimer(const float interval, AFireObject* target, void* usersData, const bool repeats) : _fireInterval(interval), _fireObject(target), _usersData(usersData), _isRepeats(repeats)
{
    AMacTimerWrapper* wrapper = [AMacTimerWrapper macTimer:this];
    
    BOOL repeatTimer = NO;
    if (repeats == true)
        repeatTimer = YES;
    
    _timer = [NSTimer timerWithTimeInterval:interval target:nil selector:@selector(timerFired:) userInfo:wrapper repeats:repeatTimer];
}

//==============================================================================

AMacTimer::~AMacTimer()
{
}

//==============================================================================


void AMacTimer::invalidate()
{
    if (_isValid == false)
        return;
    
    _isValid = false;
    [_timer invalidate];
}

//==============================================================================

bool AMacTimer::fire()
{
    if (isValid() == true)
        return false;

    [_timer fire];
    
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

//==============================================================================

void AMacTimer::fireObject()
{
    if (!_fireObject)
        return;
    
    _fireObject->timerFired(this);
}
