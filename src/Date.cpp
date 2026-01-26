//
// Created by sudhs on 26/01/2026.
//

#include "Date.h"
#include <iostream>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::isLeap(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void Date::nextDay() {
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeap(year)) daysInMonth[2] = 29;

    day++;
    if (day > daysInMonth[month]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}