cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)

# Include gli header locali
include_directories(include)

# Cerca la libreria ncurses (Su Linux è standard)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(timer
        src/main.cpp
        src/MyTime.cpp
        src/CountDownTimer.cpp
        src/Gui.cpp
        include/Gui.h
        src/Gui.cpp   # File per la gestione grafica
)

# Linka ncurses all'eseguibile
target_link_libraries(timer ${CURSES_LIBRARIES})