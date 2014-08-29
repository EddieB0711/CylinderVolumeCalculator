#ifndef IWRITER_H
#define IWRITER_H

#include "../../Models/Abstract/imodel.h"

class IWriter
{
public:
    inline void Write(IModel& Other) { DoWrite(Other); }
    virtual ~IWriter() {}

private:
    virtual void DoWrite(const IModel& Other) = 0;
};

#endif // IWRITER_H
