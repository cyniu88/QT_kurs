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

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++1y -Wall  -pedantic -Woverlength-strings -DIDOM
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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

RESOURCES += \
        ikony.qrc

win32:RC_ICONS += iDom_client.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android


