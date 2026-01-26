//
// Created by sudhs on 26/01/2026.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include "Observer.h"
#include "Timer.h"

class Display : public Observer {
private:
    Timer* subject; // Il timer da osservare
public:
    Display(Timer* t);
    void update() override; // Cosa fare quando riceve la notifica
};

#endif