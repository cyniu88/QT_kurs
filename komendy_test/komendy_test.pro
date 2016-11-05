TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    commandtest.cpp \
    command.cpp \
    commandexit.cpp \
    commandhandler.cpp

HEADERS += \
    commandtest.h \
    command.h \
    commandexit.h \
    commandhandler.h
