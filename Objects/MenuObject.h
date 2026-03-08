//
// Created by Celeste on 2026-03-08.
//

#ifndef KITCHENSINKSTUFF_MENUOBJECT_H
#define KITCHENSINKSTUFF_MENUOBJECT_H
#include "../Components/Process/MenuProcess.h"
#include "../Components/Render/MenuRender.h"
#include "BaseObject.h"
class MenuObject : BaseObject {
public:
    MenuObject() {
        menuRender = new MenuRender();
        menuProcess = new MenuProcess();
    }

    void Update() override;
private:
    MenuRender *menuRender;
    MenuProcess *menuProcess;
protected:
};


#endif //KITCHENSINKSTUFF_MENUOBJECT_H