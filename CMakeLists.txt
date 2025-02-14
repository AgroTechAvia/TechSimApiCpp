cmake_minimum_required(VERSION 3.15)

project(SimClient VERSION 1.0)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/dependencies/rpclib/cmake")
set(RPCLIB_LIBS "${PROJECT_SOURCE_DIR}/dependencies/rpclib/build/Debug/rpc.lib")

find_package(rpclib REQUIRED)

include_directories(${RPCLIB_INCLUDE_DIR})

add_library(SimClient src/SimClient.cpp)


target_include_directories(SimClient PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/rpclib/include")
target_link_libraries(SimClient PUBLIC ${RPCLIB_LIBS})

install(TARGETS SimClient
    EXPORT SimClientTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT SimClientTargets
    FILE SimClientTargets.cmake
    NAMESPACE SimClient::
    DESTINATION lib/cmake/SimClient
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/SimClientConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_file(cmake/SimClientConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/SimClientConfig.cmake"
    @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/SimClientConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/SimClientConfigVersion.cmake"
    DESTINATION lib/cmake/SimClient
)

#mkdir build
#cd build
#cmake ..
#cmake --build . --config Debug
#cmake --install . --prefix "../install" --config Debug