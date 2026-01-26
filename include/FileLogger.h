//
// Created by sudhs on 26/01/2026.
//

#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include <string>
#include "Observer.h"
#include "Timer.h"

class FileLogger : public Observer {
private:
    Timer* subject;
    std::ofstream logFile;

public:
    FileLogger(Timer* t, const std::string& filename);
    ~FileLogger(); // Chiudiamo il file nel distruttore
    void update() override;
};

#endif