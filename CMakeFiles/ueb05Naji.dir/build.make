# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/najimajaadari/Desktop/ueb05Naji

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/najimajaadari/Desktop/ueb05Naji

# Include any dependencies generated for this target.
include CMakeFiles/ueb05Naji.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ueb05Naji.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ueb05Naji.dir/flags.make

CMakeFiles/ueb05Naji.dir/src/database.c.o: CMakeFiles/ueb05Naji.dir/flags.make
CMakeFiles/ueb05Naji.dir/src/database.c.o: src/database.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ueb05Naji.dir/src/database.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ueb05Naji.dir/src/database.c.o   -c /Users/najimajaadari/Desktop/ueb05Naji/src/database.c

CMakeFiles/ueb05Naji.dir/src/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ueb05Naji.dir/src/database.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/najimajaadari/Desktop/ueb05Naji/src/database.c > CMakeFiles/ueb05Naji.dir/src/database.c.i

CMakeFiles/ueb05Naji.dir/src/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ueb05Naji.dir/src/database.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/najimajaadari/Desktop/ueb05Naji/src/database.c -o CMakeFiles/ueb05Naji.dir/src/database.c.s

CMakeFiles/ueb05Naji.dir/src/database.c.o.requires:

.PHONY : CMakeFiles/ueb05Naji.dir/src/database.c.o.requires

CMakeFiles/ueb05Naji.dir/src/database.c.o.provides: CMakeFiles/ueb05Naji.dir/src/database.c.o.requires
	$(MAKE) -f CMakeFiles/ueb05Naji.dir/build.make CMakeFiles/ueb05Naji.dir/src/database.c.o.provides.build
.PHONY : CMakeFiles/ueb05Naji.dir/src/database.c.o.provides

CMakeFiles/ueb05Naji.dir/src/database.c.o.provides.build: CMakeFiles/ueb05Naji.dir/src/database.c.o


CMakeFiles/ueb05Naji.dir/src/datetime.c.o: CMakeFiles/ueb05Naji.dir/flags.make
CMakeFiles/ueb05Naji.dir/src/datetime.c.o: src/datetime.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ueb05Naji.dir/src/datetime.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ueb05Naji.dir/src/datetime.c.o   -c /Users/najimajaadari/Desktop/ueb05Naji/src/datetime.c

CMakeFiles/ueb05Naji.dir/src/datetime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ueb05Naji.dir/src/datetime.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/najimajaadari/Desktop/ueb05Naji/src/datetime.c > CMakeFiles/ueb05Naji.dir/src/datetime.c.i

CMakeFiles/ueb05Naji.dir/src/datetime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ueb05Naji.dir/src/datetime.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/najimajaadari/Desktop/ueb05Naji/src/datetime.c -o CMakeFiles/ueb05Naji.dir/src/datetime.c.s

CMakeFiles/ueb05Naji.dir/src/datetime.c.o.requires:

.PHONY : CMakeFiles/ueb05Naji.dir/src/datetime.c.o.requires

CMakeFiles/ueb05Naji.dir/src/datetime.c.o.provides: CMakeFiles/ueb05Naji.dir/src/datetime.c.o.requires
	$(MAKE) -f CMakeFiles/ueb05Naji.dir/build.make CMakeFiles/ueb05Naji.dir/src/datetime.c.o.provides.build
.PHONY : CMakeFiles/ueb05Naji.dir/src/datetime.c.o.provides

CMakeFiles/ueb05Naji.dir/src/datetime.c.o.provides.build: CMakeFiles/ueb05Naji.dir/src/datetime.c.o


CMakeFiles/ueb05Naji.dir/src/main.c.o: CMakeFiles/ueb05Naji.dir/flags.make
CMakeFiles/ueb05Naji.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ueb05Naji.dir/src/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ueb05Naji.dir/src/main.c.o   -c /Users/najimajaadari/Desktop/ueb05Naji/src/main.c

CMakeFiles/ueb05Naji.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ueb05Naji.dir/src/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/najimajaadari/Desktop/ueb05Naji/src/main.c > CMakeFiles/ueb05Naji.dir/src/main.c.i

CMakeFiles/ueb05Naji.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ueb05Naji.dir/src/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/najimajaadari/Desktop/ueb05Naji/src/main.c -o CMakeFiles/ueb05Naji.dir/src/main.c.s

CMakeFiles/ueb05Naji.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/ueb05Naji.dir/src/main.c.o.requires

CMakeFiles/ueb05Naji.dir/src/main.c.o.provides: CMakeFiles/ueb05Naji.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/ueb05Naji.dir/build.make CMakeFiles/ueb05Naji.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/ueb05Naji.dir/src/main.c.o.provides

CMakeFiles/ueb05Naji.dir/src/main.c.o.provides.build: CMakeFiles/ueb05Naji.dir/src/main.c.o


CMakeFiles/ueb05Naji.dir/src/menu.c.o: CMakeFiles/ueb05Naji.dir/flags.make
CMakeFiles/ueb05Naji.dir/src/menu.c.o: src/menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ueb05Naji.dir/src/menu.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ueb05Naji.dir/src/menu.c.o   -c /Users/najimajaadari/Desktop/ueb05Naji/src/menu.c

CMakeFiles/ueb05Naji.dir/src/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ueb05Naji.dir/src/menu.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/najimajaadari/Desktop/ueb05Naji/src/menu.c > CMakeFiles/ueb05Naji.dir/src/menu.c.i

CMakeFiles/ueb05Naji.dir/src/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ueb05Naji.dir/src/menu.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/najimajaadari/Desktop/ueb05Naji/src/menu.c -o CMakeFiles/ueb05Naji.dir/src/menu.c.s

CMakeFiles/ueb05Naji.dir/src/menu.c.o.requires:

.PHONY : CMakeFiles/ueb05Naji.dir/src/menu.c.o.requires

CMakeFiles/ueb05Naji.dir/src/menu.c.o.provides: CMakeFiles/ueb05Naji.dir/src/menu.c.o.requires
	$(MAKE) -f CMakeFiles/ueb05Naji.dir/build.make CMakeFiles/ueb05Naji.dir/src/menu.c.o.provides.build
.PHONY : CMakeFiles/ueb05Naji.dir/src/menu.c.o.provides

CMakeFiles/ueb05Naji.dir/src/menu.c.o.provides.build: CMakeFiles/ueb05Naji.dir/src/menu.c.o


CMakeFiles/ueb05Naji.dir/src/sort.c.o: CMakeFiles/ueb05Naji.dir/flags.make
CMakeFiles/ueb05Naji.dir/src/sort.c.o: src/sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ueb05Naji.dir/src/sort.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ueb05Naji.dir/src/sort.c.o   -c /Users/najimajaadari/Desktop/ueb05Naji/src/sort.c

CMakeFiles/ueb05Naji.dir/src/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ueb05Naji.dir/src/sort.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/najimajaadari/Desktop/ueb05Naji/src/sort.c > CMakeFiles/ueb05Naji.dir/src/sort.c.i

CMakeFiles/ueb05Naji.dir/src/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ueb05Naji.dir/src/sort.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/najimajaadari/Desktop/ueb05Naji/src/sort.c -o CMakeFiles/ueb05Naji.dir/src/sort.c.s

CMakeFiles/ueb05Naji.dir/src/sort.c.o.requires:

.PHONY : CMakeFiles/ueb05Naji.dir/src/sort.c.o.requires

CMakeFiles/ueb05Naji.dir/src/sort.c.o.provides: CMakeFiles/ueb05Naji.dir/src/sort.c.o.requires
	$(MAKE) -f CMakeFiles/ueb05Naji.dir/build.make CMakeFiles/ueb05Naji.dir/src/sort.c.o.provides.build
.PHONY : CMakeFiles/ueb05Naji.dir/src/sort.c.o.provides

CMakeFiles/ueb05Naji.dir/src/sort.c.o.provides.build: CMakeFiles/ueb05Naji.dir/src/sort.c.o


CMakeFiles/ueb05Naji.dir/src/teams.c.o: CMakeFiles/ueb05Naji.dir/flags.make
CMakeFiles/ueb05Naji.dir/src/teams.c.o: src/teams.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ueb05Naji.dir/src/teams.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ueb05Naji.dir/src/teams.c.o   -c /Users/najimajaadari/Desktop/ueb05Naji/src/teams.c

CMakeFiles/ueb05Naji.dir/src/teams.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ueb05Naji.dir/src/teams.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/najimajaadari/Desktop/ueb05Naji/src/teams.c > CMakeFiles/ueb05Naji.dir/src/teams.c.i

CMakeFiles/ueb05Naji.dir/src/teams.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ueb05Naji.dir/src/teams.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/najimajaadari/Desktop/ueb05Naji/src/teams.c -o CMakeFiles/ueb05Naji.dir/src/teams.c.s

CMakeFiles/ueb05Naji.dir/src/teams.c.o.requires:

.PHONY : CMakeFiles/ueb05Naji.dir/src/teams.c.o.requires

CMakeFiles/ueb05Naji.dir/src/teams.c.o.provides: CMakeFiles/ueb05Naji.dir/src/teams.c.o.requires
	$(MAKE) -f CMakeFiles/ueb05Naji.dir/build.make CMakeFiles/ueb05Naji.dir/src/teams.c.o.provides.build
.PHONY : CMakeFiles/ueb05Naji.dir/src/teams.c.o.provides

CMakeFiles/ueb05Naji.dir/src/teams.c.o.provides.build: CMakeFiles/ueb05Naji.dir/src/teams.c.o


CMakeFiles/ueb05Naji.dir/src/tools.c.o: CMakeFiles/ueb05Naji.dir/flags.make
CMakeFiles/ueb05Naji.dir/src/tools.c.o: src/tools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ueb05Naji.dir/src/tools.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ueb05Naji.dir/src/tools.c.o   -c /Users/najimajaadari/Desktop/ueb05Naji/src/tools.c

CMakeFiles/ueb05Naji.dir/src/tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ueb05Naji.dir/src/tools.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/najimajaadari/Desktop/ueb05Naji/src/tools.c > CMakeFiles/ueb05Naji.dir/src/tools.c.i

CMakeFiles/ueb05Naji.dir/src/tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ueb05Naji.dir/src/tools.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/najimajaadari/Desktop/ueb05Naji/src/tools.c -o CMakeFiles/ueb05Naji.dir/src/tools.c.s

CMakeFiles/ueb05Naji.dir/src/tools.c.o.requires:

.PHONY : CMakeFiles/ueb05Naji.dir/src/tools.c.o.requires

CMakeFiles/ueb05Naji.dir/src/tools.c.o.provides: CMakeFiles/ueb05Naji.dir/src/tools.c.o.requires
	$(MAKE) -f CMakeFiles/ueb05Naji.dir/build.make CMakeFiles/ueb05Naji.dir/src/tools.c.o.provides.build
.PHONY : CMakeFiles/ueb05Naji.dir/src/tools.c.o.provides

CMakeFiles/ueb05Naji.dir/src/tools.c.o.provides.build: CMakeFiles/ueb05Naji.dir/src/tools.c.o


# Object files for target ueb05Naji
ueb05Naji_OBJECTS = \
"CMakeFiles/ueb05Naji.dir/src/database.c.o" \
"CMakeFiles/ueb05Naji.dir/src/datetime.c.o" \
"CMakeFiles/ueb05Naji.dir/src/main.c.o" \
"CMakeFiles/ueb05Naji.dir/src/menu.c.o" \
"CMakeFiles/ueb05Naji.dir/src/sort.c.o" \
"CMakeFiles/ueb05Naji.dir/src/teams.c.o" \
"CMakeFiles/ueb05Naji.dir/src/tools.c.o"

# External object files for target ueb05Naji
ueb05Naji_EXTERNAL_OBJECTS =

ueb05Naji: CMakeFiles/ueb05Naji.dir/src/database.c.o
ueb05Naji: CMakeFiles/ueb05Naji.dir/src/datetime.c.o
ueb05Naji: CMakeFiles/ueb05Naji.dir/src/main.c.o
ueb05Naji: CMakeFiles/ueb05Naji.dir/src/menu.c.o
ueb05Naji: CMakeFiles/ueb05Naji.dir/src/sort.c.o
ueb05Naji: CMakeFiles/ueb05Naji.dir/src/teams.c.o
ueb05Naji: CMakeFiles/ueb05Naji.dir/src/tools.c.o
ueb05Naji: CMakeFiles/ueb05Naji.dir/build.make
ueb05Naji: CMakeFiles/ueb05Naji.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable ueb05Naji"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ueb05Naji.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ueb05Naji.dir/build: ueb05Naji

.PHONY : CMakeFiles/ueb05Naji.dir/build

CMakeFiles/ueb05Naji.dir/requires: CMakeFiles/ueb05Naji.dir/src/database.c.o.requires
CMakeFiles/ueb05Naji.dir/requires: CMakeFiles/ueb05Naji.dir/src/datetime.c.o.requires
CMakeFiles/ueb05Naji.dir/requires: CMakeFiles/ueb05Naji.dir/src/main.c.o.requires
CMakeFiles/ueb05Naji.dir/requires: CMakeFiles/ueb05Naji.dir/src/menu.c.o.requires
CMakeFiles/ueb05Naji.dir/requires: CMakeFiles/ueb05Naji.dir/src/sort.c.o.requires
CMakeFiles/ueb05Naji.dir/requires: CMakeFiles/ueb05Naji.dir/src/teams.c.o.requires
CMakeFiles/ueb05Naji.dir/requires: CMakeFiles/ueb05Naji.dir/src/tools.c.o.requires

.PHONY : CMakeFiles/ueb05Naji.dir/requires

CMakeFiles/ueb05Naji.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ueb05Naji.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ueb05Naji.dir/clean

CMakeFiles/ueb05Naji.dir/depend:
	cd /Users/najimajaadari/Desktop/ueb05Naji && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/najimajaadari/Desktop/ueb05Naji /Users/najimajaadari/Desktop/ueb05Naji /Users/najimajaadari/Desktop/ueb05Naji /Users/najimajaadari/Desktop/ueb05Naji /Users/najimajaadari/Desktop/ueb05Naji/CMakeFiles/ueb05Naji.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ueb05Naji.dir/depend
