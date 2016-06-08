#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T22:24:49
#
#-------------------------------------------------

QT       += core gui sensors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        idom_client.cpp

HEADERS  += idom_client.h

FORMS    += idom_client.ui

CONFIG += mobility
MOBILITY = 

