#-------------------------------------------------
#
# Project created by QtCreator 2016-08-09T08:25:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Wczytywanie_danych
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    statistics.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    data.h \
    statistics.h

FORMS    += mainwindow.ui
