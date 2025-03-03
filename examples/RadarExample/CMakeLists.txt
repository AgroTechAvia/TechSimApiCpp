cmake_minimum_required(VERSION 3.15)

project(SimClientExample VERSION 1.0 LANGUAGES CXX)

#add_subdirectory(techsimapi)

add_executable(RadarExample RadarExample.cpp)

target_link_libraries(RadarExample PRIVATE techsimapi)

#mkdir build
#cd build
#cmake ..
#cmake --build . --config Debug