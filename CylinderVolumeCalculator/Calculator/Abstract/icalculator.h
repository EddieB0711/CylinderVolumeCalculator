#ifndef ICALCULATOR_H
#define ICALCULATOR_H

class CCylinderData;

class ICalculator
{
public:
    void Calculate(CCylinderData& data) const;
    virtual ~ICalculator() {}

private:
    virtual void DoCalculate(CCylinderData& data) const = 0;
};

#endif // ICALCULATOR_H
