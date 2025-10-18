#include <gtest/gtest.h>
#include "add/add.h"

TEST(Add, Positive) {
  EXPECT_EQ(addlib::add(1, 2), 3);
}

TEST(Add, Negative) {
  EXPECT_EQ(addlib::add(-1, -4), -5);
}

