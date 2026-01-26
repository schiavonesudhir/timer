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

    // Stampa pulita
    std::cout << "\r[ " << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << " ] ";
    std::cout << (t.getHours() < 10 ? "0" : "") << t.getHours() << ":"
              << (t.getMinutes() < 10 ? "0" : "") << t.getMinutes() << ":"
              << (t.getSeconds() < 10 ? "0" : "") << t.getSeconds() << std::flush;
}