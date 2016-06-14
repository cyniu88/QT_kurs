#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T16:36:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iDom_Client
TEMPLATE = app


SOURCES += main.cpp\
        idom_client.cpp \
    workerip.cpp

HEADERS  += idom_client.h \
    variable.h \
    workerip.h

FORMS    += idom_client.ui

CONFIG += mobility
MOBILITY = 

