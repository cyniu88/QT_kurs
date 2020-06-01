#-------------------------------------------------
#
# Project created by QtCreator 2018-11-30T21:12:02
#
#-------------------------------------------------

QT       += core gui sensors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

android {
            message("* Using settings for Android.")
            QT +=  androidextras webview quickwidgets
}

TARGET = prezenty
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ../libs/android_functions/android_interface/android_interface.cpp
android {
            message("* Using settings for Android.")
            SOURCES  +=  ../libs/android_functions/androidhelper_cyniu.cpp
}
HEADERS += \
        mainwindow.h \
    ../libs/android_functions/android_interface/android_interface.h \
    data.h

android {
            message("* Using settings for Android.")
            HEADERS +=  ../libs/android_functions/androidhelper_cyniu.h
}
FORMS += \
        mainwindow.ui

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

QMAKE_LINK    = $$QMAKE_CXX $$QMAKE_CFLAGS -Wl,--exclude-libs,libgcc.a -Wl,--exclude-libs,libatomic.a -nostdlib++
