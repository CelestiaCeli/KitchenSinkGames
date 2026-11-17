cmake_minimum_required(VERSION 4.1)
project(OpenGLTest)
project(Renderer)
project(Update)
include(FetchContent)
set(FETCHCONTENT_BASE_DIR "../lib/ext")

message("installing  outsourced libraries...")

#Fetching git respositories that host the required deps

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

#Building glad since it is a manual tool

add_subdirectory(${glad_SOURCE_DIR}/cmake glad_cmake)
glad_add_library(glad_gl_core_33 REPRODUCIBLE API gl:core=3.3)

message("Building program")

# Creating libraries

#add_library(Renderer "src/Render.cpp" "lib/Render.h")
#add_library(Update "src/Update.cpp" "lib/Update.h")

# Creating main application

add_executable(OpenGLTest "src/main.cpp")

#Linking all libraries to main application

target_link_libraries(OpenGLTest glad_gl_core_33 glfw)
