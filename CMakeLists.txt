cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Cartella degli Header
include_directories(include)

# 2. SCARICAMENTO AUTOMATICO GOOGLE TEST (Sostituisce la cartella lib)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Per evitare problemi su Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 3. ESEGUIBILE PRINCIPALE
# Assicurati che src/main.cpp esista!
add_executable(timer src/main.cpp)

# 4. ESEGUIBILE PER I TEST
# Se non hai ancora test1.cpp, crealo vuoto nella cartella tests
add_executable(Google_Tests_run tests/test1.cpp)
target_link_libraries(Google_Tests_run gtest_main)