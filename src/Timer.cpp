//
// Created by sudhs on 26/01/2026.
//
#include "Timer.h"

Timer::Timer() : running(false) {}

void Timer::attach(Observer* o) {
    observers.push_back(o);
}

void Timer::detach(Observer* o) {
    observers.remove(o);
}

void Timer::notify() {
    for (Observer* o : observers) {
        o->update();
    }
}

void Timer::update() {
    if (!running) return;

    int oldHours = currentTime.getHours();
    currentTime.tick();

    if (oldHours == 23 && currentTime.getHours() == 0) {
        currentDate.nextDay();
    }

    notify(); // Ogni volta che il tempo cambia, avvisa tutti!
}