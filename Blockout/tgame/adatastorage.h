#ifndef SPCTGAME_ADATASTORAGE_H
#define SPCTGAME_ADATASTORAGE_H

//==============================================================================
//
//  This class is responsible for creating and storing formations of any kind
//  Also it is instance provided as a reference to all the members of application
//  you need.
//
//==============================================================================

#include <list>

#include "aformationfactory.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::list<AFormation*> TFormationList;
typedef TFormationList::iterator TFormationListIter;
typedef TFormationList::const_iterator TFormationListConstIter;

//==============================================================================
    
class ADataStorage
{
private:
    TFormationList _formationList;
    AFormation* _currentFormation;
    AFormation* _wellFormation;

    AFormation* pushFormation(AFormation* pushFormation);

public:
    static TFloat cellSize();

    ADataStorage();
    ~ADataStorage();
    
    AFormation* createFormation1();
    AFormation* createFormation2();
    AFormation* createFormation3();
    AFormation* createFormation4();
    AFormation* createFormation5();
    AFormation* createFormation6();
    AFormation* createFormation7();
    AFormation* createFormation8();
    AFormation* createFormation9();
    AFormation* createFormation10();

    AFormation* createWellFormation(const TFloat width, const TFloat height, const TFloat levelsCount);
    AFormation* wellFormation();
    TFloat wellWidth();
    TFloat wellHeight();
    TFloat wellDepth();

    void currentFormation(AFormation* formation);
    AFormation* currentFormation();

    void deleteFormation(AFormation* formation);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
