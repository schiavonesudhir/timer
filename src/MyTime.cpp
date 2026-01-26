//
// Created by sudhs on 26/01/2026.
//
#include "TimerException.h"
#include "MyTime.h"
MyTime::MyTime(int h, int m, int s) {
    setTime(h, m, s);
}

void MyTime::setTime(int h, int m, int s) {
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
        throw TimerException("Errore: Formato orario non valido (0-23h, 0-59m, 0-59s).");
    }
    hours = h;
    minutes = m;
    seconds = s;
}

void MyTime::tick() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            hours = (hours + 1) % 24;
        }
    }
}

void MyTime::reset() {
    hours = minutes = seconds = 0;
}