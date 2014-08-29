#ifndef IQTABLEFUNCTORS_H
#define IQTABLEFUNCTORS_H

#include <QTableWidget>

class CCylinderController;

class IQTableFunctors
{
public:
    virtual int operator()(QTableWidget& widget, const CCylinderController& controller, int row) const = 0;
    virtual ~IQTableFunctors() {}
};

#endif // IQTABLEFUNCTORS_H
