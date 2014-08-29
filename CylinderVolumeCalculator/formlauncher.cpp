#include "formlauncher.h"
#include "dialog.h"
#include "Controllers/ccylindercontroller.h"
#include "Controllers/pcylindercontroller.h"
#include "Views/Abstract/pview.h"
#include "Views/Concrete/ccylinderview.h"
#include "Readers/Abstract/pcylinderreader.h"
#include "Readers/Concrete/ccylinderreader.h"
#include "Models/Concrete/ccylindermodel.h"
#include "Writers/Abstract/pwriter.h"
#include "Writers/Concrete/ccylinderwriter.h"
#include "Calculator/Abstract/pcalculator.h"
#include "Calculator/Concrete/ccylindercalculator.h"
#include "ccylinderdata.h"
#include "ui_formlauncher.h"
/**********************************************************/
void SetUpModel(IModel& Model)
{
    CCylinderData Data;
    Data.SetIndex(1);
    Data.SetRadius(5);
    Data.SetRadiusUnit("Feet");
    Data.SetHeight(17);
    Data.SetHeightUnit("Feet");
    Data.SetVolume(1335.18);
    Model.Add(Data);
}
/**********************************************************/
FormLauncher::FormLauncher(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::FormLauncher),
      m_Model(new CCylinderModel())
{
    ui->setupUi(this);
    SetUpModel(*m_Model);
}
/**********************************************************/
FormLauncher::~FormLauncher()
{
    delete ui;
}
/**********************************************************/
void FormLauncher::on_btnLocation1_clicked()
{
    auto Reader(std::make_shared<CCylinderReader>(m_Model));
    auto Writer(std::make_shared<CCylinderWriter>(m_Model));
    auto Calculator(std::make_shared<CCylinderCalculator>());
    auto Controller(std::make_shared<CCylinderController>(Reader, Writer, Calculator));
    auto Dialog(std::make_shared<Dialog>(this, Controller));
    auto View(std::make_shared<CCylinderView>(*Dialog));
    Controller->AddView(View);
    Controller->RenderViews();
    Dialog->exec();
}
/**********************************************************/
