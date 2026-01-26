#include <gtest/gtest.h>
#include "MyTime.h"
#include "TimerException.h"
TEST(TimeTest, IncrementSeconds) {
    MyTime t(0, 0, 59);
    t.tick();
    EXPECT_EQ(t.getMinutes(), 1);
    EXPECT_EQ(t.getSeconds(), 0);
}

TEST(TimeTest, IncrementHours) {
    MyTime t(0, 59, 59);
    t.tick();
    EXPECT_EQ(t.getHours(), 1);
    EXPECT_EQ(t.getMinutes(), 0);
    EXPECT_EQ(t.getSeconds(), 0);
}
TEST(TimeTest, InvalidTimeException) {
    MyTime t;
    // Verifichiamo che lanci l'eccezione se mettiamo 61 minuti
    EXPECT_THROW({
        t.setTime(10, 61, 0);
    }, TimerException);
}