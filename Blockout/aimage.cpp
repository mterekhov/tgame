#include "AImage.h"

//=============================================================================

AImage::AImage(const std::string& imageName, TData* data, const TWidth width,
            const THeight height, const TBitpp bitpp) : m_name(imageName),
                                            m_width(width), m_height(height),
                                            m_bitPerPixel(bitpp), m_bytePerPixel(bitpp / 8)
{
    TUint sizer = width * height * bitpp / 8;
    m_pData = new TData[sizer];
    memset(m_pData, 0, sizer);
    
    memcpy(m_pData, data, sizer);
}

//=============================================================================

AImage::~AImage()
{
    delete [] m_pData;
}

//=============================================================================

const TData* AImage::aiData() const
{
    return m_pData;
}

//=============================================================================

const TWidth AImage::aiWidth() const
{
    return m_width;
}

//=============================================================================

const THeight AImage::aiHeight() const
{
    return m_height;
}

//=============================================================================

const TBytepp AImage::aiBytePerPixel() const
{
    return m_bytePerPixel;
}

//=============================================================================

const TBitpp AImage::aiBitPerPixel() const
{
    return m_bitPerPixel;
}

//=============================================================================

const std::string& AImage::aiName() const
{
    return m_name;
}

//=============================================================================

