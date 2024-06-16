cmake_minimum_required(VERSION 3.0)

project(atom)

# Find GLFW package
find_package(glfw3 REQUIRED)

# Find OpenGL (GLAD is included with GLFW)
find_package(OpenGL REQUIRED)

# Add executable
add_executable(atom glad.c atom.cpp)

# Link libraries
target_link_libraries(atom PRIVATE glfw OpenGL::GL)