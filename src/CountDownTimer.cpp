//
// Created by sudhs on 26/01/2026.
//
#include "CountDownTimer.h"

CountdownTimer::CountdownTimer(int h, int m, int s) {
    currentTime.setTime(h, m, s);
    running = false;
}

void CountdownTimer::update() {
    if (!running) return;

    int h = currentTime.getHours();
    int m = currentTime.getMinutes();
    int s = currentTime.getSeconds();

    if (h == 0 && m == 0 && s == 0) {
        running = false; // Il countdown è finito
    } else {
        s--;
        if (s < 0) {
            s = 59;
            m--;
            if (m < 0) {
                m = 59;
                h--;
            }
        }
        currentTime.setTime(h, m, s);
    }

    notify(); // Avvisa gli osservatori del nuovo tempo
}