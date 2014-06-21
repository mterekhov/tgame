#include "akeyboardevents.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

void AKeyboardEvents::addDelegate(const AKeyEvent& newDelegate)
{
    _delegates.push_back(newDelegate);
}

//==============================================================================

void AKeyboardEvents::keyPressed(const TUint buttonCode)
{
    for (TKeyDelegateListIter iter = _delegates.begin(); iter != _delegates.end(); iter++)
    {
        iter->processKey(buttonCode);
    }
}

//==============================================================================

}   //  namespace spcTGame
