#ifndef CCYLINDERCALCULATOR_H
#define CCYLINDERCALCULATOR_H

#include "../Abstract/icalculator.h"

class CCylinderCalculator : public ICalculator
{
public:
    CCylinderCalculator();

private:
    virtual void DoCalculate(CCylinderData& data) const;
};

#endif // CCYLINDERCALCULATOR_H
