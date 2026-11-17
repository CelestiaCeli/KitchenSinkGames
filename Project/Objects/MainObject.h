//
// Created by Celeste on 2026-03-04.
//

#include "BaseObject.h"
#include "../Components/Process/MainProcess.h"
#include "../Components/Render/MainRender.h"

#ifndef KITCHENSINKSTUFF_MAINOBJECT_H
#define KITCHENSINKSTUFF_MAINOBJECT_H


class MainObject : public BaseObject
{
public:
    void Update() override;

    MainObject() {
        mainProcess = new MainProcess();
        mainRender = new MainRender();
    }

    void SetRender(MainRender *_mainRender);
    void SetProcess(MainProcess *_mainProcess);
private:
    bool quit;
    bool crashed;
    unsigned short errorCode;

    MainProcess *mainProcess;
    MainRender *mainRender;
    ~MainObject() {
        delete mainProcess;
        delete mainRender;
    }

};


#endif //KITCHENSINKSTUFF_MAINOBJECT_H