#-------------------------------------------------
#
# Project created by QtCreator 2014-03-17T19:05:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QEnvEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    EnvTreeWidget.cpp

HEADERS  += mainwindow.h \
    EnvTreeWidget.h

FORMS    += mainwindow.ui
