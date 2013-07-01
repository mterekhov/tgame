#ifndef ENGINE_ATEXTUREMANAGER_H
#define ENGINE_ATEXTUREMANAGER_H

//==============================================================================

#include <map>
#include <string>

#include "atexture.h"

//==============================================================================

typedef std::map<std::string, ATexture> TTexturesList;
typedef TTexturesList::iterator TTexturesListIter;
typedef TTexturesList::const_iterator TTexturesListConstIter;

//==============================================================================

class ATextureManager
{
private:
    TTexturesList _textureList;

    bool atClearAllTextures(TTexturesList& textureList);

public:
    static const ATexture zeroTexture;

    ATextureManager();
    ~ATextureManager();
    
    ATexture& atCreateTextureFromTGA(const std::string& filePath);
};

//==============================================================================

#endif
