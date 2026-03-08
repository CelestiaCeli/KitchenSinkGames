//
// Created by Celeste on 2026-03-04.
//

#ifndef KITCHENSINKSTUFF_MENUMATH_H
#define KITCHENSINKSTUFF_MENUMATH_H

#include "BaseProcess.h"


class MenuProcess : BaseProcess {
public:
    int IncrementIndex();
    void Process(std::string collection[], const int listLength);
private:
    int tickRate = 10;
    int currIndex = 0;
    std::string selection;
protected:
};


#endif //KITCHENSINKSTUFF_MENUMATH_H