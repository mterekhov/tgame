#include "ATextureManager.h"
#include "ATga.h"
#include "AOpenGLState.h"

//==============================================================================

const ATexture ATextureManager::zeroTexture;

//==============================================================================

ATextureManager::ATextureManager()
{
}

//==============================================================================

ATextureManager::~ATextureManager()
{
}

//==============================================================================

ATexture& ATextureManager::atCreateTextureFromTGA(const std::string& filePath)
{
    ATga tgaFile(filePath);
    
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->textureEnable();
    
    ATexture newTexture(*tgaFile.atImage());
    _textureList[newTexture.atName()] = newTexture;
    
    int err = glGetError();
    
    return _textureList[newTexture.atName()];
}
