//
// Created by sudhs on 30/01/2026.
//
#include <gtest/gtest.h>
#include "CountDownTimer.h"

// Test inizializzazione
TEST(CountDownTimer, InitialStateIsCorrect) {
    CountDownTimer timer(0, 1, 30);
    EXPECT_FALSE(timer.isFinished());

    // Verifica che l'oggetto Time interno sia corretto
    EXPECT_EQ(timer.getTime().getMinutes(), 1);
    EXPECT_EQ(timer.getTime().getSeconds(), 30);
}

// Test inizializzazione a zero (deve nascere già finito)
TEST(CountDownTimer, StartsFinishedIfZero) {
    CountDownTimer timer(0, 0, 0);
    EXPECT_TRUE(timer.isFinished());
}

// Test flusso completo: 2 secondi -> 0 secondi
TEST(CountDownTimer, UpdatesUntilFinished) {
    CountDownTimer timer(0, 0, 2); // 2 secondi

    EXPECT_FALSE(timer.isFinished());

    timer.update(); // Ora siamo a 1 sec
    EXPECT_FALSE(timer.isFinished());
    EXPECT_EQ(timer.getTime().getSeconds(), 1);

    timer.update(); // Ora siamo a 0 sec
    EXPECT_TRUE(timer.isFinished());
    EXPECT_EQ(timer.getTime().getSeconds(), 0);

    timer.update(); // Aggiornare ancora non deve rompere nulla
    EXPECT_TRUE(timer.isFinished());
}