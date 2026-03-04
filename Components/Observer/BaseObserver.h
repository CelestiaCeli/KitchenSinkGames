//
// Created by Celeste on 2026-03-04.
//
#include "../BaseComponent.h"


#ifndef KITCHENSINKSTUFF_BASEOBSERVER_H
#define KITCHENSINKSTUFF_BASEOBSERVER_H


class BaseObserver : public BaseComponent {

public:
    void AddObserver();
    void RemoveObserver();
    void Update() override;
private:
};


#endif //KITCHENSINKSTUFF_BASEOBSERVER_H