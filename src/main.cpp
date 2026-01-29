#include "CountDownTimer.h"
#include "Gui.h"
#include <thread> // Per sleep
#include <chrono>
#include <iostream>
using namespace std;
int main() {
    // Chiede l'input PRIMA di avviare la GUI di ncurses
    int h, m, s;
    cout << "Inserisci ore: "; cin >> h;
    cout << "Inserisci minuti: "; cin >> m;
    cout << "Inserisci secondi: "; cin >> s;

    // Avvio oggetti
    CountDownTimer timer(h, m, s);
    Gui gui; // Questo pulisce lo schermo ed entra in modalità grafica

    bool running = true;
    while (running && !timer.isFinished()) {
        //Disegna
        gui.draw(timer);

        //Controlla Input
        if (gui.handleInput()) {
            running = false;
        }

        //Aggiorna Timer
        timer.update();

        // Aspetta un po' (1 secondo è troppo lento per la reattività dei tasti,meglio aspettare e aggiornare il timer logicamente ogni tot cicli,ma per semplicità qui aspettiamo1 1 secondo)
        this_thread::sleep_for(chrono::seconds(1));
    }

    if (timer.isFinished()) {
        gui.showEndScreen();
    }

    return 0;
}