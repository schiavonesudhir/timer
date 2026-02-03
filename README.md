# ️⏲️ Countdown Timer Project (C++ & Ncurses)

Applicazione su terminale per il conto alla rovescia, sviluppata in C++ 11 utilizzando la libreria **ncurses** per l'interfaccia grafica (GUI).
Il progetto include un insieme di test unitari automatizzati con **GoogleTest**.

## 📋 Caratteristiche
* **Interfaccia Grafica:** GUI testuale con finestre, bordi e colori grazie a `ncurses`.
* **Architettura OOP:** Struttura modulare basata su classi (`MyTime`, `CountDownTimer`, `Gui`).
* **Validazione Input:** Gestione del tempo (rollover automatico di secondi/minuti/ore).
* **Unit Testing:** Copertura test sulla logica con GoogleTest.
* **WSL:** Ottimizzato per girare su ambienti Linux e Windows Subsystem for Linux.

---

## ⚙️ Ambiente di Sviluppo & Installazione

Per far funzionare questo progetto su Windows usare **WSL (Windows Subsystem for Linux)** per garantire compatibilità nativa con le librerie

### 1. Prerequisiti Installati
Installare Clion e apportare le modifiche necessarie per la corretta compilazione.
All'interno del terminale WSL (Ubuntu), sono stati installati i seguenti pacchetti:

```bash
# Aggiornamento dei repository
sudo apt-get update

# Installazione compilatore e tool di build
sudo apt-get install build-essential cmake

# Installazione libreria grafica NCURSES (Fondamentale)
sudo apt-get install libncurses5-dev libncursesw5-dev

```

### 2. Cambiamenti Clion
* File->Settings->Build, Execution, Deployment->Toolchain->
* * selezionare WSL;
* * toolset: Ubuntu-22.04 
* * Cmake: WSL CMAKE
* * Build Tool: gmake
* * C Compiler: cc
* * C++ Compiler: c++
* * Debugger: WSL gdb

altri cambiamenti per la visualizzazione su terminale:
Run->Edit Configurations
* spuntare "Emulate terminal in the output console" 
* Enviroment Variables: TERM=xterm-256color
