# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/ugb/christopher.mossman/cpsc589/589Boilerplate-Linux/A1-Mossman-10153801

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ugb/christopher.mossman/cpsc589/589Boilerplate-Linux/A1-Mossman-10153801

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ugb/christopher.mossman/cpsc589/589Boilerplate-Linux/A1-Mossman-10153801/CMakeFiles /home/ugb/christopher.mossman/cpsc589/589Boilerplate-Linux/A1-Mossman-10153801/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ugb/christopher.mossman/cpsc589/589Boilerplate-Linux/A1-Mossman-10153801/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named a1

# Build rule for target.
a1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 a1
.PHONY : a1

# fast build rule for target.
a1/fast:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/build
.PHONY : a1/fast

include/imgui/imgui.o: include/imgui/imgui.cpp.o

.PHONY : include/imgui/imgui.o

# target to build an object file
include/imgui/imgui.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui.cpp.o
.PHONY : include/imgui/imgui.cpp.o

include/imgui/imgui.i: include/imgui/imgui.cpp.i

.PHONY : include/imgui/imgui.i

# target to preprocess a source file
include/imgui/imgui.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui.cpp.i
.PHONY : include/imgui/imgui.cpp.i

include/imgui/imgui.s: include/imgui/imgui.cpp.s

.PHONY : include/imgui/imgui.s

# target to generate assembly for a file
include/imgui/imgui.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui.cpp.s
.PHONY : include/imgui/imgui.cpp.s

include/imgui/imgui_demo.o: include/imgui/imgui_demo.cpp.o

.PHONY : include/imgui/imgui_demo.o

# target to build an object file
include/imgui/imgui_demo.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_demo.cpp.o
.PHONY : include/imgui/imgui_demo.cpp.o

include/imgui/imgui_demo.i: include/imgui/imgui_demo.cpp.i

.PHONY : include/imgui/imgui_demo.i

# target to preprocess a source file
include/imgui/imgui_demo.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_demo.cpp.i
.PHONY : include/imgui/imgui_demo.cpp.i

include/imgui/imgui_demo.s: include/imgui/imgui_demo.cpp.s

.PHONY : include/imgui/imgui_demo.s

# target to generate assembly for a file
include/imgui/imgui_demo.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_demo.cpp.s
.PHONY : include/imgui/imgui_demo.cpp.s

include/imgui/imgui_draw.o: include/imgui/imgui_draw.cpp.o

.PHONY : include/imgui/imgui_draw.o

# target to build an object file
include/imgui/imgui_draw.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_draw.cpp.o
.PHONY : include/imgui/imgui_draw.cpp.o

include/imgui/imgui_draw.i: include/imgui/imgui_draw.cpp.i

.PHONY : include/imgui/imgui_draw.i

# target to preprocess a source file
include/imgui/imgui_draw.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_draw.cpp.i
.PHONY : include/imgui/imgui_draw.cpp.i

include/imgui/imgui_draw.s: include/imgui/imgui_draw.cpp.s

.PHONY : include/imgui/imgui_draw.s

# target to generate assembly for a file
include/imgui/imgui_draw.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_draw.cpp.s
.PHONY : include/imgui/imgui_draw.cpp.s

include/imgui/imgui_impl_glfw.o: include/imgui/imgui_impl_glfw.cpp.o

.PHONY : include/imgui/imgui_impl_glfw.o

# target to build an object file
include/imgui/imgui_impl_glfw.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_impl_glfw.cpp.o
.PHONY : include/imgui/imgui_impl_glfw.cpp.o

include/imgui/imgui_impl_glfw.i: include/imgui/imgui_impl_glfw.cpp.i

.PHONY : include/imgui/imgui_impl_glfw.i

# target to preprocess a source file
include/imgui/imgui_impl_glfw.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_impl_glfw.cpp.i
.PHONY : include/imgui/imgui_impl_glfw.cpp.i

include/imgui/imgui_impl_glfw.s: include/imgui/imgui_impl_glfw.cpp.s

.PHONY : include/imgui/imgui_impl_glfw.s

# target to generate assembly for a file
include/imgui/imgui_impl_glfw.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_impl_glfw.cpp.s
.PHONY : include/imgui/imgui_impl_glfw.cpp.s

include/imgui/imgui_impl_opengl3.o: include/imgui/imgui_impl_opengl3.cpp.o

.PHONY : include/imgui/imgui_impl_opengl3.o

# target to build an object file
include/imgui/imgui_impl_opengl3.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_impl_opengl3.cpp.o
.PHONY : include/imgui/imgui_impl_opengl3.cpp.o

include/imgui/imgui_impl_opengl3.i: include/imgui/imgui_impl_opengl3.cpp.i

.PHONY : include/imgui/imgui_impl_opengl3.i

# target to preprocess a source file
include/imgui/imgui_impl_opengl3.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_impl_opengl3.cpp.i
.PHONY : include/imgui/imgui_impl_opengl3.cpp.i

include/imgui/imgui_impl_opengl3.s: include/imgui/imgui_impl_opengl3.cpp.s

.PHONY : include/imgui/imgui_impl_opengl3.s

# target to generate assembly for a file
include/imgui/imgui_impl_opengl3.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_impl_opengl3.cpp.s
.PHONY : include/imgui/imgui_impl_opengl3.cpp.s

include/imgui/imgui_widgets.o: include/imgui/imgui_widgets.cpp.o

.PHONY : include/imgui/imgui_widgets.o

# target to build an object file
include/imgui/imgui_widgets.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_widgets.cpp.o
.PHONY : include/imgui/imgui_widgets.cpp.o

include/imgui/imgui_widgets.i: include/imgui/imgui_widgets.cpp.i

.PHONY : include/imgui/imgui_widgets.i

# target to preprocess a source file
include/imgui/imgui_widgets.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_widgets.cpp.i
.PHONY : include/imgui/imgui_widgets.cpp.i

include/imgui/imgui_widgets.s: include/imgui/imgui_widgets.cpp.s

.PHONY : include/imgui/imgui_widgets.s

# target to generate assembly for a file
include/imgui/imgui_widgets.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/include/imgui/imgui_widgets.cpp.s
.PHONY : include/imgui/imgui_widgets.cpp.s

src/Geometry.o: src/Geometry.cpp.o

.PHONY : src/Geometry.o

# target to build an object file
src/Geometry.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/Geometry.cpp.o
.PHONY : src/Geometry.cpp.o

src/Geometry.i: src/Geometry.cpp.i

.PHONY : src/Geometry.i

# target to preprocess a source file
src/Geometry.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/Geometry.cpp.i
.PHONY : src/Geometry.cpp.i

src/Geometry.s: src/Geometry.cpp.s

.PHONY : src/Geometry.s

# target to generate assembly for a file
src/Geometry.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/Geometry.cpp.s
.PHONY : src/Geometry.cpp.s

src/InputHandler.o: src/InputHandler.cpp.o

.PHONY : src/InputHandler.o

# target to build an object file
src/InputHandler.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/InputHandler.cpp.o
.PHONY : src/InputHandler.cpp.o

src/InputHandler.i: src/InputHandler.cpp.i

.PHONY : src/InputHandler.i

# target to preprocess a source file
src/InputHandler.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/InputHandler.cpp.i
.PHONY : src/InputHandler.cpp.i

src/InputHandler.s: src/InputHandler.cpp.s

.PHONY : src/InputHandler.s

# target to generate assembly for a file
src/InputHandler.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/InputHandler.cpp.s
.PHONY : src/InputHandler.cpp.s

src/Program.o: src/Program.cpp.o

.PHONY : src/Program.o

# target to build an object file
src/Program.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/Program.cpp.o
.PHONY : src/Program.cpp.o

src/Program.i: src/Program.cpp.i

.PHONY : src/Program.i

# target to preprocess a source file
src/Program.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/Program.cpp.i
.PHONY : src/Program.cpp.i

src/Program.s: src/Program.cpp.s

.PHONY : src/Program.s

# target to generate assembly for a file
src/Program.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/Program.cpp.s
.PHONY : src/Program.cpp.s

src/RenderEngine.o: src/RenderEngine.cpp.o

.PHONY : src/RenderEngine.o

# target to build an object file
src/RenderEngine.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/RenderEngine.cpp.o
.PHONY : src/RenderEngine.cpp.o

src/RenderEngine.i: src/RenderEngine.cpp.i

.PHONY : src/RenderEngine.i

# target to preprocess a source file
src/RenderEngine.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/RenderEngine.cpp.i
.PHONY : src/RenderEngine.cpp.i

src/RenderEngine.s: src/RenderEngine.cpp.s

.PHONY : src/RenderEngine.s

# target to generate assembly for a file
src/RenderEngine.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/RenderEngine.cpp.s
.PHONY : src/RenderEngine.cpp.s

src/ShaderTools.o: src/ShaderTools.cpp.o

.PHONY : src/ShaderTools.o

# target to build an object file
src/ShaderTools.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/ShaderTools.cpp.o
.PHONY : src/ShaderTools.cpp.o

src/ShaderTools.i: src/ShaderTools.cpp.i

.PHONY : src/ShaderTools.i

# target to preprocess a source file
src/ShaderTools.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/ShaderTools.cpp.i
.PHONY : src/ShaderTools.cpp.i

src/ShaderTools.s: src/ShaderTools.cpp.s

.PHONY : src/ShaderTools.s

# target to generate assembly for a file
src/ShaderTools.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/ShaderTools.cpp.s
.PHONY : src/ShaderTools.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/a1.dir/build.make CMakeFiles/a1.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... a1"
	@echo "... edit_cache"
	@echo "... include/imgui/imgui.o"
	@echo "... include/imgui/imgui.i"
	@echo "... include/imgui/imgui.s"
	@echo "... include/imgui/imgui_demo.o"
	@echo "... include/imgui/imgui_demo.i"
	@echo "... include/imgui/imgui_demo.s"
	@echo "... include/imgui/imgui_draw.o"
	@echo "... include/imgui/imgui_draw.i"
	@echo "... include/imgui/imgui_draw.s"
	@echo "... include/imgui/imgui_impl_glfw.o"
	@echo "... include/imgui/imgui_impl_glfw.i"
	@echo "... include/imgui/imgui_impl_glfw.s"
	@echo "... include/imgui/imgui_impl_opengl3.o"
	@echo "... include/imgui/imgui_impl_opengl3.i"
	@echo "... include/imgui/imgui_impl_opengl3.s"
	@echo "... include/imgui/imgui_widgets.o"
	@echo "... include/imgui/imgui_widgets.i"
	@echo "... include/imgui/imgui_widgets.s"
	@echo "... src/Geometry.o"
	@echo "... src/Geometry.i"
	@echo "... src/Geometry.s"
	@echo "... src/InputHandler.o"
	@echo "... src/InputHandler.i"
	@echo "... src/InputHandler.s"
	@echo "... src/Program.o"
	@echo "... src/Program.i"
	@echo "... src/Program.s"
	@echo "... src/RenderEngine.o"
	@echo "... src/RenderEngine.i"
	@echo "... src/RenderEngine.s"
	@echo "... src/ShaderTools.o"
	@echo "... src/ShaderTools.i"
	@echo "... src/ShaderTools.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
