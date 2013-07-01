#include "ATextureManager.h"
#include "ATga.h"

//==============================================================================

ATextureManager::ATextureManager()
{
}

//==============================================================================

ATextureManager::~ATextureManager()
{
    atClearAllTextures(m_textureList);
}

//==============================================================================

ATexture* ATextureManager::atCreateTextureFromTGA(const std::string& filePath)
{
    ATga tgaFile(filePath);
    
    ATexture* newTexture = new ATexture(*tgaFile.atImage());
    m_textureList[newTexture->atName()] = newTexture;
    
    return newTexture;
}

//==============================================================================

bool ATextureManager::atClearAllTextures(TTexturesList& textureList)
{
    if (textureList.size() == 0)
        return false;

    TTexturesListConstIter iterBegin = textureList.begin();
    TTexturesListConstIter iterEnd = textureList.end();
    for (TTexturesListConstIter iter = iterBegin; iter != iterEnd; iter++)
        delete (iter->second);
    
    textureList.clear();
    
    return true;
}
