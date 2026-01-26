//
// Created by sudhs on 26/01/2026.
//

#include "MyTime.h"
MyTime::MyTime(int h, int m, int s) {
    setTime(h, m, s);
}

void MyTime::setTime(int h, int m, int s) {
    hours = (h >= 0 && h < 24) ? h : 0;
    minutes = (m >= 0 && m < 60) ? m : 0;
    seconds = (s >= 0 && s < 60) ? s : 0;
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