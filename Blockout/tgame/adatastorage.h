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

typedef std::vector<AFormation> TFormationsList;
typedef TFormationsList::iterator TFormationsListIter;
typedef TFormationsList::const_iterator TFormationsListConstIter;

//==============================================================================

class ADataStorage
{
private:
    //  list of all formations. It shouldn't be used for rendering!!!!
    //  It is memory managment only
    TFormationsList _formationList;

    //  list of all formations for dropped blocks
    TFormationsList _droppedFormationsList;

    //  push formation into _formationList
    AFormation& addFormationToList(AFormation& formation);
	
    //  delete formation from _formationList and destroy as object(call delete)
    void deleteFormation(AFormation& formation);
    
    void makeFormationDropped(AFormation& formation);

public:
    static TFloat cellSize();

    ADataStorage();
    ~ADataStorage();
    
    AFormation createRandomFormation();

	void createCurrentFormation();
    AFormation& currentFormation();
    void assignCurrentFormation(AFormation& formation);

    void createWellFormation(const TFloat width, const TFloat height, const TFloat depth);
    const AFormation& wellFormation() const;

    //  _wellFormation width
    TFloat wellWidth();

    //  _wellFormation height
    TFloat wellHeight();

    //  _wellFormation depth
    TFloat wellDepth();

    const TFormationsList& droppedFormationsList();
    void dropCurrentFormation();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
