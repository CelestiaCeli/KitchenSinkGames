//
// Created by Celeste on 2026-03-04.
//

#include "MenuRender.h"

void MenuRender::Process(std::string collection[], const int listLength, int *currIndex) {
    for (int i = 0; i < listLength; i++) {
        std::printf("%d\t%c\n", *currIndex, collection[i].c_str());
    }
}
