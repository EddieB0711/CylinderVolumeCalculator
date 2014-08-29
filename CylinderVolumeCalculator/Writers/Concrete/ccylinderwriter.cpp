#include "ccylinderwriter.h"
#include "../../Models/Abstract/imodel.h"
/**********************************************************/
CCylinderWriter::CCylinderWriter(PModel Model)
    : m_Model(Model)
{
}
/**********************************************************/
void CCylinderWriter::DoWrite(const IModel& Other)
{
    /* I don't have a database to write to,
     * so this only saves the changes made to the Model
     * in the Calculation form.
     */
    m_Model->Clone(Other);
}
/**********************************************************/
