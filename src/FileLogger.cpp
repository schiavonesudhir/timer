//
// Created by sudhs on 26/01/2026.
//
#include "FileLogger.h"
#include <iostream>

FileLogger::FileLogger(Timer* t, const std::string& filename) : subject(t) {
    logFile.open(filename, std::ios::app); // Apre in modalità "append" (aggiunge in coda)
    if (subject) {
        subject->attach(this);
    }
}

FileLogger::~FileLogger() {
    if (subject) {
        subject->detach(this);
    }
    if (logFile.is_open()) {
        logFile.close();
    }
}

void FileLogger::update() {
    if (logFile.is_open()) {
        MyTime t = subject->getTime();
        Date d = subject->getDate();

        logFile << "LOG [" << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << "] "
                << t.getHours() << ":" << t.getMinutes() << ":" << t.getSeconds() << std::endl;
    }
}