#include "CountDownTimer.h"
#include "Gui.h"
#include <thread> // Per sleep
#include <chrono>
#include <iostream>
using namespace std;
int main() {
    // Chiediamo l'input PRIMA di avviare la GUI ncurses
    int h, m, s;
    cout << "Inserisci ore: "; cin >> h;
    cout << "Inserisci minuti: "; cin >> m;
    cout << "Inserisci secondi: "; cin >> s;

    // Avvio oggetti
    CountDownTimer timer(h, m, s);
    Gui gui; // Questo pulisce lo schermo ed entra in modalità grafica

    bool running = true;
    while (running && !timer.isFinished()) {
        // 1. Disegna
        gui.draw(timer);

        // 2. Controlla Input
        if (gui.handleInput()) {
            running = false;
        }

        // 3. Aggiorna Timer
        timer.update();

        // 4. Aspetta un po' (1 secondo è troppo lento per la reattività dei tasti,
        // meglio dormire meno e aggiornare il timer logicamente ogni tot cicli,
        // ma per semplicità qui dormiamo 1 secondo)
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    if (timer.isFinished()) {
        gui.showEndScreen();
    }

    return 0;
}