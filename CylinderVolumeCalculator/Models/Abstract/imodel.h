#ifndef IMODEL_H
#define IMODEL_H

#include "../../ccylinderdata.h"
#include "ccylinderdatacollection.h"

class IModel
{
public:
    inline void Add(const CCylinderData& Data) { DoAdd(Data); }
    inline void Apply(const CCylinderData& Data){ DoApply(Data); }
    inline void Delete(int Index) { DoDelete(Index); }
    inline CylinderDataCollection GetCollection() const { return DoGetCollection(); }
    inline void Clone(const IModel& Other) { DoClone(Other); }
    inline double GetTotalVolume() const { return DoGetTotalVolume(); }
    virtual ~IModel() {}

private:
    virtual void DoAdd(const CCylinderData& Data) = 0;
    virtual void DoApply(const CCylinderData& Data) = 0;
    virtual void DoDelete(int Index) = 0;
    virtual CylinderDataCollection DoGetCollection() const = 0;
    virtual void DoClone(const IModel& Other) = 0;
    virtual double DoGetTotalVolume() const = 0;
};

#endif // IMODEL_H
