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
include net/CMakeFiles/net.dir/depend.make

# Include the progress variables for this target.
include net/CMakeFiles/net.dir/progress.make

# Include the compile flags for this target's objects.
include net/CMakeFiles/net.dir/flags.make

net/CMakeFiles/net.dir/netTest.cc.o: net/CMakeFiles/net.dir/flags.make
net/CMakeFiles/net.dir/netTest.cc.o: ../../net/netTest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peak/moduo/HttpServer/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object net/CMakeFiles/net.dir/netTest.cc.o"
	cd /home/peak/moduo/HttpServer/build/release/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/netTest.cc.o -c /home/peak/moduo/HttpServer/net/netTest.cc

net/CMakeFiles/net.dir/netTest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/netTest.cc.i"
	cd /home/peak/moduo/HttpServer/build/release/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peak/moduo/HttpServer/net/netTest.cc > CMakeFiles/net.dir/netTest.cc.i

net/CMakeFiles/net.dir/netTest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/netTest.cc.s"
	cd /home/peak/moduo/HttpServer/build/release/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peak/moduo/HttpServer/net/netTest.cc -o CMakeFiles/net.dir/netTest.cc.s

net/CMakeFiles/net.dir/netTest.cc.o.requires:

.PHONY : net/CMakeFiles/net.dir/netTest.cc.o.requires

net/CMakeFiles/net.dir/netTest.cc.o.provides: net/CMakeFiles/net.dir/netTest.cc.o.requires
	$(MAKE) -f net/CMakeFiles/net.dir/build.make net/CMakeFiles/net.dir/netTest.cc.o.provides.build
.PHONY : net/CMakeFiles/net.dir/netTest.cc.o.provides

net/CMakeFiles/net.dir/netTest.cc.o.provides.build: net/CMakeFiles/net.dir/netTest.cc.o


# Object files for target net
net_OBJECTS = \
"CMakeFiles/net.dir/netTest.cc.o"

# External object files for target net
net_EXTERNAL_OBJECTS =

lib/libnet.a: net/CMakeFiles/net.dir/netTest.cc.o
lib/libnet.a: net/CMakeFiles/net.dir/build.make
lib/libnet.a: net/CMakeFiles/net.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/peak/moduo/HttpServer/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/libnet.a"
	cd /home/peak/moduo/HttpServer/build/release/net && $(CMAKE_COMMAND) -P CMakeFiles/net.dir/cmake_clean_target.cmake
	cd /home/peak/moduo/HttpServer/build/release/net && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/net.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
net/CMakeFiles/net.dir/build: lib/libnet.a

.PHONY : net/CMakeFiles/net.dir/build

net/CMakeFiles/net.dir/requires: net/CMakeFiles/net.dir/netTest.cc.o.requires

.PHONY : net/CMakeFiles/net.dir/requires

net/CMakeFiles/net.dir/clean:
	cd /home/peak/moduo/HttpServer/build/release/net && $(CMAKE_COMMAND) -P CMakeFiles/net.dir/cmake_clean.cmake
.PHONY : net/CMakeFiles/net.dir/clean

net/CMakeFiles/net.dir/depend:
	cd /home/peak/moduo/HttpServer/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peak/moduo/HttpServer /home/peak/moduo/HttpServer/net /home/peak/moduo/HttpServer/build/release /home/peak/moduo/HttpServer/build/release/net /home/peak/moduo/HttpServer/build/release/net/CMakeFiles/net.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : net/CMakeFiles/net.dir/depend

