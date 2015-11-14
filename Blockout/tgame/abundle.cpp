#include "abundle.h"
#include "amacbundle.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ABundleProtocol *ABundle::_mainBundle;

//==============================================================================

ABundleProtocol *ABundle::getMainBundle()
{
    if (_mainBundle)
        return _mainBundle;
    
    return new AMacBundle();
}

//==============================================================================

TString ABundle::fullPathToResource(const TString& resourceFileName)
{
    return getMainBundle()->fullPathToResource(resourceFileName);
}

//==============================================================================

}   //  namespace spcTGame
