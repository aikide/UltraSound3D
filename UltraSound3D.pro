#-------------------------------------------------
#
# Project created by QtCreator 2017-07-20T01:47:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UltraSound3D
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    window3d.cpp \
    slicewindow.cpp

HEADERS  += mainwindow.h \
    window3d.h \
    slicewindow.h

FORMS    += mainwindow.ui \
    window3d.ui \
    slicewindow.ui
