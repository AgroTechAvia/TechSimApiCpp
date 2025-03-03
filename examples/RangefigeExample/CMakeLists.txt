cmake_minimum_required(VERSION 3.15)

project(SimClientExample VERSION 1.0 LANGUAGES CXX)

#add_subdirectory(techsimapi)

add_executable(RangefireExample RangefireExample.cpp)

target_link_libraries(RangefireExample PRIVATE techsimapi)

#mkdir build
#cd build
#cmake ..
#cmake --build . --config Debug