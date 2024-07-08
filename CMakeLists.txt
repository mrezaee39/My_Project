cmake_minimum_required(VERSION 3.5)

project(MyQmlProject)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

qt5_add_resources(QT_RESOURCES resources.qrc)

add_executable(MyQmlProject main.cpp ${QT_RESOURCES})

target_link_libraries(MyQmlProject Qt5::Core Qt5::Quick)