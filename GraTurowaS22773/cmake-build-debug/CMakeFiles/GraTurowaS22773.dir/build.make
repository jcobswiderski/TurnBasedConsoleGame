# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Admin\Documents\GraTurowaS22773

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Admin\Documents\GraTurowaS22773\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GraTurowaS22773.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/GraTurowaS22773.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GraTurowaS22773.dir/flags.make

CMakeFiles/GraTurowaS22773.dir/main.cpp.obj: CMakeFiles/GraTurowaS22773.dir/flags.make
CMakeFiles/GraTurowaS22773.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Admin\Documents\GraTurowaS22773\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GraTurowaS22773.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GraTurowaS22773.dir\main.cpp.obj -c C:\Users\Admin\Documents\GraTurowaS22773\main.cpp

CMakeFiles/GraTurowaS22773.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraTurowaS22773.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Admin\Documents\GraTurowaS22773\main.cpp > CMakeFiles\GraTurowaS22773.dir\main.cpp.i

CMakeFiles/GraTurowaS22773.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraTurowaS22773.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Admin\Documents\GraTurowaS22773\main.cpp -o CMakeFiles\GraTurowaS22773.dir\main.cpp.s

CMakeFiles/GraTurowaS22773.dir/Creature.cpp.obj: CMakeFiles/GraTurowaS22773.dir/flags.make
CMakeFiles/GraTurowaS22773.dir/Creature.cpp.obj: ../Creature.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Admin\Documents\GraTurowaS22773\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GraTurowaS22773.dir/Creature.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GraTurowaS22773.dir\Creature.cpp.obj -c C:\Users\Admin\Documents\GraTurowaS22773\Creature.cpp

CMakeFiles/GraTurowaS22773.dir/Creature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraTurowaS22773.dir/Creature.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Admin\Documents\GraTurowaS22773\Creature.cpp > CMakeFiles\GraTurowaS22773.dir\Creature.cpp.i

CMakeFiles/GraTurowaS22773.dir/Creature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraTurowaS22773.dir/Creature.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Admin\Documents\GraTurowaS22773\Creature.cpp -o CMakeFiles\GraTurowaS22773.dir\Creature.cpp.s

# Object files for target GraTurowaS22773
GraTurowaS22773_OBJECTS = \
"CMakeFiles/GraTurowaS22773.dir/main.cpp.obj" \
"CMakeFiles/GraTurowaS22773.dir/Creature.cpp.obj"

# External object files for target GraTurowaS22773
GraTurowaS22773_EXTERNAL_OBJECTS =

GraTurowaS22773.exe: CMakeFiles/GraTurowaS22773.dir/main.cpp.obj
GraTurowaS22773.exe: CMakeFiles/GraTurowaS22773.dir/Creature.cpp.obj
GraTurowaS22773.exe: CMakeFiles/GraTurowaS22773.dir/build.make
GraTurowaS22773.exe: CMakeFiles/GraTurowaS22773.dir/linklibs.rsp
GraTurowaS22773.exe: CMakeFiles/GraTurowaS22773.dir/objects1.rsp
GraTurowaS22773.exe: CMakeFiles/GraTurowaS22773.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Admin\Documents\GraTurowaS22773\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GraTurowaS22773.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GraTurowaS22773.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GraTurowaS22773.dir/build: GraTurowaS22773.exe
.PHONY : CMakeFiles/GraTurowaS22773.dir/build

CMakeFiles/GraTurowaS22773.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GraTurowaS22773.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GraTurowaS22773.dir/clean

CMakeFiles/GraTurowaS22773.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Admin\Documents\GraTurowaS22773 C:\Users\Admin\Documents\GraTurowaS22773 C:\Users\Admin\Documents\GraTurowaS22773\cmake-build-debug C:\Users\Admin\Documents\GraTurowaS22773\cmake-build-debug C:\Users\Admin\Documents\GraTurowaS22773\cmake-build-debug\CMakeFiles\GraTurowaS22773.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GraTurowaS22773.dir/depend

