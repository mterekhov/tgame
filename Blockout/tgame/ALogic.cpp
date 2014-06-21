#include "alogic.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ALogic::ALogic()
{
}

//==============================================================================

ALogic::~ALogic()
{
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
    
}   //  namespace spcTGame
