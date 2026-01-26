//
// Created by sudhs on 26/01/2026.
//

#ifndef TIMEREXCEPTION_H
#define TIMEREXCEPTION_H

#include <stdexcept>
#include <string>

class TimerException : public std::runtime_error {
public:
    explicit TimerException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif