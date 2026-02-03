cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)
# Ho dovuto specificare i percorsi come percorsi assoluti

# Include per i file (.h nella cartella include)
include_directories(include)
include_directories("C:/msys64/mingw64/include")

# Forza l'uso di ncurses con path specifici
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
# Se CURSES_INCLUDE_DIR è vuoto, forza i path standard WSL
if (CURSES_INCLUDE_DIR)
    include_directories(${CURSES_INCLUDE_DIR})
    # Aggiunge anche il percorso ncurses per Windows
    if(WIN32 AND EXISTS "C:/msys64/mingw64/include/ncurses")
        include_directories("C:/msys64/mingw64/include/ncurses")
    endif()
else()
    # Path (di WSL)
    include_directories(/usr/include)
    include_directories(/usr/include/ncurses)
endif()

# sorgenti
add_executable(timer
        src/main.cpp
        src/MyTime.cpp
        src/CountDownTimer.cpp
        src/Gui.cpp
)

# Forza l'uso di ncurses per Windows
if(WIN32)
    target_include_directories(timer PRIVATE "C:/msys64/mingw64/include")
    target_link_libraries(timer "C:/msys64/mingw64/lib/libncurses.a")
else()
    target_link_libraries(timer ${CURSES_LIBRARIES})
endif()
# google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# evita conflitti con lib C a run time
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#eseguibili per i test
add_executable(runTests
        tests/MyTimeTests.cpp
        tests/CountDownTests.cpp
        src/MyTime.cpp
        src/CountDownTimer.cpp
)
#link google test e googletestmain
target_link_libraries(runTests gtest_main)
target_include_directories(runTests PRIVATE include)