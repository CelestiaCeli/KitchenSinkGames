//
// Created by Celeste on 2026-03-04.
//
#include "BaseRender.h"

#ifndef KITCHENSINKSTUFF_MENURENDER_H
#define KITCHENSINKSTUFF_MENURENDER_H
#include <iostream>


class MenuRender : BaseRender
{
public:
    void Process(std::string collection[], const int listLength);
private:

protected:
};


#endif //KITCHENSINKSTUFF_MENURENDER_H