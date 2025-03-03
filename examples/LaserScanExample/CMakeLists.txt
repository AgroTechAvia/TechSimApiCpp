cmake_minimum_required(VERSION 3.15)

project(SimClientExample VERSION 1.0 LANGUAGES CXX)

#add_subdirectory(techsimapi)

add_executable(LaserScanExample LaserScanExample.cpp)

target_link_libraries(LaserScanExample PRIVATE techsimapi)
#mkdir build
#cd build
#cmake ..
#cmake --build . --config Debug