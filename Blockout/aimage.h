#ifndef ENGINE_AIMAGE_H
#define ENGINE_AIMAGE_H

//=============================================================================

#include "BlockoutTypes.h"

#include <string>

//=============================================================================

/**
    @class AImage
    image class
*/
class AImage
{
public:
    AImage(const std::string& imageName, TData* data, const TWidth width,
            const THeight height, const TBitpp bitpp);
    
    /// default destructor
    virtual ~AImage();
    
    /// Get data container for image data
    /// @return const ASRAM* - pointer to data. Does not change class object
    const TData* aiData() const;
    
    /// Get image width
    /// @return const TWidth - width of image. Does not change class object
    const TWidth aiWidth() const;

    /// Get image height
    /// @return const THeight - height of image. Does not change class object
    const THeight aiHeight() const;

    /// Get image byte per pixel
    /// @return const TBytepp - byte per pixel. Does not change class object
    const TBytepp aiBytePerPixel() const;

    /// Get image bit per pixel
    /// @return const TBitpp - bit per pixel. Does not change class object
    const TBitpp aiBitPerPixel() const;

    /// Get image name
    /// @return const std::string& - image name. Does not change class object
    const std::string& aiName() const;
    
protected:
    /// Smart pointer to image data container
    TData* m_pData;
    
    /// Image width
    TWidth m_width;
    
    /// Image height
    THeight m_height;
    
    /// Image bytes per pixel
    TBytepp m_bytePerPixel;
    
    /// Image bit per pixel
    TBitpp m_bitPerPixel;
    
    /// Image name
    std::string m_name;
};

//=============================================================================

#endif  //  ENGINE_AIMAGE_H
