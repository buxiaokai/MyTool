# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++Test\csTool\demo1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++Test\csTool\demo1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/demo1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo1.dir/flags.make

CMakeFiles/demo1.dir/main.cpp.obj: CMakeFiles/demo1.dir/flags.make
CMakeFiles/demo1.dir/main.cpp.obj: CMakeFiles/demo1.dir/includes_CXX.rsp
CMakeFiles/demo1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++Test\csTool\demo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo1.dir/main.cpp.obj"
	D:\C++Compile\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\demo1.dir\main.cpp.obj -c D:\C++Test\csTool\demo1\main.cpp

CMakeFiles/demo1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo1.dir/main.cpp.i"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++Test\csTool\demo1\main.cpp > CMakeFiles\demo1.dir\main.cpp.i

CMakeFiles/demo1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo1.dir/main.cpp.s"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++Test\csTool\demo1\main.cpp -o CMakeFiles\demo1.dir\main.cpp.s

CMakeFiles/demo1.dir/lib/memory.cpp.obj: CMakeFiles/demo1.dir/flags.make
CMakeFiles/demo1.dir/lib/memory.cpp.obj: CMakeFiles/demo1.dir/includes_CXX.rsp
CMakeFiles/demo1.dir/lib/memory.cpp.obj: ../lib/memory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++Test\csTool\demo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/demo1.dir/lib/memory.cpp.obj"
	D:\C++Compile\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\demo1.dir\lib\memory.cpp.obj -c D:\C++Test\csTool\demo1\lib\memory.cpp

CMakeFiles/demo1.dir/lib/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo1.dir/lib/memory.cpp.i"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++Test\csTool\demo1\lib\memory.cpp > CMakeFiles\demo1.dir\lib\memory.cpp.i

CMakeFiles/demo1.dir/lib/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo1.dir/lib/memory.cpp.s"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++Test\csTool\demo1\lib\memory.cpp -o CMakeFiles\demo1.dir\lib\memory.cpp.s

CMakeFiles/demo1.dir/lib/cssdk.cpp.obj: CMakeFiles/demo1.dir/flags.make
CMakeFiles/demo1.dir/lib/cssdk.cpp.obj: CMakeFiles/demo1.dir/includes_CXX.rsp
CMakeFiles/demo1.dir/lib/cssdk.cpp.obj: ../lib/cssdk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++Test\csTool\demo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/demo1.dir/lib/cssdk.cpp.obj"
	D:\C++Compile\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\demo1.dir\lib\cssdk.cpp.obj -c D:\C++Test\csTool\demo1\lib\cssdk.cpp

CMakeFiles/demo1.dir/lib/cssdk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo1.dir/lib/cssdk.cpp.i"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++Test\csTool\demo1\lib\cssdk.cpp > CMakeFiles\demo1.dir\lib\cssdk.cpp.i

CMakeFiles/demo1.dir/lib/cssdk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo1.dir/lib/cssdk.cpp.s"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++Test\csTool\demo1\lib\cssdk.cpp -o CMakeFiles\demo1.dir\lib\cssdk.cpp.s

CMakeFiles/demo1.dir/lib/renderer.cpp.obj: CMakeFiles/demo1.dir/flags.make
CMakeFiles/demo1.dir/lib/renderer.cpp.obj: CMakeFiles/demo1.dir/includes_CXX.rsp
CMakeFiles/demo1.dir/lib/renderer.cpp.obj: ../lib/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++Test\csTool\demo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/demo1.dir/lib/renderer.cpp.obj"
	D:\C++Compile\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\demo1.dir\lib\renderer.cpp.obj -c D:\C++Test\csTool\demo1\lib\renderer.cpp

CMakeFiles/demo1.dir/lib/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo1.dir/lib/renderer.cpp.i"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++Test\csTool\demo1\lib\renderer.cpp > CMakeFiles\demo1.dir\lib\renderer.cpp.i

CMakeFiles/demo1.dir/lib/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo1.dir/lib/renderer.cpp.s"
	D:\C++Compile\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++Test\csTool\demo1\lib\renderer.cpp -o CMakeFiles\demo1.dir\lib\renderer.cpp.s

# Object files for target demo1
demo1_OBJECTS = \
"CMakeFiles/demo1.dir/main.cpp.obj" \
"CMakeFiles/demo1.dir/lib/memory.cpp.obj" \
"CMakeFiles/demo1.dir/lib/cssdk.cpp.obj" \
"CMakeFiles/demo1.dir/lib/renderer.cpp.obj"

# External object files for target demo1
demo1_EXTERNAL_OBJECTS =

demo1.exe: CMakeFiles/demo1.dir/main.cpp.obj
demo1.exe: CMakeFiles/demo1.dir/lib/memory.cpp.obj
demo1.exe: CMakeFiles/demo1.dir/lib/cssdk.cpp.obj
demo1.exe: CMakeFiles/demo1.dir/lib/renderer.cpp.obj
demo1.exe: CMakeFiles/demo1.dir/build.make
demo1.exe: CMakeFiles/demo1.dir/linklibs.rsp
demo1.exe: CMakeFiles/demo1.dir/objects1.rsp
demo1.exe: CMakeFiles/demo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++Test\csTool\demo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable demo1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\demo1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo1.dir/build: demo1.exe

.PHONY : CMakeFiles/demo1.dir/build

CMakeFiles/demo1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\demo1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/demo1.dir/clean

CMakeFiles/demo1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++Test\csTool\demo1 D:\C++Test\csTool\demo1 D:\C++Test\csTool\demo1\cmake-build-debug D:\C++Test\csTool\demo1\cmake-build-debug D:\C++Test\csTool\demo1\cmake-build-debug\CMakeFiles\demo1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo1.dir/depend

