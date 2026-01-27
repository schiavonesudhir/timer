//
// Created by sudhs on 26/01/2026.
//
#include "MyTime.h"
#include <cstdio>
MyTime::MyTime(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

bool MyTime::isZero() const {
    return hours == 0 && minutes == 0 && seconds == 0;
}

bool MyTime::tickDown() {
    if (isZero()) return false; // Non può scendere sotto zero

    if (seconds > 0) {
        seconds--;
    } else {
        if (minutes > 0) {
            minutes--;
            seconds = 59;
        } else {
            if (hours > 0) {
                hours--;
                minutes = 59;
                seconds = 59;
            }
        }
    }
    return true;
}

string MyTime::toString() const {
    char buffer[10];
    // %02d significa: stampa un intero con almeno 2 cifre, riempiendo con 0
    sprintf(buffer, "%02d:%02d:%02d", hours, minutes, seconds);
    return string(buffer);
}