#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include "Controllers/pcylindercontroller.h"

class CCylinderData;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent, PCylinderController controller);
    ~Dialog();
    void Render();

private slots:
    void on_btnAdd_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_btnCancel_clicked();
    void on_btnExit_clicked();
    void on_btnApply_clicked();
    void on_btnApplyDelete_clicked();

private:
    void EnableDisableControls();
    void EnableDisableTable();
    void PopulateGrid();
    void AttachComboBox(int Row, int Col);
    CCylinderData GetTableData();
    void HandleReturnCode(int Code);

    QPushButton* m_BtnAdd;
    QPushButton* m_BtnEdit;
    QPushButton* m_BtnDelete;
    QPushButton* m_BtnCancel;
    QPushButton* m_BtnExit;
    QPushButton* m_BtnApply;
    QPushButton* m_BtnApplyDelete;

    QLabel* m_LblErrorMessage;
    QLabel* m_LblTotalVolume;

    QTableWidget* m_Table;
    PCylinderController m_Controller;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
