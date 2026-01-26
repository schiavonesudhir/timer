//
// Created by sudhs on 26/01/2026.
//

#ifndef TIMER_H
#define TIMER_H

#include <list>
#include "MyTime.h"
#include "Date.h"
#include "Observer.h"
#include <vector>


class Timer {
protected:
    MyTime currentTime;
    Date currentDate;
    bool running;
    std::list<Observer*> observers; // Lista degli osservatori
    std::vector<MyTime> laps;

public:
    Timer();
    virtual ~Timer(){};

    // Metodi per gestire gli osservatori
    void start() { running = true; }
    void stop() { running = false; }
    void attach(Observer* o);
    void detach(Observer* o);
    void notify();

    virtual void update(); // Incrementa il tempo e notifica

    // Getter per permettere agli osservatori di leggere i dati
    MyTime getTime() const { return currentTime; }
    Date getDate() const { return currentDate; }

    void addLap() { laps.push_back(currentTime); }
    void clearLaps() { laps.clear(); }
    const std::vector<MyTime>& getLaps() const { return laps; }
};

#endif