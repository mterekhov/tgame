#ifndef ENGINE_ATEXTURE_H
#define ENGINE_ATEXTURE_H

//=============================================================================

#include <string>

#include "AImage.h"

//=============================================================================

namespace spcTGame
{
    
//==============================================================================
    
/**
    @class ATexture
    Class for texture holding and all it's attributes
*/
class ATexture
{
public:
    /// Default Constructor
    ATexture();
    
    ATexture(const ATexture& tex);

    /// Constructor
    /// @param const AImage& - image for initialization of texture
    ATexture(const AImage& image);
    
    /// Default destructor
    ~ATexture();
    
    /// Initialize texture
    /// @param AImage& - init texture with image
    /// @return TBool - true if everything is ok, otherwise false
    TBool atInit(const AImage& image);
    
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
    
    const std::string& atName() const;

    /// Setup minification filter
    /// @param const TUint - minification filter
    void atMinFilter(const TUint min);

    /// Setup magnification filter
    /// @param const TUint - magnification filter
    void atMagFilter(const TUint mag);
    
    /// Setup tile parameter
    /// @param const TBool - should we tile all the surface with this texture
    void atRepeat(const TBool r);
    
    /// Setup mipmap generation
    /// @param const TBool - should we generate mip map levels for this texture 
    void atMipMapping(const TBool m);
    
    /// Setup texture name
    /// @param const std::string& - name for the texture
    void atName(const std::string& name);

    /// Texture id
    TUint public_id;
private:
    /// Destroy all thge data in textyure object
    void atDestroy();
    
    /// Init texture from tga file
    /// @param const std::string& - relative file name of tga image
    /// @return TBool - true if everything is ok, otherwise false
    TBool atInitFromTga(const std::string& fileName);
    
    /// Apply all the filter to current texture id
    void atDefineFilters();
    
    void defineImageType(const int bytePP);
    
    /// Find out the nearest power of 2 size for texture
    /// @param const TWidth - width of original image
    /// @param const THeight - height of original image
    void atLocateSize(const TWidth width, const THeight height);
    
    /// Correct data due to texture sizes
    /// @param const AImage& - image to correct
    /// @param Tubyte* - pointer where the final data will be stored
    void atCorrectData(const AImage& image, TData* data);

    /// Texture name
    std::string _name;
    
    /// Texture id
    TUint _id;
    
    /// Texture type(in case of color scheme)
    TUint _type;
    
    /// Number of bytes per pixel component
    TUint _pixelSize;
    
    /// Texture width
    TWidth _width;             //  texture width(usualy pow of 2)
    
    /// Texture height
    THeight _height;           //  texture height(usualy pow of 2)
    
    /// Original image width
    TWidth _imageWidth;        //  width of source image
    
    /// Original image height
    THeight _imageHeight;      //  height of source image

    /// Minification filter
    TUint _minFilter;
    
    /// Magnification filter
    TUint _magFilter;
    
    /// Tile parameter
    TBool _repeat;
    
    /// Mipmap generation parameter
    TBool _mipMaping;
};

//=============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  ENGINE_ATEXTURE_H
