#-------------------------------------------------
#
# Project created by QtCreator 2016-07-08T08:07:43
#
#-------------------------------------------------

QT       += core gui  quick
android: QT += androidextras
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vibrate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vibrator.cpp

HEADERS  += mainwindow.h \
    vibrator.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

