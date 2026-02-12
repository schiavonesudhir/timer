cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# Cerca la libreria Ncurses installata nel sistema (WSL/Linux)
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

# file principali

add_executable(timer
        src/main.cpp
        src/MyTime.cpp
        src/CountDownTimer.cpp
        src/Gui.cpp
)

# Linka la libreria Ncurses trovata da CMake
target_link_libraries(timer ${CURSES_LIBRARIES})

# google test

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Scarica e rendi disponibile GoogleTest
FetchContent_MakeAvailable(googletest)

enable_testing()

# Creazione eseguibile per i test
add_executable(runTests
        tests/MyTimeTests.cpp
        tests/CountDownTests.cpp
        src/MyTime.cpp
        src/CountDownTimer.cpp
)

# Link le librerie di test e include gli header
target_link_libraries(runTests gtest_main)
target_include_directories(runTests PRIVATE include)