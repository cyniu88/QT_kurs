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
    functions.cpp \
    workerip.cpp \
    gear_BOX/gear_box.cpp \
    mytouchslider.cpp \
    force_back/force_back.cpp \
    ../libs/config_files/config_files.cpp \
    ../libs/android_functions/android_interface/android_interface.cpp \
    ../iDom_Client/mybutton/mybutton.cpp
android {
            message("* Using settings for Android.")
            SOURCES  += ../libs/android_functions/androidhelper_cyniu.cpp
        }


HEADERS  += pilotwindow.h \
    joypad.h \
    functions.h \
    workerip.h \
    variable.h \
    gear_BOX/gear_box.h \
    mytouchslider.h \
    force_back/force_back.h \
    ../libs/android_functions/android_interface/android_interface.h \
    ../libs/config_files/config_files.h \
    ../iDom_Client/mybutton/mybutton.h
android {
            message("* Using settings for Android.")
            HEADERS  += ../libs/android_functions/androidhelper_cyniu.h
        }


FORMS    += pilotwindow.ui
CONFIG += mobility   c++14
QMAKE_CXXFLAGS += -std=c++14 -Wall

MOBILITY = 

RESOURCES += \
    zasoby.qrc
OTHER_FILES += games_256.ico
DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/src/org/qtproject/example/Chronometer/AndroidHelper.java
win32:RC_ICONS += games_256.ico

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

