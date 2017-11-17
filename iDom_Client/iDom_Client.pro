#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T16:36:52
#
#-------------------------------------------------

QT += core gui network sensors svg texttospeech quickwidgets
windows {
            message("* Using settings for Windows.")
            QT +=  axcontainer
}
android {
            message("* Using settings for Android.")
            QT +=  androidextras webview

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
            ../libs/android_functions/android_interface/android_interface.cpp \
            wwwshowwindow.cpp \
            filedownloader.cpp \
            ../libs/sgvTEST/thermometerSVG/thermometer.cpp \
            volumedialog.cpp \
            frameoptions.cpp \
            ../libs/config_files/config_files.cpp \
    mybutton/mybutton.cpp \
    setalarm.cpp \
    ../libs/useful/usefull.cpp
android {
            message("* Using settings for Android.")
            SOURCES  +=  ../libs/android_functions/androidhelper_cyniu.cpp
        }

HEADERS  += idom_client.h \
            variable.h \
            workerip.h \
            functions.h \
            blocking_queue/blocking_queue.h \
            ../libs/android_functions/android_interface/android_interface.h \
            wwwshowwindow.h \
            filedownloader.h \
            ../libs/sgvTEST/thermometerSVG/thermometer.h \
            volumedialog.h \
            frameoptions.h \
            ../libs/config_files/config_files.h \
    mybutton/mybutton.h \
    setalarm.h \
    ../libs/useful/useful.h
android {
            message("* Using settings for Android.")
            HEADERS +=  ../libs/android_functions/androidhelper_cyniu.h
        }


FORMS    += idom_client.ui \
            wwwshowwindow.ui \
    volumedialog.ui \
    frameoptions.ui \
    setalarm.ui

CONFIG += mobility   c++14
QMAKE_CXXFLAGS += -std=c++1y -Wall  -pedantic


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
    android/src/org/qtproject/example/Chronometer/AndroidHelper.java \
    myqmlfile.qml \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle
