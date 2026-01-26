cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# GOOGLE TEST (Lascia quello che avevamo con FetchContent)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- QUI È DOVE DEVI AGGIUNGERE Time.cpp ---
# Eseguibile principale
add_executable(timer
        src/main.cpp
        src/MyTime.cpp   # <-- Fondamentale!
)

# Eseguibile per i Test
add_executable(Google_Tests_run
        tests/test1.cpp
        src/MyTime.cpp
        include/Date.h
        src/Date.cpp
        include/Timer.h
        src/Timer.cpp
        # <-- Fondamentale anche qui!
)
target_link_libraries(Google_Tests_run gtest_main)