#ifndef CCYLINDERREADER_H
#define CCYLINDERREADER_H
#include "../Abstract/icylinderreader.h"
//#include "../Abstract/ireader.h"
#include "../../Models/Abstract/pmodel.h"

class CCylinderReader : public ICylinderReader
{
public:
    CCylinderReader(PModel Model);

private:
    PModel m_Model;

    virtual void DoRead(IModel& Other) const;
    virtual int DoGetKeyIndex() const;
};

#endif // CCYLINDERREADER_H
