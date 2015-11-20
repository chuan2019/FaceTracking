#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T19:36:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FaceTrack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += "/usr/local/include"

LIBS += `pkg-config --libs opencv`
