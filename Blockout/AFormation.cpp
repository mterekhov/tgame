#include "AFormation.h"

#include <stdio.h>

//==============================================================================

AFormation::AFormation(const unsigned int width, const unsigned int height, const unsigned int count) : _width(width), _height(height), _levelsCount(count)
{
    int sizer = width * height * count;
    _data = new TData[sizer];
}

//==============================================================================

AFormation::~AFormation()
{
    delete [] _data;
}

//==============================================================================

unsigned int AFormation::height() const
{
    return _height;
}

//==============================================================================

unsigned int AFormation::width() const
{
    return _width;
}

//==============================================================================

unsigned int AFormation::levelsCount() const
{
    return _levelsCount;
}

//==============================================================================

TData AFormation::item(const unsigned int row, const unsigned int column, const unsigned int levelIndex) const
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

void AFormation::item(const unsigned int row, const unsigned int column, const unsigned int levelIndex, const TData& value)
{
    if (!_data)
        return;
    
    if (row > _height)
        return;
    
    if (column > _width)
        return;
    
    if (levelIndex > _levelsCount)
        return;
    
    int skip = _width * _height * levelIndex;
    _data[skip + row * _width + column] = value;
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
