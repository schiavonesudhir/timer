#include <thread>
#include <chrono>
#include "Timer.h"
#include "Display.h"
#include "FileLogger.h"
using namespace std;
int main() {
    Timer myTimer;
    Display myDisplay(&myTimer); // Il display osserva il timer
    FileLogger myLogger(&myTimer, "timer_log.txt"); // Salverà tutto su file

    myTimer.start();

    for(int i = 0; i < 10; i++) {
        myTimer.update();
        this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}