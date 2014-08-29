#ifndef CQTABLEMODIFYFUNCTOR_H
#define CQTABLEMODIFYFUNCTOR_H
#include "../Abstract/iqtablefunctors.h"

class CQTableModifyFunctor : public IQTableFunctors
{
public:
    CQTableModifyFunctor();
    virtual int operator ()(QTableWidget& Widget, const CCylinderController& Controller, int Row) const;
};

#endif // CQTABLEMODIFYFUNCTOR_H
