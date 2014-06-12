#ifndef ENGINE_ATEXTUREMANAGER_H
#define ENGINE_ATEXTUREMANAGER_H

//==============================================================================

#include <map>
#include <string>

#include "atexture.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
typedef std::map<std::string, ATexture> TTexturesList;
typedef TTexturesList::iterator TTexturesListIter;
typedef TTexturesList::const_iterator TTexturesListConstIter;

//==============================================================================

class ATextureManager
{
private:
    TTexturesList _textureList;

    TBool clearAllTextures(TTexturesList& textureList);

public:
    static const ATexture zeroTexture;

    ATextureManager();
    ~ATextureManager();
    
    ATexture& createTextureFromTGA(const std::string& filePath);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif
