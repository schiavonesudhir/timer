//
// Created by sudhs on 26/01/2026.
//
#include <gtest/gtest.h>
#include "CountdownTimer.h"

TEST(CountdownTest, DecrementLogic) {
    CountdownTimer ct(0, 1, 0); // 1 minuto
    ct.start();
    ct.update(); // Scatta un secondo
    EXPECT_EQ(ct.getTime().getSeconds(), 59);
    EXPECT_EQ(ct.getTime().getMinutes(), 0);
}

TEST(CountdownTest, StopsAtZero) {
    CountdownTimer ct(0, 0, 1);
    ct.start();
    ct.update(); // Arriva a 0
    ct.update(); // Prova ad andare sotto zero
    EXPECT_EQ(ct.getTime().getSeconds(), 0);
    EXPECT_EQ(ct.getTime().getMinutes(), 0);
}