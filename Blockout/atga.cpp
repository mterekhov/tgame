#include "ATga.h"

//=============================================================================

ATga::ATga(const std::string& filePath, bool headersOnly) : _identity(0), _image(0)
{
    TUint dotPos = filePath.rfind(".");
    std::string ext = &filePath[++dotPos];

    if (ext != "tga")
        throw;

    FILE* tga_file = fopen(filePath.c_str(), "rb");
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

    dotPos = filePath.rfind("/");
    std::string fileName = &filePath[++dotPos];
    _image = new AImage(fileName, data, tgaHeader.imageHeader.width, tgaHeader.imageHeader.height, tgaHeader.imageHeader.bitpp);
    
    if (data)
        delete [] data;
}

//=============================================================================

ATga::~ATga()
{
    if (_identity)
        delete [] _identity;
    
    if (_image)
        delete _image;
}

//=============================================================================

const AImage* ATga::atImage() const
{
    return _image;
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
        _identity = new TData[tgaHeader.fileHeader.identityLength];
        fread(_identity, sizeof(TData), tgaHeader.fileHeader.identityLength, tga_file);
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

STGAHeader ATga::atCreateTGAHeader(const AImage& image)
{
    STGAHeader header = {0};
    
    header.imageHeader.bitpp = image.aiBitPerPixel();
    header.imageHeader.width = image.aiWidth();
    header.imageHeader.height = image.aiHeight();

    return header;
}

//=============================================================================

bool ATga::atSave(const std::string& filePath, const AImage& image)
{
    STGAHeader header = atCreateTGAHeader(image);

    TUint sizer = header.imageHeader.width * header.imageHeader.height * header.imageHeader.bitpp / 8;
    TData* data = new TData[sizer];
    memset(data, 0, sizer);
    memcpy(data, image.aiData(), sizer);

    TData byte_1 = 0;
    TUShort byte_2 = 0;
    FILE* filo = fopen(filePath.c_str(), "wb");
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

    byte_2 = image.aiWidth();
    fwrite(&byte_2, 2, 1, filo); //  image width
    byte_2 = image.aiHeight();
    fwrite(&byte_2, 2, 1, filo); //  image height

    byte_1 = image.aiBitPerPixel();
    fwrite(&byte_1, 1, 1, filo); //  byte per pixel
    byte_1 = 0;
    fwrite(&byte_1, 1, 1, filo); //  image property
    
    if (!atRGB2BGR(data, header))
        return false;
    
    if (!atFlipOver(data, header))
        return false;

    if (fwrite(data, sizer, 1, filo) != 1) //  image data
        return false;

    delete [] data;
    fclose(filo);

	return true;
}
