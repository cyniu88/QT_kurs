#-------------------------------------------------
#
# Project created by QtCreator 2018-07-24T08:43:30
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = fann-GUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14  -j5
LIBS += -fopenmp
SOURCES += \
    fann_gui.cpp \
    main.cpp \
    ../FANN-test/fann-src/parallel_doublefann_cpp.cpp \
    ../FANN-test/fann-src/parallel_fann_cpp.cpp \
    ../FANN-test/fann-src/parallel_floatfann_cpp.cpp \
    ../FANN-test/fann-src/doublefann.c \
    ../FANN-test/fann-src/fann.c \
    ../FANN-test/fann-src/fann_cascade.c \
    ../FANN-test/fann-src/fann_error.c \
    ../FANN-test/fann-src/fann_io.c \
    ../FANN-test/fann-src/fann_train.c \
    ../FANN-test/fann-src/fann_train_data.c \
    ../FANN-test/fann-src/fixedfann.c \
    ../FANN-test/fann-src/floatfann.c \
    ../FANN-test/fann-src/parallel_fann.c

HEADERS += \
        fann_gui.h \
    fann_gui.h \
    ../FANN-test/fann-src/config.h \
    ../FANN-test/fann-src/doublefann.h \
    ../FANN-test/fann-src/fann.h \
    ../FANN-test/fann-src/fann_activation.h \
    ../FANN-test/fann-src/fann_cascade.h \
    ../FANN-test/fann-src/fann_cpp.h \
    ../FANN-test/fann-src/fann_data.h \
    ../FANN-test/fann-src/fann_data_cpp.h \
    ../FANN-test/fann-src/fann_error.h \
    ../FANN-test/fann-src/fann_internal.h \
    ../FANN-test/fann-src/fann_io.h \
    ../FANN-test/fann-src/fann_train.h \
    ../FANN-test/fann-src/fann_training_data_cpp.h \
    ../FANN-test/fann-src/fixedfann.h \
    ../FANN-test/fann-src/floatfann.h \
    ../FANN-test/fann-src/parallel_fann.h \
    ../FANN-test/fann-src/parallel_fann.hpp

FORMS += \
        fann_gui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
