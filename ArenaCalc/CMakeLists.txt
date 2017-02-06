cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(ArenaCalc)

macro(remove_cxx_flag_release flag)
  string(REPLACE "${flag}" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
endmacro()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-O1")
remove_cxx_flag_release("-O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

#set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
#set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_definitions(
    -DQT_NO_CAST_FROM_ASCII
    -DQT_NO_CAST_TO_ASCII
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(QT5_LIBRARIES Qt5::Widgets)

set(TARGET ${CMAKE_PROJECT_NAME})

set(SOURCES
    main.cpp
    mainwindow.cpp
    randomdialog.cpp
    randomholder.cpp
    commonstringholder.cpp
)

set(UI_SOURCES
    mainwindow.ui
    randomdialog.ui
)

qt5_wrap_ui(UI_GENERATED_HEADERS ${UI_SOURCES})

add_executable(${TARGET} ${SOURCES} ${UI_GENERATED_HEADERS})

target_link_libraries(${TARGET} ${QT5_LIBRARIES})
