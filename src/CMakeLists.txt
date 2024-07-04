cmake_minimum_required(VERSION 3.0)

project(atom)

# Find GLFW package
find_package(glfw3 REQUIRED)

# Find OpenGL (GLAD is included with GLFW)
find_package(OpenGL REQUIRED)

# List of source files
set(SOURCES
    main.cpp
    atom_launcher.cpp
    atom.cpp
    input_handler.cpp
    ../dependencies/glad/src/glad.c
    shader/shader.cpp
)

# Create executable
add_executable(atom ${SOURCES})

# Link libraries
target_link_libraries(atom PRIVATE glfw OpenGL::GL)