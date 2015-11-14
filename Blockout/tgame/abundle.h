#ifndef SPCTGAME_ABUNDLE_H
#define SPCTGAME_ABUNDLE_H

//==============================================================================

#include "blockouttypes.h"
#include "abundleprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABundle
{
private:
    static ABundleProtocol *_mainBundle;
    static ABundleProtocol *getMainBundle();
    
public:
    static TString fullPathToResource(const TString& resourceFileName);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABUNDLE_H
