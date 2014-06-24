#include "alogic.h"
#include "blockoutdebug.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ALogic::ALogic(ADataStorage& dataStorage) : _dataStorage(dataStorage)
{
}

//==============================================================================

ALogic::~ALogic()
{
}

//==============================================================================

void ALogic::startGame()
{
    AFormation& newStartFormation = generateFormation();
    _dataStorage.currentFormation(newStartFormation);
}

//==============================================================================

AFormation& ALogic::generateFormation()
{
    AFormation& newFormation = _dataStorage.createFormation1();
    return newFormation;
}

//==============================================================================

TBool ALogic::collisions(const AFormation* forCompare, const APoint& pos)
{
//    if (!_data->doesInbounds(forCompare))
//        return false;
    
//    for (TInt l = 0; l < forCompare->levelsCount(); l++)
//    {
//        for (TInt i = 0; i < forCompare->height(); i++)
//        {
//            for (TInt j = 0; j < forCompare->width(); j++)
//            {
//                TBool first = forCompare->item(i, j, l);
//                
//                TUint x = ;
//                TUint y = ;
//                TUint z = ;
//                TBool second = _data->item();
//                
//                if (first == second)
//                    return true;
//            }
//        }
//    }
    
    return false;
}

//==============================================================================

void ALogic::processLogic()
{
}

//==============================================================================
    
void ALogic::processKey(const TUint buttonCode)
{
    switch (buttonCode)
    {
        case EKEYCODES_DOWN:
            moveCurrentBlockDown();
            loger("moving down");
        break;
        
        case EKEYCODES_UP:
            loger("moving up");
        break;
        
        case EKEYCODES_LEFT:
            loger("moving left");
        break;
        
        case EKEYCODES_RIGHT:
            loger("moving right");
        break;
        
        case EKEYCODES_ROTATE_X:
            loger("rotate x");
        break;
        
        case EKEYCODES_ROTATE_Y:
            loger("rotate y");
        break;
        
        case EKEYCODES_ROTATE_Z:
            loger("rotate z");
        break;
        
        case EKEYCODES_DROP_BLOCK:
            loger("drop block");
        break;
    }
}

//==============================================================================

void ALogic::moveCurrentBlockDown()
{
}

//==============================================================================

}   //  namespace spcTGame
