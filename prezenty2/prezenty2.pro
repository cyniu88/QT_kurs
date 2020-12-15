QT       += core gui
android {
    QT  += androidextras sensors
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
MOBILITY = androidextras
SOURCES += \
    main.cpp \
    mainwindow.cpp\
    ../libs/android_functions/android_interface/android_interface.cpp
    android {
                message("* Using settings for Android.")
                SOURCES  +=  ../libs/android_functions/androidhelper_cyniu.cpp
    }
HEADERS += \
    mainwindow.h \
    data.h \
    ../libs/android_functions/android_interface/android_interface.h
    android {
                message("* Using settings for Android.")
                HEADERS +=  ../libs/android_functions/androidhelper_cyniu.h
    }

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

ANDROID_ABIS = armeabi-v7a

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
