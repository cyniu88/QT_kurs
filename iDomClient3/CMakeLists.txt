cmake_minimum_required(VERSION 3.5)

project(iDomClient3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT " -D -Wall")
add_compile_definitions(IDOM)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets AxContainer SvgWidgets LinguistTools CorePrivate)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network TextToSpeech SvgWidgets LinguistTools WebView Sensors Core)


set(TS_FILES iDomClient3_pl_PL.ts)

set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/resources/iDomClient3.rc")

set(INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/mybutton/" "${CMAKE_CURRENT_SOURCE_DIR}/json2/")

file(GLOB iDomClient3_SRC
    "*.h"
    "*.cpp"
    "*.ui"
    "mybutton/*"
    "blocking_queue/*"
)

if(ANDROID)
    set(andek ../libs/android_functions/androidhelper_cyniu.cpp)
else()
    set(andek)
endif()
set(PROJECT_SOURCES
    main.cpp
    idom_client.cpp
    idom_client.h
    idom_client.ui
    ikony.qrc
    ../libs/android_functions/android_interface/android_interface.cpp
    ../libs/sgvTEST/thermometerSVG/thermometer.cpp
    ../libs/config_files/config_files.cpp
    ../libs/useful/usefull.cpp
    ../libs/emoji/emoji.cpp
    ${andek}
    ${TS_FILES}

    ${iDomClient3_SRC}
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(iDomClient3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${app_icon_resource_windows}
    )
# Define target properties for Android with Qt 6 as:
set_property(TARGET iDomClient3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(iDomClient3 SHARED
            ${PROJECT_SOURCES}
        )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    add_executable(iDomClient3
        ${PROJECT_SOURCES}
    )
endif()

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::SvgWidgets)
target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::TextToSpeech)
target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::WebView)
target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::Sensors)
target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(iDomClient3 PRIVATE Qt${QT_VERSION_MAJOR}::CorePrivate)

target_include_directories(iDomClient3 PRIVATE "${INCLUDE_DIRECTORIES}")

set_target_properties(iDomClient3 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)



install(TARGETS iDomClient3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(iDomClient3)
endif()
