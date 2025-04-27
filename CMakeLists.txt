cmake_minimum_required(VERSION 3.5)
project(ImageViewer)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(image_viewer main.cpp)
target_link_libraries(image_viewer ${OpenCV_LIBS})
