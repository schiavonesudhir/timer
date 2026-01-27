cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)
# Ho dovuto specificare i percorsi come percorsi assoluti

# 1. Include per i tuoi file (.h nella cartella include)
include_directories(include)
include_directories("C:/msys64/mingw64/include")

# 2. Forza l'uso di ncurses con path specifici
if(WIN32)
    # Forza i path di ncurses per MINGW64
    set(CURSES_INCLUDE_DIR "C:/msys64/mingw64/include/ncurses")
    set(CURSES_LIBRARIES "C:/msys64/mingw64/lib/libncurses.a")
    message(STATUS "Using forced ncurses paths")
    message(STATUS "Include: ${CURSES_INCLUDE_DIR}")
    message(STATUS "Library: ${CURSES_LIBRARIES}")
else()
    set(CURSES_NEED_NCURSES TRUE)
    find_package(Curses REQUIRED)
endif()

# 3. DEBUG: Stampiamo cosa ha trovato (guarda nella console CMake in basso)
message(STATUS "Curses found: ${CURSES_FOUND}")
message(STATUS "Curses include dir: ${CURSES_INCLUDE_DIR}")
message(STATUS "Curses libs: ${CURSES_LIBRARIES}")

# 4. Aggiungiamo i percorsi in modo aggressivo
# Se CURSES_INCLUDE_DIR è vuoto, forziamo i path standard di Linux/WSL
if (CURSES_INCLUDE_DIR)
    include_directories(${CURSES_INCLUDE_DIR})
    # Aggiungi anche il percorso ncurses per Windows
    if(WIN32 AND EXISTS "C:/msys64/mingw64/include/ncurses")
        include_directories("C:/msys64/mingw64/include/ncurses")
    endif()
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

# 6. Link - Forza l'uso di ncurses per Windows
if(WIN32)
    target_include_directories(timer PRIVATE "C:/msys64/mingw64/include")
    target_link_libraries(timer "C:/msys64/mingw64/lib/libncurses.a")
else()
    target_link_libraries(timer ${CURSES_LIBRARIES})
endif()