#include <gtest/gtest.h>
#include "add/add.h"

TEST(AddLib, SumsPositive) {
  EXPECT_EQ(addlib::add(2, 2), 4);
  EXPECT_EQ(addlib::add(5, 3), 8);
}

TEST(AddLib, SumsNegative) {
  EXPECT_EQ(addlib::add(-2, -3), -5);
}

