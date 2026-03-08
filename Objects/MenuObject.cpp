//
// Created by Celeste on 2026-03-08.
//

#include "MenuObject.h"

void MenuObject::Update(std::string *collection[], int listLength) {
    for (int i = 0; i < listLength; i++) {
        int currIndex = menuProcess->IncrementIndex(listLength);
        menuRender->Process(*collection, currIndex);
    }

    menuProcess->Process(collection, listLength);
    menuRender->Process(collection, listLength);
}
