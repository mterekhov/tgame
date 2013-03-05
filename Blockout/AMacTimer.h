#ifndef __Blockout__AMacTimer__
#define __Blockout__AMacTimer__

//==============================================================================

#include <time.h>
#include <list>

#include "ATimer.h"
#include "BlockoutTypes.h"
#include "AFireObject.h"

//==============================================================================

class AMacTimer : public ATimer
{
private:
    AFireObject* _fireObject;
    bool _isValid;
    bool _isRepeats;
    float _fireInterval;
    void* _usersData;

public:
    AMacTimer(const float interval, AFireObject* target, void* usersData, const bool repeats);
    ~AMacTimer();
    
    void invalidate();
    bool fire();
    
    const bool isValid() const;
    const bool isRepeats() const;
    void* userData();
};

//==============================================================================

#endif
