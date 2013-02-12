#include "AData.h"

#include <stdio.h>

//==============================================================================

AData::AData(const unsigned int width, const unsigned int height, const unsigned int count) : _width(width), _height(height), _levelsCount(count)
{
    int sizer = width * height * count;
    _data = new TData[sizer];
}

//==============================================================================

AData::~AData()
{
    delete [] _data;
}

//==============================================================================

unsigned int AData::height() const
{
    return _height;
}

//==============================================================================

unsigned int AData::width() const
{
    return _width;
}

//==============================================================================

unsigned int AData::levelsCount() const
{
    return _levelsCount;
}

//==============================================================================

TData AData::item(const unsigned int row, const unsigned int column, const unsigned int levelIndex) const
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
    return _data[skip + row * _width + column];
}

//==============================================================================

bool AData::doesInbounds(const AData* data)
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
