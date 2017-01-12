#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T19:45:42
#
#-------------------------------------------------

QT       += core gui

TARGET = CentosUI
TEMPLATE = app


greaterThan(QT_MAJOR_VERSION,4):QT += widgets

SRC_DIR     = ./src
INC_DIR     = ./inc
UI_DIR      = $$PWD/ui
OBJECTS_DIR = $$PWD/build/obj
MOC_DIR     = $$PWD/build/moc
DESTDIR     = $$PWD/build/bin

INCLUDEPATH += $$INC_DIR

SOURCES += $$SRC_DIR/main.cpp\
        $$SRC_DIR/mainwindow.cpp \
        $$SRC_DIR/view1.cpp \
        $$SRC_DIR/view2.cpp \
        $$SRC_DIR/view3.cpp

HEADERS  += $$INC_DIR/mainwindow.h \
        $$INC_DIR/view1.h \
        $$INC_DIR/view2.h \
        $$INC_DIR/view3.h

FORMS    += $$UI_DIR/mainwindow.ui \
        $$UI_DIR/view1.ui \
        $$UI_DIR/view2.ui \
        $$UI_DIR/view3.ui
