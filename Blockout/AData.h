#ifndef __Blockout__AData__
#define __Blockout__AData__

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

class AData
{
private:
    unsigned int _width;
    unsigned int _height;
    unsigned int _levelsCount;
    TData* _data;

public:
    AData(const unsigned int width, const unsigned int height, const unsigned int count);
    ~AData();
    
    unsigned int height() const;
    unsigned int width() const;
    unsigned int levelsCount() const;
    TData item(const unsigned int row, const unsigned int column, const unsigned int levelIndex) const;
    
    bool doesInbounds(const AData* data);
};

//==============================================================================

#endif
