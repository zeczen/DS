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
CMAKE_COMMAND = C:\Users\seyal\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\seyal\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\seyal\Documents\C++\DS\Medical System"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\seyal\Documents\C++\DS\Medical System\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DS.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/DS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DS.dir/flags.make

CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.obj: CMakeFiles/DS.dir/flags.make
CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.obj: ../Medical\ System/taskRun3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\seyal\Documents\C++\DS\Medical System\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DS.dir\Medical_System\taskRun3.cpp.obj -c "C:\Users\seyal\Documents\C++\DS\Medical System\Medical System\taskRun3.cpp"

CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\seyal\Documents\C++\DS\Medical System\Medical System\taskRun3.cpp" > CMakeFiles\DS.dir\Medical_System\taskRun3.cpp.i

CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\seyal\Documents\C++\DS\Medical System\Medical System\taskRun3.cpp" -o CMakeFiles\DS.dir\Medical_System\taskRun3.cpp.s

CMakeFiles/DS.dir/Medical_System/Trie.cpp.obj: CMakeFiles/DS.dir/flags.make
CMakeFiles/DS.dir/Medical_System/Trie.cpp.obj: ../Medical\ System/Trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\seyal\Documents\C++\DS\Medical System\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DS.dir/Medical_System/Trie.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DS.dir\Medical_System\Trie.cpp.obj -c "C:\Users\seyal\Documents\C++\DS\Medical System\Medical System\Trie.cpp"

CMakeFiles/DS.dir/Medical_System/Trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DS.dir/Medical_System/Trie.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\seyal\Documents\C++\DS\Medical System\Medical System\Trie.cpp" > CMakeFiles\DS.dir\Medical_System\Trie.cpp.i

CMakeFiles/DS.dir/Medical_System/Trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DS.dir/Medical_System/Trie.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\seyal\Documents\C++\DS\Medical System\Medical System\Trie.cpp" -o CMakeFiles\DS.dir\Medical_System\Trie.cpp.s

# Object files for target DS
DS_OBJECTS = \
"CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.obj" \
"CMakeFiles/DS.dir/Medical_System/Trie.cpp.obj"

# External object files for target DS
DS_EXTERNAL_OBJECTS =

DS.exe: CMakeFiles/DS.dir/Medical_System/taskRun3.cpp.obj
DS.exe: CMakeFiles/DS.dir/Medical_System/Trie.cpp.obj
DS.exe: CMakeFiles/DS.dir/build.make
DS.exe: CMakeFiles/DS.dir/linklibs.rsp
DS.exe: CMakeFiles/DS.dir/objects1.rsp
DS.exe: CMakeFiles/DS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\seyal\Documents\C++\DS\Medical System\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DS.dir/build: DS.exe
.PHONY : CMakeFiles/DS.dir/build

CMakeFiles/DS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DS.dir/clean

CMakeFiles/DS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\seyal\Documents\C++\DS\Medical System" "C:\Users\seyal\Documents\C++\DS\Medical System" "C:\Users\seyal\Documents\C++\DS\Medical System\cmake-build-debug" "C:\Users\seyal\Documents\C++\DS\Medical System\cmake-build-debug" "C:\Users\seyal\Documents\C++\DS\Medical System\cmake-build-debug\CMakeFiles\DS.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DS.dir/depend

