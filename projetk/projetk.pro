#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T15:43:05
#
#-------------------------------------------------

QT       += core gui widgets
android {
message("* Using settings for Android.")
     QT += androidextras
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetk
TEMPLATE = app


SOURCES += main.cpp\
        program1.cpp

HEADERS  += program1.h

FORMS    += program1.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    zdjecia.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

