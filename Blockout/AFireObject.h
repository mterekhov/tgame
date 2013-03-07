#ifndef Blockout_AFireObject_h
#define Blockout_AFireObject_h

//==============================================================================

class ATimer;

//==============================================================================

class AFireObject
{
public:
    virtual void timerFired(const ATimer* timer) = 0;
};

//==============================================================================

#endif
