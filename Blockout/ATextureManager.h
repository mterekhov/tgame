#ifndef ENGINE_ATEXTUREMANAGER_H
#define ENGINE_ATEXTUREMANAGER_H

//==============================================================================

#include <map>
#include <string>

#include "atexture.h"

//==============================================================================

typedef std::map<std::string, ATexture*> TTexturesList;
typedef TTexturesList::iterator TTexturesListIter;
typedef TTexturesList::const_iterator TTexturesListConstIter;

//==============================================================================

class ATextureManager
{
private:
    TTexturesList m_textureList;

    bool atClearAllTextures(TTexturesList& textureList);

public:
    ATextureManager();
    ~ATextureManager();
    
    ATexture* atCreateTextureFromTGA(const std::string& filePath);
};

//==============================================================================

#endif
