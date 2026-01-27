//
// Created by sudhs on 27/01/2026.
//

#ifndef GUI_H
#define GUI_H

#include <ncurses.h>
#include "CountDownTimer.h"

class Gui {
private:
    WINDOW* win;
    int height, width;

public:
    Gui();
    ~Gui();

    // Disegna l'interfaccia
    void draw(const CountDownTimer& timer);

    // Gestisce l'input utente (ritorna true se l'utente vuole uscire)
    bool handleInput();

    // Mostra un messaggio di fine
    void showEndScreen();
};
#endif //GUI_H