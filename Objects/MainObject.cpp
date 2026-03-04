//
// Created by Celeste on 2026-03-04.
//

#include "MainObject.h"

void MainObject::Update() {
    while (!quit || !crashed)
    {
        mainProcess->Update();
        mainRender->Update();
    }
}