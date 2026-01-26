#include <iostream>
#include <thread>
#include <chrono>
#include "Timer.h"
#include "CountdownTimer.h"
#include "Display.h"
#include "TimerException.h"

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

int main() {
    Timer* mioTimer = nullptr;
    int scelta;

    try {
        std::cout << "=== GESTIONE TEMPO ===\n";
        std::cout << "1. Avvia Cronometro (Conteggio avanti)\n";
        std::cout << "2. Avvia Timer (Conteggio indietro)\n";
        std::cout << "Scelta: ";
        std::cin >> scelta;

        if (scelta == 2) {
            int h, m, s;
            std::cout << "Inserisci tempo di partenza (h m s): ";
            std::cin >> h >> m >> s;
            mioTimer = new CountdownTimer(h, m, s);
        } else {
            mioTimer = new Timer();
        }

        Display display(mioTimer);
        mioTimer->start();

        std::cout << "Premere Ctrl+C per interrompere.\n";
        std::cout << (scelta == 2 ? "MODALITA': TIMER" : "MODALITA': CRONOMETRO") << "\n";
        while (true) {
            clearScreen();
            mioTimer->update(); // Questo chiama anche notify() e quindi il display stampa
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

    } catch (const TimerException& e) {
        std::cerr << "\nERRORE: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "\nErrore imprevisto!" << std::endl;
    }

    delete mioTimer;
    return 0;
}