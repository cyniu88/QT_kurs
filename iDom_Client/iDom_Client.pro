#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T16:36:52
#
#-------------------------------------------------

QT += core gui network sensors texttospeech svg #
linux {
            message("* Using settings for Linux.")
            QT +=
}
windows {
            message("* Using settings for Windows.")
            QT +=  axcontainer qml
}
android {
            message("* Using settings for Android.")
            QT +=  androidextras webview quickwidgets
        }
MOBILITY = androidextras
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = iDom_Client
TEMPLATE = app
#LIBS = -landroid

INCLUDEPATH = $$PWD/json2

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

CONFIG += mobility   c++17
QMAKE_CXXFLAGS += -std=c++1y -Wall  -pedantic -Woverlength-strings -DIDOM

QMAKE_LINK    = $$QMAKE_CXX $$QMAKE_CFLAGS -Wl,--exclude-libs,libgcc.a -Wl,--exclude-libs,libatomic.a



RESOURCES += \
    ikony.qrc


win32:RC_ICONS += iDom_client.ico

OTHER_FILES += \
    android/src/org/qtproject/example/Chronometer/AndroidHelper.java \
    android/AndroidManifest.xml

DISTFILES += \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

