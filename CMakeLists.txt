cmake_minimum_required(VERSION 3.16)

project(PointPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)

add_executable(PointPlayer
        src/main.cpp
        src/MainWindow.cpp
        src/PlotWidget.cpp
        src/PointGenerator.cpp
)

target_link_libraries(PointPlayer Qt6::Widgets)
