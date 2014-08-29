#ifndef CQTABLEINDEXFUNCTOR_H
#define CQTABLEINDEXFUNCTOR_H
#include "../Abstract/iqtablefunctors.h"

class CQTableIndexFunctor : public IQTableFunctors
{
public:
    CQTableIndexFunctor();
    virtual int operator ()(QTableWidget& Widget, const CCylinderController& Controller, int Row) const;
};

#endif // CQTABLEINDEXFUNCTOR_H
