#include <iostream>
#include <thread> // Per std::this_thread::sleep_for
#include <chrono> // Per std::chrono::seconds
#include "MyTime.h"
using namespace std;
int main() {
    MyTime myTime(0, 0, 0);

    cout << "Avvio Timer (Premi Ctrl+C per fermare):" << std::endl;

    for (int i = 0; i < 10; ++i) { // Facciamo 10 secondi di test
        myTime.tick();
        cout << "\rTempo: "
                  << (myTime.getHours() < 10 ? "0" : "") << myTime.getHours() << ":"
                  << (myTime.getMinutes() < 10 ? "0" : "") << myTime.getMinutes() << ":"
                  << (myTime.getSeconds() < 10 ? "0" : "") << myTime.getSeconds()
                  << std::flush;

        this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "\nTest completato!" << std::endl;
    return 0;
}