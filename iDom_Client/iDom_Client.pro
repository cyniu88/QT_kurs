#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T16:36:52
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = iDom_Client
TEMPLATE = app
#LIBS = -landroid

SOURCES += main.cpp\
        idom_client.cpp \
    workerip.cpp \
    functions.cpp

HEADERS  += idom_client.h \
    variable.h \
    workerip.h \
    functions.h

FORMS    += idom_client.ui

CONFIG += mobility   c++11
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic
MOBILITY = 

DISTFILES += \
    iDom_client.ico \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

RESOURCES += \
    ikony.qrc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

