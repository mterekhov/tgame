#include "AFormation.h"
#include "BlockoutDebug.h"

#include <string.h>
#include <stdio.h>

//==============================================================================

AFormation::AFormation(const unsigned int width, const unsigned int height, const unsigned int count) : _width(width), _height(height), _levelsCount(count)
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

TData AFormation::item(const unsigned int column, const unsigned int row, const unsigned int levelIndex) const
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

void AFormation::item(const unsigned int column, const unsigned int row, const unsigned int levelIndex, const TData& value)
{
    if (!_data)
    {
        loger("formation data is empty");
        return;
    }
    
    if (row > _height)
    {
        loger("out of formation height");
        return;
    }
    
    if (column > _width)
    {
        loger("out of formation width");
        return;
    }
    
    if (levelIndex > _levelsCount)
    {
        loger("out of formation levels");
        return;
    }
    
    int skip = _width * _height * levelIndex;
    int index = skip + row * _width + column;

    _data[index] = value;
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
