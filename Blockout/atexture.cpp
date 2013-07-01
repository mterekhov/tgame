#include "ATexture.h"
#include "ATga.h"

#include <OpenGL/gl.h>

//=============================================================================

ATexture::ATexture() : _id(0), _type(GL_RGBA), _minFilter(GL_LINEAR), _magFilter(GL_LINEAR),
                       _pixelSize(GL_UNSIGNED_BYTE), _width(0), _height(0), _repeat(true),
                       _mipMaping(false), _name("undefined"), _imageWidth(0), _imageHeight(0)
{
}

//=============================================================================

ATexture::ATexture(const AImage& image) : _id(0), _type(GL_RGBA), _minFilter(GL_LINEAR), _magFilter(GL_LINEAR),
                       _pixelSize(GL_UNSIGNED_BYTE), _width(0), _height(0), _repeat(true),
                       _mipMaping(false), _name("undefined"), _imageWidth(0), _imageHeight(0)
{
    GLenum err =  glGetError();
    glEnable(GL_TEXTURE_2D);

    err =  glGetError();
    glGenTextures(1, &_id);
    err =  glGetError();

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
    if (_id)
    {
        glDeleteTextures(1, &_id);
        _id = 0;
    }
}

//=============================================================================

void ATexture::defineImageType(const int bytePP)
{
    switch (bytePP)
    {
        case 3:
            _type = GL_RGB;
        break;
        
        case 4:
            _type = GL_RGBA;
        break;
        
    }
}

//=============================================================================

bool ATexture::atInit(const AImage& image)
{
    defineImageType(image.aiBytePerPixel());
    
    //  extend image data up to nearest power of two
    atLocateSize(image.aiWidth(), image.aiHeight());    
    atBind();
    atDefineFilters();
    _name = image.aiName();

    if ((_width != image.aiWidth()) || (_height != image.aiHeight()))
    {
        TData* data = new TData[_width * _height * image.aiBytePerPixel()];
        atCorrectData(image, data);
        glTexImage2D(GL_TEXTURE_2D, 0, _type, _width, _height, 0, _type, _pixelSize, data);
    }
    else
    {
        const TData* data = image.aiData();
        glTexImage2D(GL_TEXTURE_2D, 0, _type, _width, _height, 0, _type, _pixelSize, data);
    }
        
    return true;
}

//=============================================================================

void ATexture::atDefineFilters()
{
    if (!_repeat)
    {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    else
    {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    glTexParameterf(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, _mipMaping);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _magFilter);
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
    
    _imageWidth = width;
    _imageHeight = height;
    
    _height = correctHeight;
    _width = correctWidth;
}

//=============================================================================

void ATexture::atBind() const
{
    glBindTexture(GL_TEXTURE_2D, _id);
}

//=============================================================================

void ATexture::atUnBind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

//=============================================================================

const TWidth ATexture::atImageWidth() const
{
    return _imageWidth;
}

//=============================================================================

const THeight ATexture::atImageHeight() const
{
    return _imageHeight;
}
    
//=============================================================================

const TWidth ATexture::atWidth() const
{
    return _width;
}

//=============================================================================

const THeight ATexture::atHeight() const
{
    return _height;
}
    
//=============================================================================

void ATexture::atCorrectData(const AImage& image, TData* data)
{
    const TData* originalData = image.aiData();
    TUShort bytepp = image.aiBytePerPixel();
    
    for (TUint i = 0; i < _height; i++)
    {
        for (TUint j = 0; j < _width; j++)
        {
            TUint index = bytepp * (_width * i + j);
            if ((j >= _imageWidth) || (i >= _imageHeight))
            {
                memset(&data[index], 0, bytepp);
            }
            else
            {
                TUint index2 = bytepp * (_imageWidth * i + j);
                memcpy(&data[index], &originalData[index2], bytepp);
            }
        }
    }
}

//=============================================================================

const GLenum ATexture::atType() const
{
    return _type;
}

const std::string& ATexture::atName() const
{
    return _name;
}

//=============================================================================

void ATexture::atMinFilter(const GLuint min)
{
    _minFilter = min;
}

//=============================================================================

void ATexture::atMagFilter(const GLuint mag)
{
    _magFilter = mag;
}

//=============================================================================

void ATexture::atRepeat(const bool r)
{
    _repeat = r;
}

//=============================================================================

void ATexture::atMipMapping(const bool m)
{
    _mipMaping = m;
}

//=============================================================================

void ATexture::atName(const std::string& name)
{
    _name = name;
}
