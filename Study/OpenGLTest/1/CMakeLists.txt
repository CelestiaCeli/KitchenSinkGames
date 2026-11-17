cmake_minimum_required(VERSION 4.1)
Project(OpenGLTest)

include(FetchContent)

FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 567b1ec2442d59525e24c19e8d413df6baf02496
)

FetchContent_Declare(
	glad
	GIT_REPOSITORY https://github.com/Dav1dde/glad.git
	GIT_TAG e3c14f906127dea49ead20ff4d5878294d08b7ab
)

FetchContent_MakeAvailable(glad)
FetchContent_MakeAvailable(glfw)

add_subdirectory(${glad_SOURCE_DIR}/cmake glad_cmake)

glad_add_library(glad_gl_core_33 REPRODUCIBLE API gl:core=3.3)

include_directories(PUBLIC _deps)

add_executable(OpenGLTest main.cpp)


target_link_libraries(OpenGLTest PUBLIC glad_gl_core_33)
target_link_libraries(OpenGLTest PUBLIC glfw)
