//
// Created by Celeste on 2026-03-04.
//
#include "../Components/Process/MenuProcess.h"
#include "../Components/Render/MenuRender.h"


#ifndef KITCHENSINKSTUFF_MENU_H
#define KITCHENSINKSTUFF_MENU_H

class Menu : "BaseObject.h"
{
private:
    MenuProcess *menuExecution;
    MenuRender *menuRender;
public:

    Menu() {
        menuExecution = new MenuProcess();
        menuRender = new MenuRender();
    }

    ~Menu() {
        //Delete all pointers
        delete menuExecution;
        delete menuRender;
    }
};


#endif //KITCHENSINKSTUFF_MENU_H