#-------------------------------------------------
#
# Project created by QtCreator 2014-04-20T14:00:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CylinderVolumeCalculator
TEMPLATE = app


SOURCES += main.cpp\
    ccylinderdata.cpp \
    Models/Concrete/ccylindermodel.cpp \
    Controllers/ccylindercontroller.cpp \
    Views/Abstract/iview.cpp \
    Views/Abstract/pview.cpp \
    Views/Abstract/ccylinderviewcollection.cpp \
    Views/Abstract/wview.cpp \
    formlauncher.cpp \
    dialog.cpp \
    Readers/Abstract/ireader.cpp \
    Readers/Concrete/ccylinderreader.cpp \
    Readers/Abstract/preader.cpp \
    Writers/Abstract/iwriter.cpp \
    Writers/Concrete/ccylinderwriter.cpp \
    Writers/Abstract/pwriter.cpp \
    Calculator/Abstract/icalculator.cpp \
    Calculator/Concrete/ccylindercalculator.cpp \
    Calculator/Abstract/pcalculator.cpp \
    ccylindervolumeenums.cpp \
    Functors/Abstract/iqtablefunctors.cpp \
    Functors/Concrete/cqtableindexfunctor.cpp \
    Functors/Concrete/cqtablemodifyfunctor.cpp \
    Readers/Abstract/icylinderreader.cpp \
    Readers/Abstract/pcylinderreader.cpp \
    Views/Concrete/ccylinderview.cpp

HEADERS  += \
    ccylinderdata.h \
    Models/Concrete/ccylindermodel.h \
    Models/Abstract/imodel.h \
    Models/Abstract/ccylinderdatacollection.h \
    Controllers/ccylindercontroller.h \
    Models/Abstract/pmodel.h \
    Controllers/pcylindercontroller.h \
    Views/Abstract/iview.h \
    Views/Concrete/ccylinderview.h \
    Views/Abstract/pview.h \
    Views/Abstract/ccylinderviewcollection.h \
    Views/Abstract/wview.h \
    formlauncher.h \
    dialog.h \
    Readers/Abstract/ireader.h \
    Readers/Concrete/ccylinderreader.h \
    Readers/Abstract/preader.h \
    Writers/Abstract/iwriter.h \
    Writers/Concrete/ccylinderwriter.h \
    Writers/Abstract/pwriter.h \
    Calculator/Abstract/icalculator.h \
    Calculator/Concrete/ccylindercalculator.h \
    Calculator/Abstract/pcalculator.h \
    ccylindervolumeenums.h \
    Functors/Abstract/iqtablefunctors.h \
    Functors/Concrete/cqtableindexfunctor.h \
    Functors/Concrete/cqtablemodifyfunctor.h \
    Readers/Abstract/icylinderreader.h \
    Readers/Abstract/pcylinderreader.h

FORMS    += \
    formlauncher.ui \
    dialog.ui
