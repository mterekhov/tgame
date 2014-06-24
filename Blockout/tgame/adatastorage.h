#ifndef SPCTGAME_ADATASTORAGE_H
#define SPCTGAME_ADATASTORAGE_H

//==============================================================================
//
//  This class is responsible for creating and storing formations of any kind
//
//==============================================================================

#include <list>

#include "aformationfactory.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::list<AFormation> TFormationList;
typedef TFormationList::iterator TFormationListIter;
typedef TFormationList::const_iterator TFormationListConstIter;

//==============================================================================
    
class ADataStorage
{
private:
    TFormationList _formationList;
    AFormation& _currentFormation;
    
    TFloat _wellWidth;
    TFloat _wellHeight;
    TFloat _wellDepth;
    
public:
    static TFloat cellSize();

    ADataStorage();
    ~ADataStorage();
    AFormation& createFormation1();

    TFloat wellWidth();
    TFloat wellHeight();
    TFloat wellDepth();
    void wellWidth(const TFloat width);
    void wellHeight(const TFloat height);
    void wellDepth(const TFloat depth);
    
    void currentFormation(AFormation& formation);
    AFormation& currentFormation();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
