cmake_minimum_required(VERSION 3.10.0)
project(AgroTechSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/include/rpclib/cmake")
find_package(rpclib REQUIRED)

include_directories(${RPCLIB_INCLUDE_DIR})

# Определение источников и заголовков для вашего клиента
set(SIMCLIENT_SOURCES
    src/TechSimApiClient.cpp
)

set(SIMCLIENT_HEADERS
    include/TechSimApiClient.h
)

# Создание статической библиотеки
add_library(AgroTechSimApi STATIC ${SIMCLIENT_SOURCES} ${SIMCLIENT_HEADERS})

# Линковка с библиотекой rpclib
target_link_libraries(AgroTechSimApi rpclib::rpc)