#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T13:23:02
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pilot
TEMPLATE = app


SOURCES += main.cpp\
        pilotwindow.cpp \
    joypad.cpp \
    mybutton.cpp \
    touchbutton.cpp \
    functions.cpp \
    mytouchslider.cpp \
    workerip.cpp

HEADERS  += pilotwindow.h \
    joypad.h \
    mybutton.h \
    touchbutton.h \
    functions.h \
    mytouchslider.h \
    workerip.h \
    variable.h

FORMS    += pilotwindow.ui
CONFIG += mobility   c++14
QMAKE_CXXFLAGS += -std=c++14 -Wall

MOBILITY = 

RESOURCES += \
    zasoby.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

