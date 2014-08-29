#include "ccylindercontroller.h"
#include "../Models/Concrete/ccylindermodel.h"
#include "../Views/Concrete/ccylinderview.h"
#include "../Readers/Abstract/icylinderreader.h"
#include "../Writers/Abstract/iwriter.h"
#include "../Calculator/Abstract/icalculator.h"
#include "../ccylindervolumeenums.h"
/**********************************************************/
namespace EditorMode
{
    const int VIEW_MODE = 0;
    const int EDIT_MODE = 1;
    const int NEW_MODE = 2;
    const int DELETE_MODE = 3;
}
/**********************************************************/
CCylinderController::CCylinderController(PCylinderReader Reader, PWriter Writer, PCalculator Calculator)
    : m_Reader(Reader),
      m_Writer(Writer),
      m_Calculator(Calculator),
      m_Model(std::make_shared<CCylinderModel>()),
      m_EditedModel(std::make_shared<CCylinderModel>()),
      m_EditMode(EditorMode::VIEW_MODE)
{
    m_Reader->Read(*m_Model);
    m_EditedModel->Clone(*m_Model);
    const auto& Collection(m_Model->GetCollection());
    m_CurrentIndex = Collection.size() > 0 ? Collection.begin()->first : -1;
    m_PreviousIndex = m_CurrentIndex;
}
/**********************************************************/
void CCylinderController::Add()
{
    CCylinderData Data;
    Data.SetIndex(m_Reader->GetKeyIndex());
    m_CurrentIndex = Data.GetIndex();
    m_Model->Add(Data);

    m_EditMode = EditorMode::NEW_MODE;
    RenderViews();
}
/**********************************************************/
void CCylinderController::Edit(int SelectedRow)
{
    m_CurrentIndex = SelectedRow;

    m_EditMode = EditorMode::EDIT_MODE;
    RenderViews();
}
/*********************************************************/
void CCylinderController::Apply(const CCylinderData& Data)
{
    CCylinderData Other(Data);

    m_Calculator->Calculate(Other);
    m_Model->Apply(Other);
    m_EditedModel->Clone(*m_Model);
    m_Writer->Write(*m_Model);

    m_PreviousIndex = m_CurrentIndex;

    m_EditMode = EditorMode::VIEW_MODE;
    RenderViews();
}
/*********************************************************/
void CCylinderController::Delete()
{
    m_Model->Delete(m_CurrentIndex);

    m_EditMode = EditorMode::DELETE_MODE;
    RenderViews();
}
/**********************************************************/
PModel CCylinderController::GetModel() const
{
    return m_Model;
}
/**********************************************************/
void CCylinderController::ApplyDelete()
{
    m_EditedModel->Clone(*m_Model);
    m_Writer->Write(*m_Model);
    m_CurrentIndex = m_PreviousIndex;

    m_EditMode = EditorMode::VIEW_MODE;
    RenderViews();
}
/**********************************************************/
void CCylinderController::Cancel()
{    
    m_Model->Clone(*m_EditedModel);

    m_EditMode = EditorMode::VIEW_MODE;
    RenderViews();
}
/*********************************************************/
void CCylinderController::AddView(PView View)
{
    m_Collection.push_back(View);
}
/*********************************************************/
void CCylinderController::RenderViews()
{
    for (const auto& View : m_Collection)
    {
        auto Form(View.lock());
        if (Form) { Form->Render(); }
    }
}
/**********************************************************/
bool CCylinderController::InViewMode() const
{
    return m_EditMode == EditorMode::VIEW_MODE;
}
/**********************************************************/
bool CCylinderController::InEditMode() const
{
    return m_EditMode == EditorMode::EDIT_MODE;
}
/**********************************************************/
bool CCylinderController::InDeleteMode() const
{
    return m_EditMode == EditorMode::DELETE_MODE;
}
/**********************************************************/
bool CCylinderController::InNewMode() const
{
    return m_EditMode == EditorMode::NEW_MODE;
}
/**********************************************************/
int CCylinderController::GetEditIndex() const
{
    return m_CurrentIndex;
}
/**********************************************************/
int CCylinderController::IsValid(const CCylinderData& Data)
{
    if (Data.GetRadius() <= 0)
    {
        return CCylinderVolumeEnums::InvalidRadius;
    }
    else if (Data.GetHeight() <= 0)
    {
        return CCylinderVolumeEnums::InvalidHeight;
    }

    return CCylinderVolumeEnums::IsValid;
}
/**********************************************************/
