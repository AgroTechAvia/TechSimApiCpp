# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/TechSimApiCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/TechSimApiCpp/build

# Include any dependencies generated for this target.
include CMakeFiles/SimClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SimClient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SimClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimClient.dir/flags.make

CMakeFiles/SimClient.dir/src/SimClient.cpp.o: CMakeFiles/SimClient.dir/flags.make
CMakeFiles/SimClient.dir/src/SimClient.cpp.o: ../src/SimClient.cpp
CMakeFiles/SimClient.dir/src/SimClient.cpp.o: CMakeFiles/SimClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/TechSimApiCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimClient.dir/src/SimClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimClient.dir/src/SimClient.cpp.o -MF CMakeFiles/SimClient.dir/src/SimClient.cpp.o.d -o CMakeFiles/SimClient.dir/src/SimClient.cpp.o -c /home/user/TechSimApiCpp/src/SimClient.cpp

CMakeFiles/SimClient.dir/src/SimClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimClient.dir/src/SimClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/TechSimApiCpp/src/SimClient.cpp > CMakeFiles/SimClient.dir/src/SimClient.cpp.i

CMakeFiles/SimClient.dir/src/SimClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimClient.dir/src/SimClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/TechSimApiCpp/src/SimClient.cpp -o CMakeFiles/SimClient.dir/src/SimClient.cpp.s

# Object files for target SimClient
SimClient_OBJECTS = \
"CMakeFiles/SimClient.dir/src/SimClient.cpp.o"

# External object files for target SimClient
SimClient_EXTERNAL_OBJECTS =

libSimClient.a: CMakeFiles/SimClient.dir/src/SimClient.cpp.o
libSimClient.a: CMakeFiles/SimClient.dir/build.make
libSimClient.a: CMakeFiles/SimClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/TechSimApiCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSimClient.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SimClient.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimClient.dir/build: libSimClient.a
.PHONY : CMakeFiles/SimClient.dir/build

CMakeFiles/SimClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimClient.dir/clean

CMakeFiles/SimClient.dir/depend:
	cd /home/user/TechSimApiCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/TechSimApiCpp /home/user/TechSimApiCpp /home/user/TechSimApiCpp/build /home/user/TechSimApiCpp/build /home/user/TechSimApiCpp/build/CMakeFiles/SimClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimClient.dir/depend

