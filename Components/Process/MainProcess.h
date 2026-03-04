//
// Created by Celeste on 2026-03-04.
//
#include "BaseProcess.h"

#ifndef KITCHENSINKSTUFF_MAINPROCESS_H
#define KITCHENSINKSTUFF_MAINPROCESS_H

Start

class MainProcess : public BaseProcess {
    int tickRate = 1;
public:
    void Update() override;
};


#endif //KITCHENSINKSTUFF_MAINPROCESS_H