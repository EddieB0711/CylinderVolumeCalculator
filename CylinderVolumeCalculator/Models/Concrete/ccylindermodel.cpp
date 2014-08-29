#include "ccylindermodel.h"
/**********************************************************/
/**********************************************************/
template <class TFunctor>
void ModifyCollection(CylinderDataCollection& Collection, int Index, TFunctor Functor)
{
    const auto& iter(Collection.find(Index));
    if (iter == Collection.end()) { return; }
    Functor(Index);
}
/**********************************************************/
/**********************************************************/
CCylinderModel::CCylinderModel()
{
}
/**********************************************************/
void CCylinderModel::DoAdd(const CCylinderData& Data)
{
    m_Collection.insert(CylinderDataCollection::value_type(Data.GetIndex(), Data));
}
/**********************************************************/
void CCylinderModel::DoApply(const CCylinderData& Data)
{
    auto Functor([&, Data](int Index){ m_Collection[Index] = Data; });
    ModifyCollection(m_Collection, Data.GetIndex(), Functor);
}
/**********************************************************/
void CCylinderModel::DoDelete(int Index)
{
    auto Functor([&](int Index){ m_Collection.erase(Index); });
    ModifyCollection(m_Collection, Index, Functor);
}
/**********************************************************/
CylinderDataCollection CCylinderModel::DoGetCollection() const
{
    return m_Collection;
}
/**********************************************************/
void CCylinderModel::DoClone(const IModel& Other)
{
    m_Collection = Other.GetCollection();
}
/**********************************************************/
double CCylinderModel::DoGetTotalVolume() const
{
    auto Total(0.0);
    for (const auto& Item : m_Collection)
    {
        const auto& Data(Item.second);
        if (Data.GetVolume() == -1) { continue; }
        Total += Data.GetVolume();
    }

    return Total;
}
