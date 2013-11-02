#include "ADataLiner.h"

//==============================================================================

ADataLiner::ADataLiner()
{
}

//==============================================================================

ADataLiner::~ADataLiner()
{
}

//==============================================================================

void ADataLiner::pushPoint(const APoint& coords)
{
    _coordsList.push_back(coords);
}

//==============================================================================

void ADataLiner::pushUVPoint(const APoint2D& point)
{
    _uvList.push_back(point);
}

//==============================================================================

void ADataLiner::pushNormalPoint(const APoint& point)
{
    _normalsList.push_back(point);
}

//==============================================================================

void ADataLiner::pushCoordPointList(const TPointsList& pointsList)
{
    _coordsList.insert(_coordsList.end(), pointsList.begin(), pointsList.end());
}

//==============================================================================

void ADataLiner::pushUVPointList(const TPoints2DList& pointsList)
{
    _uvList.insert(_uvList.end(), pointsList.begin(), pointsList.end());
}

//==============================================================================

void ADataLiner::pushNormalPointList(const TPointsList& pointsList)
{
    _normalsList.insert(_normalsList.end(), pointsList.begin(), pointsList.end());
}

//==============================================================================

EIntegrity ADataLiner::checkIntegrity() const
{
    EIntegrity result = EINTEGRITY_OK;
    
    TUlong coordsSize = _coordsList.size();
    if (!coordsSize)
        return EINTEGRITY_OK;
    
    TUlong uvSize = _uvList.size();
    if (uvSize)
        if (coordsSize != uvSize)
            return EINTEGRITY_INCONSISTENT;
    
    TUlong normalsSize = _normalsList.size();
    if (normalsSize)
        if (coordsSize != normalsSize)
            return EINTEGRITY_INCONSISTENT;

    return result;
}

//==============================================================================

TUint ADataLiner::pointsCount() const
{
    return numberOfFloatValues() / arrayStride();
}

//==============================================================================

TUlong ADataLiner::numberOfFloatValues() const
{
    TUlong coordsSize = _coordsList.size();
    if (!coordsSize)
        return 0;
    
    TUlong uvSize = _uvList.size();
    TUlong normalsSize = _normalsList.size();
    TUlong sizer = 3 * coordsSize + 2 * uvSize + 3 * normalsSize;
    
    return sizer;
}

//==============================================================================

TUint ADataLiner::arrayStride() const
{
    if (checkIntegrity() != EINTEGRITY_OK)
        return 0;

    TUint result = 0;

    if (!_coordsList.size())
        return 0;
    result += 3;

    if (_uvList.size())
        result += 2;

    if (_normalsList.size())
        result += 3;

    return result;
}

//==============================================================================

TBool ADataLiner::generateArray(TFloat* resultArray) const
{
    if (!resultArray)
        return false;

    if (checkIntegrity() != EINTEGRITY_OK)
        return false;
    
    TUlong stride = arrayStride();
    TUlong sizer = numberOfFloatValues();
    if (!sizer)
        return false;
    
    memset(resultArray, 0, sizer * sizeof(TFloat));
    
    for (TUint i = 0; i < _coordsList.size(); i++)
    {
        APoint point = _coordsList[i];
        resultArray[stride * i] = point.x;
        resultArray[stride * i + 1] = point.y;
        resultArray[stride * i + 2] = point.z;

        if (_uvList.size())
        {
            APoint2D point2d = _uvList[i];
            resultArray[stride * i + 3] = point2d.x;
            resultArray[stride * i + 4] = point2d.y;
        }
        
        if (_normalsList.size())
        {
            point = _normalsList[i];
            resultArray[stride * i + 5] = point.x;
            resultArray[stride * i + 6] = point.y;
            resultArray[stride * i + 7] = point.z;
        }
    }
    
    return true;
}
