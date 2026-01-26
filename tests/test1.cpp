#include <gtest/gtest.h>
#include "Time.h"

TEST(TimeTest, IncrementSeconds) {
    Time t(0, 0, 59);
    t.tick();
    EXPECT_EQ(t.getMinutes(), 1);
    EXPECT_EQ(t.getSeconds(), 0);
}

TEST(TimeTest, IncrementHours) {
    Time t(0, 59, 59);
    t.tick();
    EXPECT_EQ(t.getHours(), 1);
    EXPECT_EQ(t.getMinutes(), 0);
    EXPECT_EQ(t.getSeconds(), 0);
}