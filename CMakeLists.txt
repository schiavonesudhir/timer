cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Eseguibile principale
add_executable(timer
        src/main.cpp
        src/MyTime.cpp
        src/Date.cpp
        src/Timer.cpp
        src/Display.cpp
        src/FileLogger.cpp
        src/CountDownTimer.cpp
)

# Se vuoi che funzionino anche i test, aggiungili anche qui
add_executable(Google_Tests_run
        tests/test1.cpp
        src/MyTime.cpp
        src/Date.cpp
        src/Timer.cpp
        src/Display.cpp
        include/FileLogger.h
        src/FileLogger.cpp
        include/CountDownTimer.h
        src/CountDownTimer.cpp
        include/TimerException.h
        tests/test_countdown.cpp
)
target_link_libraries(Google_Tests_run gtest_main)