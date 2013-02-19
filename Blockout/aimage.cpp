#include "aimage.h"

//=============================================================================

AImage::AImage(const std::string& imageName, TData* data, const TWidth width,
            const THeight height, const TBitpp bitpp) : m_name(imageName), m_pData(data),
                                            m_width(width), m_height(height),
                                            m_bitPerPixel(bitpp), m_bytePerPixel(bitpp / 8)
{
}

//=============================================================================

AImage::AImage(const std::string& imageName) : m_name(imageName), m_pData(0),
                                            m_width(0), m_height(0),
                                            m_bitPerPixel(0), m_bytePerPixel(0)
{
}

//=============================================================================

AImage::~AImage()
{
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

bool AImage::aiRGB2BGR()
{
    TData* data = m_pData;
    if (!data)
        return true;

    for (TUint i = 0; i < m_height; i++)
    {
        for (TUint j = 0; j < m_width; j++)
        {
            TUint index = m_bytePerPixel * (i * m_width + j);
            TData tmp = data[index];
            data[index] = data[index + 2];
            data[index + 2] = tmp;
        }
    }

    return true;
}

//=============================================================================

bool AImage::aiFlipOver()
{
    TData* data = m_pData;
    if (!data)
        return true;

    TData* tmp = new TData[m_bytePerPixel * m_width];
    for (TUint i = 0; i < m_height / 2; i++)
    {
        TUint index = m_bytePerPixel * i * m_width;
        TUint index2 = m_bytePerPixel * (m_height - i - 1) * m_width;

        memcpy(tmp, &data[index], m_bytePerPixel * m_width);
        memcpy(&data[index], &data[index2], m_bytePerPixel * m_width);
        memcpy(&data[index2], tmp, m_bytePerPixel * m_width);
    }

    delete tmp;

    return true;
}
