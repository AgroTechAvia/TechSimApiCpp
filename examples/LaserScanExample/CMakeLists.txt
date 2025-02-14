cmake_minimum_required(VERSION 3.15)

project(SimClientExample VERSION 1.0 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "../../install")
find_package(SimClient REQUIRED)

add_executable(LaserScanExample LaserScanExample.cpp)

target_link_libraries(LaserScanExample PRIVATE SimClient::SimClient)
#mkdir build
#cd build
#cmake ..
#cmake --build . --config Debug