cmake_minimum_required(VERSION 4.1)
project(KitchenSinkStuff)

set(CMAKE_CXX_STANDARD 20)



add_executable(KitchenSinkStuff main.cpp
        Components/Process/MenuProcess.cpp
        Components/Process/MenuProcess.h
        Components/Render/MenuRender.cpp
        Components/Render/MenuRender.h
        Objects/Menu.cpp
        Objects/Menu.h
        Objects/BaseObject.h
        Components/Process/BaseProcess.h
        Components/Render/BaseRender.h
        Components/BaseComponent.h
        Components/Input/BaseInput.h
        Components/Input/MenuInput.cpp
        Components/Input/MenuInput.h
        Components/Observer/BaseObserver.cpp
        Components/Observer/BaseObserver.h
        Components/Process/IntegrityProcess.cpp
        Components/Process/IntegrityProcess.h
        Components/Process/MainProcess.cpp
        Components/Process/MainProcess.h
        Objects/MainObject.cpp
        Objects/MainObject.h
        Components/Render/MainRender.cpp
        Components/Render/MainRender.h
        CrashEnums.h
)

#Architecture - stuff the project NEEDS to work


#This project was made with the idea of mixing and matching parts in mind. Move out one and it functions like normal!
