#include "ALogic.h"

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
    
//    for (int l = 0; l < forCompare->levelsCount(); l++)
//    {
//        for (int i = 0; i < forCompare->height(); i++)
//        {
//            for (int j = 0; j < forCompare->width(); j++)
//            {
//                TBool first = forCompare->item(i, j, l);
//                
//                unsigned int x = ;
//                unsigned int y = ;
//                unsigned int z = ;
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
