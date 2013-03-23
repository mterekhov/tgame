#include "atexture.h"
#include "atga.h"

#include <OpenGL/gl.h>

//=============================================================================

ATexture::ATexture() : m_id(0), m_type(GL_RGBA), m_minFilter(GL_LINEAR), m_magFilter(GL_LINEAR),
                       m_pixelSize(GL_UNSIGNED_BYTE), m_width(0), m_height(0), m_repeat(true),
                       m_mipMaping(false), m_name("undefined"), m_imageWidth(0), m_imageHeight(0)
{
    glGenTextures(1, &m_id);
}

//=============================================================================

ATexture::ATexture(AImage& image) : m_id(0), m_type(GL_RGBA), m_minFilter(GL_LINEAR), m_magFilter(GL_LINEAR),
                       m_pixelSize(GL_UNSIGNED_BYTE), m_width(0), m_height(0), m_repeat(true),
                       m_mipMaping(false), m_name("undefined"), m_imageWidth(0), m_imageHeight(0)
{
    glGenTextures(1, &m_id);
    atInit(image);
}

//=============================================================================

ATexture::~ATexture()
{
    atDestroy();
}

//=============================================================================

void ATexture::atDestroy()
{
    if (m_id)
    {
        glDeleteTextures(1, &m_id);
        m_id = 0;
    }
}

//=============================================================================

void ATexture::defineImageType(const int bytePP)
{
    switch (bytePP)
    {
        case 3:
            m_type = GL_RGB;
        break;
        
        case 4:
            m_type = GL_RGBA;
        break;
        
    }
}

//=============================================================================

bool ATexture::atInit(const std::string& fileName)
{
    TUint dotPos = fileName.rfind(".");
    std::string ext = &fileName[++dotPos];
    
    bool res = true;
    if (ext == "tga")
        res = atInitFromTga(fileName);
        
    if (!res)
        return false;

    return true;    
}

//=============================================================================

bool ATexture::atInit(AImage& image)
{
    defineImageType(image.aiBytePerPixel());
    
    //  extend image data up to nearest power of two
    atLocateSize(image.aiWidth(), image.aiHeight());    
    atBind();
    atDefineFilters();
    m_name = image.aiName();

    if ((m_width != image.aiWidth()) || (m_height != image.aiHeight()))
    {
        TData* data = new TData[m_width * m_height * image.aiBytePerPixel()];
        atCorrectData(image, data);
        glTexImage2D(GL_TEXTURE_2D, 0, m_type, m_width, m_height, 0, m_type, m_pixelSize, data);
    }
    else
    {
        const TData* data = image.aiData();
        glTexImage2D(GL_TEXTURE_2D, 0, m_type, m_width, m_height, 0, m_type, m_pixelSize, data);
    }
        
    return true;
}

//=============================================================================

bool ATexture::atInitFromTga(const std::string& fileName)
{
    ATga tga(fileName);

    if (!atInit(tga))
        return false;
    
    return true;
}

//=============================================================================

void ATexture::atDefineFilters()
{
    if (!m_repeat)
    {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    else
    {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    glTexParameterf(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, m_mipMaping);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_magFilter);
}
    
//=============================================================================

void ATexture::atLocateSize(const TWidth width, const THeight height)
{
    THeight correctHeight = 1;
    TWidth correctWidth = 1;
    while(true)
    {
        if (correctHeight >= height)
            break;
        correctHeight = correctHeight << 1;
    };
    while(true)
    {
        if (correctWidth >= width)
            break;
        correctWidth = correctWidth << 1;
    };
    
    m_imageWidth = width;
    m_imageHeight = height;
    
    m_height = correctHeight;
    m_width = correctWidth;
}

//=============================================================================

void ATexture::atBind() const
{
    glBindTexture(GL_TEXTURE_2D, m_id);
}

//=============================================================================

void ATexture::atUnBind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

//=============================================================================

const TWidth ATexture::atImageWidth() const
{
    return m_imageWidth;
}

//=============================================================================

const THeight ATexture::atImageHeight() const
{
    return m_imageHeight;
}
    
//=============================================================================

const TWidth ATexture::atWidth() const
{
    return m_width;
}

//=============================================================================

const THeight ATexture::atHeight() const
{
    return m_height;
}
    
//=============================================================================

void ATexture::atCorrectData(const AImage& image, TData* data)
{
    const TData* originalData = image.aiData();
    TUShort bytepp = image.aiBytePerPixel();
    
    for (TUint i = 0; i < m_height; i++)
    {
        for (TUint j = 0; j < m_width; j++)
        {
            TUint index = bytepp * (m_width * i + j);
            if ((j >= m_imageWidth) || (i >= m_imageHeight))
            {
                memset(&data[index], 0, bytepp);
            }
            else
            {
                TUint index2 = bytepp * (m_imageWidth * i + j);
                memcpy(&data[index], &originalData[index2], bytepp);
            }
        }
    }
}

//=============================================================================

const GLenum ATexture::atType() const
{
    return m_type;
}

//=============================================================================

void ATexture::atMinFilter(const GLuint min)
{
    m_minFilter = min;
}

//=============================================================================

void ATexture::atMagFilter(const GLuint mag)
{
    m_magFilter = mag;
}

//=============================================================================

void ATexture::atRepeat(const bool r)
{
    m_repeat = r;
}

//=============================================================================

void ATexture::atMipMapping(const bool m)
{
    m_mipMaping = m;
}

//=============================================================================

void ATexture::atName(const std::string& name)
{
    m_name = name;
}
