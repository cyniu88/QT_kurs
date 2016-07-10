#-------------------------------------------------
#
# Project created by QtCreator 2016-07-09T14:15:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gps
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    analogclock.cpp \
    analogclock2.cpp \
    data_control.cpp \
    gps.cpp \
    mainwin.cpp

HEADERS  += mainwindow.h \
    analogclock.h \
    analogclock2.h \
    data_control.h \
    gps.h \
    mainwin.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    gps.pro.user \
    README

