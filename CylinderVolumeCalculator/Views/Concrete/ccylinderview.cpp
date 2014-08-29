#include "ccylinderview.h"
#include "../../dialog.h"

CCylinderView::CCylinderView(Dialog& Form)
    : m_Form(Form)
{
}

void CCylinderView::Render()
{
    m_Form.Render();
}

void CCylinderView::Show()
{
    m_Form.show();
}
