#ifndef __Blockout__ADrawBasics__
#define __Blockout__ADrawBasics__

//==============================================================================

class ADrawBasics
{
public:
    static ADrawBasics& instance();
    ADrawBasics();
    ~ADrawBasics();

private:
    static ADrawBasics* _basics;
};

//==============================================================================

#endif
