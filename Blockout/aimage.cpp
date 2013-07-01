#include "AImage.h"

//=============================================================================

AImage::AImage(const std::string& imageName, TData* data, const TWidth width,
            const THeight height, const TBitpp bitpp) : _name(imageName),
                                            _width(width), _height(height),
                                            _bitPerPixel(bitpp), _bytePerPixel(bitpp / 8)
{
    TUint sizer = width * height * bitpp / 8;
    _pData = new TData[sizer];
    memset(_pData, 0, sizer);
    
    memcpy(_pData, data, sizer);
}

//=============================================================================

AImage::~AImage()
{
    delete [] _pData;
}

//=============================================================================

const TData* AImage::aiData() const
{
    return _pData;
}

//=============================================================================

const TWidth AImage::aiWidth() const
{
    return _width;
}

//=============================================================================

const THeight AImage::aiHeight() const
{
    return _height;
}

//=============================================================================

const TBytepp AImage::aiBytePerPixel() const
{
    return _bytePerPixel;
}

//=============================================================================

const TBitpp AImage::aiBitPerPixel() const
{
    return _bitPerPixel;
}

//=============================================================================

const std::string& AImage::aiName() const
{
    return _name;
}

//=============================================================================

