#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T16:36:52
#
#-------------------------------------------------

QT += core gui network sensors
android {
            message("* Using settings for Android.")
            QT +=  androidextras
        }
MOBILITY = androidextras
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = iDom_Client
TEMPLATE = app
#LIBS = -landroid

SOURCES += main.cpp\
        idom_client.cpp \
    workerip.cpp \
    functions.cpp \
    blocking_queue/blocking_queue.cpp \
    android_interface/android_interface.cpp
android {
            message("* Using settings for Android.")
            SOURCES  +=  androidhelper_cyniu.cpp
        }

HEADERS  += idom_client.h \
    variable.h \
    workerip.h \
    functions.h \
    blocking_queue/blocking_queue.h \
    android_interface/android_interface.h
android {
            message("* Using settings for Android.")
            HEADERS +=  androidhelper_cyniu.h
        }


FORMS    += idom_client.ui

CONFIG += mobility   c++11
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic


OTHER_FILES += \
    iDom_client.ico \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/src/org/qtproject/example/Chronometer/Vibrate.java

RESOURCES += \
    ikony.qrc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

win32:RC_ICONS += iDom_client.ico

DISTFILES += \
    android/src/org/qtproject/example/Chronometer/AndroidHelper.java
