#ifndef SPCTGAME_AKEYBOARDEVENTS_H
#define SPCTGAME_AKEYBOARDEVENTS_H

//==============================================================================

#include <list>

#include "akeyevent.h"
#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::list<AKeyEvent> TKeyDelegateList;
typedef TKeyDelegateList::iterator TKeyDelegateListIter;

//==============================================================================

class AKeyboardEvents
{
private:
    TKeyDelegateList _delegates;
    
public:
    void addDelegate(const AKeyEvent& newDelegate);
    void keyPressed(const TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYBOARDEVENTS_H
