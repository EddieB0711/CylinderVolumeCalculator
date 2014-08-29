#ifndef FORMLAUNCHER_H
#define FORMLAUNCHER_H

#include <QMainWindow>
#include "Models/Abstract/pmodel.h"

namespace Ui {
class FormLauncher;
}

class FormLauncher : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormLauncher(QWidget *parent = 0);
    ~FormLauncher();

private slots:
    void on_btnLocation1_clicked();

private:
    PModel m_Model;
    Ui::FormLauncher *ui;
};

#endif // FORMLAUNCHER_H
