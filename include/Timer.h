//
// Created by sudhs on 26/01/2026.
//

#ifndef TIMER_H
#define TIMER_H

#include <list>
#include "MyTime.h"
#include "Date.h"
#include "Observer.h"

class Timer {
private:
    MyTime currentTime;
    Date currentDate;
    bool running;
    std::list<Observer*> observers; // Lista degli osservatori

public:
    Timer();
    void start() { running = true; }
    void stop() { running = false; }

    // Metodi per gestire gli osservatori
    void attach(Observer* o);
    void detach(Observer* o);
    void notify();

    void update(); // Incrementa il tempo e notifica

    // Getter per permettere agli osservatori di leggere i dati
    MyTime getTime() const { return currentTime; }
    Date getDate() const { return currentDate; }
};

#endif