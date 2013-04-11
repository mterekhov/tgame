#include "AFormation.h"
#include "BlockoutDebug.h"

#include <string.h>
#include <stdio.h>

//==============================================================================

AFormation::AFormation(const TUint width, const TUint height, const TUint count) : _width(width), _height(height), _levelsCount(count)
{
    int sizer = width * height * count;
    _data = new TData[sizer];
    memset(_data, EDATASTATE_EMPTY, sizer * sizeof(TData));
}

//==============================================================================

AFormation::AFormation(const AFormation& formation) : _width(formation.width()), _height(formation.height()), _levelsCount(formation.levelsCount())
{
    _data = new TData[_width * _height * _levelsCount];
    int sizer = _width * _height * _levelsCount * sizeof(TData);
    memcpy(_data, formation.data(), sizer);
}

//==============================================================================

AFormation::~AFormation()
{
    delete [] _data;
}

//==============================================================================

TUint AFormation::height() const
{
    return _height;
}

//==============================================================================

TUint AFormation::width() const
{
    return _width;
}

//==============================================================================

TUint AFormation::levelsCount() const
{
    return _levelsCount;
}

//==============================================================================

TData AFormation::item(const TUint column, const TUint row, const TUint levelIndex) const
{
    if (!_data)
        return 0;
    
    if (row > _height)
        return 0;
    
    if (column > _width)
        return 0;
    
    if (levelIndex > _levelsCount)
        return 0;
    
    int skip = _width * _height * levelIndex;
    return _data[skip + row * _width + column];
}

//==============================================================================

bool AFormation::item(const TUint column, const TUint row, const TUint levelIndex, const TData& value)
{
    if (!_data)
        return false;

    if (row > _height)
        return false;

    if (column > _width)
        return false;

    if (levelIndex > _levelsCount)
        return false;

    int skip = _width * _height * levelIndex;
    int index = skip + row * _width + column;

    _data[index] = value;
    
    return true;
}

//==============================================================================

bool AFormation::doesInbounds(const AFormation* data)
{
    if (!data)
        return false;
    
    if ((data->height() < _height) &&
       (data->width() < _width) &&
       (data->levelsCount() < _levelsCount))
       return true;
    
    return false;
}

//==============================================================================

const TData* AFormation::data() const
{
    return _data;
}

//==============================================================================
