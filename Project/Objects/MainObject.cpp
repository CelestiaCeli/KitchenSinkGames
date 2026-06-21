//
// Created by Celeste on 2026-03-04.
//

#include "MainObject.h"

void MainObject::Update() {
    while (!quit || !crashed)
    {

        mainProcess()->Update();
        mainRender->Update();
    }
}

void MainObject::SetProcess(MainProcess *_mainProcess)
{
    delete mainProcess;
    mainProcess = _mainProcess;
}

void MainObject::SetRender(MainRender *_mainRender)
{
    delete  mainRender;
    mainRender = _mainRender;
}


