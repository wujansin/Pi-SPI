# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/tbox/project/pi-io-test/spi/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tbox/project/pi-io-test/spi/build

# Include any dependencies generated for this target.
include CMakeFiles/spi_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spi_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spi_test.dir/flags.make

CMakeFiles/spi_test.dir/spi_test.c.o: CMakeFiles/spi_test.dir/flags.make
CMakeFiles/spi_test.dir/spi_test.c.o: /home/tbox/project/pi-io-test/spi/src/spi_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tbox/project/pi-io-test/spi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/spi_test.dir/spi_test.c.o"
	/usr/bin/arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spi_test.dir/spi_test.c.o -c /home/tbox/project/pi-io-test/spi/src/spi_test.c

CMakeFiles/spi_test.dir/spi_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spi_test.dir/spi_test.c.i"
	/usr/bin/arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tbox/project/pi-io-test/spi/src/spi_test.c > CMakeFiles/spi_test.dir/spi_test.c.i

CMakeFiles/spi_test.dir/spi_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spi_test.dir/spi_test.c.s"
	/usr/bin/arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tbox/project/pi-io-test/spi/src/spi_test.c -o CMakeFiles/spi_test.dir/spi_test.c.s

# Object files for target spi_test
spi_test_OBJECTS = \
"CMakeFiles/spi_test.dir/spi_test.c.o"

# External object files for target spi_test
spi_test_EXTERNAL_OBJECTS =

spi_test: CMakeFiles/spi_test.dir/spi_test.c.o
spi_test: CMakeFiles/spi_test.dir/build.make
spi_test: CMakeFiles/spi_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tbox/project/pi-io-test/spi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable spi_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spi_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spi_test.dir/build: spi_test

.PHONY : CMakeFiles/spi_test.dir/build

CMakeFiles/spi_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spi_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spi_test.dir/clean

CMakeFiles/spi_test.dir/depend:
	cd /home/tbox/project/pi-io-test/spi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tbox/project/pi-io-test/spi/src /home/tbox/project/pi-io-test/spi/src /home/tbox/project/pi-io-test/spi/build /home/tbox/project/pi-io-test/spi/build /home/tbox/project/pi-io-test/spi/build/CMakeFiles/spi_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spi_test.dir/depend

