//
// Created by sudhs on 27/01/2026.
//
#include "Gui.h"
#include <string>

Gui::Gui() {
    initscr();            // Avvia ncurses
    cbreak();             // Disabilita buffering riga
    noecho();             // Non mostra i tasti premuti
    curs_set(0);          // Nasconde cursore
    nodelay(stdscr, TRUE);// Input NON bloccante

    // Abilita colori se supportati
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_CYAN, COLOR_BLACK);  // Bordo
        init_pair(2, COLOR_RED, COLOR_BLACK);   // Tempo
        init_pair(3, COLOR_GREEN, COLOR_BLACK); // Testo info
    }

    // Crea finestra centrata
    height = 10; width = 40;
    int start_y = (LINES - height) / 2;
    int start_x = (COLS - width) / 2;
    win = newwin(height, width, start_y, start_x);
}

Gui::~Gui() {
    delwin(win);
    endwin(); // Ripristina il terminale normale
}

void Gui::draw(const CountDownTimer& timer) {
    werase(win); // Pulisce finestra

    // Disegna bordo
    wattron(win, COLOR_PAIR(1));
    box(win, 0, 0);
    mvwprintw(win, 0, 2, "[ WSL TIMER ]");
    wattroff(win, COLOR_PAIR(1));

    // Scrivi Tempo (Grande e Rosso)
    string timeStr = timer.getTime().toString();
    wattron(win, A_BOLD | COLOR_PAIR(2));
    mvwprintw(win, height/2 - 1, (width - timeStr.length())/2, "%s", timeStr.c_str());
    wattroff(win, A_BOLD | COLOR_PAIR(2));

    // Scrivi istruzioni
    wattron(win, COLOR_PAIR(3));
    string info = "Premi 'Q' per uscire";
    mvwprintw(win, height - 2, (width - info.length())/2, "%s", info.c_str());
    wattroff(win, COLOR_PAIR(3));

    wrefresh(win);
}

bool Gui::handleInput() {
    int ch = getch();
    if (ch == 'q' || ch == 'Q') return true;
    return false;
}

void Gui::showEndScreen() {
    werase(win);
    box(win, 0, 0);
    wattron(win, A_BLINK | A_BOLD | COLOR_PAIR(2));
    mvwprintw(win, height/2, 10, "TEMPO SCADUTO!");
    wattroff(win, A_BLINK | A_BOLD | COLOR_PAIR(2));
    mvwprintw(win, height-2, 8, "Premi S per uscire");
    wrefresh(win);

    // Aspetta input bloccante alla fine
    nodelay(stdscr, FALSE);
    while(getch() != 's');
}