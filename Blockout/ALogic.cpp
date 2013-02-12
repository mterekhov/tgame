#include "ALogic.h"

//==============================================================================

ALogic::ALogic(const unsigned int width, const unsigned int height, const unsigned int levelIndex)
{
    _data = new AData(width, height, levelIndex);
}

//==============================================================================

ALogic::~ALogic()
{
    delete _data;
}

//==============================================================================

bool ALogic::collisions(const AData* forCompare, const APoint& pos)
{
    if (!_data->doesInbounds(forCompare))
        return false;
    
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
