//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

TEST(Test, int_test) {
  s21::array<double, s21::array<int, 3U>().size()> z{{1.2, 1.3, 1.34}};
  EXPECT_DOUBLE_EQ(z.front(), 1.2);
}