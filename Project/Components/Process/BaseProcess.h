//
// Created by Celeste on 2026-03-04.
//
#include "../BaseComponent.h"

#ifndef KITCHENSINKSTUFF_BASEPROCESS_H
#define KITCHENSINKSTUFF_BASEPROCESS_H



class BaseProcess : public BaseComponent
{
public:
    int tickRate;
    virtual void Update() override;
};


#endif //KITCHENSINKSTUFF_BASEPROCESS_H