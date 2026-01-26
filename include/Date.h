//
// Created by sudhs on 26/01/2026.
//

#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day, month, year;
    bool isLeap(int y) const; // Controllo anno bisestile

public:
    Date(int d = 1, int m = 1, int y = 2024);
    void nextDay();
    void display() const;

    // Getter
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

#endif