#include "../Abstract/icalculator.h"
#include "../../ccylinderdata.h"
/**********************************************************/
void ICalculator::Calculate(CCylinderData& data) const
{
    CCylinderData newData(data);
    DoCalculate(newData);
    data.SetVolume(newData.GetVolume());
}
/**********************************************************/
