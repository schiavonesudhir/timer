//
// Created by sudhs on 19/01/2026.
//

#ifndef MYTIME_H
#define MYTIME_H
#include <string>
using namespace std;
class MyTime {
private:
    int hours;
    int minutes;
    int seconds;

public:
    MyTime(int h = 0, int m = 0, int s = 0);

    // Getters
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    // Ritorna vero se il tempo è 00:00:00
    bool isZero() const;

    // Toglie un secondo. Ritorna false se siamo già a 0.
    bool tickDown();

    // Formato stampa (es. "01:05:09")
    string toString() const;
};

#endif