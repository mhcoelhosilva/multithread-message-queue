# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/matheussilva/dev/multithread-message-queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/matheussilva/dev/multithread-message-queue/build/release

# Include any dependencies generated for this target.
include CMakeFiles/MMQ.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MMQ.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MMQ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MMQ.dir/flags.make

CMakeFiles/MMQ.dir/src/main.cpp.o: CMakeFiles/MMQ.dir/flags.make
CMakeFiles/MMQ.dir/src/main.cpp.o: /Users/matheussilva/dev/multithread-message-queue/src/main.cpp
CMakeFiles/MMQ.dir/src/main.cpp.o: CMakeFiles/MMQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/matheussilva/dev/multithread-message-queue/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MMQ.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MMQ.dir/src/main.cpp.o -MF CMakeFiles/MMQ.dir/src/main.cpp.o.d -o CMakeFiles/MMQ.dir/src/main.cpp.o -c /Users/matheussilva/dev/multithread-message-queue/src/main.cpp

CMakeFiles/MMQ.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MMQ.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheussilva/dev/multithread-message-queue/src/main.cpp > CMakeFiles/MMQ.dir/src/main.cpp.i

CMakeFiles/MMQ.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MMQ.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheussilva/dev/multithread-message-queue/src/main.cpp -o CMakeFiles/MMQ.dir/src/main.cpp.s

CMakeFiles/MMQ.dir/src/mmq.cpp.o: CMakeFiles/MMQ.dir/flags.make
CMakeFiles/MMQ.dir/src/mmq.cpp.o: /Users/matheussilva/dev/multithread-message-queue/src/mmq.cpp
CMakeFiles/MMQ.dir/src/mmq.cpp.o: CMakeFiles/MMQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/matheussilva/dev/multithread-message-queue/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MMQ.dir/src/mmq.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MMQ.dir/src/mmq.cpp.o -MF CMakeFiles/MMQ.dir/src/mmq.cpp.o.d -o CMakeFiles/MMQ.dir/src/mmq.cpp.o -c /Users/matheussilva/dev/multithread-message-queue/src/mmq.cpp

CMakeFiles/MMQ.dir/src/mmq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MMQ.dir/src/mmq.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheussilva/dev/multithread-message-queue/src/mmq.cpp > CMakeFiles/MMQ.dir/src/mmq.cpp.i

CMakeFiles/MMQ.dir/src/mmq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MMQ.dir/src/mmq.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheussilva/dev/multithread-message-queue/src/mmq.cpp -o CMakeFiles/MMQ.dir/src/mmq.cpp.s

CMakeFiles/MMQ.dir/src/mmq2.cpp.o: CMakeFiles/MMQ.dir/flags.make
CMakeFiles/MMQ.dir/src/mmq2.cpp.o: /Users/matheussilva/dev/multithread-message-queue/src/mmq2.cpp
CMakeFiles/MMQ.dir/src/mmq2.cpp.o: CMakeFiles/MMQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/matheussilva/dev/multithread-message-queue/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MMQ.dir/src/mmq2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MMQ.dir/src/mmq2.cpp.o -MF CMakeFiles/MMQ.dir/src/mmq2.cpp.o.d -o CMakeFiles/MMQ.dir/src/mmq2.cpp.o -c /Users/matheussilva/dev/multithread-message-queue/src/mmq2.cpp

CMakeFiles/MMQ.dir/src/mmq2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MMQ.dir/src/mmq2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheussilva/dev/multithread-message-queue/src/mmq2.cpp > CMakeFiles/MMQ.dir/src/mmq2.cpp.i

CMakeFiles/MMQ.dir/src/mmq2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MMQ.dir/src/mmq2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheussilva/dev/multithread-message-queue/src/mmq2.cpp -o CMakeFiles/MMQ.dir/src/mmq2.cpp.s

CMakeFiles/MMQ.dir/src/naive.cpp.o: CMakeFiles/MMQ.dir/flags.make
CMakeFiles/MMQ.dir/src/naive.cpp.o: /Users/matheussilva/dev/multithread-message-queue/src/naive.cpp
CMakeFiles/MMQ.dir/src/naive.cpp.o: CMakeFiles/MMQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/matheussilva/dev/multithread-message-queue/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MMQ.dir/src/naive.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MMQ.dir/src/naive.cpp.o -MF CMakeFiles/MMQ.dir/src/naive.cpp.o.d -o CMakeFiles/MMQ.dir/src/naive.cpp.o -c /Users/matheussilva/dev/multithread-message-queue/src/naive.cpp

CMakeFiles/MMQ.dir/src/naive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MMQ.dir/src/naive.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheussilva/dev/multithread-message-queue/src/naive.cpp > CMakeFiles/MMQ.dir/src/naive.cpp.i

CMakeFiles/MMQ.dir/src/naive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MMQ.dir/src/naive.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheussilva/dev/multithread-message-queue/src/naive.cpp -o CMakeFiles/MMQ.dir/src/naive.cpp.s

# Object files for target MMQ
MMQ_OBJECTS = \
"CMakeFiles/MMQ.dir/src/main.cpp.o" \
"CMakeFiles/MMQ.dir/src/mmq.cpp.o" \
"CMakeFiles/MMQ.dir/src/mmq2.cpp.o" \
"CMakeFiles/MMQ.dir/src/naive.cpp.o"

# External object files for target MMQ
MMQ_EXTERNAL_OBJECTS =

MMQ: CMakeFiles/MMQ.dir/src/main.cpp.o
MMQ: CMakeFiles/MMQ.dir/src/mmq.cpp.o
MMQ: CMakeFiles/MMQ.dir/src/mmq2.cpp.o
MMQ: CMakeFiles/MMQ.dir/src/naive.cpp.o
MMQ: CMakeFiles/MMQ.dir/build.make
MMQ: CMakeFiles/MMQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/matheussilva/dev/multithread-message-queue/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable MMQ"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MMQ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MMQ.dir/build: MMQ
.PHONY : CMakeFiles/MMQ.dir/build

CMakeFiles/MMQ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MMQ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MMQ.dir/clean

CMakeFiles/MMQ.dir/depend:
	cd /Users/matheussilva/dev/multithread-message-queue/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/matheussilva/dev/multithread-message-queue /Users/matheussilva/dev/multithread-message-queue /Users/matheussilva/dev/multithread-message-queue/build/release /Users/matheussilva/dev/multithread-message-queue/build/release /Users/matheussilva/dev/multithread-message-queue/build/release/CMakeFiles/MMQ.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MMQ.dir/depend

