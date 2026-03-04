//
// Created by Celeste on 2026-03-04.
//

#ifndef KITCHENSINKSTUFF_BASELISTENER_H
#define KITCHENSINKSTUFF_BASELISTENER_H

#include "../BaseComponent.h"

class BaseListener : public BaseComponent {
public:
    virtual void AddObserver();
    virtual void RemoveObserver();
};

#endif //KITCHENSINKSTUFF_BASELISTENER_H