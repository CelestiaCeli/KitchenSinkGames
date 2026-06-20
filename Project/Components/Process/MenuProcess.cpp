//
// Created by Celeste on 2026-03-04.
//
#include <iostream>

#include "MenuProcess.h"

//TODO: add menu functionality

void MenuProcess::Update(std::string collection[], const int listLength) {
    std::string selection;
    std::getline(std::cin, selection);


    switch (selection)
    {
        default:

            break;
    }
}

int MenuProcess::IncrementIndex() {
    return currIndex++;
}

