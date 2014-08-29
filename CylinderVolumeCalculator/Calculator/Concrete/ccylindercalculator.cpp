#include "ccylindercalculator.h"
#include "../../ccylinderdata.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Calculator
{
/**********************************************************/
void ConvertRadiusToFeet(CCylinderData& data)
{
    if (data.GetRadiusUnit() == "Feet") { return; }
    data.SetRadius(data.GetRadius() / 12);
}
/**********************************************************/
void ConvertHeightToFeet(CCylinderData& data)
{
    if (data.GetHeightUnit() == "Feet") { return; }
    data.SetHeight(data.GetHeight() / 12);
}
/**********************************************************/
void Round(CCylinderData& data)
{
    double unrounded = (M_PI * (data.GetRadius() * data.GetRadius()) * data.GetHeight()) * 100;
    data.SetVolume(floor(unrounded + .5) / 100);
}
/**********************************************************/
}
/**********************************************************/
CCylinderCalculator::CCylinderCalculator()
{
}
/**********************************************************/
void CCylinderCalculator::DoCalculate(CCylinderData& data) const
{
    Calculator::ConvertRadiusToFeet(data);
    Calculator::ConvertHeightToFeet(data);
    Calculator::Round(data);
}
/**********************************************************/
