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
CMAKE_SOURCE_DIR = /home/topcue/cryptofuzz/third_party/cpu_features

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/topcue/cryptofuzz/third_party/cpu_features/build

# Include any dependencies generated for this target.
include CMakeFiles/cpu_features.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpu_features.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpu_features.dir/flags.make

CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o: CMakeFiles/cpu_features.dir/flags.make
CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o: ../src/cpuinfo_x86.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/topcue/cryptofuzz/third_party/cpu_features/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o"
	/usr/bin/clang-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o   -c /home/topcue/cryptofuzz/third_party/cpu_features/src/cpuinfo_x86.c

CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.i"
	/usr/bin/clang-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/topcue/cryptofuzz/third_party/cpu_features/src/cpuinfo_x86.c > CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.i

CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.s"
	/usr/bin/clang-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/topcue/cryptofuzz/third_party/cpu_features/src/cpuinfo_x86.c -o CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.s

CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.requires:

.PHONY : CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.requires

CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.provides: CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.requires
	$(MAKE) -f CMakeFiles/cpu_features.dir/build.make CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.provides.build
.PHONY : CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.provides

CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.provides.build: CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o


# Object files for target cpu_features
cpu_features_OBJECTS = \
"CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o"

# External object files for target cpu_features
cpu_features_EXTERNAL_OBJECTS = \
"/home/topcue/cryptofuzz/third_party/cpu_features/build/CMakeFiles/utils.dir/src/filesystem.c.o" \
"/home/topcue/cryptofuzz/third_party/cpu_features/build/CMakeFiles/utils.dir/src/stack_line_reader.c.o" \
"/home/topcue/cryptofuzz/third_party/cpu_features/build/CMakeFiles/utils.dir/src/string_view.c.o"

libcpu_features.a: CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o
libcpu_features.a: CMakeFiles/utils.dir/src/filesystem.c.o
libcpu_features.a: CMakeFiles/utils.dir/src/stack_line_reader.c.o
libcpu_features.a: CMakeFiles/utils.dir/src/string_view.c.o
libcpu_features.a: CMakeFiles/cpu_features.dir/build.make
libcpu_features.a: CMakeFiles/cpu_features.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/topcue/cryptofuzz/third_party/cpu_features/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcpu_features.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cpu_features.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpu_features.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpu_features.dir/build: libcpu_features.a

.PHONY : CMakeFiles/cpu_features.dir/build

CMakeFiles/cpu_features.dir/requires: CMakeFiles/cpu_features.dir/src/cpuinfo_x86.c.o.requires

.PHONY : CMakeFiles/cpu_features.dir/requires

CMakeFiles/cpu_features.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpu_features.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpu_features.dir/clean

CMakeFiles/cpu_features.dir/depend:
	cd /home/topcue/cryptofuzz/third_party/cpu_features/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/topcue/cryptofuzz/third_party/cpu_features /home/topcue/cryptofuzz/third_party/cpu_features /home/topcue/cryptofuzz/third_party/cpu_features/build /home/topcue/cryptofuzz/third_party/cpu_features/build /home/topcue/cryptofuzz/third_party/cpu_features/build/CMakeFiles/cpu_features.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpu_features.dir/depend
