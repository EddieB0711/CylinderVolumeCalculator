#include "dialog.h"
#include "ui_dialog.h"
#include "Controllers/ccylindercontroller.h"
#include "Models/Abstract/imodel.h"
#include "ccylindervolumeenums.h"
#include "Functors/Concrete/cqtableindexfunctor.h"
#include "Functors/Concrete/cqtablemodifyfunctor.h"

#include <QSignalMapper>
#include <QComboBox>
/**********************************************************/
QComboBox* CreateCombo()
{
    auto Combo(new QComboBox());
    Combo->addItem("Feet");
    Combo->addItem("Inches");
    Combo->setCurrentIndex(0);

    return Combo;
}
/**********************************************************/
int SearchGrid(QTableWidget& Widget, const CCylinderController& Controller, const IQTableFunctors& Functor)
{
    auto Index(-1);

    for (auto Row(0); Row < Widget.rowCount(); ++Row)
    {
        Index = Functor(Widget, Controller, Row);
        if (Index != -1) { break; }
    }

    return Index;
}
/**********************************************************/
Dialog::Dialog(QWidget *parent, PCylinderController Controller) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_Controller(Controller)
{
    ui->setupUi(this);
    m_Table = ui->tableWidget;
    m_BtnAdd = ui->btnAdd;
    m_BtnApply = ui->btnApply;
    m_BtnApplyDelete = ui->btnApplyDelete;
    m_BtnCancel = ui->btnCancel;
    m_BtnDelete = ui->btnDelete;
    m_BtnEdit = ui->btnEdit;
    m_BtnExit = ui->btnExit;
    m_LblErrorMessage = ui->lblErrorMessage;
    m_LblTotalVolume = ui->lblTotalVolume;
    m_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
/**********************************************************/
Dialog::~Dialog()
{
    delete ui;
}
/**********************************************************/
void Dialog::AttachComboBox(int Row, int Col)
{
    if (m_Table->rowCount() <= 0) { return; }

    auto Mapper(new QSignalMapper(this));
    auto Combo(CreateCombo());
    m_Table->setCellWidget(Row, Col, Combo);
    connect(Combo, SIGNAL(currentIndexChanged(int)), Mapper, SLOT(map()));
    Mapper->setMapping(Combo, QString("%1-%2").arg(Row).arg(Col));
}
/**********************************************************/
QTableWidgetItem* CreateTableItem(double Data)
{
    if (Data == -1) { return new QTableWidgetItem(); }
    return new QTableWidgetItem(QString::number(Data));
}
/**********************************************************/
QTableWidgetItem* CreateTableItem(QString Data)
{
    auto Item(new QTableWidgetItem());
    Item->setText(Data);

    return Item;
}
/**********************************************************/
void SetComboText(QTableWidget& Widget, QString Text, int Row, int Col)
{
    auto Combo((QComboBox*) Widget.cellWidget(Row, Col));
    Combo->setCurrentText(Text);
}
/**********************************************************/
void Dialog::PopulateGrid()
{
    const auto& Model(*m_Controller->GetModel());
    const auto& Collection(Model.GetCollection());
    m_Table->clearContents();
    m_Table->setRowCount(int(Collection.size()));

    auto Row(0);
    for (const auto& Items : Collection)
    {
        const auto& Data(Items.second);

        m_Table->setItem(Row, CCylinderVolumeEnums::IndexColumn, CreateTableItem(Data.GetIndex()));
        m_Table->setItem(Row, CCylinderVolumeEnums::RadiusColumn, CreateTableItem(Data.GetRadius()));

        AttachComboBox(Row, CCylinderVolumeEnums::RadiusUnitColumn);
        SetComboText(*m_Table, Data.GetRadiusUnit().c_str(), Row, CCylinderVolumeEnums::RadiusUnitColumn);

        m_Table->setItem(Row, CCylinderVolumeEnums::HeightColumn, CreateTableItem(Data.GetHeight()));

        AttachComboBox(Row, CCylinderVolumeEnums::HeightUnitColumn);
        SetComboText(*m_Table, Data.GetHeightUnit().c_str(), Row, CCylinderVolumeEnums::HeightUnitColumn);

        m_Table->setItem(Row, CCylinderVolumeEnums::VolumnColumn, CreateTableItem(Data.GetVolume()));
        ++Row;
    }

    m_LblTotalVolume->setText(QString::number(Model.GetTotalVolume()));
    m_Table->hideColumn(CCylinderVolumeEnums::IndexColumn);
}
/**********************************************************/
QString GetComboText(QTableWidget& Widget, int Row, int Col)
{
    auto Combo((QComboBox*) Widget.cellWidget(Row, Col));
    return Combo->currentText();
}
/**********************************************************/
CCylinderData Dialog::GetTableData()
{
    auto SelectedRow(SearchGrid(*m_Table, *m_Controller, CQTableIndexFunctor()));
    CCylinderData Data;

    Data.SetIndex(m_Table->item(SelectedRow, CCylinderVolumeEnums::IndexColumn)->text().toDouble());
    Data.SetRadius(m_Table->item(SelectedRow, CCylinderVolumeEnums::RadiusColumn)->text().toDouble());
    Data.SetRadiusUnit(GetComboText(*m_Table, SelectedRow, CCylinderVolumeEnums::RadiusUnitColumn).toStdString());
    Data.SetHeight(m_Table->item(SelectedRow, CCylinderVolumeEnums::HeightColumn)->text().toDouble());
    Data.SetHeightUnit(GetComboText(*m_Table, SelectedRow, CCylinderVolumeEnums::HeightUnitColumn).toStdString());
    Data.SetVolume(m_Table->item(SelectedRow, CCylinderVolumeEnums::VolumnColumn)->text().toDouble());

    return Data;
}
/**********************************************************/
void Dialog::Render()
{
    PopulateGrid();
    EnableDisableControls();
    m_Table->setCurrentCell(SearchGrid(*m_Table, *m_Controller, CQTableIndexFunctor()), CCylinderVolumeEnums::RadiusColumn);
    m_LblErrorMessage->setText("");
}
/**********************************************************/
void Dialog::EnableDisableControls()
{
    m_BtnAdd->setEnabled(m_Controller->InViewMode());
    m_BtnEdit->setEnabled(m_Controller->InViewMode() && m_Table->rowCount() > 0);
    m_BtnDelete->setEnabled(m_Controller->InEditMode());
    m_BtnCancel->setEnabled(m_Controller->InNewMode() || m_Controller->InEditMode() || m_Controller->InDeleteMode());
    m_BtnExit->setEnabled(m_Controller->InViewMode());
    m_BtnApply->setVisible(m_Controller->InEditMode() || m_Controller->InNewMode() || m_Controller->InViewMode());
    m_BtnApply->setEnabled(m_Controller->InEditMode() || m_Controller->InNewMode());
    m_BtnApplyDelete->setVisible(m_Controller->InDeleteMode());
    m_BtnApplyDelete->setEnabled(m_Controller->InDeleteMode());

    EnableDisableTable();
}
/**********************************************************/
void Dialog::EnableDisableTable()
{
    SearchGrid(*m_Table, *m_Controller, CQTableModifyFunctor());
}
/**********************************************************/
void Dialog::on_btnAdd_clicked()
{
    m_Controller->Add();
}
/**********************************************************/
void Dialog::on_btnEdit_clicked()
{
    auto SelectedRow(m_Table->item(m_Table->currentRow(), 0)->text().toInt());
    m_Controller->Edit(SelectedRow);
}
/**********************************************************/
void Dialog::on_btnDelete_clicked()
{
    m_Controller->Delete();
}
/**********************************************************/
void Dialog::on_btnCancel_clicked()
{
    m_Controller->Cancel();
}
/**********************************************************/
void Dialog::on_btnExit_clicked()
{   
    this->close();
}
/**********************************************************/
void Dialog::HandleReturnCode(int Code)
{
    auto CurrentRow(SearchGrid(*m_Table, *m_Controller, CQTableIndexFunctor()));
    switch (Code)
    {
    case CCylinderVolumeEnums::InvalidRadius:
        m_Table->editItem(m_Table->item(CurrentRow, CCylinderVolumeEnums::RadiusColumn));
        m_LblErrorMessage->setText("Invalid Radius");
        break;
    case CCylinderVolumeEnums::InvalidHeight:
        m_Table->editItem(m_Table->item(CurrentRow, CCylinderVolumeEnums::HeightColumn));
        m_LblErrorMessage->setText("Invalid Height");
        break;
    }
}
/**********************************************************/
void Dialog::on_btnApply_clicked()
{
    const auto& Data(GetTableData());
    auto Code(m_Controller->IsValid(Data));

    if (Code == CCylinderVolumeEnums::IsValid)
    {
        m_Controller->Apply(Data);
    }
    else
    {
        HandleReturnCode(Code);
    }
}
/**********************************************************/
void Dialog::on_btnApplyDelete_clicked()
{
    m_Controller->ApplyDelete();
}
/**********************************************************/
