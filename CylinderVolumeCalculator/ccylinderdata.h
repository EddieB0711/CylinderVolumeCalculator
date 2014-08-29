#ifndef CCYLINDERDATA_H
#define CCYLINDERDATA_H

#include <string>

class CCylinderData
{
public:
    CCylinderData();
    CCylinderData(const CCylinderData& Other);
    CCylinderData(CCylinderData&& Other);

    CCylinderData& operator =(CCylinderData&& Other);

    int GetIndex() const;
    void SetIndex(int Index);

    double GetRadius() const;
    void SetRadius(double Radius);

    std::string GetRadiusUnit() const;
    void SetRadiusUnit(std::string Unit);

    double GetHeight() const;
    void SetHeight(double Height);

    std::string GetHeightUnit() const;
    void SetHeightUnit(std::string Unit);

    double GetVolume() const;
    void SetVolume(double Volume);

private:
    int m_Index;
    double m_Radius;
    std::string m_RadiusUnit;
    double m_Height;
    std::string m_HeightUnit;
    double m_Volume;
};

#endif // CCYLINDERDATA_H
