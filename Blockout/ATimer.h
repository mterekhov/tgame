#ifndef __Blockout__ATimer__
#define __Blockout__ATimer__

#include "AFireObject.h"

class ATimer
{
public:
    static ATimer* createTimer(const float interval, AFireObject* target, void* usersData, const bool repeats);
    
    virtual void invalidate() = 0;
    virtual bool fire() = 0;
    
    virtual const bool isValid() const = 0;
    virtual const bool isRepeats() const = 0;
    virtual void* userData() = 0;
    
    virtual void fireObject() = 0;
};

#endif
