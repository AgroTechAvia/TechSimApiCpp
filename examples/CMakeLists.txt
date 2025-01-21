cmake_minimum_required(VERSION 3.15)

project(SimClientExample)


set(CMAKE_PREFIX_PATH "../install")

find_package(SimClient REQUIRED)

find_package(OpenCV REQUIRED)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE SimClient::SimClient ${OpenCV_LIBS})

#mkdir build
#cd build
#cmake ..
#cmake --build . --config Debug