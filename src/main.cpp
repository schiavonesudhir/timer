#include <thread>
#include <chrono>
#include "Timer.h"
#include "Display.h"
#include "FileLogger.h"
#include "CountDownTimer.h"
#include <iostream>
using namespace std;
int main() {
    // Possiamo scegliere quale timer usare usando il polimorfismo
    Timer* mioTimer = new CountdownTimer(0, 0, 10); // Parte da 10 secondi

    Display display(mioTimer);

    cout << "Avvio Countdown..." << std::endl;
    mioTimer->start();

    for(int i = 0; i < 11; i++) {
        mioTimer->update();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    cout << "\nFine!" << std::endl;
    delete mioTimer;
    return 0;
}