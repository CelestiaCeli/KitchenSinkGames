#include <iostream>
#include <GL/gl.h>
void StartUp();

bool ProcessLoop();
bool Execute();
bool Render();

int Debug();
int DebugPoint();

bool quit = false;

int main()
{
    //TODO: add check startup to scan for an entry point

    if (Debug) {
        //return DebugPoint();
    }

    while (!quit)
    {
        bool crashed = ProcessLoop();

        if (!ProcessLoop())
        {
            return Debug();
        }
    }
}

bool ProcessLoop()
{
    bool success = true;
    if (Execute()) {
        success = true;
    }
    if (Render()) {
        success = true;
    }

    return success;
}

//Main can only happen once in the project, thus there needs to be a way to check project integrity in case a file is removed.

bool Execute()
{

    return true;
}

bool Render()
{
    return true;
}

int Debug()
{
    return 100;
}



int DebugPoint() {
    std::cout << "The";
    return std::addressof(Debug)();
}
