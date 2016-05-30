#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T19:57:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GrowCutQt
TEMPLATE = app


SOURCES += main.cpp\
        growcutwindow.cpp \
    ModelGrowCut/BasicTypes.cpp \
    ModelGrowCut/CellularAutomata.cpp \
    myqlabel.cpp

HEADERS  += growcutwindow.h \
    ModelGrowCut/BasicTypes.h \
    ModelGrowCut/Cell.h \
    ModelGrowCut/CellularAutomata.h \
    ModelGrowCut/Matrix.h \
    ImageConverter.h \
    myqlabel.h

FORMS    += growcutwindow.ui

RESOURCES += \
    res.qrc



