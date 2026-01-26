//
// Created by sudhs on 26/01/2026.
//

#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include "Timer.h"

class CountdownTimer : public Timer {
public:
    CountdownTimer(int h, int m, int s);

    // Sovrascriviamo il metodo update per contare all'indietro
    void update() override;
};

#endif