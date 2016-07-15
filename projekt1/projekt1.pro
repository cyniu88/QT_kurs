#-------------------------------------------------
#
# Project created by QtCreator 2016-07-15T16:06:09
#
#-------------------------------------------------

QT       += core gui network multimedia #androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projekt1
TEMPLATE = app


SOURCES += main.cpp\
        dzien1.cpp \
    qgooglespeech.cpp


HEADERS  += dzien1.h \
    qgooglespeech.h \
    qgooglespeech_global.h


FORMS    += dzien1.ui

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
    android/gradlew.bat \
    android/src/org/qtproject/example/textandroidextras/TestAndroidClient.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

