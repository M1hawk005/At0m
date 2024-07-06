cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 20)
project(atom)

# Find GLFW package
find_package(glfw3 REQUIRED)

# Find OpenGL (GLAD is included with GLFW)
find_package(OpenGL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/imgui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/imgui/backends)
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
) 
# List of source files
set(SOURCES
    main.cpp
    atom_launcher.cpp
    atom.cpp
    input_handler.cpp
    ../dependencies/glad/src/glad.c
    shader/shader.cpp
    util/global.cpp
)

# Create executable
add_executable(atom ${SOURCES} ${IMGUI_SOURCES})

# Link libraries
target_link_libraries(atom PRIVATE glfw OpenGL::GL)