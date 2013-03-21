#include "atga.h"

//=============================================================================

ATga::ATga(const std::string& fileName, bool headersOnly) : AImage(fileName)
{
    FILE* tga_file = fopen(fileName.c_str(), "rb");
    if (!tga_file)
        throw;

    if (!atReadHeaders(tga_file))
        throw;

    if (!headersOnly)
        if (!atReadData(tga_file))
            throw;

    fclose(tga_file);
}

//=============================================================================

ATga::~ATga()
{
    if (m_identity)
        delete [] m_identity;
    
    if (m_pData)
        delete [] m_pData;
}

//=============================================================================

bool ATga::atReadHeaders(FILE* tga_file)
{
    if (!tga_file)
        return false;

    SFileHeader file_header = {0};
    fread(&file_header.identityLength, 1, 1, tga_file);
    fread(&file_header.paleteType, 1, 1, tga_file);
    fread(&file_header.imageType, 1, 1, tga_file);

    SPaletteHeader palette_header = {0};
    fread(&palette_header.offset, 2, 1, tga_file);
    fread(&palette_header.size, 2, 1, tga_file);
    fread(&palette_header.bitpp, 1, 1, tga_file);

    SImageHeader image_header = {0};
    fread(&image_header.x_coord, 2, 1, tga_file);
    fread(&image_header.y_coord, 2, 1, tga_file);
    fread(&image_header.width, 2, 1, tga_file);
    fread(&image_header.height, 2, 1, tga_file);
    fread(&image_header.bitpp, 1, 1, tga_file);
    fread(&image_header.image_descriptor, 1, 1, tga_file);

    if (file_header.identityLength)
    {
        m_identity = new TData[file_header.identityLength];
        fread(m_identity, sizeof(TData), file_header.identityLength, tga_file);
    }

    switch(file_header.imageType)
    {
        case TGA_TRUE_COLOR_IMAGE:
            m_bitPerPixel = image_header.bitpp;
            m_bytePerPixel = m_bitPerPixel / 8;
        break;

        case TGA_NOT_IMAGE_DATA:
        case TGA_PALETTE_IMAGE:
        case TGA_BLACK_WHITE_IMAGE:
        case TGA_RLE_PALETTE_IMAGE:
        case TGA_RLE_TRUE_COLOR_IMAGE:
        case TGA_RLE_BLACK_WHITE_IMAGE:
            return false;
        break;
    }

    m_width = image_header.width;
    m_height = image_header.height;

    return true;
}

//=============================================================================

bool ATga::atReadData(FILE* tga_file)
{
    if (!tga_file)
        return false;

    TUint data_size = m_width * m_height * m_bytePerPixel;
    m_pData = new TData[data_size];
    fread(m_pData, sizeof(TData), data_size, tga_file);
    if (!aiRGB2BGR())
        return false;
    if (!aiFlipOver())
        return false;

    return true;
}

//=============================================================================

bool ATga::atSave(const std::string& fileName)
{
    TData* data = m_pData;
	if (!data)
		return false;

    TData byte_1 = 0;
    TUShort byte_2 = 0;
    FILE* filo = fopen(fileName.c_str(), "wb");
    if (!filo)
        return false;

    fwrite(&byte_1, 1, 1, filo); //  identity length
    fwrite(&byte_1, 1, 1, filo); //  palete type
    byte_1 = 2;
    fwrite(&byte_1, 1, 1, filo); //  image type
    byte_1 = 0;
    fwrite(&byte_2, 2, 1, filo); //  palete offset
    fwrite(&byte_2, 2, 1, filo); //  palete size
    fwrite(&byte_1, 1, 1, filo); //  palete bpp
    fwrite(&byte_2, 2, 1, filo); //  x coord
    fwrite(&byte_2, 2, 1, filo); //  y coord

    byte_2 = m_width;
    fwrite(&byte_2, 2, 1, filo); //  image width
    byte_2 = m_height;
    fwrite(&byte_2, 2, 1, filo); //  image height

    byte_1 = m_bitPerPixel;
    fwrite(&byte_1, 1, 1, filo); //  byte per pixel
    byte_1 = 0;
    fwrite(&byte_1, 1, 1, filo); //  image property

    if (!aiRGB2BGR())
        return false;
    if (!aiFlipOver())
        return false;

    if (fwrite(data, m_bytePerPixel * m_width * m_height, 1, filo) != 1) //  image data
        return false;

    if (!aiFlipOver())
        return false;
    if (!aiRGB2BGR())
        return false;

    fclose(filo);

	return true;
}
