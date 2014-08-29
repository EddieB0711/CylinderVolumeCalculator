#include "formlauncher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormLauncher w;
    w.show();

    return a.exec();
}
