//
// Created by Celeste on 2026-03-04.
//

#ifndef KITCHENSINKSTUFF_MENU_H
#define KITCHENSINKSTUFF_MENU_H

class Menu
{

    enum CONTEXT_MENU {

    };

public:
    //The primary menu function to execute
    int MenuFunc();
private:
    int currIndex = 0;
};


#endif //KITCHENSINKSTUFF_MENU_H