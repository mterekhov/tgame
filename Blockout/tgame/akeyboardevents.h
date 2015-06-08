#ifndef SPCTGAME_AKEYBOARDEVENTS_H
#define SPCTGAME_AKEYBOARDEVENTS_H

//==============================================================================

#include <list>

#include "akeyeventdelegate.h"
#include "blockouttypes.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::list<AKeyEventDelegate*> TKeyDelegateList;
typedef TKeyDelegateList::iterator TKeyDelegateListIter;

//==============================================================================

class AKeyboardEvents
{
private:
    TKeyDelegateList _delegates;
    
public:
    void addDelegate(AKeyEventDelegate& newDelegate);
    void keyPressed(const TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYBOARDEVENTS_H
