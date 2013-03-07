#include "ALogic.h"

//==============================================================================

ALogic::ALogic(const AFormation& initFormation) : _data(initFormation)
{
}

//==============================================================================

ALogic::~ALogic()
{
}

//==============================================================================

bool ALogic::collisions(const AFormation* forCompare, const APoint& pos)
{
//    if (!_data->doesInbounds(forCompare))
//        return false;
    
//    for (int l = 0; l < forCompare->levelsCount(); l++)
//    {
//        for (int i = 0; i < forCompare->height(); i++)
//        {
//            for (int j = 0; j < forCompare->width(); j++)
//            {
//                bool first = forCompare->item(i, j, l);
//                
//                unsigned int x = ;
//                unsigned int y = ;
//                unsigned int z = ;
//                bool second = _data->item();
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
