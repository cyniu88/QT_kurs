#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T13:23:02
#
#-------------------------------------------------

QT       += core gui widgets network gamepad
android {
            message("* Using settings for Android.")
            QT +=  androidextras sensors

        }
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pilot
TEMPLATE = app


SOURCES += main.cpp\
        pilotwindow.cpp \
    joypad.cpp \
    mybutton.cpp \
    functions.cpp \
    workerip.cpp \
    gear_BOX/gear_box.cpp \
    mytouchslider.cpp \
    android_interface/android_interface.cpp \
    force_back/force_back.cpp \
    ../libs/config_files/config_files.cpp
android {
            message("* Using settings for Android.")
            SOURCES  +=  androidhelper_cyniu.cpp
        }


HEADERS  += pilotwindow.h \
    joypad.h \
    mybutton.h \
    functions.h \
    workerip.h \
    variable.h \
    gear_BOX/gear_box.h \
    mytouchslider.h \
    android_interface/android_interface.h \
    force_back/force_back.h \
    ../libs/config_files/config_files.h
android {
            message("* Using settings for Android.")
            HEADERS  +=  androidhelper_cyniu.h
        }


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
    android/gradlew.bat \
    android/src/org/qtproject/example/Chronometer/AndroidHelper.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

