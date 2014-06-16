#ifndef SPCTGAME_ATEXTUREMANAGER_H
#define SPCTGAME_ATEXTUREMANAGER_H

//==============================================================================

#include <map>
#include <string>

#include "atexture.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
typedef std::map<TString, ATexture> TTexturesList;
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
    
    ATexture& createTextureFromTGA(const TString& filePath);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif
