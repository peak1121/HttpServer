# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/peak/moduo/HttpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/peak/moduo/HttpServer/build/release

# Include any dependencies generated for this target.
include base/tests/CMakeFiles/timestamp_test.dir/depend.make

# Include the progress variables for this target.
include base/tests/CMakeFiles/timestamp_test.dir/progress.make

# Include the compile flags for this target's objects.
include base/tests/CMakeFiles/timestamp_test.dir/flags.make

base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o: base/tests/CMakeFiles/timestamp_test.dir/flags.make
base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o: ../../base/tests/TimeStamp_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peak/moduo/HttpServer/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o"
	cd /home/peak/moduo/HttpServer/build/release/base/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o -c /home/peak/moduo/HttpServer/base/tests/TimeStamp_test.cc

base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.i"
	cd /home/peak/moduo/HttpServer/build/release/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peak/moduo/HttpServer/base/tests/TimeStamp_test.cc > CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.i

base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.s"
	cd /home/peak/moduo/HttpServer/build/release/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peak/moduo/HttpServer/base/tests/TimeStamp_test.cc -o CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.s

base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.requires:

.PHONY : base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.requires

base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.provides: base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.requires
	$(MAKE) -f base/tests/CMakeFiles/timestamp_test.dir/build.make base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.provides.build
.PHONY : base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.provides

base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.provides.build: base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o


# Object files for target timestamp_test
timestamp_test_OBJECTS = \
"CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o"

# External object files for target timestamp_test
timestamp_test_EXTERNAL_OBJECTS =

bin/timestamp_test: base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o
bin/timestamp_test: base/tests/CMakeFiles/timestamp_test.dir/build.make
bin/timestamp_test: lib/libbase.a
bin/timestamp_test: base/tests/CMakeFiles/timestamp_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/peak/moduo/HttpServer/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/timestamp_test"
	cd /home/peak/moduo/HttpServer/build/release/base/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timestamp_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/tests/CMakeFiles/timestamp_test.dir/build: bin/timestamp_test

.PHONY : base/tests/CMakeFiles/timestamp_test.dir/build

base/tests/CMakeFiles/timestamp_test.dir/requires: base/tests/CMakeFiles/timestamp_test.dir/TimeStamp_test.cc.o.requires

.PHONY : base/tests/CMakeFiles/timestamp_test.dir/requires

base/tests/CMakeFiles/timestamp_test.dir/clean:
	cd /home/peak/moduo/HttpServer/build/release/base/tests && $(CMAKE_COMMAND) -P CMakeFiles/timestamp_test.dir/cmake_clean.cmake
.PHONY : base/tests/CMakeFiles/timestamp_test.dir/clean

base/tests/CMakeFiles/timestamp_test.dir/depend:
	cd /home/peak/moduo/HttpServer/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peak/moduo/HttpServer /home/peak/moduo/HttpServer/base/tests /home/peak/moduo/HttpServer/build/release /home/peak/moduo/HttpServer/build/release/base/tests /home/peak/moduo/HttpServer/build/release/base/tests/CMakeFiles/timestamp_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/tests/CMakeFiles/timestamp_test.dir/depend
