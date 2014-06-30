#include "atexturemanager.h"
#include "atga.h"
#include "aopenglstate.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ATexture ATextureManager::_zeroTexture;

//==============================================================================

ATexture& ATextureManager::zeroTexture()
{
    return _zeroTexture;
}

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
