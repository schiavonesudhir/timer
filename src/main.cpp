#include <iostream>
#include <thread> // Per sleep_for
#include <chrono> // Per seconds
#include <cstdlib> // Per system()
#include "Countdown.h"
using namespace std;
// Funzione helper per pulire lo schermo su Linux/WSL
void clearScreen() {
    system("clear");
}

int main() {
    int h, m, s;

    // Input iniziale
    clearScreen();
    cout << "=== COUNTDOWN TIMER (WSL) ===\n";
    cout << "Inserisci ore: "; cin >> h;
    cout << "Inserisci minuti: "; cin >> m;
    cout << "Inserisci secondi: "; cin >> s;

    // Creazione oggetto
    Countdown myCountdown(h, m, s);

    // Loop principale
    while (!myCountdown.isFinished()) {
        clearScreen();

        Time t = myCountdown.getTime();

        // Grafica ANSI
        cout << "\n\n";
        cout << "\t+------------------+\n";
        // \033[1;31m = Rosso grassetto, \033[0m = Reset colore
        cout << "\t|    \033[1;31m" << t.toString() << "\033[0m    |\n";
        cout << "\t+------------------+\n";
        cout << "\n\t   Counting down...\n";

        // Aspetta 1 secondo
        this_thread::sleep_for(chrono::seconds(1));

        // Aggiorna logica
        myCountdown.update();
    }

    // Schermata finale
    clearScreen();
    cout << "\n\n";
  	cout << "\t********************\n";
    cout << "\t* TEMPO SCADUTO! *\n";
    cout << "\t********************\n";
    cout << "\n\a"; // ...\a emette un suono (BEEP)

    return 0;
}