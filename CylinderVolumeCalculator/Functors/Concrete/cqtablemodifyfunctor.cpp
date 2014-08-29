#include "cqtablemodifyfunctor.h"
#include "../../ccylindervolumeenums.h"
#include "../../Controllers/ccylindercontroller.h"

#include <QComboBox>
/**********************************************************/
namespace ModifyFunctor
{
/**********************************************************/
void ToggleCombo(QTableWidget& Widget, bool ComboFlag, int Row, int Col)
{
    auto combo((QComboBox*) Widget.cellWidget(Row, Col));
    combo->setEnabled(ComboFlag);
}
/**********************************************************/
void ToggleFlags(QTableWidget& Widget, int Row, Qt::ItemFlags Flag, bool ComboFlag)
{
    Widget.item(Row, CCylinderVolumeEnums::IndexColumn)->setFlags(Qt::ItemIsSelectable);
    Widget.item(Row, CCylinderVolumeEnums::RadiusColumn)->setFlags(Flag);
    ToggleCombo(Widget, ComboFlag, Row, CCylinderVolumeEnums::RadiusUnitColumn);
    Widget.item(Row, CCylinderVolumeEnums::HeightColumn)->setFlags(Flag);
    ToggleCombo(Widget, ComboFlag, Row, CCylinderVolumeEnums::HeightUnitColumn);
    Widget.item(Row, CCylinderVolumeEnums::VolumnColumn)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}
/**********************************************************/
}
/**********************************************************/
CQTableModifyFunctor::CQTableModifyFunctor()
{
}
/**********************************************************/
int CQTableModifyFunctor::operator ()(QTableWidget& Widget, const CCylinderController& Controller, int Row) const
{
    if (Widget.item(Row, CCylinderVolumeEnums::IndexColumn)->text().toInt() == Controller.GetEditIndex()
            && (Controller.InNewMode() || Controller.InEditMode()))
    {
        ModifyFunctor::ToggleFlags(Widget, Row, Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable, true);
    }
    else
    {
       ModifyFunctor::ToggleFlags(Widget, Row, Qt::ItemIsSelectable | Qt::ItemIsEnabled, false);
    }

    return -1;
}
/**********************************************************/
