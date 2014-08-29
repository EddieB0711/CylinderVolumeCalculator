#ifndef PCALCULATOR_H
#define PCALCULATOR_H

#include <memory>

class ICalculator;

typedef std::shared_ptr<ICalculator> PCalculator;

#endif // PCALCULATOR_H
