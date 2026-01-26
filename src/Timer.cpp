//
// Created by sudhs on 26/01/2026.
//
#include "Timer.h"
#include <iostream>
using namespace std;

Timer::Timer() : running(false) {}

void Timer::update() {
    if (!running) return;

    int oldHours = currentTime.getHours();
    currentTime.tick();

    // Se passano 24 ore, incrementa la data
    if (oldHours == 23 && currentTime.getHours() == 0) {
        currentDate.nextDay();
    }
}

void Timer::show() const {
    cout << "Data: " << currentDate.getDay() << "/" << currentDate.getMonth() << "/" << currentDate.getYear();
    cout << " Ora: " << currentTime.getHours() << ":" << currentTime.getMinutes() << ":" << currentTime.getSeconds() << std::endl;
}