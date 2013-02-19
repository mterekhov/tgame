#ifndef SPCBAIKAL_ATEXTURE_H
#define SPCBAIKAL_ATEXTURE_H

//=============================================================================

#include <string>

#include "aimage.h"

//=============================================================================

/**
    @class ATexture
    Class for texture holding and all it's attributes
*/
class ATexture
{
public:
    /// Default Constructor
    ATexture();

    /// Constructor
    /// @param const AImage& - image for initialization of texture
    ATexture(AImage& image);
    
    /// Default destructor
    ~ATexture();
    
    /// Initialize texture
    /// @param const std::string& - file name of image in tga format
    /// @return bool - true if everything is ok, otherwise false
    bool atInit(const std::string& fileName);
    
    /// Initialize texture
    /// @param AImage& - init texture with image
    /// @return bool - true if everything is ok, otherwise false
    bool atInit(AImage& image);
    
    /// Bind texture
    void atBind() const;
    
    /// Unbin texture
    void atUnBind() const;
    
    /// Get image width
    /// @return const TWidth - width of original image from tga file
    const TWidth atImageWidth() const;

    /// Get image height
    /// @return const THeight - height of original image from tga file
    const THeight atImageHeight() const;    

    /// Get texture width
    /// @return const TWidth - width of texture
    const TWidth atWidth() const;

    /// Get texture height
    /// @return const THeight - height of texture
    const THeight atHeight() const;
    
    /// Get type of texture
    /// @return const GLenum - type of texture. Means GL_RGBA, GL_RGB or GL_BGR
    const TUint atType() const;

    /// Setup minification filter
    /// @param const TUint - minification filter
    void atMinFilter(const TUint min);

    /// Setup magnification filter
    /// @param const TUint - magnification filter
    void atMagFilter(const TUint mag);
    
    /// Setup tile parameter
    /// @param const bool - should we tile all the surface with this texture
    void atRepeat(const bool r);
    
    /// Setup mipmap generation
    /// @param const bool - should we generate mip map levels for this texture 
    void atMipMapping(const bool m);
    
    /// Setup texture name
    /// @param const std::string& - name for the texture
    void atName(const std::string& name);

private:
    /// Destroy all thge data in textyure object
    void atDestroy();
    
    /// Init texture from tga file
    /// @param const std::string& - relative file name of tga image
    /// @return bool - true if everything is ok, otherwise false
    bool atInitFromTga(const std::string& fileName);
    
    /// Apply all the filter to current texture id
    void atDefineFilters();
    
    /// Find out the nearest power of 2 size for texture
    /// @param const TWidth - width of original image
    /// @param const THeight - height of original image
    void atLocateSize(const TWidth width, const THeight height);
    
    /// Correct data due to texture sizes
    /// @param const AImage& - image to correct
    /// @param Tubyte* - pointer where the final data will be stored
    void atCorrectData(const AImage& image, TData* data);

    /// Texture name
    std::string m_name;
    
    /// Texture id
    TUint m_id;
    
    /// Texture type(in case of color scheme)
    TUint m_type;
    
    /// Number of bytes per pixel component
    TUint m_pixelSize;
    
    /// Texture width
    TWidth m_width;             //  texture width(usualy pow of 2)
    
    /// Texture height
    THeight m_height;           //  texture height(usualy pow of 2)
    
    /// Original image width
    TWidth m_imageWidth;        //  width of source image
    
    /// Original image height
    THeight m_imageHeight;      //  height of source image

    /// Minification filter
    TUint m_minFilter;
    
    /// Magnification filter
    TUint m_magFilter;
    
    /// Tile parameter
    bool m_repeat;
    
    /// Mipmap generation parameter
    bool m_mipMaping;
};

//=============================================================================

#endif  //  SPCBAIKAL_ATEXTURE_H
