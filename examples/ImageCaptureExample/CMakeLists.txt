cmake_minimum_required(VERSION 3.15)

project(SimClientExample VERSION 1.0 LANGUAGES CXX)

find_package(OpenCV REQUIRED)

#add_subdirectory(techsimapi)

add_executable(GetImageExample GetImageExample.cpp)

target_link_libraries(GetImageExample PRIVATE techsimapi ${OpenCV_LIBS})

#mkdir build
#cd build
#cmake ..
#cmake --build . --config Debug
