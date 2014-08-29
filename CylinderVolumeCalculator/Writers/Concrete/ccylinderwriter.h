#ifndef CCYLINDERWRITER_H
#define CCYLINDERWRITER_H

#include "../Abstract/iwriter.h"
#include "../../Models/Abstract/pmodel.h"

class CCylinderWriter : public IWriter
{
public:
    CCylinderWriter(PModel Model);

private:
    PModel m_Model;

    virtual void DoWrite(const IModel& Other);
};

#endif // CCYLINDERWRITER_H
