#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SimClient::SimClient" for configuration ""
set_property(TARGET SimClient::SimClient APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SimClient::SimClient PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libSimClient.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SimClient::SimClient )
list(APPEND _IMPORT_CHECK_FILES_FOR_SimClient::SimClient "${_IMPORT_PREFIX}/lib/libSimClient.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
