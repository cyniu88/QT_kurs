TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    command.cpp \
    commandhandler.cpp \
    commandClasses/command_big.cpp \
    commandClasses/command_clock.cpp \
    commandClasses/command_cmd.cpp \
    commandClasses/command_hello.cpp \
    commandClasses/command_help.cpp \
    commandClasses/command_ip.cpp \
    commandClasses/command_ok.cpp \
    commandClasses/command_show.cpp \
    commandClasses/command_sleep.cpp \
    commandClasses/commandexit.cpp \
    commandClasses/commandtest.cpp \
    commandClasses/command_put.cpp


HEADERS += \
    command.h \
    commandhandler.h \
    commandClasses/command_big.h \
    commandClasses/command_clock.h \
    commandClasses/command_cmd.h \
    commandClasses/command_hello.h \
    commandClasses/command_help.h \
    commandClasses/command_ip.h \
    commandClasses/command_ok.h \
    commandClasses/command_show.h \
    commandClasses/command_sleep.h \
    commandClasses/commandexit.h \
    commandClasses/commandtest.h \
    commandClasses/command_put.h
