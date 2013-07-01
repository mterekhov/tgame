#include "ATga.h"

//=============================================================================

ATga::ATga(const std::string& fileName, bool headersOnly) : m_identity(0), m_image(0)
{
    FILE* tga_file = fopen(fileName.c_str(), "rb");
    if (!tga_file)
        throw;

    STGAHeader tgaHeader = {0};
    if (!atReadHeaders(tga_file, tgaHeader))
        throw;

    TData* data = 0;
    if (!headersOnly)
    {
        TBytepp bytepp = 0;
        switch(tgaHeader.fileHeader.imageType)
        {
            case TGA_TRUE_COLOR_IMAGE:
                bytepp = tgaHeader.imageHeader.bitpp / 8;
            break;
        }

        TUint data_size = tgaHeader.imageHeader.width * tgaHeader.imageHeader.height * bytepp;
        data = new TData[data_size];
        memset(data, 0, data_size);
        if (!atReadData(data, tga_file, data_size, tgaHeader))
            throw;
    }

    fclose(tga_file);

    m_image = new AImage(fileName, data, tgaHeader.imageHeader.width, tgaHeader.imageHeader.height, tgaHeader.imageHeader.bitpp);
    
    if (data)
        delete [] data;
}

//=============================================================================

ATga::~ATga()
{
    if (m_identity)
        delete [] m_identity;
    
    if (m_image)
        delete m_image;
}

//=============================================================================

const AImage* ATga::atImage() const
{
    return m_image;
}

//=============================================================================

bool ATga::atReadHeaders(FILE* tga_file, STGAHeader& tgaHeader)
{
    if (!tga_file)
        return false;

    fread(&tgaHeader.fileHeader.identityLength, 1, 1, tga_file);
    fread(&tgaHeader.fileHeader.paleteType, 1, 1, tga_file);
    fread(&tgaHeader.fileHeader.imageType, 1, 1, tga_file);

    fread(&tgaHeader.paletteHeader.offset, 2, 1, tga_file);
    fread(&tgaHeader.paletteHeader.size, 2, 1, tga_file);
    fread(&tgaHeader.paletteHeader.bitpp, 1, 1, tga_file);

    fread(&tgaHeader.imageHeader.x_coord, 2, 1, tga_file);
    fread(&tgaHeader.imageHeader.y_coord, 2, 1, tga_file);
    fread(&tgaHeader.imageHeader.width, 2, 1, tga_file);
    fread(&tgaHeader.imageHeader.height, 2, 1, tga_file);
    fread(&tgaHeader.imageHeader.bitpp, 1, 1, tga_file);
    fread(&tgaHeader.imageHeader.image_descriptor, 1, 1, tga_file);

    if (tgaHeader.fileHeader.identityLength)
    {
        m_identity = new TData[tgaHeader.fileHeader.identityLength];
        fread(m_identity, sizeof(TData), tgaHeader.fileHeader.identityLength, tga_file);
    }

    return true;
}

//=============================================================================

bool ATga::atReadData(TData* data, FILE* tga_file, const TUint data_size, const STGAHeader& tgaHeader)
{
    if (!tga_file)
        return false;

    fread(data, sizeof(TData), data_size, tga_file);
    
    if (!atRGB2BGR(data, tgaHeader))
        return false;
    
    if (!atFlipOver(data, tgaHeader))
        return false;

    return true;
}

//=============================================================================

bool ATga::atRGB2BGR(TData* data, const STGAHeader& tgaHeader)
{
    TData* tmpData = data;
    if (!tmpData)
        return true;

    TUint bytepp = tgaHeader.imageHeader.bitpp / 8;
    for (TUint i = 0; i < tgaHeader.imageHeader.height; i++)
    {
        for (TUint j = 0; j < tgaHeader.imageHeader.width; j++)
        {
            TUint index = bytepp * (i * tgaHeader.imageHeader.width + j);
            TData tmp = tmpData[index];
            tmpData[index] = tmpData[index + 2];
            tmpData[index + 2] = tmp;
        }
    }

    return true;
}

//=============================================================================

bool ATga::atFlipOver(TData* data, const STGAHeader& tgaHeader)
{
    TData* tmpData = data;
    if (!tmpData)
        return true;

    TUint bytepp = tgaHeader.imageHeader.bitpp / 8;
    TData* tmp = new TData[bytepp * tgaHeader.imageHeader.width];
    for (TUint i = 0; i < tgaHeader.imageHeader.height / 2; i++)
    {
        TUint index = bytepp * i * tgaHeader.imageHeader.width;
        TUint index2 = bytepp * (tgaHeader.imageHeader.height - i - 1) * tgaHeader.imageHeader.width;

        memcpy(tmp, &tmpData[index], bytepp * tgaHeader.imageHeader.width);
        memcpy(&tmpData[index], &tmpData[index2], bytepp * tgaHeader.imageHeader.width);
        memcpy(&tmpData[index2], tmp, bytepp * tgaHeader.imageHeader.width);
    }

    delete tmp;

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
