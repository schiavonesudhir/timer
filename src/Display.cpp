//
// Created by sudhs on 26/01/2026.
//
#include "Display.h"
#include <iostream>

Display::Display(Timer* t) : subject(t) {
    subject->attach(this); // Si registra automaticamente
}

void Display::update() {
    MyTime t = subject->getTime();
    Date d = subject->getDate();
    const auto& laps = subject->getLaps();

    // Pulizia e stampa orario principale
    std::cout << "\r[ " << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << " ] ";
    std::cout << (t.getHours() < 10 ? "0" : "") << t.getHours() << ":"
              << (t.getMinutes() < 10 ? "0" : "") << t.getMinutes() << ":"
              << (t.getSeconds() < 10 ? "0" : "") << t.getSeconds();

    // Stampa i Lap se presenti (stampa solo gli ultimi 3 per non riempire lo schermo)
    if (!laps.empty()) {
        std::cout << "  | Laps: ";
        int start = laps.size() > 3 ? laps.size() - 3 : 0;
        for (size_t i = start; i < laps.size(); ++i) {
            std::cout << "#" << i+1 << "(" << laps[i].getSeconds() << "s) ";
        }
    }
    std::cout << std::flush;
}