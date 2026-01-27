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
    if (!finished) {
        // Prova a scalare un secondo
        bool stillRunning = currentTime.tickDown();

        if (!stillRunning) {
            finished = true;
        }
    }
}