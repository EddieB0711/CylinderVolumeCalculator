#include "cqtableindexfunctor.h"
#include "../../Controllers/ccylindercontroller.h"
#include "../../ccylindervolumeenums.h"
/**********************************************************/
CQTableIndexFunctor::CQTableIndexFunctor()
{
}
/**********************************************************/
int CQTableIndexFunctor::operator ()(QTableWidget& Widget, const CCylinderController& Controller, int Row) const
{
    if (Controller.GetEditIndex() == Widget.item(Row, CCylinderVolumeEnums::IndexColumn)->text().toInt())
    {
        return Row;
    }

    return -1;
}
/**********************************************************/
