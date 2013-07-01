#include "ATextureManager.h"

//==============================================================================

ATextureManager::ATextureManager()
{
}

//==============================================================================

ATextureManager::~ATextureManager()
{
}

//==============================================================================

ATexture* ATextureManager::atCreateTexture(const std::string& textureFileName)
{
    ATexture* newTexture = new ATexture(textureFileName);
    m_textureList.push_back(tex);
}
