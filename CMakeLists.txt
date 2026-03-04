cmake_minimum_required(VERSION 4.1)

project(KitchenSinkStuff LANGUAGES CXX)
project(Architectural LANGUAGES CXX)
project(Menu LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

#This project was made with the idea of mixing and matching parts in mind. Move out one and it functions like normal!

#Architectural
add_library(Architectural main.cpp
CrashEnums.h
Components/Input/BaseInput.h
Components/Process/BaseProcess.h
Components/Render/BaseRender.h
Components/Observer/BaseObserver.h
Objects/BaseObject.h
        Components/Listener/BaseListener.cpp
        Components/Listener/BaseListener.h)

#External Architecture

#Menu
add_library(Menu
        Components/Render/MenuRender.h
Components/Process/MenuProcess.h
Components/Input/MenuInput.h)

link_libraries(KitchenSinkStuff
Architectural
Menu)
add_executable(KitchenSinkStuff
Architectural
Menu)
