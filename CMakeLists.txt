cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)

# 1. Include per i tuoi file (.h nella cartella include)
include_directories(include)

# 2. Cerca Ncurses
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

# 3. DEBUG: Stampiamo cosa ha trovato (guarda nella console CMake in basso)
message(STATUS "Curses found: ${CURSES_FOUND}")
message(STATUS "Curses include dir: ${CURSES_INCLUDE_DIR}")
message(STATUS "Curses libs: ${CURSES_LIBRARIES}")

# 4. Aggiungiamo i percorsi in modo aggressivo
# Se CURSES_INCLUDE_DIR è vuoto, forziamo i path standard di Linux/WSL
if (CURSES_INCLUDE_DIR)
    include_directories(${CURSES_INCLUDE_DIR})
else()
    # Path standard su Ubuntu/Debian (WSL)
    include_directories(/usr/include)
    include_directories(/usr/include/ncurses)
endif()

# 5. Definizione sorgenti
add_executable(timer
        src/main.cpp
        src/MyTime.cpp
        src/CountDownTimer.cpp
        src/Gui.cpp
        include/Gui.h # Utile per far vedere l'header nell'albero del progetto
        # HAI RIMOSSO IL DUPLICATO DI src/Gui.cpp CHE C'ERA QUI
)

# 6. Link
target_link_libraries(timer ${CURSES_LIBRARIES})