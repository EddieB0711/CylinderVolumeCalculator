#ifndef CCYLINDERCONTROLLER_H
#define CCYLINDERCONTROLLER_H

#include "../Models/Abstract/pmodel.h"
#include "../Views/Abstract/pview.h"
#include "../Views/Abstract/ccylinderviewcollection.h"
#include "../Readers/Abstract/pcylinderreader.h"
#include "../Writers/Abstract/pwriter.h"
#include "../Calculator/Abstract/pcalculator.h"

class CCylinderData;

class CCylinderController
{
public:
    CCylinderController(PCylinderReader Reader, PWriter Writer, PCalculator Calculator);
    void Add();
    void Edit(int selectedRow);
    void Apply(const CCylinderData& Data);
    void Delete();
    void ApplyDelete();
    void Cancel();
    PModel GetModel() const;
    void AddView(PView View);
    void RenderViews();
    bool InViewMode() const;
    bool InEditMode() const;
    bool InDeleteMode() const;
    bool InNewMode() const;
    int GetEditIndex() const;
    int IsValid(const CCylinderData& Data);

private:
    PCylinderReader m_Reader;
    PWriter m_Writer;
    PCalculator m_Calculator;
    ViewCollection m_Collection;
    PModel m_Model;
    PModel m_EditedModel;
    int m_EditMode;
    int m_CurrentIndex;
    int m_PreviousIndex;
};

#endif // CCYLINDERCONTROLLER_H
