#ifndef SPCBAIKAL_ATGA_H
#define SPCBAIKAL_ATGA_H

//=============================================================================

#include <stdio.h>

#include "aimage.h"

//=============================================================================

/// Length of comments in tga file
typedef TData TIdentityLength;

/// Palette type in tga file
typedef TData TPaletteType;

/// Type of image in tga file
typedef TData TImageType;

/// Palette offset in tga file
typedef TUShort TPaletteOffset;

/// Palette size in tga file
typedef TUShort TPaletteSize;

//=============================================================================

/// @struct SFileHeader
/// Header of tga file
struct SFileHeader
{
    /// Length of comments
    TIdentityLength identityLength;
    
    /// Palette type
    TPaletteType paleteType;
    
    /// Type of image
    TImageType imageType;
};

/// @struct SPaletteHeader
/// Palette header of tga file
struct SPaletteHeader
{
    /// Offset of palette
    TPaletteOffset offset;
    
    /// Size of palette
    TPaletteSize size;
    
    /// Bits per pixel
    TBitpp bitpp;
};

/// @struct SImageHeader
/// Image header
struct SImageHeader
{
    /// X coord
    TUShort x_coord;
    
    /// Y coord
    TUShort y_coord;
    
    /// Width
    TWidth width;
    
    /// Height
    THeight height;
    
    /// Bits per pixel
    TBitpp bitpp;
    
    /// ???
    TData image_descriptor;
};

//=============================================================================

/// Size of SFileHeader structure in bytes
#define FILE_HEADER_SIZE 3

/// Size of SPaletteHeader structure in bytes
#define PALETTE_HEADER_SIZE 5

/// Size of SImageHeader structure in bytes
#define IMAGE_HEADER_SIZE 10

//=============================================================================

/**
    Type of image in TGA file format
*/
enum EImageType
{
    /// No image data in file
    TGA_NOT_IMAGE_DATA,

    /// Palette image
    TGA_PALETTE_IMAGE,

    /// True-color image
    TGA_TRUE_COLOR_IMAGE,

    /// Gray-scale image
    TGA_BLACK_WHITE_IMAGE,

    /// Palette image with run-length encoding
    TGA_RLE_PALETTE_IMAGE = 9,

    /// True-color image with run-length encoding
    TGA_RLE_TRUE_COLOR_IMAGE,

    /// Gray-scale image with run-length encoding
    TGA_RLE_BLACK_WHITE_IMAGE
};

//=============================================================================
/**
    @class ATga
    API to work with TGA files format
*/
class ATga : public AImage
{
public:
    /// Constructor
    /// @param const std::string& - file name of tga image
    /// @param bool - should we read all the image data or only it's header
    /// @return const std::string& - relative file name
	ATga(const std::string& filename, bool headersOnly = false);

    /// Default destructor
	virtual ~ATga();

    /// Save current image data into file
    /// @param const std::string& - full path to file to save to
    /// @return bool - true if everything is ok, otherwise false
    bool atSave(const std::string& fileName);

private:
    /// Comments in tga file. Usually it is absent
	TData* m_identity;

    /// Read image data
    /// @param FILE* - pointer to an open for binary reading file
    /// @return bool - true if everything is ok, otherwise false
	bool atReadData(FILE* tga_file);

    /// Read all the image headers
    /// @param FILE* - pointer to an open for binary reading file
    /// @return bool - true if everything is ok, otherwise false
	bool atReadHeaders(FILE* tga_file);
    
    /// Destroy all the data
	void atClearData();
};

//=============================================================================

#endif  //  SPCBAIKAL_ATGA_H