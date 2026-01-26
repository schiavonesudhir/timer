//
// Created by sudhs on 26/01/2026.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
#include "MyTime.h"
#include "Date.h"

class Timer {
private:
    Time currentTime;
    Date currentDate;
    bool running;

public:
    Timer();
    void update(); // Chiamata ogni secondo
    void start() { running = true; }
    void stop() { running = false; }
    void show() const;
};

#endif
#endif //TIMER_TIMER_H