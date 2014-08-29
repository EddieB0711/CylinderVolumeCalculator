#ifndef CCYLINDERVIEW_H
#define CCYLINDERVIEW_H

#include "../Abstract/iview.h"

class Dialog;

class CCylinderView : public IView
{
public:
    CCylinderView(Dialog& Form);
    virtual void Render();
    virtual void Show();

private:
    Dialog& m_Form;
};

#endif // CCYLINDERVIEW_H
