//
// Created by sudhs on 30/01/2026.
//
#include <gtest/gtest.h>
#include "MyTime.h"

// Test del costruttore e dei getter di base
TEST(MyTimeTest, ConstructorSetsValuesCorrectly) {
    MyTime t(10, 30, 45);
    EXPECT_EQ(t.getHours(), 10);
    EXPECT_EQ(t.getMinutes(), 30);
    EXPECT_EQ(t.getSeconds(), 45);
}

// Test per vedere se gestisce lo zero
TEST(MyTimeTest, IsZeroReturnsTrueOnlyWhenFinished) {
    MyTime tZero(0, 0, 0);
    EXPECT_TRUE(tZero.isZero());

    MyTime tNotZero(0, 0, 1);
    EXPECT_FALSE(tNotZero.isZero());
}

// Test Rollover un secondo
TEST(MyTimeTest, TickDownDecrementsSeconds) {
    MyTime t(0, 0, 10);
    bool result = t.tickDown();

    EXPECT_TRUE(result); // Deve ritornare true (ancora attivo)
    EXPECT_EQ(t.getSeconds(), 9);
}

// Rollover dei minuti (es. da 00:01:00 -> 00:00:59)
TEST(MyTimeTest, TickDownHandlesMinuteRollover) {
    MyTime t(0, 1, 0); // 1 minuto esatto
    t.tickDown();

    EXPECT_EQ(t.getMinutes(), 0);
    EXPECT_EQ(t.getSeconds(), 59);
}

// Test critico: Rollover delle ore (es. 01:00:00 -> 00:59:59)
TEST(MyTimeTest, TickDownHandlesHourRollover) {
    MyTime t(1, 0, 0); // 1 ora esatta
    t.tickDown();

    EXPECT_EQ(t.getHours(), 0);
    EXPECT_EQ(t.getMinutes(), 59);
    EXPECT_EQ(t.getSeconds(), 59);
}

// Test formattazione stringa
TEST(MyTimeTest, ToStringFormatsCorrectly) {
    MyTime t(1, 5, 9);
    // Ci aspettiamo lo zero-padding (01:05:09)
    EXPECT_EQ(t.toString(), "01:05:09");
}

// Test limite: Tick su 00:00:00
TEST(MyTimeTest, TickDownAtZeroReturnsFalse) {
    MyTime t(0, 0, 0);
    bool result = t.tickDown();

    EXPECT_FALSE(result); // Deve ritornare false (finito)
    EXPECT_EQ(t.getSeconds(), 0); // Non deve andare a -1
}