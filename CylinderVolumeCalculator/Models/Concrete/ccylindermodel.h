#ifndef CCYLINDERMODEL_H
#define CCYLINDERMODEL_H

#include "../Abstract/IModel.h"

class CCylinderModel : public IModel
{
public:
    CCylinderModel();

private:
    CylinderDataCollection m_Collection;

    virtual void DoAdd(const CCylinderData& Data);
    virtual void DoApply(const CCylinderData& Data);
    virtual void DoDelete(int Index);
    virtual CylinderDataCollection DoGetCollection() const;
    virtual void DoClone(const IModel& Other);
    virtual double DoGetTotalVolume() const;
};

#endif // CCYLINDERMODEL_H
