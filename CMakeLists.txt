# The following CMakeLists.txt file is a modified version of the one produced by Andrew Owens for CPSC 587 students.
# I used it as a baseline, and modified it for the purposes of this CPSC 589 assignment. 
cmake_minimum_required(VERSION 3.0)
project(a1 VERSION 1.0 LANGUAGES C CXX)

#[ OpenGL ]
find_package(OpenGL REQUIRED)

#[ GLFW ]
find_package(glfw3 3.3 REQUIRED)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

#[ Headers ]
set(HEADERS
    src/Geometry.h
    src/InputHandler.h
    src/Program.h
    src/RenderEngine.h
    src/ShaderTools.h
    include/imgui/imconfig.h
    include/imgui/imgui.h
    include/imgui/imgui_impl_glfw.h
    include/imgui/imgui_impl_opengl3.h
    include/imgui/imgui_internal.h
    include/imgui/imstb_rectpack.h
    include/imgui/imstb_textedit.h
    include/imgui/imstb_truetype.h
    )

#[ Sources ]
set(SOURCES
    src/main.cpp
    src/Geometry.cpp
    src/InputHandler.cpp
    src/Program.cpp
    src/RenderEngine.cpp
    src/ShaderTools.cpp
    include/imgui/imgui.cpp
    include/imgui/imgui_demo.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_impl_glfw.cpp
    include/imgui/imgui_impl_opengl3.cpp
    include/imgui/imgui_widgets.cpp
    )

#[ Resource ]
set(RESOURCE_FILES
    shaders/main.frag
    shaders/main.vert
    )

configure_file(shaders/main.frag shaders-cmakecopy/main.frag COPYONLY)
configure_file(shaders/main.vert shaders-cmakecopy/main.vert COPYONLY)

#[ Executable ]
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

#[ Definitions ]
target_compile_definitions(${PROJECT_NAME}
    PRIVATE -DGLFW_INCLUDE_NONE
    )

if(MSVC)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE -D_USE_MATH_DEFINES
        )
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    MACOSX_BUNDLE TRUE
    MACOSX_FRAMEWORK_IDENTIFIER org.cmake.${PROJECT_NAME}
    )

target_link_libraries(${PROJECT_NAME}
    PRIVATE ${OPENGL_gl_LIBRARY}
    PRIVATE glfw
    PRIVATE ${CMAKE_DL_LIBS}
    )

target_include_directories(${PROJECT_NAME}
    PRIVATE include
    PRIVATE src
    PRIVATE include/imgui
    )
