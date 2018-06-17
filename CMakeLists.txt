cmake_minimum_required(VERSION 3.1)
project(videosave)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)
add_executable(videosave main.cpp
        ${OpenCV_INCLUDE_DIRS})
target_link_libraries(videosave
        ${OpenCV_LIBRARIES})