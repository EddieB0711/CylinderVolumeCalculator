#include "ccylinderdata.h"
#include <utility>

CCylinderData::CCylinderData()
    : m_Index(-1),
      m_Radius(-1),
      m_RadiusUnit("Feet"),
      m_Height(-1),
      m_HeightUnit("Feet"),
      m_Volume(-1)
{
}
/**********************************************************/
CCylinderData::CCylinderData(const CCylinderData& Other)
    : m_Index(Other.m_Index),
      m_Radius(Other.m_Radius),
      m_RadiusUnit(Other.m_RadiusUnit),
      m_Height(Other.m_Height),
      m_HeightUnit(Other.m_HeightUnit),
      m_Volume(Other.m_Volume)
{
}
/**********************************************************/
CCylinderData::CCylinderData(CCylinderData&& Other)
    : m_Index(Other.m_Index),
      m_Radius(Other.m_Radius),
      m_RadiusUnit(std::move(Other.m_RadiusUnit)),
      m_Height(Other.m_Height),
      m_HeightUnit(std::move(Other.m_HeightUnit)),
      m_Volume(Other.m_Volume)
{
}
/**********************************************************/
CCylinderData& CCylinderData::operator =(CCylinderData&& Other)
{
    if (this == &Other) { return *this; }

    m_Index = Other.m_Index;
    m_Radius = Other.m_Radius;
    m_RadiusUnit = std::move(Other.m_RadiusUnit);
    m_Height = Other.m_Height;
    m_HeightUnit = std::move(Other.m_HeightUnit);
    m_Volume = Other.m_Volume;

    return *this;
}
/**********************************************************/
int CCylinderData::GetIndex() const
{
    return m_Index;
}
/**********************************************************/
void CCylinderData::SetIndex(int Index)
{
    m_Index = Index;
}
/**********************************************************/
double CCylinderData::GetRadius() const
{
    return m_Radius;
}
/**********************************************************/
void CCylinderData::SetRadius(double Radius)
{
    m_Radius = Radius;
}
/**********************************************************/
std::string CCylinderData::GetRadiusUnit() const
{
    return m_RadiusUnit;
}
/**********************************************************/
void CCylinderData::SetRadiusUnit(std::string Unit)
{
    m_RadiusUnit = Unit;
}
/**********************************************************/
double CCylinderData::GetHeight() const
{
    return m_Height;
}
/**********************************************************/
void CCylinderData::SetHeight(double Height)
{
    m_Height = Height;
}
/**********************************************************/
std::string CCylinderData::GetHeightUnit() const
{
    return m_HeightUnit;
}
/**********************************************************/
void CCylinderData::SetHeightUnit(std::string Unit)
{
    m_HeightUnit = Unit;
}
/**********************************************************/
double CCylinderData::GetVolume() const
{
    return m_Volume;
}
/**********************************************************/
void CCylinderData::SetVolume(double Volume)
{
    m_Volume = Volume;
}
/**********************************************************/
