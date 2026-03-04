void StartUp();

bool ProcessLoop();
bool Execute();
bool Render();

int Debug();

bool quit = false;

int main()
{

    int errorCode = AttemptStartUp();

    return errorCode;
    StartUp();
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
        success = false;
    }
    if (Render()) {
        success = false;
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
