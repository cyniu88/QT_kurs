#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T13:23:02
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pilot
TEMPLATE = app


SOURCES += main.cpp\
        pilotwindow.cpp \
    joypad.cpp \
    mybutton.cpp \
    touchbutton.cpp

HEADERS  += pilotwindow.h \
    joypad.h \
    mybutton.h \
    touchbutton.h

FORMS    += pilotwindow.ui

CONFIG += mobility
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
