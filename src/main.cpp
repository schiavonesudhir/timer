#include <thread>
#include <chrono>
#include "Timer.h"
#include "Display.h"

int main() {
    Timer myTimer;
    Display myDisplay(&myTimer); // Il display osserva il timer

    myTimer.start();

    while (true) {
        myTimer.update();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}