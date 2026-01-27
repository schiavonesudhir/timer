//
// Created by sudhs on 26/01/2026.
//

#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include "MyTime.h"

class CountDownTimer {
private:
    MyTime currentTime;
    bool finished;

public:
    CountDownTimer(int h, int m, int s);

    // Esegue un passo del timer
    void update();

    // Controlla se è finito
    bool isFinished() const { return finished; }

    // Restituisce l'oggetto Time per vederlo
    MyTime getTime() const { return currentTime; }
};

#endif