cmake_minimum_required(VERSION 3.15)

project(techsimapi VERSION 1.0)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/dependencies/rpclib/cmake")

if(WIN32)
    set(RPCLIB_LIBS "${PROJECT_SOURCE_DIR}/dependencies/rpclib/build/Debug/rpc.lib")
elseif(UNIX)
    set(RPCLIB_LIBS "${PROJECT_SOURCE_DIR}/dependencies/rpclib/build/librpc.a")
endif()

find_package(rpclib REQUIRED)

include_directories(${RPCLIB_INCLUDE_DIR})

include_directories(include)

add_library(techsimapi STATIC
    src/SimClient.cpp
)

target_include_directories(techsimapi PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(techsimapi PRIVATE ${RPCLIB_LIBS})

#git submodule init 
#git submodule update 
#mkdir build
#cd build
#cmake ..
#cmake --build .