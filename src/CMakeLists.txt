cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project("At0m" VERSION 1.0.0)

find_package(OpenGL REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/../dependencies")
include_directories("${CMAKE_SOURCE_DIR}/../dependencies/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/../dependencies/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/../dependencies/imgui")


file(GLOB_RECURSE SRCS_HEADERS_IMGUI "${CMAKE_SOURCE_DIR}/../dependencies/imgui/*.cpp" "${CMAKE_SOURCE_DIR}/../dependencies/imgui/*.h")
file(GLOB_RECURSE SRCS_HEADERS_GLAD "${CMAKE_SOURCE_DIR}/../dependencies/glad/*.c" "${CMAKE_SOURCE_DIR}/../dependencies/glad/*.h")

file(GLOB_RECURSE SRCS "${CMAKE_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS} ${SRCS_HEADERS_IMGUI} ${SRCS_HEADERS_GLAD})

target_link_libraries(${PROJECT_NAME} OpenGL::GL)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} winmm.lib)
    if (MSVC)
        target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/../dependencies/glfw/lib-vc2022/glfw3.lib")
    elseif (MINGW)
        target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/../dependencies/glfw/lib-mingw-w64/libglfw3.a")
    endif ()
elseif (UNIX)
    find_package(glfw3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw ${CMAKE_DL_LIBS})
else ()
    message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif ()

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/../build")