#ifndef SPCTGAME_AFORMATION_H
#define SPCTGAME_AFORMATION_H

//==============================================================================
//
//  This class is a simple formation
//
//==============================================================================

#include "BlockoutTypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
enum EDataState
{
    EDATASTATE_EMPTY,
    EDATASTATE_RENDERABLE,
    EDATASTATE_ROTATED
};

//==============================================================================

class AFormation
{
private:
    TUint _width;
    TUint _height;
    TUint _levelsCount;
    TData* _data;

public:
    AFormation();
    AFormation(const TUint width, const TUint height, const TUint count);
    AFormation(const AFormation& formation);
    ~AFormation();
    
    const TData* data() const;
    TUint height() const;
    TUint width() const;
    TUint levelsCount() const;
    TData item(const TUint column, const TUint row, const TUint levelIndex) const;
    TBool item(const TUint column, const TUint row, const TUint levelIndex, const TData& value);
    
    TBool doesInbounds(const AFormation* data);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATION_H
