#include "ATextureManager.h"
#include "ATga.h"
#include "AOpenGLState.h"

//==============================================================================

namespace spcTGame
{
    
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

ATexture& ATextureManager::createTextureFromTGA(const TString& filePath)
{
    ATga tgaFile(filePath);
    
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->textureEnable();
    
    ATexture newTexture(*tgaFile.image());
    _textureList[newTexture.name()] = newTexture;

    oglState->textureDisable();

    return _textureList[newTexture.name()];
}

//==============================================================================
    
}   //  namespace spcTGame
