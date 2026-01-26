//
// Created by sudhs on 19/01/2026.
//

#ifndef MYTIME_H
#define MYTIME_H

class MyTime { // Cambiato nome da Time a MyTime
private:
    int hours;
    int minutes;
    int seconds;

public:
    MyTime(int h = 0, int m = 0, int s = 0);
    void tick();
    void reset();
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    void setTime(int h, int m, int s);
};

#endif