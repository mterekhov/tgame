#ifndef ENGINE_ADATA_H
#define ENGINE_ADATA_H

//==============================================================================

#include "BlockoutTypes.h"

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

#endif