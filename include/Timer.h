//
// Created by sudhs on 19/01/2026.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
class Timer {
private:
    int seconds;
public:
    Timer() : seconds(0) {}
    void addSecond() { seconds++; }
    int getSeconds() const { return seconds; }
    void reset() { seconds = 0; }
};
#endif //TIMER_TIMER_H