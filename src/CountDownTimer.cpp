//
// Created by sudhs on 26/01/2026.
//
#include "CountDownTimer.h"

CountDownTimer::CountDownTimer(int h, int m, int s): currentTime(h, m, s), finished(false) {
    if (currentTime.isZero()) {
        finished = true;
    }
}

void CountDownTimer::update() {
    if (finished) return;

    // Prova a scendere di un secondo
    currentTime.tickDown();

    // Controllo immediato: Se DOPO il tick e a zero, è finita.
    if (currentTime.isZero()) {
        finished = true;
    }
}