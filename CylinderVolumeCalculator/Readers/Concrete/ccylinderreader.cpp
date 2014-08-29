#include "ccylinderreader.h"
#include "../../Models/Abstract/imodel.h"
/**********************************************************/
CCylinderReader::CCylinderReader(PModel Model)
    : m_Model(Model)
{
}
/**********************************************************/
void CCylinderReader::DoRead(IModel& Other) const
{
    Other.Clone(*m_Model);
}
/**********************************************************/
int CCylinderReader::DoGetKeyIndex() const
{
    /*
     * Simulate getting the next index from a database
     * or other source of storage.
     */
    static int Index = 0;

    if (Index == 0)
    {
        const auto& collection(m_Model->GetCollection());
        Index = collection.size() > 0 ? collection.begin()->first : 0;
    }
    ++Index;

    return Index;
}
/**********************************************************/
